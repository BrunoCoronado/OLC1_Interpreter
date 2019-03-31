#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

#include "archivo.h";

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
