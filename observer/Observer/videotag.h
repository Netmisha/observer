#ifndef VIDEOTAG_H
#define VIDEOTAG_H
#include "opencv2/opencv.hpp"
#include <QLabel>
#include <QWidget>
#include <QRubberBand>
namespace Ui {
class VideoTag;
}

class VideoTag : public QWidget
{
    Q_OBJECT

public:
    explicit VideoTag(QWidget *parent = 0);
    ~VideoTag();

private slots:
    void on_Start_clicked();

    void on_Stop_clicked();

    void on_Pause_clicked();

private:
    volatile bool start=false;
    void ThreadStream();
    Ui::VideoTag *ui;
    QRubberBand *rubber;
    bool move_rubber;
    QPoint rubber_offset;
    volatile bool stream = false;
    volatile bool in_bound = true;
    volatile bool lock_rect = false;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // VIDEOTAG_H
