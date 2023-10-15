#ifndef RHOMBUS_H
#define RHOMBUS_H


#include "rectangle.h"
#include <QPainter>
#include <QDebug>

class Rhombus : public Shape
{
public:
    Rhombus();
    void draw(QPainter *) override;
    virtual ~Rhombus();
private:
    void pressInInitializing(QPointF) override;
    void moveInInitializing(QPointF) override;
    void releaseInInitializing() override;
    void calculateAreaPerimeter() override;
    int n;
    QPointF verticies[4];
};

#endif // RHOMBUS_H
