#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fs(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("Миша, всё херня, давай по новой");
    ui->pushButton->setEnabled(false);
    clearInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fs;
}

void MainWindow::updateInfo() {
    if (!abitList.isEmpty()) {
        int n = std::min(std::max(ui->comboBox_FIO->currentIndex(), 0), abitList.size() - 1);
        ui->comboBox_FIO->clear();
        for (Abiturient *i : abitList) {
            ui->comboBox_FIO->addItem(i->getFIO());
        }
        ui->comboBox_FIO->setCurrentIndex(n);
        turnOnInterface();
    }
    else {
        ui->comboBox_FIO->clear();
        clearInfo();
        ui->pushButton_add->setEnabled(true);
    }
}

void MainWindow::updateComboBoxInfo(int n) {
    if (n > -1) {
        ui->label_mark1->setText(QString::number(abitList[n]->getMark(0)));
        ui->label_mark2->setText(QString::number(abitList[n]->getMark(1)));
        ui->label_mark3->setText(QString::number(abitList[n]->getMark(2)));
        ui->label_subj1->setText(abitList[n]->getSubject(0) + ":");
        ui->label_subj2->setText(abitList[n]->getSubject(1) + ":");
        ui->label_subj3->setText(abitList[n]->getSubject(2) + ":");
        ui->label_avMark->setText(QString::number(abitList[n]->getAverageMark()));
        ui->label_major->setText(abitList[n]->getMajor());
    }
}

void MainWindow::clearInfo() {
    ui->pushButton_add->setEnabled(false);
    ui->pushButton_change->setEnabled(false);
    ui->pushButton_delete->setEnabled(false);
    ui->pushButton_search->setEnabled(false);
    ui->pushButton_showStat->setEnabled(false);
    ui->pushButton_sort->setEnabled(false);
    ui->comboBox_FIO->clear();
    ui->label_mark1->setText("N/D");
    ui->label_mark2->setText("N/D");
    ui->label_mark3->setText("N/D");
    ui->label_subj1->setText("Predmet1:");
    ui->label_subj2->setText("Predmet2:");
    ui->label_subj3->setText("Predmet3:");
    ui->label_avMark->setText("N/D");
    ui->label_major->setText("N/D");
}

void MainWindow::turnOnInterface() {
    ui->pushButton->setEnabled(true);
    ui->pushButton_add->setEnabled(true);
    ui->pushButton_change->setEnabled(true);
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_search->setEnabled(true);
    ui->pushButton_showStat->setEnabled(true);
    ui->pushButton_sort->setEnabled(true);
}


void MainWindow::on_pushButton_openFile_clicked()
{
    if (fs) {
        ui->pushButton->setEnabled(false);
        clearInfo();
        delete fs;
    }
    fs = new FileStream(QFileDialog::getOpenFileName(this, "Open File", "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW1_T2/LW1_T2", "*.txt"));

    if (fs->loadFromFile(abitList)) {
        qDebug() << "Succesfully loaded from file";
        turnOnInterface();
        updateInfo();

    }
    else
        qDebug() << "There is an error while loading";
}


void MainWindow::on_comboBox_FIO_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    updateComboBoxInfo(index);
}


void MainWindow::on_pushButton_change_clicked()
{
    AddChange wind(0, abitList[ui->comboBox_FIO->currentIndex()]);
    wind.setWindowTitle("Change");
    wind.exec();
    updateInfo();
}


void MainWindow::on_pushButton_add_clicked()
{
    Abiturient *tmp = nullptr;
    AddChange wind(1, tmp);
    wind.setWindowTitle("Add");
    wind.exec();
    if (tmp) {
        abitList.push_back(tmp);
    }
    updateInfo();
}

void MainWindow::on_pushButton_delete_clicked()
{
    if (!abitList.isEmpty()) {
        abitList.erase(abitList.begin() + ui->comboBox_FIO->currentIndex());
        updateInfo();
    }
}


void MainWindow::on_pushButton_clicked()
{
    fs->saveToFile(abitList);
}

void MainWindow::on_pushButton_search_clicked()
{
    QString FIO = ui->lineEdit_FIO->text();
    if (FIO != "") {
        ui->plainTextEdit->clear();
        for (Abiturient *i : abitList) {
            if (i->getFIO() == FIO) {
                QString info = "Ф.И.О.: ";
                info += i->getFIO();
                info += "\nСпециальность: ";
                info += i->getMajor();
                info += "\nСредняя оценка: ";
                info += QString::number(i->getAverageMark());
                info += "\n";
                info += i->getSubject(0);
                info += ": ";
                info += QString::number(i->getMark(0));
                info += "\n";
                info += i->getSubject(1);
                info += ": ";
                info += QString::number(i->getMark(1));
                info += "\n";
                info += i->getSubject(2);
                info += ": ";
                info += QString::number(i->getMark(2));
                info += "\n";
                ui->plainTextEdit->appendPlainText(info);
            }
        }
    }
}


void MainWindow::on_pushButton_showStat_clicked()
{
    QString major = ui->lineEdit_stat->text();
    if (major != "") {
        ui->plainTextEdit->clear();
        for (Abiturient *i : abitList) {
            if (i->getMajor() == major) {
                QString info = "Ф.И.О.: ";
                info += i->getFIO();
                info += "\nСуммарный балл: ";
                info += QString::number(i->getSummaryMark());
                info += "\n";
                ui->plainTextEdit->appendPlainText(info);
            }
        }
    }
}


void MainWindow::on_pushButton_sort_clicked()
{
    qs(abitList, 0, abitList.size() - 1);
    on_pushButton_showStat_clicked();
    updateInfo();
}

int MainWindow::partition(QVector<Abiturient *> &list, int start, int end) {
    int pivot = list[end]->getSummaryMark();

    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (list[j]->getSummaryMark() >= pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }

    std::swap(list[i + 1], list[end]);

    return i + 1;
}

void MainWindow::qs(QVector<Abiturient *> &list, int start, int end) {
    if (start < end) {
        int pi = partition(list, start, end);

        qs(list, start, pi - 1);
        qs(list, pi + 1, end);
    }
}
