%{
#include <iostream>
#include <string>
#include <sstream>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
};
int contador = 0;
int yylex(void);
void yyerror(string);
string createvar(void);
%}

%token TK_NUM
%token TK_TIPO_FLOAT
%token TK_TIPO_DOUBLE
%token TK_TIPO_STRING
%token TK_TIPO_BOOL
%token TK_MAIN TK_ID TK_TIPO_INT
%token TK_FIM TK_ERROR
%token TK_COMP TK_LT TK_GT TK_LTE TK_GTE TK_DIFF
%token TK_OR TK_AND TK_NOT TK_XOR
%token TK_EQ TK_MOD

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

COMANDOS	: COMANDO COMANDOS
			|
			;

COMANDO 	: E ';'
			;

E 			: E TK_PLUS E
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" + "+$3.label+";\n";
			}
			| E TK_SUB E
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" - "+$3.label+";\n";
			}
			|E TK_MULT E
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" * "+$3.label+";\n";
			}
			| E TK_DIV E
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" / "+$3.label+";\n";
			}
			| E TK_MOD E
			{
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" % "+$3.label+";\n";
			}

			| E TK_COMP E {
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " == " + $3.label + ";\n";
			}
			| E TK_LT E {
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
			}
			| E TK_LTE E {
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " <= " + $3.label + ";\n";
			}
			| E TK_GT E {
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
			}
			| E TK_GTE E {
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
			}
			| E TK_DIFF E {
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " != " + $3.label + ";\n";
			}

			| E TK_OR E {
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " || " + $3.label + ";\n";
			}
			| E TK_AND E {
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " && " + $3.label + ";\n";
			}
			| E TK_XOR E {
				$$.label = createvar();
				$$.traducao = $1.traducao + $3.traducao + $$.label + " = " + $1.label + " ^ " + $3.label + ";\n";
			}

			| TK_NUM
			{
				$$.label = createvar();
				$$.traducao = "\t"+$$.label+ " = " + $1.traducao + ";\n";
			}
			| TK_ID
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