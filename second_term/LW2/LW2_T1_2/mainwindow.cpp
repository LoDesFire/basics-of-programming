#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fs(nullptr)
    , abitura(nullptr)
    , planOfRecruitment(0)
{
    ui->setupUi(this);
    turnOffButtons();
    planOfRecruitment = 12;
    ui->label_plan->setText(QString::number(planOfRecruitment));
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateList(int i) {
    if (abitura && abitura->get_size()) {
        ui->label_subject1->setText((abitura->operator [](i))->getSubject(0) + ":");
        ui->label_subject2->setText((abitura->operator [](i))->getSubject(1) + ":");
        ui->label_subject3->setText((abitura->operator [](i))->getSubject(2) + ":");
        ui->label_mark1->setText(QString::number((abitura->operator [](i))->getMark(0)));
        ui->label_mark2->setText(QString::number((abitura->operator [](i))->getMark(1)));
        ui->label_mark3->setText(QString::number((abitura->operator [](i))->getMark(2)));
    }
    else
    {
        ui->label_mark1->setText("N/D");
        ui->label_mark2->setText("N/D");
        ui->label_mark3->setText("N/D");
        ui->label_subject1->setText("N/D:");
        ui->label_subject2->setText("N/D:");
        ui->label_subject3->setText("N/D:");
        ui->label_recruited->setText("N/D");
    }
}

void MainWindow::updateComboBox() {
    ui->comboBox_FIO->clear();
    for (unsigned long long i = 0; i < abitura->get_size(); i++) {
        ui->comboBox_FIO->addItem((abitura->operator [](i))->getFIO());
    }
    updateList(0);
    ui->label_recruited->setText(QString::number(abitura->get_size()));
}

void MainWindow::on_comboBox_FIO_currentIndexChanged(int i)
{
    if (i != -1)
        updateList(i);
}

void MainWindow::on_action_open_triggered(bool checked)
{
    Q_UNUSED(checked);
    if (abitura)
        delete abitura;
    abitura = new List();
    if (fs)
        delete fs;
    fs = new FileStream(QFileDialog::getOpenFileName(this, "Open File", "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW2_T1_2/", "*.txt"));

    if (fs->loadFromFile(abitura)) {
        if (abitura->get_size() <= planOfRecruitment) {
            QMessageBox::information(this, "INFO", "Read succesfully!");
            updateComboBox();
            turnOnButtons();
            ui->action_save->setEnabled(true);
            return;
        }
        else {
            QMessageBox::warning(this, "Warning", "Out of Limit");
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Wrong format");
    }
    if (abitura) {
        delete abitura;
        abitura = nullptr;
        ui->comboBox_FIO->clear();
        updateList(0);
        turnOffButtons();
        ui->action_save->setEnabled(false);
    }
}

void MainWindow::on_action_save_triggered(bool checked) {
    Q_UNUSED(checked);
    fs->saveTheFile(abitura);
}

void MainWindow::on_action_saveAs_triggered(bool checked)
{
    Q_UNUSED(checked);
    FileStream::saveToFile(abitura);
}

void MainWindow::on_pushButton_addEmp_clicked()
{
    Abiturient *newAbiturient;
    AddChange *wind = new AddChange(newAbiturient, this);
    wind->setWindowTitle("Add abiturient");
    wind->exec();

    if (newAbiturient) {
        abitura->push_back(newAbiturient);
        updateComboBox();
        turnOnButtons();
        ui->comboBox_FIO->setCurrentIndex(abitura->get_size() - 1);
    }
}

void MainWindow::turnOffButtons() {
    ui->pushButton_addEmp->setEnabled(false);
    ui->pushButton_delete->setEnabled(false);
    ui->pushButton_findSverh->setEnabled(false);
    ui->pushButton_sort->setEnabled(false);

}

void MainWindow::turnOnButtons() {
    if (abitura->get_size() >= planOfRecruitment)
        ui->pushButton_addEmp->setEnabled(false);
    else
        ui->pushButton_addEmp->setEnabled(true);
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_findSverh->setEnabled(true);
    ui->pushButton_sort->setEnabled(true);
}


void MainWindow::on_pushButton_delete_clicked()
{
    int ind = ui->comboBox_FIO->currentIndex();
    abitura->erase(ind);
    turnOnButtons();
    if (!abitura->get_size())
    {
        turnOffButtons();
        ui->pushButton_addEmp->setEnabled(true);
    }
    updateComboBox();
    ui->comboBox_FIO->setCurrentIndex(fmin(ind, abitura->get_size() - 1));
}

void MainWindow::on_pushButton_findSverh_clicked()
{
    ui->plainTextEdit_info->clear();
    for (unsigned long long i = 0; i < abitura->get_size(); i++) {
        if ((abitura->operator [](i))->getSummary() / 3.0 > abitura->getAvMark())
            ui->plainTextEdit_info->appendPlainText(*((abitura->operator [](i))->toPlainText()));
    }
    if (!abitura->get_size())
        ui->plainTextEdit_info->appendPlainText("Абитуриентов не найдено");
}


void MainWindow::on_pushButton_sort_clicked()
{
    List::mergeSort(abitura, 0, abitura->get_size() - 1, comparator);
    updateComboBox();
}

bool MainWindow::comparator(Abiturient *a, Abiturient *b) {
    return a->getFIO() < b->getFIO();
}


