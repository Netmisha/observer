#ifndef MYQFRAME_H
#define MYQFRAME_H

#include <QFrame>
#include <QPainter>
#include <QVector>

class MyQFrame : public QFrame
{
    Q_OBJECT
public:
<<<<<<< HEAD:Observer/myframe.h
    myFrame(QWidget * );
    ~myFrame();
=======
    MyQFrame(QWidget *);
    QVector<QPoint> &getPoints();
>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301:Observer/myqframe.h
private slots:
    void setLinePos(QVector<QPoint> &);
    void paintEvent(QPaintEvent *);
private:
    void RepaintLines();
    QVector<QPoint> points_;
    QPainter painter_;

};

#endif // MYQFRAME_H
