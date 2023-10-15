#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myTree = new MyTree();
    ui->lineEdit_character->setMaxLength(1);
}

void MainWindow::update_tree() {
    auto tree = ui->treeWidget;
    tree->clear();
    if (myTree->isEmpty()) {
        return;
    }
    auto *item = new QTreeWidgetItem(tree);
    item->setText(1, QString::fromStdString(myTree->getRoot()->data.FIO));
    item->setText(0, QString::number(myTree->getRoot()->data.ID));
    tree->addTopLevelItem(item);

    if (myTree->getRoot()->left) {
        update_tree(item, myTree->getRoot()->left);
    }
    if (myTree->getRoot()->right) {
        update_tree(item, myTree->getRoot()->right);
    }
    tree->expandAll();
}

void MainWindow::update_tree(QTreeWidgetItem *parent, Node<Human> *p) {
    auto *item = new QTreeWidgetItem(parent);
    item->setText(1, QString::fromStdString(p->data.FIO));
    item->setText(0, QString::number(p->data.ID));
    parent->addChild(item);
    if (p->left) {
        update_tree(item, p->left);
    }
    if (p->right) {
        update_tree(item, p->right);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_insert_clicked()
{
    bool ok, res = true;
    int key = ui->lineEdit_key->text().toInt(&ok);
    res &= ok;
    QString FIO = ui->lineEdit_FIO->text();
    res &= !FIO.isEmpty();

    if (!res) {
        QMessageBox::warning(this, "Grrr...", "Неверный ввод");
        return;
    }

    if (myTree->searchByKey(key, [](Node<Human>*){})) {
        QMessageBox::warning(this, "Grrr...", "Такой ключ уже существует");
        return;
    }

    myTree->insert({FIO.toStdString(), key});
    update_tree();
}


void MainWindow::on_pushButton_delete_clicked()
{
    bool ok;
    int key = ui->lineEdit_key2->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Grrr...", "Неверный ввод");
        return;
    }

    if (!myTree->searchByKey(key, [](Node<Human>*){})) {
        QMessageBox::warning(this, "Grrr...", "Покажи, бля, где?");
        return;
    }

    myTree->deleteByKey(key);
    update_tree();
}


void MainWindow::on_pushButton_search_clicked()
{
    bool ok;
    int key = ui->lineEdit_key2->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Grrr...", "Неверный ввод");
        return;
    }

    myTree->searchByKey(key, [](Node<Human>* node){
        if (!node)
            QMessageBox::warning(nullptr, "Grrr...", "Нет такого");
        else {
            QString resp = "Номер: ";
            resp += QString::number(node->data.ID);
            resp += "\nФИО: ";
            resp += node->data.FIO.c_str();
            QMessageBox::warning(nullptr, "Grrr...", resp);
        }
    });
}


void MainWindow::on_pushButton_makeTask_clicked()
{
    char c =  ui->lineEdit_character->text().toStdString().c_str()[0];

    QMessageBox::information(nullptr, "Grrr...", QString::number(myTree->makeTask(c)));

}

