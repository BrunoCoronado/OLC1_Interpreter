#include "ast.h"

#include <iostream>
#include <fstream>

using namespace std;


ast::ast()
{
    this->raiz = new nodo();
}

ast::ast(nodo *raiz){
    this->raiz = raiz;
}
int numero = 1;
void ast::graficar(){
    try {
        if(raiz){
            if(raiz->idTipo != -1){
                archivo.open("ast.txt");
                archivo << "digraph G {\n";
                string idNodo = "nodo" + to_string(contadorNodos++);
                archivo << idNodo << "[label = \" NO: " << numero++ << " \\n VALOR: " << raiz->valor.toStdString() << " \\n TIPO: " << raiz->tipo.toStdString() << " \"]\n";

                if(raiz->hijos.length() != 0){
                    for (int i = 0 ; i < raiz->hijos.length() ; ++i) {
                        graficarHijos(idNodo, raiz->hijos[i]);
                    }
                }

                archivo << conexiones << "\n}";
                archivo.close();
                system("dot -Tsvg ast.txt -o ast.svg");
                system("xdg-open ast.svg");
            }
        }
    } catch (int e) {
        cout << "ERROR AL GRAFICAR AST" << endl;
    }
}

void ast::graficarHijos(string padre, nodo hijo){
    try {
        string idNodo = "nodo" + to_string(contadorNodos++);
        if(hijo.idTipo == 57){
            archivo << idNodo << "[label = \" NO: " << numero++ << " \\n VALOR: " << hijo.valor.remove(QChar('\"'), Qt::CaseInsensitive).toStdString() << " \\n TIPO: " << hijo.tipo.toStdString() << " \"]\n";

        }else if(hijo.idTipo == 58){
            archivo << idNodo << "[label = \" NO: " << numero++ << " \\n VALOR: " << hijo.valor.remove(QChar('\''), Qt::CaseInsensitive).toStdString() << " \\n TIPO: " << hijo.tipo.toStdString() << " \"]\n";
        }else{
            archivo << idNodo << "[label = \" NO: " << numero++ << " \\n VALOR: " << hijo.valor.toStdString() << " \\n TIPO: " << hijo.tipo.toStdString() << " \"]\n";
        }
        conexiones += padre + "->" + idNodo + "\n";
        if(hijo.hijos.length() != 0){
            for (int i = 0 ; i < hijo.hijos.length() ; ++i) {
                graficarHijos(idNodo, hijo.hijos[i]);
            }
        }
    } catch (int e) {
        cout << "ERROR AL GRAFICAR AST" << endl;
    }
}
