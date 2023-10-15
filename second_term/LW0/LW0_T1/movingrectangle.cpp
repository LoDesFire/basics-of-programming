#include "movingrectangle.h"
#include "ui_movingrectangle.h"

MovingRectangle::MovingRectangle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MovingRectangle)
{
    ui->setupUi(this);
    x = 10.f;
}

void MovingRectangle::paintEvent(QPaintEvent *event) {

  Q_UNUSED(event);
  QPainter qp(this);

  drawRect(&qp);

  update();
}

void MovingRectangle::drawRect(QPainter *qp) {

  qp->translate(QPoint(x, 10.f));
  QPen pen(Qt::white, 2, Qt::SolidLine);
  qp->setPen(pen);
  qp->drawRect(0, 10, 100, 50);
  x += 0.05f;
}

void MovingRectangle::closeEvent(QCloseEvent* event )
{
    emit ClosingSignal();
    event->accept();
}

MovingRectangle::~MovingRectangle()
{
    delete ui;
}

