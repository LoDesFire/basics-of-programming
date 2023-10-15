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


void MainWindow::on_action_triggered()
{
    MyQueue q;
    for (int i = 0; i < 5 + arc4random() % 40; i++) {
        q.push(arc4random() % 20);
    }

    QStandardItemModel* model = new QStandardItemModel();
    foreach (auto item, q.toList()) {
        QStandardItem* listItem = new QStandardItem(QString::number(item));
        model->appendRow(listItem);
    }
    ui->listView->setModel(model);
    ui->listView->update();


    q.make_task();

    QStandardItemModel* model_2 = new QStandardItemModel();
    foreach (auto item, q.toList()) {
        QStandardItem* listItem = new QStandardItem(QString::number(item));
        model_2->appendRow(listItem);
    }
    ui->listView_2->setModel(model_2);
    ui->listView_2->update();
}

