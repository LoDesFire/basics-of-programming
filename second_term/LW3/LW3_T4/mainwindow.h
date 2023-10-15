#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "Vector.h"
#include <QMessageBox>
#include "constructor.h"

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

    void on_action_capacity_triggered();

    void on_action_size_triggered();

    void on_action_empty_triggered();

    void on_action_maxSize_triggered();

    void on_action_assign_triggered();

    void on_action_swap_triggered();

    void on_action_insert_triggered();

    void on_action_clear_triggered();

    void on_action_emplace_triggered();

    void on_action_erase_triggered();

private:
    Ui::MainWindow *ui;
    void updateTable();
    Vector<long long> a;
    Vector<long long> b;
};
#endif // MAINWINDOW_H
