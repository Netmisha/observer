#include "selectcamera.h"
#include "ui_selectcamera.h"
#include <thread>

SelectCamera::SelectCamera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCamera)
{
    ui->setupUi(this);
    ui->remote_settingBox->setVisible(false);
    connect(this,SIGNAL(RepaintLines(QVector<QPoint>&)), ui->frame, SLOT(setLinePos(QVector<QPoint>&)));
    ShowDeviceList();
    InitializationFrame();
}
SelectCamera::~SelectCamera()
{
    run=false;
    Sleep(1000);
    delete ui;
}

void SelectCamera::ShowDeviceList() {
    int device_count=0;
    while (true) {
        VideoCapture cap(device_count); // open the default camer
        if(!cap.isOpened())  // check if we succeeded
            break;
        cap.release();
        ui->list_of_cameras_comboBox->addItem(QString("Camera_%1").arg(++device_count));
        ui->list_of_cameras_comboBox->setCurrentIndex(-1);
    }
}
void SelectCamera::on_select_from_listButton_clicked()
{
    if(!ui->select_cameraBox->isVisible()) {
        ui->select_cameraBox->setVisible(!ui->select_cameraBox->isVisible());
        ui->remote_settingBox->setVisible(!ui->remote_settingBox->isVisible());
        ui->list_of_cameras_comboBox->setCurrentIndex(literals::kDefoultIndex);
        run=false;
    }
}

void SelectCamera::on_remote_cameraButton_clicked()
{
    if(!ui->remote_settingBox->isVisible()) {
        ui->select_cameraBox->setVisible(!ui->select_cameraBox->isVisible());
        ui->remote_settingBox->setVisible(!ui->remote_settingBox->isVisible());
        ui->camera_ipEdit->clear();
        ui->camera_portEdit->clear();
        ui->camera_passwordEdit->clear();
        run=false;
    }
}
void SelectCamera::ShowImg () {
    VideoCapture cap(ui->list_of_cameras_comboBox->currentIndex()); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return;
    while(run)
    {
        Mat frame;
        cap >> frame;
        ui->opencv_view->showImage(frame);
    }
    cap.release();
}
void SelectCamera::paintEvent(QPaintEvent *) {
    ui->frame->setGeometry(0,0,ui->opencv_view->width(),ui->opencv_view->height());
    QVector<QPoint> points;
    points.push_back(QPoint(ui->frame_point_1->pos().x()+5,ui->frame_point_1->pos().y()+5));
    points.push_back(QPoint(ui->frame_point_2->pos().x()+5,ui->frame_point_2->pos().y()+5));
    points.push_back(QPoint(ui->frame_point_3->pos().x()+5,ui->frame_point_3->pos().y()+5));
    points.push_back(QPoint(ui->frame_point_4->pos().x()+5,ui->frame_point_4->pos().y()+5));
    emit RepaintLines(points);
}
void SelectCamera::on_previewButton_clicked()
{

}
void SelectCamera::on_nextButton_clicked()
{
    run=false;
}
void SelectCamera::on_list_of_cameras_comboBox_currentIndexChanged(int index)
{
    run=false;
    Sleep(500);
    if(index!=-1) {
        run=true;
        std::thread thr(&SelectCamera::ShowImg, this);
        thr.detach();
    }
    InitializationFrame();
}
void SelectCamera::InitializationFrame()
{
    int x1=10;
    int x2=ui->opencv_view->width()-20;
    int y1=10;
    int y2=ui->opencv_view->height()-20;
    int w=10;
    int h=10;
    ui->frame_point_1->setGeometry(x1,y1,w,h);
    ui->frame_point_2->setGeometry(x2,y1,w,h);
    ui->frame_point_3->setGeometry(x2,y2,w,h);
    ui->frame_point_4->setGeometry(x1,y2,w,h);
}



































