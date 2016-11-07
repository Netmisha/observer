#ifndef VIDEOTAG_H
#define VIDEOTAG_H
#include <QLabel>
#include <QWidget>
#include <QRubberBand>
#include <QMouseEvent>
#include <QPoint>
#include "opencv2/opencv.hpp"
using namespace cv;
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

    void on_AddTag_clicked();

    void on_DeleteTag_clicked();

    void on_RenameTag_clicked();

private:
    volatile bool start=false;
    void ThreadStream();
    void TagStreamThread();
    Ui::VideoTag *ui;
    QRubberBand *rubber;
    bool move_rubber;
    QPoint rubber_offset;
    volatile bool stream = false;
    volatile bool in_bound = true;
    volatile bool lock_rect = false;
    QPoint A,B,C,D;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // VIDEOTAG_H
