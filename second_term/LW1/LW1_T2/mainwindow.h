#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "abiturient.h"
#include "filestream.h"
#include "addchange.h"
#include <QFileDialog>
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
    void on_pushButton_openFile_clicked();

    void on_comboBox_FIO_currentIndexChanged(int index);

    void on_pushButton_change_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_showStat_clicked();

    void on_pushButton_sort_clicked();

private:
    Ui::MainWindow *ui;
    FileStream *fs;
    QVector<Abiturient *> abitList;
    void updateInfo();
    void clearInfo();
    void turnOnInterface();
    void updateComboBoxInfo(int);
    void qs(QVector<Abiturient *> &, int, int);
    int partition(QVector<Abiturient *> &, int, int);
};
#endif // MAINWINDOW_H
