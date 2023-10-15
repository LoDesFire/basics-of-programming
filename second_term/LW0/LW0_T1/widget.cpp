#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("aboba");
    mr = nullptr;
    sl = nullptr;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_MovingRectangle_clicked()
{
    mr = new MovingRectangle();
    mr->setWindowTitle("MovingRectangle");
    connect(mr, &MovingRectangle::ClosingSignal, this, &Widget::on_MovingRectangleclosed);

    hide();

    mr->show();

}


void Widget::on_pushButton_SteamLocomotive_clicked()
{
    sl = new SteamLocomotive();
    sl->setWindowTitle("Chuh-chuh");
    connect(sl, &SteamLocomotive::ClosingSignal, this, &Widget::on_SteamLocomotiveclosed);

    hide();

    sl->show();

}

void Widget::on_MovingRectangleclosed()
{
    disconnect(mr, &MovingRectangle::ClosingSignal, this, &Widget::on_MovingRectangleclosed);
    delete mr;
    mr = nullptr;

    qDebug() << "Succesfully_closed_the_window\n";

    show();
}

void Widget::on_SteamLocomotiveclosed()
{
    disconnect(sl, &SteamLocomotive::ClosingSignal, this, &Widget::on_SteamLocomotiveclosed);
    delete sl;
    sl = nullptr;

    qDebug() << "Succesfully_closed_the_window\n";

    show();
}
