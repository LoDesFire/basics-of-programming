#ifndef MYFIGURE_H
#define MYFIGURE_H

#include "rectangle.h"
#include "shape.h"
#include <QPainter>
#include <QVector>

class MyFigure : public Shape
{
    QVector<QPointF> list;
    void calculateAreaPerimeter() override;

public:
    MyFigure();
    virtual ~MyFigure();
    void pressInInitializing(QPointF) override;
    void moveInInitializing(QPointF) override;
    void releaseInInitializing() override;
    void draw(QPainter *) override;
};

#endif // MYFIGURE_H
