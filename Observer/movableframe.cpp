#include "movableframe.h"

MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent) {}

<<<<<<< HEAD
=======
bool MovableFrame::CheckLimits(const QPoint &pos)
{
    if(pos.x()>0 && pos.x()+this->width()<this->parent_->width()) {
        if(pos.y()>0 && pos.y()+this->height()<parent_->height()) {
            return true;
        }
    }
    return false;
}

>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301
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
