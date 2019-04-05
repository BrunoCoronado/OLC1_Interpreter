#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QList>

#include "archivo.h"
#include "scanner.h"
#include "parser.h"
#include "nodo.h"
#include "ast.h"
#include "error.h"

nodo *raizAST;
bool errorCompilacion = false;
QList<error> errores;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNuevo_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "NUEVO ARCHIVO", QDir::homePath(), ".fi  (*.fi)");
    if(!path.isNull()){
        archivo archivo;
        archivo.nuevo(path.toStdString()+".fi");
        this->setWindowTitle(path+".fi");
    }
}

void MainWindow::on_actionAbrir_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "ABRIR ARCHIVO", QDir::homePath(), ".fi  (*.fi)");
    if(!path.isNull()){
        archivo archivo;
        QString contenido = QString::fromStdString(archivo.abrir(path.toStdString()));
        ui->txtEditor->setText(contenido);
        this->setWindowTitle(path);
    }
}

void MainWindow::on_actionGuardar_triggered()
{
    archivo archivo;
    if(this->windowTitle().toStdString().compare( "OLC") != 0){
        archivo.guardar(this->windowTitle().toStdString(),ui->txtEditor->toPlainText().toStdString());
    }else{
        QMessageBox::warning(this, "GUARDAR", "No existe una ruta para guardar");
    }
}

void MainWindow::on_actionGuardar_Como_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "GUARDAR COMO", QDir::homePath(), ".fi  (*.fi)");
    if(!path.isNull()){
        archivo archivo;
        archivo.guardarComo(path.toStdString()+".fi", ui->txtEditor->toPlainText().toStdString());
        this->setWindowTitle(path+".fi");
    }
}

void MainWindow::on_actionCompilar_triggered()
{
    raizAST = new nodo("raiz", "raiz", 0);
    errores = QList<error>();
    archivo archivo;
    if(this->windowTitle().toStdString().compare( "OLC") != 0){
        archivo.guardar(this->windowTitle().toStdString(),ui->txtEditor->toPlainText().toStdString() + "$");
        char path[this->windowTitle().toStdString().length() + 1];
        strcpy(path,this->windowTitle().toStdString().c_str());
        yyin = fopen(path, "rt");
        yyparse();
    }else{
        QString tmp = QDir::tempPath() + "/entrada.fi";
        archivo.guardarComo(tmp.toStdString() ,ui->txtEditor->toPlainText().toStdString() + "$");
        char path[tmp.toStdString().length() + 1];
        strcpy(path,tmp.toStdString().c_str());
        yyin = fopen(path, "rt");
        yyparse();
    }
    if(!errorCompilacion){
        //procedemos a recorrer el arbol
    }else{
        QMessageBox::warning(this, "Error", "Se encontraron errores en la entrada.");
        cout <<  "fdf " << errores[0].descripcion << errores[0].linea << endl;
    }
}

void MainWindow::on_actionAST_triggered()
{
    try {
        ast ast(raizAST);
        ast.graficar();
    } catch (int e) {
        cout << "ERROR AL GRAFICAR AST" <<endl;
    }
}


void MainWindow::on_actionErrores_triggered()
{
    if(errorCompilacion){
        try {
            if(errores.length() != 0){
                ofstream archivo;
                archivo.open("errores.html");
                archivo << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte de Errores</title>\n</head>\n<body>\n<h1 align=\"center\">Reporte de Errores</h1>\n<style type=\"text/css\">\n.tg  {border-collapse:collapse;border-spacing:0;margin:0px auto;}\n.tg td{font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;border-color:black;}\n.tg th{font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;border-color:black;}\n.tg .tg-4tse{background-color:#cb0d00;color:#000000;text-align:left;vertical-align:top}\n.tg .tg-0lax{text-align:left;vertical-align:top}\nh1{font-family:Arial, sans-serif}\n</style>\n";
                archivo << "<table class=\"tg\">\n";
                archivo << "<tr>\n<th class=\"tg-4tse\">No</th>\n<th class=\"tg-4tse\">Error</th>\n<th class=\"tg-4tse\">Linea</th>\n";
                for (int i = 0 ; i < errores.length() ; ++i) {
                    archivo << "<tr>";
                    archivo << "<td class=\"tg-0Lax\">" << (i+1) << "<br></td>";
                    archivo << "<td Class=\"tg-0Lax\">" << errores[i].descripcion << "</td>";
                    archivo << "<td Class=\"tg-0Lax\">" << errores[i].linea << "</td>";
                    archivo << "</tr>";
                }
                archivo << "</body>\n</html>";
                archivo.close();
                system("xdg-open errores.html");
            }
        } catch (int e) {
            cout << "ERROR AL GRAFICAR ERRORES" << endl;
        }
    }else{
        QMessageBox::warning(this, "Error", "No se encontraron errores en la entrada.");
    }
}
