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

Symbol *symbolTable = NULL;

void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);
//void addPredefinedConstants();

void yyerror(char *s);
%}

// TODO chequear longitud de identifier
// TODO rangos int, coords

%union {
    double dValue;
    char* id;      // index into symbolTable
    nodeType* nPtr;
};

%token <dValue> INTEGER
%token <id> VARIABLE CTYPE
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
%token LE
%token GE
%token NE
%token EQ
%token PLUS
%token MODULUS
%token DRAW
%token TREE
%token END
%token MOVE
%token ANIMATE
%token COS
%token SIN
%token PRINT
%token INT FLOAT COLOR

%type <nPtr> stmt expr stmt_list frame conditional_body conditional condition assignment var_type var_list

%%

program:
        function { exit(0); }
        ;

function:
          function stmt { ex($2); freeNode($2); }
        | function frame { ex($2); freeNode($2); }
        | /* NULL */
        ;

frame:
          FRAME '{' stmt_list '}' { $$ = $3; }
        ;


stmt:
          ';'   { $$ = opr(';', 2, NULL, NULL); }
        | var_type ';' { $$ = $1; }
        | expr ';'  { $$ = $1; }
        | assignment ';'  { $$ = $1; }
        | LOOP '(' assignment ';' conditional ';'  assignment ')' conditional_body { 
                $$ = opr(LOOP, 4, $3, $5, $7, $9); 
            }
        | IF '(' conditional ')' conditional_body %prec IFX    { $$ = opr(IF, 2, $3, $5); }
        | IF '(' conditional ')' conditional_body ELSE conditional_body  { $$ = opr(IF, 3, $3, $5, $7); }
        | SETCOLOR '(' expr ')' ';'  { $$ = opr(SETCOLOR, 1, $3); }
        | WAIT '(' expr ')' ';'  { $$ = opr(WAIT, 1, $3); }
        | DRAW PIXEL '(' expr ',' expr ')' ';'  { $$ = opr(PIXEL, 2, $4, $6); }
        | DRAW TREE '(' expr ',' expr ',' expr ',' expr ',' expr ')' ';'  { 
                $$ = opr(TREE, 2, $4, $6, $8, $10, $12); 
            }
        //| '{' stmt_list '}' { $$ = $2; }
        ;

var_type:
          '(' INT ')' var_list { $$ = $4; }
        |  '(' COLOR ')' var_list { $$ = $4; }
        ;

var_list:
        VARIABLE { $$ = opr('=', 2, id($1), 0); }
        | var_list ',' VARIABLE { $$ = opr('=', 2, id($3), 0); }
        ;

assignment:
           VARIABLE '=' expr { $$ = opr('=', 2, id($1), $3); }
          ;

conditional_body:
          '{' stmt_list '}' { $$ = $2; }
          | stmt_list { $$ = $1; }
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

expr:
          INTEGER               { $$ = con($1); }
        | CTYPE              { $$ = conColor($1); }
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
        ;

conditional:
           expr '<' expr         { $$ = opr('<', 2, $1, $3); }
         | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
         | expr '>''=' expr         { $$ = opr(GE, 2, $1, $4); }
         | expr '<''=' expr         { $$ = opr(LE, 2, $1, $4); }
         | expr '=''=' expr         { $$ = opr(EQ, 2, $1, $4); }
         | expr '!''=' expr         { $$ = opr(NE, 2, $1, $4); }
         ;

condition:
           '(' assignment ';' conditional ';'  assignment ')' { $$ = $4; }
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

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(void) {
    //addPredefinedConstants();

    yyparse();

    return 0;
}