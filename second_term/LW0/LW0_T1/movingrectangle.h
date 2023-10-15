#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H

#include <QWidget>
#include <QCloseEvent>
#include <QPainter>

namespace Ui {
class MovingRectangle;
}

class MovingRectangle : public QWidget
{
    Q_OBJECT

public:
    explicit MovingRectangle(QWidget *parent = nullptr);
    ~MovingRectangle();

signals:
    void ClosingSignal();

private:
    Ui::MovingRectangle *ui;
    float x;

protected:
    void closeEvent(QCloseEvent*);
    void paintEvent(QPaintEvent *);
    virtual void drawRect(QPainter *);

};

#endif // MOVINGRECTANGLE_H
