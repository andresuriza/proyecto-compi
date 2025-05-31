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
    IF = 260,                      /* IF  */
    IFX = 261,                     /* IFX  */
    ELSE = 262,                    /* ELSE  */
    UMINUS = 263,                  /* UMINUS  */
    FUNC = 264,                    /* FUNC  */
    INT = 265,                     /* INT  */
    COLOR = 266,                   /* COLOR  */
    COORD = 267,                   /* COORD  */
    LINE = 268,                    /* LINE  */
    RECT = 269,                    /* RECT  */
    CIRCLE = 270,                  /* CIRCLE  */
    PIXEL = 271,                   /* PIXEL  */
    SETCOLOR = 272,                /* SETCOLOR  */
    WAIT = 273,                    /* WAIT  */
    FRAME = 274,                   /* FRAME  */
    LOOP = 275,                    /* LOOP  */
    LT = 276,                      /* LT  */
    GT = 277,                      /* GT  */
    PLUS = 278,                    /* PLUS  */
    MODULUS = 279,                 /* MODULUS  */
    DRAW = 280,                    /* DRAW  */
    END = 281,                     /* END  */
    MOVE = 282,                    /* MOVE  */
    ANIMATE = 283,                 /* ANIMATE  */
    COS = 284,                     /* COS  */
    SIN = 285,                     /* SIN  */
    FLOAT = 286,                   /* FLOAT  */
    PRINT = 287                    /* PRINT  */
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
#define IF 260
#define IFX 261
#define ELSE 262
#define UMINUS 263
#define FUNC 264
#define INT 265
#define COLOR 266
#define COORD 267
#define LINE 268
#define RECT 269
#define CIRCLE 270
#define PIXEL 271
#define SETCOLOR 272
#define WAIT 273
#define FRAME 274
#define LOOP 275
#define LT 276
#define GT 277
#define PLUS 278
#define MODULUS 279
#define DRAW 280
#define END 281
#define MOVE 282
#define ANIMATE 283
#define COS 284
#define SIN 285
#define FLOAT 286
#define PRINT 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "vgraph.y"

    double dValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */

#line 137 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
