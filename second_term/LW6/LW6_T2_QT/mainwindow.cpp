#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hs(nullptr)
{
    ui->setupUi(this);
    ui->plot->addGraph();
    ui->comboBox->setCurrentIndex(-1);
    ui->horizontalSlider_3->setRange(5, 90);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable() {
    QCustomPlot *plot = ui->plot;

    plot->xAxis->setRange(0, ui->comboBox->currentText().toInt());
    plot->xAxis->ticker()->setTickCount(8);
    plot->yAxis->setLabel("Среднее время поиска одного элемента");
    plot->xAxis->setLabel("Количество значений");

    QVector <double> time, count;

    for (int i = 0; i <= ui->comboBox->currentText().toInt(); i++) {
        makeHashTable(i, ui->horizontalSlider_2->value());
        unsigned int start_time =  clock();
        for (int j = 0; j < i; j++) {
            hs->findValue(hs->operator [](j));
        }
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time; // искомо
        count.append(i);
        time.append(search_time / double(i) / 1000.0);
    }

    if (!count.isEmpty())
        plot->graph(0)->setData(count, time);

    double yRange = time.back() * 1.5;
    std::sort(time.begin(), time.end());
    yRange = std::max(yRange, time[time.size() / 2] * 2);
    plot->yAxis->setRange(0, yRange);
    plot->replot();
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    Q_UNUSED(value);
    updateTable();
}

void MainWindow::makeHashTable(int tableSize, int collisions ) {
    delete hs;
    hs = nullptr;
    int size = tableSize;
    int collisionCount = std::min(collisions, size);
    int step = collisionCount * (ui->horizontalSlider_3->value() / 100.0) + 1;
    int remained = collisionCount;
    if (step == 0 || size == 0)
        return;

    hs = new HashTable(size);

    for (int i = 0; i < size - collisionCount; i++) {
        hs->insertValue(i + step);
    }

    for (int i = 0; i < collisionCount / step; i++) {
        for (int j = 0; j < step; j++) {
            hs->insertValue(j + i * size);
        }
    }
    remained -= (collisionCount / step) * step;
    for (int i = 0; i < remained; i++) {
        hs->insertValue(i + (collisionCount / step + 1) * size);
    }

//    hs->print();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    auto maxRange =  ui->comboBox->currentText().toInt();
    ui->horizontalSlider_2->setRange(1, maxRange);
    ui->horizontalSlider_2->setValue(maxRange * 0.3);
    ui->label_7->setText(ui->comboBox->currentText());
}


void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    Q_UNUSED(value);
    updateTable();
}

