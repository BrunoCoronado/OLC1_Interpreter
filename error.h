#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <QList>

using namespace std;

class error
{
public:
    error();
    error(string descripcion, int linea);

    string descripcion;
    int linea;
};

#endif // ERROR_H
