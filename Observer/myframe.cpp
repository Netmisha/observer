#include "myframe.h"

myFrame::myFrame(QWidget *parent):QFrame(parent)
{

}

myFrame::~myFrame()
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
void myFrame::paintEvent(QPaintEvent *)
{
    RepaintLines();
}

void myFrame::RepaintLines()
{
    painter_.begin(this);
    painter_.setPen(Qt::blue);
    painter_.setBrush(Qt::Dense7Pattern);
    if(!points_.isEmpty()) {
         painter_.drawLine(points_[0],points_[1]);
         painter_.drawLine(points_[1],points_[2]);
         painter_.drawLine(points_[2],points_[3]);
         painter_.drawLine(points_[3],points_[0]);
    }
    painter_.end();
    update();
}
