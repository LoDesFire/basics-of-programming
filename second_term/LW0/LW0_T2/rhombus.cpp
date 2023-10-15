#include "rhombus.h"

Rhombus::Rhombus() :
    n(0)
    , verticies{{0.f,0.f}, {0.f, 0.f}, {0.f, 0.f}, {0.f, 0.f}}
{
    name = "rhombus";
}

void Rhombus::draw(QPainter *qp) {
    if (mode != INITIALIZING) {
        qp->translate(center.x() + deltaC.x(),center.y() + deltaC.y());
    }
    qp->rotate(-rotation  - deltaR);

    QPointF arrOfPoints[4];
    for (int i = 0; i < 4; i++) {
        arrOfPoints[i] = verticies[i];
        arrOfPoints[i].rx() *= size.width() * deltaS.width();
        arrOfPoints[i].ry() *= size.height() * deltaS.height();
    }

    qp->setPen(QPen(Qt::white, 2, Qt::SolidLine));
    qp->drawPolygon(arrOfPoints, 4);

    if (mode != NONE) {
        qp->setPen(QPen(Qt::red, 3, Qt::SolidLine));
        if (mode != INITIALIZING) {
            qp->drawPoint(0, 0);
        }
        else {
            qp->drawPoint(center);
        }
    }

}

void Rhombus::calculateAreaPerimeter()
{
    QPointF arrOfPoints[4];
    for (int i = 0; i < 4; i++) {
        arrOfPoints[i] = verticies[i];
        arrOfPoints[i].rx() *= size.width() * deltaS.width();
        arrOfPoints[i].ry() *= size.height() * deltaS.height();
    }
    area = vectorModule(arrOfPoints[0] - arrOfPoints[2]) * vectorModule(arrOfPoints[1] - arrOfPoints[3]) / 2.f;
    perimeter = 4.f * vectorModule(arrOfPoints[1] - arrOfPoints[0]);
}

void Rhombus::pressInInitializing(QPointF mPos)
{
    float angle;
    if (n == 0) {
        for (int i = 0; i < 4; i++)
            verticies[i] = mPos;

    }
    else {
        angle = -vectorAngle(mPos - verticies[0]);
        verticies[2] = QPointF(verticies[1].x() + vectorModule(verticies[1] - verticies[0]) * cos(angle * M_PI / 180.f), verticies[1].y() + sin(angle * M_PI / 180.f) * vectorModule(verticies[1] - verticies[0]));
        verticies[3] = QPointF(verticies[0].x() + cos(angle * M_PI / 180.f) * vectorModule(verticies[1] - verticies[0]), verticies[0].y() + sin(angle * M_PI / 180.f) * vectorModule(verticies[1] - verticies[0]));
        center = QPointF(verticies[0].x() - (verticies[0] - verticies[2]).x() / 2, verticies[0].y() - (verticies[0] - verticies[2]).y() / 2);
        calculateAreaPerimeter();
    }
    size = {1.f, 1.f};
}

void Rhombus::moveInInitializing(QPointF mPos)
{
    float angle;
    switch(n) {
    case 0:
        verticies[1] = mPos;
        break;
    case 1:
    {
        angle = -vectorAngle(mPos - verticies[0]);
        verticies[2] = QPointF(verticies[1].x() + vectorModule(verticies[1] - verticies[0]) * cos(angle * M_PI / 180.f), verticies[1].y() + sin(angle * M_PI / 180.f) * vectorModule(verticies[1] - verticies[0]));
        verticies[3] = QPointF(verticies[0].x() + cos(angle * M_PI / 180.f) * vectorModule(verticies[1] - verticies[0]), verticies[0].y() + sin(angle * M_PI / 180.f) * vectorModule(verticies[1] - verticies[0]));
        center = QPointF(verticies[0].x() - (verticies[0] - verticies[2]).x() / 2, verticies[0].y() - (verticies[0] - verticies[2]).y() / 2);
        calculateAreaPerimeter();
        break;
    }
    }
}

void Rhombus::releaseInInitializing()
{
    if (n == 0) n = 1;
    else {
        for (int i = 0; i < 4; i++)
            verticies[i] -= center;
        mode = NONE;
    }
}

Rhombus::~Rhombus()
{

}
