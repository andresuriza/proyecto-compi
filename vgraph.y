%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast.h"
#include <ctype.h>
#include <string.h>

nodeType *opr(int oper, int nops, ...);
nodeType *id(char* name);
nodeType *con(double value);
nodeType *conColor(const char *value);

FILE *out;

Symbol *symbolTable = NULL;

void freeNode(nodeType *p);
int ex(nodeType *p, FILE *out);
int yylex(void);
void start_interpreter_file(FILE **out);
void end_interpreter_file(FILE *out);

void yyerror(const char *s);
%}

%union {
    double dValue;
    char* id;
    nodeType* nPtr;
};

%token <dValue> INTEGER
%token <id> VARIABLE COLORTYPE
%token IF
%nonassoc IFX
%nonassoc ELSE

%left '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%token FUNC
%token COORD
%token LINE
%token RECT
%token CIRCLE
%token PIXEL
%token SETCOLOR
%token WAIT
%token FRAME
%token LOOP
%token DRAW
%token END
%token MOVE
%token ANIMATE
%token COS
%token SIN
%token INT COLOR
%token GE LE EQ NE
%token I_DECL C_DECL
%token FUNCTION RETURN CLEAR

%type <nPtr> stmt expr stmt_list frame conditional_body conditional assignment var_type
%type <nPtr> int_list color_list param_list_opt func_def

// TODO AGREGAR MARRON

%%

program:
        function
        | error { fprintf(stderr, "Error de sintaxis en la estructura 'program'\n"); yyerrok; }
        ;

function:
          function stmt { ex($2, out); freeNode($2); }
        | function frame { ex($2, out); freeNode($2); }
        | function func_def { ex($2, out); freeNode($2); }
        | /* NULL */
        | error { fprintf(stderr, "Error en 'function'\n"); yyerrok; }
        ;

frame:
          FRAME '{' stmt_list '}' { $$ = $3; }
        | error { fprintf(stderr, "Error en definición de 'frame'\n"); yyerrok; $$ = NULL; }
        ;


func_def:
    FUNCTION VARIABLE '(' param_list_opt ')' '{' stmt_list '}' { $$ = $7; }
    | error { fprintf(stderr, "Error en definición de funcion\n"); yyerrok; $$ = NULL; }
    ;

param_list_opt:
      VARIABLE {}
    | expr {}
    | param_list_opt ',' VARIABLE {}
    | param_list_opt ',' expr {}
    ;

stmt:
          ';'   { $$ = opr(';', 2, NULL, NULL); }
        | var_type ';' { $$ = $1; }
        | expr ';'  { $$ = $1; }
        | assignment ';'  { $$ = $1; }
        | RETURN ';' { $$ = opr(FUNC, 0); }
        | CLEAR '(' ')' { $$ = opr(FUNC, 0); } // CAMBIAR
        | VARIABLE '(' param_list_opt ')' ';' { $$ = $3; }
        | LOOP '(' assignment ';' conditional ';'  assignment ')' conditional_body { $$ = opr(LOOP, 4, $3, $5, $7, $9); }
        | IF '(' conditional ')' conditional_body %prec IFX { $$ = opr(IF, 2, $3, $5); }
        | IF '(' conditional ')' conditional_body ELSE conditional_body { $$ = opr(IF, 3, $3, $5, $7); }
        | SETCOLOR '(' expr ')' ';'  { $$ = opr(SETCOLOR, 1, $3); }
        | WAIT '(' expr ')' ';'  { $$ = opr(WAIT, 1, $3); }
        | DRAW PIXEL '(' expr ',' expr ')' ';'  { $$ = opr(PIXEL, 2, $4, $6); }
        | DRAW LINE '(' expr ',' expr ',' expr ',' expr ')' ';'  { $$ = opr(LINE, 4, $4, $6, $8, $10); }
        | DRAW CIRCLE '(' expr ',' expr ','  expr')' ';'  { $$ = opr(CIRCLE, 3, $4, $6, $8); }
        | DRAW RECT '(' expr ',' expr ',' expr ',' expr ')' ';'  { $$ = opr(RECT, 4, $4, $6, $8, $10); }
        | error ';' { fprintf(stderr, "Error en sentencia\n"); yyerrok; $$ = NULL; }
        ;

var_type:
          '(' INT ')' int_list { $$ = $4; }
        | '(' COLOR ')' color_list { $$ = $4; }
        | error { fprintf(stderr, "Error en declaración de tipo\n"); yyerrok; $$ = NULL; }
        ;

int_list:
        VARIABLE { $$ = opr(I_DECL, 2, id($1), con(0)); }
        | int_list ',' VARIABLE { $$ = opr(';', 2, $1, opr(I_DECL, 2, id($3), con(0))); }
        | error { fprintf(stderr, "Error en lista de enteros\n"); yyerrok; $$ = NULL; }
        ;

color_list:
        VARIABLE { $$ = opr(C_DECL, 2, id($1), conColor("rojo")); }
        | color_list ',' VARIABLE { $$ = opr(';', 2, $1, opr(C_DECL, 2, id($3), conColor("rojo"))); }
        | error { fprintf(stderr, "Error en lista de colores\n"); yyerrok; $$ = NULL; }
        ;


assignment:
           VARIABLE '=' expr { $$ = opr('=', 2, id($1), $3); }
         | error { fprintf(stderr, "Error en asignación\n"); yyerrok; $$ = NULL; }
         ;

conditional_body:
          '{' stmt_list '}' { $$ = $2; }
        | stmt_list { $$ = $1; }
        | error { fprintf(stderr, "Error en cuerpo condicional\n"); yyerrok; $$ = NULL; }
        ;

stmt_list:
          stmt { $$ = $1; }
        | stmt_list stmt { $$ = opr(';', 2, $1, $2); }
        | error { fprintf(stderr, "Error en lista de sentencias\n"); yyerrok; $$ = NULL; }
        ;

expr:
          INTEGER               { $$ = con($1); }
        | COLORTYPE            { $$ = conColor($1); }
        | VARIABLE              { $$ = id($1); }
        | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
        | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
        | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
        | expr '%' expr         { $$ = opr('%', 2, $1, $3); }
        | COS '(' expr ')'      { $$ = opr(COS, 1, $3); }
        | SIN '(' expr ')'      { $$ = opr(SIN, 1, $3); }
        | '(' expr ')'          { $$ = $2; }
        | error { fprintf(stderr, "Error en expresión\n"); yyerrok; $$ = NULL; }
        ;

conditional:
           expr '<' expr         { $$ = opr('<', 2, $1, $3); }
         | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
         | expr '>''=' expr      { $$ = opr(GE, 2, $1, $4); }
         | expr '<''=' expr      { $$ = opr(LE, 2, $1, $4); }
         | expr '=''=' expr      { $$ = opr(EQ, 2, $1, $4); }
         | expr '!''=' expr      { $$ = opr(NE, 2, $1, $4); }
         | error { fprintf(stderr, "Error en condición lógica\n"); yyerrok; $$ = NULL; }
         ;

%%

nodeType *conColor(const char *name) {
    nodeType *p = malloc(sizeof(nodeType));
    p->type = typeCon;
    
    if (strcmp(name, "rojo") == 0) {
        p->con.value = ROJO;
        p->con.type = SYM_COLOR;
    }

    else if (strcmp(name, "verde") == 0) {
        p->con.value = VERDE;
        p->con.type = SYM_COLOR;
    }

    else if (strcmp(name, "azul") == 0) {
        p->con.value = AZUL;
        p->con.type = SYM_COLOR;
    }  
    else if (strcmp(name, "negro") == 0) {
        p->con.value = NEGRO;
        p->con.type = SYM_COLOR;
    }  
    else if (strcmp(name, "cyan") == 0) {
        p->con.value = CYAN;
        p->con.type = SYM_COLOR;
    }  
    else if (strcmp(name, "magenta") == 0) {
        p->con.value = MAGENTA;
        p->con.type = SYM_COLOR;
    }  
    else if (strcmp(name, "cafe") == 0) {
        p->con.value = CAFE;
        p->con.type = SYM_COLOR;
    }  
    else if (strcmp(name, "gris") == 0) {
        p->con.value = GRIS;
        p->con.type = SYM_COLOR;
    }  
    else if (strcmp(name, "amarillo") == 0) {
        p->con.value = AMARILLO;
        p->con.type = SYM_COLOR;
    }  
    else if (strcmp(name, "blanco") == 0) {
        p->con.value = BLANCO;
        p->con.type = SYM_COLOR;
    }  
    else if (strcmp(name, "marron") == 0) {
        p->con.value = MARRON;
        p->con.type = SYM_COLOR;
    }  
    
    else {
        yyerror("Unknown color");
    }
    return p;
}

nodeType *con(double value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(char* name) {
    nodeType *p;

    // allocate node
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    // copy information
    p->type = typeId;
    p->id.name = strdup(name);

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(const char *s) {
    extern int yylineno;
    extern char *yytext;
    fprintf(stderr, "Error de sintaxis en línea %d cerca de '%s': %s\n", yylineno, yytext, s);
    exit(1);  // Detiene inmediatamente
}

int main(void) {
    start_interpreter_file(&out);
    yyparse();
    end_interpreter_file(out);
    return 0;
}