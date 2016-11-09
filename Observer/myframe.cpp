#include "myframe.h"

myFrame::myFrame(QWidget *parent):QFrame(parent)
{

}

void myFrame::setLinePos(QVector<QPoint> &points)
{
    points_.clear();
    for(auto &iter:points) {
        points_.push_back(iter);
    }
    RepaintLines();
}

QVector<QPoint> &myFrame::getPoints()
{
    return points_;
}
void myFrame::paintEvent(QPaintEvent *)
{
    RepaintLines();
}

void myFrame::RepaintLines()
{
    painter_.begin(this);
    QPen pen(Qt::DashLine);
    pen.setColor(Qt::blue);
    painter_.setPen(pen);
    if(!points_.isEmpty()) {
         painter_.drawLine(points_[0],points_[1]);
         painter_.drawLine(points_[1],points_[2]);
         painter_.drawLine(points_[2],points_[3]);
         painter_.drawLine(points_[3],points_[0]);
    }
    painter_.end();
    update();
}
