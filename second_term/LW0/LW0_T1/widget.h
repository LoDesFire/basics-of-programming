#ifndef WIDGET_H
#define WIDGET_H

#include "movingrectangle.h"
#include "steamlocomotive.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_pushButton_MovingRectangle_clicked();

    void on_pushButton_SteamLocomotive_clicked();

    void on_MovingRectangleclosed();

    void on_SteamLocomotiveclosed();

private:
    Ui::Widget *ui;
    MovingRectangle *mr;
    SteamLocomotive *sl;
};
#endif // WIDGET_H
