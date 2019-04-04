#ifndef AST_H
#define AST_H

#include <iostream>
#include <fstream>

#include "nodo.h"

using namespace  std;

class ast
{
private:
    nodo *raiz;
    string conexiones = "", hijos = "";
    int contadorNodos = 0;
    ofstream archivo;

public:
    ast();

    ast(nodo *raiz);
    void graficar();
    void graficarHijos(string padre, nodo hijo);
};

#endif // AST_H
