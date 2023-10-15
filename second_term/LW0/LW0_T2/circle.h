#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>
#include "shape.h"

class Circle : public Shape
{
public:
    Circle();
    void draw(QPainter *) override;
    virtual ~Circle();

private:
    float r;
    void pressInInitializing(QPointF) override;
    void moveInInitializing(QPointF) override;
    void releaseInInitializing() override;
    void calculateAreaPerimeter() override;
};

#endif // CIRCLE_H
