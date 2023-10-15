#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"
#include <QPainter>

class Hexagon : public Shape
{
    void pressInInitializing(QPointF) override;
    void moveInInitializing(QPointF) override;
    void releaseInInitializing() override;
    void calculateAreaPerimeter() override;
    QPointF verticies[6];
    float r;

public:
    Hexagon();
    virtual ~Hexagon();
    void draw(QPainter *) override;
};

#endif // HEXAGON_H
