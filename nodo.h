#ifndef NODO_H
#define NODO_H

#include <QString>
#include <QList>


class nodo
{

public:
    nodo();
    nodo(QString tipo, QString valor, int idTipo);

    void agregar(nodo nuevoNodo);
    int tipoNodo();

    QString tipo;
    QString valor;
    int idTipo;
    QList<nodo> hijos;

};

#endif // NODO_H
