#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <QPainter>

class Triangle : public Shape
{
private:
    QPointF verticies[3];
    QPointF mid;
    void pressInInitializing(QPointF) override;
    void moveInInitializing(QPointF) override;
    void releaseInInitializing() override;
    void calculateAreaPerimeter() override;
    int n;

public:
    Triangle();
    virtual ~Triangle();
    void draw(QPainter *) override;
};

#endif // TRIANGLE_H
