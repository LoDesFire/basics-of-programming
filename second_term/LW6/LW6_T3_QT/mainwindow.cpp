#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hs(new MyHashTable(100))
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable() {
    QVector<QVector<QTableWidgetItem*>> *vector = hs->print();
    ui->tableWidget->setRowCount(vector->size());

    for (int i = 0; i < vector->size(); i++) {
        ui->tableWidget->setItem(i, 0,  (*vector)[i][0]);
        ui->tableWidget->setItem(i, 1, (*vector)[i][1]);
    }
}


void MainWindow::on_action_triggered()
{
    delete hs;
    hs = new MyHashTable(100);
    for (int i = 0; i < 200; i++)
        hs->insertValue(arc4random() % 10000);
    hs->eraseEven();
    updateTable();
}

unsigned int MainWindow::getValue() {
    bool ok;
    unsigned int value = ui->lineEdit_value->text().toUInt(&ok);
    if (!ok)
        throw std::exception();
    return value;
}

void MainWindow::on_pushButton_insert_clicked()
{
    unsigned int value = 0;
    try {
        value = getValue();
    }
    catch (...) {
        QMessageBox::warning(this, "Grrr...", "Введите число");
        return;
    }

    hs->insertValue(value);
    updateTable();
}


void MainWindow::on_pushButton_search_clicked()
{
    unsigned int value = 0;
    try {
        value = getValue();
    }
    catch (...) {
        QMessageBox::warning(this, "Grrr...", "Введите число");
        return;
    }

    QMessageBox::information(this, "",hs->findValue(value) ? "Yes" : "No");
    updateTable();
}


void MainWindow::on_pushButton_delete_clicked()
{
    unsigned int value = 0;
    try {
        value = getValue();
    }
    catch (...) {
        QMessageBox::warning(this, "Grrr...", "Введите число");
        return;
    }

    hs->deleteValue(value);
    updateTable();
}

