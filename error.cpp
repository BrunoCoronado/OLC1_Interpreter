#include "error.h"

#include <iostream>
#include <fstream>

using namespace std;

error::error()
{

}

error::error(string descripcion, int linea){
    this->descripcion = descripcion;
    this->linea = linea;
}
