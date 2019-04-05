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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    INT = 258,
    DOUBLE = 259,
    BOOL = 260,
    CHAR = 261,
    STRING = 262,
    ARREGLO = 263,
    TRUE = 264,
    FALSE = 265,
    IMPRIMIR = 266,
    SHOW = 267,
    SI = 268,
    SINO = 269,
    PARA = 270,
    REPETIR = 271,
    ACEPTACION = 272,
    IGUAL_IGUAL = 273,
    NO_IGUAL = 274,
    MENOR_QUE = 275,
    MENOR_IGUAL = 276,
    MAYOR_QUE = 277,
    MAYOR_IGUAL = 278,
    OR = 279,
    AND = 280,
    NOT = 281,
    MAS = 282,
    MENOS = 283,
    MULTIPLICACION = 284,
    DIVISION = 285,
    POTENCIA = 286,
    COMA = 287,
    IGUAL = 288,
    PUNTO_Y_COMA = 289,
    MAS_MAS = 290,
    MENOS_MENOS = 291,
    CORCHETE_ABRE = 292,
    CORCHETE_CIERRA = 293,
    LLAVE_CIERRA = 294,
    LLAVE_ABRE = 295,
    PARENTESIS_ABRE = 296,
    PARENTESIS_CIERRA = 297,
    IDENTIFICADOR = 298,
    ENTERO = 299,
    DECIMAL = 300,
    CADENA = 301,
    CARACTER = 302,
    ERROR = 303
  };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define BOOL 260
#define CHAR 261
#define STRING 262
#define ARREGLO 263
#define TRUE 264
#define FALSE 265
#define IMPRIMIR 266
#define SHOW 267
#define SI 268
#define SINO 269
#define PARA 270
#define REPETIR 271
#define ACEPTACION 272
#define IGUAL_IGUAL 273
#define NO_IGUAL 274
#define MENOR_QUE 275
#define MENOR_IGUAL 276
#define MAYOR_QUE 277
#define MAYOR_IGUAL 278
#define OR 279
#define AND 280
#define NOT 281
#define MAS 282
#define MENOS 283
#define MULTIPLICACION 284
#define DIVISION 285
#define POTENCIA 286
#define COMA 287
#define IGUAL 288
#define PUNTO_Y_COMA 289
#define MAS_MAS 290
#define MENOS_MENOS 291
#define CORCHETE_ABRE 292
#define CORCHETE_CIERRA 293
#define LLAVE_CIERRA 294
#define LLAVE_ABRE 295
#define PARENTESIS_ABRE 296
#define PARENTESIS_CIERRA 297
#define IDENTIFICADOR 298
#define ENTERO 299
#define DECIMAL 300
#define CADENA 301
#define CARACTER 302
#define ERROR 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "parser.y" /* yacc.c:1909  */

    class nodo *nodoAST;
    char *cont;

#line 155 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
