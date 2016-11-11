#include "movableframe.h"

<<<<<<< HEAD
MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent)
{

=======
MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent) {}

bool MovableFrame::CheckLimits(const QPoint &pos)
{
    if(pos.x()>0 && pos.x()+this->width()<this->parent_->width()) {
        if(pos.y()>0 && pos.y()+this->height()<parent_->height()) {
            return true;
        }
    }
    return false;
>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
}

void MovableFrame::mousePressEvent(QMouseEvent *event)
{
    start_pos_=event->pos();
}

void MovableFrame::mouseMoveEvent(QMouseEvent *event)
{
    QPoint new_pos=event->pos()-start_pos_+this->pos();
<<<<<<< HEAD
    if(( new_pos.x() > 0 && new_pos.x()<parent_->width()-this->width())&& ( new_pos.y() > 0 && new_pos.y()<parent_->height()-this->height())) {
=======
    if(CheckLimits(event->pos()-start_pos_+this->pos())) {
>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
        this->setGeometry(QRect(new_pos, this->size()));
    }
    emit FrameMoving();
}
