%{
#include "ast.h"
#include "y.tab.h"
#include <stdlib.h>
void yyerror (char *);
%}

%%

"draw" { return DRAW; }
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
[a-z][a-zA-Z0-9]* {yylval.sIndex = yylval.sIndex = *yytext - 'a'; return VARIABLE;}
[-+*%/!={};,()><] {return *yytext;}
"#".* {} // Para comentarios
[ \t\n]+ ;
.   yyerror("Unknown character");

%%

int yywrap(void) {
    return 1;
}