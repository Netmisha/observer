#ifndef MYFRAME_H
#define MYFRAME_H

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <QVector>
#include <QMouseEvent>
#include <QLabel>

class myFrame : public QFrame
{
    Q_OBJECT
public:
    myFrame(QWidget * );
    ~myFrame();
private slots:
    void setLinePos(QVector<QPoint> &);
protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event) {
    }
private:
    void RepaintLines();
    QVector<QPoint> points_;
    QPainter painter_;
    QLabel l;
};

#endif // MYFRAME_H
