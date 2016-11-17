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
    bool CheckLimits(const QPoint &);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint start_pos_;
    QWidget *parent_;
};
#endif // MOVABLEFRAME_H
