#include "movableframe.h"

MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent)
{

}

void MovableFrame::mousePressEvent(QMouseEvent *event)
{
    start_pos_=event->pos();
}

void MovableFrame::mouseMoveEvent(QMouseEvent *event)
{
    QPoint new_pos=event->pos()-start_pos_+this->pos();
    if(( new_pos.x() > 0 && new_pos.x()<parent_->width()-this->width())&& ( new_pos.y() > 0 && new_pos.y()<parent_->height()-this->height())) {
        this->setGeometry(QRect(new_pos, this->size()));
    }
    emit FrameMoving();
}
