#include "steamlocomotive.h"
#include "ui_steamlocomotive.h"

SteamLocomotive::SteamLocomotive(MovingRectangle *parent) :
    MovingRectangle(parent),
    ui(new Ui::SteamLocomotive)
{
    ui->setupUi(this);
    smoke = new Circle[10];
    for (int i = 0; i < 10; i++) {
        smoke[i].x = 150.f;
        smoke[i].y = 90.f;
        smoke[i].r = 1.f;
    }
}

void SteamLocomotive::drawRect(QPainter *qp){


    QPen pen(Qt::white, 1, Qt::SolidLine);
    qp->setPen(pen);
    QPoint triangle[][3] = {
        {{120, 140}, {100, 180}, {120, 220}},
        {{120, 220}, {120, 260}, {60, 260}},
        {{140, 100}, {150, 90}, {160, 100}},
        {{240, 60}, {320, 60}, {280, 20}},
    };
    for (int i = 0; i < 4; i++) {
        qp->drawPolygon(triangle[i], 3);
    }
    QRect rectangle[] = {
        {120, 140, 120, 80},
        {240, 60, 80, 160},
        {140, 100, 20, 40},
        {260, 100, 40, 40},
    };
    for (int i = 0; i < 4; i++) {
        qp->drawRect(rectangle[i]);
    }
    for (int i = 0; i < 5; i++) {
        qp->drawEllipse(120 + 40 * i, 220, 40, 40);
    }

    for (int i = 0; i < 10; i++) {
        if (smoke[i].y < -5 * i) {
            smoke[i].x = 150.f;
            smoke[i].y = 90.f;
            smoke[i].r = 1.f;
        }
        QPen pen(Qt::white, 0.3, Qt::SolidLine);
        qp->setPen(pen);
        smoke[i].r += 0.001f * i;
        smoke[i].y -= 0.002f * i;
        qp->drawEllipse(smoke[i].x - smoke[i].r, smoke[i].y - smoke[i].r, smoke[i].r * 2, smoke[i].r*2);
    }



}

SteamLocomotive::~SteamLocomotive()
{
    delete ui;
    delete[] smoke;
}
