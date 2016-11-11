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
#include <QListView>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QCursor>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QGraphicsPathItem>
#include <QGridLayout>
#include <QMutex>
#include <QDebug>
#include <thread>
#include <QPainter>
#include <QBrush>
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
    void showContextMenu(const QPoint&);
private:
   Ui::VideoTag *ui;
   QRubberBand *rubber;
   QImage shot_;
   QImage TagImg;
   QRect CropArea;
   QMutex mutex;
   QString temp;
   QPoint origin;
   volatile bool start=false;
   volatile bool lock_rect = false;
   volatile bool stream = false;
   VideoCapture cap;
   Mat frame;
   void ThreadStream();
   void TagStreamThread();
   void OnDataRename(QWidget* EditLine);
   void tag_delete(const QPoint& pos);
   void mouseHandler(int event, int x, int y, int flags, void* param);
   void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);
   void paintEvent(QPaintEvent *event);
};

#endif // VIDEOTAG_H
