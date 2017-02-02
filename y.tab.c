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
atributos* getVarNoEscopo(string varName);
string gerarBloco();
string gerarInicioDeBloco(string l);
string gerarFimDeBloco(string l);


#line 122 "y.tab.c" /* yacc.c:339  */

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
    TK_TIPO_FLOAT = 261,
    TK_TIPO_CHAR = 262,
    TK_TIPO_STRING = 263,
    TK_TIPO_BOOL = 264,
    TK_MAIN = 265,
    TK_ID = 266,
    TK_TIPO_INT = 267,
    TK_FIM = 268,
    TK_ERROR = 269,
    TK_COMP = 270,
    TK_LT = 271,
    TK_GT = 272,
    TK_LTE = 273,
    TK_GTE = 274,
    TK_DIFF = 275,
    TK_OR = 276,
    TK_AND = 277,
    TK_NOT = 278,
    TK_XOR = 279,
    TK_EQ = 280,
    TK_MOD = 281,
    TK_TIPO_BOOL_TRUE = 282,
    TK_TIPO_BOOL_FALSE = 283,
    TK_SHIFT_LEFT = 284,
    TK_SHIFT_RIGHT = 285,
    TK_IF = 286,
    TK_ELSE = 287,
    TK_WHILE = 288,
    TK_DO = 289,
    TK_FOR = 290,
    TK_BREAK = 291,
    TK_CONTINUE = 292,
    TK_PLUS = 293,
    TK_SUB = 294,
    TK_MULT = 295,
    TK_DIV = 296
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_CHAR 259
#define TK_REAL 260
#define TK_TIPO_FLOAT 261
#define TK_TIPO_CHAR 262
#define TK_TIPO_STRING 263
#define TK_TIPO_BOOL 264
#define TK_MAIN 265
#define TK_ID 266
#define TK_TIPO_INT 267
#define TK_FIM 268
#define TK_ERROR 269
#define TK_COMP 270
#define TK_LT 271
#define TK_GT 272
#define TK_LTE 273
#define TK_GTE 274
#define TK_DIFF 275
#define TK_OR 276
#define TK_AND 277
#define TK_NOT 278
#define TK_XOR 279
#define TK_EQ 280
#define TK_MOD 281
#define TK_TIPO_BOOL_TRUE 282
#define TK_TIPO_BOOL_FALSE 283
#define TK_SHIFT_LEFT 284
#define TK_SHIFT_RIGHT 285
#define TK_IF 286
#define TK_ELSE 287
#define TK_WHILE 288
#define TK_DO 289
#define TK_FOR 290
#define TK_BREAK 291
#define TK_CONTINUE 292
#define TK_PLUS 293
#define TK_SUB 294
#define TK_MULT 295
#define TK_DIV 296

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

#line 255 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      42,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    85,    90,    96,   101,   108,   115,   116,
     119,   133,   147,   160,   176,   189,   204,   217,   230,   243,
     257,   270,   285,   307,   329,   350,   365,   368,   382,   387,
     393,   399,   405,   412,   417,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   433,   437,   441,   445,   451,   461,
     476,   484,   495,   509,   520,   533,   544,   558,   569,   579,
     589,   595,   601,   615,   621,   627,   633,   639,   645,   651,
     657,   665,   671,   679,   685,   691,   697,   703,   709,   715,
     724,   730,   736,   743,   750,   757,   764,   771,   778,   785,
     792,   800
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_CHAR", "TK_REAL",
  "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_STRING", "TK_TIPO_BOOL",
  "TK_MAIN", "TK_ID", "TK_TIPO_INT", "TK_FIM", "TK_ERROR", "TK_COMP",
  "TK_LT", "TK_GT", "TK_LTE", "TK_GTE", "TK_DIFF", "TK_OR", "TK_AND",
  "TK_NOT", "TK_XOR", "TK_EQ", "TK_MOD", "TK_TIPO_BOOL_TRUE",
  "TK_TIPO_BOOL_FALSE", "TK_SHIFT_LEFT", "TK_SHIFT_RIGHT", "TK_IF",
  "TK_ELSE", "TK_WHILE", "TK_DO", "TK_FOR", "TK_BREAK", "TK_CONTINUE",
  "TK_PLUS", "TK_SUB", "TK_MULT", "TK_DIV", "'('", "')'", "'{'", "'}'",
  "';'", "$accept", "S", "ESCOPO_GLOBAL", "FUNC_MAIN", "BLOCO",
  "ESCOPO_INI", "ESCOPO_FIM", "DECLARACAO", "DECLARACAOSIMPLES",
  "DECLARACAOATRIBUICAO", "ATRIBUICAO", "CAST", "TIPO", "COMANDOS",
  "COMANDO", "E", "IF", "ELSE", "WHILE", "WHILE_LABEL", "DO", "DO_LABEL",
  "FOR", "FOR_LABEL", "BREAK", "CONTINUE", "NUMBER", "BOOLEANEXP",
  "BOOLEANTYPE", "LOGICALEXP", "NUMEXP", "CHAREXP", YY_NULLPTR
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
     295,   296,    40,    41,   123,   125,    59
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -35

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -80,    19,    27,   -80,    42,   -80,    50,    57,    61,   -80,
     -80,    26,   -80,   -80,   -80,    95,    96,   106,   104,   124,
      13,   -80,   -80,    98,   -80,   -80,   -80,   100,   108,   110,
     -80,   -80,   -80,   117,   -80,   105,    26,   122,   -80,   -80,
     130,   -80,    61,   -80,   133,   -80,   -80,   -80,   138,   -80,
     -80,   196,   -80,   -19,   -10,    74,   120,    84,   -80,   146,
     -80,   146,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   110,
     136,    -1,   147,   167,   -80,   -80,   -80,   -80,   -80,   146,
     161,   178,   146,   146,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    85,   -80,
     194,   -80,   153,   -80,   -80,   -34,   -80,   -80,    21,    92,
     -80,    29,   196,    89,   157,   150,   -80,   -80,   -80,   123,
     159,   104,   158,   138,   138,     2,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   264,   264,   141,   141,
     163,   203,   171,   172,   173,     1,   175,   221,   -80,    61,
      23,    48,   246,    61,   146,   146,   239,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   170,   -80,   156,    80,   -27,
     -80,   177,   178,   -80,   -80,   -80,   160,    61,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     2,     0,     0,     0,     6,
       4,    28,    61,    91,    60,     0,     0,     0,    62,     0,
       0,    71,    72,     0,    53,    55,    57,     0,     0,     0,
      36,     8,     9,     0,    47,     0,    28,     0,    38,    39,
       0,    40,     0,    41,     0,    42,    43,    90,    46,    70,
      69,    44,    45,     0,     0,     0,    28,     0,    66,     0,
      67,     0,    58,    59,    30,    32,    31,    62,    29,     0,
       0,     0,    69,     0,    37,     7,     5,    33,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    12,     0,    13,    25,    60,    26,    23,    90,     0,
      10,     0,     0,     0,     0,     0,    63,    73,    80,     0,
       0,     0,     0,    64,    65,     0,    74,    76,    78,    77,
      79,    75,    87,    86,    88,    89,    82,    83,    84,    85,
      60,     0,     0,    71,    72,     0,    61,     0,    68,     0,
       0,    62,    81,     0,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    14,    15,    48,    52,     0,     0,     0,
      49,     0,     0,    50,    51,    54,     0,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -41,   -80,   -80,   -80,   -80,   -80,
     -79,   168,   199,   195,   -80,   174,    69,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   183,   -13,   220,   -26,
     -11,   -80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    10,    11,    76,    30,    31,    32,
      33,    34,   114,    35,    36,    37,    38,   170,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
     112,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    80,   122,    72,    23,    12,    98,    14,    64,   -24,
      65,    66,   -24,    67,    68,   100,    71,     9,    73,     3,
      82,    83,    82,    83,    58,    51,    12,    99,    14,    12,
      13,    14,    15,    16,    67,    17,   101,    18,    19,     4,
      21,    22,   116,    72,   125,    51,   111,   162,   113,    20,
      82,    83,     6,    21,    22,    59,    71,    23,    73,    24,
      25,    26,    27,    28,   -22,   125,   119,   -22,    29,   123,
     124,   -34,   148,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   141,    12,   145,
     140,   -27,     7,   176,   -27,   146,    67,    14,   147,   102,
       8,    82,    83,    67,   152,     9,    53,    54,   165,   109,
      82,    83,   166,    12,   156,    14,    64,    55,    65,    66,
     103,    67,    68,    12,   104,   105,   172,   125,   173,    56,
     110,    67,   149,    20,   125,    57,   178,    21,    22,   152,
      61,   167,   168,    20,    82,    83,    62,    21,    22,    12,
      75,    14,    69,    12,    63,    14,    12,    67,    14,    82,
      83,   151,    29,    74,    67,    90,   153,    91,    78,    20,
      92,    93,    79,    21,    22,    81,    20,    82,    83,   115,
     143,   144,    84,    85,    86,    87,    88,    89,    69,   121,
     117,    90,   125,    91,   120,    69,    92,    93,   142,   171,
     150,   154,   169,   177,   155,    94,    95,    96,    97,   157,
     118,    84,    85,    86,    87,    88,    89,   159,   160,   161,
      90,   163,    91,   175,   106,    92,    93,    90,    70,    91,
     107,    77,    92,    93,    94,    95,    96,    97,   174,   108,
      60,    94,    95,    96,    97,    90,     0,    91,     0,   158,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    90,     0,    91,     0,   164,    92,    93,
      90,     0,    91,     0,     0,    92,    93,    94,    95,    96,
      97,     0,   118,     0,    94,    95,    96,    97,    90,     0,
      91,     0,     0,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97
};

static const yytype_int16 yycheck[] =
{
      11,    42,    81,    29,    31,     3,    25,     5,     6,    43,
       8,     9,    46,    11,    12,    25,    29,    44,    29,     0,
      21,    22,    21,    22,    11,    36,     3,    46,     5,     3,
       4,     5,     6,     7,    11,     9,    46,    11,    12,    12,
      27,    28,    43,    69,    42,    56,    59,    46,    61,    23,
      21,    22,    10,    27,    28,    42,    69,    31,    69,    33,
      34,    35,    36,    37,    43,    42,    79,    46,    42,    82,
      83,    45,    43,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     3,   102,
       5,    43,    42,   172,    46,     3,    11,     5,   109,    25,
      43,    21,    22,    11,   115,    44,    11,    11,   149,    25,
      21,    22,   153,     3,   125,     5,     6,    11,     8,     9,
      46,    11,    12,     3,     4,     5,    46,    42,   169,    25,
      46,    11,    43,    23,    42,    11,   177,    27,    28,   150,
      42,   154,   155,    23,    21,    22,    46,    27,    28,     3,
      45,     5,    42,     3,    46,     5,     3,    11,     5,    21,
      22,    11,    42,    46,    11,    24,    43,    26,    46,    23,
      29,    30,    42,    27,    28,    42,    23,    21,    22,    43,
      27,    28,    15,    16,    17,    18,    19,    20,    42,    11,
      43,    24,    42,    26,    33,    42,    29,    30,     4,    43,
      43,    42,    32,    43,    46,    38,    39,    40,    41,    46,
      43,    15,    16,    17,    18,    19,    20,    46,    46,    46,
      24,    46,    26,    46,    56,    29,    30,    24,    29,    26,
      56,    36,    29,    30,    38,    39,    40,    41,   169,    56,
      20,    38,    39,    40,    41,    24,    -1,    26,    -1,    46,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    24,    -1,    26,    -1,    46,    29,    30,
      24,    -1,    26,    -1,    -1,    29,    30,    38,    39,    40,
      41,    -1,    43,    -1,    38,    39,    40,    41,    24,    -1,
      26,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,    12,    50,    10,    42,    43,    44,
      51,    52,     3,     4,     5,     6,     7,     9,    11,    12,
      23,    27,    28,    31,    33,    34,    35,    36,    37,    42,
      54,    55,    56,    57,    58,    60,    61,    62,    63,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    11,    11,    11,    25,    11,    11,    42,
      75,    42,    46,    46,     6,     8,     9,    11,    12,    42,
      59,    74,    76,    77,    46,    45,    53,    60,    46,    42,
      51,    42,    21,    22,    15,    16,    17,    18,    19,    20,
      24,    26,    29,    30,    38,    39,    40,    41,    25,    46,
      25,    46,    25,    46,     4,     5,    58,    62,    73,    25,
      46,    74,    77,    74,    59,    43,    43,    43,    43,    74,
      33,    11,    57,    74,    74,    42,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
       5,    77,     4,    27,    28,    74,     3,    77,    43,    43,
      43,    11,    77,    43,    42,    46,    77,    46,    46,    46,
      46,    46,    46,    46,    46,    51,    51,    74,    74,    32,
      64,    43,    46,    51,    63,    46,    57,    43,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    52,    53,    54,    54,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     5,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     5,     5,     5,     5,     5,     5,
       5,     5,     3,     3,     3,     3,     3,     4,     0,     1,
       1,     1,     1,     2,     0,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     6,
       2,     2,     5,     1,     7,     1,     9,     1,     2,     2,
       1,     1,     1,     3,     3,     3,     2,     2,     4,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1
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
#line 80 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "sintatica.y" /* yacc.c:1646  */
    {
					abrirEscopo();
				}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "sintatica.y" /* yacc.c:1646  */
    {
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << (yyvsp[0]).traducao << "\treturn 0;\n}" << endl; 
			}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "sintatica.y" /* yacc.c:1646  */
    {
				abrirEscopo();
				(yyval).traducao = "";
			}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "sintatica.y" /* yacc.c:1646  */
    {
				fecharEscopo();
				(yyval).traducao = "";
			}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 120 "sintatica.y" /* yacc.c:1646  */
    {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-1]).label) == false){
				  			(*mapa)[(yyvsp[-1]).label].label = createvar();
				  			(*mapa)[(yyvsp[-1]).label].tipo = "int"; 
				  		}

				  		(yyval).tipo = (*mapa)[(yyvsp[-1]).label].tipo;
						(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;

						(yyval).label =  (yyvsp[-1]).label;
						(yyval).traducao = "\tint " + (yyval).label + ";\n";
				  }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "sintatica.y" /* yacc.c:1646  */
    {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-1]).label) == false){
				  			(*mapa)[(yyvsp[-1]).label].label = createvar();
				  			(*mapa)[(yyvsp[-1]).label].tipo = "int"; 
				  		}

				  		(yyval).tipo = (*mapa)[(yyvsp[-1]).label].tipo;
						(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;

						(yyval).label =  (yyvsp[-1]).label;
						(yyval).traducao = "\tfloat " + (yyval).label + ";\n";
				  }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 148 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-1]).label) == false){
				  			(*mapa)[(yyvsp[-1]).label].label = createvar();
				  			(*mapa)[(yyvsp[-1]).label].tipo = "char"; 
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-1]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-1]).label].tipo;
					 	(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;
						(yyval).traducao = "\tchar " + (yyval).label + ";\n";
				  }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "sintatica.y" /* yacc.c:1646  */
    {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-1]).label) == false){
				  			(*mapa)[(yyvsp[-1]).label].label = createvar();
				  			(*mapa)[(yyvsp[-1]).label].tipo = "int"; 
				  		}

				  		(yyval).tipo = (*mapa)[(yyvsp[-1]).label].tipo;
						(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;

						(yyval).label =  (yyvsp[-1]).label;
						(yyval).traducao = "\tint " + (yyval).label + ";\n";
				  }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 177 "sintatica.y" /* yacc.c:1646  */
    {
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tint " + (yyval).label + " = " + (yyvsp[-1]).traducao + ";\n";
					 }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 190 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;

					 	(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
					 }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 205 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "float"; 
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tfloat " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
					 }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 218 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "float"; 
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = (yyvsp[-1]).traducao + "\tfloat " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
					 }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 231 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "char"; 
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tchar " + (yyval).label + " = '" + (yyvsp[-1]).traducao + "';\n";
					 }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 244 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tint " + (yyval).label + " = 1;\n";
					 }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 258 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = "\tint " + (yyval).label + " = 0;\n";
					 }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 271 "sintatica.y" /* yacc.c:1646  */
    {
					 	(yyval).label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo((yyvsp[-3]).label) == false){
				  			(*mapa)[(yyvsp[-3]).label].label = createvar();
				  			(*mapa)[(yyvsp[-3]).label].tipo = "int"; 
				  		}

					 	(yyval).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).tipo = (*mapa)[(yyvsp[-3]).label].tipo;
					 	(yyvsp[-3]).label = (*mapa)[(yyvsp[-3]).label].label;
					 	(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
					 }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 286 "sintatica.y" /* yacc.c:1646  */
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
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 308 "sintatica.y" /* yacc.c:1646  */
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
			 	
			 	(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + varDeclarada->label + " = (" + tipoAtual + ") " + (yyvsp[0]).label + ";\n";
			}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 330 "sintatica.y" /* yacc.c:1646  */
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
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 351 "sintatica.y" /* yacc.c:1646  */
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
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 369 "sintatica.y" /* yacc.c:1646  */
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
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 382 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 388 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "int";
			}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 394 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "float";
			}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 400 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "boolean";
			}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 406 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = "char";
			}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 413 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 434 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 438 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;	
			}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 442 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 446 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 452 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyvsp[0]).isFunction = false;
				//Se condição for false, usar goto para pular o bloco inteiro de $5
			    (yyval).traducao = (yyvsp[-2]).traducao + "\n\tif (" + (yyvsp[-2]).label +" == 0) goto " + (yyval).blocoFim + ";\n" 
			    + (yyvsp[0]).traducao + "\t" + (yyval).blocoFim + ":\n";
			}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 462 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyvsp[-1]).isFunction = false;
			    (yyval).traducao = "\n" + (yyvsp[-3]).traducao + 
					 "\n\t" + "if(" + (yyvsp[-3]).label + " == 0) goto " + (yyvsp[0]).blocoIni + ";\n" + 
					 (yyvsp[-1]).traducao + 
					 "\tgoto " + (yyvsp[0]).blocoFim +";\n" +
					 (yyvsp[0]).traducao + 
					 "\n\t" + (yyvsp[0]).blocoFim + ":\n";	
			}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 477 "sintatica.y" /* yacc.c:1646  */
    {
				(yyvsp[0]).isFunction = false;	
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				(yyval).traducao = "\n\t" + (yyval).blocoIni + ":\n" + (yyvsp[0]).traducao;
			}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 485 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).jump = gerarBloco();
				(yyval).blocoIni = gerarInicioDeBloco((yyval).jump);
				(yyval).blocoFim = gerarFimDeBloco((yyval).jump);
				
				(yyval).traducao = "\n\t" + (yyval).blocoIni + ":\n" +
							  (yyvsp[0]).traducao;
			}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 496 "sintatica.y" /* yacc.c:1646  */
    {
				(yyvsp[0]).isFunction = false;
				atributos* att = estruturasDeRepeticao.front();
				(yyval).jump = att->jump;
				(yyval).blocoIni = att->blocoIni;
				(yyval).blocoFim = att->blocoFim;
			    (yyval).traducao = (yyvsp[-2]).traducao + "\n\t" + (yyval).blocoIni + ":\n\tif (" + (yyvsp[-2]).label +" == 0) goto " + (yyval).blocoFim + ";\n" 
			    + (yyvsp[0]).traducao + "\n\tgoto " + (yyval).blocoIni + ";\n\t" + (yyval).blocoFim + ":\n";

			    estruturasDeRepeticao.pop_front();
			}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 510 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "while";
				estruturasDeRepeticao.push_front(att);
			}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 521 "sintatica.y" /* yacc.c:1646  */
    {
				(yyvsp[-5]).isFunction = false;
				atributos* att = estruturasDeRepeticao.front();
				(yyval).jump = att->jump;
				(yyval).blocoIni = att->blocoIni;
				(yyval).blocoFim = att->blocoFim;
			    (yyval).traducao = "\n\t" + (yyval).blocoIni + "\n" + (yyvsp[-2]).traducao + (yyvsp[-5]).traducao + "\n\tif (" + (yyvsp[-2]).label + " == 0)" +
			    "goto " + (yyval).blocoFim + ";" + 	"\n\t" + "goto " + (yyval).blocoIni + ";" + "\n\t" + (yyval).blocoFim + ":\n";
			    estruturasDeRepeticao.pop_front();
			}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 534 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "do";
				estruturasDeRepeticao.push_front(att);
			}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 545 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = estruturasDeRepeticao.front();
				(yyval).jump = att->jump;
				(yyval).blocoIni = att->blocoIni;
				(yyval).blocoFim = att->blocoFim;
				(yyval).traducao = (yyvsp[-6]).traducao + "\n\t" + (yyval).blocoIni + ":\n\t" + (yyvsp[-4]).traducao + 
				"\n\tif(" + (yyvsp[-4]).label + " == 0) goto " + (yyval).blocoFim + ";\n\t" + (yyvsp[0]).traducao + "\n\n" + (yyvsp[-2]).traducao + 
				"\tgoto " + (yyval).blocoIni + ";\n\t" + (yyval).blocoFim;

				estruturasDeRepeticao.pop_front();
			}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 559 "sintatica.y" /* yacc.c:1646  */
    {
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "for";
				estruturasDeRepeticao.push_front(att);
			}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 570 "sintatica.y" /* yacc.c:1646  */
    {
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'break' fora de blocos 'for', 'while' e 'do/while'.");

				atributos * att = estruturasDeRepeticao.front();
				(yyval).traducao = "\n\tgoto " + att->blocoFim + ";\n";
			}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 580 "sintatica.y" /* yacc.c:1646  */
    {
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'continue' fora de blocos 'for', 'while' e 'do/while'.");

				atributos * att = estruturasDeRepeticao.front();
				(yyval).traducao = "\n\tgoto " + att->blocoIni + ";\n";
			}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 590 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).traducao = "\tfloat "+ (yyval).label+ " = " + (yyvsp[0]).traducao + ";\n";
				(yyval).tipo = "float";
			}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 596 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).traducao = "\tint "+ (yyval).label+ " = " + (yyvsp[0]).traducao + ";\n";
				(yyval).tipo = "int";
			}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 602 "sintatica.y" /* yacc.c:1646  */
    {
				//Verificando se a variavel existe no escopo corrente
				(yyval).label = createvar();
				atributos* variavel = getVarNoEscopo((yyvsp[0]).label);

		  		if(varNoEscopo((yyvsp[0]).label) == false) 
		  			yyerror("Variável '" + (yyvsp[0]).label + "' não declarada no bloco.");

		  		(yyval).traducao = "\t" + variavel->tipo + " " + (yyval).label + " = " + variavel->label + ";\n";
		  		(yyval).tipo = variavel->tipo;
			}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 616 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
			}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 622 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " || " + (yyvsp[0]).label + ";\n";
			}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 628 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " && " + (yyvsp[0]).label + ";\n";
			}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 634 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = "\tint " + (yyval).label + " = " + (yyvsp[-1]).traducao + " == 0;\n";
			}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 640 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[0]).label + " == 0;\n";
			}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 646 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + " == 0;\n";
			}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 652 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[0]).label + ";\n";
			}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 658 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 666 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = "\tint "+ (yyval).label+ " = 1;\n";
			}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 672 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = "\tint "+ (yyval).label+ " = 0;\n";
			}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 680 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-1]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
			}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 686 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " == " + (yyvsp[0]).label + ";\n";
			}
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 692 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " != " + (yyvsp[0]).label + ";\n";
			}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 698 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " < " + (yyvsp[0]).label + ";\n";
			}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 704 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " <= " + (yyvsp[0]).label + ";\n";
			}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 710 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " > " + (yyvsp[0]).label + ";\n";
			}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 716 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "boolean";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tint " + (yyval).label + " = " + (yyvsp[-2]).label + " >= " + (yyvsp[0]).label + ";\n";
			}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 725 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = (yyvsp[-1]).tipo;
				(yyval).traducao = (yyvsp[-1]).traducao + "\t" + (yyvsp[-1]).tipo + " " + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
			}
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 731 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = (yyvsp[-2]).tipo;
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[0]).label + ";\n";
			}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 737 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "+")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = "+(yyvsp[-2]).label+" + "+(yyvsp[0]).label+";\n";
			}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 744 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "-")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label+" = "+(yyvsp[-2]).label+" - "+(yyvsp[0]).label+";\n";
			}
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 751 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "*")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label+" = "+(yyvsp[-2]).label+" * "+(yyvsp[0]).label+";\n";
			}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 758 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "/")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = "+(yyvsp[-2]).label+" / "+(yyvsp[0]).label+";\n";
			}
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 765 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "%")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label+" = "+(yyvsp[-2]).label+" % "+(yyvsp[0]).label+";\n";
			}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 772 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "^")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[-2]).label + " ^ " + (yyvsp[0]).label + ";\n";
			}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 779 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, "<<")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[-2]).label + " << " + (yyvsp[0]).label + ";\n";
			}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 786 "sintatica.y" /* yacc.c:1646  */
    {
				//Gerando o tipo de cast a partir dos numeros da operação
				(yyval).tipo = mapa_cast[gera_chave((yyvsp[-2]).tipo, (yyvsp[0]).tipo, ">>")].resultado;
				(yyval).label = createvar();
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).tipo + " " + (yyval).label + " = " + (yyvsp[-2]).label + " >> " + (yyvsp[0]).label + ";\n";
			}
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 793 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 801 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = createvar();
				(yyval).tipo = "char";
				(yyval).traducao = "\t"+ (yyval).label+ " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2451 "y.tab.c" /* yacc.c:1646  */
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
#line 809 "sintatica.y" /* yacc.c:1906  */


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
