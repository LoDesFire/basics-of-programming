#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Vedomost");
    w.setFixedSize(870, 360);
    w.show();
    return a.exec();
}
