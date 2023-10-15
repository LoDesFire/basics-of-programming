#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <regex>
#include <vector>
#include <QString>
#include <QDebug>
#include <stack>
#include <unordered_map>

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

    void on_pushButton_listOfPrototypes_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_writeVars_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    QString searchForVars(QString inputText);
    QString countClassesStructsArrays(QString inputText);
    QString prototypeList(QString inputText);
    QString varChangingPlace(QString inputText);
    QString localVarsCount(QString inputText);
    QString overridedFuncsCount(QString inputText);
    QString branchDepth(QString inputText);
    QString logicalMistakes(QString inputText);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
