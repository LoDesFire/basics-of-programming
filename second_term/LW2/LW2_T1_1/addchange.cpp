#include "addchange.h"
#include "ui_addchange.h"

AddChange::AddChange(Employee *&empl, QWidget *parent) :
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
    long long number = ui->lineEdit_number->text().toLongLong(&ok);
    isValid &= ok;
    float tariff = ui->lineEdit_tariff->text().toFloat(&ok);
    isValid &= ok;
    int hours = ui->lineEdit_hours->text().toInt(&ok);
    isValid &= ok;
    if (ui->lineEdit_FIO->text() == "")
        isValid = false;
    if (!isValid) QMessageBox::warning(this, "Ошибка", "Введены неверные данные");
    else {
        employee = new Employee(ui->lineEdit_FIO->text(), number, hours, tariff);
        this->close();
    }
}

AddChange::~AddChange()
{
    delete ui;
}
