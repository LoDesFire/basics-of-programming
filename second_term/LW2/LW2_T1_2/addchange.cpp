#include "addchange.h"
#include "ui_addchange.h"

AddChange::AddChange(Abiturient *&empl, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddChange)
    , employee(empl)
{
    ui->setupUi(this);
}

void AddChange::on_pushButton_cancel_clicked() {
    this->close();
}

void AddChange::on_pushButton_ok_clicked() {
    bool ok, isValid = true;
    float mark[3];
    mark[0] = ui->lineEdit_mark1->text().toFloat(&ok);
    if (mark[0] > 10.0 + 1e6)
        ok = false;
    isValid &= ok;
    mark[1] = ui->lineEdit_mark2->text().toFloat(&ok);
    if (mark[1] > 10.0 + 1e6)
        ok = false;
    isValid &= ok;
    mark[2] = ui->lineEdit_mark3->text().toFloat(&ok);
    if (mark[2] > 10.0 + 1e6)
        ok = false;
    isValid &= ok;
    if (ui->lineEdit_FIO->text() == "")
        isValid = false;
    if (!isValid) QMessageBox::warning(this, "Ошибка", "Введены неверные данные");
    else {
        employee = new Abiturient(ui->lineEdit_FIO->text(), ui->lineEdit_subj1->text(), ui->lineEdit_subj2->text(), ui->lineEdit_subj3->text(), mark);
        this->close();
    }
}

AddChange::~AddChange()
{
    delete ui;
}
