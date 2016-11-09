#include "movableframe.h"
#include "cqtopencvviewergl.h"

MovableFrame::MovableFrame(QWidget *parent) : QFrame(parent), parent_(parent)
{

}

bool MovableFrame::CheckLimits(const QPoint &pos)
{
    CQtOpenCVViewerGl * opencv_view=(CQtOpenCVViewerGl *)this->parent()->parent();
    if(pos.x()>opencv_view->getRenderPos().x() && pos.x()<opencv_view->getRenderPos().x()+opencv_view->getRenderSize().width()) {
        if(pos.y()>opencv_view->getRenderPos().y() && pos.y()<opencv_view->getRenderPos().y()+opencv_view->getRenderSize().height()) {
            return true;
        }
    }
    return false;
}

void MovableFrame::mousePressEvent(QMouseEvent *event)
{
    start_pos_=event->pos();
}

void MovableFrame::mouseMoveEvent(QMouseEvent *event)
{
    QPoint new_pos=event->pos()-start_pos_+this->pos();
    if(CheckLimits(event->pos()-start_pos_+this->pos())) {
        this->setGeometry(QRect(new_pos, this->size()));
    }
    emit FrameMoving();
}
