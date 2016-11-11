#ifndef MOVABLEFRAME_H
#define MOVABLEFRAME_H

#include <QWidget>
#include <QFrame>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>
#include <QPainter>

class MovableFrame : public QFrame
{
   Q_OBJECT
public:
    MovableFrame(QWidget *parent = 0);
signals:
    void FrameMoving();
private:
<<<<<<< HEAD
=======
    bool CheckLimits(const QPoint &);
>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint start_pos_;
    QWidget *parent_;
};

#endif // MOVABLEFRAME_H
