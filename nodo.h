#ifndef NODO_H
#define NODO_H

#include <QString>
#include <QList>


class nodo
{

public:
    nodo();
    nodo(QString tipo, QString valor, int idTipo, int fila, int columna, int numero);

    void agregar(nodo nuevoNodo);
    int tipoNodo();

    QString tipo;
    QString valor;
    int idTipo;
    int numero;
    int fila;
    int columna;
    QList<nodo> hijos;

};

#endif // NODO_H
