/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "miint.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "stackElement.h"
#include "stack.h"
#include "GestorDeMemoria.h"
#include <typeinfo>
#include <cstdarg>


// stuff from flex that bison needs to know about:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
char global[7] = "global";
GestorDeMemoria mem;
Stack stack;
int etiqueta = 0;
int etiqFunc = 0;
void yyerror(const char *s);
FILE *qFile = fopen ( "fichero.q.c", "w+");
void gc(const char* code, ...);

#line 92 "miint.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "miint.tab.h".  */
#ifndef YY_YY_MIINT_TAB_H_INCLUDED
# define YY_YY_MIINT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MIENTRAS = 258,
    SI = 259,
    MAYORQUE = 260,
    MENORQUE = 261,
    IGUAL = 262,
    DIFERENTE = 263,
    IMPRIMIR = 264,
    DECLAR = 265,
    ASIGNACION = 266,
    PYCOMA = 267,
    FUNCION = 268,
    ABREPAR = 269,
    CIERRAPAR = 270,
    ABRECOR = 271,
    CIERRACOR = 272,
    COMILLAS = 273,
    SUMA = 274,
    RESTA = 275,
    MULTIPLICACION = 276,
    DIVISION = 277,
    CONCATENACION = 278,
    IDENTIFICADOR = 279,
    RISTRA = 280,
    CAD = 281,
    ENT = 282,
    NUMERO = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "miint.y" /* yacc.c:355  */

	int ent;
	char *cad;

#line 166 "miint.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MIINT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 183 "miint.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    56,    71,    72,    73,    74,    78,    83,
      84,    85,    86,    87,    89,    96,   100,    95,   114,   120,
     113,   133,   150,   167,   184,   203,   244,   260,   264,   265,
     266,   267,   271,   289,   307,   308,   309,   310,   314,   332,
     350,   368,   387,   405,   423,   427,   431,   435,   443,   442,
     479,   497,   504,   539,   577,   608,   612,   635,   654
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MIENTRAS", "SI", "MAYORQUE", "MENORQUE",
  "IGUAL", "DIFERENTE", "IMPRIMIR", "DECLAR", "ASIGNACION", "PYCOMA",
  "FUNCION", "ABREPAR", "CIERRAPAR", "ABRECOR", "CIERRACOR", "COMILLAS",
  "SUMA", "RESTA", "MULTIPLICACION", "DIVISION", "CONCATENACION",
  "IDENTIFICADOR", "RISTRA", "CAD", "ENT", "NUMERO", "$accept", "vod",
  "$@1", "body", "sentencias", "si", "$@2", "$@3", "mientras", "$@4",
  "$@5", "cond", "imprime", "callfunc", "operacionent", "suma", "identi",
  "resta", "multiplicacion", "division", "declare", "declarefunc", "$@6",
  "declareent", "operacioncad", "declarecad", "inicializar",
  "inicializarent", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

#define YYPACT_NINF -31

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-31)))

#define YYTABLE_NINF -4

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -31,    21,    56,   -31,    10,    17,    43,   -31,    74,    43,
     -31,   -31,   -31,    82,    35,    46,   -31,   -31,    85,    86,
      77,   -31,   -31,    87,   -31,    90,    88,    92,    76,    83,
      84,     0,    94,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
       8,     8,    95,   100,   -31,     5,   -31,    72,   -31,   -31,
      57,   -31,   -31,   -31,   -31,    96,     8,    98,    30,    99,
     -31,    31,    72,   101,    44,    73,    89,    91,    93,     8,
       8,     8,     8,     8,   -31,   -31,    58,   -31,     8,     8,
       8,     8,   -31,    97,    60,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,    71,    66,    66,    66,    66,    -1,   102,    66,
      66,    66,    66,   106,   103,     8,   -31,   -31,   -31,   -31,
     -31,    66,     1,     3,   -31,   -31
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    14,     1,     0,    14,     6,     5,     0,     7,
       4,    18,    15,     0,     0,     0,    12,    13,     0,     0,
       0,    47,    46,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    10,     8,    44,    45,     9,    48,
       0,     0,     0,     0,    50,     0,    35,    57,    58,    28,
      56,    29,    30,    31,    26,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    14,     0,    19,     0,     0,
       0,     0,    16,    52,     0,    54,    27,    37,    33,    39,
      41,    43,     0,    32,    38,    40,    42,     0,     0,    21,
      22,    23,    24,     0,     0,     0,    36,    49,    14,    14,
      51,    53,     0,     0,    20,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,   -31,    -5,   -31,   -31,   -31,   -31,   -31,
     -31,   104,   -31,   -31,    70,   -31,   -30,   -31,   -31,   -31,
     -31,   118,   -31,   105,   -31,   107,   -31,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    16,    27,   103,    17,    26,
      98,    57,    18,    19,    48,    49,    58,    51,    52,    53,
      20,     7,    55,    21,    85,    22,    23,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       9,    50,    11,    12,    11,    12,    11,    12,    13,    14,
      13,    14,    13,    14,    45,    64,   107,    -3,   114,    45,
     115,     3,    56,    15,    46,    15,    76,    15,    47,    46,
       4,    84,    46,    62,     8,    78,    79,    80,    81,    92,
      93,    94,    95,    96,    69,    56,    11,    12,    99,   100,
     101,   102,    13,    14,    74,    46,    83,    31,    69,    87,
      32,    29,    30,    70,    71,    72,    73,    15,    74,     4,
      97,    69,    69,    87,    69,   111,    70,    71,    72,    73,
      69,    74,    74,   105,    74,    69,   106,    14,    25,    35,
      74,    65,    66,    67,    68,    74,    28,    33,    34,    38,
      42,    88,    40,   112,   113,    39,    41,    43,    44,    54,
      60,    61,    75,    77,    82,    63,    86,    89,   108,    90,
     104,    91,   109,    10,     0,    36,     0,    37,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59
};

static const yytype_int8 yycheck[] =
{
       5,    31,     3,     4,     3,     4,     3,     4,     9,    10,
       9,    10,     9,    10,    14,    45,    17,     0,    17,    14,
      17,     0,    14,    24,    24,    24,    56,    24,    28,    24,
      13,    61,    24,    28,    24,     5,     6,     7,     8,    69,
      70,    71,    72,    73,    14,    14,     3,     4,    78,    79,
      80,    81,     9,    10,    24,    24,    25,    11,    14,    15,
      14,    26,    27,    19,    20,    21,    22,    24,    24,    13,
      75,    14,    14,    15,    14,   105,    19,    20,    21,    22,
      14,    24,    24,    23,    24,    14,    15,    10,    14,    12,
      24,    19,    20,    21,    22,    24,    14,    12,    12,    12,
      24,    28,    14,   108,   109,    15,    14,    24,    24,    15,
      15,    11,    16,    15,    15,    45,    15,    28,    16,    28,
      23,    28,    16,     5,    -1,    20,    -1,    20,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,     0,    13,    32,    33,    50,    24,    33,
      50,     3,     4,     9,    10,    24,    34,    37,    41,    42,
      49,    52,    54,    55,    56,    14,    38,    35,    14,    26,
      27,    11,    14,    12,    12,    12,    52,    54,    12,    15,
      14,    14,    24,    24,    24,    14,    24,    28,    43,    44,
      45,    46,    47,    48,    15,    51,    14,    40,    45,    40,
      15,    11,    28,    43,    45,    19,    20,    21,    22,    14,
      19,    20,    21,    22,    24,    16,    45,    15,     5,     6,
       7,     8,    15,    25,    45,    53,    15,    15,    28,    28,
      28,    28,    45,    45,    45,    45,    45,    33,    39,    45,
      45,    45,    45,    36,    23,    23,    15,    17,    16,    16,
      25,    45,    33,    33,    17,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    31,    30,    32,    32,    32,    32,    33,    33,
      33,    33,    33,    33,    33,    35,    36,    34,    38,    39,
      37,    40,    40,    40,    40,    41,    42,    43,    43,    43,
      43,    43,    44,    44,    45,    45,    45,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    49,    49,    51,    50,
      52,    53,    54,    54,    54,    55,    56,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     2,     3,     3,
       3,     3,     2,     2,     0,     0,     0,     9,     0,     0,
       9,     3,     3,     3,     3,     4,     3,     3,     1,     1,
       1,     1,     3,     3,     2,     1,     4,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     0,     8,
       3,     3,     5,     7,     5,     1,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 56 "miint.y" /* yacc.c:1646  */
    {gc("#include \"Q.h\"\n");
	gc("#define INI 0\n");
	gc("#define FIN -2\n");
	gc("BEGIN\n");
	gc("L %d:\n", etiqueta);
	etiqueta++;
	}
#line 1347 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 64 "miint.y" /* yacc.c:1646  */
    {gc("\tR0=0;\n");
	{gc("\tGT(-2);\n");
	gc("END\n");}
	}
#line 1356 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "miint.y" /* yacc.c:1646  */
    {
	// Para saber el numero de bytes que hay que reservar en memoria
	(yyval.ent) = (yyval.ent) + (yyvsp[-1].ent);
	}
#line 1365 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 89 "miint.y" /* yacc.c:1646  */
    {
	(yyval.ent) = 0;
	}
#line 1373 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "miint.y" /* yacc.c:1646  */
    {
	
	}
#line 1381 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 100 "miint.y" /* yacc.c:1646  */
    {
	(yyvsp[-2].ent)=etiqueta;
	gc("\tIF(!R%d) GT(%d);\n", (yyvsp[-1].ent), (yyvsp[-2].ent));
	etiqueta++;
	mem.liberaRegistro((yyvsp[-1].ent));
	}
#line 1392 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 107 "miint.y" /* yacc.c:1646  */
    {
	gc("L %d:\n",(yyvsp[-6].ent));
	}
#line 1400 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 114 "miint.y" /* yacc.c:1646  */
    {
	(yyvsp[0].ent) = etiqueta;
	gc("L %d:\n", (yyvsp[0].ent));
	etiqueta++;
	}
#line 1410 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 120 "miint.y" /* yacc.c:1646  */
    {
	(yyvsp[-2].ent)=etiqueta;
	gc("\tIF(!R%d) GT(%d);\n", (yyvsp[-1].ent), (yyvsp[-2].ent));
	etiqueta++;
	mem.liberaRegistro((yyvsp[-1].ent));
	}
#line 1421 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 127 "miint.y" /* yacc.c:1646  */
    {
	gc("\tGT(%d);\nL %d:\n", (yyvsp[-8].ent), (yyvsp[-6].ent));
	}
#line 1429 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 134 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getVariable((yyvsp[-2].cad)).getTipo(), "ent")==0 && strcmp(stack.getVariable((yyvsp[0].cad)).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable((yyvsp[0].cad)).getDireccion());
		gc("\tR%d=R%d>R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
	}
#line 1450 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 151 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getVariable((yyvsp[-2].cad)).getTipo(), "ent")==0 && strcmp(stack.getVariable((yyvsp[0].cad)).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable((yyvsp[0].cad)).getDireccion());
		gc("\tR%d=R%d<R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
	}
#line 1471 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 168 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getVariable((yyvsp[-2].cad)).getTipo(), "ent")==0 && strcmp(stack.getVariable((yyvsp[0].cad)).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable((yyvsp[0].cad)).getDireccion());
		gc("\tR%d=R%d==R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
	}
#line 1492 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 185 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getVariable((yyvsp[-2].cad)).getTipo(), "ent")==0 && strcmp(stack.getVariable((yyvsp[0].cad)).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable((yyvsp[0].cad)).getDireccion());
		gc("\tR%d=R%d!=R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
	}
#line 1513 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 204 "miint.y" /* yacc.c:1646  */
    {
	if(!stack.existsVariable((yyvsp[-1].cad))){
		printf("la variable %s no existe\n", (yyvsp[-1].cad));
	} else {
		if (mem.getStat()==mem.getCode()+1){
				gc("CODE(%d)\n", mem.getCode());
				mem.incrementCode();
		}		
		if(strcmp(stack.getVariable((yyvsp[-1].cad)).getTipo(), "cad")==0){
			//imprimir cadena
			int ret, ristra;
			ret = mem.devuelveRegistroLibre();
			ristra = mem.devuelveRegistroLibre();
			int size = stack.getVariable((yyvsp[-1].cad)).getSize();
			for(int i = 0; i < size; i++){
				gc("\tR%d=%d;\n", ret, etiqueta);
				gc("\tR%d=U(0x%x+%d);\n", ristra, stack.getVariable((yyvsp[-1].cad)).getDireccion(), i);
				gc("\tGT(-12);\nL %d:\n", etiqueta);
				etiqueta++;	
			}
			mem.liberaRegistro(ret);
			mem.liberaRegistro(ristra);
		}
		else{
			//imprimir numero
			int ret, numero;
			ret = mem.devuelveRegistroLibre();
			numero = mem.devuelveRegistroLibre();
			gc("\tR%d=%d;\n", ret, etiqueta);
			gc("\tR%d=I(0x%x);\n", numero, stack.getVariable((yyvsp[-1].cad)).getDireccion());
			gc("\tGT(-13);\nL %d:\n", etiqueta);
			etiqueta++;
			mem.liberaRegistro(ret);
			mem.liberaRegistro(numero);
		}	
	}
	}
#line 1555 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 245 "miint.y" /* yacc.c:1646  */
    {
	if (mem.getStat()==mem.getCode()+1){
				gc("CODE(%d)\n", mem.getCode());
				mem.incrementCode();
	}
	gc("\tR7=R7-8;\n");
	gc("\tP(R7+4)=R6;\n");	
	gc("\tP(R7)=%d;\n", etiqueta);
	gc("\tGT(%d);\n", stack.getFuncion((yyvsp[-2].cad)).getEtiqueta());
	gc("L %d:\n", etiqueta);
	etiqueta++;
	}
#line 1572 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 261 "miint.y" /* yacc.c:1646  */
    {
	(yyval.ent) = (yyvsp[-1].ent);
	}
#line 1580 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 272 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getVariable((yyvsp[-2].cad)).getTipo(), "ent")==0 && strcmp(stack.getVariable((yyvsp[0].cad)).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable((yyvsp[0].cad)).getDireccion());
		gc("\tR%d=R%d+R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
	;
	}
#line 1602 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 290 "miint.y" /* yacc.c:1646  */
    {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", res, (yyvsp[-2].ent));
		gc("\tR%d=%d;\n", add, (yyvsp[0].ent));
		gc("\tR%d=R%d+R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
#line 1621 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 307 "miint.y" /* yacc.c:1646  */
    {(yyval.cad)=(yyvsp[0].cad);}
#line 1627 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 308 "miint.y" /* yacc.c:1646  */
    {(yyval.cad)=(yyvsp[0].cad);}
#line 1633 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 309 "miint.y" /* yacc.c:1646  */
    {(yyval.cad) = (yyvsp[-1].cad);}
#line 1639 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 310 "miint.y" /* yacc.c:1646  */
    {(yyval.cad) = (yyvsp[-1].cad);}
#line 1645 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 315 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getVariable((yyvsp[-2].cad)).getTipo(), "ent")==0 && strcmp(stack.getVariable((yyvsp[0].cad)).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable((yyvsp[0].cad)).getDireccion());
		gc("\tR%d=R%d-R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
	;
	}
#line 1667 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 333 "miint.y" /* yacc.c:1646  */
    {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", res, (yyvsp[-2].ent));
		gc("\tR%d=%d;\n", add, (yyvsp[0].ent));
		gc("\tR%d=R%d-R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);	
	}
#line 1686 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 351 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getVariable((yyvsp[-2].cad)).getTipo(), "ent")==0 && strcmp(stack.getVariable((yyvsp[0].cad)).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable((yyvsp[0].cad)).getDireccion());
		gc("\tR%d=R%d*R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
	;
	}
#line 1708 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 369 "miint.y" /* yacc.c:1646  */
    {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", res, (yyvsp[-2].ent));
		gc("\tR%d=%d;\n", add, (yyvsp[0].ent));
		gc("\tR%d=R%d*R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);

	}
#line 1728 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 388 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getVariable((yyvsp[-2].cad)).getTipo(), "ent")==0 && strcmp(stack.getVariable((yyvsp[0].cad)).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable((yyvsp[0].cad)).getDireccion());
		gc("\tR%d=R%d/R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
	;
	}
#line 1750 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 406 "miint.y" /* yacc.c:1646  */
    {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", res, (yyvsp[-2].ent));
		gc("\tR%d=%d;\n", add, (yyvsp[0].ent));
		gc("\tR%d=R%d/R%d;\n", res, res, add);
		(yyval.ent) = res;
		mem.liberaRegistro(add);
	}
#line 1769 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 424 "miint.y" /* yacc.c:1646  */
    {
	(yyval.ent) += (yyvsp[0].ent);
	}
#line 1777 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 428 "miint.y" /* yacc.c:1646  */
    {
	(yyval.ent) += (yyvsp[0].ent);
	}
#line 1785 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 432 "miint.y" /* yacc.c:1646  */
    {
	(yyval.ent) = (yyvsp[0].ent);
	}
#line 1793 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 436 "miint.y" /* yacc.c:1646  */
    {
	(yyval.ent) = (yyvsp[0].ent);
	}
#line 1801 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 443 "miint.y" /* yacc.c:1646  */
    {
	if(stack.existsFuncion((yyvsp[-2].cad))){
		printf("ya existe %s\n", (yyvsp[-2].cad));
	} else {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		mem.setAmbito((yyvsp[-2].cad));
		int etiq = etiqueta;
		etiqueta++;
		stack.addFuncion((yyvsp[-2].cad), etiq);
		etiqFunc = etiqueta;
		gc("\tGT(%d);\n", etiqueta);
		gc("L %d:\n", etiq);
		gc("\tR6=R7;\n");	
		etiqueta++;
	}
	}
#line 1825 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 463 "miint.y" /* yacc.c:1646  */
    {
	if (mem.getStat()==mem.getCode()+1){
				gc("CODE(%d)\n", mem.getCode());
				mem.incrementCode();
	}
	gc("\tR7=R6;\n");
	gc("\tR6=P(R7+4);\n");
	gc("\tR5=P(R7);\n");
	gc("\tGT(R5);\n");
	gc("L %d: \n", etiqFunc);
	stack.cleanDinamicStack((yyvsp[-6].cad));
	mem.setAmbito(global);
	}
#line 1843 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 480 "miint.y" /* yacc.c:1646  */
    {
	(yyval.ent) = 4;
	if(stack.existsVariable((yyvsp[0].cad))){
		printf("ya existe %s\n", (yyvsp[0].cad));
	} else {
		int dir = mem.cogerDireccionDeMemoriaEnt();
		if (mem.getStat()==mem.getCode()){
			gc("STAT(%d)\n", mem.getStat());
			mem.incrementStat();
		}
		gc("\tMEM(0x%x, %d);\n", dir, 4);
		stack.addVariable((yyvsp[0].cad), "ent", mem.getAmbito(), dir, 4);		
	}
	}
#line 1862 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 498 "miint.y" /* yacc.c:1646  */
    {
		(yyval.cad) = strcat((yyvsp[-2].cad), (yyvsp[0].cad));
	}
#line 1870 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 505 "miint.y" /* yacc.c:1646  */
    {
	if(stack.existsVariable((yyvsp[-2].cad))){
		printf("ya existe %s\n", (yyvsp[-2].cad));
	} else {
		int size = strlen((yyvsp[0].cad));
		char h[size-2];
		for(int i = 0; i < size-2; i++){
			h[i] = (yyvsp[0].cad)[i+1];
		}
		h[size-2] = '\0';
		(yyval.ent) = strlen(h);
		int dir = mem.cogerDireccionDeMemoriaCad(strlen(h));
		if (mem.getStat()==mem.getCode()){
			gc("STAT(%d)\n", mem.getStat());
			mem.incrementStat();
		}
		gc("\tMEM(0x%x, %d);\n", dir, strlen(h));
		stack.addVariable((yyvsp[-2].cad), "cad", mem.getAmbito(), dir, strlen(h));
				if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int id=mem.devuelveRegistroLibre();
		gc("\tR%d=0x%x;\n", id, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		int val = mem.devuelveRegistroLibre();
		for(int i = 0; i < strlen(h); i++){
			gc("\tR%d=%d;\n", val, h[i]);
			gc("\tU(R%d+%d)=R%d;\n", id,i, val);
		}
		mem.liberaRegistro(id);
		mem.liberaRegistro(val);
	}
	}
#line 1908 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 540 "miint.y" /* yacc.c:1646  */
    {
		if(strcmp(stack.getVariable((yyvsp[-2].cad)).getTipo(), "cad")==0 && strcmp(stack.getVariable((yyvsp[0].cad)).getTipo(), "cad")==0){
		
			int size = stack.getVariable((yyvsp[-2].cad)).getSize() + stack.getVariable((yyvsp[0].cad)).getSize();
			(yyval.ent) = size;
			int dir = mem.cogerDireccionDeMemoriaCad(size);
			if (mem.getStat()==mem.getCode()){
				gc("STAT(%d)\n", mem.getStat());
				mem.incrementStat();
			}
			gc("\tMEM(0x%x, %d);\n", dir, size);
			stack.addVariable((yyvsp[-4].cad), "cad", mem.getAmbito(), dir, size);
					if (mem.getStat()==mem.getCode()+1){
				gc("CODE(%d)\n", mem.getCode());
				mem.incrementCode();
			}
			int reg0 = mem.devuelveRegistroLibre();
			int reg1 = mem.devuelveRegistroLibre();
			int reg2 = mem.devuelveRegistroLibre();
			gc("\tR%d=0x%x;\n", reg0, stack.getVariable((yyvsp[-4].cad)).getDireccion());
			gc("\tR%d=0x%x;\n", reg1, stack.getVariable((yyvsp[-2].cad)).getDireccion());
			int i;
			for(i = 0; i < stack.getVariable((yyvsp[-2].cad)).getSize(); i++){
				gc("\tR%d=U(R%d+%d);\n", reg2, reg1, i );
				gc("\tU(R%d+%d)=R%d;\n", reg0, i, reg2 );
			}
			gc("\tR%d=0x%x;\n", reg1, stack.getVariable((yyvsp[0].cad)).getDireccion());
			for(i = 0; i < stack.getVariable((yyvsp[0].cad)).getSize(); i++){
				gc("\tR%d=U(R%d+%d);\n", reg2, reg1, i );
				gc("\tU(R%d+%d)=R%d;\n", reg0, i+stack.getVariable((yyvsp[-2].cad)).getSize(), reg2 );
			}
			mem.liberaRegistro(reg0);
			mem.liberaRegistro(reg1);
			mem.liberaRegistro(reg2);
		}
		
	}
#line 1950 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 578 "miint.y" /* yacc.c:1646  */
    {
		int size = strlen((yyvsp[0].cad));
		(yyval.ent) = size;
		int dir = mem.cogerDireccionDeMemoriaCad(size);
		if (mem.getStat()==mem.getCode()){
			gc("STAT(%d)\n", mem.getStat());
			mem.incrementStat();
		}
		gc("\tSTR(0x%x, \"%s\");\n", dir, (yyvsp[0].cad));
		stack.addVariable((yyvsp[-2].cad), "cad", mem.getAmbito(), dir, size);
				if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		

		int id=mem.devuelveRegistroLibre();
		gc("\tR%d=0x%x;\n", id, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		int val = mem.devuelveRegistroLibre();
		char* palabra = (yyvsp[0].cad);
		for(int i = 0; i < strlen(palabra); i++){
			gc("\tR%d=%d;\n", val, palabra[i]);
			gc("\tU(R%d+%d)=R%d;\n", id,i, val);
		}
		mem.liberaRegistro(id);
		mem.liberaRegistro(val);
	}
#line 1982 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 613 "miint.y" /* yacc.c:1646  */
    {
	if(!stack.existsVariable((yyvsp[-2].cad))){
		printf("la variable %s no existe\n", (yyvsp[-2].cad));
	} else {
		if(!stack.existsVariable((yyvsp[0].cad))){
			printf("la variable %s no existe\n", (yyvsp[0].cad));
		} else {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=0x%x;\n", res, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable((yyvsp[0].cad)).getDireccion());
		gc("\tI(R%d)=R%d;\n", res, add);
		mem.liberaRegistro(add);
		mem.liberaRegistro(res);	
	}
	}
	}
#line 2009 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 635 "miint.y" /* yacc.c:1646  */
    {
	
	if(!stack.existsVariable((yyvsp[-2].cad))){
		printf("la variable %s no existe\n", (yyvsp[-2].cad));
	} else {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int id=mem.devuelveRegistroLibre();
		gc("\tR%d=0x%x;\n", id, stack.getVariable((yyvsp[-2].cad)).getDireccion());
		int val = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", val, (yyvsp[0].ent));
		gc("\tI(R%d)=R%d;\n", id, val);
		mem.liberaRegistro(id);
		mem.liberaRegistro(val);
	}	
	
	}
#line 2033 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 655 "miint.y" /* yacc.c:1646  */
    {
	if(!stack.existsVariable((yyvsp[-2].cad))){
		printf("la variable %s no existe\n", (yyvsp[-2].cad));
	} else {
		int reg = mem.devuelveRegistroLibre();
		gc("\tR%d=0x%x;\n", reg, stack.getVariable((yyvsp[-2].cad)).getDireccion() );
		gc("\tI(R%d)=R%d;\n", reg, (yyvsp[0].ent));
		mem.liberaRegistro(reg);
		mem.liberaRegistro((yyvsp[0].ent));
	}
	}
#line 2049 "miint.tab.c" /* yacc.c:1646  */
    break;


#line 2053 "miint.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 667 "miint.y" /* yacc.c:1906  */


int main(int argc, char** argv) {
	// open a file handle to a particular file:
	if(argc>1) yyin=fopen(argv[1], "r");
	//yydebug = 1;
	yyparse();
	stack.printStack();
	
	
	
}

void gc(const char* code, ...){
	//printf("dentro\n");
	va_list args;
	va_start (args, code);
	vfprintf(qFile, code, args);
	va_end (args);
}

void yyerror(const char *s) {
	printf("error sintactico: %s\n", s);
}
