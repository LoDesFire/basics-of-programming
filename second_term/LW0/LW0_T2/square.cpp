#include "square.h"

Square::Square()
{
    name = "square";
}

void Square::moveInInitializing(QPointF mPos)
{
    float side = vectorModule(mPos - mouse0Pos) / sqrt(2), orientX = sign((mPos - mouse0Pos).x()), orientY = sign((mPos - mouse0Pos).y());
    orientX = (orientX ? orientX : 1);
    orientY = (orientY ? orientY : 1);
    center = mouse0Pos + QPointF(side* orientX, side * orientY) / 2;
    width = side * orientX;
    height = side* orientY;
    if ((width < 0.00001f && width > -0.00001f))
        width = 0.01f;
    if ((height < 0.00001f && height > -0.00001f))
        height = 0.01f;
    calculateAreaPerimeter();
}

Square::~Square()
{

}
