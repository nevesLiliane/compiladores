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
#line 1 "sintatica.y" /* yacc.c:339  */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <list> 

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string tamanho;
	string jump;
	string blocoIni;
	string blocoFim;
	bool isFunction;
	bool stringDinamica;
	int tamanhoString;
};

//Estrutura que guarda informações sobre o cast a ser feito
typedef struct _tipo_cast
{
	string resultado;
	int operando_cast;
} tipo_cast;
// Mapa de casts
map<string, tipo_cast> mapa_cast;
list < map<string,atributos>* > escopo;
list<atributos*> estruturasDeRepeticao;
list<string> erros;
int contador = 0;
int numBloco = 0;
int yylex(void);
void yyerror(string);
string createvar(void);

// Função para geração do mapa de cast
void gera_mapa_cast();
string gera_chave(string operador1, string operador2, string operacao);
tipo_cast cast_possivel(string tipo1, string tipo2, string operador);

//Funções para escopo
void abrirEscopo();
void fecharEscopo();
bool varNoEscopo(string varName);
bool varNoEscopoAtual(string varName);
atributos* getVarNoEscopo(string varName);
string gerarBloco();
string gerarInicioDeBloco(string l);
string gerarFimDeBloco(string l);
template < typename T > std::string to_string( const T& n );

#line 126 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TK_NUM = 258,
    TK_CHAR = 259,
    TK_REAL = 260,
    TK_STRING = 261,
    TK_TIPO_FLOAT = 262,
    TK_TIPO_CHAR = 263,
    TK_TIPO_STRING = 264,
    TK_TIPO_BOOL = 265,
    TK_MAIN = 266,
    TK_ID = 267,
    TK_TIPO_INT = 268,
    TK_FIM = 269,
    TK_ERROR = 270,
    TK_COMP = 271,
    TK_LT = 272,
    TK_GT = 273,
    TK_LTE = 274,
    TK_GTE = 275,
    TK_DIFF = 276,
    TK_OR = 277,
    TK_AND = 278,
    TK_NOT = 279,
    TK_XOR = 280,
    TK_EQ = 281,
    TK_MOD = 282,
    TK_TIPO_BOOL_TRUE = 283,
    TK_TIPO_BOOL_FALSE = 284,
    TK_SHIFT_LEFT = 285,
    TK_SHIFT_RIGHT = 286,
    TK_IF = 287,
    TK_ELSE = 288,
    TK_WHILE = 289,
    TK_DO = 290,
    TK_FOR = 291,
    TK_BREAK = 292,
    TK_CONTINUE = 293,
    TK_PLUS = 294,
    TK_SUB = 295,
    TK_MULT = 296,
    TK_DIV = 297
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_CHAR 259
#define TK_REAL 260
#define TK_STRING 261
#define TK_TIPO_FLOAT 262
#define TK_TIPO_CHAR 263
#define TK_TIPO_STRING 264
#define TK_TIPO_BOOL 265
#define TK_MAIN 266
#define TK_ID 267
#define TK_TIPO_INT 268
#define TK_FIM 269
#define TK_ERROR 270
#define TK_COMP 271
#define TK_LT 272
#define TK_GT 273
#define TK_LTE 274
#define TK_GTE 275
#define TK_DIFF 276
#define TK_OR 277
#define TK_AND 278
#define TK_NOT 279
#define TK_XOR 280
#define TK_EQ 281
#define TK_MOD 282
#define TK_TIPO_BOOL_TRUE 283
#define TK_TIPO_BOOL_FALSE 284
#define TK_SHIFT_LEFT 285
#define TK_SHIFT_RIGHT 286
#define TK_IF 287
#define TK_ELSE 288
#define TK_WHILE 289
#define TK_DO 290
#define TK_FOR 291
#define TK_BREAK 292
#define TK_CONTINUE 293
#define TK_PLUS 294
#define TK_SUB 295
#define TK_MULT 296
#define TK_DIV 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      43,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    91,    97,   101,   107,   113,   118,   125,
     132,   136,   141,   146,   150,   156,   173,   190,   206,   223,
     243,   259,   277,   293,   309,   325,   342,   359,   376,   402,
     424,   457,   478,   493,   496,   510,   515,   521,   527,   533,
     540,   545,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   561,   565,   569,   573,   577,   583,   593,   608,   616,
     627,   641,   652,   665,   676,   690,   701,   711,   721,   727,
     733,   747,   753,   759,   765,   771,   777,   783,   789,   797,
     803,   811,   817,   823,   829,   835,   841,   847,   856,   862,
     868,   875,   882,   889,   896,   903,   910,   917,   924,   932,
     940,   950,   959
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_CHAR", "TK_REAL",
  "TK_STRING", "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_STRING",
  "TK_TIPO_BOOL", "TK_MAIN", "TK_ID", "TK_TIPO_INT", "TK_FIM", "TK_ERROR",
  "TK_COMP", "TK_LT", "TK_GT", "TK_LTE", "TK_GTE", "TK_DIFF", "TK_OR",
  "TK_AND", "TK_NOT", "TK_XOR", "TK_EQ", "TK_MOD", "TK_TIPO_BOOL_TRUE",
  "TK_TIPO_BOOL_FALSE", "TK_SHIFT_LEFT", "TK_SHIFT_RIGHT", "TK_IF",
  "TK_ELSE", "TK_WHILE", "TK_DO", "TK_FOR", "TK_BREAK", "TK_CONTINUE",
  "TK_PLUS", "TK_SUB", "TK_MULT", "TK_DIV", "'('", "')'", "'{'", "'}'",
  "';'", "$accept", "S", "ESCOPO_GLOBAL", "ESTRUTURA", "FUNC_MAIN",
  "BLOCO", "ESCOPO_INI", "ESCOPO_FIM", "DECLARACOES", "DECLARACAO",
  "DECLARACAOSIMPLES", "DECLARACAOATRIBUICAO", "ATRIBUICAO", "CAST",
  "TIPO", "COMANDOS", "COMANDO", "E", "IF", "ELSE", "WHILE", "WHILE_LABEL",
  "DO", "DO_LABEL", "FOR", "FOR_LABEL", "BREAK", "CONTINUE", "NUMBER",
  "BOOLEANEXP", "BOOLEANTYPE", "LOGICALEXP", "NUMEXP", "CHAREXP",
  "STRINGEXP", YY_NULLPTR
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
     295,   296,   297,    40,    41,   123,   125,    59
};
# endif

#define YYPACT_NINF -162

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-162)))

#define YYTABLE_NINF -42

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -162,     9,   218,  -162,    13,    17,    47,    52,   115,  -162,
    -162,   218,  -162,  -162,  -162,   -13,    -9,    49,    57,    33,
      76,  -162,  -162,    50,  -162,    99,  -162,   109,  -162,   151,
    -162,    61,   164,  -162,  -162,    84,  -162,   135,  -162,   229,
      92,  -162,  -162,    60,  -162,    69,    94,   106,    11,   -17,
    -162,  -162,   222,   112,   125,   247,  -162,  -162,  -162,  -162,
    -162,   129,   265,   165,   165,   165,   165,   165,   165,   165,
     165,  -162,  -162,   109,  -162,  -162,  -162,  -162,   159,  -162,
    -162,  -162,   -11,   137,   193,   159,   159,  -162,   165,   165,
     165,   165,   165,   165,  -162,  -162,    82,  -162,  -162,   165,
    -162,   272,   272,   272,   272,   174,   174,   254,   254,  -162,
      14,  -162,  -162,   143,   143,   272,   272,   272,   272,   272,
     272,  -162,   160,   173,   146,  -162,  -162,  -162,   145,   148,
      11,  -162,   149,  -162,   144,    82,   150,  -162,  -162,   155,
    -162,   112,  -162,   157,  -162,  -162,   143,   222,  -162,   154,
     272,  -162,   131,   159,  -162,  -162,   162,  -162,  -162,  -162,
    -162,  -162,   159,   169,   205,  -162,    85,  -162,  -162,  -162,
     102,    29,   179,    38,   176,   160,   182,   112,   114,   112,
     159,   159,   188,  -162,    56,   -15,    77,  -162,   183,   205,
    -162,  -162,  -162,   192,   112,  -162
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     0,     2,
       5,     0,    11,    13,    14,     0,     0,     0,     0,     0,
       0,     4,    10,     0,    16,     0,    17,     0,    19,     0,
      18,     0,     0,    15,    69,    68,    70,     0,    98,     0,
       0,   101,   102,     0,    68,     0,    79,    80,     0,     0,
      78,    77,     0,     0,    69,     0,    22,    37,    39,    38,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,     0,    28,    74,    79,    80,     0,    75,
      25,    26,     0,    77,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     8,     6,    35,    20,    21,     0,
      88,    95,    94,    96,    97,    90,    91,    92,    93,   100,
       0,    71,    81,    72,    73,    82,    84,    86,    85,    87,
      83,    99,    70,     0,     0,    61,    63,    65,     0,     0,
       0,    43,     0,    55,     0,    35,     0,    45,    46,     0,
      47,     0,    48,     0,    49,    50,    53,    51,    52,    54,
      89,    76,    35,     0,    66,    67,     0,    44,     9,     7,
      40,    42,     0,     0,     0,    32,    68,    70,    33,    30,
      98,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,    56,    60,     0,     0,     0,    57,     0,     0,
      58,    59,    62,     0,     0,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,  -162,   233,  -114,  -162,  -162,  -162,    20,
    -162,  -162,  -161,    93,   116,   113,  -162,    98,    65,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,   103,   -29,
     212,   -46,   -22,  -162,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,    10,    95,    96,   159,    11,   131,
      13,    14,   132,   133,    61,   134,   135,   136,   137,   187,
     138,   139,   140,   141,   142,   143,   144,   145,    38,   146,
      50,    51,    52,   148,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    39,    83,   176,    43,    85,    86,    85,    86,     3,
      55,    85,    86,    23,    34,    62,    44,    25,    57,    82,
      58,    59,    12,    36,    60,    15,    84,   163,   193,    16,
      87,    22,   189,   111,    24,    45,    85,    86,    26,    76,
      77,   101,   102,   103,   104,   105,   106,   107,   108,   110,
     109,    85,    86,    34,    48,    35,   113,   114,   151,    17,
      85,    86,    36,   182,    18,   183,   115,   116,   117,   118,
     119,   120,   190,   177,   147,    27,    31,   150,    85,    86,
     195,    75,   179,    29,    83,    34,   121,    44,    41,     4,
       5,     6,     7,    37,   122,   123,    28,    76,    77,    73,
     188,    82,    32,    40,    30,    53,    45,    74,    84,   124,
      76,    77,    78,   147,   124,    41,   125,   126,   127,   128,
     129,    42,    94,    33,   171,   130,    19,    20,   -41,   -31,
     147,    56,   -31,   173,    34,   165,   166,    41,    34,    72,
      44,    80,    57,   167,    58,    59,   -29,    36,    60,   -29,
     150,   184,   185,    81,    34,    45,    44,    94,   -34,    76,
      77,   -34,    34,    36,    44,    85,    86,    54,    34,    44,
      44,    36,    97,    99,   130,    45,    36,    36,    37,    46,
      47,   112,    34,    45,    44,    20,   152,    76,    77,   153,
     158,   178,   154,    73,    48,   155,   157,   161,   162,    63,
     164,    64,    48,   174,    65,    66,   172,    37,    37,    88,
      89,    90,    91,    92,    93,    69,    70,   175,    63,   180,
      64,   186,    37,    65,    66,     4,     5,     6,     7,   181,
     192,     8,    67,    68,    69,    70,   194,   100,    88,    89,
      90,    91,    92,    93,    21,   168,   156,    63,   160,    64,
     169,   191,    65,    66,    63,   170,    64,    79,     0,    65,
      66,    67,    68,    69,    70,     0,     0,     0,    67,    68,
      69,    70,    63,     0,    64,     0,    71,    65,    66,    63,
       0,    64,     0,     0,    65,    66,    67,    68,    69,    70,
      63,     0,    64,     0,    98,    65,    66,    63,     0,    64,
       0,     0,    65,    66,    67,    68,    69,    70,     0,   100,
       0,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      29,    23,    48,   164,    27,    22,    23,    22,    23,     0,
      32,    22,    23,    26,     3,    37,     5,    26,     7,    48,
       9,    10,     2,    12,    13,    12,    48,   141,   189,    12,
      47,    11,    47,    44,    47,    24,    22,    23,    47,    28,
      29,    63,    64,    65,    66,    67,    68,    69,    70,    78,
      73,    22,    23,     3,    43,     5,    85,    86,    44,    12,
      22,    23,    12,   177,    12,   179,    88,    89,    90,    91,
      92,    93,   186,    44,    96,    26,    43,    99,    22,    23,
     194,    12,    44,    26,   130,     3,     4,     5,     6,     7,
       8,     9,    10,    43,    12,    13,    47,    28,    29,    39,
      44,   130,    26,     4,    47,    44,    24,    47,   130,    32,
      28,    29,    43,   135,    32,     6,    34,    35,    36,    37,
      38,    12,    45,    47,   153,    43,    11,    12,    46,    44,
     152,    47,    47,   162,     3,     4,     5,     6,     3,    47,
       5,    47,     7,    12,     9,    10,    44,    12,    13,    47,
     172,   180,   181,    47,     3,    24,     5,    45,    44,    28,
      29,    47,     3,    12,     5,    22,    23,     3,     3,     5,
       5,    12,    47,    44,    43,    24,    12,    12,    43,    28,
      29,    44,     3,    24,     5,    12,    26,    28,    29,    43,
      46,    12,    47,    39,    43,    47,    47,    47,    43,    25,
      43,    27,    43,    34,    30,    31,    44,    43,    43,    16,
      17,    18,    19,    20,    21,    41,    42,    12,    25,    43,
      27,    33,    43,    30,    31,     7,     8,     9,    10,    47,
      47,    13,    39,    40,    41,    42,    44,    44,    16,    17,
      18,    19,    20,    21,    11,   152,   130,    25,   135,    27,
     152,   186,    30,    31,    25,   152,    27,    45,    -1,    30,
      31,    39,    40,    41,    42,    -1,    -1,    -1,    39,    40,
      41,    42,    25,    -1,    27,    -1,    47,    30,    31,    25,
      -1,    27,    -1,    -1,    30,    31,    39,    40,    41,    42,
      25,    -1,    27,    -1,    47,    30,    31,    25,    -1,    27,
      -1,    -1,    30,    31,    39,    40,    41,    42,    -1,    44,
      -1,    39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     7,     8,     9,    10,    13,    51,
      52,    56,    57,    58,    59,    12,    12,    12,    12,    11,
      12,    52,    57,    26,    47,    26,    47,    26,    47,    26,
      47,    43,    26,    47,     3,     5,    12,    43,    76,    80,
       4,     6,    12,    82,     5,    24,    28,    29,    43,    77,
      78,    79,    80,    44,     3,    80,    47,     7,     9,    10,
      13,    62,    80,    25,    27,    30,    31,    39,    40,    41,
      42,    47,    47,    39,    47,    12,    28,    29,    43,    78,
      47,    47,    77,    79,    80,    22,    23,    47,    16,    17,
      18,    19,    20,    21,    45,    53,    54,    47,    47,    44,
      44,    80,    80,    80,    80,    80,    80,    80,    80,    82,
      77,    44,    44,    77,    77,    80,    80,    80,    80,    80,
      80,     4,    12,    13,    32,    34,    35,    36,    37,    38,
      43,    57,    60,    61,    63,    64,    65,    66,    68,    69,
      70,    71,    72,    73,    74,    75,    77,    80,    81,    82,
      80,    44,    26,    43,    47,    47,    62,    47,    46,    55,
      63,    47,    43,    53,    43,     4,     5,    12,    61,    65,
      76,    77,    44,    77,    34,    12,    60,    44,    12,    44,
      43,    47,    53,    53,    77,    77,    33,    67,    44,    47,
      53,    66,    47,    60,    44,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    53,    54,    55,
      56,    56,    56,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    61,    61,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    65,    65,    65,    66,    66,    67,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     5,     3,     1,     1,
       2,     1,     0,     1,     1,     3,     3,     3,     3,     3,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     3,
       3,     3,     3,     3,     4,     0,     1,     1,     1,     1,
       2,     0,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     6,     2,     2,
       5,     1,     7,     1,     9,     1,     2,     2,     1,     1,
       1,     3,     3,     3,     2,     2,     4,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     1,     1
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
#line 85 "sintatica.y" /* yacc.c:1646  */
    {
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n";
				cout << (yyvsp[0]).traducao;
			}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 91 "sintatica.y" /* yacc.c:1646  */
    {
					abrirEscopo();
					(yyval).traducao = "";
				}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 98 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + "\n" + (yyvsp[0]).traducao;
			}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "int main(void)\n{\n" + (yyvsp[0]).traducao + "\treturn 0;\n}\n"; 
			}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 119 "sintatica.y" /* yacc.c:1646  */
    {
				abrirEscopo();
				(yyval).traducao = "";
			}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 126 "sintatica.y" /* yacc.c:1646  */
    {
				fecharEscopo();
				(yyval).traducao = "";
			}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 137 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 141 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 157 "sintatica.y" /* yacc.c:1646  */
    {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-1]).label) == false){
				  			(*mapa)[(yyvsp[-1]).label].label = createvar();
				  			(*mapa)[(yyvsp[-1]).label].tipo = "int"; 
				  		} 
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-1]).label + "' no escopo.");
				  		}

				  		(yyval).tipo = (*mapa)[(yyvsp[-1]).label].tipo;
						(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;

						(yyval).label =  (yyvsp[-1]).label;
						(yyval).traducao = "\tint " + (yyval).label + ";\n";
				  }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 174 "sintatica.y" /* yacc.c:1646  */
    {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-1]).label) == false){
				  			(*mapa)[(yyvsp[-1]).label].label = createvar();
				  			(*mapa)[(yyvsp[-1]).label].tipo = "int"; 
				  		} 
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-1]).label + "' no escopo.");
				  		}

				  		(yyval).tipo = (*mapa)[(yyvsp[-1]).label].tipo;
						(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;

						(yyval).label =  (yyvsp[-1]).label;
						(yyval).traducao = "\tfloat " + (yyval).label + ";\n";
				  }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 191 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-1]).label) == false){
				  			(*mapa)[(yyvsp[-1]).label].label = createvar();
				  			(*mapa)[(yyvsp[-1]).label].tipo = "char"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-1]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-1]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-1]).label].tipo;
					 	(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;
						(yyval).traducao = "\tchar " + (yyval).label + ";\n";
				  }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 207 "sintatica.y" /* yacc.c:1646  */
    {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-1]).label) == false){
				  			(*mapa)[(yyvsp[-1]).label].label = createvar();
				  			(*mapa)[(yyvsp[-1]).label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-1]).label + "' no escopo.");
				  		}

				  		(yyval).tipo = (*mapa)[(yyvsp[-1]).label].tipo;
						(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;

						(yyval).label =  (yyvsp[-1]).label;
						(yyval).traducao = "\tint " + (yyval).label + ";\n";
				  }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 224 "sintatica.y" /* yacc.c:1646  */
    {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-1]).label) == false){
				  			(*mapa)[(yyvsp[-1]).label].label = createvar();
				  			(*mapa)[(yyvsp[-1]).label].tipo = "string"; 
				  			(*mapa)[(yyvsp[-1]).label].stringDinamica = true; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-1]).label + "' no escopo.");
				  		}

				  		(yyval).tipo = (*mapa)[(yyvsp[-1]).label].tipo;
						(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;

						(yyval).label =  (yyvsp[-1]).label;
						(yyval).traducao = "\tchar[] " + (yyval).label + ";\n";
				  }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 244 "sintatica.y" /* yacc.c:1646  */
    {
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-3]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tint " + (yyval).label + " = " + (yyvsp[-1]).traducao + ";\n";
					 }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 260 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-3]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;

					 	(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
					 }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 278 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "float"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-3]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tfloat " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
					 }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 294 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "float"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-3]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = (yyvsp[-1]).traducao + "\tfloat " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
					 }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 310 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "char"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-3]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tchar " + (yyval).label + " = '" + (yyvsp[-1]).traducao + "';\n";
					 }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 326 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-3]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tint " + (yyval).label + " = 1;\n";
					 }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 343 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-3]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tint " + (yyval).label + " = 0;\n";
					 }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 360 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-3]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
					 }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 377 "sintatica.y" /* yacc.c:1646  */
    {
				 		(yyval).label = createvar();
				 		int tamanho = (yyvsp[-1]).tamanhoString;

				 		map<string,atributos>* mapa = escopo.front();

				  		if(varNoEscopoAtual((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "string"; 
				  			(*mapa)[(yyvsp[-3]).label].tamanhoString = tamanho;
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + (yyvsp[-3]).label + "' no escopo.");
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tamanhoString = (*mapa)[(yyvsp[-3]).label].tamanhoString;

					 	(yyval).traducao = (yyvsp[-1]).traducao + "\tchar " + (yyval).label + "[" + to_string(tamanho) + "];\n\t" + "strncpy(" +
					 	(yyval).label + "," + (yyvsp[-1]).label + "," + to_string(tamanho) + ");\n";
					 }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 403 "sintatica.y" /* yacc.c:1646  */
    {
			 	//Verificando se a variavel existe no escopo corrente
				(yyval).label = createvar();

		  		if(varNoEscopo((yyvsp[-2]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[-2]).label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo((yyvsp[-2]).label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, (yyvsp[0]).tipo, "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != (yyvsp[0]).tipo && cast.resultado == "")
		  			yyerror("Variavel '" + (yyvsp[-2]).label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo " + (yyvsp[0]).tipo);

		  		if(cast.resultado != varDeclarada->tipo)
		 			tipoAtual = cast.resultado;

		  		(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + varDeclarada->label + " = (" + tipoAtual + ")" + (yyvsp[0]).label + ";\n";
			 }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 425 "sintatica.y" /* yacc.c:1646  */
    {
				//Verificando se a variavel existe no escopo corrente
				(yyval).label = createvar();
				bool castImplicito = false;

		  		if(varNoEscopo((yyvsp[-2]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[-2]).label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo((yyvsp[-2]).label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, (yyvsp[0]).tipo, "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != (yyvsp[0]).tipo && cast.resultado == "")
		  			yyerror("Variavel '" + (yyvsp[-2]).label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo " + (yyvsp[0]).tipo);
			 	
			 	if(cast.resultado != varDeclarada->tipo && varDeclarada->tipo != "string")
			 	{
		 			tipoAtual = cast.resultado;
		 			castImplicito = true;
			 	}
			 	
			 	if(castImplicito)
			 	{
			 		(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + varDeclarada->label + " = (" + tipoAtual + ") " + (yyvsp[0]).label + ";\n";
			 	}
			 	else
			 	{
		 			(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + varDeclarada->label + " = " + (yyvsp[0]).label + ";\n";
			 	}
			}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 458 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();

		  		if(varNoEscopo((yyvsp[-2]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[-2]).label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo((yyvsp[-2]).label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, "float", "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "float" && cast.resultado == "")
		  			yyerror("Variavel '" + (yyvsp[-2]).label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo float");
			 	
			 	if(cast.resultado != varDeclarada->tipo)
		 			tipoAtual = cast.resultado;

			 	(yyval).traducao = (yyvsp[-2]).traducao + " = (" + tipoAtual + ")" + (yyvsp[0]).traducao + ";\n";
			}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 479 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();

		  		if(varNoEscopo((yyvsp[-2]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[-2]).label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo((yyvsp[-2]).label);

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "char")
		  			yyerror("Variavel '" + (yyvsp[-2]).label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo char");

			 	(yyval).traducao = (yyvsp[-2]).traducao + " = '" + (yyvsp[0]).traducao + "';\n";
			}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 497 "sintatica.y" /* yacc.c:1646  */
    {
				string nome_variavel_temporaria_cast;
				string chave = gera_chave((yyvsp[-2]).traducao, (yyvsp[0]).tipo, "=");
				if (mapa_cast.find(chave) != mapa_cast.end()) {
					tipo_cast cast = mapa_cast[chave];
					nome_variavel_temporaria_cast = createvar();
					(yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + nome_variavel_temporaria_cast + " = " + "(" + cast.resultado + ") " + (yyvsp[0]).label + ";";
					(yyval).tipo = cast.resultado;
					(yyval).tamanho = (yyvsp[0]).tamanho;
					(yyval).label = nome_variavel_temporaria_cast;
				}
			}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 510 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 516 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "int";
			}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 522 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "float";
			}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 528 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "boolean";
			}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 534 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "char";
			}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 541 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 545 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 562 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 566 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;	
			}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 570 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 574 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 578 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 584 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyvsp[0]).isFunction = false;
				//Se condição for false, usar goto para pular o bloco inteiro de $5
			    (yyval).traducao = (yyvsp[-2]).traducao + "\n\tif (" + (yyvsp[-2]).label +") goto " + (yyval).blocoFim + ";\n" 
			    + (yyvsp[0]).traducao + "\t" + (yyval).blocoFim + ":\n";
			}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 594 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyvsp[-1]).isFunction = false;
			    (yyval).traducao = "\n" + (yyvsp[-3]).traducao + 
					 "\n\t" + "if(" + (yyvsp[-3]).label + ") goto " + (yyvsp[0]).blocoIni + ";\n" + 
					 (yyvsp[-1]).traducao + 
					 "\tgoto " + (yyvsp[0]).blocoFim +";\n" +
					 (yyvsp[0]).traducao + 
					 "\n\t" + (yyvsp[0]).blocoFim + ":\n";	
			}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 609 "sintatica.y" /* yacc.c:1646  */
    {
				(yyvsp[0]).isFunction = false;	
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyval).traducao = "\n\t" + (yyval).blocoIni + ":\n" + (yyvsp[0]).traducao;
			}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 617 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				
				(yyval).traducao = "\n\t" + (yyval).blocoIni + ":\n" +
							  (yyvsp[0]).traducao;
			}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 628 "sintatica.y" /* yacc.c:1646  */
    {
				(yyvsp[0]).isFunction = false;
				atributos* att = estruturasDeRepeticao.front();
				(yyval).jump = att->jump;
				(yyval).blocoIni = att->blocoIni;
				(yyval).blocoFim = att->blocoFim;
			    (yyval).traducao = (yyvsp[-2]).traducao + "\n\t" + (yyval).blocoIni + ":\n\tif (" + (yyvsp[-2]).label +") goto " + (yyval).blocoFim + ";\n" 
			    + (yyvsp[0]).traducao + "\n\tgoto " + (yyval).blocoIni + ";\n\t" + (yyval).blocoFim + ":\n";

			    estruturasDeRepeticao.pop_front();
			}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 642 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "while";
				estruturasDeRepeticao.push_front(att);
			}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 653 "sintatica.y" /* yacc.c:1646  */
    {
				(yyvsp[-5]).isFunction = false;
				atributos* att = estruturasDeRepeticao.front();
				(yyval).jump = att->jump;
				(yyval).blocoIni = att->blocoIni;
				(yyval).blocoFim = att->blocoFim;
			    (yyval).traducao = "\n\t" + (yyval).blocoIni + "\n" + (yyvsp[-2]).traducao + (yyvsp[-5]).traducao + "\n\tif (" + (yyvsp[-2]).label + ")" +
			    "goto " + (yyval).blocoFim + ";" + 	"\n\t" + "goto " + (yyval).blocoIni + ";" + "\n\t" + (yyval).blocoFim + ":\n";
			    estruturasDeRepeticao.pop_front();
			}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 666 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "do";
				estruturasDeRepeticao.push_front(att);
			}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 677 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = estruturasDeRepeticao.front();
				(yyval).jump = att->jump;
				(yyval).blocoIni = att->blocoIni;
				(yyval).blocoFim = att->blocoFim;
				(yyval).traducao = (yyvsp[-6]).traducao + "\n\t" + (yyval).blocoIni + ":\n\t" + (yyvsp[-4]).traducao + 
				"\n\tif(" + (yyvsp[-4]).label + ") goto " + (yyval).blocoFim + ";\n\t" + (yyvsp[0]).traducao + "\n\n" + (yyvsp[-2]).traducao + 
				"\tgoto " + (yyval).blocoIni + ";\n\t" + (yyval).blocoFim + ":\n";

				estruturasDeRepeticao.pop_front();
			}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 691 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "for";
				estruturasDeRepeticao.push_front(att);
			}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 702 "sintatica.y" /* yacc.c:1646  */
    {
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'break' fora de blocos 'for', 'while' e 'do/while'.");

				atributos * att = estruturasDeRepeticao.front();
				(yyval).traducao = "\n\tgoto " + att->blocoFim + ";\n";
			}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 712 "sintatica.y" /* yacc.c:1646  */
    {
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'continue' fora de blocos 'for', 'while' e 'do/while'.");

				atributos * att = estruturasDeRepeticao.front();
				(yyval).traducao = "\n\tgoto " + att->blocoIni + ";\n";
			}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 722 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).traducao = "\tfloat "+ (yyval).label+ " = " + (yyvsp[0]).traducao + ";\n";
				(yyval).tipo = "float";
			}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 728 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).traducao = "\tint "+ (yyval).label+ " = " + (yyvsp[0]).traducao + ";\n";
				(yyval).tipo = "int";
			}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 734 "sintatica.y" /* yacc.c:1646  */
    {
				//Verificando se a variavel existe no escopo corrente
				(yyval).label = createvar();
				atributos* variavel = getVarNoEscopo((yyvsp[0]).label);

		  		if(varNoEscopo((yyvsp[0]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[0]).label + "' não declarada no bloco.");

		  		(yyval).traducao = "\t" + variavel->tipo + " " + (yyval).label + " = " + variavel->label + ";\n";
		  		(yyval).tipo = variavel->tipo;
			}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 748 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
			}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 754 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " || " + (yyvsp[0]).label + ";\n";
			}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 760 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " && " + (yyvsp[0]).label + ";\n";
			}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 766 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = "\tint " + (yyval).label + " = " + (yyvsp[-1]).traducao + " == 0;\n";
			}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 772 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[0]).label + " == 0;\n";
			}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 778 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + " == 0;\n";
			}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 784 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[0]).label + ";\n";
			}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 790 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 798 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = "\tint "+ (yyval).label+ " = 1;\n";
			}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 804 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = "\tint "+ (yyval).label+ " = 0;\n";
			}
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 812 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
			}
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 818 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " == " + (yyvsp[0]).label + ";\n";
			}
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 824 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " != " + (yyvsp[0]).label + ";\n";
			}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 830 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " < " + (yyvsp[0]).label + ";\n";
			}
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 836 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " <= " + (yyvsp[0]).label + ";\n";
			}
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 842 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " > " + (yyvsp[0]).label + ";\n";
			}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 848 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " >= " + (yyvsp[0]).label + ";\n";
			}
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 857 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = (yyvsp[-1]).tipo;
				(yyval).traducao = (yyvsp[-1]).traducao + "\t" + (yyvsp[-1]).tipo + " " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
			}
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 863 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = (yyvsp[-2]).tipo;
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[0]).label + ";\n";
			}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 869 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "+")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = "+(yyvsp[-2]).label+" + "+(yyvsp[0]).label+";\n";
			}
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 876 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "-")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label+" = "+(yyvsp[-2]).label+" - "+(yyvsp[0]).label+";\n";
			}
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 883 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "*")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label+" = "+(yyvsp[-2]).label+" * "+(yyvsp[0]).label+";\n";
			}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 890 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "/")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = "+(yyvsp[-2]).label+" / "+(yyvsp[0]).label+";\n";
			}
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 897 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "%")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label+" = "+(yyvsp[-2]).label+" % "+(yyvsp[0]).label+";\n";
			}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 904 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "^")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[-2]).label + " ^ " + (yyvsp[0]).label + ";\n";
			}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 911 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "<<")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[-2]).label + " << " + (yyvsp[0]).label + ";\n";
			}
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 918 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, ">>")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[-2]).label + " >> " + (yyvsp[0]).label + ";\n";
			}
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 925 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 933 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "char";
				(yyval).traducao = "\t"+ (yyval).label+ " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 941 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "string";
				int tamanho = (yyvsp[-2]).tamanhoString + (yyvsp[0]).tamanhoString;
				(yyval).tamanhoString = tamanho;
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\tchar " + (yyval).label + "[" + to_string(tamanho) + "];\n" + 
				"\tstrncpy(" + (yyval).label + "," + (yyvsp[-2]).label + "," + to_string((yyvsp[-2]).tamanhoString) + ");\n" +
				"\tstrncpy(" + (yyval).label + " + " + to_string((yyvsp[-2]).tamanhoString + 1) + "," + (yyvsp[0]).label + "," + to_string((yyvsp[0]).tamanhoString) + ");\n";
			}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 951 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "string";
				int tamanho = (yyvsp[0]).traducao.size() - 1;
				(yyval).tamanhoString = tamanho;
				(yyval).traducao = "\n\tchar " + (yyval).label + "[" + to_string(tamanho) + "];\n" + 
				"\tstrncpy(" + (yyval).label + "," + (yyvsp[0]).traducao + "," + to_string(tamanho) + ");\n";
			}
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 960 "sintatica.y" /* yacc.c:1646  */
    {
				//Verificando se a variavel existe no escopo corrente
				(yyval).label = createvar();
				atributos* variavel = getVarNoEscopo((yyvsp[0]).label);

		  		if(varNoEscopo((yyvsp[0]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[0]).label + "' não declarada no bloco.");

		  		(yyval).traducao = "\n\tchar " + (yyval).label + "[" + to_string(variavel->tamanhoString) + "];" +  
		  		"\n\tstrncpy(" + (yyval).label + "," + variavel->label + "," + to_string(variavel->tamanhoString) + ");\n";

		  		(yyval).tipo = variavel->tipo;
		  		(yyval).tamanhoString = variavel->tamanhoString;
			}
#line 2676 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2680 "y.tab.c" /* yacc.c:1646  */
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
#line 976 "sintatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	gera_mapa_cast();
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}			

string createvar(){
	stringstream a;
	contador = contador + 1;
	a << "temp" << contador;
	return a.str();
}

void gera_mapa_cast() {
	std::fstream file("mapa_cast.txt", std::ios_base::in);
	string operador1, operador2, operacao, resultado;
	int operando_cast;

	while(file >> operador1 >> operacao >> operador2 >> resultado >> operando_cast) {
		tipo_cast cast = {resultado, operando_cast};
		mapa_cast[gera_chave(operador1, operador2, operacao)] = cast;
	}
}

string gera_chave(string operador1, string operador2, string operacao) {
	return operador1 + "_" + operacao + "_" + operador2;
}

tipo_cast cast_possivel(string tipo1, string tipo2, string operador){
	return mapa_cast[gera_chave(tipo1, tipo2, operador)];
}

void abrirEscopo(){
	map<string,atributos> *novoEscopo = new map<string,atributos>;
	escopo.push_front(novoEscopo);
}

void fecharEscopo(){
	escopo.pop_front();
}

bool varNoEscopo(string varName){
	for (std::list< map<string,atributos>* >::iterator it=escopo.begin(); it!=escopo.end(); it++)
    {
    	map<string,atributos>* m = *it;

    	if((*m).find(varName) != (*m).end())
    		return true;
    }

	return false;
}

bool varNoEscopoAtual(string varName){
	map<string,atributos>* m = escopo.front();

	return (*m).find(varName) != (*m).end();
}

atributos* getVarNoEscopo(string varName){
	for (std::list< map<string,atributos>* >::iterator it=escopo.begin(); it!=escopo.end(); it++)
    {
    	map<string,atributos>* m = *it;

    	if((*m).find(varName) != (*m).end())
    		return &(*m)[varName];
    }

	return NULL;
}

string gerarBloco()
{
	stringstream label;
	label << "Bloco" << numBloco++;
	
	return label.str();
}
string gerarInicioDeBloco(string l)
{
	stringstream label;
	label << "blocoIni" << l;
	
	return label.str();
}
string gerarFimDeBloco(string l)
{
	stringstream label;
	label << "blocoFim" << l;
	
	return label.str();
}

template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
