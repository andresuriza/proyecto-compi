%{
#include <stdio.h>
int yylex();
void yyerror(const char *s);
%}

%token IDENT
%token NUMBER
%token FUNC
%token LPAR
%token RPAR
%token LCURLY
%token RCURLY
%token INT
%token COLOR
%token COLORTYP
%token COORD
%token SEMICOLON
%token EQUALS
%token SHAPEFOUR
%token SHAPETHREE
%token SHAPETWO
%token DRAW
%token COMMA
%token SETCOLOR
%token WAIT
%token FRAME
%token LOOP
%token LT
%token GT
%token PLUS
%token IF
%token ELSE

%start program

%%
program: functions {printf("program -> functions\n");}

functions: declaration functions {printf("functions -> declaration functions\n");}
         | frame {printf("functions -> frame\n");}

frame: FRAME LCURLY body RCURLY {printf("frame -> FRAME LCURLY body RCURLY\n");}

body:   loop body {printf("body -> loop\n");}
        | if body {printf("functions -> drawing functions\n");}
        | else body {printf("functions -> drawing functions\n");}
        | elseif body {printf("functions -> drawing functions\n");}
        | drawing body {printf("functions -> drawing functions\n");}
        | declaration body {printf("declaration -> declaration functions\n");}
        | setcolor body {printf("declaration -> setcolor functions\n");}
        | wait body {printf("declaration -> wait functions\n");}
        | %empty {printf("frame -> empty\n");}

loop: LOOP LPAR IDENT EQUALS NUMBER SEMICOLON IDENT LT NUMBER SEMICOLON IDENT EQUALS IDENT PLUS NUMBER RPAR LCURLY body RCURLY
    {printf("loop -> LOOP LPAR IDENT EQUALS NUMBER SEMICOLON IDENT LT NUMBER SEMICOLON IDENT EQUALS IDENT PLUS NUMBER RPAR LCURLY body RCURLY\n");}

condition: IDENT GT NUMBER {printf("condition -> IDENT GT NUMBER \n");}
           | IDENT LT NUMBER {printf("condition -> IDENT LT NUMBER \n");}
           | IDENT EQUALS EQUALS NUMBER {printf("condition -> IDENT EQUALS EQUALS NUMBER  \n");}

if: IF LPAR condition RPAR LCURLY body RCURLY {printf("if -> IF LPAR condition RPAR LCURLY body RCURLY \n");}

else: ELSE LCURLY body RCURLY {printf("else -> ELSE LCURLY body RCURLY \n");}

elseif: ELSE IF LPAR condition RPAR LCURLY body RCURLY 
        {printf("elseif -> ELSE IF LPAR condition RPAR LCURLY body RCURLY \n");}

drawing: DRAW SHAPEFOUR LPAR NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER RPAR SEMICOLON 
         {printf("drawing -> DRAW SHAPE LPAR NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER RPAR SEMICOLON\n");}
         |
         DRAW SHAPETHREE LPAR NUMBER COMMA NUMBER COMMA NUMBER RPAR SEMICOLON 
         {printf("drawing -> DRAW SHAPE LPAR NUMBER COMMA NUMBER COMMA NUMBER RPAR SEMICOLON\n");}
         |
         DRAW SHAPETWO LPAR NUMBER COMMA NUMBER RPAR SEMICOLON 
         {printf("drawing -> DRAW SHAPE LPAR NUMBER COMMA NUMBER RPAR SEMICOLON\n");}
         |
         DRAW SHAPETWO LPAR IDENT COMMA IDENT RPAR SEMICOLON 
         {printf("drawing -> DRAW SHAPE LPAR IDENT COMMA IDENT RPAR SEMICOLON\n");}

setcolor: SETCOLOR LPAR COLORTYP RPAR SEMICOLON {printf("setcolor -> SETCOLOR LPAR COLORTYP RPAR SEMICOLON\n");}
          | SETCOLOR LPAR IDENT RPAR SEMICOLON {printf("setcolor -> SETCOLOR LPAR IDENT RPAR SEMICOLON\n");}

wait: WAIT LPAR NUMBER RPAR SEMICOLON {printf("wait -> WAIT LPAR NUMBER RPAR SEMICOLON\n");} 

declaration: LPAR INT RPAR IDENT EQUALS NUMBER SEMICOLON 
             {printf("declaration -> LPAR INTEGER RPAR IDENT EQUALS NUMBER SEMICOLON\n");}
           | IDENT EQUALS NUMBER SEMICOLON {printf("declaration -> IDENT EQUALS NUMBER SEMICOLON \n");}
           | IDENT EQUALS COLORTYP SEMICOLON {printf("declaration -> IDENT EQUALS COLORTYP SEMICOLON \n");}
           | LPAR COLOR RPAR IDENT EQUALS COLORTYP SEMICOLON 
             {printf("declaration -> LPAR COLOR RPAR IDENT EQUALS ROJO SEMICOLON\n");}
           | LPAR INT RPAR IDENT SEMICOLON {printf("declaration -> LPAR INT RPAR IDENT SEMICOLON\n");}
           | LPAR COLOR RPAR IDENT SEMICOLON {printf("declaration -> LPAR COLOR RPAR IDENT SEMICOLON\n");}
%%

int main(void) {
    yyparse();
}

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}