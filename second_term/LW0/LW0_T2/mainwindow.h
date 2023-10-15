#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "square.h"
#include "rhombus.h"
#include "star.h"
#include "hexagon.h"
#include "myfigure.h"
#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QtMath>

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
    void on_pushButton_move_clicked();

    void on_pushButton_rotate_clicked();

    void on_pushButton_resize_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Shape **shape;
    int figNumber;

    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent *);
    void turnOfftheMode();
};
#endif // MAINWINDOW_H
