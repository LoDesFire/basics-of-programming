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
    a.~Vector();
    b.~Vector();
    delete ui;
}



void MainWindow::on_action_capacity_triggered()
{
    QMessageBox::information(this, "Warning", "Capacity: " + QString::number((ui->tabWidget->currentIndex() ? b.capacity() : a.capacity())));
}


void MainWindow::on_action_size_triggered()
{
    QMessageBox::information(this, "Warning", "Size: " + QString::number((ui->tabWidget->currentIndex() ? b.size() : a.size())));
}


void MainWindow::on_action_empty_triggered()
{
    QString ans =  (ui->tabWidget->currentIndex() ? (b.empty()? "YES" : "NO") : (a.empty()? "YES" : "NO"));
    QMessageBox::information(this, "Warning", "Is empty: " + ans);
}


void MainWindow::on_action_maxSize_triggered()
{
    QMessageBox::information(this, "Warning", "Maximal size: " + QString::number(b.max_size()));
}


void MainWindow::on_action_assign_triggered()
{
    if (ui->tabWidget->currentIndex() ) {
        b.assign(a.begin(), a.end());
    }
    else {
        a.assign(b.begin(), b.end());
    }

    updateTable();
}


void MainWindow::on_action_swap_triggered()
{
    a.swap(b);
    updateTable();
}


void MainWindow::on_action_insert_triggered()
{
    Constructor *dialog;
    QString ans = "Введите номер элемента:";
    dialog = new Constructor(ans, 1, (ui->tabWidget->currentIndex() ? b.size() : a.size()) + 1);
    dialog->exec();

    if (!ans.size())
        return;
    size_t n = ans.toULongLong() - 1;

    delete dialog;
    ans = "Введите элемент:";
    dialog = new Constructor(ans, LLONG_MIN, LLONG_MAX);
    dialog->exec();

    if (!ans.size())
        return;
    long long val = ans.toLongLong();

    if (ui->tabWidget->currentIndex()) {
        b.insert(b.begin() + n, val);
    }
    else
        a.insert(a.begin() + n, val);

    qDebug() << a.capacity() << "\n";

    updateTable();
}


void MainWindow::updateTable() {
    ui->tableWidget->setRowCount(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(a[i])));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&a[i]),
                                                                                     QT_POINTER_SIZE * 2, 16, QChar('0') )));
    }

    ui->tableWidget_2->setRowCount(b.size());
    for (size_t i = 0; i < b.size(); i++) {
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::number(b[i])));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&b[i]),
                                                                                     QT_POINTER_SIZE * 2, 16, QChar('0') )));
    }
}

void MainWindow::on_action_clear_triggered()
{
    if (ui->tabWidget->currentIndex()) {
        b.clear();
    }
    else
        a.clear();

    updateTable();
}


void MainWindow::on_action_emplace_triggered()
{
    Constructor *dialog;
    QString ans = "Введите номер элемента:";
    dialog = new Constructor(ans, 1, (ui->tabWidget->currentIndex() ? b.size() : a.size()) + 1);
    dialog->exec();

    if (!ans.size())
        return;
    size_t n = ans.toULongLong() - 1;

    delete dialog;
    ans = "Введите аргумент:";
    dialog = new Constructor(ans, LLONG_MIN, LLONG_MAX);
    dialog->exec();

    if (!ans.size())
        return;
    long long val = ans.toLongLong();

    if (ui->tabWidget->currentIndex()) {
        b.emplace(b.begin() + n, val);
    }
    else
        a.emplace(a.begin() + n, val);

    updateTable();
}


void MainWindow::on_action_erase_triggered()
{
    Constructor *dialog;
    QString ans = "Введите номер элемента:";
    dialog = new Constructor(ans, 1, (ui->tabWidget->currentIndex() ? b.size() : a.size()) + 1);
    dialog->exec();

    if (!ans.size())
        return;
    size_t n = ans.toULongLong() - 1;

    delete dialog;
    ans = "Введите количество удаляемых элементов:";
    dialog = new Constructor(ans, 0, (ui->tabWidget->currentIndex() ? b.size() : a.size()) - (long long )n);
    dialog->exec();

    if (!ans.size())
        return;
    long long val = ans.toLongLong();

    if (ui->tabWidget->currentIndex()) {
        b.erase(b.begin() + n, b.begin() + n + val);
    }
    else
        a.erase(a.begin() + n, a.begin() + n + val);

    updateTable();
}

