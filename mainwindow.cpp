#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

#include "archivo.h"
#include "scanner.h"
#include "parser.h"
#include "nodo.h"
#include "ast.h"

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
nodo *raizAST;
void MainWindow::on_actionCompilar_triggered()
{
    raizAST = new nodo("raiz", "raiz", 0);
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
