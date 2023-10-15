#ifndef STAR_H
#define STAR_H

#include <QWidget>
#include <QDebug>
#include "shape.h"

class Star : public Shape
{
    void pressInInitializing(QPointF) override;
    void moveInInitializing(QPointF) override;
    void releaseInInitializing() override;
    void calculateAreaPerimeter() override;
    int n, counter;
    QPointF *verticies;

public:
    Star(int);
    virtual ~Star();
    void draw(QPainter *) override;
};

#endif // STAR_H
