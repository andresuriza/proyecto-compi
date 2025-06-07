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
    COLOR = 291,                   /* COLOR  */
    C_DECL = 292,                  /* C_DECL  */
    I_DECL = 293                   /* I_DECL  */
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
#define C_DECL 292
#define I_DECL 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "vgraph.y"

    double dValue;
    char* id;      // index into symbolTable
    nodeType* nPtr;

#line 229 "y.tab.c"

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
  YYSYMBOL_COLORTYPE = 5,                  /* COLORTYPE  */
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
  YYSYMBOL_C_DECL = 44,                    /* C_DECL  */
  YYSYMBOL_I_DECL = 45,                    /* I_DECL  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '='  */
  YYSYMBOL_53_ = 53,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_function = 56,                  /* function  */
  YYSYMBOL_frame = 57,                     /* frame  */
  YYSYMBOL_stmt = 58,                      /* stmt  */
  YYSYMBOL_var_type = 59,                  /* var_type  */
  YYSYMBOL_int_list = 60,                  /* int_list  */
  YYSYMBOL_color_list = 61,                /* color_list  */
  YYSYMBOL_assignment = 62,                /* assignment  */
  YYSYMBOL_conditional_body = 63,          /* conditional_body  */
  YYSYMBOL_stmt_list = 64,                 /* stmt_list  */
  YYSYMBOL_expr = 65,                      /* expr  */
  YYSYMBOL_conditional = 66                /* conditional  */
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
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
       2,     2,     2,    53,     2,     2,     2,    15,     2,     2,
      49,    50,    13,    11,    51,    12,     2,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
      10,    52,     9,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      42,    43,    44,    45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    80,    81,    82,    86,    91,    92,    93,
      94,    95,    98,    99,   100,   101,   102,   103,   110,   111,
     115,   116,   120,   121,   125,   129,   130,   134,   135,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   154,   155,   156,   157,   158,   159
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
  "COLORTYPE", "IF", "IFX", "ELSE", "'>'", "'<'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "UMINUS", "FUNC", "COORD", "LINE", "RECT", "CIRCLE",
  "PIXEL", "SETCOLOR", "WAIT", "FRAME", "LOOP", "LE", "GE", "NE", "EQ",
  "PLUS", "MODULUS", "DRAW", "TREE", "END", "MOVE", "ANIMATE", "COS",
  "SIN", "PRINT", "INT", "FLOAT", "COLOR", "C_DECL", "I_DECL", "'{'",
  "'}'", "';'", "'('", "')'", "','", "'='", "'!'", "$accept", "program",
  "function", "frame", "stmt", "var_type", "int_list", "color_list",
  "assignment", "conditional_body", "stmt_list", "expr", "conditional", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -94,     8,    94,   -94,   -94,   -45,   -94,   -21,    19,   -19,
     -17,    -2,   -11,    -5,     2,     5,   -94,   200,   -94,   -94,
      14,    15,   327,    19,    19,   -94,    19,   -94,    19,    19,
     196,    43,     6,    17,    19,    19,    20,    26,   258,   -94,
     -94,    19,    19,    19,    19,    19,   -94,   151,   241,    27,
     263,   268,   -94,    98,   -45,    16,    19,    19,   273,   287,
      63,    77,   -94,    28,    28,   -94,   -94,   -94,     1,     7,
      32,    40,   145,    46,    47,   -94,   -94,    19,    60,    74,
     -94,   -94,   -94,    45,   -94,    56,    19,   151,    19,   151,
      19,    19,   196,   100,   196,   -94,   -94,    64,    19,    19,
     109,   111,   151,   151,   151,   151,   149,   145,    43,   313,
     212,   -94,   -94,   -94,   -94,    73,    78,    19,   145,   -94,
     246,   -94,    19,   253,    19,   318,    80,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     1,    29,    31,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     4,     3,
       0,     0,     0,     0,     0,    31,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
      10,     0,     0,     0,     0,     0,     9,    24,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    33,    34,    35,    36,    37,     0,     0,
       0,     0,     0,     0,     0,     6,    28,     0,     0,     0,
      38,    39,    20,    18,    22,    19,     0,    42,     0,    41,
       0,     0,     0,    12,    26,    14,    15,     0,     0,     0,
       0,     0,    43,    44,    45,    46,     0,     0,     0,     0,
       0,    21,    23,    25,    13,     0,     0,     0,     0,    16,
       0,    11,     0,     0,     0,     0,     0,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -94,    -1,   -94,   -94,   -94,   -29,   -93,
     -27,    -8,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    18,    52,    20,    83,    85,    21,    93,
      94,    22,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    19,    55,    53,     4,    25,     6,    23,     3,    38,
       4,    25,     6,     8,   114,    47,    48,    32,    38,     8,
      50,    51,     4,    25,     6,   121,    58,    59,    24,    33,
      28,     8,    29,    63,    64,    65,    66,    67,    31,    14,
      15,    43,    44,    45,    30,    14,    15,    54,    78,    79,
      26,    34,    76,    86,    35,    56,    26,    14,    15,    88,
      87,    89,    39,    40,    77,   106,    57,    82,    26,    48,
      60,    41,    42,    43,    44,    45,    61,    72,   102,   115,
     103,    84,   104,   105,    90,    41,    42,    43,    44,    45,
     109,   110,    91,    76,    95,    96,   100,     4,     5,     6,
       7,     4,     5,     6,     7,    76,     8,   101,   107,   120,
       8,    98,   108,   111,   123,   112,   125,     9,    10,    11,
      12,     9,    10,   118,    12,    99,   119,    13,   127,    97,
       0,    13,    14,    15,     0,     0,    14,    15,     0,     0,
       0,     0,    16,    17,     0,    75,    16,    17,     4,     5,
       6,     7,     4,     5,     6,     7,     0,     8,     0,     0,
       0,     8,    41,    42,    43,    44,    45,     0,     9,    10,
       0,    12,     9,    10,     0,    12,     0,     0,    13,     0,
       0,     0,    13,    14,    15,     0,     0,    14,    15,     0,
       0,    92,     0,    16,    17,     0,   113,    16,    17,     4,
       5,     6,     7,     4,    25,     6,     0,     0,     8,     0,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     9,
      10,     0,    12,    41,    42,    43,    44,    45,     0,    13,
       0,     0,     0,     0,    14,    15,     0,     0,    14,    15,
       0,    36,     0,    37,    16,    17,     0,     0,     0,    26,
      68,    69,    41,    42,    43,    44,    45,    41,    42,    43,
      44,    45,     0,   117,    41,    42,    43,    44,    45,    41,
      42,    43,    44,    45,    41,    42,    43,    44,    45,    41,
      42,    43,    44,    45,    41,    42,    43,    44,    45,     0,
       0,     0,     0,    70,    71,     0,     0,   122,    41,    42,
      43,    44,    45,     0,   124,     0,     0,     0,    62,     0,
       0,     0,     0,    73,     0,     0,     0,     0,    74,     0,
       0,     0,     0,    80,    41,    42,    43,    44,    45,    41,
      42,    43,    44,    45,     0,     0,     0,    81,    41,    42,
      43,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,    46
};

static const yytype_int8 yycheck[] =
{
       8,     2,    31,    30,     3,     4,     5,    52,     0,    17,
       3,     4,     5,    12,   107,    23,    24,    22,    26,    12,
      28,    29,     3,     4,     5,   118,    34,    35,    49,    34,
      49,    12,    49,    41,    42,    43,    44,    45,    49,    38,
      39,    13,    14,    15,    46,    38,    39,     4,    56,    57,
      49,    49,    53,    52,    49,    49,    49,    38,    39,    52,
      68,    69,    48,    48,    48,    92,    49,     4,    49,    77,
      50,    11,    12,    13,    14,    15,    50,    50,    86,   108,
      88,     4,    90,    91,    52,    11,    12,    13,    14,    15,
      98,    99,    52,    94,    48,    48,    51,     3,     4,     5,
       6,     3,     4,     5,     6,   106,    12,    51,     8,   117,
      12,    51,    48,     4,   122,     4,   124,    23,    24,    25,
      26,    23,    24,    50,    26,    51,    48,    33,    48,    77,
      -1,    33,    38,    39,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    48,    49,    -1,    47,    48,    49,     3,     4,
       5,     6,     3,     4,     5,     6,    -1,    12,    -1,    -1,
      -1,    12,    11,    12,    13,    14,    15,    -1,    23,    24,
      -1,    26,    23,    24,    -1,    26,    -1,    -1,    33,    -1,
      -1,    -1,    33,    38,    39,    -1,    -1,    38,    39,    -1,
      -1,    46,    -1,    48,    49,    -1,    47,    48,    49,     3,
       4,     5,     6,     3,     4,     5,    -1,    -1,    12,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    -1,    26,    11,    12,    13,    14,    15,    -1,    33,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    38,    39,
      -1,    41,    -1,    43,    48,    49,    -1,    -1,    -1,    49,
       9,    10,    11,    12,    13,    14,    15,    11,    12,    13,
      14,    15,    -1,    51,    11,    12,    13,    14,    15,    11,
      12,    13,    14,    15,    11,    12,    13,    14,    15,    11,
      12,    13,    14,    15,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    51,    11,    12,
      13,    14,    15,    -1,    51,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    50,    11,    12,    13,    14,    15,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    50,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    55,    56,     0,     3,     4,     5,     6,    12,    23,
      24,    25,    26,    33,    38,    39,    48,    49,    57,    58,
      59,    62,    65,    52,    49,     4,    49,    65,    49,    49,
      46,    49,    22,    34,    49,    49,    41,    43,    65,    48,
      48,    11,    12,    13,    14,    15,    48,    65,    65,    66,
      65,    65,    58,    64,     4,    62,    49,    49,    65,    65,
      50,    50,    50,    65,    65,    65,    65,    65,     9,    10,
      52,    53,    50,    50,    50,    47,    58,    48,    65,    65,
      50,    50,     4,    60,     4,    61,    52,    65,    52,    65,
      52,    52,    46,    63,    64,    48,    48,    66,    51,    51,
      51,    51,    65,    65,    65,    65,    64,     8,    48,    65,
      65,     4,     4,    47,    63,    62,    50,    51,    50,    48,
      65,    63,    51,    65,    51,    65,    50,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     4,     1,     2,     2,
       2,     9,     5,     7,     5,     5,     8,    14,     4,     4,
       1,     3,     1,     3,     3,     3,     1,     1,     2,     1,
       1,     1,     2,     3,     3,     3,     3,     3,     4,     4,
       3,     3,     3,     4,     4,     4,     4
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
#line 76 "vgraph.y"
                 { exit(0); }
#line 1395 "y.tab.c"
    break;

  case 3: /* function: function stmt  */
#line 80 "vgraph.y"
                        { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1401 "y.tab.c"
    break;

  case 4: /* function: function frame  */
#line 81 "vgraph.y"
                         { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1407 "y.tab.c"
    break;

  case 6: /* frame: FRAME '{' stmt_list '}'  */
#line 86 "vgraph.y"
                                  { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1413 "y.tab.c"
    break;

  case 7: /* stmt: ';'  */
#line 91 "vgraph.y"
                { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1419 "y.tab.c"
    break;

  case 8: /* stmt: var_type ';'  */
#line 92 "vgraph.y"
                       { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1425 "y.tab.c"
    break;

  case 9: /* stmt: expr ';'  */
#line 93 "vgraph.y"
                    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1431 "y.tab.c"
    break;

  case 10: /* stmt: assignment ';'  */
#line 94 "vgraph.y"
                          { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1437 "y.tab.c"
    break;

  case 11: /* stmt: LOOP '(' assignment ';' conditional ';' assignment ')' conditional_body  */
#line 95 "vgraph.y"
                                                                                   { 
                (yyval.nPtr) = opr(LOOP, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); 
            }
#line 1445 "y.tab.c"
    break;

  case 12: /* stmt: IF '(' conditional ')' conditional_body  */
#line 98 "vgraph.y"
                                                               { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1451 "y.tab.c"
    break;

  case 13: /* stmt: IF '(' conditional ')' conditional_body ELSE conditional_body  */
#line 99 "vgraph.y"
                                                                         { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1457 "y.tab.c"
    break;

  case 14: /* stmt: SETCOLOR '(' expr ')' ';'  */
#line 100 "vgraph.y"
                                     { (yyval.nPtr) = opr(SETCOLOR, 1, (yyvsp[-2].nPtr)); }
#line 1463 "y.tab.c"
    break;

  case 15: /* stmt: WAIT '(' expr ')' ';'  */
#line 101 "vgraph.y"
                                 { (yyval.nPtr) = opr(WAIT, 1, (yyvsp[-2].nPtr)); }
#line 1469 "y.tab.c"
    break;

  case 16: /* stmt: DRAW PIXEL '(' expr ',' expr ')' ';'  */
#line 102 "vgraph.y"
                                                { (yyval.nPtr) = opr(PIXEL, 2, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr)); }
#line 1475 "y.tab.c"
    break;

  case 17: /* stmt: DRAW TREE '(' expr ',' expr ',' expr ',' expr ',' expr ')' ';'  */
#line 103 "vgraph.y"
                                                                          { 
                (yyval.nPtr) = opr(TREE, 2, (yyvsp[-10].nPtr), (yyvsp[-8].nPtr), (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr)); 
            }
#line 1483 "y.tab.c"
    break;

  case 18: /* var_type: '(' INT ')' int_list  */
#line 110 "vgraph.y"
                               { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1489 "y.tab.c"
    break;

  case 19: /* var_type: '(' COLOR ')' color_list  */
#line 111 "vgraph.y"
                                    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1495 "y.tab.c"
    break;

  case 20: /* int_list: VARIABLE  */
#line 115 "vgraph.y"
                 { (yyval.nPtr) = opr(I_DECL, 2, id((yyvsp[0].id)), con(0)); }
#line 1501 "y.tab.c"
    break;

  case 21: /* int_list: int_list ',' VARIABLE  */
#line 116 "vgraph.y"
                                { (yyval.nPtr) = opr(I_DECL, 2, id((yyvsp[0].id)), con(0)); }
#line 1507 "y.tab.c"
    break;

  case 22: /* color_list: VARIABLE  */
#line 120 "vgraph.y"
                 { (yyval.nPtr) = opr(C_DECL, 2, id((yyvsp[0].id)), conColor("rojo")); }
#line 1513 "y.tab.c"
    break;

  case 23: /* color_list: color_list ',' VARIABLE  */
#line 121 "vgraph.y"
                                  { (yyval.nPtr) = opr(C_DECL, 2, id((yyvsp[0].id)), conColor("rojo")); }
#line 1519 "y.tab.c"
    break;

  case 24: /* assignment: VARIABLE '=' expr  */
#line 125 "vgraph.y"
                             { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].id)), (yyvsp[0].nPtr)); }
#line 1525 "y.tab.c"
    break;

  case 25: /* conditional_body: '{' stmt_list '}'  */
#line 129 "vgraph.y"
                            { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1531 "y.tab.c"
    break;

  case 26: /* conditional_body: stmt_list  */
#line 130 "vgraph.y"
                      { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1537 "y.tab.c"
    break;

  case 27: /* stmt_list: stmt  */
#line 134 "vgraph.y"
                                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1543 "y.tab.c"
    break;

  case 28: /* stmt_list: stmt_list stmt  */
#line 135 "vgraph.y"
                                { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1549 "y.tab.c"
    break;

  case 29: /* expr: INTEGER  */
#line 139 "vgraph.y"
                                { (yyval.nPtr) = con((yyvsp[0].dValue)); }
#line 1555 "y.tab.c"
    break;

  case 30: /* expr: COLORTYPE  */
#line 140 "vgraph.y"
                                 { (yyval.nPtr) = conColor((yyvsp[0].id)); }
#line 1561 "y.tab.c"
    break;

  case 31: /* expr: VARIABLE  */
#line 141 "vgraph.y"
                                { (yyval.nPtr) = id((yyvsp[0].id)); }
#line 1567 "y.tab.c"
    break;

  case 32: /* expr: '-' expr  */
#line 142 "vgraph.y"
                                { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1573 "y.tab.c"
    break;

  case 33: /* expr: expr '+' expr  */
#line 143 "vgraph.y"
                                { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1579 "y.tab.c"
    break;

  case 34: /* expr: expr '-' expr  */
#line 144 "vgraph.y"
                                { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1585 "y.tab.c"
    break;

  case 35: /* expr: expr '*' expr  */
#line 145 "vgraph.y"
                                { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1591 "y.tab.c"
    break;

  case 36: /* expr: expr '/' expr  */
#line 146 "vgraph.y"
                                { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1597 "y.tab.c"
    break;

  case 37: /* expr: expr '%' expr  */
#line 147 "vgraph.y"
                                { (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1603 "y.tab.c"
    break;

  case 38: /* expr: COS '(' expr ')'  */
#line 148 "vgraph.y"
                                { (yyval.nPtr) = opr(COS, 1, (yyvsp[-1].nPtr)); }
#line 1609 "y.tab.c"
    break;

  case 39: /* expr: SIN '(' expr ')'  */
#line 149 "vgraph.y"
                                { (yyval.nPtr) = opr(SIN, 1, (yyvsp[-1].nPtr)); }
#line 1615 "y.tab.c"
    break;

  case 40: /* expr: '(' expr ')'  */
#line 150 "vgraph.y"
                                { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1621 "y.tab.c"
    break;

  case 41: /* conditional: expr '<' expr  */
#line 154 "vgraph.y"
                                 { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1627 "y.tab.c"
    break;

  case 42: /* conditional: expr '>' expr  */
#line 155 "vgraph.y"
                                 { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1633 "y.tab.c"
    break;

  case 43: /* conditional: expr '>' '=' expr  */
#line 156 "vgraph.y"
                                    { (yyval.nPtr) = opr(GE, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1639 "y.tab.c"
    break;

  case 44: /* conditional: expr '<' '=' expr  */
#line 157 "vgraph.y"
                                    { (yyval.nPtr) = opr(LE, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1645 "y.tab.c"
    break;

  case 45: /* conditional: expr '=' '=' expr  */
#line 158 "vgraph.y"
                                    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1651 "y.tab.c"
    break;

  case 46: /* conditional: expr '!' '=' expr  */
#line 159 "vgraph.y"
                                    { (yyval.nPtr) = opr(NE, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1657 "y.tab.c"
    break;


#line 1661 "y.tab.c"

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

#line 166 "vgraph.y"


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
