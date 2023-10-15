#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MyHashTable.h"
#include <QMessageBox>

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
    void on_action_triggered();

    void on_pushButton_insert_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_delete_clicked();

private:
    unsigned int getValue();
    void updateTable();
    Ui::MainWindow *ui;
    MyHashTable *hs;
};
#endif // MAINWINDOW_H
