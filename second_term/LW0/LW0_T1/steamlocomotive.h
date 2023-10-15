#ifndef STEAMLOCOMOTIVE_H
#define STEAMLOCOMOTIVE_H

#include "movingrectangle.h"
#include <QWidget>

struct circle {
   float x, y, r;
};

using Circle = struct circle;

namespace Ui {
class SteamLocomotive;
}

class SteamLocomotive : public MovingRectangle
{
    Q_OBJECT

public:
    explicit SteamLocomotive(MovingRectangle *parent = nullptr);
    ~SteamLocomotive();

private:
    Ui::SteamLocomotive *ui;
    Circle *smoke;


protected:
    void drawRect(QPainter *) override;

};

#endif // STEAMLOCOMOTIVE_H
