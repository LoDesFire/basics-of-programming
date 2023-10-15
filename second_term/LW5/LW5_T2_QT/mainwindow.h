#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "Iterator.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void updateTable();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_pushFront_clicked();

    void on_pushButton_pushBack_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_popFront_clicked();

    void on_pushButton_PopBack_clicked();

private:
    Ui::MainWindow *ui;
    Deque<QString> aboba;
};
#endif // MAINWINDOW_H
