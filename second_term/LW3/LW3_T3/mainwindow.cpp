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

void MainWindow::updateVec() {
    ui->tableWidget_2->clear();
    ui->tableWidget->setRowCount(vec.size());

    for (size_t i = 0; i < vec.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(vec[i])));
    }
}


void MainWindow::on_action_triggered()
{
    vec.clear();
    int rand_val = 1 + arc4random() % 30;
    if (!(rand_val & 1)) rand_val += 1;

    for (int i = 0; i < rand_val; i++) {
        vec.push_back(arc4random() % 20);
    }

    updateVec();

    b.clear();
    size_t i = 2;
    for (; i < vec.size(); i += 3) {
        qsort(&vec[0], i - 2, i);
        b.push_back(vec[i - 1]);
    }

    double tmp = 0;
    for (size_t i = vec.size() / 3 * 3; i < vec.size(); i++) {
        tmp += vec[i];
    }
    if (vec.size() % 3)
        b.push_back(tmp / double(vec.size() % 3));

    updateVec2();
}

int MainWindow::partition(double *array, int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      std::swap(array[i], array[j]);
    }
  }


  std::swap(array[i + 1], array[high]);

  return (i + 1);
}

void MainWindow::qsort(double *array, int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);

    qsort(array, low, pi - 1);

    qsort(array, pi + 1, high);
  }
}

void MainWindow::updateVec2()
{
    ui->tableWidget_2->setRowCount(b.size());

    for (size_t i = 0; i < b.size(); i++) {
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::number(b[i])));
    }
}

