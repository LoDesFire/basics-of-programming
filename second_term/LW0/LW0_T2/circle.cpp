#include "circle.h"

Circle::Circle() :
    r(0)
{
    name = "circle";
}

void Circle::draw(QPainter *qp) {
    qp->translate(center.x() + deltaC.x(),center.y() + deltaC.y());
    qp->rotate(-rotation  - deltaR);

    qp->setPen(QPen(Qt::white, 2, Qt::SolidLine));
    qp->drawEllipse({0, 0}, r * size.width() * deltaS.width(), r * size.height() * deltaS.height());

    if (mode != NONE) {
        qp->setPen(QPen(Qt::red, 3, Qt::SolidLine));
        qp->drawPoint(0, 0);
    }
}

void Circle::calculateAreaPerimeter()
{
    perimeter = 2 * M_PI * r * size.width() * deltaS.width();
    area = M_PI * r * size.width() * deltaS.width() * r * size.width() * deltaS.width();
}

void Circle::pressInInitializing(QPointF mPos)
{
    center = mPos;
    size = {1.f, 1.f};
    r = 0.01f;
}

void Circle::moveInInitializing(QPointF mPos)
{
    center = mouse0Pos;
    r = vectorModule(mPos - mouse0Pos);
    size = {1.f, 1.f};
    if ((r < 0.00001f && r > -0.00001f)) {
        r = 0.01f;
    }
    calculateAreaPerimeter();
}

void Circle::releaseInInitializing()
{
//    Q_UNUSED(mPos);
    mode = NONE;
}

Circle::~Circle()
{

}
