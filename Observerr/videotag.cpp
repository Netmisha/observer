#include "videotag.h"
#include "ui_videotag.h"
#include "opencv2/opencv.hpp"
#include <thread>
#include <QRubberBand>
#include <QMouseEvent>
#include <QToolTip>
#include <QString>
#include <QDebug>
#include <math.h>
using namespace cv;
VideoTag::VideoTag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoTag)
{
       ui->setupUi(this);
}

VideoTag::~VideoTag()
{
    delete ui;
}

void VideoTag::on_Start_clicked()
{
    if(VideoTag::start==true){
        return;
    }
    VideoTag::start = true;
    stream=true;
    std::thread thr(&VideoTag::ThreadStream, this);
    thr.detach();
}
void VideoTag::on_AddTag_clicked()
{
    std::thread thr (&VideoTag::TagStreamThread, this);
    thr.detach();
}
void VideoTag::TagStreamThread(){
    int RectW = abs(abs(A.x()) - abs(B.x()));
    int RectH = abs(abs(C.y()) - abs(A.y()));
    qDebug()<<"RectW"<<RectW;
    qDebug()<<"RectH"<<RectH;
    VideoCapture cp(0);
 while(1){
     Mat f;
    cp>>f;
    Mat crop = f(Rect(A.x()-10,A.y()-30,RectW,RectH));
    ui->TagStream->showImage(crop);
 }

}
void VideoTag::ThreadStream(){ // Stream to MainStreamWindow
    Mat frame;
    VideoCapture cap(0);
    while(stream)
    {
        cap >> frame;

        ui->MainV->showImage(frame);
    }
}

void VideoTag::mousePressEvent(QMouseEvent *event){
    qDebug()<<ui->TagStream->width();
     qDebug()<<ui->TagStream->height();
     qDebug()<<ui->TagStream->x();
     qDebug()<<ui->TagStream->y();
    A  = event->pos();
    if(lock_rect == true){
        rubber->close();
    }
    if (event->pos().x() < 10 || event->pos().y() < 30 || (event->pos().x() > 10 && event->pos().y() > 170) ||
             (event->pos().x() > 280 && event->pos().y() < 170)){ // Make sure rectangle is in MainVideoWindow
        in_bound = false;
        return;
    }
    in_bound =true;
    rubber_offset = event->pos();
   rubber = new QRubberBand(QRubberBand::Rectangle, this);
   QToolTip::showText(event->pos(),QString("%1,%2").arg(rubber->size().width()).arg(rubber->size().height()),this);
}
void VideoTag::mouseMoveEvent(QMouseEvent *event){
   D = event->pos();
   B.setX(D.x());
   B.setY(A.y());
   C.setX(A.x());
   C.setY(D.y());
   if((B.x() > 260 && B.y() > 30) || C.y() > 220 || D.y() < 30 || B.x()<11){ // Check if the RECT is not crossing the bounds
       qDebug()<<"Out";
       rubber->close();
       return;

   }
    if (in_bound == false){
        return;

    }
    rubber->setGeometry(QRect(rubber_offset,event->pos()).normalized());
    rubber->show();
}

void VideoTag::mouseReleaseEvent(QMouseEvent *event){
   qDebug()<<"A"<<A;
   qDebug()<<"B"<<B;
   qDebug()<<"C"<<C;
   qDebug()<<"D"<<D;
    if(in_bound == false){
        return;

    }
    move_rubber = false;
    lock_rect = true;
}
void VideoTag::on_Stop_clicked()
{



}

void VideoTag::on_Pause_clicked()
{
    start = false;
    stream = false;
}



void VideoTag::on_DeleteTag_clicked()
{

}

void VideoTag::on_RenameTag_clicked()
{

}
