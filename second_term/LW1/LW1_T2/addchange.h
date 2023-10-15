#ifndef ADDCHANGE_H
#define ADDCHANGE_H

#include <QDialog>
#include <QMessageBox>
#include <QAbstractButton>
#include <QString>
#include "abiturient.h"

namespace Ui {
class AddChange;
}

class AddChange : public QDialog
{
    Q_OBJECT

public:
    AddChange(int, Abiturient *&_abitur, QWidget *parent = nullptr);
    ~AddChange();

private slots:

    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::AddChange *ui;
    int mode;
    Abiturient *&abitur;
};

#endif // ADDCHANGE_H
