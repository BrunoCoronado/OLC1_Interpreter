#include "nodo.h"

nodo::nodo()
{
    tipo = "";
    valor = "";
    idTipo = -1;
    hijos = QList<nodo>();
}
nodo::nodo(QString tipo, QString valor, int idTipo){
    this->tipo = tipo;
    this->valor = valor;
    this->idTipo = idTipo;
    hijos = QList<nodo>();
}

void nodo::agregar(nodo nuevoNodo){
    this->hijos.append(nuevoNodo);
}

int nodo::tipoNodo(){
    return this->idTipo;
}


