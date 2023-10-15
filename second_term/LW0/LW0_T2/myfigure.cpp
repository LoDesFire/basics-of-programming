#include "myfigure.h"

MyFigure::MyFigure()
{
    name = "N/D";
}

void MyFigure::draw(QPainter *qp) {
    qp->translate(center.x() + deltaC.x(),center.y() + deltaC.y());
    qp->rotate(-rotation  - deltaR);

//    QPointF serp[41] = {
//        {-3, -10.1}, {-2, -11.1}, {0, -11.4}, {2, -11.1}, {4, -10.4}, {6, -9}, {8, -7}, {9, -5}, {9.5, -3}, {9.7, -1}, {9.2, 1},
//        {8.7, 3}, {8.1, 4}, {10, 5.2}, {8.3, 7.3}, {6.8, 6}, {5, 7}, {3, 8}, {1, 8.9}, {-1, 8.8}, {-3.1, 8}, {-5, 7}, {-5.9, 6.9},
//        {-7, 8.9}, {-8, 10.5}, {-9, 10.5}, {-9.8, 10}, {-10.1, 9.1}, {-6.1, 4.9}, {-3.8, 6}, {-2, 6.5}, {0, 6.5}, {2, 6}, {4, 4.9},
//        {6, 3}, {7, 0}, {7, -4}, {6, -6}, {4, -8}, {1, -9.8}, {-1, -10.2},
//    };
//    QPointF molot[9] = {
//        {3.9, 4}, {5.4, 2.5}, {-5.4, -5.9}, {-3, -9}, {-4.3, -10.1}, {-7.4, -9}, {-12, -3}, {-9, -1}, {-7, -4},
//    };
//    for (int i = 0; i < 41; i++) {
//        serp[i].rx() *= width * size.width() * deltaS.width() / 22.f;
//        serp[i].ry() *= height * size.height() * deltaS.height() / 22.f;
//        if (i < 9) {
//            molot[i].rx() *= width * size.width() * deltaS.width() / 22.f;
//            molot[i].ry() *= height * size.height() * deltaS.height() / 22.f;
//        }
//    }

//    qp->setPen(QPen(Qt::white, 2, Qt::SolidLine));
//    qp->drawPolygon(serp, 41);
//    qp->drawPolygon(molot, 9);

    for (auto i = list.begin(); i < list.end() - 1; i++)
        qp->drawLine(*i, *(i+1));


    if (mode != NONE) {
        qp->setPen(QPen(Qt::red, 3, Qt::SolidLine));
        qp->drawPoint(0, 0);
    }
}

void MyFigure::calculateAreaPerimeter() {
    area = -1;
}


MyFigure::~MyFigure()
{

}

void MyFigure::pressInInitializing(QPointF mPos){
    list.push_back(mPos);
}

void MyFigure::moveInInitializing(QPointF mPos){
    Q_UNUSED(mPos);
    list.push_back(mPos);
}

void MyFigure::releaseInInitializing(){

}
