#include "triangle.h"

Triangle::Triangle() :
    verticies{{0.f,0.f}, {0.f, 0.f}, {0.f, 0.f}}
    , n(0)
{
    name = "triangle";
}

void Triangle::pressInInitializing(QPointF mPos){
    verticies[n++] =  mPos;
    if (n == 3) {
        mode = NONE;
        mid = findCenterOfTriangle(verticies);
        for (int i = 0; i < 3; i++) {
            verticies[i].rx() -= mid.x();
            verticies[i].ry() -= mid.y();
        }
        center = mid;
        deltaC = {0.f, 0.f};
        calculateAreaPerimeter();
    }
}

void Triangle::moveInInitializing(QPointF mPos){
    Q_UNUSED(mPos);
}

void Triangle::releaseInInitializing(){

}

void Triangle::draw(QPainter *qp) {
    if (mode != INITIALIZING) {

        qp->translate(center.x() + deltaC.x(),center.y() + deltaC.y());
        qp->rotate(-rotation  - deltaR);
        qp->setPen(QPen(Qt::white, 2, Qt::SolidLine));
        QPointF arrOfPoints[3];
        for (int i = 0; i < 3; i++) {
            arrOfPoints[i] = verticies[i];
            arrOfPoints[i].rx() *= size.width() * deltaS.width();
            arrOfPoints[i].ry() *= size.width() * deltaS.width();
        }
        qp->drawPolygon(arrOfPoints, 3);
        if (mode != NONE) {
            qp->setPen(QPen(Qt::red, 3, Qt::SolidLine));
            qp->drawPoint(0, 0);
        }
    }
    else {
        qp->setPen(QPen(Qt::red, 3, Qt::SolidLine));
        for (int i = 0; i < 3; i++) {
            qp->drawPoint(verticies[i]);
        }
    }
}

void Triangle::calculateAreaPerimeter() {
    perimeter = 0;
    QPointF arrOfPoints[3];
    for (int i = 0; i < 3; i++) {
        arrOfPoints[i] = verticies[i];
        arrOfPoints[i].rx() *= size.width() * deltaS.width();
        arrOfPoints[i].ry() *= size.width() * deltaS.width();
    }
    QPointF vectors[3];
    for (int i = 0; i < 3; i++) {
        vectors[i] = arrOfPoints[i] - arrOfPoints[(i + 1) % 3];
        perimeter += vectorModule(vectors[i]);
    }
    float ang = vectorAngle(vectors[0]) - vectorAngle(vectors[1]);
    area = fabs(sin(ang * M_PI / 180.f)) * 1.f/2.f * vectorModule(vectors[0]) * vectorModule(vectors[1]);
}

Triangle::~Triangle()
{

}

