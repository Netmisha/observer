#ifndef MYFRAME_H
#define MYFRAME_H

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <QVector>

class myFrame : public QFrame
{
    Q_OBJECT
public:
    myFrame(QWidget * );
private slots:
    void setLinePos(QVector<QPoint> &);
protected:
    void paintEvent(QPaintEvent *);
private:
    QVector<QPoint> points_;
};

#endif // MYFRAME_H
