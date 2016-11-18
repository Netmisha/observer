#ifndef MYQFRAME_H
#define MYQFRAME_H
#include <QFrame>
#include <QPainter>
#include <QVector>
class MyQFrame : public QFrame
{
    Q_OBJECT
public:
    MyQFrame(QWidget *);
    QVector<QPoint> &getPoints();
private slots:
    void setLinePos(QVector<QPoint> &);
    void paintEvent(QPaintEvent *);
private:
    void RepaintLines();
    QVector<QPoint> points_;
    QPainter painter_;

};
#endif // MYQFRAME_H
