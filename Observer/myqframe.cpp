#include "myqframe.h"

MyQFrame::MyQFrame(QWidget *parent): QFrame(parent)
{

}
<<<<<<< HEAD:Observer/myframe.cpp

myFrame::~myFrame()
{

}

void myFrame::setLinePos(QVector<QPoint> &points)
=======
void MyQFrame::setLinePos(QVector<QPoint> &points)
>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301:Observer/myqframe.cpp
{
    points_.clear();
    for(auto &iter:points) {
        points_.push_back(iter);
    }
}
<<<<<<< HEAD:Observer/myframe.cpp
void myFrame::paintEvent(QPaintEvent *)
=======
QVector<QPoint> & MyQFrame::getPoints()
{
    return points_;
}
void MyQFrame::paintEvent(QPaintEvent *)
>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301:Observer/myqframe.cpp
{
    RepaintLines();
}
void MyQFrame::RepaintLines()
{
<<<<<<< HEAD:Observer/myframe.cpp
    painter_.begin(this);
    painter_.setPen(Qt::blue);
    painter_.setBrush(Qt::Dense7Pattern);
=======
    QPen pen(Qt::DashLine);
    pen.setColor(Qt::blue);
    painter_.begin(this);
    painter_.setPen(pen);
>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301:Observer/myqframe.cpp
    if(!points_.isEmpty()) {
         painter_.drawLine(points_[0],points_[1]);
         painter_.drawLine(points_[1],points_[2]);
         painter_.drawLine(points_[2],points_[3]);
         painter_.drawLine(points_[3],points_[0]);
    }
    painter_.end();
    update();
}
