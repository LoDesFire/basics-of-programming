#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_strerror_clicked()
{
    bool ok;
    int errorCode = ui->lineEdit_strerror->text().toUInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }
    QMessageBox::information(this, "Yeah", QString(String::Strerror(errorCode)));
}


void MainWindow::on_pushButton_strlen_clicked()
{
    if (!ui->radioButton_strlen1->isChecked() && !ui->radioButton_strlen2->isChecked()) {
        QMessageBox::warning(this, "Grrr...", "Check radio button");
        return;
    }

    QString qstr = (ui->radioButton_strlen1->isChecked() ?ui->lineEdit_str1->text() : ui->lineEdit_str2->text());
    if (!qstr.size()) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String str = qstr.toStdString().c_str();

    QMessageBox::information(this, "Yeah", QString::number(String::Strlen(str)));
}


void MainWindow::on_pushButton_6_clicked()
{
    if (ui->lineEdit_str1->text().isEmpty() || ui->lineEdit_str2->text().isEmpty()) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str1 = ui->lineEdit_str1->text().toStdString().c_str()
      , str2 = ui->lineEdit_str2->text().toStdString().c_str();

    String::Strcat(str1, str2);

    ui->lineEdit_str1->setText(QString(str1));
    ui->lineEdit_str2->setText(QString(str2));
}


void MainWindow::on_pushButton_5_clicked()
{
    if (ui->lineEdit_str1->text().isEmpty() || ui->lineEdit_str2->text().isEmpty()) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str1 = ui->lineEdit_str1->text().toStdString().c_str()
      , str2 = ui->lineEdit_str2->text().toStdString().c_str();

    String::Strcpy(str1, str2);

    ui->lineEdit_str1->setText(QString(str1));
    ui->lineEdit_str2->setText(QString(str2));
}


void MainWindow::on_pushButton_7_clicked()
{
    if (ui->lineEdit_str1->text().isEmpty() || ui->lineEdit_str2->text().isEmpty()) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str1 = ui->lineEdit_str1->text().toStdString().c_str()
      , str2 = ui->lineEdit_str2->text().toStdString().c_str();

    QMessageBox::information(this, "Yeah", QString::number(String::Strcmp(str1, str2)));
}


void MainWindow::on_pushButton_9_clicked()
{
    bool ok;
    int value = ui->lineEdit_strBAmount->text().toUInt(&ok);
    if (ui->lineEdit_str1->text().isEmpty() || ui->lineEdit_str2->text().isEmpty() || !ok) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str1 = ui->lineEdit_str1->text().toStdString().c_str()
      , str2 = ui->lineEdit_str2->text().toStdString().c_str();


    String::Strncat(str1, str2, value);

    ui->lineEdit_str1->setText(QString(str1));
    ui->lineEdit_str2->setText(QString(str2));
}


void MainWindow::on_pushButton_10_clicked()
{
    bool ok;
    int value = ui->lineEdit_strBAmount->text().toUInt(&ok);
    if (ui->lineEdit_str1->text().isEmpty() || ui->lineEdit_str2->text().isEmpty() || !ok) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str1 = ui->lineEdit_str1->text().toStdString().c_str()
      , str2 = ui->lineEdit_str2->text().toStdString().c_str();

    String::Strncpy(str1, str2, value);

    ui->lineEdit_str1->setText(QString(str1));
    ui->lineEdit_str2->setText(QString(str2));
}


void MainWindow::on_pushButton_11_clicked()
{
    bool ok;
    int value = ui->lineEdit_strBAmount->text().toUInt(&ok);
    if (ui->lineEdit_str1->text().isEmpty() || ui->lineEdit_str2->text().isEmpty() || !ok) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str1 = ui->lineEdit_str1->text().toStdString().c_str()
      , str2 = ui->lineEdit_str2->text().toStdString().c_str();

    QMessageBox::information(this, "Yeah", QString::number(String::Strncmp(str1, str2, value)));
}


void MainWindow::on_pushButton_2_clicked()
{
    bool ok;
    int value = ui->lineEdit_memBAmount->text().toUInt(&ok);
    if (ui->lineEdit_str1->text().isEmpty() || ui->lineEdit_str2->text().isEmpty() || !ok) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str1 = ui->lineEdit_str1->text().toStdString().c_str()
      , str2 = ui->lineEdit_str2->text().toStdString().c_str();

    String::Memmove(reinterpret_cast<void*>(str1.data()), reinterpret_cast<void*>(str2.data()), value);

    ui->lineEdit_str1->setText(QString(str1));
    ui->lineEdit_str2->setText(QString(str2));
}




void MainWindow::on_pushButton_clicked()
{
    bool ok;
    int value = ui->lineEdit_memBAmount->text().toUInt(&ok);
    if (ui->lineEdit_str1->text().isEmpty() || ui->lineEdit_str2->text().isEmpty() || !ok) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str1 = ui->lineEdit_str1->text().toStdString().c_str()
      , str2 = ui->lineEdit_str2->text().toStdString().c_str();

    String::Memcpy(reinterpret_cast<void*>(str1.data()), reinterpret_cast<void*>(str2.data()), value);

    ui->lineEdit_str1->setText(QString(str1));
    ui->lineEdit_str2->setText(QString(str2));
}


void MainWindow::on_pushButton_3_clicked()
{
    bool ok;
    int value = ui->lineEdit_memBAmount->text().toUInt(&ok);
    if (ui->lineEdit_str1->text().isEmpty() || ui->lineEdit_str2->text().isEmpty() || !ok) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str1 = ui->lineEdit_str1->text().toStdString().c_str()
      , str2 = ui->lineEdit_str2->text().toStdString().c_str();

    QMessageBox::information(this, "Yeah", QString::number(String::Memcmp(str1, str2, value)));
}


void MainWindow::on_pushButton_4_clicked()
{

    if (!ui->radioButton_memset1->isChecked() && !ui->radioButton_memset2->isChecked()) {
        QMessageBox::warning(this, "Grrr...", "Check radio button");
        return;
    }

    bool ok, res = true;
    int value1 = ui->lineEdit_memsetBAmount->text().toUInt(&ok);
    res &= ok;
    int value2 = ui->lineEdit_memsetValue->text().toUInt(&ok);
    res &= ok;
    QString qstr = (ui->radioButton_memset1->isChecked() ?ui->lineEdit_str1->text() : ui->lineEdit_str2->text());
    if (!qstr.size() || !res) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }

    String
      str = qstr.toStdString().c_str();
    String::Memset(reinterpret_cast<void*>(str.data()), value2, value1);

    if (ui->radioButton_memset1->isChecked())
        ui->lineEdit_str1->setText(QString(str));
    else
        ui->lineEdit_str2->setText(QString(str));
}


void MainWindow::on_pushButton_12_clicked()
{
    if (!ui->radioButton_strtok1->isChecked() && !ui->radioButton_strtok2->isChecked()) {
        QMessageBox::warning(this, "Grrr...", "Check radio button");
        return;
    }

    QString qstr = (ui->radioButton_strtok1->isChecked() ?ui->lineEdit_str1->text() : ui->lineEdit_str2->text());
    if (!qstr.size()) {
        QMessageBox::warning(this, "Grrr...", "Wrong input");
        return;
    }


    String str2 = ui->lineEdit_delimiters->text().toStdString().c_str();

    String
      str = qstr.toStdString().c_str();

    String NULL_STR = String();

    QString ans = QString(String::Strtok(str, str2));
    String checker = ans.toStdString().c_str();
    while(checker[0] != '\0') {
        QMessageBox::information(this, "Yeah", ans);
        checker = String::Strtok(NULL_STR, str2);
        qDebug() << checker;
        ans = QString(checker);
    }
}

