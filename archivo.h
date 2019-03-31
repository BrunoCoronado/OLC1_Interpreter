#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>

using namespace std;

class archivo
{    
public:
    archivo();

    string nuevo(string path);
    string abrir(string path);
    void guardar(string path, string contenido);
    void guardarComo(string path, string contenido);
};

#endif // ARCHIVO_H
