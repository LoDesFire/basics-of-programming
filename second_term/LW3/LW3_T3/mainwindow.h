#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Vector.h"

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
    void updateVec();
    void updateVec2();
    int partition(double *array, int low, int high);
    void qsort(double *array, int low, int high);
    Ui::MainWindow *ui;
    Vector<double> vec;
    Vector<double> b;
};
#endif // MAINWINDOW_H
