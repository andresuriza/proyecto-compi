/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "vgraph.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast.h"
#include <ctype.h>
#include <string.h>

nodeType *opr(int oper, int nops, ...);
nodeType *id(char* name);
nodeType *con(double value);
nodeType *conColor(const char *value);

Symbol *symbolTable = NULL;

void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);
//void addPredefinedConstants();

void yyerror(char *s);

#line 94 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    CTYPE = 260,                   /* CTYPE  */
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
    LE = 275,                      /* LE  */
    GE = 276,                      /* GE  */
    NE = 277,                      /* NE  */
    EQ = 278,                      /* EQ  */
    PLUS = 279,                    /* PLUS  */
    MODULUS = 280,                 /* MODULUS  */
    DRAW = 281,                    /* DRAW  */
    TREE = 282,                    /* TREE  */
    END = 283,                     /* END  */
    MOVE = 284,                    /* MOVE  */
    ANIMATE = 285,                 /* ANIMATE  */
    COS = 286,                     /* COS  */
    SIN = 287,                     /* SIN  */
    PRINT = 288,                   /* PRINT  */
    INT = 289,                     /* INT  */
    FLOAT = 290,                   /* FLOAT  */
    COLOR = 291                    /* COLOR  */
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
#define CTYPE 260
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
#define LE 275
#define GE 276
#define NE 277
#define EQ 278
#define PLUS 279
#define MODULUS 280
#define DRAW 281
#define TREE 282
#define END 283
#define MOVE 284
#define ANIMATE 285
#define COS 286
#define SIN 287
#define PRINT 288
#define INT 289
#define FLOAT 290
#define COLOR 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "vgraph.y"

    double dValue;
    char* id;      // index into symbolTable
    nodeType* nPtr;

#line 225 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_VARIABLE = 4,                   /* VARIABLE  */
  YYSYMBOL_CTYPE = 5,                      /* CTYPE  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_IFX = 7,                        /* IFX  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_9_ = 9,                         /* '>'  */
  YYSYMBOL_10_ = 10,                       /* '<'  */
  YYSYMBOL_11_ = 11,                       /* '+'  */
  YYSYMBOL_12_ = 12,                       /* '-'  */
  YYSYMBOL_13_ = 13,                       /* '*'  */
  YYSYMBOL_14_ = 14,                       /* '/'  */
  YYSYMBOL_15_ = 15,                       /* '%'  */
  YYSYMBOL_UMINUS = 16,                    /* UMINUS  */
  YYSYMBOL_FUNC = 17,                      /* FUNC  */
  YYSYMBOL_COORD = 18,                     /* COORD  */
  YYSYMBOL_LINE = 19,                      /* LINE  */
  YYSYMBOL_RECT = 20,                      /* RECT  */
  YYSYMBOL_CIRCLE = 21,                    /* CIRCLE  */
  YYSYMBOL_PIXEL = 22,                     /* PIXEL  */
  YYSYMBOL_SETCOLOR = 23,                  /* SETCOLOR  */
  YYSYMBOL_WAIT = 24,                      /* WAIT  */
  YYSYMBOL_FRAME = 25,                     /* FRAME  */
  YYSYMBOL_LOOP = 26,                      /* LOOP  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_GE = 28,                        /* GE  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_PLUS = 31,                      /* PLUS  */
  YYSYMBOL_MODULUS = 32,                   /* MODULUS  */
  YYSYMBOL_DRAW = 33,                      /* DRAW  */
  YYSYMBOL_TREE = 34,                      /* TREE  */
  YYSYMBOL_END = 35,                       /* END  */
  YYSYMBOL_MOVE = 36,                      /* MOVE  */
  YYSYMBOL_ANIMATE = 37,                   /* ANIMATE  */
  YYSYMBOL_COS = 38,                       /* COS  */
  YYSYMBOL_SIN = 39,                       /* SIN  */
  YYSYMBOL_PRINT = 40,                     /* PRINT  */
  YYSYMBOL_INT = 41,                       /* INT  */
  YYSYMBOL_FLOAT = 42,                     /* FLOAT  */
  YYSYMBOL_COLOR = 43,                     /* COLOR  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_50_ = 50,                       /* '='  */
  YYSYMBOL_51_ = 51,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_program = 53,                   /* program  */
  YYSYMBOL_function = 54,                  /* function  */
  YYSYMBOL_frame = 55,                     /* frame  */
  YYSYMBOL_stmt = 56,                      /* stmt  */
  YYSYMBOL_var_type = 57,                  /* var_type  */
  YYSYMBOL_var_list = 58,                  /* var_list  */
  YYSYMBOL_assignment = 59,                /* assignment  */
  YYSYMBOL_conditional_body = 60,          /* conditional_body  */
  YYSYMBOL_stmt_list = 61,                 /* stmt_list  */
  YYSYMBOL_expr = 62,                      /* expr  */
  YYSYMBOL_conditional = 63                /* conditional  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    15,     2,     2,
      47,    48,    13,    11,    49,    12,     2,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
      10,    50,     9,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    79,    80,    81,    85,    90,    91,    92,
      93,    94,    97,    98,    99,   100,   101,   102,   109,   110,
     114,   115,   119,   123,   124,   128,   129,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   148,
     149,   150,   151,   152,   153
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "VARIABLE",
  "CTYPE", "IF", "IFX", "ELSE", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "FUNC", "COORD", "LINE", "RECT", "CIRCLE", "PIXEL",
  "SETCOLOR", "WAIT", "FRAME", "LOOP", "LE", "GE", "NE", "EQ", "PLUS",
  "MODULUS", "DRAW", "TREE", "END", "MOVE", "ANIMATE", "COS", "SIN",
  "PRINT", "INT", "FLOAT", "COLOR", "'{'", "'}'", "';'", "'('", "')'",
  "','", "'='", "'!'", "$accept", "program", "function", "frame", "stmt",
  "var_type", "var_list", "assignment", "conditional_body", "stmt_list",
  "expr", "conditional", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -99,     5,    92,   -99,   -99,   -44,   -99,   -39,   195,   -34,
     -25,   -13,    -4,   -20,    -3,     0,   -99,   200,   -99,   -99,
       4,     9,   313,   195,   195,   -99,   195,   -99,   195,   195,
     190,    47,     6,    16,   195,   195,     8,    14,   245,   -99,
     -99,   195,   195,   195,   195,   195,   -99,   318,   239,    18,
     250,   255,   -99,    96,   -44,    22,   195,   195,   260,   265,
      76,    76,   -99,    15,    15,   -99,   -99,   -99,     7,    20,
      38,    41,   141,    48,    59,   -99,   -99,   195,    27,    60,
     -99,   -99,   -99,    44,    44,   195,   318,   195,   318,   195,
     195,   190,    56,   190,   -99,   -99,    61,   195,   195,   106,
     318,   318,   318,   318,   145,   141,    47,   270,    72,   -99,
     -99,   -99,    64,    68,   195,   141,   -99,   148,   -99,   195,
     206,   195,   308,    77,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     1,    27,    29,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     4,     3,
       0,     0,     0,     0,     0,    29,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
      10,     0,     0,     0,     0,     0,     9,    22,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     6,    26,     0,     0,     0,
      36,    37,    20,    18,    19,     0,    40,     0,    39,     0,
       0,     0,    12,    24,    14,    15,     0,     0,     0,     0,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    21,
      23,    13,     0,     0,     0,     0,    16,     0,    11,     0,
       0,     0,     0,     0,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   -99,   -99,    -1,   -99,    63,   -28,   -98,   -26,
      -8,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    18,    52,    20,    83,    21,    92,    93,
      22,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    19,    32,    55,    53,     3,    23,   111,    24,    38,
       4,    25,     6,    28,    33,    47,    48,   118,    38,     8,
      50,    51,    29,     4,    25,     6,    58,    59,    43,    44,
      45,    30,     8,    63,    64,    65,    66,    67,    41,    42,
      43,    44,    45,    31,    34,    14,    15,    35,    78,    79,
      39,    54,    76,    56,    26,    40,    60,    85,    14,    15,
      86,    88,    61,    57,   105,   104,    72,    26,    77,    48,
      87,    41,    42,    43,    44,    45,    97,   100,   112,   101,
      82,   102,   103,    41,    42,    43,    44,    45,    89,   107,
     108,    90,    76,    99,    94,     4,     5,     6,     7,     4,
       5,     6,     7,    76,     8,    95,   117,   106,     8,    98,
     109,   120,   115,   122,   116,     9,    10,    11,    12,     9,
      10,   114,    12,   124,    84,    13,    96,     0,     0,    13,
      14,    15,     0,     0,    14,    15,     0,     0,    16,    17,
       0,    75,    16,    17,     4,     5,     6,     7,     4,     5,
       6,     7,     0,     8,     0,     0,     0,     8,     0,    41,
      42,    43,    44,    45,     9,    10,     0,    12,     9,    10,
       0,    12,     0,     0,    13,     0,     0,     0,    13,    14,
      15,     0,     0,    14,    15,    91,     0,    16,    17,     0,
     110,    16,    17,     4,     5,     6,     7,   119,     4,    25,
       6,     0,     8,     4,    25,     6,     0,     8,     0,     0,
       0,     0,     8,     9,    10,     0,    12,    41,    42,    43,
      44,    45,     0,    13,     0,     0,     0,     0,    14,    15,
       0,     0,     0,    14,    15,     0,    16,    17,    14,    15,
       0,    36,    26,    37,     0,     0,     0,    26,    68,    69,
      41,    42,    43,    44,    45,   121,    41,    42,    43,    44,
      45,    41,    42,    43,    44,    45,    41,    42,    43,    44,
      45,    41,    42,    43,    44,    45,    41,    42,    43,    44,
      45,    41,    42,    43,    44,    45,     0,     0,     0,    70,
      71,     0,     0,    62,     0,     0,     0,     0,    73,     0,
       0,     0,     0,    74,     0,     0,     0,     0,    80,     0,
       0,     0,     0,    81,     0,     0,     0,     0,   113,    41,
      42,    43,    44,    45,    41,    42,    43,    44,    45,    41,
      42,    43,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,    46
};

static const yytype_int8 yycheck[] =
{
       8,     2,    22,    31,    30,     0,    50,   105,    47,    17,
       3,     4,     5,    47,    34,    23,    24,   115,    26,    12,
      28,    29,    47,     3,     4,     5,    34,    35,    13,    14,
      15,    44,    12,    41,    42,    43,    44,    45,    11,    12,
      13,    14,    15,    47,    47,    38,    39,    47,    56,    57,
      46,     4,    53,    47,    47,    46,    48,    50,    38,    39,
      68,    69,    48,    47,     8,    91,    48,    47,    46,    77,
      50,    11,    12,    13,    14,    15,    49,    85,   106,    87,
       4,    89,    90,    11,    12,    13,    14,    15,    50,    97,
      98,    50,    93,    49,    46,     3,     4,     5,     6,     3,
       4,     5,     6,   104,    12,    46,   114,    46,    12,    49,
       4,   119,    48,   121,    46,    23,    24,    25,    26,    23,
      24,    49,    26,    46,    61,    33,    77,    -1,    -1,    33,
      38,    39,    -1,    -1,    38,    39,    -1,    -1,    46,    47,
      -1,    45,    46,    47,     3,     4,     5,     6,     3,     4,
       5,     6,    -1,    12,    -1,    -1,    -1,    12,    -1,    11,
      12,    13,    14,    15,    23,    24,    -1,    26,    23,    24,
      -1,    26,    -1,    -1,    33,    -1,    -1,    -1,    33,    38,
      39,    -1,    -1,    38,    39,    44,    -1,    46,    47,    -1,
      45,    46,    47,     3,     4,     5,     6,    49,     3,     4,
       5,    -1,    12,     3,     4,     5,    -1,    12,    -1,    -1,
      -1,    -1,    12,    23,    24,    -1,    26,    11,    12,    13,
      14,    15,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    38,    39,    -1,    46,    47,    38,    39,
      -1,    41,    47,    43,    -1,    -1,    -1,    47,     9,    10,
      11,    12,    13,    14,    15,    49,    11,    12,    13,    14,
      15,    11,    12,    13,    14,    15,    11,    12,    13,    14,
      15,    11,    12,    13,    14,    15,    11,    12,    13,    14,
      15,    11,    12,    13,    14,    15,    -1,    -1,    -1,    50,
      51,    -1,    -1,    48,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    48,    11,
      12,    13,    14,    15,    11,    12,    13,    14,    15,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,    54,     0,     3,     4,     5,     6,    12,    23,
      24,    25,    26,    33,    38,    39,    46,    47,    55,    56,
      57,    59,    62,    50,    47,     4,    47,    62,    47,    47,
      44,    47,    22,    34,    47,    47,    41,    43,    62,    46,
      46,    11,    12,    13,    14,    15,    46,    62,    62,    63,
      62,    62,    56,    61,     4,    59,    47,    47,    62,    62,
      48,    48,    48,    62,    62,    62,    62,    62,     9,    10,
      50,    51,    48,    48,    48,    45,    56,    46,    62,    62,
      48,    48,     4,    58,    58,    50,    62,    50,    62,    50,
      50,    44,    60,    61,    46,    46,    63,    49,    49,    49,
      62,    62,    62,    62,    61,     8,    46,    62,    62,     4,
      45,    60,    59,    48,    49,    48,    46,    62,    60,    49,
      62,    49,    62,    48,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    59,    60,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     4,     1,     2,     2,
       2,     9,     5,     7,     5,     5,     8,    14,     4,     4,
       1,     3,     3,     3,     1,     1,     2,     1,     1,     1,
       2,     3,     3,     3,     3,     3,     4,     4,     3,     3,
       3,     4,     4,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: function  */
#line 75 "vgraph.y"
                 { exit(0); }
#line 1384 "y.tab.c"
    break;

  case 3: /* function: function stmt  */
#line 79 "vgraph.y"
                        { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1390 "y.tab.c"
    break;

  case 4: /* function: function frame  */
#line 80 "vgraph.y"
                         { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1396 "y.tab.c"
    break;

  case 6: /* frame: FRAME '{' stmt_list '}'  */
#line 85 "vgraph.y"
                                  { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1402 "y.tab.c"
    break;

  case 7: /* stmt: ';'  */
#line 90 "vgraph.y"
                { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1408 "y.tab.c"
    break;

  case 8: /* stmt: var_type ';'  */
#line 91 "vgraph.y"
                       { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1414 "y.tab.c"
    break;

  case 9: /* stmt: expr ';'  */
#line 92 "vgraph.y"
                    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1420 "y.tab.c"
    break;

  case 10: /* stmt: assignment ';'  */
#line 93 "vgraph.y"
                          { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1426 "y.tab.c"
    break;

  case 11: /* stmt: LOOP '(' assignment ';' conditional ';' assignment ')' conditional_body  */
#line 94 "vgraph.y"
                                                                                   { 
                (yyval.nPtr) = opr(LOOP, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); 
            }
#line 1434 "y.tab.c"
    break;

  case 12: /* stmt: IF '(' conditional ')' conditional_body  */
#line 97 "vgraph.y"
                                                               { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1440 "y.tab.c"
    break;

  case 13: /* stmt: IF '(' conditional ')' conditional_body ELSE conditional_body  */
#line 98 "vgraph.y"
                                                                         { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1446 "y.tab.c"
    break;

  case 14: /* stmt: SETCOLOR '(' expr ')' ';'  */
#line 99 "vgraph.y"
                                     { (yyval.nPtr) = opr(SETCOLOR, 1, (yyvsp[-2].nPtr)); }
#line 1452 "y.tab.c"
    break;

  case 15: /* stmt: WAIT '(' expr ')' ';'  */
#line 100 "vgraph.y"
                                 { (yyval.nPtr) = opr(WAIT, 1, (yyvsp[-2].nPtr)); }
#line 1458 "y.tab.c"
    break;

  case 16: /* stmt: DRAW PIXEL '(' expr ',' expr ')' ';'  */
#line 101 "vgraph.y"
                                                { (yyval.nPtr) = opr(PIXEL, 2, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr)); }
#line 1464 "y.tab.c"
    break;

  case 17: /* stmt: DRAW TREE '(' expr ',' expr ',' expr ',' expr ',' expr ')' ';'  */
#line 102 "vgraph.y"
                                                                          { 
                (yyval.nPtr) = opr(TREE, 2, (yyvsp[-10].nPtr), (yyvsp[-8].nPtr), (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr)); 
            }
#line 1472 "y.tab.c"
    break;

  case 18: /* var_type: '(' INT ')' var_list  */
#line 109 "vgraph.y"
                               { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1478 "y.tab.c"
    break;

  case 19: /* var_type: '(' COLOR ')' var_list  */
#line 110 "vgraph.y"
                                  { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1484 "y.tab.c"
    break;

  case 20: /* var_list: VARIABLE  */
#line 114 "vgraph.y"
                 { (yyval.nPtr) = opr('=', 2, id((yyvsp[0].id)), 0); }
#line 1490 "y.tab.c"
    break;

  case 21: /* var_list: var_list ',' VARIABLE  */
#line 115 "vgraph.y"
                                { (yyval.nPtr) = opr('=', 2, id((yyvsp[0].id)), 0); }
#line 1496 "y.tab.c"
    break;

  case 22: /* assignment: VARIABLE '=' expr  */
#line 119 "vgraph.y"
                             { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].id)), (yyvsp[0].nPtr)); }
#line 1502 "y.tab.c"
    break;

  case 23: /* conditional_body: '{' stmt_list '}'  */
#line 123 "vgraph.y"
                            { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1508 "y.tab.c"
    break;

  case 24: /* conditional_body: stmt_list  */
#line 124 "vgraph.y"
                      { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1514 "y.tab.c"
    break;

  case 25: /* stmt_list: stmt  */
#line 128 "vgraph.y"
                                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1520 "y.tab.c"
    break;

  case 26: /* stmt_list: stmt_list stmt  */
#line 129 "vgraph.y"
                                { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1526 "y.tab.c"
    break;

  case 27: /* expr: INTEGER  */
#line 133 "vgraph.y"
                                { (yyval.nPtr) = con((yyvsp[0].dValue)); }
#line 1532 "y.tab.c"
    break;

  case 28: /* expr: CTYPE  */
#line 134 "vgraph.y"
                             { (yyval.nPtr) = conColor((yyvsp[0].id)); }
#line 1538 "y.tab.c"
    break;

  case 29: /* expr: VARIABLE  */
#line 135 "vgraph.y"
                                { (yyval.nPtr) = id((yyvsp[0].id)); }
#line 1544 "y.tab.c"
    break;

  case 30: /* expr: '-' expr  */
#line 136 "vgraph.y"
                                { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1550 "y.tab.c"
    break;

  case 31: /* expr: expr '+' expr  */
#line 137 "vgraph.y"
                                { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1556 "y.tab.c"
    break;

  case 32: /* expr: expr '-' expr  */
#line 138 "vgraph.y"
                                { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1562 "y.tab.c"
    break;

  case 33: /* expr: expr '*' expr  */
#line 139 "vgraph.y"
                                { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1568 "y.tab.c"
    break;

  case 34: /* expr: expr '/' expr  */
#line 140 "vgraph.y"
                                { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1574 "y.tab.c"
    break;

  case 35: /* expr: expr '%' expr  */
#line 141 "vgraph.y"
                                { (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1580 "y.tab.c"
    break;

  case 36: /* expr: COS '(' expr ')'  */
#line 142 "vgraph.y"
                                { (yyval.nPtr) = opr(COS, 1, (yyvsp[-1].nPtr)); }
#line 1586 "y.tab.c"
    break;

  case 37: /* expr: SIN '(' expr ')'  */
#line 143 "vgraph.y"
                                { (yyval.nPtr) = opr(SIN, 1, (yyvsp[-1].nPtr)); }
#line 1592 "y.tab.c"
    break;

  case 38: /* expr: '(' expr ')'  */
#line 144 "vgraph.y"
                                { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1598 "y.tab.c"
    break;

  case 39: /* conditional: expr '<' expr  */
#line 148 "vgraph.y"
                                 { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1604 "y.tab.c"
    break;

  case 40: /* conditional: expr '>' expr  */
#line 149 "vgraph.y"
                                 { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1610 "y.tab.c"
    break;

  case 41: /* conditional: expr '>' '=' expr  */
#line 150 "vgraph.y"
                                    { (yyval.nPtr) = opr(GE, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1616 "y.tab.c"
    break;

  case 42: /* conditional: expr '<' '=' expr  */
#line 151 "vgraph.y"
                                    { (yyval.nPtr) = opr(LE, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1622 "y.tab.c"
    break;

  case 43: /* conditional: expr '=' '=' expr  */
#line 152 "vgraph.y"
                                    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1628 "y.tab.c"
    break;

  case 44: /* conditional: expr '!' '=' expr  */
#line 153 "vgraph.y"
                                    { (yyval.nPtr) = opr(NE, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1634 "y.tab.c"
    break;


#line 1638 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 160 "vgraph.y"


nodeType *conColor(const char *name) {
    nodeType *p = malloc(sizeof(nodeType));
    p->type = typeCon;
    
    if (strcmp(name, "rojo") == 0) {
        p->con.value = ROJO;
        p->con.type = SYM_COLOR;
    }

    else if (strcmp(name, "verde") == 0) {
        p->con.value = VERDE;
        p->con.type = SYM_COLOR;
    }

    else if (strcmp(name, "azul") == 0) {
        p->con.value = AZUL;
        p->con.type = SYM_COLOR;
    }  
    
    else {
        yyerror("Unknown color");
    }
    return p;
}

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

nodeType *id(char* name) {
    nodeType *p;

    // allocate node
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    // copy information
    p->type = typeId;
    p->id.name = strdup(name);

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
    //addPredefinedConstants();

    yyparse();

    return 0;
}
