#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , s(nullptr)
{
    ui->setupUi(this);
    s = new Stack;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    fs = new FileStream(QFileDialog::getOpenFileName(this, "Open File", "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW2_T2/"));
    checkFile();
}


void MainWindow::checkFile() {
    QString input;
    s->clear();
    int n = 0;
    int opened = 0;
    while (fs->readLineFromFile(input)) {
        for (int i = 0; i < input.length(); i++) {
            bool isValid = true;
            switch (input.toStdString()[i]) {
            case '(':
                s->push('(', n + 1, i + 1);
                opened++;
                break;
            case ')':
                if (s->empty()) {
                    isValid = false;
                    s->push(')', n + 1, i + 1);
                    break;
                }
                if (s->top().c != '(')
                    isValid = false;
                else {
                    s->pop();
                    opened--;
                }
                break;
            case '{':
                s->push('{', n + 1, i + 1);
                opened++;
                break;
            case '}':
                if (s->empty()) {
                    isValid = false;
                    s->push('}', n + 1, i + 1);
                    break;
                }
                if (s->top().c != '{')
                    isValid = false;
                else {
                    s->pop();
                    opened--;
                }
                break;
            case '[':
                s->push('[', n + 1, i + 1);
                opened++;
                break;
            case ']':
                if (s->empty()) {
                    isValid = false;
                    s->push(']', n + 1, i + 1);
                    break;
                }
                if (s->top().c != '[')
                    isValid = false;
                else {
                    s->pop();
                    opened--;
                }
                break;
            default:
                break;
            }

            if (!isValid) {
                QMessageBox::warning(this, "Warning", "Warning:\nrow: " + QString::number(s->top().row) + "\nindex: " + QString::number(s->top().index));
                return;
            }
        }
        n++;
    }

    if (opened)
        QMessageBox::warning(this, "Warning", "Warning:\nrow: " + QString::number(s->top().row) + "\nindex: " + QString::number(s->top().index));
    else
        QMessageBox::information(this, "Success", "Pretty file");
}


void MainWindow::on_pushButton_clicked()
{
    QString input = ui->plainTextEdit->toPlainText();
    fs = new FileStream("/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW2_T2/tmp.txt");
    fs->saveToFile(input);
    fs->toBegin();
    checkFile();
    fs->removeFile();
    delete fs;
}

