#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include <QMouseEvent>

class Shape
{
private:
    void move(QPointF);
    void setLocation();
    void rotate(QPointF);
    void setRotation();
    void resize(QPointF);
    void setSize();

protected:
    QPointF center, deltaC;
    QSizeF size, deltaS;
    float rotation, deltaR;
    float area, perimeter;
    int mode;
    QPointF mouse0Pos;
    QPointF findCenterOfTriangle(QPointF *);
    int sign(float);
    float vectorAngle(QPointF);
    float vectorModule(QPointF);
    virtual void pressInInitializing(QPointF);
    virtual void moveInInitializing(QPointF);
    virtual void releaseInInitializing();
    virtual void calculateAreaPerimeter();

public:
    Shape();
    virtual ~Shape();
    virtual void draw(QPainter *);
    void shapeMousePressEvent(QMouseEvent *);
    void shapeMouseMoveEvent(QMouseEvent *);
    void shapeMouseReleaseEvent();
    void setMode(int);
    int getMode();
    float getArea();
    float getPerimeter();
    QString name;
    enum Modes
    {
        NONE,
        MOVING,
        ROTATING,
        RESIZING,
        INITIALIZING,
    };
};

#endif // SHAPE_H
