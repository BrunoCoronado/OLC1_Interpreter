#include "archivo.h"

#include <iostream>
#include <fstream>

using namespace std;

archivo::archivo()
{

}

string archivo::nuevo(string path)
{
    try {
        ofstream nuevoArchivo (path);
        nuevoArchivo.close();
        return path;
    } catch (int e) {
        cout << "ERROR AL CREAR EL ARCHIVO" << endl;
    }
    return "";
}

string archivo::abrir(string path)
{
    string contenido = "";
    char c;
    try {
        ifstream archivo (path);
        while (archivo.get(c))
            contenido += c;
        archivo.close();
        return contenido;
    } catch (int e) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
    }
    return "";
}

void archivo::guardar(string path, string contenido)
{
    try {
        fstream archivo;
        archivo.open(path);
        if(!archivo.fail()){
            archivo << contenido;
            archivo.close();
        }else{
            cout << "NO HAY DESTINO PARA GUARDAR" << endl;
        }
    } catch (int e) {
        cout << "ERROR AL GUARDAR EL ARCHIVO" << endl;
    }
}

void archivo::guardarComo(string path, string contenido)
{
    try {
        ofstream archivo (path);
        archivo << contenido;
        archivo.close();
    } catch (int e) {
        cout << "ERROR AL GUARDAR EL ARCHIVO" << endl;
    }
}
