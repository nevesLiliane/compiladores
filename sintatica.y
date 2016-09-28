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
int yylex(void);
void yyerror(string);
%}

%token TK_NUM
%token TK_TIPO_FLOAT
%token TK_TIPO_DOUBLE
%token TK_TIPO_STRING
%token TK_TIPO_BOOL
%token TK_MAIN TK_ID TK_TIPO_INT
%token TK_FIM TK_ERROR

%start S

%left '+'
%left '-'
%left '*'
%left '/'

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

E 			: E '+' E
			{
				$$.label = "temp";
				$1.label = "temp";
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" + "+$2.label+";\n";
			}
			| E '-' E
			{
				$$.label = "temp";
				$1.label = "temp";
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" - "+$2.label+";\n";
			}
			|E '*' E
			{
				$$.label = "temp";
				$1.label = "temp";
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" * "+$2.label+";\n";
			}
			| E '/' E
			{
				$$.label = "temp";
				$2.label = "temp";
				$$.traducao = $1.traducao + $3.traducao + "\t"+$$.label+" = "+$1.label+" / "+$2.label+";\n";
			}
			| TK_NUM
			{
				$$.label = "temp";
				$$.traducao = "\t"+$$.label+" = " + $1.traducao + ";\n";
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
