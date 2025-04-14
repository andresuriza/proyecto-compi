%{
#include "calc.tab.h"
%}

%%
"print"     {return print;}
"exit"      {return exit_command;}
"draw"      {return draw;}
[a-zA-Z]        {yylval.id = yytext[0]; return identifier;}
[0-9]+      {yylval.num = atoi(yytext); return number;}
[ \t\f\v\n]     ;
[-+=*/;]      {return yytext[0];}
.       {ECHO; yyerror ("unexpected character");}

%%

int yywrap (void) {return 1;}