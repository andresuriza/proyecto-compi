%{
#include <stdio.h>
#include "vgraph.tab.h"
%}

%%
"frame" { return FRAME; }
"loop" { return LOOP; }
"int" { return INT; }
"color" { return COLOR; }
"draw" { return DRAW; }
"setcolor" { return SETCOLOR; }
"wait" { return WAIT; }
(rojo|verde|azul) { return COLORTYP; }
(line|rect) { return SHAPEFOUR; }
"circle" { return SHAPETHREE; }
"pixel" { return SHAPETWO; }
"if" { return IF; }
"else" { return ELSE; }
"(" { return LPAR; }
")" { return RPAR; }
"{" { return LCURLY; }
"}" { return RCURLY; }
[0-9]+ { return NUMBER; }
[a-z]+ { return IDENT; }
[=] {return EQUALS; }
[<] {return LT; }
[>] {return GT; }
"+" {return PLUS; }
[,] { return COMMA; }
[;] { return SEMICOLON; }
[ \t\n] {}
%%