/*declaraciones C*/
%{
    #include "scanner.h"
    #include <cstdio>
    #include <iostream>
    #include <QString>

    using namespace std;

    #include "nodo.h"; 

    
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
    extern char *yytext;

    extern nodo *raizAST;

    int contadorTokens = 0;

    int yyerror(const char* mens)
    {
        std::cout << mens <<" no se reconocio " <<" "<<yytext<< std::endl;
        return 0;
    }
%}

%union{
    class nodo *nodoAST;
    char *cont;
}

%token INT
%token DOUBLE
%token BOOL
%token CHAR
%token STRING
%token ARREGLO
%token TRUE
%token FALSE
%token IMPRIMIR
%token SHOW
%token SI
%token SINO
%token PARA
%token REPETIR
%token ACEPTACION
%token IGUAL_IGUAL
%token NO_IGUAL
%token MENOR_QUE
%token MENOR_IGUAL
%token MAYOR_QUE
%token MAYOR_IGUAL
%token OR
%token AND
%token NOT
%token MAS
%token MENOS
%token MULTIPLICACION
%token DIVISION
%token POTENCIA
%token COMA
%token IGUAL
%token PUNTO_Y_COMA
%token MAS_MAS
%token MENOS_MENOS
%token CORCHETE_ABRE
%token CORCHETE_CIERRA
%token LLAVE_CIERRA
%token LLAVE_ABRE
%token PARENTESIS_ABRE
%token PARENTESIS_CIERRA
%token<cont> IDENTIFICADOR
%token<cont> ENTERO
%token<cont> DECIMAL
%token<cont> CADENA
%token<cont> CARACTER

%type<nodoAST> A;
%type<nodoAST> B;
%type<nodoAST> C;
%type<nodoAST> D;
%type<nodoAST> D0;
%type<nodoAST> E; 
%type<nodoAST> F;
%type<nodoAST> G;
%type<nodoAST> H;
%type<nodoAST> H1;
%type<nodoAST> H2;
%type<nodoAST> I;
%type<nodoAST> J;
%type<nodoAST> J0;
%type<nodoAST> J1;
%type<nodoAST> K;
%type<nodoAST> L;
%type<nodoAST> L0;
%type<nodoAST> L1;
%type<nodoAST> M;
%type<nodoAST> N;

%left COMA SINO
%left OR
%left AND
%left NOT
%left IGUAL_IGUAL NO_IGUAL MENOR_QUE MENOR_IGUAL MAYOR_QUE MAYOR_IGUAL
%left MAS MENOS
%left DIVISION MULTIPLICACION
%left POTENCIA

%start A

%%
/*declaraciones Bison*/

A:  B ACEPTACION
        {
            nodo *inicio = new nodo("raiz", "raiz", 0, 0, 0, contadorTokens++);
            nodo *n = new nodo("aceptacion", "$", 0, @2.first_line, @2.first_column, contadorTokens++);
            inicio->agregar(*$1);
            inicio->agregar(*n);
            raizAST = inicio;
        }   
    |ACEPTACION
        {
            nodo *inicio = new nodo("raiz", "raiz", 0, 0, 0, contadorTokens++);
            nodo *n = new nodo("aceptacion", "$", 0, @1.first_line, @1.first_column, contadorTokens++);
            inicio->agregar(*n);
            raizAST = inicio;
        }
;

B:  B C
        {
            $1->agregar(*$2);
            $$ = $1;
        }
    |C
        {
            $$ = $1;
        }
;

C:  D
        {
            $$ = $1;
        }
    |J
        {
            $$ = $1;
        }
    |K
        {
            $$ = $1;
        }
    |L
        {
            $$ = $1;
        }
    |M
        {
            $$ = $1;
        }
    |N
        {
            $$ = $1;
        }
;

D:  D0 E IGUAL F PUNTO_Y_COMA
        {
            $1->agregar(*$2);
            nodo *n = new nodo("igual", "=", 11, @3.first_line, @3.first_column, contadorTokens++);
            n->agregar(*$4);
            $1->agregar(*n);
            //$1->agregar(*$4);
            $$ = $1;
        }
    |D0 E PUNTO_Y_COMA
        {
            $1->agregar(*$2);
            $$ = $1;
        }
    |D0 ARREGLO E G IGUAL H PUNTO_Y_COMA
        {
            $4->agregar(*$3);
            $4->agregar(*$6);
            $1->agregar(*$4);
            $$ = $1;
        }
    |D0 ARREGLO E G PUNTO_Y_COMA
        {
            $4->agregar(*$3);
            $1->agregar(*$4);
            $$ = $1;
        }
;

D0: INT
        {
            $$ = new nodo("tipo de dato", "int", 50, @1.first_line, @1.first_column, contadorTokens++);
        }
    |DOUBLE
        {
            $$ = new nodo("tipo de dato", "double", 51, @1.first_line, @1.first_column, contadorTokens++);
        }
    |BOOL
        {
            $$ = new nodo("tipo de dato", "bool", 52, @1.first_line, @1.first_column, contadorTokens++);
        }
    |CHAR 
        {
            $$ = new nodo("tipo de dato", "char", 53, @1.first_line, @1.first_column, contadorTokens++);
        }
    |STRING 
        {
            $$ = new nodo("tipo de dato", "string", 54, @1.first_line, @1.first_column, contadorTokens++);
        }
;

E:  E COMA E
        {
            nodo *padre = new nodo("coma", ",", 10, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |IDENTIFICADOR
        {
            $$ = new nodo("identificador", $1, 1, @1.first_line, @1.first_column, contadorTokens++);
            free($1);
        }
;

F:  F MAS F
        {
            nodo *padre = new nodo("mas", "+", 25, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MENOS F
        {
            nodo *padre = new nodo("menos", "-", 21, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MULTIPLICACION F
        {
            nodo *padre = new nodo("multiplicacion", "*", 24, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F DIVISION F
        {
            nodo *padre = new nodo("division", "/", 23, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F POTENCIA F
        {
            nodo *padre = new nodo("potencia", "^", 22, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |MENOS F
        {
            nodo *padre = new nodo("menos", "-", 21, @1.first_line, @1.first_column, contadorTokens++); 
            padre->agregar(*$2);
            $$ = padre;
        }
    |F AND F
        {
            nodo *padre = new nodo("and", "&&", 20, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F OR F
        {
            nodo *padre = new nodo("or", "||", 19, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |NOT F
        {
            nodo *padre = new nodo("not", ">=", 18, @1.first_line, @1.first_column, contadorTokens++); 
            padre->agregar(*$2);
            $$ = padre;
        }
    |F IGUAL_IGUAL F
        {
            nodo *padre = new nodo("igual igual", "==", 17, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F NO_IGUAL F
        {
            nodo *padre = new nodo("no igual", "!=", 16, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MENOR_QUE F
        {
            nodo *padre = new nodo("menor que", ">=", 15, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MAYOR_QUE F
        {
            nodo *padre = new nodo("mayor que", ">", 14, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MENOR_IGUAL F
        {
            nodo *padre = new nodo("menor igual", "<=", 13, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MAYOR_IGUAL F
        {
            nodo *padre = new nodo("mayor igual", ">=", 12, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |PARENTESIS_ABRE F PARENTESIS_CIERRA
        {
            $$ = $2;
        }
    |ENTERO
        {
            $$ = new nodo("entero", $1, 60, @1.first_line, @1.first_column, contadorTokens++);
            free($1);
        }
    |DECIMAL
        {
            $$ = new nodo("decimal", $1, 59, @1.first_line, @1.first_column, contadorTokens++);
        }
    |CARACTER
        {
            $$ = new nodo("caracter", $1, 58, @1.first_line, @1.first_column, contadorTokens++);
        }
    |CADENA
        {
            $$ = new nodo("cadena", $1, 57, @1.first_line, @1.first_column, contadorTokens++);
        }
    |TRUE
        {
            $$ = new nodo("true", "true", 56, @1.first_line, @1.first_column, contadorTokens++);
        }
    |FALSE
        {
            $$ = new nodo("false", "false", 55, @1.first_line, @1.first_column, contadorTokens++);
        }
    |IDENTIFICADOR
        {
            $$ = new nodo("identificador", $1, 1, @1.first_line, @1.first_column, contadorTokens++);
        }
    |IDENTIFICADOR CORCHETE_ABRE F CORCHETE_CIERRA
        {
            nodo *padre = new nodo("identificador", $1, 1, @1.first_line, @1.first_column, contadorTokens++);
            padre->agregar(*$3);
            $$ = padre;
        }
    |IDENTIFICADOR CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA
        {
            nodo *padre = new nodo("identificador", $1, 1, @1.first_line, @1.first_column, contadorTokens++);
            padre->agregar(*$3);
            padre->agregar(*$6);
            $$ = padre;
        }
    |IDENTIFICADOR CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA
        {
            nodo *padre = new nodo("identificador", $1, 1, @1.first_line, @1.first_column, contadorTokens++);
            padre->agregar(*$3);
            padre->agregar(*$6);
            padre->agregar(*$9);
            $$ = padre;
        }
;

G:  CORCHETE_ABRE F CORCHETE_CIERRA 
        {
            nodo *padre = new nodo("arreglo", "arreglo", 2, @1.first_line, @1.first_column, contadorTokens++); 
            padre->agregar(*$2);
            $$ = padre;   
        }
    |CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA 
        {
            nodo *padre = new nodo("arreglo", "arreglo", 2, @1.first_line, @1.first_column, contadorTokens++); 
            padre->agregar(*$2);
            padre->agregar(*$5);
            $$ = padre;   
        }
    |CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA 
        {
            nodo *padre = new nodo("arreglo", "arreglo", 2, @1.first_line, @1.first_column, contadorTokens++); 
            padre->agregar(*$2);
            padre->agregar(*$5);
            padre->agregar(*$8);
            $$ = padre;   
        }
;

H:  LLAVE_ABRE H1 LLAVE_CIERRA
        {
            $$ = $2;
        }
    |LLAVE_ABRE I LLAVE_CIERRA
        {
            $$ = $2;
        }
;

H1: H1 COMA H1
        {
            nodo *padre = new nodo("coma", ",", 10, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |LLAVE_ABRE H2 LLAVE_CIERRA
        {
            $$ = $2;
        }
    |LLAVE_ABRE I LLAVE_CIERRA
        {
            $$ = $2;
        }
;

H2: H2 COMA H2
        {
            nodo *padre = new nodo("coma", ",", 10, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |LLAVE_ABRE I LLAVE_CIERRA
        {
            $$ = $2;
        }
;

I:  I COMA I
        {
            nodo *padre = new nodo("coma", ",", 10, @2.first_line, @2.first_column, contadorTokens++); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F
        {
            $$ = $1;
        }
;

J:  IDENTIFICADOR IGUAL F PUNTO_Y_COMA
        {
            nodo *padre = new nodo("identificador", $1, 1, @1.first_line, @1.first_column, contadorTokens++);
            nodo *n = new nodo("igual", "=", 11, @2.first_line, @2.first_column, contadorTokens++);
            padre->agregar(*n);
            padre->agregar(*$3);
            $$ = padre;
        }
    |J1 J0 PUNTO_Y_COMA
        {
            $2->agregar(*$1);
            $$ = $2;
        }
;

J0: MAS_MAS
        {
           $$ = new nodo("mas mas", "++", 26, @1.first_line, @1.first_column, contadorTokens++);
        }
    |MENOS_MENOS
        {
           $$ = new nodo("menos menos", "--", 27, @1.first_line, @1.first_column, contadorTokens++);
        }
;

J1: IDENTIFICADOR
        {
            $$ = new nodo("identificador", $1, 1, @1.first_line, @1.first_column, contadorTokens++);
        }
    |DECIMAL
        {
            $$ = new nodo("decimal", $1, 59, @1.first_line, @1.first_column, contadorTokens++);
        }
    |ENTERO
        {
            $$ = new nodo("entero", $1, 60, @1.first_line, @1.first_column, contadorTokens++);
        }
    |CARACTER
        {
            $$ = new nodo("caracter", $1, 58, @1.first_line, @1.first_column, contadorTokens++);
        }
;

K:  IMPRIMIR PARENTESIS_ABRE F PARENTESIS_CIERRA PUNTO_Y_COMA
        {
            nodo *padre = new nodo("imprimir", "imprimir", 70, @1.first_line, @1.first_column, contadorTokens++);
            padre->agregar(*$3);
            $$ = padre;
        }
    |SHOW PARENTESIS_ABRE F COMA F PARENTESIS_CIERRA PUNTO_Y_COMA
        {
            nodo *padre = new nodo("show", "show", 71, @1.first_line, @1.first_column, contadorTokens++);
            padre->agregar(*$3);
            padre->agregar(*$5);
            $$ = padre;
        }
;

L:  L0 
        {
            $$ = $1;
        }
    |L0 SINO L1 
        {
            nodo *n = new nodo("sino", "sino", 73, @2.first_line, @2.first_column, contadorTokens++);
            $1->agregar(*n);
            $1->agregar(*$3);
            $$ = $1;
        }
    |L0 SINO LLAVE_ABRE C LLAVE_CIERRA   
        {
            nodo *n = new nodo("sino", "sino", 73, @2.first_line, @2.first_column, contadorTokens++);
            $1->agregar(*n);
            $1->agregar(*$4);
            $$ = $1;   
        }
    |L0 SINO L1 SINO LLAVE_ABRE C LLAVE_CIERRA  
        {   
            nodo *n1 = new nodo("sino", "sino", 73, @2.first_line, @2.first_column, contadorTokens++);
            $1->agregar(*n1);
            $1->agregar(*$3);
            nodo *n2 = new nodo("sino", "sino", 73, @2.first_line, @2.first_column, contadorTokens++);
            $1->agregar(*n2);
            $1->agregar(*$6);
            $$ = $1;
        }
;

L0: SI PARENTESIS_ABRE F PARENTESIS_CIERRA LLAVE_ABRE C LLAVE_CIERRA
        {
            nodo *padre = new nodo("si", "si", 72, @1.first_line, @1.first_column, contadorTokens++);
            padre->agregar(*$3);
            padre->agregar(*$6);
            $$ = padre;
        }
;

L1: L1 SINO L1
        {
            nodo *padre = new nodo("sino", "sino", 73, @2.first_line, @2.first_column, contadorTokens++);
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |L0
        {
            $$ = $1;
        }
;

M:  PARA PARENTESIS_ABRE F PUNTO_Y_COMA F PUNTO_Y_COMA F PARENTESIS_CIERRA LLAVE_ABRE C LLAVE_CIERRA 
    {
        nodo *padre = new nodo("para", "para", 74, @1.first_line, @1.first_column, contadorTokens++);
        padre->agregar(*$3);
        padre->agregar(*$5);
        padre->agregar(*$7);
        padre->agregar(*$10);
        $$ = padre;
    }
;

N: REPETIR PARENTESIS_ABRE F PARENTESIS_CIERRA LLAVE_ABRE C LLAVE_CIERRA
    {
        nodo *padre = new nodo("repetir", "repetir", 75, @1.first_line, @1.first_column, contadorTokens++);
        padre->agregar(*$3);
        padre->agregar(*$6);
        $$ = padre;
    }
;

%%
/*codigo adicional C*/