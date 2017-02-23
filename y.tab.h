/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    TK_SWITCH = 302,
    TK_CASE = 303,
    TK_DEFAULT = 304,
    TK_DOIS_PONTOS = 305,
    TK_ANY = 306,
    TK_PLUS = 307,
    TK_SUB = 308,
    TK_MULT = 309,
    TK_DIV = 310
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
#define TK_SWITCH 302
#define TK_CASE 303
#define TK_DEFAULT 304
#define TK_DOIS_PONTOS 305
#define TK_ANY 306
#define TK_PLUS 307
#define TK_SUB 308
#define TK_MULT 309
#define TK_DIV 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
