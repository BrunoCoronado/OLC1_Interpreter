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
#line 2 "parser.y" /* yacc.c:339  */

    #include "scanner.h"
    #include <cstdio>
    #include <iostream>
    #include <sstream>
    #include <QString>
    #include <QList>

    using namespace std;

    #include "nodo.h"; 
    #include "error.h"

    
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
    extern char *yytext;

    extern nodo *raizAST;
    extern bool errorCompilacion;
    extern QList<error> errores;

    int yyerror(const char* mens)
    {
        stringstream ss;
        ss << mens <<" no se reconocio " <<" "<<yytext;
        std::string s = ss.str();
        error e(ss.str(),yylineno);
        errores.append(e);
        errorCompilacion = true;
        return 0;
    }

#line 101 "parser.cpp" /* yacc.c:339  */

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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    INT = 258,
    DOUBLE = 259,
    BOOL = 260,
    CHAR = 261,
    STRING = 262,
    ARREGLO = 263,
    TRUE = 264,
    FALSE = 265,
    IMPRIMIR = 266,
    SHOW = 267,
    SI = 268,
    SINO = 269,
    PARA = 270,
    REPETIR = 271,
    ACEPTACION = 272,
    IGUAL_IGUAL = 273,
    NO_IGUAL = 274,
    MENOR_QUE = 275,
    MENOR_IGUAL = 276,
    MAYOR_QUE = 277,
    MAYOR_IGUAL = 278,
    OR = 279,
    AND = 280,
    NOT = 281,
    MAS = 282,
    MENOS = 283,
    MULTIPLICACION = 284,
    DIVISION = 285,
    POTENCIA = 286,
    COMA = 287,
    IGUAL = 288,
    PUNTO_Y_COMA = 289,
    MAS_MAS = 290,
    MENOS_MENOS = 291,
    CORCHETE_ABRE = 292,
    CORCHETE_CIERRA = 293,
    LLAVE_CIERRA = 294,
    LLAVE_ABRE = 295,
    PARENTESIS_ABRE = 296,
    PARENTESIS_CIERRA = 297,
    IDENTIFICADOR = 298,
    ENTERO = 299,
    DECIMAL = 300,
    CADENA = 301,
    CARACTER = 302,
    ERROR = 303
  };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define BOOL 260
#define CHAR 261
#define STRING 262
#define ARREGLO 263
#define TRUE 264
#define FALSE 265
#define IMPRIMIR 266
#define SHOW 267
#define SI 268
#define SINO 269
#define PARA 270
#define REPETIR 271
#define ACEPTACION 272
#define IGUAL_IGUAL 273
#define NO_IGUAL 274
#define MENOR_QUE 275
#define MENOR_IGUAL 276
#define MAYOR_QUE 277
#define MAYOR_IGUAL 278
#define OR 279
#define AND 280
#define NOT 281
#define MAS 282
#define MENOS 283
#define MULTIPLICACION 284
#define DIVISION 285
#define POTENCIA 286
#define COMA 287
#define IGUAL 288
#define PUNTO_Y_COMA 289
#define MAS_MAS 290
#define MENOS_MENOS 291
#define CORCHETE_ABRE 292
#define CORCHETE_CIERRA 293
#define LLAVE_CIERRA 294
#define LLAVE_ABRE 295
#define PARENTESIS_ABRE 296
#define PARENTESIS_CIERRA 297
#define IDENTIFICADOR 298
#define ENTERO 299
#define DECIMAL 300
#define CADENA 301
#define CARACTER 302
#define ERROR 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "parser.y" /* yacc.c:355  */

    class nodo *nodoAST;
    char *cont;

#line 242 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 273 "parser.cpp" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   682

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   135,   142,   147,   154,   161,   167,   171,
     175,   179,   183,   187,   193,   201,   206,   215,   223,   227,
     231,   235,   239,   245,   252,   259,   266,   273,   280,   287,
     294,   300,   307,   314,   320,   327,   334,   341,   348,   355,
     362,   366,   371,   376,   381,   386,   390,   394,   399,   405,
     412,   422,   428,   435,   445,   449,   455,   462,   466,   472,
     479,   485,   492,   498,   506,   513,   517,   523,   527,   531,
     535,   541,   547,   556,   560,   567,   574,   586,   595,   602,
     608,   619,   623,   633,   640
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "BOOL", "CHAR",
  "STRING", "ARREGLO", "TRUE", "FALSE", "IMPRIMIR", "SHOW", "SI", "SINO",
  "PARA", "REPETIR", "ACEPTACION", "IGUAL_IGUAL", "NO_IGUAL", "MENOR_QUE",
  "MENOR_IGUAL", "MAYOR_QUE", "MAYOR_IGUAL", "OR", "AND", "NOT", "MAS",
  "MENOS", "MULTIPLICACION", "DIVISION", "POTENCIA", "COMA", "IGUAL",
  "PUNTO_Y_COMA", "MAS_MAS", "MENOS_MENOS", "CORCHETE_ABRE",
  "CORCHETE_CIERRA", "LLAVE_CIERRA", "LLAVE_ABRE", "PARENTESIS_ABRE",
  "PARENTESIS_CIERRA", "IDENTIFICADOR", "ENTERO", "DECIMAL", "CADENA",
  "CARACTER", "ERROR", "$accept", "A", "B", "C0", "C", "D", "D0", "E", "F",
  "G", "H", "H1", "H2", "I", "J", "J0", "J1", "K", "L", "L0", "L1", "M",
  "M0", "M1", "N", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,   -91,   -91,   -91,   -91,   -91,   -32,   -23,   -14,   -11,
      -1,   -91,    27,   -91,   -91,   -91,    73,    80,   -91,   -91,
      -4,   -91,    -2,   -91,   -91,    61,   -91,   -91,   304,   304,
     304,    19,   304,   304,   -91,   -91,   -91,    47,   -91,    11,
     -91,   -91,    69,    -5,   -91,   -91,   304,   304,   304,    76,
     -91,   -91,   -91,   -91,   334,   608,   350,    81,   -91,   304,
     366,   540,   -22,    47,   304,   -91,   -91,   274,   -91,    88,
     651,   -18,   382,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,    71,   304,    82,
     304,   557,    94,   -91,   304,    55,   -91,   574,   139,   -91,
       1,   -91,   414,    89,    89,    89,    89,    89,    89,   637,
     651,   -18,   -18,    95,    95,   -91,   -91,   398,   274,   591,
      86,   274,   435,    96,   -91,   -91,   -91,   -91,   274,   -91,
      91,   101,   156,   -91,   -91,   103,    97,   201,   111,   147,
     106,   215,   304,   -91,   -91,   -91,   113,   -91,   304,   282,
     623,    -3,    62,   -91,   -91,   456,   274,   477,   304,    67,
      68,   118,   -91,   304,   -91,   127,   260,   128,    72,   130,
     -91,   -91,   -91,   -91,   304,   -91,   304,   -91,   -91,   498,
     519,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    19,    20,    21,    22,     0,     0,     0,     0,
       0,     3,    67,    69,    68,    70,     0,     0,     5,     8,
       0,     9,     0,    10,    11,    73,    12,    13,     0,     0,
       0,     0,     0,     0,     1,     2,     4,     0,    24,     0,
      65,    66,     0,     0,    45,    46,     0,     0,     0,    47,
      41,    42,    44,    43,     0,     0,     0,     0,    81,     0,
       0,     0,     0,     0,     0,    15,    64,     0,    79,    75,
      33,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,    23,     0,     0,     7,
       0,    40,     0,    34,    35,    36,    38,    37,    39,    32,
      31,    25,    26,    27,    28,    29,    71,     0,     0,     0,
       0,     0,     0,     0,    17,    14,    74,     6,     0,    78,
      48,     0,     0,    82,    67,     0,     0,     0,    51,     0,
       0,     0,     0,    72,    77,    83,     0,    84,     0,     0,
      62,     0,     0,    16,    76,     0,     0,     0,     0,     0,
       0,     0,    54,     0,    55,    49,     0,    52,     0,     0,
      57,    58,    56,    61,     0,    80,     0,    60,    59,     0,
       0,    50,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   -90,     0,   143,   -91,   -21,   -27,   -91,
     -91,    15,     8,   -84,   -91,   -91,    59,   -91,   -91,   -36,
      85,   -91,   -91,   -91,   -91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    98,    99,    19,    20,    39,   150,    95,
     140,   151,   159,   152,    21,    42,    22,    23,    24,    25,
      69,    26,    59,   136,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      18,    54,    55,    56,    37,    60,    61,    68,     8,    28,
      63,    84,    85,    86,     8,    94,    62,    36,    29,    70,
      71,    72,     1,     2,     3,     4,     5,    30,   132,   161,
      31,   137,    91,    40,    41,    67,   162,    97,   141,    38,
      32,   128,    96,    63,    64,    65,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      33,   117,    57,   119,    68,   160,   166,   122,     1,     2,
       3,     4,     5,    34,   168,    43,     6,     7,     8,   173,
       9,    10,    11,     1,     2,     3,     4,     5,   123,   124,
      38,     6,     7,     8,   163,     9,    10,    35,   127,   169,
     163,   164,   100,    66,   163,   116,   170,   171,    12,    13,
      14,   177,    15,    73,    90,   155,    82,    83,    84,    85,
      86,   157,   118,    12,    13,    14,    86,    15,   142,   134,
      13,    14,   127,    15,   121,   143,   139,   127,   145,   146,
     153,   127,     1,     2,     3,     4,     5,   179,   148,   180,
       6,     7,     8,   156,     9,    10,    44,    45,   149,     1,
       2,     3,     4,     5,   174,   176,   127,     6,     7,     8,
     158,     9,    10,    46,    58,    47,   172,   178,   126,   135,
       0,     0,    12,    13,    14,   129,    15,   149,    48,     0,
      49,    50,    51,    52,    53,   144,     0,     0,     0,    12,
      13,    14,     0,    15,     1,     2,     3,     4,     5,     0,
       0,     0,     6,     7,     8,     0,     9,    10,     1,     2,
       3,     4,     5,     0,     0,     0,     6,     7,     8,     0,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
     147,     0,     0,     0,    12,    13,    14,     0,    15,     0,
       0,     0,     0,     0,   154,     0,     0,     0,    12,    13,
      14,     0,    15,     1,     2,     3,     4,     5,     0,     0,
       0,     6,     7,     8,     0,     9,    10,     1,     2,     3,
       4,     5,     0,     0,     0,     6,     7,     8,     0,     9,
      10,    44,    45,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,    12,    13,    14,     0,    15,    46,     0,
      47,     0,     0,    44,    45,     0,     0,    12,    13,    14,
       0,    15,   158,    48,     0,    49,    50,    51,    52,    53,
      46,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    49,    50,    51,
      52,    53,    74,    75,    76,    77,    78,    79,    80,    81,
       0,    82,    83,    84,    85,    86,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    87,    82,    83,    84,
      85,    86,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    89,    82,    83,    84,    85,    86,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    92,    82,
      83,    84,    85,    86,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,   101,    82,    83,    84,    85,    86,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
     131,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,     0,   130,    74,    75,    76,    77,    78,    79,    80,
      81,     0,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,     0,   138,    74,    75,    76,    77,    78,    79,
      80,    81,     0,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,   165,    74,    75,    76,    77,    78,
      79,    80,    81,     0,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,     0,   167,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,   181,    74,    75,    76,
      77,    78,    79,    80,    81,     0,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,   182,    74,    75,
      76,    77,    78,    79,    80,    81,     0,    82,    83,    84,
      85,    86,     0,     0,    93,    74,    75,    76,    77,    78,
      79,    80,    81,     0,    82,    83,    84,    85,    86,     0,
       0,   120,    74,    75,    76,    77,    78,    79,    80,    81,
       0,    82,    83,    84,    85,    86,     0,     0,   125,    74,
      75,    76,    77,    78,    79,    80,    81,     0,    82,    83,
      84,    85,    86,     0,     0,   133,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,    83,    84,    85,    86,
      88,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,    83,    84,    85,    86,    74,    75,    76,    77,    78,
      79,     0,    81,     0,    82,    83,    84,    85,    86,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    82,    83,
      84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       0,    28,    29,    30,     8,    32,    33,    43,    13,    41,
      32,    29,    30,    31,    13,    37,    37,    17,    41,    46,
      47,    48,     3,     4,     5,     6,     7,    41,   118,    32,
      41,   121,    59,    35,    36,    40,    39,    64,   128,    43,
      41,    40,    63,    32,    33,    34,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      33,    88,    43,    90,   100,   149,   156,    94,     3,     4,
       5,     6,     7,     0,   158,    14,    11,    12,    13,   163,
      15,    16,    17,     3,     4,     5,     6,     7,    33,    34,
      43,    11,    12,    13,    32,    15,    16,    17,    98,    32,
      32,    39,    14,    34,    32,    34,    39,    39,    43,    44,
      45,    39,    47,    37,    33,   142,    27,    28,    29,    30,
      31,   148,    40,    43,    44,    45,    31,    47,    37,    43,
      44,    45,   132,    47,    40,    34,    40,   137,    35,    42,
      34,   141,     3,     4,     5,     6,     7,   174,    37,   176,
      11,    12,    13,    40,    15,    16,     9,    10,    40,     3,
       4,     5,     6,     7,    37,    37,   166,    11,    12,    13,
      40,    15,    16,    26,    31,    28,   161,   169,    39,   120,
      -1,    -1,    43,    44,    45,   100,    47,    40,    41,    -1,
      43,    44,    45,    46,    47,    39,    -1,    -1,    -1,    43,
      44,    45,    -1,    47,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    -1,    15,    16,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    12,    13,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    43,    44,    45,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    43,    44,
      45,    -1,    47,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    12,    13,    -1,    15,    16,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    12,    13,    -1,    15,
      16,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    43,    44,    45,    -1,    47,    26,    -1,
      28,    -1,    -1,     9,    10,    -1,    -1,    43,    44,    45,
      -1,    47,    40,    41,    -1,    43,    44,    45,    46,    47,
      26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    44,    45,
      46,    47,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    42,    27,    28,    29,
      30,    31,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    42,    27,    28,    29,    30,    31,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    42,    27,
      28,    29,    30,    31,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    42,    27,    28,    29,    30,    31,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      42,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    34,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    34,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    34,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    34,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    18,    19,    20,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    31,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    27,    28,
      29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    11,    12,    13,    15,
      16,    17,    43,    44,    45,    47,    50,    51,    53,    54,
      55,    63,    65,    66,    67,    68,    70,    73,    41,    41,
      41,    41,    41,    33,     0,    17,    53,     8,    43,    56,
      35,    36,    64,    14,     9,    10,    26,    28,    41,    43,
      44,    45,    46,    47,    57,    57,    57,    43,    54,    71,
      57,    57,    56,    32,    33,    34,    34,    40,    68,    69,
      57,    57,    57,    37,    18,    19,    20,    21,    22,    23,
      24,    25,    27,    28,    29,    30,    31,    42,    32,    42,
      33,    57,    42,    34,    37,    58,    56,    57,    52,    53,
      14,    42,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    34,    57,    40,    57,
      34,    40,    57,    33,    34,    34,    39,    53,    40,    69,
      38,    42,    52,    34,    43,    65,    72,    52,    38,    40,
      59,    52,    37,    34,    39,    35,    42,    39,    37,    40,
      57,    60,    62,    34,    39,    57,    40,    57,    40,    61,
      62,    32,    39,    32,    39,    38,    52,    38,    62,    32,
      39,    39,    60,    62,    37,    39,    37,    39,    61,    57,
      57,    38,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    67,    67,    67,    68,    69,    69,
      70,    71,    71,    72,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     7,     5,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       2,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     7,
      10,     3,     6,     9,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     4,     3,     1,     1,     1,     1,     1,
       1,     5,     7,     1,     5,     3,     7,     7,     3,     1,
      10,     1,     4,     2,     7
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 131 "parser.y" /* yacc.c:1646  */
    {
            nodo *n = new nodo("aceptacion", "$", 0);
            raizAST->agregar(*n);
        }
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 136 "parser.y" /* yacc.c:1646  */
    {
            nodo *n = new nodo("aceptacion", "$", 0);
            raizAST->agregar(*n);
        }
#line 1681 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "parser.y" /* yacc.c:1646  */
    {
            raizAST->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = (yyvsp[-1].nodoAST);
        }
#line 1690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 148 "parser.y" /* yacc.c:1646  */
    {
            raizAST->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 1699 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 155 "parser.y" /* yacc.c:1646  */
    {
            nodo *n = new nodo("C0", "C0", 0);
            n->agregar(*(yyvsp[-1].nodoAST));
            n->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = n;
        }
#line 1710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 162 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 1718 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 168 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 1726 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 176 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 1742 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 180 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 1750 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 184 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 1758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 188 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 1766 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 194 "parser.y" /* yacc.c:1646  */
    {
            (yyvsp[-4].nodoAST)->agregar(*(yyvsp[-3].nodoAST));
            nodo *n = new nodo("igual", "=", 11);
            n->agregar(*(yyvsp[-1].nodoAST));
            (yyvsp[-4].nodoAST)->agregar(*n);
            (yyval.nodoAST) = (yyvsp[-4].nodoAST);
        }
#line 1778 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 202 "parser.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].nodoAST)->agregar(*(yyvsp[-1].nodoAST));
            (yyval.nodoAST) = (yyvsp[-2].nodoAST);
        }
#line 1787 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 207 "parser.y" /* yacc.c:1646  */
    {
            (yyvsp[-6].nodoAST)->agregar(*(yyvsp[-4].nodoAST));
            (yyvsp[-6].nodoAST)->agregar(*(yyvsp[-3].nodoAST));
            nodo *n = new nodo("igual", "=", 11);
            n->agregar(*(yyvsp[-1].nodoAST));
            (yyvsp[-6].nodoAST)->agregar(*n);
            (yyval.nodoAST) = (yyvsp[-6].nodoAST);
        }
#line 1800 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 216 "parser.y" /* yacc.c:1646  */
    {
            (yyvsp[-4].nodoAST)->agregar(*(yyvsp[-2].nodoAST));
            (yyvsp[-4].nodoAST)->agregar(*(yyvsp[-1].nodoAST));
            (yyval.nodoAST) = (yyvsp[-4].nodoAST);
        }
#line 1810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 224 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("tipo de dato", "int", 50);
        }
#line 1818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 228 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("tipo de dato", "double", 51);
        }
#line 1826 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 232 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("tipo de dato", "bool", 52);
        }
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 236 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("tipo de dato", "char", 53);
        }
#line 1842 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 240 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("tipo de dato", "string", 54);
        }
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 246 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("coma", ",", 10); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1861 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 253 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("identificador", (yyvsp[0].cont), 1);
            free((yyvsp[0].cont));
        }
#line 1870 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 260 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("aritmetico", "+", 25); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1881 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 267 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("aritmetico", "-", 21); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1892 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 274 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("aritmetico", "*", 24); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1903 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 281 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("aritmetico", "/", 23); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1914 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 288 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("aritmetico", "^", 22); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1925 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 295 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("aritmetico", "-", 21); 
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1935 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 301 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("logico", "&&", 20); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1946 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 308 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("logico", "||", 19); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1957 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 315 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("logico", "!", 18); 
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1967 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 321 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("relacional", "==", 17); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1978 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 328 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("relacional", "!=", 16); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 1989 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 335 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("relacional", "<", 15); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2000 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 342 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("relacional", ">", 14); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2011 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 349 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("relacional", "<=", 13); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 356 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("relacional", ">=", 12); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 363 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[-1].nodoAST);
        }
#line 2041 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 367 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("entero", (yyvsp[0].cont), 60);
            free((yyvsp[0].cont));
        }
#line 2050 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 372 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("decimal", (yyvsp[0].cont), 59);
            free((yyvsp[0].cont));
        }
#line 2059 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 377 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("caracter", (yyvsp[0].cont), 58);
            free((yyvsp[0].cont));
        }
#line 2068 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 382 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("cadena", (yyvsp[0].cont), 57);
            free((yyvsp[0].cont));
        }
#line 2077 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 387 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("true", "true", 56);
        }
#line 2085 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 391 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("false", "false", 55);
        }
#line 2093 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 395 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("identificador", (yyvsp[0].cont), 1);
            free((yyvsp[0].cont));
        }
#line 2102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 400 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("identificador", (yyvsp[-3].cont), 1);
            padre->agregar(*(yyvsp[-1].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 406 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("identificador", (yyvsp[-6].cont), 1);
            padre->agregar(*(yyvsp[-4].nodoAST));
            padre->agregar(*(yyvsp[-1].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 413 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("identificador", (yyvsp[-9].cont), 1);
            padre->agregar(*(yyvsp[-7].nodoAST));
            padre->agregar(*(yyvsp[-4].nodoAST));
            padre->agregar(*(yyvsp[-1].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2135 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 423 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("arreglo", "arreglo", 2); 
            padre->agregar(*(yyvsp[-1].nodoAST));
            (yyval.nodoAST) = padre;   
        }
#line 2145 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 429 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("arreglo", "arreglo", 2); 
            padre->agregar(*(yyvsp[-4].nodoAST));
            padre->agregar(*(yyvsp[-1].nodoAST));
            (yyval.nodoAST) = padre;   
        }
#line 2156 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 436 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("arreglo", "arreglo", 2); 
            padre->agregar(*(yyvsp[-7].nodoAST));
            padre->agregar(*(yyvsp[-4].nodoAST));
            padre->agregar(*(yyvsp[-1].nodoAST));
            (yyval.nodoAST) = padre;   
        }
#line 2168 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 446 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[-1].nodoAST);
        }
#line 2176 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 450 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[-1].nodoAST);
        }
#line 2184 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 456 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("coma", ",", 10); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2195 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 463 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[-1].nodoAST);
        }
#line 2203 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 467 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[-1].nodoAST);
        }
#line 2211 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 473 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("coma", ",", 10); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2222 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 480 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[-1].nodoAST);
        }
#line 2230 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 486 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("coma", ",", 10); 
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2241 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 493 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 2249 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 499 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("identificador", (yyvsp[-3].cont), 1);
            nodo *n = new nodo("igual", "=", 11);
            n->agregar(*(yyvsp[-1].nodoAST));
            padre->agregar(*n);
            (yyval.nodoAST) = padre;
        }
#line 2261 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 507 "parser.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].nodoAST)->agregar(*(yyvsp[-2].nodoAST));
            (yyval.nodoAST) = (yyvsp[-1].nodoAST);
        }
#line 2270 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 514 "parser.y" /* yacc.c:1646  */
    {
           (yyval.nodoAST) = new nodo("mas mas", "++", 26);
        }
#line 2278 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 518 "parser.y" /* yacc.c:1646  */
    {
           (yyval.nodoAST) = new nodo("menos menos", "--", 27);
        }
#line 2286 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 524 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("identificador", (yyvsp[0].cont), 1);
        }
#line 2294 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 528 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("decimal", (yyvsp[0].cont), 59);
        }
#line 2302 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 532 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("entero", (yyvsp[0].cont), 60);
        }
#line 2310 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 536 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("caracter", (yyvsp[0].cont), 58);
        }
#line 2318 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 542 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("imprimir", "imprimir", 70);
            padre->agregar(*(yyvsp[-2].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2328 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 548 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("show", "show", 71);
            padre->agregar(*(yyvsp[-4].nodoAST));
            padre->agregar(*(yyvsp[-2].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2339 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 557 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 2347 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 561 "parser.y" /* yacc.c:1646  */
    {
            nodo *n = new nodo("sino", "sino", 73);
            n->agregar(*(yyvsp[-1].nodoAST));
            (yyvsp[-4].nodoAST)->agregar(*n);
            (yyval.nodoAST) = (yyvsp[-4].nodoAST);   
        }
#line 2358 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 568 "parser.y" /* yacc.c:1646  */
    {
            //nodo *n = new nodo("sino", "sino", 73);
            //$1->agregar(*n);
            (yyvsp[-2].nodoAST)->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = (yyvsp[-2].nodoAST);
        }
#line 2369 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 575 "parser.y" /* yacc.c:1646  */
    {   
            //nodo *n1 = new nodo("sino", "sino", 73);
            //$1->agregar(*n1);
            (yyvsp[-6].nodoAST)->agregar(*(yyvsp[-4].nodoAST));
            nodo *n2 = new nodo("sino", "sino", 73);
            n2->agregar(*(yyvsp[-1].nodoAST));
            (yyvsp[-6].nodoAST)->agregar(*n2);
            (yyval.nodoAST) = (yyvsp[-6].nodoAST);
        }
#line 2383 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 587 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("si", "si", 72);
            padre->agregar(*(yyvsp[-4].nodoAST));
            padre->agregar(*(yyvsp[-1].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2394 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 596 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("sino", "sino", 73);
            padre->agregar(*(yyvsp[-2].nodoAST));
            padre->agregar(*(yyvsp[0].nodoAST));
            (yyval.nodoAST) = padre;
        }
#line 2405 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 603 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 2413 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 609 "parser.y" /* yacc.c:1646  */
    {
        nodo *padre = new nodo("para", "para", 74);
        padre->agregar(*(yyvsp[-7].nodoAST));
        padre->agregar(*(yyvsp[-6].nodoAST));
        padre->agregar(*(yyvsp[-1].nodoAST));
        padre->agregar(*(yyvsp[-4].nodoAST));
        (yyval.nodoAST) = padre;
    }
#line 2426 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 620 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = (yyvsp[0].nodoAST);
        }
#line 2434 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 624 "parser.y" /* yacc.c:1646  */
    {
            nodo *padre = new nodo("identificador", (yyvsp[-3].cont), 1);
            nodo *n = new nodo("igual", "=", 11);
            n->agregar(*(yyvsp[-1].nodoAST));
            padre->agregar(*n);
            (yyval.nodoAST) = padre;
        }
#line 2446 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 634 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodoAST) = new nodo("mas mas", "++", 26);
            (yyval.nodoAST)->agregar(*(yyvsp[-1].nodoAST));
        }
#line 2455 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 641 "parser.y" /* yacc.c:1646  */
    {
        nodo *padre = new nodo("repetir", "repetir", 75);
        padre->agregar(*(yyvsp[-4].nodoAST));
        padre->agregar(*(yyvsp[-1].nodoAST));
        (yyval.nodoAST) = padre;
    }
#line 2466 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2470 "parser.cpp" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 649 "parser.y" /* yacc.c:1906  */

/*codigo adicional C*/
