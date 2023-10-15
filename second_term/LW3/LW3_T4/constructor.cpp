#include "constructor.h"
#include "ui_constructor.h"

Constructor::Constructor(QString &qq, long long _bottom, long long _top, QWidget *parent) :
    QDialog(parent),
    ans(qq),
    ui(new Ui::Constructor),
    bottom(_bottom),
    top(_top)
{

    ui->setupUi(this);
    ui->label->setText(qq);
}

Constructor::~Constructor()
{
    delete ui;
}

void Constructor::on_pushButton_2_clicked()
{
    ans = ui->lineEdit->text();

    bool ok;
    long long val = ans.toLongLong(&ok);

    if (!ok || val > top || val < bottom)
        QMessageBox::warning(this, "Warning", "Warning");
    else
        close();
}


void Constructor::on_pushButton_clicked()
{
    ans = nullptr;
    this->close();
    return;
}

