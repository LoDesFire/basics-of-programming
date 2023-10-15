#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Vector.h"
#include "pair.h"
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
    void on_action_triggered();

private:
    void upadateMatrix();
    Ui::MainWindow *ui;
    Pair<Vector<int>, Vector<Pair<int, double>>> pvvpid;
    Vector<int> vi_tmp;
    Vector<Pair<int, double>> vpid_tmp;
};
#endif // MAINWINDOW_H
