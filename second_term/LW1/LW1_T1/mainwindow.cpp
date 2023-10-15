#include "mainwindow.h"

#include "ui_mainwindow.h"

const int FILE_BUFFER_SIZE = 32768;

MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow), date(nullptr), n(0) {
    ui -> setupUi(this);
    ui -> pushButton_birthday -> setEnabled(false);
    ui -> pushButton_isLeap -> setEnabled(false);
    ui -> pushButton_prevDay -> setEnabled(false);
    ui -> pushButton_weekNum -> setEnabled(false);
    ui -> pushButton_add -> setEnabled(false);
    ui -> pushButton_change -> setEnabled(false);
}

MainWindow::~MainWindow() {
    delete ui;
    if (date) {
        delete[] date;
    }
}

void MainWindow::updateTable() {
    if (!filename.isEmpty()) {
        f.setFileName(filename);
        f.open(QIODevice::ReadOnly);

        if (f.isOpen()) {
            QTextStream fin(&f);
            bool isValid = true;
            int columnCount = 0;

            while (!fin.atEnd()) {
                QString dateInFile;
                fin >> dateInFile;

                if (QDate::fromString(dateInFile, "dd.MM.yyyy").isValid()) {
                    columnCount++;
                }
                else
                    isValid = false;
            }

            if (isValid) {
                ui -> pushButton_birthday -> setEnabled(true);
                ui -> pushButton_isLeap -> setEnabled(true);
                ui -> pushButton_prevDay -> setEnabled(true);
                ui -> pushButton_weekNum -> setEnabled(true);
                ui -> pushButton_add -> setEnabled(true);
                ui -> pushButton_change -> setEnabled(true);

                n = columnCount;
                ui -> tableWidget -> setColumnCount(n);
                if (date) {
                    delete[] date;
                }
                date = new Date[n]();

                columnCount = 0;

                fin.seek(std::ios::beg);

                while (!fin.atEnd() && isValid) {
                    QString dateInFile;
                    fin >> dateInFile;

                    date[columnCount++] = QDate::fromString(dateInFile, "dd.MM.yyyy");
                }

                if (isValid) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < n; j++) {
                        if (ui -> tableWidget -> item(i, j))
                            delete ui -> tableWidget -> item(i, j);
                        switch (i) {
                        case 0:
                            ui -> tableWidget -> setItem(0, j, new QTableWidgetItem(date[j].toStr()));
                            break;
                        case 1:
                            ui -> tableWidget -> setItem(1, j, new QTableWidgetItem(date[j].NextDay().toStr()));
                            break;
                        case 2:
                            ui -> tableWidget -> setItem(2, j, new QTableWidgetItem(QString::number(date[j].Duration(date[(j + 1) % n]))));
                            break;
                        }
                    }
                }

                ui -> statusbar -> showMessage("Updated");
                }
                else
                    ui -> statusbar -> showMessage("Bad format");

            }
            else
                ui -> statusbar -> showMessage("Bad format");

            f.close();

        }
        else
            ui -> statusbar -> showMessage("Unable to open a file");
    }
    else {
        ui -> statusbar -> showMessage("Try Again");
        ui->tableWidget->setColumnCount(0);
        ui -> pushButton_birthday -> setEnabled(false);
        ui -> pushButton_isLeap -> setEnabled(false);
        ui -> pushButton_prevDay -> setEnabled(false);
        ui -> pushButton_weekNum -> setEnabled(false);
        ui -> pushButton_add -> setEnabled(false);
        ui -> pushButton_change -> setEnabled(false);
    }
}

void MainWindow::on_pushButton_clicked() {
    filename = QFileDialog::getOpenFileName(this, "Open File", "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW1_T1/LW1_T1", "*.txt");
    updateTable();
}

void MainWindow::on_pushButton_birthday_clicked() {
    for (int j = 0; j < n; j++) {
        if (ui -> tableWidget -> item(3, j))
            delete ui -> tableWidget -> item(3, j);

        ui -> tableWidget -> setItem(3, j, new QTableWidgetItem(QString::number(date[j].DaysTillYourBirthday(Date(ui -> dateEdit_2 -> date())))));
    }
}

void MainWindow::on_pushButton_weekNum_clicked() {
    for (int j = 0; j < n; j++) {
        if (ui -> tableWidget -> item(3, j))
            delete ui -> tableWidget -> item(3, j);

        ui -> tableWidget -> setItem(3, j, new QTableWidgetItem(QString::number(date[j].WeekNumber())));
    }
}

void MainWindow::on_pushButton_isLeap_clicked() {
    for (int j = 0; j < n; j++) {
        if (ui -> tableWidget -> item(3, j))
            delete ui -> tableWidget -> item(3, j);

        ui -> tableWidget -> setItem(3, j, new QTableWidgetItem((date[j].isLeap() ? "Yes" : "No")));
    }
}

void MainWindow::on_pushButton_prevDay_clicked() {
    for (int j = 0; j < n; j++) {
        if (ui -> tableWidget -> item(3, j))
            delete ui -> tableWidget -> item(3, j);
        if (date[j].PreviousDay().year() < 0) {
            ui -> tableWidget -> setItem(3, j, new QTableWidgetItem(date[j].PreviousDay().makeOpposite().toStr() + " до н.э."));
        } else
            ui -> tableWidget -> setItem(3, j, new QTableWidgetItem(date[j].PreviousDay().toStr()));
    }
}

void MainWindow::on_pushButton_add_clicked() {
    if (!filename.isEmpty()) {
        f.setFileName(filename);
        f.open(QIODevice::Append);
        if (f.isOpen()) {
            f.seek(-1);
            std::string dat = ui -> dateEdit_addChange -> date().toString("dd.MM.yyyy").toStdString();
            f.putChar(' ');
            for (auto i: dat) {
                f.putChar(i);
            }
            f.close();
            updateTable();
            ui -> statusbar -> showMessage("Date added");
        } else {
            ui -> statusbar -> showMessage("Try Again...");
        }
    } else {
        ui -> statusbar -> showMessage("Open A File");
    }
}

void MainWindow::on_pushButton_change_clicked() {
    if (!ui -> tableWidget -> selectedRanges().isEmpty()) {
        if (!filename.isEmpty()) {
            f.setFileName(filename);
            f.open(QIODevice::ReadWrite);

            if (f.isOpen()) {
                    char data[FILE_BUFFER_SIZE];
                    int i = -1, columnCount = 0;
                    f.read(data, FILE_BUFFER_SIZE);
                    while (columnCount != ui -> tableWidget -> selectedRanges().constFirst().leftColumn() + 1) {
                        i++;
                        if ((i == 0 || data[i - 1] == ' ' || data[i - 1] == '\n') && (data[i] <= '9' && data[i] >= '0')) {
                            columnCount++;
                        }
                    }

                    f.seek(i);
                    std::string dat = ui -> dateEdit_addChange -> date().toString("dd.MM.yyyy").toStdString();
                    for (auto i: dat) {
                        f.putChar(i);
                    }
                    f.close();
                    updateTable();
                    ui -> statusbar -> showMessage("Date changed");
            }
            else
                ui -> statusbar -> showMessage("Try Again");

        }
        else
            ui -> statusbar -> showMessage("Open A File");
    }
    else
        ui -> statusbar -> showMessage("Select Item");
}

void MainWindow::on_tableWidget_itemSelectionChanged() {
    if (!ui -> tableWidget -> selectedRanges().isEmpty()) {
        ui -> statusbar -> showMessage("Selected column: " + QString::number(ui -> tableWidget -> selectedRanges().constFirst().leftColumn() + 1));
    }
}

bool MainWindow::isNumber(char c) {
    return c <= '9' && c >= '0';
}
