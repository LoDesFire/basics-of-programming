#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //this->setFixedSize(475, 148);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString *OPZ = OPZ::exprToOPZ(ui->lineEdit->text());
    if (*OPZ == "Error")
        QMessageBox::warning(this, "Warning", "Неверный ввод");
    else
    {
        bool ok;
        double expression = OPZ::calculate(*OPZ, ok);
        if (ok) {
            ui->lineEdit_OPZ->setText(*OPZ);
            ui->lineEdit_ans->setText(QString::number(expression));
        }
        else
            QMessageBox::warning(this, "Warning", "Неверный ввод");
    }
    delete OPZ;
}



void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

