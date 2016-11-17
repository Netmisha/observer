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
#include <QThread>
#include <QPainter>
#include <QBrush>
#include <tagclass.h>
#include <QVector>
#include <QMessageBox>
#include <QInputDialog>
#include <QFont>
#include <selectcamera.h>
#include <QTime>
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
    void on_AddTag_clicked();
    void on_dbl_clicked(QListWidgetItem *item);
    void showContextMenu(const QPoint&);
    void itemClicked();
    void on_Back_clicked();
    void on_Next_clicked();
    void ReceiveImage(Mat imgsrc);
<<<<<<< HEAD
=======

>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
signals:
    void SendID(int id);
    void OpenSettings();
    void OpenSelectCamera();
private:
   Ui::VideoTag *ui;
   QFont setF;
<<<<<<< HEAD
   Mat *TM;
=======
   Mat TM;
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
   TagClass *NewTag;
   QVector <TagClass*> TagContainer;
   QThread MainV,ChildV;
   QRubberBand *rubber;
   QImage shot_; QImage EmptyList;
   QImage TagImg;
   QRect CropArea;
   QMutex mutex;
   QString temp;
   QPoint origin;
   QString TagName;
   QPoint TagListItem;
   QMessageBox Messa;
   QInputDialog *GetTagName; bool ok;
   bool StartThread = false;
   volatile int VPos=-1;
   bool firstTag = true;
   volatile bool start=false;
   volatile bool lock_rect = false;
   volatile bool stream = true;
   bool LabelEmpty = true;
   VideoCapture cap;
   Mat frame;
   void ThreadStream();
   void TagStreamThread();
   void OnDataRename(QWidget* EditLine);
   void tag_delete(const QPoint& pos);
   void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);
   void paintEvent(QPaintEvent *event);
};

#endif // VIDEOTAG_H
