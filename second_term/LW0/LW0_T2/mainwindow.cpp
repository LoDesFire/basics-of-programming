#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , figNumber(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Paint QT Application");
    shape = new Shape*[100]();
    for (int i = 0; i < 100; i++)
         shape[i] = nullptr;
}

void MainWindow::paintEvent(QPaintEvent *qe) {
    Q_UNUSED(qe);
    for (int i = 0; i < 100; i++) {
        if (shape[i]) {
            QPainter *qp = new QPainter(this);
            qp->setClipRect(10, 60, 600, 452);

            shape[i]->draw(qp);

            qp->end();
            delete qp;
        }
    }

    if (shape[figNumber]) {
        ui->label_currentFigure->setText("№" + QString::number(figNumber + 1) + " - " + shape[figNumber]->name);
        if (shape[figNumber]->getMode() == Shape::NONE)
            turnOfftheMode();
        if (shape[figNumber]->getArea() == -1) {
            ui->label_area->setText("is protected");
            ui->label_perimeter->setText("belongs to the USSR");
            this->setWindowTitle("Welcome to the BSSR");
        }
        else {
            this->setWindowTitle("Paint QT Application");
            ui->label_area->setText(QString::number(shape[figNumber]->getArea()));
            ui->label_perimeter->setText(QString::number(shape[figNumber]->getPerimeter()));
        }
    }
    else {
        ui->label_currentFigure->setText("№" + QString::number(figNumber + 1) + " - empty");
        ui->label_area->setText("N/D");
        ui->label_perimeter->setText("N/D");
        ui->pushButton_move->setEnabled(false);
        ui->pushButton_resize->setEnabled(false);
        ui->pushButton_rotate->setEnabled(false);
    }
    update();
}

/// Processing of mouse actions

void MainWindow::mousePressEvent(QMouseEvent* me) {
    if (shape[figNumber]) {
        shape[figNumber]->shapeMousePressEvent(me);

        switch(shape[figNumber]->getMode()) {
        case Shape::ROTATING:
            this->setCursor(Qt::ClosedHandCursor);
            break;
        case Shape::RESIZING:
            this->setCursor(Qt::PointingHandCursor);
            break;
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *me) {
    if (shape[figNumber]) {
        shape[figNumber]->shapeMouseMoveEvent(me);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *me) {
    Q_UNUSED(me);
    if (shape[figNumber]) {
        shape[figNumber]->shapeMouseReleaseEvent();

        switch(shape[figNumber]->getMode()) {
        case Shape::MOVING:
            this->setCursor(Qt::SizeAllCursor);
            break;
        case Shape::ROTATING:
            this->setCursor(Qt::OpenHandCursor);
            break;
        case Shape::RESIZING:
            this->setCursor(Qt::OpenHandCursor);
            break;
        }
    }
}

/// Processing of buttons

void MainWindow::on_pushButton_move_clicked()
{
    if (shape[figNumber]->getMode() == Shape::NONE) {
        shape[figNumber]->setMode(Shape::MOVING);
        this->setCursor(Qt::SizeAllCursor);
        ui->statusBar->showMessage("Moving mode");
        ui->pushButton_resize->setEnabled(false);
        ui->pushButton_rotate->setEnabled(false);
    }
    else {
        turnOfftheMode();
    }
}

void MainWindow::on_pushButton_rotate_clicked()
{
    if (shape[figNumber]->getMode() == Shape::NONE) {
        shape[figNumber]->setMode(Shape::ROTATING);
        this->setCursor(Qt::OpenHandCursor);
        ui->statusBar->showMessage("Rotating mode");
        ui->pushButton_resize->setEnabled(false);
        ui->pushButton_move->setEnabled(false);
    }
    else {
        turnOfftheMode();
    }
}

void MainWindow::on_pushButton_resize_clicked()
{
    if (shape[figNumber]->getMode() == Shape::NONE) {
        shape[figNumber]->setMode(Shape::RESIZING);
        this->setCursor(Qt::OpenHandCursor);
        ui->statusBar->showMessage("Scaling mode");
        ui->pushButton_move->setEnabled(false);
        ui->pushButton_rotate->setEnabled(false);
    }
    else {
        turnOfftheMode();
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    turnOfftheMode();
    ui->pushButton_move->setEnabled(false);
    ui->pushButton_resize->setEnabled(false);
    ui->pushButton_rotate->setEnabled(false);
    int n = 8;
    if (shape[figNumber]) {
        delete shape[figNumber];
        shape[figNumber] = nullptr;
    }

    switch(index) {
    case 0:
        this->setCursor(Qt::ArrowCursor);
        break;
    case 1:
        shape[figNumber] = new Triangle();
        break;
    case 2:
        shape[figNumber] = new Circle();
        break;
    case 3:
        shape[figNumber] = new Rhombus();
        break;
    case 4:
        shape[figNumber] = new Square();
        break;
    case 5:
        shape[figNumber] = new Rectangle();
        break;
    case 6:
        n -= 1;
    case 7:
        n -= 2;
    case 8:
        shape[figNumber] = new Star(n);
        break;
    case 9:
        shape[figNumber] = new Hexagon();
        break;
    case 10:
        shape[figNumber] = new MyFigure();
        break;
    }

    if (shape[figNumber]) {
        shape[figNumber]->setMode(Shape::INITIALIZING);
        this->setCursor(Qt::PointingHandCursor);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ke) {
    switch(ke->key()) {
    case Qt::Key_Escape:
        {
            if (shape[figNumber]) {
                switch(shape[figNumber]->getMode()) {
                case Shape::INITIALIZING:
                    ui->comboBox->setCurrentIndex(0);
                    break;
                default:
                    turnOfftheMode();
                    break;
                }
            }
            break;
        }
    }
}

void MainWindow::turnOfftheMode() {
    if (shape[figNumber]) {
        shape[figNumber]->setMode(Shape::NONE);
        shape[figNumber]->shapeMouseReleaseEvent();
    }

    this->setCursor(Qt::ArrowCursor);

    ui->pushButton_resize->setEnabled(true);
    ui->pushButton_rotate->setEnabled(true);
    ui->pushButton_move->setEnabled(true);
    ui->statusBar->showMessage("");
}

void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < 100; i++) {
        if (shape[i]) {
           delete shape[i];
            shape[i] = nullptr;
        }
    }
    ui->comboBox->setCurrentIndex(0);
    figNumber = 0;
}


void MainWindow::on_pushButton_2_clicked()
{
    if (figNumber < 100 && shape[figNumber]) {
        if (shape[figNumber]->getMode() != Shape::INITIALIZING) {

            shape[figNumber]->shapeMouseReleaseEvent();
            turnOfftheMode();
            figNumber++;
            ui->comboBox->setCurrentIndex(0);
        }
        else {
            ui->comboBox->setCurrentIndex(0);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
