#include "movableframe.h"
MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent) {}
bool MovableFrame::CheckLimits(const QPoint &pos) {
    if(pos.x()>0 && pos.x()+this->width()<this->parent_->width()) {
        if(pos.y()>0 && pos.y()+this->height()<parent_->height()) {
            return true;
        }
    }
    return false;
}
void MovableFrame::mousePressEvent(QMouseEvent *event) {
    start_pos_=event->pos();
}
void MovableFrame::mouseMoveEvent(QMouseEvent *event) {
    QPoint new_pos=event->pos()-start_pos_+this->pos();
    if(CheckLimits(event->pos()-start_pos_+this->pos())) {
        this->setGeometry(QRect(new_pos, this->size()));
    }
    emit FrameMoving();
}
