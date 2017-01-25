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
    TK_TIPO_FLOAT = 261,
    TK_TIPO_DOUBLE = 262,
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
    TK_PLUS = 289,
    TK_SUB = 290,
    TK_MULT = 291,
    TK_DIV = 292
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_CHAR 259
#define TK_REAL 260
#define TK_TIPO_FLOAT 261
#define TK_TIPO_DOUBLE 262
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
#define TK_PLUS 289
#define TK_SUB 290
#define TK_MULT 291
#define TK_DIV 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
