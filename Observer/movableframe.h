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
    bool CheckLimits(const QPoint &);
=======
>>>>>>> 308241a7847dfd01a02293d314c8ac01f84adcd7
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint start_pos_;
    QWidget *parent_;
};

#endif // MOVABLEFRAME_H
