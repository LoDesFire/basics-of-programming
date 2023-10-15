#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>

namespace Ui {
class Constructor;
}

class Constructor : public QDialog
{
    Q_OBJECT

public:
    explicit Constructor(QString &, long long bottom, long long top, QWidget *parent = nullptr);
    ~Constructor();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    QString &ans;
    long long bottom, top;
    Ui::Constructor *ui;
};

#endif // CONSTRUCTOR_H
