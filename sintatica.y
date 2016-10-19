%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string tamanho;
};

//Estrutura que guarda informações sobre o cast a ser feito
typedef struct _tipo_cast
{
	string resultado;
	int operando_cast;
} tipo_cast;
// Mapa de casts
map<string, tipo_cast> mapa_cast;
int contador = 0;
int yylex(void);
void yyerror(string);
string createvar(void);

// Função para geração do mapa de cast
void gera_mapa_cast();
string gera_chave(string operador1, string operador2, string operacao);
%}

%token TK_NUM
%token TK_CHAR
%token TK_REAL
%token TK_TIPO_FLOAT
%token TK_TIPO_DOUBLE
%token TK_TIPO_STRING
%token TK_TIPO_BOOL
%token TK_MAIN TK_ID TK_TIPO_INT
%token TK_FIM TK_ERROR
%token TK_COMP TK_LT TK_GT TK_LTE TK_GTE TK_DIFF
%token TK_OR TK_AND TK_NOT TK_XOR
%token TK_EQ TK_MOD
%token TK_TIPO_BOOL_TRUE TK_TIPO_BOOL_FALSE
%token TK_SHIFT_LEFT TK_SHIFT_RIGHT

%start S

%left TK_PLUS TK_SUB
%left TK_MULT TK_DIV

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

DECLARACAO	: DECLARACAOSIMPLES
			| DECLARACAOATRIBUICAO
			;

DECLARACAOSIMPLES : TK_TIPO_INT TK_ID ';'
				  {
						$$.label = createvar();
						$$.traducao = "\tint " + $$.label + ";\n";
				  }
				  | TK_TIPO_FLOAT TK_ID ';'
				  {
						$$.label = createvar();
						$$.traducao = "\tfloat " + $$.label + ";\n";
				  }
				  | TK_TIPO_STRING TK_ID ';'
				  {
						$$.label = createvar();
						$$.traducao = "\tstring " + $$.label + ";\n";
				  }
				  | TK_TIPO_BOOL TK_ID ';'
				  {
						$$.label = createvar();
						$$.traducao = "\tboolean " + $$.label + ";\n";
				  }
				  ;

DECLARACAOATRIBUICAO : TK_TIPO_INT TK_ID TK_EQ TK_NUM ';'
					 {
					 	$$.label = createvar();
					 	$$.traducao = "\tint " + $$.label + " = " + $4.traducao + ";\n";
					 }
					 | TK_TIPO_INT TK_ID TK_EQ NUMEXP ';'
					 {
					 	$$.label = createvar();
					 	$$.traducao = $4.traducao + "\tint " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_FLOAT TK_ID TK_EQ TK_REAL ';'
					 {
					 	$$.label = createvar();
					 	$$.traducao = "\tfloat " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_FLOAT TK_ID TK_EQ NUMEXP ';'
					 {
					 	$$.label = createvar();
					 	$$.traducao = $4.traducao + "\tfloat " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_STRING TK_ID TK_EQ TK_CHAR';'
					 {
					 	$$.label = createvar();
					 	$$.traducao = "\tchar " + $$.label + " = " + $4.traducao + ";\n";
					 }
					 | TK_TIPO_STRING TK_ID TK_EQ  E ';'
					 {
					 	$$.label = createvar();
					 	$$.traducao = $4.traducao + "\tchar " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_BOOL TK_ID TK_EQ  TK_TIPO_BOOL_TRUE';'
					 {
					 	$$.label = createvar();
					 	$$.traducao = "\tint " + $$.label + " = 1;\n";
					 }
					 | TK_TIPO_BOOL TK_ID TK_EQ  TK_TIPO_BOOL_FALSE ';'
					 {
					 	$$.label = createvar();
					 	$$.traducao = "\tint " + $$.label + " = 0;\n";
					 }
					 | TK_TIPO_BOOL TK_ID TK_EQ  BOOLEANEXP ';'
					 {
					 	$$.label = createvar();
					 	$$.traducao = $4.traducao + "\tint " + $$.label + " = " + $4.label + ";\n";
					 }
					 ;

ATRIBUICAO	: TK_ID TK_EQ TK_NUM ';'
			 {
			 	$$.label = createvar();
			 	$$.traducao = $1.traducao + " = " + $3.traducao + ";\n";
			 }
			| TK_ID TK_EQ E
			{
				$$.label = createvar();
			 	$$.traducao = $3.traducao + "\t" + $1.traducao + " = " + $3.label + ";\n";
			}
			| TK_ID TK_EQ TK_REAL ';'
			{
				$$.label = createvar();
			 	$$.traducao = $1.traducao + " = " + $3.traducao + ";\n";
			}
			| TK_ID TK_EQ TK_CHAR';'
			{
				$$.label = createvar();
			 	$$.traducao = $1.traducao + " = " + $3.traducao + ";\n";
			}
			| TK_ID TK_EQ CAST ';'
			;

CAST 		: '(' TIPO ')' TK_ID ';'
			{
				string nome_variavel_temporaria_cast;
				string chave = gera_chave($2.label, $4.tipo, "=");
				if (mapa_cast.find(chave) != mapa_cast.end()) {
					tipo_cast cast = mapa_cast[chave];
					nome_variavel_temporaria_cast = createvar();
					$$.traducao = "\t" + $4.traducao + "\n\t" + nome_variavel_temporaria_cast + " = " + "(" + cast.resultado + ") " + $4.label + ";";
					$$.tipo = cast.resultado;
					$$.tamanho = $4.tamanho;
					$$.label = nome_variavel_temporaria_cast;
				}
			};

TIPO 		: TK_TIPO_INT
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			| TK_TIPO_FLOAT
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			| TK_TIPO_BOOL
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			| TK_TIPO_DOUBLE
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			| TK_TIPO_STRING
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			};

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			;

COMANDO 	: E ';'
			| DECLARACAO
			| ATRIBUICAO
			;

E 			: NUMEXP
			| CHAREXP
			| BOOLEANEXP
			;


NUMBER		: TK_REAL
			{
				$$.label = createvar();
				$$.traducao = "\tfloat "+ $$.label+ " = " + $1.traducao + ";\n";
			}
			| TK_NUM
			{
				$$.label = createvar();
				$$.traducao = "\tint "+ $$.label+ " = " + $1.traducao + ";\n";
			}
			;

BOOLEANEXP	: '(' BOOLEANEXP ')' 
			{
				$$.label = createvar();
				$$.traducao = $2.traducao + "\tint " + $$.label + " = " + $2.label + ";\n";
			}
			| BOOLEANEXP TK_OR BOOLEANEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " || " + $3.label + ";\n";
			}
			| BOOLEANEXP TK_AND BOOLEANEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " && " + $3.label + ";\n";
			}
			| TK_NOT TK_ID 
			{
				$$.label = createvar();
				$$.traducao = "\tint " + $$.label + " = " + $1.traducao + " == 0;\n";
			}
			| TK_NOT BOOLEANTYPE 
			{
				$$.label = createvar();
				$$.traducao = $2.traducao + "\tint " + $$.label + " = " + $2.label + " == 0;\n";
			}
			| TK_NOT '(' BOOLEANEXP ')' 
			{
				$$.label = createvar();
				$$.traducao = $3.traducao + "\tint " + $$.label + " = " + $3.label + " == 0;\n";
			}
			| LOGICALEXP
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + "\tint " + $$.label + " = " + $1.label + ";\n";
			}
			| BOOLEANTYPE
			;

BOOLEANTYPE : TK_TIPO_BOOL_TRUE
			{
				$$.label = createvar();
				$$.traducao = "\tint "+ $$.label+ " = 1;\n";
			}
			| TK_TIPO_BOOL_FALSE
			{
				$$.label = createvar();
				$$.traducao = "\tint "+ $$.label+ " = 0;\n";
			}
			;

LOGICALEXP	: '(' LOGICALEXP ')' 
			{
				$$.label = createvar();
				$$.traducao = $2.traducao + "\tint " + $$.label + " = " + $2.label + ";\n";
			}
			| NUMEXP TK_COMP NUMEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " == " + $3.label + ";\n";
			}
			| NUMEXP TK_DIFF NUMEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " != " + $3.label + ";\n";
			}
			| NUMEXP TK_LT NUMEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
			}
			| NUMEXP TK_LTE NUMEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " <= " + $3.label + ";\n";
			}
			| NUMEXP TK_GT NUMEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
			}
			| NUMEXP TK_GTE NUMEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
			}
			;


NUMEXP		: '(' NUMEXP ')'
			{
				$$.label = createvar();
				$$.traducao = $2.traducao + "\t" + $$.label + " = " + $2.label + ";\n";
			}
			| NUMEXP TK_PLUS NUMEXP
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" + "+$3.label+";\n";
			}
			| NUMEXP TK_SUB NUMEXP
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" - "+$3.label+";\n";
			}
			| NUMEXP TK_MULT NUMEXP
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" * "+$3.label+";\n";
			}
			| NUMEXP TK_DIV NUMEXP
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" / "+$3.label+";\n";
			}
			| NUMEXP TK_MOD NUMEXP
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" % "+$3.label+";\n";
			}
			| NUMEXP TK_XOR NUMEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " ^ " + $3.label + ";\n";
			}
			| NUMEXP TK_SHIFT_LEFT NUMEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " << " + $3.label + ";\n";
			}
			| NUMEXP TK_SHIFT_RIGHT NUMEXP 
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " >> " + $3.label + ";\n";
			}
			| NUMBER
			;

CHAREXP		: TK_CHAR
			{
				$$.label = createvar();
				$$.traducao = "\t"+ $$.label+ " = " + $1.traducao + ";\n";
			}
			;


%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
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
	FILE* file = fopen("./src/mapa_cast.txt", "r");
	char operador1[20] = "";
	char operador2[20] = "";
	char operacao[3] = "";
	char resultado[20] = "";
	int operando_cast;
	while(fscanf(file, "%s\t%s\t%s\t%s\t%d\n", operador1, operacao, operador2, resultado, &operando_cast)) {
		tipo_cast cast = {resultado, operando_cast};
		mapa_cast[gera_chave(operador1, operador2, operacao)] = cast;
		//cout << operador1 << " " << operador2 << " " << operacao;
		if(feof(file)) {
			break;
		}
	}
	fclose(file);
}

string gera_chave(string operador1, string operador2, string operacao) {
	return operador1 + "_" + operacao + "_" + operador2;
}