/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    VARIABLE = 259,                /* VARIABLE  */
    COLORTYPE = 260,               /* COLORTYPE  */
    IF = 261,                      /* IF  */
    IFX = 262,                     /* IFX  */
    ELSE = 263,                    /* ELSE  */
    UMINUS = 264,                  /* UMINUS  */
    FUNC = 265,                    /* FUNC  */
    COORD = 266,                   /* COORD  */
    LINE = 267,                    /* LINE  */
    RECT = 268,                    /* RECT  */
    CIRCLE = 269,                  /* CIRCLE  */
    PIXEL = 270,                   /* PIXEL  */
    SETCOLOR = 271,                /* SETCOLOR  */
    WAIT = 272,                    /* WAIT  */
    FRAME = 273,                   /* FRAME  */
    LOOP = 274,                    /* LOOP  */
    DRAW = 275,                    /* DRAW  */
    END = 276,                     /* END  */
    MOVE = 277,                    /* MOVE  */
    ANIMATE = 278,                 /* ANIMATE  */
    COS = 279,                     /* COS  */
    SIN = 280,                     /* SIN  */
    INT = 281,                     /* INT  */
    COLOR = 282,                   /* COLOR  */
    GE = 283,                      /* GE  */
    LE = 284,                      /* LE  */
    EQ = 285,                      /* EQ  */
    NE = 286,                      /* NE  */
    I_DECL = 287,                  /* I_DECL  */
    C_DECL = 288,                  /* C_DECL  */
    FUNCTION = 289,                /* FUNCTION  */
    RETURN = 290,                  /* RETURN  */
    CLEAR = 291                    /* CLEAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTEGER 258
#define VARIABLE 259
#define COLORTYPE 260
#define IF 261
#define IFX 262
#define ELSE 263
#define UMINUS 264
#define FUNC 265
#define COORD 266
#define LINE 267
#define RECT 268
#define CIRCLE 269
#define PIXEL 270
#define SETCOLOR 271
#define WAIT 272
#define FRAME 273
#define LOOP 274
#define DRAW 275
#define END 276
#define MOVE 277
#define ANIMATE 278
#define COS 279
#define SIN 280
#define INT 281
#define COLOR 282
#define GE 283
#define LE 284
#define EQ 285
#define NE 286
#define I_DECL 287
#define C_DECL 288
#define FUNCTION 289
#define RETURN 290
#define CLEAR 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "vgraph.y"

    double dValue;
    char* id;
    nodeType* nPtr;

#line 145 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
