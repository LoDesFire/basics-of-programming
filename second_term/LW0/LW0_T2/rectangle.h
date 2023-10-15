#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <QPainter>

class Rectangle : public Shape
{
    void pressInInitializing(QPointF) override;
    virtual void moveInInitializing(QPointF) override;
    void releaseInInitializing() override;

protected:
    virtual void calculateAreaPerimeter() override;
    float width, height;

public:
    Rectangle();
    virtual ~Rectangle();
    virtual void draw(QPainter *) override;
};

#endif // RECTANGLE_H
