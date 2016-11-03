#include "videotag.h"
#include "ui_videotag.h"
#include "opencv2/opencv.hpp"
#include <thread>
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

void VideoTag::on_Stop_clicked()
{



}

void VideoTag::on_Pause_clicked()
{
    start = false;
    stream = false;
}
