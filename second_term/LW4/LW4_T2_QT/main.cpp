#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("C-funtions");
    w.setFixedSize(775, 345);
    w.show();
    return a.exec();
}
