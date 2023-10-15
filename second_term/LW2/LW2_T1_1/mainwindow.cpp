#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fs(nullptr)
    , employees(nullptr)
{
    ui->setupUi(this);
    turnOffButtons();
    ui->lineEdit_search->setPlaceholderText("Min.  зарплата");
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateList(int i) {
    if (employees && employees->get_size()) {
        ui->label_number->setText(QString::number((employees->operator [](i))->data->getNumber()));
        ui->label_tariff->setText(QString::number((employees->operator [](i))->data->getTariff()));
        ui->label_hours->setText(QString::number((employees->operator [](i))->data->getHours()));
    }
    else
    {
        ui->label_number->setText("N/D");
        ui->label_tariff->setText("N/D");
        ui->label_hours->setText("N/D");
    }
}

void MainWindow::updateComboBox() {
    ui->comboBox_FIO->clear();
    for (unsigned long long i = 0; i < employees->get_size(); i++) {
        ui->comboBox_FIO->addItem((employees->operator [](i))->data->getFIO());
    }
    updateList(0);
}

void MainWindow::on_comboBox_FIO_currentIndexChanged(int i)
{
    if (i != -1)
        updateList(i);
}

void MainWindow::on_action_open_triggered(bool checked)
{
    Q_UNUSED(checked);
    if (employees)
        delete employees;
    employees = new List();
    if (fs)
        delete fs;
    fs = new FileStream(QFileDialog::getOpenFileName(this, "Open File", "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW2_T1_1/", "*.txt"));

    if (fs->loadFromFile(employees)) {
        QMessageBox::information(this, "INFO", "Read succesfully!");
        updateComboBox();
        turnOnButtons();
        ui->action_save->setEnabled(true);
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Wrong format");
        delete employees;
        employees = nullptr;
        ui->comboBox_FIO->clear();
        updateList(0);
        turnOffButtons();
        ui->action_save->setEnabled(false);
    }
}

void MainWindow::on_action_save_triggered(bool checked) {
    Q_UNUSED(checked);
    fs->saveTheFile(employees);
}

void MainWindow::on_action_saveAs_triggered(bool checked)
{
    Q_UNUSED(checked);
    FileStream::saveToFile(employees);
}

void MainWindow::on_pushButton_addEmp_clicked()
{
    Employee *newEmployee;
    AddChange *wind = new AddChange(newEmployee, this);
    wind->setWindowTitle("Add employee");
    wind->exec();

    if (newEmployee) {
        employees->push_back(newEmployee);
        updateComboBox();
        turnOnButtons();
        ui->comboBox_FIO->setCurrentIndex(employees->get_size() - 1);
    }
}

void MainWindow::turnOffButtons() {
    ui->pushButton_addEmp->setEnabled(false);
    ui->pushButton_delete->setEnabled(false);
    ui->pushButton_findSverh->setEnabled(false);
    ui->pushButton_search->setEnabled(false);
    ui->lineEdit_search->setEnabled(false);
    ui->pushButton_findSverh_2->setEnabled(false);

}

void MainWindow::turnOnButtons() {
    ui->pushButton_addEmp->setEnabled(true);
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_findSverh->setEnabled(true);
    ui->pushButton_search->setEnabled(true);
    ui->lineEdit_search->setEnabled(true);
    ui->pushButton_findSverh_2->setEnabled(true);
}


void MainWindow::on_pushButton_delete_clicked()
{
    int ind = ui->comboBox_FIO->currentIndex();
    employees->erase(ind);
    if (!employees->get_size())
    {
        turnOffButtons();
        ui->pushButton_addEmp->setEnabled(true);
    }
    updateComboBox();
    ui->comboBox_FIO->setCurrentIndex(fmin(ind, employees->get_size() - 1));
}


void MainWindow::on_comboBox_searchMode_currentIndexChanged(int index)
{
    if (!index)
        ui->lineEdit_search->setPlaceholderText("Min.  зарплата");
    else
        ui->lineEdit_search->setPlaceholderText("Min.  отработка");
}

void MainWindow::on_lineEdit_search_returnPressed()
{
    on_pushButton_search_clicked();
}

void MainWindow::on_pushButton_search_clicked()
{
    ui->plainTextEdit_info->clear();
    bool ok;
    double value = ui->lineEdit_search->text().toDouble(&ok);
    if (ok) {
        for (unsigned long long i = 0; i < employees->get_size(); i++) {
            QString output;
            if (!ui->comboBox_searchMode->currentIndex()) {
                if ((employees->operator [](i))->data->getSalary() > value - 1e-12)
                    output = *((employees->operator [](i))->data->toPlainText());
            }
            else {
                if ((employees->operator [](i))->data->getHours() > (int)value)
                    output = *((employees->operator [](i))->data->toPlainText());
            }
            ui->plainTextEdit_info->appendPlainText(output);
        }
    }
    else
        QMessageBox::warning(this, "Warning", "Wrong format");
}


void MainWindow::on_pushButton_findSverh_clicked()
{
    ui->plainTextEdit_info->clear();
    for (unsigned long long i = 0; i < employees->get_size(); i++) {
        if ((employees->operator [](i))->data->getHours() > 144)
            ui->plainTextEdit_info->appendPlainText(*((employees->operator [](i))->data->toPlainText()));
    }
    if (!employees->get_size())
        ui->plainTextEdit_info->appendPlainText("Сотррудников не найдено");
}


void MainWindow::on_pushButton_findSverh_2_clicked()
{
    List::mergeSort(employees, 0, employees->get_size() - 1, comparator);
    updateComboBox();
}

bool MainWindow::comparator(Employee *a, Employee *b) {
    return a->getNumber() < b->getNumber();
}


