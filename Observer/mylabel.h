#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QRubberBand>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent=0);
    ~MyLabel(){delete rubber_;}
    QRect getSelectedRect(QSize);
    QRect getSelectedArea();
    void Clear_Rubber();
    void PaintRubber(QRect,QSize);
private slots:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);
private:
    bool pressed_=false;
    QRubberBand *rubber_;
    void ResizeRubber();
    QPoint start_;
    QRect rect_;
    QSize win_size;
    double kof_x;
    double kof_y;
};

#endif // MYLABEL_H
