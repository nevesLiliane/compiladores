%{
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <list>
#include <vector> 

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
	bool isArray;
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
list<atributos*> caseTemp;
list<string> caseLabel;
list<string> caseLabelTemp;
list<string> caseTraducao;
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
%}

%token TK_NUM
%token TK_CHAR
%token TK_REAL
%token TK_STRING
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
%token TK_IF TK_ELSE TK_WHILE TK_DO TK_FOR TK_BREAK TK_BREAK_ALL TK_CONTINUE TK_ELIF
%token TK_MAIS_MAIS TK_MENOS_MENOS TK_MAIS_COMPOSTO TK_MENOS_COMPOSTO TK_MULT_COMPOSTO TK_DIV_COMPOSTO
%token TK_SWITCH TK_CASE TK_DEFAULT TK_DOIS_PONTOS
%token TK_WRITE TK_READ
%token TK_ANY

%start S

%left TK_PLUS TK_SUB
%left TK_MULT TK_DIV
%left '(' ')'

%%

S 			: ESCOPO_GLOBAL ESTRUTURA
			{
				cout << "/*Compilador AVX*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#include <stdlib.h>\n\nusing namespace std;\n\n";
				cout << $2.traducao;
			}
			;

ESCOPO_GLOBAL: {
					abrirEscopo();
					$$.traducao = "";
				}
				;

ESTRUTURA 	: DECLARACOES FUNC_MAIN
			{
				$$.traducao = $1.traducao + "\n" + $2.traducao;
			}
			| FUNC_MAIN
			{
				$$.traducao = $1.traducao;
			}
			;

FUNC_MAIN 	: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				$$.traducao = "int main(void)\n{\n" + $5.traducao + "\treturn 0;\n}\n"; 
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

DECLARACOES : DECLARACOES DECLARACAO
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			| DECLARACAO
			{
				$$.traducao = $1.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

DECLARACAO	: DECLARACAOSIMPLES
			{
				$$.traducao = $1.traducao;
			}
			| DECLARACAOATRIBUICAO
			{
				$$.traducao = $1.traducao;
			}
			;

DECLARACAOSIMPLES : TK_TIPO_INT TK_ID ';'
				  {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		} 
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

				  		$$.tipo = (*mapa)[$2.label].tipo;
						$2.label = (*mapa)[$2.label].label;

						$$.label =  $2.label;
						$$.traducao = "\tint " + $$.label + ";\n";
				  }
				  | TK_TIPO_FLOAT TK_ID ';'
				  {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		} 
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

				  		$$.tipo = (*mapa)[$2.label].tipo;
						$2.label = (*mapa)[$2.label].label;

						$$.label =  $2.label;
						$$.traducao = "\tfloat " + $$.label + ";\n";
				  }
				  | TK_TIPO_CHAR TK_ID ';'
				  {
						$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "char"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
						$$.traducao = "\tchar " + $$.label + ";\n";
				  }
				  | TK_TIPO_BOOL TK_ID ';'
				  {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

				  		$$.tipo = (*mapa)[$2.label].tipo;
						$2.label = (*mapa)[$2.label].label;

						$$.label =  $2.label;
						$$.traducao = "\tint " + $$.label + ";\n";
				  }
				  | TK_TIPO_STRING TK_ID ';'
				  {
				  		map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "string"; 
				  			(*mapa)[$2.label].stringDinamica = true; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

				  		$$.tipo = (*mapa)[$2.label].tipo;
						$2.label = (*mapa)[$2.label].label;

						$$.label =  $2.label;
						$$.traducao = "\tchar[] " + $$.label + ";\n";
				  }
				  ;

DECLARACAOATRIBUICAO : TK_TIPO_INT TK_ID TK_EQ TK_NUM ';'
					 {
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
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
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;

					 	$$.traducao = $4.traducao + "\tint " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_FLOAT TK_ID TK_EQ TK_REAL ';'
					 {
					 	$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "float"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = "\tfloat " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_FLOAT TK_ID TK_EQ NUMEXP ';'
					 {
					 	$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "float"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = $4.traducao + "\tfloat " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_CHAR TK_ID TK_EQ TK_CHAR';'
					 {
					 	$$.label = createvar();map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "char"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
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
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = "\tint " + $$.label + " = 1;\n";
					 }
					 | TK_TIPO_BOOL TK_ID TK_EQ  TK_TIPO_BOOL_FALSE ';'
					 {
					 	$$.label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = "\tint " + $$.label + " = 0;\n";
					 }
					 | TK_TIPO_BOOL TK_ID TK_EQ  BOOLEANEXP ';'
					 {
					 	$$.label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "int"; 
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.traducao = $4.traducao + "\tint " + $$.label + " = " + $4.label + ";\n";
					 }
					 | TK_TIPO_STRING TK_ID TK_EQ STRINGEXP ';'
					 {
				 		$$.label = createvar();
				 		int tamanho = $4.tamanhoString;

				 		map<string,atributos>* mapa = escopo.front();

				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = "string"; 
				  			(*mapa)[$2.label].tamanhoString = tamanho;
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	$$.tamanhoString = (*mapa)[$2.label].tamanhoString;

					 	$$.traducao = $4.traducao + "\tchar " + $$.label + "[" + to_string(tamanho) + "];\n\t" + "strncpy(" +
					 	$$.label + "," + $4.label + "," + to_string(tamanho) + ");\n";
					 }
					 | TK_ANY TK_ID TK_EQ E ';'
					 {
					 	$$.label = createvar();
					 	map<string,atributos>* mapa = escopo.front();
				  		if(varNoEscopoAtual($2.label) == false){
				  			(*mapa)[$2.label].label = createvar();
				  			(*mapa)[$2.label].tipo = $4.tipo;
				  		}
				  		else {
			  				yyerror("Já existe uma variavel com nome '" + $2.label + "' no escopo.");
				  		}

					 	$$.label = (*mapa)[$2.label].label;
					 	$$.tipo = (*mapa)[$2.label].tipo;
					 	$2.label = (*mapa)[$2.label].label;
					 	string tipo = $4.tipo;
					 	if(tipo == "boolean")
					 		tipo = "int";

					 	$$.traducao = $4.traducao + "\t" + tipo + " " + $$.label + " = " + $4.label + ";\n";
					 }
					 ;

ATRIBUICAO	: TK_ID TK_EQ NUMBER
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
				bool castImplicito = false;

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, $3.tipo, "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != $3.tipo && cast.resultado == "")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo " + $3.tipo);
			 	
			 	if(cast.resultado != varDeclarada->tipo && varDeclarada->tipo != "string")
			 	{
		 			tipoAtual = cast.resultado;
		 			castImplicito = true;
			 	}
			 	
			 	if(castImplicito)
			 	{
			 		$$.traducao = $3.traducao + "\n\t" + varDeclarada->label + " = (" + tipoAtual + ") " + $3.label + ";\n";
			 	}
			 	else
			 	{
		 			$$.traducao = $3.traducao + "\n\t" + varDeclarada->label + " = " + $3.label + ";\n";
			 	}
			}
			| TK_ID TK_EQ TK_REAL
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
			| TK_ID TK_EQ TK_CHAR
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
			| TK_ID TK_MAIS_COMPOSTO E 
			{
				$$.label = createvar();
				bool castImplicito = false;

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, $3.tipo, "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != $3.tipo && cast.resultado == "")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo " + $3.tipo);
			 	
			 	if(cast.resultado != varDeclarada->tipo && varDeclarada->tipo != "string")
			 	{
		 			tipoAtual = cast.resultado;
		 			castImplicito = true;
			 	}
			 	
			 	if(castImplicito)
			 	{
			 		string tempVar = createvar();
			 		$$.traducao = $3.traducao + "\n\t" + tempVar + " = (" + tipoAtual + ") " + $3.label + ";\n\t"
			 		+ varDeclarada->label + " = " + varDeclarada->label + " + " + tempVar + ";\n";
			 	}
			 	else
			 	{
			 		string tempVar = createvar();
		 			$$.traducao = $3.traducao + "\n\t" + tempVar + " = " + $3.label + ";\n\t" 
		 			+ varDeclarada->label + " = " + varDeclarada->label + " + " + tempVar + ";\n";
			 	}
			}
			| TK_ID TK_MENOS_COMPOSTO E 
			{
				$$.label = createvar();
				bool castImplicito = false;

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, $3.tipo, "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != $3.tipo && cast.resultado == "")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo " + $3.tipo);
			 	
			 	if(cast.resultado != varDeclarada->tipo && varDeclarada->tipo != "string")
			 	{
		 			tipoAtual = cast.resultado;
		 			castImplicito = true;
			 	}
			 	
			 	if(castImplicito)
			 	{
			 		string tempVar = createvar();
			 		$$.traducao = $3.traducao + "\n\t" + tempVar + " = (" + tipoAtual + ") " + $3.label + ";\n\t"
			 		+ varDeclarada->label + " = " + varDeclarada->label + " - " + tempVar + ";\n";
			 	}
			 	else
			 	{
			 		string tempVar = createvar();
		 			$$.traducao = $3.traducao + "\n\t" + tempVar + " = " + $3.label + ";\n\t" 
		 			+ varDeclarada->label + " = " + varDeclarada->label + " - " + tempVar + ";\n";
			 	}
			}
			| TK_ID TK_MULT_COMPOSTO E 
			{
				$$.label = createvar();
				bool castImplicito = false;

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, $3.tipo, "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != $3.tipo && cast.resultado == "")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo " + $3.tipo);
			 	
			 	if(cast.resultado != varDeclarada->tipo && varDeclarada->tipo != "string")
			 	{
		 			tipoAtual = cast.resultado;
		 			castImplicito = true;
			 	}
			 	
			 	if(castImplicito)
			 	{
			 		string tempVar = createvar();
			 		$$.traducao = $3.traducao + "\n\t" + tempVar + " = (" + tipoAtual + ") " + $3.label + ";\n\t"
			 		+ varDeclarada->label + " = " + varDeclarada->label + " * " + tempVar + ";\n";
			 	}
			 	else
			 	{
			 		string tempVar = createvar();
		 			$$.traducao = $3.traducao + "\n\t" + tempVar + " = " + $3.label + ";\n\t" 
		 			+ varDeclarada->label + " = " + varDeclarada->label + " * " + tempVar + ";\n";
			 	}
			}
			| TK_ID TK_DIV_COMPOSTO E 
			{
				$$.label = createvar();
				bool castImplicito = false;

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		tipo_cast cast = cast_possivel(varDeclarada->tipo, $3.tipo, "=");

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != $3.tipo && cast.resultado == "")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " imcompativel com o tipo " + $3.tipo);
			 	
			 	if(cast.resultado != varDeclarada->tipo && varDeclarada->tipo != "string")
			 	{
		 			tipoAtual = cast.resultado;
		 			castImplicito = true;
			 	}
			 	
			 	if(castImplicito)
			 	{
			 		string tempVar = createvar();
			 		$$.traducao = $3.traducao + "\n\t" + tempVar + " = (" + tipoAtual + ") " + $3.label + ";\n\t"
			 		+ varDeclarada->label + " = " + varDeclarada->label + " / " + tempVar + ";\n";
			 	}
			 	else
			 	{
			 		string tempVar = createvar();
		 			$$.traducao = $3.traducao + "\n\t" + tempVar + " = " + $3.label + ";\n\t" 
		 			+ varDeclarada->label + " = " + varDeclarada->label + " / " + tempVar + ";\n";
			 	}
			}
			| TK_ID TK_EQ CAST
			;



CAST 		: '(' TIPO ')' TK_ID
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
			|
			{
				$$.traducao = "";
			}
			;

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
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			| DECLARACAO
			| ATRIBUICAO ';'
			| IF
			| WHILE
			| DO
			| FOR
			| SWITCH
			| BREAK
			| BREAKALL
			| CONTINUE
			| WRITE
			| READ
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
			| STRINGEXP
			{
				$$.tipo = $1.tipo;
			}
			| CAST
			{
				$$.tipo = $1.tipo;
			}
			;
WRITE		: TK_WRITE '(' E ')'	
			{
				$$.traducao = $3.traducao + "\tcout << " + $3.label +" << endl;\n";
			}
			;
READ 		: TK_READ '(' TK_ID ')'
			{
				atributos* atrib = getVarNoEscopo($3.label);
				$$.traducao = "\tcin >> " + atrib->label + ";\n";
			}
			;
IF 			: TK_IF '(' BOOLEANEXP ')' BLOCO
			{
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
				$5.isFunction = false;
				//Se condição for false, usar goto para pular o bloco inteiro de $5
			    $$.traducao = $3.traducao + "\n\tif (" + $3.label +") goto " + $$.blocoFim + ";\n" 
			    + $5.traducao + "\t" + $$.blocoFim + ":\n";
			}
			| TK_IF '(' BOOLEANEXP ')' BLOCO ELSES
			{
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
				$5.isFunction = false;
			    $$.traducao = "\n" + $3.traducao + 
					 "\n\t" + "if(" + $3.label + ") goto " + $6.blocoIni + ";\n" + 
					 $5.traducao + 
					 "\tgoto " + $6.blocoFim +";\n" +
					 $6.traducao + 
					 "\n\t" + $6.blocoFim + ":\n";	
			}
			;

ELSES		: ELSE
			{
				$$.traducao = $1.traducao;
			}
			| ELIF
			{
				$$.traducao = $1.traducao;
			}
			;

ELIF 		: TK_ELIF '(' BOOLEANEXP ')' BLOCO
			{
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
				$$.traducao = "\n\t" + $$.blocoIni + ":\n" + $3.traducao + "\n\tif(" + $3.label + ") goto " + $$.blocoFim +
				";\n" + $5.traducao + "\n\t" + $$.blocoFim + ":";
			}
			|
			TK_ELIF '(' BOOLEANEXP ')' BLOCO ELSES
			{
				$$.jump = gerarBloco();
				$$.blocoIni = gerarInicioDeBloco($$.jump);
				$$.blocoFim = gerarFimDeBloco($$.jump);
				$$.traducao = "\n\t" + $$.blocoIni + ":\n" + $3.traducao + "\n\tif(" + $3.label + ") goto " + $6.blocoIni +
				";\n" + $5.traducao + "\n\tgoto " + $6.blocoFim + ";\n" + $6.traducao + "\n\t" + $6.blocoFim + ":\n";
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

WHILE 		: WHILE_LABEL '(' BOOLEANEXP ')' BLOCO
			{
				$5.isFunction = false;
				atributos* att = estruturasDeRepeticao.front();
				$$.jump = att->jump;
				$$.blocoIni = att->blocoIni;
				$$.blocoFim = att->blocoFim;
			    $$.traducao = $3.traducao + "\n\t" + $$.blocoIni + ":\n\tif (" + $3.label +") goto " + $$.blocoFim + ";\n" 
			    + $5.traducao + "\n\tgoto " + $$.blocoIni + ";\n\t" + $$.blocoFim + ":\n";

			    estruturasDeRepeticao.pop_front();
			}
			;

WHILE_LABEL : TK_WHILE
			{
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "while";
				estruturasDeRepeticao.push_front(att);
			}
			;

DO 			: DO_LABEL BLOCO TK_WHILE '(' BOOLEANEXP ')' ';'
			{
				$2.isFunction = false;
				atributos* att = estruturasDeRepeticao.front();
				$$.jump = att->jump;
				$$.blocoIni = att->blocoIni;
				$$.blocoFim = att->blocoFim;
			    $$.traducao = "\n\t" + $$.blocoIni + "\n" + $5.traducao + $2.traducao + "\n\tif (" + $5.label + ")" +
			    "goto " + $$.blocoFim + ";" + 	"\n\t" + "goto " + $$.blocoIni + ";" + "\n\t" + $$.blocoFim + ":\n";
			    estruturasDeRepeticao.pop_front();
			}
			;

DO_LABEL	: TK_DO
			{
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "do";
				estruturasDeRepeticao.push_front(att);
			}
			;

FOR 		:  FOR_LABEL '(' ATRIBUICAO ';' BOOLEANEXP ';' ATRIBUICAO ')' BLOCO
			{
				atributos* att = estruturasDeRepeticao.front();
				$$.jump = att->jump;
				$$.blocoIni = att->blocoIni;
				$$.blocoFim = att->blocoFim;
				$$.traducao = $3.traducao + "\n\t" + $$.blocoIni + ":\n\t" + $5.traducao + 
				"\n\tif(" + $5.label + ") goto " + $$.blocoFim + ";\n\t" + $9.traducao + "\n\n" + $7.traducao + 
				"\tgoto " + $$.blocoIni + ";\n\t" + $$.blocoFim + ":\n";

				estruturasDeRepeticao.pop_front();
			}
			;

FOR_LABEL	: TK_FOR
			{
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "for";
				estruturasDeRepeticao.push_front(att);
			}
			;

SWITCH 		: SWITCH_LABEL '(' E ')' '{' CASES '}'
			{
				list<string>::iterator i;
				$$.traducao = "";
				atributos* att = estruturasDeRepeticao.front();
	
				for(i = caseLabel.begin(); i != caseLabel.end(); i++)
				{
					$$.traducao += caseTraducao.front() + "\n\t" + caseLabelTemp.front() + " = " + $3.label + " == " + *i + ";\n";
					caseLabelTemp.pop_front();
					caseTraducao.pop_front();
				}
				
				
				$$.traducao += "\n" + $6.traducao + "\n\t" + att->blocoFim + ":\n";
				estruturasDeRepeticao.pop_front();
				caseLabel.clear();
			}
			;

CASES 		: CASE CASES
			{
				$$.traducao = $1.traducao + "\n" + $2.traducao;
			}
			| CASE
			{
				$$.traducao = $1.traducao;
			}
			| DEFAULT
			{
				$$.traducao = $1.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

CASE 		: CASE_LABEL E TK_DOIS_PONTOS COMANDOS
			{
				string label = createvar();
				atributos* att = estruturasDeRepeticao.front();

				caseLabelTemp.push_front(label);
				caseLabel.push_front($2.label);
				caseTraducao.push_front($2.traducao);

				$$.traducao += "\n\tif (!" + caseLabelTemp.front() +") goto " + att->blocoFim + ";\n\n" 
				+ $4.traducao + "\n\n\t" + att->blocoFim + ":\n";

				estruturasDeRepeticao.pop_front();
			}
			;

DEFAULT 	: TK_DEFAULT TK_DOIS_PONTOS COMANDOS
			{
				$$.traducao = $3.traducao;
			}
			;

CASE_LABEL	: TK_CASE
			{
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "case";
				estruturasDeRepeticao.push_front(att);
				$$.traducao = "";
			}
			;

SWITCH_LABEL: TK_SWITCH
			{
				atributos* att = new atributos;
				att->jump = gerarBloco();
				att->blocoIni = gerarInicioDeBloco(att->jump);
				att->blocoFim = gerarFimDeBloco(att->jump);
				att->tipo = "switch";
				estruturasDeRepeticao.push_front(att);
				$$.traducao = "";
			}
			;

BREAK 		: TK_BREAK ';'
			{
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'break' fora de blocos 'for', 'while' e 'do/while'.");

				atributos * att = estruturasDeRepeticao.front();
				$$.traducao = "\n\tgoto " + att->blocoFim + ";\n";
			}
			;

BREAKALL 	: TK_BREAK_ALL ';'
			{
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'breakall' fora de blocos 'for', 'while' e 'do/while'.");

				atributos *att = estruturasDeRepeticao.back();
				$$.traducao = "\n\tgoto " + att->blocoFim + ";\n";
			}
			;

CONTINUE 	: TK_CONTINUE ';'
			{
				if(estruturasDeRepeticao.size() < 1)
					yyerror("Não e possivel usar o comando 'continue' fora de blocos 'for', 'while' e 'do/while'.");

				atributos * att = estruturasDeRepeticao.front();
				$$.traducao = "\n\tgoto " + att->blocoIni + ";\n";
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
			| TK_ID
			{
				//Verificando se a variavel existe no escopo corrente
				$$.label = createvar();
				atributos* variavel = getVarNoEscopo($1.label);

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		$$.traducao = "\tint " + $$.label + " = " + variavel->label + ";\n";
		  		$$.tipo = variavel->tipo;
			}
			| LOGICALEXP
			{
				$$.label = createvar();
				$$.tipo = "boolean";
				$$.traducao = $1.traducao + "\tint " + $$.label + " = " + $1.label + ";\n";
			}
			| BOOLEANTYPE
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
			}
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
			| TK_ID TK_MAIS_MAIS
			{
				$$.label = createvar();

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "int" && varDeclarada->tipo != "float")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " não pode ser convertida para numero");

			 	if(varDeclarada->tipo == "int")
		 		{
		 			$$.traducao = "\t" + $$.label + " = " + varDeclarada->label + ";\n\t" + varDeclarada->label 
		 			+ " = " + varDeclarada->label + " + 1;\n";
		 		}
		 		else
		 		{
		 			$$.traducao = "\t" + $$.label + " = " + varDeclarada->label + ";\n\t" + varDeclarada->label 
		 			+ " = " + varDeclarada->label + " + 1.0;\n";
		 		}

		 		$$.tipo = varDeclarada->tipo;
			}
			| TK_ID TK_MENOS_MENOS
			{
				$$.label = createvar();

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "int" && varDeclarada->tipo != "float")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " não pode ser convertida para numero");

			 	if(varDeclarada->tipo == "int")
		 		{
		 			$$.traducao = "\t" + $$.label + " = " + varDeclarada->label + ";\n\t" + varDeclarada->label + " = " 
		 			+ varDeclarada->label + " - 1;\n";
		 		}
		 		else
		 		{
		 			$$.traducao = "\t" + $$.label + " = " + varDeclarada->label + ";\n\t" + varDeclarada->label 
		 			+ " = " + varDeclarada->label + " - 1.0;\n";
		 		}

		 		$$.tipo = varDeclarada->tipo;
			}
			| TK_MAIS_MAIS TK_ID
			{
				$$.label = createvar();

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "int" && varDeclarada->tipo != "float")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " não pode ser convertida para numero");

			 	if(varDeclarada->tipo == "int")
		 		{
		 			$$.traducao = "\t" + varDeclarada->label + " = " + varDeclarada->label + " + 1;\n\t" + $$.label + " = " + varDeclarada->label + ";\n";
		 		}
		 		else
		 		{
		 			$$.traducao = "\t" + varDeclarada->label + " = " + varDeclarada->label + " + 1.0;\n\t" + $$.label + " = " + varDeclarada->label + ";\n";
		 		}

		 		$$.tipo = varDeclarada->tipo;
			}
			| TK_MENOS_MENOS TK_ID
			{
				$$.label = createvar();

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		atributos* varDeclarada = getVarNoEscopo($1.label);
		  		string tipoAtual = varDeclarada->tipo;

		  		//TODO:Fazer cast implicito se possivel
		  		if(varDeclarada->tipo != "int" && varDeclarada->tipo != "float")
		  			yyerror("Variavel '" + $1.label +"' do tipo " + varDeclarada->tipo + " não pode ser convertida para numero");

			 	if(varDeclarada->tipo == "int")
		 		{
		 			$$.traducao = "\t" + varDeclarada->label + " = " + varDeclarada->label + " - 1;\n\t" + $$.label + " = " + varDeclarada->label + ";\n";
		 		}
		 		else
		 		{
		 			$$.traducao = "\t" + varDeclarada->label + " = " + varDeclarada->label + " - 1.0;\n\t" + $$.label + " = " + varDeclarada->label + ";\n";
		 		}

		 		$$.tipo = varDeclarada->tipo;
			}
			| NUMBER
			{
				$$.tipo = $1.tipo;
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			;

CHAREXP		: TK_CHAR
			{
				$$.label = createvar();
				$$.tipo = "char";
				$$.traducao = "\t"+ $$.label+ " = " + $1.traducao + ";\n";
			}
			;

STRINGEXP	: STRINGEXP TK_PLUS STRINGEXP
			{
				$$.label = createvar();
				$$.tipo = "string";
				int tamanho = $1.tamanhoString + $3.tamanhoString;
				$$.tamanhoString = tamanho;
				$$.traducao = $1.traducao + $3.traducao + "\n\tchar " + $$.label + "[" + to_string(tamanho) + "];\n" + 
				"\tstrncpy(" + $$.label + "," + $1.label + "," + to_string($1.tamanhoString) + ");\n" +
				"\tstrncpy(" + $$.label + " + " + to_string($1.tamanhoString + 1) + "," + $3.label + "," + to_string($3.tamanhoString) + ");\n";
			}
			| TK_STRING
			{
				$$.label = createvar();
				$$.tipo = "string";
				int tamanho = $1.traducao.size() - 1;
				$$.tamanhoString = tamanho;
				$$.traducao = "\n\tchar " + $$.label + "[" + to_string(tamanho) + "];\n" + 
				"\tstrncpy(" + $$.label + "," + $1.traducao + "," + to_string(tamanho) + ");\n";
			}
			| TK_ID
			{
				//Verificando se a variavel existe no escopo corrente
				$$.label = createvar();
				atributos* variavel = getVarNoEscopo($1.label);

		  		if(varNoEscopo($1.label) == false) 
		  			yyerror("Variável '" + $1.label + "' não declarada no bloco.");

		  		$$.traducao = "\n\tchar " + $$.label + "[" + to_string(variavel->tamanhoString) + "];" +  
		  		"\n\tstrncpy(" + $$.label + "," + variavel->label + "," + to_string(variavel->tamanhoString) + ");\n";

		  		$$.tipo = variavel->tipo;
		  		$$.tamanhoString = variavel->tamanhoString;
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
