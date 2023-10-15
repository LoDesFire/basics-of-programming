#include "hexagon.h"

Hexagon::Hexagon()
{
    name = "hexagon";
}

void Hexagon::draw(QPainter *qp) {
    qp->translate(center.x() + deltaC.x(),center.y() + deltaC.y());
    qp->rotate(-rotation  - deltaR);
    QPointF arrOfPoints[6];
    for (int i = 0; i < 6; i++) {
        arrOfPoints[i] = verticies[i];
        arrOfPoints[i].rx() *= size.width() * deltaS.width();
        arrOfPoints[i].ry() *= size.width() * deltaS.width();
    }

    qp->setPen(QPen(Qt::white, 2, Qt::SolidLine));
    qp->drawPolygon(arrOfPoints, 6);

    if (mode != NONE) {
        qp->setPen(QPen(Qt::red, 3, Qt::SolidLine));
        qp->drawPoint(0, 0);
    }
}

void Hexagon::pressInInitializing(QPointF mPos) {
    center = mPos;
    size = {1.f, 1.f};
    r = 0.01f;
}

void Hexagon::moveInInitializing(QPointF mPos) {
    r = vectorModule(mPos - mouse0Pos);
    rotation = vectorAngle(mPos - center) + 60.f;
    if ((r < 0.00001f && r > -0.00001f)) {
        r = 0.01f;
    }
    for (int i = 0; i < 6; i++) {
        verticies[i].rx() = r * cos(i * 60.f * M_PI / 180.f);
        verticies[i].ry() = r * sin(i * 60.f * M_PI / 180.f);
    }
    calculateAreaPerimeter();
}

void Hexagon::releaseInInitializing() {
    mode = NONE;
}

void Hexagon::calculateAreaPerimeter() {
    float side = vectorModule(verticies[1] * size.width() * deltaS.width() - verticies[0] * size.width() * deltaS.width());
    perimeter = 3.f * side;
    area = 3.f / 2.f * side * side * sqrt(3);
}


Hexagon::~Hexagon()
{

}
