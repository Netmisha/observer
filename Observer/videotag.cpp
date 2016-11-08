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
#include <tagclass.h>
#include <QMenu>
#include <QListView>
using namespace cv;
VideoTag::VideoTag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoTag)
{
       ui->setupUi(this);
       A = ui->MainV->pos();
       MainVH = ui->MainV->height();
       MainVW = ui->MainV->width();
       B = ui->MainV->geometry().topRight();
       C =ui->MainV->geometry().bottomLeft();
       D = ui->MainV->geometry().bottomRight();
       WCalibre = (MainVW / ui->TagStream->geometry().width())+0.5;
       HCalibre = (MainVH / ui->TagStream->geometry().height())+0.5;
       qDebug()<<WCalibre;
       ui->TagList->addItem("Test1");
       ui->TagList->addItem("Test2");
        connect(ui->TagList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_dbl_clicked(QListWidgetItem*)));
        connect(ui->TagList, SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(tag_rename(QListWidgetItem*)));
         layout = new QGridLayout(ui->TagList);
        ui->TagList->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(ui->TagList,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(showContextMenu(const QPoint&)));
}

VideoTag::~VideoTag()
{
    delete ui;
}
void VideoTag::showContextMenu(const QPoint &pos){
    QPoint item = ui->TagList->mapToGlobal(pos);
    QMenu submenu;
    submenu.addAction("Delete");
    QAction* rightclick = submenu.exec(item);
    if(rightclick && rightclick->text().contains("Delete")){
        tag_delete(pos);
    }

}
void VideoTag::tag_delete(const QPoint& pos){
 ui->TagList->takeItem(ui->TagList->indexAt(pos).row());

}
void VideoTag::tag_rename(QListWidgetItem *it){
    if(isEditable){
    QString text;
    text.append(it->text());
    qDebug()<<text;
    isEditable = false;
    }
}
void VideoTag::on_dbl_clicked(QListWidgetItem* it){
it->setFlags(it->flags() | Qt::ItemIsEditable);
ui->TagList->editItem(it);
isEditable = true;
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
   // VideoCapture cp(0);

 while(1){
     Mat f;
    cap>>f;
   //Mat crop = f(Rect(clickPosPres.x()-10,clickPosPres.y()-30,2.5*DrawRect.width(),2.5*DrawRect.height()));
    rectangle(f,Rect(clickPosPres.x()*1.3,clickPosPres.y()*1.5,WCalibre*DrawRect.width(),HCalibre*DrawRect.height()),CV_RGB(255,0,0),3,8,0);
    qDebug()<<clickPosPres;
    ui->TagStream->showImage(f);
 }

}
void VideoTag::ThreadStream(){ // Stream to MainStreamWindow
    cap = 0;
    while(stream)
    {
        cap >> frame;
        ui->MainV->showImage(frame);

    }
}

void VideoTag::mousePressEvent(QMouseEvent *event){
    clickPosPres = event->pos();
    qDebug()<<event->pos();
    if(lock_rect == true){
        rubber->close();
    }
    if (clickPosPres.x() < A.x() || clickPosPres.x() > B.x() || clickPosPres.x() > D.x() ||
            clickPosPres.y() < A.y() || clickPosPres.y() > C.y()){
        qDebug()<<"Cursor out of MainVideoStream Window bounds";
        in_bound = false;
        return;
    }
    in_bound =true;
    rubber_offset = clickPosPres;
   rubber = new QRubberBand(QRubberBand::Rectangle, this);
}
void VideoTag::mouseMoveEvent(QMouseEvent *event){
    QPoint clickPosMove = event->pos();
   if(clickPosMove.x() < A.x() || clickPosMove.x() > B.x() || clickPosMove.x() > D.x() ||
           clickPosMove.y() < A.y() || clickPosMove.y() > C.y()){ // Check if the RECT is not crossing the bounds
       qDebug()<<"Rectangle crossed the bounds";
       rubber->close();
       return;

   }
    if (in_bound == false){
        return;

    }
    rubber->setGeometry(QRect(rubber_offset,event->pos()));
    rubber->show();
    DrawRect = rubber->geometry();
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




