#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "hash_table.h"
#include <ctime>

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
    void on_horizontalSlider_2_valueChanged(int value);

    void on_comboBox_currentIndexChanged(int index);

    void on_horizontalSlider_3_valueChanged(int value);

private:
    void makeHashTable(int tableSize, int collisions);
    void updateTable();
    Ui::MainWindow *ui;
    HashTable *hs;
};
#endif // MAINWINDOW_H
