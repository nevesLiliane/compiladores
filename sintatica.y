%{
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

%}

%token TK_NUM
%token TK_CHAR
%token TK_REAL
%token TK_TIPO_FLOAT
%token TK_TIPO_CHAR TK_TIPO_STRING
%token TK_TIPO_BOOL
%token TK_MAIN TK_ID TK_TIPO_INT
%token TK_FIM TK_ERROR
%token TK_COMP TK_LT TK_GT TK_LTE TK_GTE TK_DIFF
%token TK_OR TK_AND TK_NOT TK_XOR
%token TK_EQ TK_MOD
%token TK_TIPO_BOOL_TRUE TK_TIPO_BOOL_FALSE
%token TK_SHIFT_LEFT TK_SHIFT_RIGHT
%token TK_IF TK_ELSE TK_WHILE TK_DO

%start S

%left TK_PLUS TK_SUB
%left TK_MULT TK_DIV

%%

S 			: ESCOPO_GLOBAL FUNC_MAIN
			{

			}
			;

ESCOPO_GLOBAL: {
					abrirEscopo();
				}
				;

FUNC_MAIN 	: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: ESCOPO_INI COMANDOS ESCOPO_FIM
			{
				$$.traducao = $2.traducao;
			}
			;
ESCOPO_INI	: '{'
			{
				abrirEscopo();
				$$.traducao = "";
			}
			;

ESCOPO_FIM	: '}'
			{
				fecharEscopo();
				$$.traducao = "";
			}
			;

DECLARACAO	: DECLARACAOSIMPLES
			| DECLARACAOATRIBUICAO
			;

DECLARACAOSIMPLES : TK_TIPO_INT TK_ID ';'
				  {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}

				  		$$.tipo = (*mapa)[$2.label].tipo;
						$2.label = (*mapa)[$2.label].label;

						$$.label =  $2.label;
						$$.traducao = "\tint " + $$.label + ";\n";
				  }
				  | TK_TIPO_FLOAT TK_ID ';'
				  {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}

				  		$$.tipo = (*mapa)[$2.label].tipo;
						$2.label = (*mapa)[$2.label].label;

						$$.label =  $2.label;
						$$.traducao = "\tfloat " + $$.label + ";\n";
				  }
				  | TK_TIPO_CHAR TK_ID ';'
				  {
						$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "char"; 
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
						$$.traducao = "\tchar " + $$.label + ";\n";
				  }
				  | TK_TIPO_BOOL TK_ID ';'
				  {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}

				  		$$.tipo = (*mapa)[$2.label].tipo;
						$2.label = (*mapa)[$2.label].label;

						$$.label =  $2.label;
						$$.traducao = "\tint " + $$.label + ";\n";
				  }
				  ;

DECLARACAOATRIBUICAO : TK_TIPO_INT TK_ID TK_EQ TK_NUM ';'
					 {
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = "\tint " + $$.label + " = " + $4.traducao + ";\n";
					 }
					 | TK_TIPO_INT TK_ID TK_EQ NUMEXP ';'
					 {
					 	$$.label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;

					 	$$.traducao = $4.traducao + "\tint " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_FLOAT TK_ID TK_EQ TK_REAL ';'
					 {
					 	$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "float"; 
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = "\tfloat " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_FLOAT TK_ID TK_EQ NUMEXP ';'
					 {
					 	$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "float"; 
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = $4.traducao + "\tfloat " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_CHAR TK_ID TK_EQ TK_CHAR';'
					 {
					 	$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "char"; 
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = "\tchar " + $$.label + " = '" + $4.traducao + "';\n";
					 }
					 | TK_TIPO_BOOL TK_ID TK_EQ  TK_TIPO_BOOL_TRUE';'
					 {
					 	$$.label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = "\tint " + $$.label + " = 1;\n";
					 }
					 | TK_TIPO_BOOL TK_ID TK_EQ  TK_TIPO_BOOL_FALSE ';'
					 {
					 	$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = "\tint " + $$.label + " = 0;\n";
					 }
					 | TK_TIPO_BOOL TK_ID TK_EQ  BOOLEANEXP ';'
					 {
					 	$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopo($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = $4.traducao + "\tint " + $$.label + " = " + $4.label + ";\n";
					 }
					 ;

ATRIBUICAO	: TK_ID TK_EQ NUMBER ';'
			 {
			 	//Verificando se a variavel existe no escopo corrente
				$$.label = createvar();

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, $3.tipo, "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != $3.tipo && cast.resultado == "")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo " + $3.tipo);

		  		if(cast.resultado != varDeclarada->tipo)
		 			tipoAtual = cast.resultado;

		  		$$.traducao = $3.traducao + "\n\t" + varDeclarada->label + " = (" + tipoAtual + ")" + $3.label + ";\n";
			 }
			| TK_ID TK_EQ E
			{
				//Verificando se a variavel existe no escopo corrente
				$$.label = createvar();

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, $3.tipo, "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != $3.tipo && cast.resultado == "")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo " + $3.tipo);
			 	
			 	if(cast.resultado != varDeclarada->tipo)
		 			tipoAtual = cast.resultado;
			 	
			 	$$.traducao = $3.traducao + "\n\t" + varDeclarada->label + " = (" + tipoAtual + ") " + $3.label + ";\n";
			}
			| TK_ID TK_EQ TK_REAL ';'
			{
				$$.label = createvar();

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, "float", "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "float" && cast.resultado == "")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo float");
			 	
			 	if(cast.resultado != varDeclarada->tipo)
		 			tipoAtual = cast.resultado;

			 	$$.traducao = $1.traducao + " = (" + tipoAtual + ")" + $3.traducao + ";\n";
			}
			| TK_ID TK_EQ TK_CHAR';'
			{
				$$.label = createvar();

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "char")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo char");

			 	$$.traducao = $1.traducao + " = '" + $3.traducao + "';\n";
			}
			| TK_ID TK_EQ CAST ';'
			;

CAST 		: '(' TIPO ')' TK_ID ';'
			{
				string nome_variavel_temporaria_cast;
				string chave = gera_chave($2.traducao, $4.tipo, "=");
				if (mapa_cast.find(chave) != mapa_cast.end()) {
					tipo_cast cast = mapa_cast[chave];
					nome_variavel_temporaria_cast = createvar();
					$$.traducao = "\t" + $4.traducao + "\n\t" + nome_variavel_temporaria_cast + " = " + "(" + cast.resultado + ") " + $4.label + ";";
					$$.tipo = cast.resultado;
					$$.tamanho = $4.tamanho;
					$$.label = nome_variavel_temporaria_cast;
				}
			}
			| ;

TIPO 		: TK_TIPO_INT
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "int";
			}
			| TK_TIPO_FLOAT
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "float";
			}
			| TK_TIPO_BOOL
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "boolean";
			}
			| TK_TIPO_STRING
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "char";
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
			| IF
			| WHILE
			| DO
			;

E 			: NUMEXP
			{
				$$.tipo = $1.tipo;
			}
			| CHAREXP
			{
				$$.tipo = $1.tipo;	
			}
			| BOOLEANEXP
			{
				$$.tipo = $1.tipo;
			}
			| CAST
			{
				$$.tipo = $1.tipo;
			}
			;

IF 			: TK_IF '(' BOOLEANEXP ')' BLOCO
			{
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
				$5.isFunction = false;
				//Se condição for false, usar goto para pular o bloco inteiro de $5
			    $$.traducao = $3.traducao + "\n\tif (" + $3.label +" == 0) goto " + $$.blocoFim + ";\n" 
			    + $5.traducao + "\t" + $$.blocoFim + ":\n";
			}
			| TK_IF '(' BOOLEANEXP ')' BLOCO ELSE
			{
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
				$5.isFunction = false;
			    $$.traducao = "\n" + $3.traducao + 
					 "\n\t" + "if(" + $3.label + " == 0) goto " + $6.blocoIni + ";\n" + 
					 $5.traducao + 
					 "\tgoto " + $6.blocoFim +";\n" +
					 $6.traducao + 
					 "\n\t" + $6.blocoFim + ":\n";	
			}
			;

ELSE        : TK_ELSE BLOCO
			{
				$2.isFunction = false;	
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
				$$.traducao = "\n\t" + $$.blocoIni + ":\n" + $2.traducao;
			}
			| TK_ELSE IF
			{
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
				
				$$.traducao = "\n\t" + $$.blocoIni + ":\n" +
							  $2.traducao;
			}
			;

WHILE 		: TK_WHILE '(' BOOLEANEXP ')' BLOCO
			{
				$5.isFunction = false;
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
			    $$.traducao = $3.traducao + "\n\t" + $$.blocoIni + ":\n\tif (" + $3.label +" == 0) goto " + $$.blocoFim + ";\n" 
			    + $5.traducao + "\n\tgoto " + $$.blocoIni + ";\n\t" + $$.blocoFim + ":\n";
			}
			;

DO 			: TK_DO BLOCO TK_WHILE '(' BOOLEANEXP ')' ';'
			{
				$2.isFunction = false;
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
			    $$.traducao = "\n\t" + $$.blocoIni + "\n" + $5.traducao + $2.traducao + "\n\tif (" + $5.label + " == 0)" +
			    "goto " + $$.blocoFim + ";" + 	"\n\t" + "goto " + $$.blocoIni + ";" + "\n\t" + $$.blocoFim + ":\n";
			}
			;

NUMBER		: TK_REAL
			{
				$$.label = createvar();
				$$.traducao = "\tfloat "+ $$.label+ " = " + $1.traducao + ";\n";
				$$.tipo = "float";
			}
			| TK_NUM
			{
				$$.label = createvar();
				$$.traducao = "\tint "+ $$.label+ " = " + $1.traducao + ";\n";
				$$.tipo = "int";
			}
			| TK_ID
			{
				//Verificando se a variavel existe no escopo corrente
				$$.label = createvar();
				atributos* variavel = getVarNoEscopo($1.label);

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		$$.traducao = "\t" + variavel->tipo + " " + $$.label + " = " + variavel->label + ";\n";
		  		$$.tipo = variavel->tipo;
			}
			;

BOOLEANEXP	: '(' BOOLEANEXP ')' 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $2.traducao + "\tint " + $$.label + " = " + $2.label + ";\n";
			}
			| BOOLEANEXP TK_OR BOOLEANEXP 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " || " + $3.label + ";\n";
			}
			| BOOLEANEXP TK_AND BOOLEANEXP 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " && " + $3.label + ";\n";
			}
			| TK_NOT TK_ID 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = "\tint " + $$.label + " = " + $1.traducao + " == 0;\n";
			}
			| TK_NOT BOOLEANTYPE 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $2.traducao + "\tint " + $$.label + " = " + $2.label + " == 0;\n";
			}
			| TK_NOT '(' BOOLEANEXP ')' 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $3.traducao + "\tint " + $$.label + " = " + $3.label + " == 0;\n";
			}
			| LOGICALEXP
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + "\tint " + $$.label + " = " + $1.label + ";\n";
			}
			| BOOLEANTYPE
			;

BOOLEANTYPE : TK_TIPO_BOOL_TRUE
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = "\tint "+ $$.label+ " = 1;\n";
			}
			| TK_TIPO_BOOL_FALSE
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = "\tint "+ $$.label+ " = 0;\n";
			}
			;

LOGICALEXP	: '(' LOGICALEXP ')' 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $2.traducao + "\tint " + $$.label + " = " + $2.label + ";\n";
			}
			| NUMEXP TK_COMP NUMEXP 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " == " + $3.label + ";\n";
			}
			| NUMEXP TK_DIFF NUMEXP 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " != " + $3.label + ";\n";
			}
			| NUMEXP TK_LT NUMEXP 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
			}
			| NUMEXP TK_LTE NUMEXP 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " <= " + $3.label + ";\n";
			}
			| NUMEXP TK_GT NUMEXP 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
			}
			| NUMEXP TK_GTE NUMEXP 
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
			}
			;


NUMEXP		: '(' NUMEXP ')'
			{
				$$.label = createvar();
				$$.tipo = $2.tipo;
				$$.traducao = $2.traducao + "\t" + $2.tipo + " " + $$.label + " = " + $2.label + ";\n";
			}
			| '(' TIPO ')' NUMEXP
			{
				$$.label = createvar();
				$$.tipo = $2.tipo;
				$$.traducao = $4.traducao + "\t" + $$.tipo + " " + $$.label + " = " + $4.label + ";\n";
			} 
			| NUMEXP TK_PLUS NUMEXP
			{
				//Gerando o tipo de cast a partir dos numeros da operação
				$$.tipo = mapa_cast[gera_chave($1.tipo, $3.tipo, "+")].resultado;
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label + " = "+$1.label+" + "+$3.label+";\n";
			}
			| NUMEXP TK_SUB NUMEXP
			{
				//Gerando o tipo de cast a partir dos numeros da operação
				$$.tipo = mapa_cast[gera_chave($1.tipo, $3.tipo, "-")].resultado;
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label+" = "+$1.label+" - "+$3.label+";\n";
			}
			| NUMEXP TK_MULT NUMEXP
			{
				//Gerando o tipo de cast a partir dos numeros da operação
				$$.tipo = mapa_cast[gera_chave($1.tipo, $3.tipo, "*")].resultado;
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label+" = "+$1.label+" * "+$3.label+";\n";
			}
			| NUMEXP TK_DIV NUMEXP
			{
				//Gerando o tipo de cast a partir dos numeros da operação
				$$.tipo = mapa_cast[gera_chave($1.tipo, $3.tipo, "/")].resultado;
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label + " = "+$1.label+" / "+$3.label+";\n";
			}
			| NUMEXP TK_MOD NUMEXP
			{
				//Gerando o tipo de cast a partir dos numeros da operação
				$$.tipo = mapa_cast[gera_chave($1.tipo, $3.tipo, "%")].resultado;
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label+" = "+$1.label+" % "+$3.label+";\n";
			}
			| NUMEXP TK_XOR NUMEXP 
			{
				//Gerando o tipo de cast a partir dos numeros da operação
				$$.tipo = mapa_cast[gera_chave($1.tipo, $3.tipo, "^")].resultado;
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label + " = " + $1.label + " ^ " + $3.label + ";\n";
			}
			| NUMEXP TK_SHIFT_LEFT NUMEXP 
			{
				//Gerando o tipo de cast a partir dos numeros da operação
				$$.tipo = mapa_cast[gera_chave($1.tipo, $3.tipo, "<<")].resultado;
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label + " = " + $1.label + " << " + $3.label + ";\n";
			}
			| NUMEXP TK_SHIFT_RIGHT NUMEXP 
			{
				//Gerando o tipo de cast a partir dos numeros da operação
				$$.tipo = mapa_cast[gera_chave($1.tipo, $3.tipo, ">>")].resultado;
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label + " = " + $1.label + " >> " + $3.label + ";\n";
			}
			| NUMBER
			;

CHAREXP		: TK_CHAR
			{
				$$.label = createvar();
				$$.tipo = "char";
				$$.traducao = "\t"+ $$.label+ " = " + $1.traducao + ";\n";
			}
			;


%%

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