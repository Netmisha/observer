#include "myqframe.h"

MyQFrame::MyQFrame(QWidget *parent): QFrame(parent)
{

}
void MyQFrame::setLinePos(QVector<QPoint> &points)
{
    points_.clear();
    for(auto &iter:points) {
        points_.push_back(iter);
    }
}
QVector<QPoint> & MyQFrame::getPoints()
{
    return points_;
}
void MyQFrame::paintEvent(QPaintEvent *)
{
    RepaintLines();
}
void MyQFrame::RepaintLines()
{
    QPen pen(Qt::DashLine);
    pen.setColor(Qt::blue);
    painter_.begin(this);
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
