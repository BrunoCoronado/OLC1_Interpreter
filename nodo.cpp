#include "nodo.h"

nodo::nodo()
{
    tipo = "";
    valor = "";
    idTipo = -1;
    numero = -1;
    fila = -1;
    columna = -1;
    hijos = QList<nodo>();
}
nodo::nodo(QString tipo, QString valor, int idTipo, int fila, int columna, int numero){
    this->tipo = tipo;
    this->valor = valor;
    this->idTipo = idTipo;
    this->numero = numero;
    this->fila = fila;
    this->columna = columna;
    hijos = QList<nodo>();
}

void nodo::agregar(nodo nuevoNodo){
    this->hijos.append(nuevoNodo)    ;
}

int nodo::tipoNodo(){
    return this->idTipo;
}


