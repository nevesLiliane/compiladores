%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
ESPECIAIS [!?.,;:]

CARACTERE {LETRA}|{NUM}|{ESPECIAIS}

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*
STRING 		\'{DELIM}*{CARACTERE}+({DELIM}*{CARACTERE}+)*{DELIM}*\'|\"{DELIM}*{CARACTERE}+({DELIM}*{CARACTERE}+)*{DELIM}*\"

%%

"\n"		{}

{DELIM} 	{}

"main"		{ return TK_MAIN; }

"int"		{ return TK_TIPO_INT; }
"float"		{ return TK_TIPO_FLOAT; }
"char"		{ return TK_TIPO_CHAR; }
"boolean"	{ return TK_TIPO_BOOL; }
"string"	{ return TK_TIPO_STRING; }

"true"		{ return TK_TIPO_BOOL_TRUE; }
"false"		{ return TK_TIPO_BOOL_FALSE; }

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
"do"		{ return TK_DO; }
"for"		{ return TK_FOR; }
"break"		{ return TK_BREAK; }
"continue"	{ return TK_CONTINUE; }

{NUM}		{ yylval.traducao = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{CHAR}		{ yylval.label = yytext; return TK_CHAR; }
{REAL}		{ yylval.traducao = yytext; return TK_REAL; }
{STRING}	{ yylval.traducao = yytext; return TK_STRING; }

.			{ *yytext; }

%%
