#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable() {
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(aboba.size());
    if (aboba.size()){
        auto end = aboba.end();
        ++end;
        unsigned long long k = 0;
        for (auto i = aboba.begin(); i!= end; ++i, k++) {
            ui->tableWidget->setItem(k, 0, new QTableWidgetItem(*i));
        }
    }

}

void MainWindow::on_pushButton_pushFront_clicked()
{
    if (!ui->lineEdit->text().isEmpty()) {
        aboba.push_front(ui->lineEdit->text());
    }
    updateTable();
}


void MainWindow::on_pushButton_pushBack_clicked()
{
    if (!ui->lineEdit->text().isEmpty()) {
        aboba.push_back(ui->lineEdit->text());
    }
    updateTable();
}


void MainWindow::on_pushButton_clear_clicked()
{
    aboba.clear();
    updateTable();
}


void MainWindow::on_pushButton_popFront_clicked()
{
    try {
        aboba.pop_front();
    }
    catch (...)
    {
        QMessageBox::warning(this, "", "Deque is empty");
    }
    updateTable();
}


void MainWindow::on_pushButton_PopBack_clicked()
{
    try {
        aboba.pop_back();
    }
    catch (...)
    {
        QMessageBox::warning(this, "", "Deque is empty");
    }
    updateTable();
}

