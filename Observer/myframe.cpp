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
}
void myFrame::paintEvent(QPaintEvent *)
{
    QPainter pointer(this);
    pointer.setPen(Qt::blue);
    pointer.setBrush(Qt::Dense7Pattern);
    if(!points_.isEmpty()) {
         pointer.drawLine(points_[0],points_[1]);
         pointer.drawLine(points_[1],points_[2]);
         pointer.drawLine(points_[2],points_[3]);
         pointer.drawLine(points_[3],points_[0]);
    }

}
