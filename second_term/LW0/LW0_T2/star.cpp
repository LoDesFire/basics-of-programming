#include "star.h"

Star::Star(int N) :
    counter(0)
{
    n = 2 * N;
    verticies = new QPointF[n];
    name = "star #" + QString::number(n / 2);
}

void Star::draw(QPainter *qp) {
    qp->translate(center.x() + deltaC.x(),center.y() + deltaC.y());
    qp->rotate(-rotation  - deltaR);
    if (mode != INITIALIZING) {
        QPointF *arrOfPoints = new QPointF[n];
        for (int i = 0; i < n; i++) {
            arrOfPoints[i] = verticies[i];
            arrOfPoints[i] *= size.width() * deltaS.width();
            arrOfPoints[i] *= size.height() * deltaS.height();
        }

        qp->setPen(QPen(Qt::white, 2, Qt::SolidLine));
        qp->drawPolygon(arrOfPoints, n);
        delete[] arrOfPoints;

        if (mode != NONE) {
            qp->setPen(QPen(Qt::red, 3, Qt::SolidLine));
            qp->drawPoint(0, 0);
        }
    }
    else {
        if (counter < 2) {
            qp->setPen(QPen(Qt::blue, 4, Qt::SolidLine));
            for (int i = 0; i < n; i += 2)
                qp->drawPoint(verticies[i]);
        }
        else {
            qp->setPen(QPen(Qt::white, 2, Qt::SolidLine));
            qp->drawPolygon(verticies, n);

            qp->setPen(QPen(Qt::blue, 4, Qt::SolidLine));
            for (int i = 1; i < n; i += 2)
                qp->drawPoint(verticies[i]);
        }
        qp->setPen(QPen(Qt::red, 3, Qt::SolidLine));
        qp->drawPoint(0, 0);
    }

}

void Star::pressInInitializing(QPointF mPos) {
    float increment = 360 / n;
    size = {1.f, 1.f};

    for (int i = (!counter ? 0 : 1) ; i < n; i += 2) {
        if (!counter) center = mPos;
        verticies[i].rx() = 0.01f * cos(i * increment * M_PI / 180.f);
        verticies[i].ry() = 0.01f * sin(i * increment * M_PI / 180.f);
    }
}
void Star::moveInInitializing(QPointF mPos) {
    float r = vectorModule(mPos - center);
    float increment = 360 / n;

    for (int i = (!counter ? 0 : 1); i < n; i += 2) {
        if (counter) {
            counter = 2;
            rotation = vectorAngle(mPos - center) + increment;
            calculateAreaPerimeter();
        }
        verticies[i].rx() = fmax(r, 0.01f) * cos(i * increment * M_PI / 180.f);
        verticies[i].ry() = fmax(r, 0.01f) * sin(i * increment * M_PI / 180.f);
    }

}
void Star::releaseInInitializing() {
    if (!counter) counter = 1;
    else {
        mode = NONE;
    }
}
void Star::calculateAreaPerimeter() {
    area = 0;
    int k = (vectorModule(verticies[0]) > vectorModule(verticies[1]) ? 1 : 0);

    QPointF *arrOfPoints = new QPointF[n];
    for (int i = 0; i < n; i++) {
        arrOfPoints[i] = verticies[i];
        arrOfPoints[i] *= size.width() * deltaS.width();
        arrOfPoints[i] *= size.height() * deltaS.height();
    }

    QPointF vectors[4];
    vectors[0] = (arrOfPoints[k + 1] - arrOfPoints[k]) ;
    vectors[1] = (arrOfPoints[k + 1] - arrOfPoints[k + 2]);
    vectors[2] = arrOfPoints[k] ;
    vectors[3] = arrOfPoints[k + 2] ;
    delete[] arrOfPoints;

    float ang = vectorAngle(vectors[1]) - vectorAngle(vectors[0]);
    area += fabs(sin(ang * M_PI / 180.f)) * 1.f/2.f * vectorModule(vectors[0]) * vectorModule(vectors[1]);

    ang =  vectorAngle(vectors[3]) - vectorAngle(vectors[2]);
    area += fabs(sin(ang * M_PI / 180.f)) * 1.f/2.f * vectorModule(vectors[2]) * vectorModule(vectors[3]);

    area *= n / 2.f;

    perimeter = n / 2 * (vectorModule(vectors[0]) + vectorModule(vectors[1]));
}

Star::~Star()
{
    delete[] verticies;
}

