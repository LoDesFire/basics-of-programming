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

void MainWindow::upadateMatrix() {
    ui->tableWidget->setRowCount(pvvpid.first.size());
    ui->tableWidget_2->setRowCount(pvvpid.second.size());


    for (size_t i = 0; i < pvvpid.first.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(pvvpid.first[i])));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&pvvpid.first[i]),
                                                                                                    QT_POINTER_SIZE * 2, 16, QChar('0') )));
    }


    for (size_t i = 0; i < pvvpid.second.size(); i++) {
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::number(pvvpid.second[i].first)));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::number(pvvpid.second[i].second)));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&pvvpid.second[i]),
                                                                                                    QT_POINTER_SIZE * 2, 16, QChar('0') )));
    }
}


void MainWindow::on_action_triggered()
{
    int rand_val1 = 2 + arc4random() % 20;
    int rand_val2 = 2 + arc4random() % 20;

    vi_tmp.clear();

    for (int i = 0; i < rand_val1; i++) {
        vi_tmp.push_back(arc4random() % 1989032);
    }

    vpid_tmp.clear();


    for (int i = 0; i < rand_val2; i++) {
        vpid_tmp.push_back({(int)(arc4random() % 1989032), (arc4random() % 1989032 )/ (double)(1e-10 + arc4random() % 1989032)});
    }

    pvvpid = {vi_tmp, vpid_tmp};

    upadateMatrix();
}

