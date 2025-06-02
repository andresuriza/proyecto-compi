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

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(double value);

void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(char *s);
double sym[26];                    /* symbol table */

#line 90 "y.tab.c"

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
    IF = 260,                      /* IF  */
    IFX = 261,                     /* IFX  */
    ELSE = 262,                    /* ELSE  */
    UMINUS = 263,                  /* UMINUS  */
    FUNC = 264,                    /* FUNC  */
    COORD = 265,                   /* COORD  */
    LINE = 266,                    /* LINE  */
    RECT = 267,                    /* RECT  */
    CIRCLE = 268,                  /* CIRCLE  */
    PIXEL = 269,                   /* PIXEL  */
    SETCOLOR = 270,                /* SETCOLOR  */
    WAIT = 271,                    /* WAIT  */
    FRAME = 272,                   /* FRAME  */
    LOOP = 273,                    /* LOOP  */
    LE = 274,                      /* LE  */
    GE = 275,                      /* GE  */
    NE = 276,                      /* NE  */
    EQ = 277,                      /* EQ  */
    PLUS = 278,                    /* PLUS  */
    MODULUS = 279,                 /* MODULUS  */
    DRAW = 280,                    /* DRAW  */
    END = 281,                     /* END  */
    MOVE = 282,                    /* MOVE  */
    ANIMATE = 283,                 /* ANIMATE  */
    COS = 284,                     /* COS  */
    SIN = 285,                     /* SIN  */
    PRINT = 286,                   /* PRINT  */
    INT = 287,                     /* INT  */
    FLOAT = 288,                   /* FLOAT  */
    COLOR = 289                    /* COLOR  */
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
#define COORD 265
#define LINE 266
#define RECT 267
#define CIRCLE 268
#define PIXEL 269
#define SETCOLOR 270
#define WAIT 271
#define FRAME 272
#define LOOP 273
#define LE 274
#define GE 275
#define NE 276
#define EQ 277
#define PLUS 278
#define MODULUS 279
#define DRAW 280
#define END 281
#define MOVE 282
#define ANIMATE 283
#define COS 284
#define SIN 285
#define PRINT 286
#define INT 287
#define FLOAT 288
#define COLOR 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "vgraph.y"

    double dValue;
    int sIndex;      // index into symbolTable
    nodeType* nPtr;

#line 217 "y.tab.c"

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
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_IFX = 6,                        /* IFX  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_8_ = 8,                         /* '>'  */
  YYSYMBOL_9_ = 9,                         /* '<'  */
  YYSYMBOL_10_ = 10,                       /* '+'  */
  YYSYMBOL_11_ = 11,                       /* '-'  */
  YYSYMBOL_12_ = 12,                       /* '*'  */
  YYSYMBOL_13_ = 13,                       /* '/'  */
  YYSYMBOL_14_ = 14,                       /* '%'  */
  YYSYMBOL_UMINUS = 15,                    /* UMINUS  */
  YYSYMBOL_FUNC = 16,                      /* FUNC  */
  YYSYMBOL_COORD = 17,                     /* COORD  */
  YYSYMBOL_LINE = 18,                      /* LINE  */
  YYSYMBOL_RECT = 19,                      /* RECT  */
  YYSYMBOL_CIRCLE = 20,                    /* CIRCLE  */
  YYSYMBOL_PIXEL = 21,                     /* PIXEL  */
  YYSYMBOL_SETCOLOR = 22,                  /* SETCOLOR  */
  YYSYMBOL_WAIT = 23,                      /* WAIT  */
  YYSYMBOL_FRAME = 24,                     /* FRAME  */
  YYSYMBOL_LOOP = 25,                      /* LOOP  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_NE = 28,                        /* NE  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MODULUS = 31,                   /* MODULUS  */
  YYSYMBOL_DRAW = 32,                      /* DRAW  */
  YYSYMBOL_END = 33,                       /* END  */
  YYSYMBOL_MOVE = 34,                      /* MOVE  */
  YYSYMBOL_ANIMATE = 35,                   /* ANIMATE  */
  YYSYMBOL_COS = 36,                       /* COS  */
  YYSYMBOL_SIN = 37,                       /* SIN  */
  YYSYMBOL_PRINT = 38,                     /* PRINT  */
  YYSYMBOL_INT = 39,                       /* INT  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_COLOR = 41,                     /* COLOR  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_function = 52,                  /* function  */
  YYSYMBOL_frame = 53,                     /* frame  */
  YYSYMBOL_stmt = 54,                      /* stmt  */
  YYSYMBOL_declaration = 55,               /* declaration  */
  YYSYMBOL_assignment = 56,                /* assignment  */
  YYSYMBOL_conditional_body = 57,          /* conditional_body  */
  YYSYMBOL_stmt_list = 58,                 /* stmt_list  */
  YYSYMBOL_expr = 59,                      /* expr  */
  YYSYMBOL_conditional = 60                /* conditional  */
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
#define YYLAST   333

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
       2,     2,     2,    49,     2,     2,     2,    14,     2,     2,
      45,    46,    12,    10,    47,    11,     2,    13,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       9,    48,     8,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
       5,     6,     7,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    74,    75,    76,    80,    84,    85,    86,
      87,    88,    91,    92,    93,    94,    95,   100,   101,   105,
     109,   110,   114,   115,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   133,   134,   135,   136,   137,
     138
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
  "IF", "IFX", "ELSE", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UMINUS", "FUNC", "COORD", "LINE", "RECT", "CIRCLE", "PIXEL", "SETCOLOR",
  "WAIT", "FRAME", "LOOP", "LE", "GE", "NE", "EQ", "PLUS", "MODULUS",
  "DRAW", "END", "MOVE", "ANIMATE", "COS", "SIN", "PRINT", "INT", "FLOAT",
  "COLOR", "'{'", "'}'", "';'", "'('", "')'", "','", "'='", "'!'",
  "$accept", "program", "function", "frame", "stmt", "declaration",
  "assignment", "conditional_body", "stmt_list", "expr", "conditional", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -98,     4,    79,   -98,   -98,   -43,   -38,    29,   -34,   -32,
     -26,   -25,     9,   -14,   -11,   -98,   184,   -98,   -98,    -3,
       0,   289,    29,    29,   -98,    29,   -98,    29,    29,   171,
      41,     1,    29,    29,     7,    12,   227,   -98,   -98,    29,
      29,    29,    29,    29,   -98,   187,   222,    14,   237,   242,
     -98,    95,   -43,     8,    29,   247,   252,    51,    53,   -98,
      13,    13,   -98,   -98,   -98,     6,    11,    16,    19,   125,
      24,    25,   -98,   -98,    29,   199,   -98,   -98,   -98,   -98,
      29,   187,    29,   187,    29,    29,   171,    65,   171,   -98,
     -98,    31,    29,   187,   187,   187,   187,   141,   125,    41,
     264,   -98,   -98,    27,    33,   125,   -98,   -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     1,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     4,     3,     0,
       0,     0,     0,     0,    25,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,    10,     0,
       0,     0,     0,     0,     9,    19,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,     0,     6,    23,     0,     0,    32,    33,    17,    18,
       0,    36,     0,    35,     0,     0,     0,    12,    21,    14,
      15,     0,     0,    37,    38,    39,    40,     0,     0,     0,
       0,    20,    13,     0,     0,     0,    16,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -98,   -98,    -2,   -98,   -28,   -97,   -23,    -4,
       5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    17,    50,    19,    20,    87,    88,    21,
      47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,   102,    53,    26,     3,    22,    51,    23,   107,     4,
      24,    27,    36,    28,     4,    24,    29,     7,    45,    46,
      30,    36,     7,    48,    49,    41,    42,    43,    55,    56,
      31,    32,     4,    24,    33,    60,    61,    62,    63,    64,
       7,    37,    13,    14,    38,    52,    54,    13,    14,    73,
      75,    25,    74,    57,    80,    78,    25,    79,    58,    82,
      69,    81,    83,    97,    84,    13,    14,    85,    89,    90,
      46,   103,    98,   105,    25,    99,    93,   106,    94,    91,
      95,    96,     4,     5,     6,     0,    73,     0,   100,     0,
       7,     0,     0,     0,     0,    73,     0,     0,     4,     5,
       6,     8,     9,    10,    11,     0,     7,     0,     0,     0,
       0,    12,     0,     0,     0,    13,    14,     8,     9,     0,
      11,     0,     0,    15,    16,     0,     0,    12,     4,     5,
       6,    13,    14,     0,     0,     0,     7,     0,    72,    15,
      16,     0,     0,     0,     4,     5,     6,     8,     9,     0,
      11,     0,     7,     0,     0,     0,     0,    12,     0,     0,
       0,    13,    14,     8,     9,     0,    11,    86,     0,    15,
      16,     0,     0,    12,     4,     5,     6,    13,    14,     0,
       0,     0,     7,     0,   101,    15,    16,     4,    24,     0,
       0,     0,     0,     8,     9,     7,    11,    39,    40,    41,
      42,    43,     0,    12,     0,     0,     0,    13,    14,    39,
      40,    41,    42,    43,     0,    15,    16,     0,     0,     0,
      13,    14,     0,    34,     0,    35,     0,     0,     0,    25,
      65,    66,    39,    40,    41,    42,    43,    39,    40,    41,
      42,    43,     0,     0,     0,     0,    92,    39,    40,    41,
      42,    43,    39,    40,    41,    42,    43,    39,    40,    41,
      42,    43,    39,    40,    41,    42,    43,     0,     0,     0,
      67,    68,     0,    59,    39,    40,    41,    42,    43,     0,
       0,     0,     0,    70,     0,     0,     0,     0,    71,     0,
       0,     0,     0,    76,     0,     0,     0,     0,    77,    39,
      40,    41,    42,    43,     0,     0,     0,     0,     0,     0,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44
};

static const yytype_int8 yycheck[] =
{
       2,    98,    30,     7,     0,    48,    29,    45,   105,     3,
       4,    45,    16,    45,     3,     4,    42,    11,    22,    23,
      45,    25,    11,    27,    28,    12,    13,    14,    32,    33,
      21,    45,     3,     4,    45,    39,    40,    41,    42,    43,
      11,    44,    36,    37,    44,     4,    45,    36,    37,    51,
      54,    45,    44,    46,    48,     4,    45,     4,    46,    48,
      46,    65,    66,    86,    48,    36,    37,    48,    44,    44,
      74,    99,     7,    46,    45,    44,    80,    44,    82,    74,
      84,    85,     3,     4,     5,    -1,    88,    -1,    92,    -1,
      11,    -1,    -1,    -1,    -1,    97,    -1,    -1,     3,     4,
       5,    22,    23,    24,    25,    -1,    11,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    36,    37,    22,    23,    -1,
      25,    -1,    -1,    44,    45,    -1,    -1,    32,     3,     4,
       5,    36,    37,    -1,    -1,    -1,    11,    -1,    43,    44,
      45,    -1,    -1,    -1,     3,     4,     5,    22,    23,    -1,
      25,    -1,    11,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    36,    37,    22,    23,    -1,    25,    42,    -1,    44,
      45,    -1,    -1,    32,     3,     4,     5,    36,    37,    -1,
      -1,    -1,    11,    -1,    43,    44,    45,     3,     4,    -1,
      -1,    -1,    -1,    22,    23,    11,    25,    10,    11,    12,
      13,    14,    -1,    32,    -1,    -1,    -1,    36,    37,    10,
      11,    12,    13,    14,    -1,    44,    45,    -1,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,    45,
       8,     9,    10,    11,    12,    13,    14,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    47,    10,    11,    12,
      13,    14,    10,    11,    12,    13,    14,    10,    11,    12,
      13,    14,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      48,    49,    -1,    46,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    46,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     3,     4,     5,    11,    22,    23,
      24,    25,    32,    36,    37,    44,    45,    53,    54,    55,
      56,    59,    48,    45,     4,    45,    59,    45,    45,    42,
      45,    21,    45,    45,    39,    41,    59,    44,    44,    10,
      11,    12,    13,    14,    44,    59,    59,    60,    59,    59,
      54,    58,     4,    56,    45,    59,    59,    46,    46,    46,
      59,    59,    59,    59,    59,     8,     9,    48,    49,    46,
      46,    46,    43,    54,    44,    59,    46,    46,     4,     4,
      48,    59,    48,    59,    48,    48,    42,    57,    58,    44,
      44,    60,    47,    59,    59,    59,    59,    58,     7,    44,
      59,    43,    57,    56,    46,    46,    44,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     4,     1,     2,     2,
       2,     9,     5,     7,     5,     5,     8,     4,     4,     3,
       3,     1,     1,     2,     1,     1,     2,     3,     3,     3,
       3,     3,     4,     4,     3,     3,     3,     4,     4,     4,
       4
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
#line 70 "vgraph.y"
                    { exit(0); }
#line 1361 "y.tab.c"
    break;

  case 3: /* function: function stmt  */
#line 74 "vgraph.y"
                        { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1367 "y.tab.c"
    break;

  case 4: /* function: function frame  */
#line 75 "vgraph.y"
                         { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1373 "y.tab.c"
    break;

  case 6: /* frame: FRAME '{' stmt_list '}'  */
#line 80 "vgraph.y"
                                  { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1379 "y.tab.c"
    break;

  case 7: /* stmt: ';'  */
#line 84 "vgraph.y"
                { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1385 "y.tab.c"
    break;

  case 8: /* stmt: declaration ';'  */
#line 85 "vgraph.y"
                          { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1391 "y.tab.c"
    break;

  case 9: /* stmt: expr ';'  */
#line 86 "vgraph.y"
                    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1397 "y.tab.c"
    break;

  case 10: /* stmt: assignment ';'  */
#line 87 "vgraph.y"
                          { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1403 "y.tab.c"
    break;

  case 11: /* stmt: LOOP '(' assignment ';' conditional ';' assignment ')' conditional_body  */
#line 88 "vgraph.y"
                                                                                   { 
                (yyval.nPtr) = opr(LOOP, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); 
            }
#line 1411 "y.tab.c"
    break;

  case 12: /* stmt: IF '(' conditional ')' conditional_body  */
#line 91 "vgraph.y"
                                                               { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1417 "y.tab.c"
    break;

  case 13: /* stmt: IF '(' conditional ')' conditional_body ELSE conditional_body  */
#line 92 "vgraph.y"
                                                                         { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1423 "y.tab.c"
    break;

  case 14: /* stmt: SETCOLOR '(' expr ')' ';'  */
#line 93 "vgraph.y"
                                     { (yyval.nPtr) = opr(SETCOLOR, 1, (yyvsp[-2].nPtr)); }
#line 1429 "y.tab.c"
    break;

  case 15: /* stmt: WAIT '(' expr ')' ';'  */
#line 94 "vgraph.y"
                                 { (yyval.nPtr) = opr(WAIT, 1, (yyvsp[-2].nPtr)); }
#line 1435 "y.tab.c"
    break;

  case 16: /* stmt: DRAW PIXEL '(' expr ',' expr ')' ';'  */
#line 95 "vgraph.y"
                                                { (yyval.nPtr) = opr(PIXEL, 2, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr)); }
#line 1441 "y.tab.c"
    break;

  case 17: /* declaration: '(' INT ')' VARIABLE  */
#line 100 "vgraph.y"
                               { (yyval.nPtr) = opr('=', 2, id((yyvsp[0].sIndex)), 0);  }
#line 1447 "y.tab.c"
    break;

  case 18: /* declaration: '(' COLOR ')' VARIABLE  */
#line 101 "vgraph.y"
                               { (yyval.nPtr) = opr('=', 2, id((yyvsp[0].sIndex)), 0);  }
#line 1453 "y.tab.c"
    break;

  case 19: /* assignment: VARIABLE '=' expr  */
#line 105 "vgraph.y"
                             { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1459 "y.tab.c"
    break;

  case 20: /* conditional_body: '{' stmt_list '}'  */
#line 109 "vgraph.y"
                            { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1465 "y.tab.c"
    break;

  case 21: /* conditional_body: stmt_list  */
#line 110 "vgraph.y"
                      { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1471 "y.tab.c"
    break;

  case 22: /* stmt_list: stmt  */
#line 114 "vgraph.y"
                                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1477 "y.tab.c"
    break;

  case 23: /* stmt_list: stmt_list stmt  */
#line 115 "vgraph.y"
                                { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1483 "y.tab.c"
    break;

  case 24: /* expr: INTEGER  */
#line 119 "vgraph.y"
                                { (yyval.nPtr) = con((yyvsp[0].dValue)); }
#line 1489 "y.tab.c"
    break;

  case 25: /* expr: VARIABLE  */
#line 120 "vgraph.y"
                                { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 1495 "y.tab.c"
    break;

  case 26: /* expr: '-' expr  */
#line 121 "vgraph.y"
                                { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1501 "y.tab.c"
    break;

  case 27: /* expr: expr '+' expr  */
#line 122 "vgraph.y"
                                { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1507 "y.tab.c"
    break;

  case 28: /* expr: expr '-' expr  */
#line 123 "vgraph.y"
                                { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1513 "y.tab.c"
    break;

  case 29: /* expr: expr '*' expr  */
#line 124 "vgraph.y"
                                { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1519 "y.tab.c"
    break;

  case 30: /* expr: expr '/' expr  */
#line 125 "vgraph.y"
                                { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1525 "y.tab.c"
    break;

  case 31: /* expr: expr '%' expr  */
#line 126 "vgraph.y"
                                { (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1531 "y.tab.c"
    break;

  case 32: /* expr: COS '(' expr ')'  */
#line 127 "vgraph.y"
                                { (yyval.nPtr) = opr(COS, 1, (yyvsp[-1].nPtr)); }
#line 1537 "y.tab.c"
    break;

  case 33: /* expr: SIN '(' expr ')'  */
#line 128 "vgraph.y"
                                { (yyval.nPtr) = opr(SIN, 1, (yyvsp[-1].nPtr)); }
#line 1543 "y.tab.c"
    break;

  case 34: /* expr: '(' expr ')'  */
#line 129 "vgraph.y"
                                { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1549 "y.tab.c"
    break;

  case 35: /* conditional: expr '<' expr  */
#line 133 "vgraph.y"
                                 { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1555 "y.tab.c"
    break;

  case 36: /* conditional: expr '>' expr  */
#line 134 "vgraph.y"
                                 { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1561 "y.tab.c"
    break;

  case 37: /* conditional: expr '>' '=' expr  */
#line 135 "vgraph.y"
                                    { (yyval.nPtr) = opr(GE, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1567 "y.tab.c"
    break;

  case 38: /* conditional: expr '<' '=' expr  */
#line 136 "vgraph.y"
                                    { (yyval.nPtr) = opr(LE, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1573 "y.tab.c"
    break;

  case 39: /* conditional: expr '=' '=' expr  */
#line 137 "vgraph.y"
                                    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1579 "y.tab.c"
    break;

  case 40: /* conditional: expr '!' '=' expr  */
#line 138 "vgraph.y"
                                    { (yyval.nPtr) = opr(NE, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1585 "y.tab.c"
    break;


#line 1589 "y.tab.c"

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

#line 145 "vgraph.y"


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

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

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
    yyparse();
    return 0;
}
