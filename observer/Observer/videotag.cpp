#include "videotag.h"
#include "ui_videotag.h"
#include "opencv2/opencv.hpp"
#include <thread>
#include <QRubberBand>
#include <QMouseEvent>
#include <QToolTip>
#include <QString>
#include <QDebug>
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

void VideoTag::ThreadStream(){

    VideoCapture cap(0); // open the default camera
    while(stream)
    {
        Mat frame;
        cap >> frame;
        ui->MainV->showImage(frame);
    }
}

void VideoTag::mousePressEvent(QMouseEvent *event){
    if(lock_rect == true){
        rubber->close();
    }
    if (event->pos().x() < 10 || event->pos().y() < 30 || (event->pos().x() > 10 && event->pos().y() > 170) ||
             (event->pos().x() > 280 && event->pos().y() < 170)){
        qDebug()<<event->pos();
        in_bound = false;
        return;
    }
    in_bound =true;
    rubber_offset = event->pos();
    qDebug()<<rubber_offset;
   rubber = new QRubberBand(QRubberBand::Rectangle, this);
   QToolTip::showText(event->pos(),QString("%1,%2").arg(rubber->size().width()).arg(rubber->size().height()),this);
}
void VideoTag::mouseMoveEvent(QMouseEvent *event){
    if (in_bound == false){
        return;

    }
    rubber->setGeometry(QRect(rubber_offset,event->pos()).normalized());
   // QToolTip::showText(rubber_offset);
   // event->globalPos(),QString("%1,%2").arg(rubber->size().width()).arg(rubber->size().height()),this
    rubber->show();
}

void VideoTag::mouseReleaseEvent(QMouseEvent *event){
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
