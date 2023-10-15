#ifndef ADDCHANGE_H
#define ADDCHANGE_H

#include <QDialog>
#include <QMessageBox>
#include "abiturient.h"

namespace Ui {
class AddChange;
}

class AddChange : public QDialog
{
    Q_OBJECT

public:
    explicit AddChange(Abiturient *&, QWidget *parent = nullptr);
    ~AddChange();
private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::AddChange *ui;
    Abiturient *&employee;
};

#endif // ADDCHANGE_H
