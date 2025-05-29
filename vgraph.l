%{
#include "vgraph.tab.h"
void yyerror (char *s);
int yylex();
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
"int" { return INT; }
"color" { return COLOR; }
[0-9]+ {yylval.intT = atoi(yytext); return INTEGER;}
[0-9]+"."[0-9]+ {yylval.floatT = atoi(yytext); return FLOAT;}
[a-z][a-zA-Z0-9]* {yylval.id = yytext[0]; return IDENTIFIER;}
[-+*%/={};,()] {return yytext[0];}
"#".* {} // Para comentarios
[ \t\n] ;

%%

int yywrap (void) {return 1;}