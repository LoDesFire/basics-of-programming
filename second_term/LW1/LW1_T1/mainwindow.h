#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include "date.h"
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_birthday_clicked();

    void on_pushButton_weekNum_clicked();

    void on_pushButton_isLeap_clicked();

    void on_pushButton_prevDay_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_change_clicked();

    void on_tableWidget_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    Date *date;
    int n;
    QString filename;
    QFile f;
    void updateTable();
    bool isNumber(char);
};
#endif // MAINWINDOW_H
