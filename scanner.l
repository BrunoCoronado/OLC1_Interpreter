/*DEFINICIONES*/
%{
    #include "parser.h"  

    int yylex();
    void yyerror(const char *s);
%}

%option caseless
%option case-insensitive
%option yylineno
%option noyywrap

COMENTARIO_UNA_LINEA >>(.*?)\n
COMETARIO_MULTILINEA <-(.*?)->
FIN_DE_LINEA \r|\n|\r\n
ESPACIO_EN_BLANCO {FIN_DE_LINEA}|[ \t\f]
DIGITO [0-9]
TEXTO_ENTRE_COMILLAS \"([^\"]*?)\"
CARACTER '(.?)'
IDENTIFICADOR [a-z][a-z|0-9|"_"]*

%%

"int"                               { return(INT); /*printf("int %s\n",yytext);*/ }     
"double"                            { /*printf("double %s\n",yytext);*/ return(DOUBLE);}
"bool"                              { return(BOOL); /*printf("bool %s\n",yytext);*/ }
"char"                              { return(CHAR); /*printf("char %s\n",yytext);*/ }      
"string"                            { return(STRING); /*printf("string %s\n",yytext);*/ }
"arreglo"                           { return(ARREGLO); /*printf("string %s\n",yytext);*/ }    

"verdadero"                         { return(TRUE); /*printf("true %s\n",yytext);*/} 
"true"                              { return(TRUE); /*printf("true %s\n",yytext);*/} 
"falso"                             { /*printf("false %s\n",yytext);*/ return(FALSE);}        
"false"                             { /*printf("false %s\n",yytext);*/ return(FALSE);}        
                    
"imprimir"                          { return(IMPRIMIR); /*printf(" %s\n", yytext);*/}                                        
"show"                              { return(SHOW); /*printf(" %s\n", yytext);*/}        
"si"                                { return(SI); /*printf(" %s\n", yytext);*/}        
"sino"                              { return(SINO); /*printf(" %s\n", yytext);*/}        
"para"                              { return(PARA); /*printf(" %s\n", yytext);*/}        
"repetir"                           { return(REPETIR); /*printf(" %s\n", yytext);*/}            

"$"                                 { return(ACEPTACION); /*printf("$ %s\n",yytext);*/}
"=="                                { return(IGUAL_IGUAL); /*printf("== %s\n",yytext);*/}
"!="                                { return(NO_IGUAL); /*printf("!= %s\n",yytext);*/}
"<"                                 { return(MENOR_QUE); /*printf("< %s\n",yytext);*/}
"<="|"=<"                           { return(MENOR_IGUAL); /*printf("<= %s\n",yytext);*/}    
">"                                 { return(MAYOR_QUE); /*printf("> %s\n",yytext);*/}
">="|"=>"                           { return(MAYOR_IGUAL); /*printf(">= %s\n",yytext);*/}        
"||"                                { return(OR); /*printf("|| %s\n",yytext);*/}        
"&&"                                { return(AND); /*printf("&& %s\n",yytext);*/}        
"!"                                 { return(NOT); /*printf("! %s\n",yytext);*/}    
"+"                                 { return(MAS); /*printf("+ %s\n",yytext);*/}    
"-"                                 { return(MENOS); /*printf("- %s\n",yytext);*/}    
"*"                                 { return(MULTIPLICACION); /*printf("* %s\n",yytext);*/}    
"/"                                 { return(DIVISION); /*printf("/ %s\n",yytext);*/}    
"^"                                 { return(POTENCIA); /*printf("^ %s\n",yytext);*/}   
","                                 { return(COMA); /*printf(", %s\n",yytext);*/}   
"="                                 { return(IGUAL); /*printf("= %s\n",yytext);*/}   
";"                                 { /*printf(" %s\n",yytext);*/ return(PUNTO_Y_COMA); } 
"++"                                { return(MAS_MAS); /*printf("++ %s\n",yytext);*/} 
"--"                                { return(MENOS_MENOS); /*printf("-- %s\n",yytext);*/} 
"["                                 { return(CORCHETE_ABRE); /*printf("[ %s\n",yytext);*/} 
"]"                                 { return(CORCHETE_CIERRA); /*printf("] %s\n",yytext);*/} 
"}"                                 { return(LLAVE_CIERRA); /*printf("} %s\n",yytext);*/} 
"{"                                 { return(LLAVE_ABRE); /*printf(" %s\n",yytext);*/}
"("                                 { return(PARENTESIS_ABRE); /*printf(" %s\n",yytext);*/}
")"                                 { /*printf(" %s\n",yytext);*/ return(PARENTESIS_CIERRA);}
  
{IDENTIFICADOR}                     { yylval.cont = strdup(yytext); return(IDENTIFICADOR); /*printf("IDENTIFICADOR %s\n",yytext);*/}   
{DIGITO}+                           { yylval.cont = strdup(yytext); return(ENTERO); /*printf("numero %s\n",yytext);*/}    
{DIGITO}+"."{DIGITO}*               { yylval.cont = strdup(yytext); return(DECIMAL); /*printf("decimal %s\n",yytext);*/}
{TEXTO_ENTRE_COMILLAS}              { yylval.cont = strdup(yytext); return(CADENA); /*printf("texto entre comillas %s\n",yytext);*/}
{CARACTER}                          { yylval.cont = strdup(yytext); return(CARACTER); /*printf("caracter %s\n",yytext);*/}

{COMENTARIO_UNA_LINEA}              {}
{COMETARIO_MULTILINEA}              {}
{FIN_DE_LINEA}                      {}
{ESPACIO_EN_BLANCO}                 {}

.                                  { printf("Error lexico no se reconocio lexema\n"); return(ERROR);}


%%
/*CODIGO*/
