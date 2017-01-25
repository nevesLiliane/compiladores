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
"char"		{return TK_TIPO_STRING;}
"boolean"	{return TK_TIPO_BOOL;}

"true"		{return TK_TIPO_BOOL_TRUE;}
"false"		{return TK_TIPO_BOOL_FALSE;}

[(){}[\];,]	{ return *yytext; }

"+"			{ return TK_PLUS; }
"-"			{ return TK_SUB; }
"*"			{ return TK_MULT; }
"/"			{ return TK_DIV; }
"="			{ return TK_EQ; }
"%"			{ return TK_MOD; }

"=="		{ return TK_COMP; }
"<"			{ return TK_LT; }
">"			{ return TK_GT; }
"<="		{ return TK_LTE; }
">="		{ return TK_GTE; }
"!="		{ return TK_DIFF; }

"&&"		{ return TK_AND; }
"^"			{ return TK_XOR; }
"||"		{ return TK_OR; }
"!"			{ return TK_NOT; }
"<<"		{ return TK_SHIFT_LEFT; }
">>"		{ return TK_SHIFT_RIGHT; }

"if"		{ return TK_IF; }
"else"		{ return TK_ELSE; }
"while"		{ return TK_WHILE; }

{NUM}		{ yylval.traducao = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{CHAR}		{ yylval.label = yytext; return TK_CHAR; }
{REAL}		{ yylval.traducao = yytext; return TK_REAL; }

.			{ *yytext; }

%%
