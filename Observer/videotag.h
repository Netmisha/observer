#ifndef VIDEOTAG_H
#define VIDEOTAG_H
#include <QLabel>
#include <QWidget>
#include <QRubberBand>
#include <QMouseEvent>
#include <QPoint>
#include "opencv2/opencv.hpp"
#include<opencv2/highgui/highgui.hpp>
#include <QRect>
#include <QMenu>
#include <tagclass.h>
#include <QListView>
#include <QListWidgetItem>
#include <QPushButton>
#include <QGridLayout>
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
    void on_dbl_clicked(QListWidgetItem *item);
    void tag_rename(QListWidgetItem *item);
    void showContextMenu(const QPoint&);
private:
    QPushButton *m_button;
    QGridLayout *layout;
    volatile bool isEditable =false;
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
     QPoint clickPosPres;
     VideoCapture cap;
    int MainVW, MainVH;
    QRect DrawRect;
     QPoint clickPosMove;
     Mat frame;
     Mat f;

     float WCalibre;
     float HCalibre;

     Point point1, point2;
     int drag = 0;
     cv::Rect rect;
     cv:: Mat img,roiImg;
     int select_flag = 0;
      void tag_delete(const QPoint& pos);
     void mouseHandler(int event, int x, int y, int flags, void* param);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // VIDEOTAG_H
