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
GestorDeMemoria mem;
Stack stack;
void yyerror(const char *s);
FILE *qFile = fopen ( "fichero.q.c", "w+");
void gc(const char* code, ...);

#line 89 "miint.tab.c" /* yacc.c:339  */

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
    SI = 258,
    MIENTRAS = 259,
    MAYORQUE = 260,
    MENORQUE = 261,
    IGUAL = 262,
    DIFERENTE = 263,
    ESCANEAR = 264,
    IMPRIMIR = 265,
    DECLAR = 266,
    ASIGNACION = 267,
    PYCOMA = 268,
    FUNCION = 269,
    ABREPAR = 270,
    CIERRAPAR = 271,
    ABRECOR = 272,
    CIERRACOR = 273,
    SUMA = 274,
    RESTA = 275,
    MULTIPLICACION = 276,
    DIVISION = 277,
    CONCATENACION = 278,
    IDENTIFICADOR = 279,
    CAD = 280,
    ENT = 281,
    NUMERO = 282,
    RISTRA = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "miint.y" /* yacc.c:355  */

	int ent;
	char *cad;

#line 163 "miint.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MIINT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 180 "miint.tab.c" /* yacc.c:358  */

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
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

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
       0,    53,    53,    53,    64,    65,    66,    67,    72,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    85,
      89,    93,   103,   113,   123,   137,   141,   154,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   170,   177,   187,
     194,   198,   199,   200,   201,   205,   212,   216,   223,   227,
     234,   239,   240,   241,   242,   246,   258,   274,   289,   290,
     291,   292,   293,   297,   310,   326,   339,   349
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SI", "MIENTRAS", "MAYORQUE", "MENORQUE",
  "IGUAL", "DIFERENTE", "ESCANEAR", "IMPRIMIR", "DECLAR", "ASIGNACION",
  "PYCOMA", "FUNCION", "ABREPAR", "CIERRAPAR", "ABRECOR", "CIERRACOR",
  "SUMA", "RESTA", "MULTIPLICACION", "DIVISION", "CONCATENACION",
  "IDENTIFICADOR", "CAD", "ENT", "NUMERO", "RISTRA", "$accept", "vod",
  "$@1", "body", "sentencias", "$@2", "si", "mientras", "cond", "escaneo",
  "imprime", "callfunc", "operacionent", "operacioncad", "suma", "identi",
  "resta", "multiplicacion", "division", "declare", "declarefunc",
  "declareent", "declarecad", "inicializar", "inicializarent",
  "inicializarcad", YY_NULLPTR
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

#define YYPACT_NINF -36

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-36)))

#define YYTABLE_NINF -4

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,    12,     4,   -36,    18,    13,   114,   -36,    29,   114,
     -36,    52,    53,    58,    60,     1,    46,   148,    -4,    73,
     -36,   -36,    89,    93,    97,    21,    98,   -36,   124,   -36,
     -36,   -36,    -7,   -36,   -36,    74,     1,     1,    99,    96,
     -36,   111,    32,   117,   103,   109,   113,   132,   137,    63,
      -3,   -36,   -36,   -36,   -36,   -36,   -36,    85,   -36,   142,
     -36,   -36,   -36,   -36,     1,     1,     1,     1,     1,     1,
     -36,   -36,   159,   -36,   -36,   155,   157,    25,   158,   -36,
     160,   -36,   148,    -4,   -36,   110,   -36,   124,   -36,   -36,
     -36,   -36,   -36,   -36,   151,   153,   -36,   -36,   -36,    67,
     134,   136,    22,    22,    22,    22,    22,    42,   -36,   161,
       1,     1,     1,     1,   162,   -36,   -36,   -36,   -36,   -36,
      11,   -36,    22,    22,    22,    22,   -36,   -36,    77,   104,
     -36,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    18,     1,     0,    18,     6,     5,     0,     7,
       4,     0,     0,     0,     0,     0,    42,     0,     0,     0,
      16,    17,     0,     0,     0,     0,     0,    33,     0,    34,
      35,    36,     0,    61,    62,     0,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    53,    14,    15,    11,    12,     0,    31,     0,
      28,    29,    30,    13,     0,     0,     0,     0,     0,     0,
      41,    10,     0,    58,    59,     0,     0,     0,     0,    25,
       0,    44,    64,    66,    60,    65,    67,    63,    27,    40,
      46,    48,    50,    37,     0,     0,     9,    51,    52,     0,
       0,     0,    39,    45,    47,    49,    38,     0,    18,     0,
       0,     0,     0,     0,     0,    26,    57,    56,    32,    43,
       8,    18,    21,    22,    23,    24,    18,    55,     8,     8,
      19,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,   -36,   -36,    -5,   -36,   -36,   -36,   143,   139,
     -36,   -36,   -33,   -35,   -23,   -14,   -22,   -21,   -20,   -36,
     177,   133,   135,   -36,   152,   154
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    19,    20,    21,    76,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    50,
       7,    51,    52,    32,    33,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    41,    58,    60,    61,    62,    71,    86,    49,    85,
      96,    59,     3,    -3,    11,    12,    15,    72,     4,    48,
      13,    14,    77,    77,    99,    40,    15,     4,    87,   127,
     110,   111,   112,   113,    56,    16,    57,    64,    17,    18,
      64,    13,     8,   100,    35,    40,    70,    15,    17,    70,
     101,   102,   103,   104,   105,   106,    40,    15,    42,    82,
      83,    43,    58,    60,    61,    62,    40,    36,    37,    82,
      83,    59,    86,    38,    85,    39,    58,    60,    61,    62,
      11,    12,    57,   118,    49,    59,    13,    14,    94,    95,
      75,    40,    15,    87,    17,   130,   122,   123,   124,   125,
      15,    16,    53,   120,    17,    18,    54,    11,    12,    40,
      55,    63,    17,    13,    14,    79,   128,    11,    12,    15,
      80,   129,   131,    13,    14,    57,    64,    81,    16,    15,
      89,    17,    18,    88,    40,    70,    90,    17,    16,    64,
      91,    17,    18,    65,    66,    67,    68,    69,    70,    64,
      81,    64,   119,    65,    66,    67,    68,    64,    70,    92,
      70,    65,    66,    67,    68,    93,    70,    44,    45,    46,
      47,   107,   108,   109,   114,   116,   115,   117,   121,   126,
      78,    84,    10,    97,    73,    98,    74
};

static const yytype_uint8 yycheck[] =
{
       5,    15,    25,    25,    25,    25,    13,    42,    11,    42,
      13,    25,     0,     0,     3,     4,    15,    24,    14,    23,
       9,    10,    36,    37,    57,    24,    15,    14,    42,    18,
       5,     6,     7,     8,    13,    24,    15,    15,    27,    28,
      15,     9,    24,    57,    15,    24,    24,    15,    27,    24,
      64,    65,    66,    67,    68,    69,    24,    15,    12,    27,
      28,    15,    85,    85,    85,    85,    24,    15,    15,    27,
      28,    85,   107,    15,   107,    15,    99,    99,    99,    99,
       3,     4,    15,    16,    11,    99,     9,    10,    25,    26,
      16,    24,    15,   107,    27,    18,   110,   111,   112,   113,
      15,    24,    13,   108,    27,    28,    13,     3,     4,    24,
      13,    13,    27,     9,    10,    16,   121,     3,     4,    15,
      24,   126,    18,     9,    10,    15,    15,    16,    24,    15,
      27,    27,    28,    16,    24,    24,    27,    27,    24,    15,
      27,    27,    28,    19,    20,    21,    22,    23,    24,    15,
      16,    15,    16,    19,    20,    21,    22,    15,    24,    27,
      24,    19,    20,    21,    22,    28,    24,    19,    20,    21,
      22,    12,    17,    16,    16,    24,    16,    24,    17,    17,
      37,    42,     5,    50,    32,    50,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,     0,    14,    32,    33,    49,    24,    33,
      49,     3,     4,     9,    10,    15,    24,    27,    28,    34,
      35,    36,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    52,    53,    54,    15,    15,    15,    15,    15,
      24,    44,    12,    15,    19,    20,    21,    22,    23,    11,
      48,    50,    51,    13,    13,    13,    13,    15,    43,    44,
      45,    46,    47,    13,    15,    19,    20,    21,    22,    23,
      24,    13,    24,    53,    54,    16,    37,    44,    37,    16,
      24,    16,    27,    28,    38,    41,    42,    44,    16,    27,
      27,    27,    27,    28,    25,    26,    13,    50,    51,    41,
      44,    44,    44,    44,    44,    44,    44,    12,    17,    16,
       5,     6,     7,     8,    16,    16,    24,    24,    16,    16,
      33,    17,    44,    44,    44,    44,    17,    18,    33,    33,
      18,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    31,    30,    32,    32,    32,    32,    34,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    35,
      36,    37,    37,    37,    37,    38,    39,    40,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    42,    42,    43,
      43,    44,    44,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    48,    48,    49,    50,    51,    52,    52,
      52,    52,    52,    53,    53,    53,    54,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     2,     0,     4,
       3,     3,     3,     3,     3,     3,     2,     2,     0,     7,
       7,     3,     3,     3,     3,     3,     4,     3,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     3,     3,     3,
       3,     2,     1,     4,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     1,     7,     3,     3,     2,     2,
       3,     1,     1,     3,     3,     3,     3,     3
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
#line 53 "miint.y" /* yacc.c:1646  */
    {gc("#include \"Q.h\"\n");
	gc("#define INI 0\n");
	gc("#define FIN -2\n");
	gc("BEGIN\n");
	}
#line 1359 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 59 "miint.y" /* yacc.c:1646  */
    {gc("\tGT(-2);\n");
	gc("END\n");}
#line 1366 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 72 "miint.y" /* yacc.c:1646  */
    {gc("STAT(%d)\n", mem.getStat());}
#line 1372 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 85 "miint.y" /* yacc.c:1646  */
    {printf("%d\n", (yyvsp[-4].ent));}
#line 1378 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 89 "miint.y" /* yacc.c:1646  */
    {printf("%d\n", (yyvsp[-4].ent));}
#line 1384 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 94 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getStackElement((yyvsp[-2].cad)).getType(), "ent")==0 && strcmp(stack.getStackElement((yyvsp[0].cad)).getType(), "ent")==0){
		if(stack.getEntValue((yyvsp[-2].cad))>stack.getEntValue((yyvsp[0].cad))){
			(yyval.ent) = 1;
		} else {
			(yyval.ent) = 0;
		}
	}
	}
#line 1398 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 104 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getStackElement((yyvsp[-2].cad)).getType(), "ent")==0 && strcmp(stack.getStackElement((yyvsp[0].cad)).getType(), "ent")==0){
		if(stack.getEntValue((yyvsp[-2].cad))<stack.getEntValue((yyvsp[0].cad))){
			(yyval.ent) = 1;
		} else {
			(yyval.ent) = 0;
		}
	}
	}
#line 1412 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 114 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getStackElement((yyvsp[-2].cad)).getType(), "ent")==0 && strcmp(stack.getStackElement((yyvsp[0].cad)).getType(), "ent")==0){
		if(stack.getEntValue((yyvsp[-2].cad))==stack.getEntValue((yyvsp[0].cad))){
			(yyval.ent) = 1;
		} else {
			(yyval.ent) = 0;
		}
	}
	}
#line 1426 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 124 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getStackElement((yyvsp[-2].cad)).getType(), "ent")==0 && strcmp(stack.getStackElement((yyvsp[0].cad)).getType(), "ent")==0){
		if(stack.getEntValue((yyvsp[-2].cad))!=stack.getEntValue((yyvsp[0].cad))){
			(yyval.ent) = 1;
		} else {
			(yyval.ent) = 0;
		}
	}
	}
#line 1440 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 137 "miint.y" /* yacc.c:1646  */
    {}
#line 1446 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 142 "miint.y" /* yacc.c:1646  */
    {
	if(!stack.exists((yyvsp[-1].cad))){
		printf("la variable no existe\n");
	} else {
	if(strcmp(stack.getStackElement((yyvsp[-1].cad)).getType(), "cad")==0){
		printf("%s\n",stack.getCadValue((yyvsp[-1].cad)));
	}	
	}
	}
#line 1460 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "miint.y" /* yacc.c:1646  */
    {}
#line 1466 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 171 "miint.y" /* yacc.c:1646  */
    {
		char* j= strcat((yyvsp[-2].cad), (yyvsp[0].cad));
		printf("%s\n", j);
	}
#line 1475 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 178 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getStackElement((yyvsp[-2].cad)).getType(), "cad")==0 && strcmp(stack.getStackElement((yyvsp[0].cad)).getType(), "cad")==0){
		(yyval.cad) = strcat(stack.getCadValue((yyvsp[-2].cad)), stack.getCadValue((yyvsp[0].cad)));
	}
	;
	}
#line 1486 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 188 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getStackElement((yyvsp[-2].cad)).getType(), "ent")==0 && strcmp(stack.getStackElement((yyvsp[0].cad)).getType(), "ent")==0){
		(yyval.ent) = stack.getEntValue((yyvsp[-2].cad)) + stack.getEntValue((yyvsp[0].cad));
	}
	;
	}
#line 1497 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 194 "miint.y" /* yacc.c:1646  */
    {(yyval.ent)=(yyvsp[-2].ent)+(yyvsp[0].ent);}
#line 1503 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 198 "miint.y" /* yacc.c:1646  */
    {(yyval.cad)=(yyvsp[0].cad);}
#line 1509 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 199 "miint.y" /* yacc.c:1646  */
    {(yyval.cad)=(yyvsp[0].cad);}
#line 1515 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 200 "miint.y" /* yacc.c:1646  */
    {(yyval.cad) = (yyvsp[-1].cad);}
#line 1521 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 201 "miint.y" /* yacc.c:1646  */
    {(yyval.cad) = (yyvsp[-1].cad);}
#line 1527 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 206 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getStackElement((yyvsp[-2].cad)).getType(), "ent")==0 && strcmp(stack.getStackElement((yyvsp[0].cad)).getType(), "ent")==0){
		(yyval.ent) = stack.getEntValue((yyvsp[-2].cad)) - stack.getEntValue((yyvsp[0].cad));
	}
	;
	}
#line 1538 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 212 "miint.y" /* yacc.c:1646  */
    {(yyval.ent)=(yyvsp[-2].ent)-(yyvsp[0].ent);}
#line 1544 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 217 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getStackElement((yyvsp[-2].cad)).getType(), "ent")==0 && strcmp(stack.getStackElement((yyvsp[0].cad)).getType(), "ent")==0){
		(yyval.ent) = stack.getEntValue((yyvsp[-2].cad)) * stack.getEntValue((yyvsp[0].cad));
	}
	;
	}
#line 1555 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 223 "miint.y" /* yacc.c:1646  */
    {(yyval.ent)=(yyvsp[-2].ent)*(yyvsp[0].ent);}
#line 1561 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 228 "miint.y" /* yacc.c:1646  */
    {
	if(strcmp(stack.getStackElement((yyvsp[-2].cad)).getType(), "ent")==0 && strcmp(stack.getStackElement((yyvsp[0].cad)).getType(), "ent")==0){
		(yyval.ent) = stack.getEntValue((yyvsp[-2].cad)) / stack.getEntValue((yyvsp[0].cad));
	}
	;
	}
#line 1572 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 234 "miint.y" /* yacc.c:1646  */
    {(yyval.ent)=(yyvsp[-2].ent)-(yyvsp[0].ent);}
#line 1578 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 247 "miint.y" /* yacc.c:1646  */
    {
	if(stack.exists((yyvsp[-5].cad))){
		printf("ya existe\n");
	} else {
		//stack.addStackElement($2, "func");	
	}
	}
#line 1590 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 259 "miint.y" /* yacc.c:1646  */
    {
	if(stack.exists((yyvsp[0].cad))){
		printf("ya existe\n");
	} else {
		//printf("adding %s\n", $3);
		int dir = mem.cogerDireccionDeMemoriaEnt();
		
		gc("\tMEM(0x%x, %d);\n", dir, 4);
		gc("CODE(%d)\n", mem.getCode());
		stack.addStackElement((yyvsp[0].cad), "ent", dir);	
	}
	}
#line 1607 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 275 "miint.y" /* yacc.c:1646  */
    {
	if(stack.exists((yyvsp[0].cad))){
		printf("ya existe\n");
	} else {
		int dir = mem.cogerDireccionDeMemoriaCad();
		gc("STAT(%d)\n", mem.getStat());
		gc("\tMEM(0x%x, %d);\n", dir, 20);
		gc("CODE(%d)\n", mem.getCode());
		stack.addStackElement((yyvsp[0].cad), "cad", dir);	
	}
	}
#line 1623 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 291 "miint.y" /* yacc.c:1646  */
    {}
#line 1629 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 298 "miint.y" /* yacc.c:1646  */
    {
	if(!stack.exists((yyvsp[-2].cad))){
		printf("la variable no existe\n");
	} else {
		if(!stack.exists((yyvsp[0].cad))){
			printf("la variable no existe\n");
		} else {
			gc("\tR%d=%d;\n", stack.getEntValue((yyvsp[0].cad)), (yyvsp[-2].cad));
			stack.addEntValue(stack.getEntValue((yyvsp[0].cad)), (yyvsp[-2].cad));
	}
	}
	}
#line 1646 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 310 "miint.y" /* yacc.c:1646  */
    {
	
	if(!stack.exists((yyvsp[-2].cad))){
		printf("la variable no existe\n");
	} else {
		int id=mem.devuelveRegistroLibre();
		gc("\tR%d=0x%x;\n", id, stack.getStackElement((yyvsp[-2].cad)).getAddress(), (yyvsp[0].ent));
		int val = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", val, (yyvsp[0].ent));
		gc("\tI(R%d)=R%d;\n", id, val);
		mem.liberaRegistro(id);
		mem.liberaRegistro(val);
		stack.addEntValue((yyvsp[0].ent), (yyvsp[-2].cad));
	}	
	
	}
#line 1667 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 327 "miint.y" /* yacc.c:1646  */
    {
	if(!stack.exists((yyvsp[-2].cad))){
		printf("la variable no existe\n");
	} else {
		printf("ha\n");
		gc("\tR%d=%d;\n", mem.devuelveRegistroLibre(), (yyvsp[0].ent));
		stack.addEntValue((yyvsp[0].ent), (yyvsp[-2].cad));
	}
	}
#line 1681 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 339 "miint.y" /* yacc.c:1646  */
    {
	
	if(!stack.exists((yyvsp[-2].cad))){
		printf("la variable no existe\n");
	} else {
		stack.addCadValue((yyvsp[0].cad), (yyvsp[-2].cad));
	}	
	
	}
#line 1695 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 350 "miint.y" /* yacc.c:1646  */
    {
	if(!stack.exists((yyvsp[-2].cad))){
		printf("la variable no existe\n");
	} else {
		stack.addCadValue((yyvsp[0].cad), (yyvsp[-2].cad));
	}
	}
#line 1707 "miint.tab.c" /* yacc.c:1646  */
    break;


#line 1711 "miint.tab.c" /* yacc.c:1646  */
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
#line 358 "miint.y" /* yacc.c:1906  */


int main(int argc, char** argv) {
	// open a file handle to a particular file:
	if(argc>1) yyin=fopen(argv[1], "r");
	yyparse();
	stack.printStack();
	
	
}

void gc(const char* code, ...){
	printf("dentro\n");
	va_list args;
	va_start (args, code);
	vfprintf(qFile, code, args);
	va_end (args);
}

void yyerror(const char *s) {
	printf("error sintactico: %s\n", s);
}
