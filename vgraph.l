%{
#include "ast.h"
#include "y.tab.h"
#include <stdlib.h>
void yyerror (char *);
%}

%%

"draw" { return DRAW; }
"rojo" { yylval.id = strdup(yytext); return CTYPE; }
"verde" { yylval.id = strdup(yytext); return CTYPE; }
"azul" { yylval.id = strdup(yytext); return CTYPE; }
"setcolor" { return SETCOLOR; }
"frame" { return FRAME; }
"loop" { return LOOP; }
"if" { return IF; }
"else" { return ELSE; }
"end" { return END; }
"wait" { return WAIT; }
"line" { return LINE; }
"circle" { return CIRCLE; }
"rect" { return RECT; }
"tree" { return TREE; }
"move" { return MOVE; }
"animate" { return ANIMATE; }
"cos" { return COS; }
"sin" { return SIN; }
"pixel" { return PIXEL; }
"print" { return PRINT; }
"int"       { return INT; }
"float"     { return FLOAT; }
"color"     { return COLOR; }

[0-9]+\.[0-9]+ {yylval.dValue = atof(yytext); return INTEGER;}
[0-9]+ {yylval.dValue = atoi(yytext); return INTEGER;}
[a-z][a-zA-Z0-9]* {yylval.id = strdup(yytext); return VARIABLE;}
[-+*%/!={};,()><] {return *yytext;}
"#".* {} // Para comentarios
[ \t\n]+ ;
.   yyerror("Unknown character");

%%

int yywrap(void) {
    return 1;
}