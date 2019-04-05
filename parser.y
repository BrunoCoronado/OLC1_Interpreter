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

    int yyerror(const char* mens)
    {
        std::cout << mens <<" no se reconocio " <<" "<<yytext << " en linea "  << yylineno << std::endl;
        return 0;
    }
%}

%locations

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
%token<cont> ERROR

%type<nodoAST> A;
%type<nodoAST> B;
%type<nodoAST> C;
%type<nodoAST> C0;
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
%type<nodoAST> M0;
%type<nodoAST> M1;
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
            nodo *n = new nodo("aceptacion", "$", 0);
            raizAST->agregar(*n);
        }   
    |ACEPTACION
        {
            nodo *n = new nodo("aceptacion", "$", 0);
            raizAST->agregar(*n);
        }
;

B:  B C
        {
            raizAST->agregar(*$2);
            $$ = $1;
        }
    |C
        {
            raizAST->agregar(*$1);
            $$ = $1;
        }
;

C0: C0 C
        {
            nodo *n = new nodo("C0", "C0", 0);
            n->agregar(*$1);
            n->agregar(*$2);
            $$ = n;
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
            nodo *n = new nodo("igual", "=", 11);
            n->agregar(*$4);
            $1->agregar(*n);
            $$ = $1;
        }
    |D0 E PUNTO_Y_COMA
        {
            $1->agregar(*$2);
            $$ = $1;
        }
    |D0 ARREGLO E G IGUAL H PUNTO_Y_COMA
        {
            $1->agregar(*$3);
            $1->agregar(*$4);
            nodo *n = new nodo("igual", "=", 11);
            n->agregar(*$6);
            $1->agregar(*n);
            $$ = $1;
        }
    |D0 ARREGLO E G PUNTO_Y_COMA
        {
            $1->agregar(*$3);
            $1->agregar(*$4);
            $$ = $1;
        }
;

D0: INT
        {
            $$ = new nodo("tipo de dato", "int", 50);
        }
    |DOUBLE
        {
            $$ = new nodo("tipo de dato", "double", 51);
        }
    |BOOL
        {
            $$ = new nodo("tipo de dato", "bool", 52);
        }
    |CHAR 
        {
            $$ = new nodo("tipo de dato", "char", 53);
        }
    |STRING 
        {
            $$ = new nodo("tipo de dato", "string", 54);
        }
;

E:  E COMA E
        {
            nodo *padre = new nodo("coma", ",", 10); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |IDENTIFICADOR
        {
            $$ = new nodo("identificador", $1, 1);
            free($1);
        }
;

F:  F MAS F
        {
            nodo *padre = new nodo("aritmetico", "+", 25); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MENOS F
        {
            nodo *padre = new nodo("aritmetico", "-", 21); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MULTIPLICACION F
        {
            nodo *padre = new nodo("aritmetico", "*", 24); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F DIVISION F
        {
            nodo *padre = new nodo("aritmetico", "/", 23); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F POTENCIA F
        {
            nodo *padre = new nodo("aritmetico", "^", 22); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |MENOS F
        {
            nodo *padre = new nodo("aritmetico", "-", 21); 
            padre->agregar(*$2);
            $$ = padre;
        }
    |F AND F
        {
            nodo *padre = new nodo("logico", "&&", 20); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F OR F
        {
            nodo *padre = new nodo("logico", "||", 19); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |NOT F
        {
            nodo *padre = new nodo("logico", "!", 18); 
            padre->agregar(*$2);
            $$ = padre;
        }
    |F IGUAL_IGUAL F
        {
            nodo *padre = new nodo("relacional", "==", 17); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F NO_IGUAL F
        {
            nodo *padre = new nodo("relacional", "!=", 16); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MENOR_QUE F
        {
            nodo *padre = new nodo("relacional", "<", 15); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MAYOR_QUE F
        {
            nodo *padre = new nodo("relacional", ">", 14); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MENOR_IGUAL F
        {
            nodo *padre = new nodo("relacional", "<=", 13); 
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |F MAYOR_IGUAL F
        {
            nodo *padre = new nodo("relacional", ">=", 12); 
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
            $$ = new nodo("entero", $1, 60);
            free($1);
        }
    |DECIMAL
        {
            $$ = new nodo("decimal", $1, 59);
            free($1);
        }
    |CARACTER
        {
            $$ = new nodo("caracter", $1, 58);
            free($1);
        }
    |CADENA
        {
            $$ = new nodo("cadena", $1, 57);
            free($1);
        }
    |TRUE
        {
            $$ = new nodo("true", "true", 56);
        }
    |FALSE
        {
            $$ = new nodo("false", "false", 55);
        }
    |IDENTIFICADOR
        {
            $$ = new nodo("identificador", $1, 1);
            free($1);
        }
    |IDENTIFICADOR CORCHETE_ABRE F CORCHETE_CIERRA
        {
            nodo *padre = new nodo("identificador", $1, 1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |IDENTIFICADOR CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA
        {
            nodo *padre = new nodo("identificador", $1, 1);
            padre->agregar(*$3);
            padre->agregar(*$6);
            $$ = padre;
        }
    |IDENTIFICADOR CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA
        {
            nodo *padre = new nodo("identificador", $1, 1);
            padre->agregar(*$3);
            padre->agregar(*$6);
            padre->agregar(*$9);
            $$ = padre;
        }
;

G:  CORCHETE_ABRE F CORCHETE_CIERRA 
        {
            nodo *padre = new nodo("arreglo", "arreglo", 2); 
            padre->agregar(*$2);
            $$ = padre;   
        }
    |CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA 
        {
            nodo *padre = new nodo("arreglo", "arreglo", 2); 
            padre->agregar(*$2);
            padre->agregar(*$5);
            $$ = padre;   
        }
    |CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA CORCHETE_ABRE F CORCHETE_CIERRA 
        {
            nodo *padre = new nodo("arreglo", "arreglo", 2); 
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
            nodo *padre = new nodo("coma", ",", 10); 
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
            nodo *padre = new nodo("coma", ",", 10); 
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
            nodo *padre = new nodo("coma", ",", 10); 
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
            nodo *padre = new nodo("identificador", $1, 1);
            nodo *n = new nodo("igual", "=", 11);
            n->agregar(*$3);
            padre->agregar(*n);
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
           $$ = new nodo("mas mas", "++", 26);
        }
    |MENOS_MENOS
        {
           $$ = new nodo("menos menos", "--", 27);
        }
;

J1: IDENTIFICADOR
        {
            $$ = new nodo("identificador", $1, 1);
        }
    |DECIMAL
        {
            $$ = new nodo("decimal", $1, 59);
        }
    |ENTERO
        {
            $$ = new nodo("entero", $1, 60);
        }
    |CARACTER
        {
            $$ = new nodo("caracter", $1, 58);
        }
;

K:  IMPRIMIR PARENTESIS_ABRE F PARENTESIS_CIERRA PUNTO_Y_COMA
        {
            nodo *padre = new nodo("imprimir", "imprimir", 70);
            padre->agregar(*$3);
            $$ = padre;
        }
    |SHOW PARENTESIS_ABRE F COMA F PARENTESIS_CIERRA PUNTO_Y_COMA
        {
            nodo *padre = new nodo("show", "show", 71);
            padre->agregar(*$3);
            padre->agregar(*$5);
            $$ = padre;
        }
;

L:  L0 
        {
            $$ = $1;
        }
    |L0 SINO LLAVE_ABRE C0 LLAVE_CIERRA   
        {
            nodo *n = new nodo("sino", "sino", 73);
            n->agregar(*$4);
            $1->agregar(*n);
            $$ = $1;   
        }
    |L0 SINO L1 
        {
            //nodo *n = new nodo("sino", "sino", 73);
            //$1->agregar(*n);
            $1->agregar(*$3);
            $$ = $1;
        }
    |L0 SINO L1 SINO LLAVE_ABRE C0 LLAVE_CIERRA  
        {   
            //nodo *n1 = new nodo("sino", "sino", 73);
            //$1->agregar(*n1);
            $1->agregar(*$3);
            nodo *n2 = new nodo("sino", "sino", 73);
            n2->agregar(*$6);
            $1->agregar(*n2);
            $$ = $1;
        }
;

L0: SI PARENTESIS_ABRE F PARENTESIS_CIERRA LLAVE_ABRE C0 LLAVE_CIERRA
        {
            nodo *padre = new nodo("si", "si", 72);
            padre->agregar(*$3);
            padre->agregar(*$6);
            $$ = padre;
        }
;

L1: L1 SINO L1
        {
            nodo *padre = new nodo("sino", "sino", 73);
            padre->agregar(*$1);
            padre->agregar(*$3);
            $$ = padre;
        }
    |L0
        {
            $$ = $1;
        }
;

M:  PARA PARENTESIS_ABRE M0 F PUNTO_Y_COMA M1 PARENTESIS_CIERRA LLAVE_ABRE C0 LLAVE_CIERRA 
    {
        nodo *padre = new nodo("para", "para", 74);
        padre->agregar(*$3);
        padre->agregar(*$4);
        padre->agregar(*$9);
        padre->agregar(*$6);
        $$ = padre;
    }
;

M0: D
        {
            $$ = $1;
        }
    |IDENTIFICADOR IGUAL F PUNTO_Y_COMA
        {
            nodo *padre = new nodo("identificador", $1, 1);
            nodo *n = new nodo("igual", "=", 11);
            n->agregar(*$3);
            padre->agregar(*n);
            $$ = padre;
        }
;

M1: J1 MAS_MAS 
        {
            $$ = new nodo("mas mas", "++", 26);
            $$->agregar(*$1);
        }
;

N: REPETIR PARENTESIS_ABRE F PARENTESIS_CIERRA LLAVE_ABRE C0 LLAVE_CIERRA
    {
        nodo *padre = new nodo("repetir", "repetir", 75);
        padre->agregar(*$3);
        padre->agregar(*$6);
        $$ = padre;
    }
;

%%
/*codigo adicional C*/