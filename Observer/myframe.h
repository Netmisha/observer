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
    QVector<QPoint> &getPoints();
private slots:
    void setLinePos(QVector<QPoint> &);
protected:
    void paintEvent(QPaintEvent *);
private:
    void RepaintLines();
    QVector<QPoint> points_;
    QPainter painter_;
};

#endif // MYFRAME_H
