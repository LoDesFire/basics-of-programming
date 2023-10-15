#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QMessageBox>
#include "MyTree.h"
#include <QDebug>

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
    void on_pushButton_insert_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_makeTask_clicked();

private:
    MyTree *myTree;
    void update_tree(QTreeWidgetItem *, Node<Human> *);
    void update_tree();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
