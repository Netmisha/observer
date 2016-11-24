#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    rubber_=new QRubberBand(QRubberBand::Rectangle,this);
}

QRect MyLabel::getSelectedRect(QSize img_size)
{
    double kof_x=(double)img_size.width()/width();
    double kof_y=(double)img_size.height()/height();
    QRect new_rect;
    new_rect.setX(rect_.x()*kof_x);
    new_rect.setY(rect_.y()*kof_y);
    new_rect.setWidth(rect_.width()*kof_x);
    new_rect.setHeight(rect_.height()*kof_y);
    return new_rect;
}

QRect MyLabel::getSelectedArea()
{
    return rubber_->geometry();
}

void MyLabel::Clear_Rubber()
{
    rubber_->setGeometry(0,0,0,0);
}

void MyLabel::PaintRubber(QRect rect, QSize img_size)
{
    double kof_x=(double)img_size.width()/width();
    double kof_y=(double)img_size.height()/height();
    QRect new_rect;
    new_rect.setX(rect.x()/kof_x);
    new_rect.setY(rect.y()/kof_y);
    new_rect.setWidth(rect.width()/kof_x);
    new_rect.setHeight(rect.height()/kof_y);
    rect_=new_rect;
    rubber_->setGeometry(new_rect);
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    pressed_=true;
    start_=event->pos();
    rubber_->setGeometry(0,0,0,0);
    rubber_->show();
}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    if(pressed_ && event->pos().x()<width() && event->pos().y()<height()) {
        QSize size;
        size.setWidth(abs(event->pos().x()-start_.x()));
        size.setHeight(abs(event->pos().y()-start_.y()));
        if(event->pos().x()>start_.x() && event->pos().y()>start_.y()) {
            rubber_->setGeometry(QRect(start_,size));
            return;
        }
        if(event->pos().x()>start_.x() && event->pos().y()<start_.y()) {
            rubber_->setGeometry(QRect(QPoint(start_.x(),event->pos().y()),size));
            return;
        }
        if(event->pos().x()<start_.x() && event->pos().y()>start_.y()) {
            rubber_->setGeometry(QRect(QPoint(event->pos().x(), start_.y()),size));
            return;
        }
        if(event->pos().x()<start_.x() && event->pos().y()<start_.y()) {
            rubber_->setGeometry(QRect(event->pos(),size));
            return;
        }
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *)
{
    pressed_=false;
    rect_=QRect(rubber_->pos(),rubber_->size());
    win_size=size();
}
void MyLabel::resizeEvent(QResizeEvent *event)
{
    if(rect_.width() && rect().height()) {
        kof_x=(double)(event->size().width())/win_size.width();
        kof_y=(double)(event->size().height())/win_size.height();
        ResizeRubber();
    }
}
void MyLabel::ResizeRubber()
{
    QRect new_rect;
    new_rect.setX(rect_.x()*kof_x);
    new_rect.setY(rect_.y()*kof_y);
    new_rect.setWidth(rect_.width()*kof_x);
    new_rect.setHeight(rect_.height()*kof_y);
    rubber_->setGeometry(new_rect);
}
