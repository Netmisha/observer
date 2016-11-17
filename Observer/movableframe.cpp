#include "movableframe.h"
<<<<<<< HEAD
MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent) {}
bool MovableFrame::CheckLimits(const QPoint &pos) {
    if(pos.x()>0 && pos.x()+this->width()<this->parent_->width()) {
        if(pos.y()>0 && pos.y()+this->height()<parent_->height()) {
            return true;
        }
    }
    return false;
=======
#include <QVector>
MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent) {}
bool MovableFrame::CheckLimits(const QPoint &pos) {
    QVector<QObject *>children= parent_->children().toVector();
    if(pos.x()<0 && pos.x()+this->width()>this->parent_->width()) {
        if(pos.y()<0 && pos.y()+this->height()>parent_->height()) {
            return false;
        }
    }
    return true;
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
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
