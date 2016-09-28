%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}
"float"		{return TK_TIPO_FLOAT;}
"double"	{return TK_TIPO_DOUBLE;}
"string"	{return TK_TIPO_STRING;}
"boolean"	{return TK_TIPO_BOOL;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

{NUM}		{ yylval.traducao = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%