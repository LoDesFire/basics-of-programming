#include "shape.h"

Shape::Shape() :
    center(0.f,0.f)
    , size(1.f,1.f)
    , deltaS(1.f, 1.f)
    , rotation(0.f)
    , deltaR(0.f)
    , area(0.f)
    , perimeter(0.f)
{

}

void Shape::shapeMousePressEvent(QMouseEvent *me) {
    if (mode != NONE) {
        mouse0Pos = me->pos();
    }
    if (mode == INITIALIZING) {
        pressInInitializing(me->pos());
    }
}

void Shape::shapeMouseMoveEvent(QMouseEvent *me) {
    switch(mode) {
    case MOVING:
        move(me->pos());
        break;
    case ROTATING:
        rotate(me->pos());
        break;
    case RESIZING:
        resize(me->pos());
        break;
    case INITIALIZING:
        moveInInitializing(me->pos());
        break;
    }
}

void Shape::shapeMouseReleaseEvent() {
    switch(mode) {
    case INITIALIZING:
        releaseInInitializing();
        break;
    case RESIZING:
         setSize();
        break;
    case ROTATING:
        setRotation();
        break;
    case MOVING:
        setLocation();
        break;
    }
}

/// Animation while moving

void Shape::move(QPointF d) {
    deltaC = d - mouse0Pos;
}

void Shape::setLocation() {
    center += deltaC;
    deltaC = {0, 0};
}

/// Animation while rotating

void Shape::rotate(QPointF b) {
    deltaR = vectorAngle(b - center) - vectorAngle(mouse0Pos - center);
}

void Shape::setRotation() {
    rotation += deltaR;
    deltaR = 0.f;
}

/// Animation while resizing

void Shape::resize(QPointF b) {
    if (mouse0Pos - center == QPointF(0.f, 0.f)) {
        deltaS = {1.f, 1.f};
    }
    else {
        float tmp = vectorModule(b - center) / vectorModule(mouse0Pos- center);
        deltaS = {tmp, tmp};
    }
    if (deltaS.width() * size.width() <= 1e-4 || deltaS.height() * size.height() <= 1e-4) {
        float fakeSize = fmin(size.width(), size.height());
        if (fakeSize != 0.f)
            deltaS  = {1e-4 / fakeSize, 1e-4 / fakeSize};
        else
            deltaS  = {1.f, 1.f};
    }
    else {
        if (deltaS.width() * size.width() >= 1e4 || deltaS.height() * size.height() >= 1e4) {
            float fakeSize = fmax(size.width(), size.height());
            if (fakeSize != 0.f)
                deltaS  = {1e4 / fakeSize, 1e4 / fakeSize};
            else
                deltaS  = {1.f, 1.f};
        }
    }
    calculateAreaPerimeter();
}

void Shape::setSize() {
    size.rwidth() *= deltaS.width();
    size.rheight() *= deltaS.height();

    deltaS = {1.f, 1.f};
    calculateAreaPerimeter();
}

/// Useful functions

float Shape::vectorModule(QPointF b) {
    return sqrt((b.x() * b.x() + b.y() * b.y()));
}

float Shape::vectorAngle(QPointF b) {
    if (b.x() != 0 || b.y() != 0) {
        float sinB = b.y() / vectorModule(b), cosB = b.x() / vectorModule(b), ang = 0;

        if (sinB > 0 && cosB < 0) {
            ang = asin(sinB) * 180.f / M_PI + 180.f;
        }
        else {
            if (cosB >= 0 && sinB > 0) {
                ang = 360.f - asin(sinB) * 180.f / M_PI;
            }
            else
                ang = acos(cosB) * 180.f / M_PI;
        }
        return ang;
    }
    else {
        return 0;
    }
}

QPointF Shape::findCenterOfTriangle(QPointF *triangle)
{
    QPointF mid = {(triangle[0].x() + triangle[1].x())/2.f, (triangle[0].y() + triangle[1].y())/2.f};
    return {(triangle[2].x() + 2.f * mid.x())/3.f, (triangle[2].y() + 2.f * mid.y())/3.f};
}

int Shape::sign(float f)
{
    return (f < 0.f ? -1 : (f == 0.f ? 0 : 1));
}


/// getters | setters
void Shape::setMode(int md) {
    mode = md;
}

int Shape::getMode() {
    return mode;
}

float Shape::getArea() {
    return area;
}

float Shape::getPerimeter() {
    return perimeter;
}




void Shape::draw(QPainter* qp) {
    Q_UNUSED(qp);
}

void Shape::calculateAreaPerimeter() {

}

void Shape::pressInInitializing(QPointF mPos) {
    Q_UNUSED(mPos);
}

void Shape::moveInInitializing(QPointF mPos) {
    Q_UNUSED(mPos);
}
void Shape::releaseInInitializing() {

}

Shape::~Shape()
{}



