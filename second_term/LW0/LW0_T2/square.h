#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"
#include <QPainter>

class Square : public Rectangle
{
    void moveInInitializing(QPointF) override;

public:
    Square();
    virtual ~Square();
};

#endif // SQUARE_H
