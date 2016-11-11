#include "movableframe.h"

<<<<<<< HEAD
MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent) {}

bool MovableFrame::CheckLimits(const QPoint &pos)
{
    if(pos.x()>0 && pos.x()+this->width()<this->parent_->width()) {
        if(pos.y()>0 && pos.y()+this->height()<parent_->height()) {
            return true;
        }
    }
    return false;
=======
MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent)
{

>>>>>>> 308241a7847dfd01a02293d314c8ac01f84adcd7
}

void MovableFrame::mousePressEvent(QMouseEvent *event)
{
    start_pos_=event->pos();
}

void MovableFrame::mouseMoveEvent(QMouseEvent *event)
{
    QPoint new_pos=event->pos()-start_pos_+this->pos();
<<<<<<< HEAD
    if(CheckLimits(event->pos()-start_pos_+this->pos())) {
=======
    if(( new_pos.x() > 0 && new_pos.x()<parent_->width()-this->width())&& ( new_pos.y() > 0 && new_pos.y()<parent_->height()-this->height())) {
>>>>>>> 308241a7847dfd01a02293d314c8ac01f84adcd7
        this->setGeometry(QRect(new_pos, this->size()));
    }
    emit FrameMoving();
}
