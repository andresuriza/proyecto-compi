%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(double value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(char *s);
double sym[26];                    /* symbol table */
%}

// TODO chequear longitud de identifier
// TODO rangos int, coords

%union {
    double dValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
};

%token <dValue> INTEGER
%token <sIndex> VARIABLE
%token IF
%nonassoc IFX
%nonassoc ELSE

%left '>' '<'
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%token FUNC
%token INT
%token COLOR
%token COORD
%token LINE
%token RECT
%token CIRCLE
%token PIXEL
%token SETCOLOR
%token WAIT
%token FRAME
%token LOOP
%token LT
%token GT
%token PLUS
%token MODULUS
%token DRAW
%token END
%token MOVE
%token ANIMATE
%token COS
%token SIN
%token FLOAT
%token PRINT

%type <nPtr> stmt expr stmt_list frame

%%

program:
        function    { exit(0); }
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
        | expr ';'  { $$ = $1; }
        //| PRINT expr ';'                 { $$ = opr(PRINT, 1, $2); }
        | VARIABLE '=' expr ';' { $$ = opr('=', 2, id($1), $3); }
        //| WHILE '(' expr ')' stmt        { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' expr ')' stmt %prec IFX    { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt    { $$ = opr(IF, 3, $3, $5, $7); }
        | SETCOLOR '(' expr ')' ';'  { $$ = opr(SETCOLOR, 1, $3); }
        | WAIT '(' expr ')' ';'  { $$ = opr(WAIT, 1, $3); }
        | DRAW PIXEL '(' expr ',' expr ')' ';'  { $$ = opr(PIXEL, 2, $4, $6); }
        | '{' stmt_list '}' { $$ = $2; }
        ;


stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

expr:
          INTEGER               { $$ = con($1); }
        | VARIABLE              { $$ = id($1); }
        | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
        | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
        | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
        | expr '<' expr         { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
        | COS '(' expr ')'      { $$ = opr(COS, 1, $3); }
        | SIN '(' expr ')'      { $$ = opr(SIN, 1, $3); }
        //| expr GE expr          { $$ = opr(GE, 2, $1, $3); }
        //| expr LE expr          { $$ = opr(LE, 2, $1, $3); }
        //| expr NE expr          { $$ = opr(NE, 2, $1, $3); }
        //| expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
        | '(' expr ')'          { $$ = $2; }
        ;

%%

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

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

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
    yyparse();
    return 0;
}

/**
exp: term {$$ = $1;}
	| exp '+' term {$$ = $1 + $3;}
	| exp '-' term {$$ = $1 - $3;}
	| exp '*' term {$$ = $1 * $3;}
	| exp '/' term {$$ = $1 / $3;}
	| COS '(' exp ')' {$$ = cos($3);}
	| SIN '(' exp ')'{$$ = sin($3);}
	| exp '%' term {$$ = (int)$1 % (int)$3;}
	| error { fprintf(stderr, "Syntax error in exp \n"); yyerror; }
	;

term: INTEGER {$$ = $1;}
		| IDENTIFIER {$$ = symbolVal($1);} 
		| error { fprintf(stderr, "Syntax error in term \n"); yyerror; }
        ;

float_r: INTEGER {;}
	   | FLOAT {;}
	   ;

if: IF '(' condition ')' {printf("if something \n");}
  ;

else: {{printf("else something \n");};}
    ;

condition: {;}
		 ;

%%

int computeSymbolIndex(char token)
{
	int idx = -1;
	if(islower(token)) {
		idx = token - 'a' + 26;
	} else if(isupper(token)) {
		idx = token - 'A';
	}
	return idx;
} 
*/

/* returns the value of a given symbol
int symbolVal(char symbol)
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

/* updates the value of a given symbol
void updateSymbolVal(char symbol, int val)
{
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

void yyerror (char *s) {
	fprintf (stderr, "Parse error:%s\n", s);
	exit(1);
} 

int main (void) {
	/* init symbol table
	int i;
	for(i=0; i<52; i++) {
		symbols[i] = 0;
	}
	
	yydebug = 0;

	yyparse();
}
*/