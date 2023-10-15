#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Vector.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Vector<float> as{1, 3, 5};
    //qDebug() << as[0];

}

MainWindow::~MainWindow()
{
    delete ui;
}

