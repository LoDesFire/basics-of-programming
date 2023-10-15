#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include "filestream.h"
#include "list.h"
#include "addchange.h"

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
    void on_comboBox_FIO_currentIndexChanged(int index);
    void on_action_open_triggered(bool checked);
    void on_lineEdit_search_returnPressed();
    void on_action_save_triggered(bool checked);
    void on_action_saveAs_triggered(bool checked);
    void on_pushButton_addEmp_clicked();

    void on_pushButton_delete_clicked();

    void on_comboBox_searchMode_currentIndexChanged(int index);

    void on_pushButton_search_clicked();

    void on_pushButton_findSverh_clicked();

    void on_pushButton_findSverh_2_clicked();

private:
    Ui::MainWindow *ui;
    FileStream *fs;
    List *employees;
    void updateList(int);
    void updateComboBox();
    void turnOffButtons();
    void turnOnButtons();
    static bool comparator(Employee *a, Employee *b);
};
#endif // MAINWINDOW_H
