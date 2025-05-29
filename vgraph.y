%{
void yyerror (char *s);
int yylex();
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
%}

// TODO chequear longitud de identifier
// TODO rangos int, coords

%union {int intT; float floatT; char* id;}         /* Yacc definitions */
%start line

%token <id> IDENTIFIER
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
%token IF
%token ELSE
%token MODULUS
%token DRAW
%token END
%token MOVE
%token ANIMATE
%token COS
%token SIN
%token <intT> INTEGER 
%token <floatT> FLOAT

%type line
%type frame
%type body
%type loop
%type wait 
%type assignment 
%type var_declare 
%type set_color
%type draw_shape
%type <floatT> exp term float_r fcos fsin

%%
line: frame {printf("Program finished executing \n");}
	| assignment ';' {;}
    | assignment ';' line {;}
    ;

frame: FRAME '{' body '}' {printf("Executing frame \n");}
	 | error { fprintf(stderr, "Syntax error in frame \n"); yyerror; }
	 ;

body: assignment ';' {;}
	| wait ';' {;}
	| loop {;}
	| set_color ';' {;}
	| draw_shape ';' {;}
	| body assignment ';' {;}
	| body wait ';' {;}
	| body loop {;}
	| body set_color ';' {;}
	| body draw_shape ';' {;}
	| error { fprintf(stderr, "Syntax error in body \n"); yyerror; }
	;

assignment: IDENTIFIER '=' INTEGER {
				updateSymbolVal($1, $3);
				printf("new symbol = %d \n", $3);
		  }
		  |
		  var_declare {;}
		  | error { fprintf(stderr, "Syntax error in assignment \n"); yyerror; }
          ;

var_declare: '(' INT ')' IDENTIFIER {printf("Declared as int succesfully \n");}
		   | '(' COLOR	')' IDENTIFIER {printf("Declared color succesfully \n");}
		   | error { fprintf(stderr, "Syntax error in var_declare \n"); yyerror; }
		   ; 

wait: WAIT '(' INTEGER ')' {printf("wait = \n");}
	| error { fprintf(stderr, "Syntax error in wait \n"); yyerror; }
    ;

loop: LOOP '(' assignment ';' assignment ';' assignment ')' '{' body '}' {
	printf("Executing loop \n");
	}
	| error { fprintf(stderr, "Syntax error in loop \n"); yyerror; }
	;

set_color: SETCOLOR '(' IDENTIFIER ')' {printf("color set \n");}
		 ;

draw_shape: DRAW PIXEL '(' float_r ',' float_r ')' {
	printf("shape drawn \n");
	}
		  | DRAW LINE '(' float_r ',' float_r ',' float_r ',' float_r ')' {
			printf("shape drawn \n");
			}
		  | DRAW RECT '(' float_r ',' float_r ',' float_r ',' float_r ')' {
			printf("shape drawn \n");
			}
		  | DRAW CIRCLE '(' float_r ',' float_r ',' float_r ')' {
			printf("shape drawn \n");
			}
		  | error { fprintf(stderr, "Syntax error in draw_shape \n"); yyerror; }
		  ;

exp: term {$$ = $1;}
	| exp '+' term {$$ = $1 + $3;}
	| exp '-' term {$$ = $1 - $3;}
	| exp '*' term {$$ = $1 * $3;}
	| exp '/' term {$$ = $1 / $3;}
	//| exp '%' term {$$ = $1 % $3;}
	;

term: INTEGER {$$ = $1;}
		| IDENTIFIER {$$ = symbolVal($1);} 
        ;

fcos: COS '(' exp ')' {printf("soy un cos \n");}
	;

fsin: SIN '(' exp ')'{printf("soy un sin \n");}
	;

float_r: INTEGER {;}
	   | FLOAT {;}
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

/* returns the value of a given symbol */
int symbolVal(char symbol)
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

/* updates the value of a given symbol */
void updateSymbolVal(char symbol, int val)
{
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

int main (void) {
	/* init symbol table */
	int i;
	for(i=0; i<52; i++) {
		symbols[i] = 0;
	}

	return yyparse ( );
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 