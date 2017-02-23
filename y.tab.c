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
    TK_BREAK_ALL = 293,
    TK_CONTINUE = 294,
    TK_ELIF = 295,
    TK_MAIS_MAIS = 296,
    TK_MENOS_MENOS = 297,
    TK_MAIS_COMPOSTO = 298,
    TK_MENOS_COMPOSTO = 299,
    TK_MULT_COMPOSTO = 300,
    TK_DIV_COMPOSTO = 301,
    TK_PLUS = 302,
    TK_SUB = 303,
    TK_MULT = 304,
    TK_DIV = 305
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
#define TK_BREAK_ALL 293
#define TK_CONTINUE 294
#define TK_ELIF 295
#define TK_MAIS_MAIS 296
#define TK_MENOS_MENOS 297
#define TK_MAIS_COMPOSTO 298
#define TK_MENOS_COMPOSTO 299
#define TK_MULT_COMPOSTO 300
#define TK_DIV_COMPOSTO 301
#define TK_PLUS 302
#define TK_SUB 303
#define TK_MULT 304
#define TK_DIV 305

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

#line 277 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      51,    52,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    92,    98,   102,   108,   114,   119,   126,
     133,   137,   142,   147,   151,   157,   174,   191,   207,   224,
     244,   260,   278,   294,   310,   326,   343,   360,   377,   403,
     425,   458,   479,   494,   530,   566,   602,   638,   641,   655,
     660,   666,   672,   678,   685,   690,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   707,   711,   715,   719,
     723,   729,   739,   754,   755,   758,   767,   777,   785,   796,
     810,   821,   834,   845,   859,   870,   880,   890,   900,   906,
     912,   926,   932,   938,   944,   950,   956,   962,   968,   976,
     982,   990,   996,  1002,  1008,  1014,  1020,  1026,  1035,  1041,
    1047,  1054,  1061,  1068,  1075,  1082,  1089,  1096,  1103,  1130,
    1157,  1182,  1207,  1215,  1223,  1233,  1242
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
  "TK_ELSE", "TK_WHILE", "TK_DO", "TK_FOR", "TK_BREAK", "TK_BREAK_ALL",
  "TK_CONTINUE", "TK_ELIF", "TK_MAIS_MAIS", "TK_MENOS_MENOS",
  "TK_MAIS_COMPOSTO", "TK_MENOS_COMPOSTO", "TK_MULT_COMPOSTO",
  "TK_DIV_COMPOSTO", "TK_PLUS", "TK_SUB", "TK_MULT", "TK_DIV", "'('",
  "')'", "'{'", "'}'", "';'", "$accept", "S", "ESCOPO_GLOBAL", "ESTRUTURA",
  "FUNC_MAIN", "BLOCO", "ESCOPO_INI", "ESCOPO_FIM", "DECLARACOES",
  "DECLARACAO", "DECLARACAOSIMPLES", "DECLARACAOATRIBUICAO", "ATRIBUICAO",
  "CAST", "TIPO", "COMANDOS", "COMANDO", "E", "IF", "ELSES", "ELIF",
  "ELSE", "WHILE", "WHILE_LABEL", "DO", "DO_LABEL", "FOR", "FOR_LABEL",
  "BREAK", "BREAKALL", "CONTINUE", "NUMBER", "BOOLEANEXP", "BOOLEANTYPE",
  "LOGICALEXP", "NUMEXP", "CHAREXP", "STRINGEXP", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    40,    41,   123,   125,    59
};
# endif

#define YYPACT_NINF -164

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -164,     8,   198,  -164,    11,    24,    48,    55,    15,  -164,
    -164,   198,  -164,  -164,  -164,   -21,     3,    31,    38,    20,
      52,  -164,  -164,    82,  -164,    80,  -164,    18,  -164,   209,
    -164,    62,   140,  -164,  -164,    35,   130,    92,   114,    28,
    -164,   280,    95,  -164,  -164,   110,  -164,    -9,    99,   109,
     146,   -16,  -164,  -164,   273,    84,   111,   306,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,   137,   315,   223,
     223,   223,   223,   223,   223,   223,   223,  -164,  -164,    18,
    -164,  -164,  -164,  -164,   217,  -164,  -164,  -164,    -7,   144,
     236,   217,   217,  -164,   223,   223,   223,   223,   223,   223,
    -164,  -164,    93,  -164,  -164,   223,  -164,   341,   341,   341,
     341,   348,   348,   355,   355,  -164,    43,  -164,  -164,   162,
     162,   341,   341,   341,   341,   341,   341,  -164,   271,   192,
     148,  -164,  -164,  -164,   145,   164,   168,   146,  -164,   169,
    -164,   173,    93,   177,  -164,  -164,   191,  -164,    84,  -164,
     193,  -164,  -164,  -164,   162,   273,  -164,   202,   341,  -164,
     174,   189,   189,   189,   189,   217,  -164,  -164,  -164,   210,
    -164,  -164,  -164,  -164,  -164,   217,   235,   258,  -164,    36,
     130,  -164,  -164,    61,  -164,  -164,  -164,  -164,    96,   231,
     138,   220,    66,   221,    84,   121,    84,   217,   217,    -8,
    -164,   187,   -11,   -10,   224,  -164,  -164,  -164,   226,   258,
    -164,  -164,   217,  -164,   227,   225,    84,    84,  -164,    -8,
    -164
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     0,     2,
       5,     0,    11,    13,    14,     0,     0,     0,     0,     0,
       0,     4,    10,     0,    16,     0,    17,     0,    19,     0,
      18,     0,     0,    15,    79,    78,    80,     0,     0,     0,
     112,     0,     0,   115,   116,     0,    78,     0,    89,    90,
       0,     0,    88,    87,     0,     0,    79,     0,    22,   108,
     109,   110,   111,    41,    43,    42,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,     0,
      28,    84,    89,    90,     0,    85,    25,    26,     0,    87,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       8,     6,    39,    20,    21,     0,    98,   105,   104,   106,
     107,   100,   101,   102,   103,   114,     0,    81,    91,    82,
      83,    92,    94,    96,    95,    97,    93,   113,    80,     0,
       0,    70,    72,    74,     0,     0,     0,     0,    47,     0,
      60,     0,    39,     0,    49,    50,     0,    51,     0,    52,
       0,    53,    54,    55,    58,    56,    57,    59,    99,    86,
      39,    39,    39,    39,    39,     0,    75,    76,    77,     0,
      48,     9,     7,    44,    46,     0,     0,     0,    32,    78,
      80,    37,    30,   112,    33,    34,    35,    36,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,    61,
      69,     0,     0,     0,     0,    62,    64,    63,     0,     0,
      67,    68,     0,    71,     0,     0,     0,     0,    73,    65,
      66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,  -164,   267,  -135,  -164,  -164,  -164,     7,
    -164,  -164,  -163,   120,   150,   153,  -164,   188,    98,    77,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,   139,   -29,   255,   -48,   -22,  -164,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,    10,   101,   102,   172,    11,   138,
      13,    14,   139,   140,    67,   141,   142,   143,   144,   205,
     206,   207,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    40,   154,    52,    53,    54,   156,   157
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    41,    89,    81,    45,    23,    91,    92,     3,    12,
      57,    91,    92,   176,   193,    91,    92,    68,    22,    82,
      83,    88,   130,    15,    43,   203,    19,    20,    90,    25,
      44,    34,   204,    46,    24,    63,    16,    64,    65,    93,
      36,    66,    84,   100,   209,   117,   214,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   115,    27,    26,   199,
      17,   200,   119,   120,    29,    91,    92,    18,   210,    37,
      38,    31,   121,   122,   123,   124,   125,   126,    32,    39,
     155,   218,   219,   158,    42,    34,    28,    35,   -31,    89,
      58,   -31,   160,    30,    36,   159,    34,   127,    46,    43,
       4,     5,     6,     7,    61,   128,   129,    33,    88,   161,
     162,   163,   164,   -29,    55,    90,   -29,    47,    91,    92,
     155,    82,    83,    37,    38,   130,    62,   131,   132,   133,
     134,   135,   136,    39,    37,    38,   188,   100,   155,   155,
     155,   155,   155,    56,   137,    46,   190,   -45,   194,    34,
      78,    46,    36,    63,    86,    64,    65,    79,    36,    66,
      91,    92,    59,    60,    87,    80,   103,   158,   201,   202,
      47,    59,    60,   -38,    82,    83,   -38,    34,   178,   179,
      43,    37,    38,   215,    91,    92,   180,    37,    38,   105,
     196,    39,    34,   127,    46,    43,   118,    50,    47,   165,
     166,   180,    82,    83,    20,     4,     5,     6,     7,    91,
      92,     8,    34,    47,    46,    37,    38,    82,    83,   167,
      34,    36,    46,   168,   170,   137,    34,   171,    46,    36,
      37,    38,   174,    47,    34,    36,    46,    48,    49,   208,
     137,    47,   175,   195,   177,    82,    83,    91,    92,    79,
      37,    38,    94,    95,    96,    97,    98,    99,    37,    38,
      50,    69,   189,    70,    37,    38,    71,    72,    50,   191,
     192,   197,    37,    38,    39,   212,   198,   217,    21,   216,
     181,   213,    39,    73,    74,    75,    76,   169,   106,    94,
      95,    96,    97,    98,    99,   173,   220,   160,    69,   183,
      70,   211,    85,    71,    72,    69,     0,    70,     0,     0,
      71,    72,    59,    60,   161,   162,   163,   164,     0,     0,
      73,    74,    75,    76,     0,     0,     0,    73,    74,    75,
      76,    69,     0,    70,     0,    77,    71,    72,     0,     0,
      69,     0,    70,     0,     0,    71,    72,     0,   182,   184,
     185,   186,   187,    73,    74,    75,    76,     0,     0,     0,
       0,   104,    73,    74,    75,    76,    69,   106,    70,     0,
       0,    71,    72,    69,     0,    70,     0,     0,    71,    72,
      69,     0,    70,     0,     0,    71,    72,     0,    73,    74,
      75,    76,     0,     0,     0,     0,     0,    75,    76
};

static const yytype_int16 yycheck[] =
{
      29,    23,    50,    12,    27,    26,    22,    23,     0,     2,
      32,    22,    23,   148,   177,    22,    23,    39,    11,    28,
      29,    50,    32,    12,     6,    33,    11,    12,    50,    26,
      12,     3,    40,     5,    55,     7,    12,     9,    10,    55,
      12,    13,    51,    53,    55,    52,   209,    69,    70,    71,
      72,    73,    74,    75,    76,    84,    79,    26,    55,   194,
      12,   196,    91,    92,    26,    22,    23,    12,   203,    41,
      42,    51,    94,    95,    96,    97,    98,    99,    26,    51,
     102,   216,   217,   105,     4,     3,    55,     5,    52,   137,
      55,    55,    26,    55,    12,    52,     3,     4,     5,     6,
       7,     8,     9,    10,    12,    12,    13,    55,   137,    43,
      44,    45,    46,    52,    52,   137,    55,    24,    22,    23,
     142,    28,    29,    41,    42,    32,    12,    34,    35,    36,
      37,    38,    39,    51,    41,    42,   165,    53,   160,   161,
     162,   163,   164,     3,    51,     5,   175,    54,    52,     3,
      55,     5,    12,     7,    55,     9,    10,    47,    12,    13,
      22,    23,    41,    42,    55,    55,    55,   189,   197,   198,
      24,    41,    42,    52,    28,    29,    55,     3,     4,     5,
       6,    41,    42,   212,    22,    23,    12,    41,    42,    52,
      52,    51,     3,     4,     5,     6,    52,    51,    24,    51,
      55,    12,    28,    29,    12,     7,     8,     9,    10,    22,
      23,    13,     3,    24,     5,    41,    42,    28,    29,    55,
       3,    12,     5,    55,    55,    51,     3,    54,     5,    12,
      41,    42,    55,    24,     3,    12,     5,    28,    29,    52,
      51,    24,    51,    12,    51,    28,    29,    22,    23,    47,
      41,    42,    16,    17,    18,    19,    20,    21,    41,    42,
      51,    25,    52,    27,    41,    42,    30,    31,    51,    34,
      12,    51,    41,    42,    51,    51,    55,    52,    11,    52,
     160,    55,    51,    47,    48,    49,    50,   137,    52,    16,
      17,    18,    19,    20,    21,   142,   219,    26,    25,   160,
      27,   203,    47,    30,    31,    25,    -1,    27,    -1,    -1,
      30,    31,    41,    42,    43,    44,    45,    46,    -1,    -1,
      47,    48,    49,    50,    -1,    -1,    -1,    47,    48,    49,
      50,    25,    -1,    27,    -1,    55,    30,    31,    -1,    -1,
      25,    -1,    27,    -1,    -1,    30,    31,    -1,   160,   161,
     162,   163,   164,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    47,    48,    49,    50,    25,    52,    27,    -1,
      -1,    30,    31,    25,    -1,    27,    -1,    -1,    30,    31,
      25,    -1,    27,    -1,    -1,    30,    31,    -1,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,     7,     8,     9,    10,    13,    59,
      60,    64,    65,    66,    67,    12,    12,    12,    12,    11,
      12,    60,    65,    26,    55,    26,    55,    26,    55,    26,
      55,    51,    26,    55,     3,     5,    12,    41,    42,    51,
      87,    91,     4,     6,    12,    93,     5,    24,    28,    29,
      51,    88,    89,    90,    91,    52,     3,    91,    55,    41,
      42,    12,    12,     7,     9,    10,    13,    70,    91,    25,
      27,    30,    31,    47,    48,    49,    50,    55,    55,    47,
      55,    12,    28,    29,    51,    89,    55,    55,    88,    90,
      91,    22,    23,    55,    16,    17,    18,    19,    20,    21,
      53,    61,    62,    55,    55,    52,    52,    91,    91,    91,
      91,    91,    91,    91,    91,    93,    88,    52,    52,    88,
      88,    91,    91,    91,    91,    91,    91,     4,    12,    13,
      32,    34,    35,    36,    37,    38,    39,    51,    65,    68,
      69,    71,    72,    73,    74,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    88,    91,    92,    93,    91,    52,
      26,    43,    44,    45,    46,    51,    55,    55,    55,    70,
      55,    54,    63,    71,    55,    51,    61,    51,     4,     5,
      12,    69,    73,    87,    73,    73,    73,    73,    88,    52,
      88,    34,    12,    68,    52,    12,    52,    51,    55,    61,
      61,    88,    88,    33,    40,    75,    76,    77,    52,    55,
      61,    74,    51,    55,    68,    88,    52,    52,    61,    61,
      75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    59,    59,    60,    61,    62,    63,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     5,     3,     1,     1,
       2,     1,     0,     1,     1,     3,     3,     3,     3,     3,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     0,
       1,     1,     1,     1,     2,     0,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     6,     1,     1,     5,     6,     2,     2,     5,
       1,     7,     1,     9,     1,     2,     2,     2,     1,     1,
       1,     3,     3,     3,     2,     2,     4,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     1,     1,     3,     1,     1
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
#line 86 "sintatica.y" /* yacc.c:1646  */
    {
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n";
				cout << (yyvsp[0]).traducao;
			}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 92 "sintatica.y" /* yacc.c:1646  */
    {
					abrirEscopo();
					(yyval).traducao = "";
				}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 99 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + "\n" + (yyvsp[0]).traducao;
			}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 103 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 109 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "int main(void)\n{\n" + (yyvsp[0]).traducao + "\treturn 0;\n}\n"; 
			}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 120 "sintatica.y" /* yacc.c:1646  */
    {
				abrirEscopo();
				(yyval).traducao = "";
			}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "sintatica.y" /* yacc.c:1646  */
    {
				fecharEscopo();
				(yyval).traducao = "";
			}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 138 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 142 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 148 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 152 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 158 "sintatica.y" /* yacc.c:1646  */
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
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 175 "sintatica.y" /* yacc.c:1646  */
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
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 192 "sintatica.y" /* yacc.c:1646  */
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
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 208 "sintatica.y" /* yacc.c:1646  */
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
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 225 "sintatica.y" /* yacc.c:1646  */
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
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 245 "sintatica.y" /* yacc.c:1646  */
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
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 261 "sintatica.y" /* yacc.c:1646  */
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
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 279 "sintatica.y" /* yacc.c:1646  */
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
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 295 "sintatica.y" /* yacc.c:1646  */
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
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 311 "sintatica.y" /* yacc.c:1646  */
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
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 327 "sintatica.y" /* yacc.c:1646  */
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
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 344 "sintatica.y" /* yacc.c:1646  */
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
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 361 "sintatica.y" /* yacc.c:1646  */
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
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 378 "sintatica.y" /* yacc.c:1646  */
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
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 404 "sintatica.y" /* yacc.c:1646  */
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
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 426 "sintatica.y" /* yacc.c:1646  */
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
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 459 "sintatica.y" /* yacc.c:1646  */
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
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 480 "sintatica.y" /* yacc.c:1646  */
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
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 495 "sintatica.y" /* yacc.c:1646  */
    {
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
			 		string tempVar = createvar();
			 		(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + tempVar + " = (" + tipoAtual + ") " + (yyvsp[0]).label + ";\n\t"
			 		+ varDeclarada->label + " = " + varDeclarada->label + " + " + tempVar + ";\n";
			 	}
			 	else
			 	{
			 		string tempVar = createvar();
		 			(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + tempVar + " = " + (yyvsp[0]).label + ";\n\t" 
		 			+ varDeclarada->label + " = " + varDeclarada->label + " + " + tempVar + ";\n";
			 	}
			}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 531 "sintatica.y" /* yacc.c:1646  */
    {
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
			 		string tempVar = createvar();
			 		(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + tempVar + " = (" + tipoAtual + ") " + (yyvsp[0]).label + ";\n\t"
			 		+ varDeclarada->label + " = " + varDeclarada->label + " - " + tempVar + ";\n";
			 	}
			 	else
			 	{
			 		string tempVar = createvar();
		 			(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + tempVar + " = " + (yyvsp[0]).label + ";\n\t" 
		 			+ varDeclarada->label + " = " + varDeclarada->label + " - " + tempVar + ";\n";
			 	}
			}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 567 "sintatica.y" /* yacc.c:1646  */
    {
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
			 		string tempVar = createvar();
			 		(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + tempVar + " = (" + tipoAtual + ") " + (yyvsp[0]).label + ";\n\t"
			 		+ varDeclarada->label + " = " + varDeclarada->label + " * " + tempVar + ";\n";
			 	}
			 	else
			 	{
			 		string tempVar = createvar();
		 			(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + tempVar + " = " + (yyvsp[0]).label + ";\n\t" 
		 			+ varDeclarada->label + " = " + varDeclarada->label + " * " + tempVar + ";\n";
			 	}
			}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 603 "sintatica.y" /* yacc.c:1646  */
    {
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
			 		string tempVar = createvar();
			 		(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + tempVar + " = (" + tipoAtual + ") " + (yyvsp[0]).label + ";\n\t"
			 		+ varDeclarada->label + " = " + varDeclarada->label + " / " + tempVar + ";\n";
			 	}
			 	else
			 	{
			 		string tempVar = createvar();
		 			(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + tempVar + " = " + (yyvsp[0]).label + ";\n\t" 
		 			+ varDeclarada->label + " = " + varDeclarada->label + " / " + tempVar + ";\n";
			 	}
			}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 642 "sintatica.y" /* yacc.c:1646  */
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
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 655 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 661 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "int";
			}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 667 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "float";
			}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 673 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "boolean";
			}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 679 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "char";
			}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 686 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 690 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 708 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 712 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;	
			}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 716 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 720 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 724 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 730 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyvsp[0]).isFunction = false;
				//Se condição for false, usar goto para pular o bloco inteiro de $5
			    (yyval).traducao = (yyvsp[-2]).traducao + "\n\tif (" + (yyvsp[-2]).label +") goto " + (yyval).blocoFim + ";\n" 
			    + (yyvsp[0]).traducao + "\t" + (yyval).blocoFim + ":\n";
			}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 740 "sintatica.y" /* yacc.c:1646  */
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
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 759 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyval).traducao = "\n\t" + (yyval).blocoIni + ":\n" + (yyvsp[-2]).traducao + "\n\tif(" + (yyvsp[-2]).label + ") goto " + (yyval).blocoFim +
				";\n" + (yyvsp[0]).traducao + "\n\t" + (yyval).blocoFim + ":";
			}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 768 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyval).traducao = "\n\t" + (yyval).blocoIni + ":\n" + (yyvsp[-3]).traducao + "\n\tif(" + (yyvsp[-3]).label + ") goto " + (yyvsp[0]).blocoIni +
				";\n" + (yyvsp[-1]).traducao + "\n\tgoto " + (yyvsp[0]).blocoFim + ";\n" + (yyvsp[0]).traducao + "\n\t" + (yyvsp[0]).blocoFim + ":\n";
			}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 778 "sintatica.y" /* yacc.c:1646  */
    {
				(yyvsp[0]).isFunction = false;	
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyval).traducao = "\n\t" + (yyval).blocoIni + ":\n" + (yyvsp[0]).traducao;
			}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 786 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				
				(yyval).traducao = "\n\t" + (yyval).blocoIni + ":\n" +
							  (yyvsp[0]).traducao;
			}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 797 "sintatica.y" /* yacc.c:1646  */
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
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 811 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "while";
				estruturasDeRepeticao.push_front(att);
			}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 822 "sintatica.y" /* yacc.c:1646  */
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
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 835 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "do";
				estruturasDeRepeticao.push_front(att);
			}
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 846 "sintatica.y" /* yacc.c:1646  */
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
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 860 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "for";
				estruturasDeRepeticao.push_front(att);
			}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 871 "sintatica.y" /* yacc.c:1646  */
    {
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'break' fora de blocos 'for', 'while' e 'do/while'.");

				atributos * att = estruturasDeRepeticao.front();
				(yyval).traducao = "\n\tgoto " + att->blocoFim + ";\n";
			}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 881 "sintatica.y" /* yacc.c:1646  */
    {
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'breakall' fora de blocos 'for', 'while' e 'do/while'.");

				atributos *att = estruturasDeRepeticao.back();
				(yyval).traducao = "\n\tgoto " + att->blocoFim + ";\n";
			}
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 891 "sintatica.y" /* yacc.c:1646  */
    {
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'continue' fora de blocos 'for', 'while' e 'do/while'.");

				atributos * att = estruturasDeRepeticao.front();
				(yyval).traducao = "\n\tgoto " + att->blocoIni + ";\n";
			}
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 901 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).traducao = "\tfloat "+ (yyval).label+ " = " + (yyvsp[0]).traducao + ";\n";
				(yyval).tipo = "float";
			}
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 907 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).traducao = "\tint "+ (yyval).label+ " = " + (yyvsp[0]).traducao + ";\n";
				(yyval).tipo = "int";
			}
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 913 "sintatica.y" /* yacc.c:1646  */
    {
				//Verificando se a variavel existe no escopo corrente
				(yyval).label = createvar();
				atributos* variavel = getVarNoEscopo((yyvsp[0]).label);

		  		if(varNoEscopo((yyvsp[0]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[0]).label + "' não declarada no bloco.");

		  		(yyval).traducao = "\t" + variavel->tipo + " " + (yyval).label + " = " + variavel->label + ";\n";
		  		(yyval).tipo = variavel->tipo;
			}
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 927 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
			}
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 933 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " || " + (yyvsp[0]).label + ";\n";
			}
#line 2596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 939 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " && " + (yyvsp[0]).label + ";\n";
			}
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 945 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = "\tint " + (yyval).label + " = " + (yyvsp[-1]).traducao + " == 0;\n";
			}
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 951 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[0]).label + " == 0;\n";
			}
#line 2626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 957 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + " == 0;\n";
			}
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 963 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[0]).label + ";\n";
			}
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 969 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 977 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = "\tint "+ (yyval).label+ " = 1;\n";
			}
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 983 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = "\tint "+ (yyval).label+ " = 0;\n";
			}
#line 2676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 991 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
			}
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 997 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " == " + (yyvsp[0]).label + ";\n";
			}
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1003 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " != " + (yyvsp[0]).label + ";\n";
			}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1009 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " < " + (yyvsp[0]).label + ";\n";
			}
#line 2716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1015 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " <= " + (yyvsp[0]).label + ";\n";
			}
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1021 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " > " + (yyvsp[0]).label + ";\n";
			}
#line 2736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1027 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " >= " + (yyvsp[0]).label + ";\n";
			}
#line 2746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1036 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = (yyvsp[-1]).tipo;
				(yyval).traducao = (yyvsp[-1]).traducao + "\t" + (yyvsp[-1]).tipo + " " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
			}
#line 2756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1042 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = (yyvsp[-2]).tipo;
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[0]).label + ";\n";
			}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1048 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "+")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = "+(yyvsp[-2]).label+" + "+(yyvsp[0]).label+";\n";
			}
#line 2777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1055 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "-")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label+" = "+(yyvsp[-2]).label+" - "+(yyvsp[0]).label+";\n";
			}
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1062 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "*")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label+" = "+(yyvsp[-2]).label+" * "+(yyvsp[0]).label+";\n";
			}
#line 2799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1069 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "/")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = "+(yyvsp[-2]).label+" / "+(yyvsp[0]).label+";\n";
			}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1076 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "%")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label+" = "+(yyvsp[-2]).label+" % "+(yyvsp[0]).label+";\n";
			}
#line 2821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1083 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "^")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[-2]).label + " ^ " + (yyvsp[0]).label + ";\n";
			}
#line 2832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1090 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "<<")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[-2]).label + " << " + (yyvsp[0]).label + ";\n";
			}
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1097 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, ">>")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[-2]).label + " >> " + (yyvsp[0]).label + ";\n";
			}
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1104 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();

		  		if(varNoEscopo((yyvsp[-1]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[-1]).label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo((yyvsp[-1]).label);
		  		string tipoAtual = varDeclarada->tipo;

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "int" && varDeclarada->tipo != "float")
		  			yyerror("Variavel '" + (yyvsp[-1]).label +"' do tipo " + varDeclarada->tipo + " não pode ser convertida para numero");

			 	if(varDeclarada->tipo == "int")
		 		{
		 			(yyval).traducao = "\t" + (yyval).label + " = " + varDeclarada->label + ";\n\t" + varDeclarada->label 
		 			+ " = " + varDeclarada->label + " + 1;\n";
		 		}
		 		else
		 		{
		 			(yyval).traducao = "\t" + (yyval).label + " = " + varDeclarada->label + ";\n\t" + varDeclarada->label 
		 			+ " = " + varDeclarada->label + " + 1.0;\n";
		 		}

		 		(yyval).tipo = varDeclarada->tipo;
			}
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1131 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();

		  		if(varNoEscopo((yyvsp[-1]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[-1]).label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo((yyvsp[-1]).label);
		  		string tipoAtual = varDeclarada->tipo;

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "int" && varDeclarada->tipo != "float")
		  			yyerror("Variavel '" + (yyvsp[-1]).label +"' do tipo " + varDeclarada->tipo + " não pode ser convertida para numero");

			 	if(varDeclarada->tipo == "int")
		 		{
		 			(yyval).traducao = "\t" + (yyval).label + " = " + varDeclarada->label + ";\n\t" + varDeclarada->label + " = " 
		 			+ varDeclarada->label + " - 1;\n";
		 		}
		 		else
		 		{
		 			(yyval).traducao = "\t" + (yyval).label + " = " + varDeclarada->label + ";\n\t" + varDeclarada->label 
		 			+ " = " + varDeclarada->label + " - 1.0;\n";
		 		}

		 		(yyval).tipo = varDeclarada->tipo;
			}
#line 2916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1158 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();

		  		if(varNoEscopo((yyvsp[-1]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[-1]).label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo((yyvsp[-1]).label);
		  		string tipoAtual = varDeclarada->tipo;

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "int" && varDeclarada->tipo != "float")
		  			yyerror("Variavel '" + (yyvsp[-1]).label +"' do tipo " + varDeclarada->tipo + " não pode ser convertida para numero");

			 	if(varDeclarada->tipo == "int")
		 		{
		 			(yyval).traducao = "\t" + varDeclarada->label + " = " + varDeclarada->label + " + 1;\n\t" + (yyval).label + " = " + varDeclarada->label + "\n";
		 		}
		 		else
		 		{
		 			(yyval).traducao = "\t" + varDeclarada->label + " = " + varDeclarada->label + " + 1.0;\n\t" + (yyval).label + " = " + varDeclarada->label + "\n";
		 		}

		 		(yyval).tipo = varDeclarada->tipo;
			}
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1183 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();

		  		if(varNoEscopo((yyvsp[-1]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[-1]).label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo((yyvsp[-1]).label);
		  		string tipoAtual = varDeclarada->tipo;

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "int" && varDeclarada->tipo != "float")
		  			yyerror("Variavel '" + (yyvsp[-1]).label +"' do tipo " + varDeclarada->tipo + " não pode ser convertida para numero");

			 	if(varDeclarada->tipo == "int")
		 		{
		 			(yyval).traducao = "\t" + varDeclarada->label + " = " + varDeclarada->label + " - 1;\n\t" + (yyval).label + " = " + varDeclarada->label + "\n";
		 		}
		 		else
		 		{
		 			(yyval).traducao = "\t" + varDeclarada->label + " = " + varDeclarada->label + " - 1.0;\n\t" + (yyval).label + " = " + varDeclarada->label + "\n";
		 		}

		 		(yyval).tipo = varDeclarada->tipo;
			}
#line 2974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1208 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 2984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1216 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "char";
				(yyval).traducao = "\t"+ (yyval).label+ " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1224 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "string";
				int tamanho = (yyvsp[-2]).tamanhoString + (yyvsp[0]).tamanhoString;
				(yyval).tamanhoString = tamanho;
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\tchar " + (yyval).label + "[" + to_string(tamanho) + "];\n" + 
				"\tstrncpy(" + (yyval).label + "," + (yyvsp[-2]).label + "," + to_string((yyvsp[-2]).tamanhoString) + ");\n" +
				"\tstrncpy(" + (yyval).label + " + " + to_string((yyvsp[-2]).tamanhoString + 1) + "," + (yyvsp[0]).label + "," + to_string((yyvsp[0]).tamanhoString) + ");\n";
			}
#line 3008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1234 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "string";
				int tamanho = (yyvsp[0]).traducao.size() - 1;
				(yyval).tamanhoString = tamanho;
				(yyval).traducao = "\n\tchar " + (yyval).label + "[" + to_string(tamanho) + "];\n" + 
				"\tstrncpy(" + (yyval).label + "," + (yyvsp[0]).traducao + "," + to_string(tamanho) + ");\n";
			}
#line 3021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1243 "sintatica.y" /* yacc.c:1646  */
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
#line 3040 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3044 "y.tab.c" /* yacc.c:1646  */
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
#line 1259 "sintatica.y" /* yacc.c:1906  */


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
