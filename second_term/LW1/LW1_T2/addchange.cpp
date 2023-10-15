#include "addchange.h"
#include "ui_addchange.h"

AddChange::AddChange( int _mode, Abiturient *&_abitur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddChange)
    , mode(_mode)
    , abitur(_abitur)
{
    ui->setupUi(this);
    if (!_mode) {
        ui->lineEdit_FIO->setText(abitur->getFIO());
        ui->lineEdit_avMark->setText(QString::number(abitur->getAverageMark()));
        ui->lineEdit_major->setText(abitur->getMajor());
        ui->lineEdit_mark1->setText(QString::number(abitur->getMark(0)));
        ui->lineEdit_mark2->setText(QString::number(abitur->getMark(1)));
        ui->lineEdit_mark3->setText(QString::number(abitur->getMark(2)));
        ui->lineEdit_subj1->setText(abitur->getSubject(0));
        ui->lineEdit_subj2->setText(abitur->getSubject(1));
        ui->lineEdit_subj3->setText(abitur->getSubject(2));
    }
}

AddChange::~AddChange()
{
    delete ui;
}

void AddChange::on_pushButton_cancel_clicked()
{
    this->close();
}


void AddChange::on_pushButton_ok_clicked()
{
    bool ok, isValid = true;
    float avMark = ui->lineEdit_avMark->text().toDouble(&ok);
    if (!ok || (avMark > 10 || avMark < 0)) isValid = false;
    int mark = ui->lineEdit_mark1->text().toInt(&ok);
    if (!ok || (mark > 100 || mark < 0)) isValid = false;
    mark = ui->lineEdit_mark2->text().toInt(&ok);
    if (!ok || (mark > 100 || mark < 0)) isValid = false;
    mark = ui->lineEdit_mark3->text().toInt(&ok);
    if (!ok || (mark > 100 || mark < 0)) isValid = false;
    if (ui->lineEdit_FIO->text() == "" || ui->lineEdit_major->text() == "" || ui->lineEdit_subj1->text() == "" || ui->lineEdit_subj2->text() == "" || ui->lineEdit_subj3->text() == "")
        isValid = false;
    if (!isValid) QMessageBox::warning(this, "Ошибка", "Введены неверные данные");
    else
    {
        int mark[3] = {
            ui->lineEdit_mark1->text().toInt(),
            ui->lineEdit_mark2->text().toInt(),
            ui->lineEdit_mark3->text().toInt(),
        };
        QString subject[3] = {
            ui->lineEdit_subj1->text(),
            ui->lineEdit_subj2->text(),
            ui->lineEdit_subj3->text(),
        };

        if (!mode) {
            Abiturient *tmp = new Abiturient(ui->lineEdit_FIO->text(), ui->lineEdit_major->text(), ui->lineEdit_avMark->text().toDouble(), subject, mark);
            delete abitur;
            abitur = tmp;
        }
        else {
            abitur = new Abiturient(ui->lineEdit_FIO->text(), ui->lineEdit_major->text(), ui->lineEdit_avMark->text().toDouble(), subject, mark);
        }
        this->close();
    }
}

