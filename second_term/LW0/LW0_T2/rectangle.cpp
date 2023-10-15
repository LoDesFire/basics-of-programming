#include "rectangle.h"

Rectangle::Rectangle() :
    width(0.01f)
    , height(0.01f)
{
    name = "rectangle";
}

void Rectangle::draw(QPainter *qp) {
    qp->translate(center.x() + deltaC.x(),center.y() + deltaC.y());
    qp->rotate(-rotation  - deltaR);

    qp->setPen(QPen(Qt::white, 2, Qt::SolidLine));
    qp->drawRect(-width * size.width() * deltaS.width() / 2, -height * size.height() * deltaS.height() / 2, width * size.width() * deltaS.width(), height * size.height() * deltaS.height());

    if (mode != NONE) {
        qp->setPen(QPen(Qt::red, 3, Qt::SolidLine));
        qp->drawPoint(0, 0);
    }
}

void Rectangle::calculateAreaPerimeter()
{
    area = fabs(width * size.width() * deltaS.width() * height * size.height() * deltaS.height());
    perimeter = fabs(2 * width * size.width() * deltaS.width()) + fabs(2 * height * size.height() * deltaS.height());
}

void Rectangle::pressInInitializing(QPointF mPos)
{
    center = QPointF(mPos);
    width = 0.01f;
    height = 0.01f;
    size = {1.f, 1.f};
    calculateAreaPerimeter();
}

void Rectangle::moveInInitializing(QPointF mPos)
{
    center = mouse0Pos + (mPos - mouse0Pos) / 2;
    width = mPos.x() - mouse0Pos.x();
    height = mPos.y() - mouse0Pos.y();
    calculateAreaPerimeter();
    if ((width < 0.00001f && width > -0.00001f)) {
        width = 0.01f;
    }

    if  (height < 0.00001f && height > -0.00001f) {
        height = 0.01f;
    }
}

void Rectangle::releaseInInitializing()
{
     mode = NONE;
}

Rectangle::~Rectangle()
{

}
