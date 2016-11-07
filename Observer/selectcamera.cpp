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
    connect(ui->frame_point_1,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
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
        cap.open(device_count); // open the default camer
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
        cap.release();
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
    cap.open(ui->list_of_cameras_comboBox->currentIndex()); // open the default camera
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
    QVector<QPoint> points;
    points.push_back(QPoint(ui->frame_point_1->pos().x()+5,ui->frame_point_1->pos().y()+5));
    points.push_back(QPoint(ui->frame_point_2->pos().x()+5,ui->frame_point_2->pos().y()+5));
    points.push_back(QPoint(ui->frame_point_3->pos().x()+5,ui->frame_point_3->pos().y()+5));
    points.push_back(QPoint(ui->frame_point_4->pos().x()+5,ui->frame_point_4->pos().y()+5));
    emit RepaintLines(points);
}
void SelectCamera::on_previewButton_clicked()
{
    Mat img=imread("1.jpg");
    ui->opencv_view->showImage(img);

}
void SelectCamera::on_nextButton_clicked()
{
    Mat im_src=imread("1.jpg");
    std::vector<Point2f> pts_src;
    pts_src.push_back(Point2f(ui->frame_point_1->pos().x(), ui->frame_point_1->pos().y()));
    pts_src.push_back(Point2f(ui->frame_point_2->pos().x(), ui->frame_point_2->pos().y()));
    pts_src.push_back(Point2f(ui->frame_point_3->pos().x(), ui->frame_point_3->pos().y()));
    pts_src.push_back(Point2f(ui->frame_point_4->pos().x(), ui->frame_point_4->pos().y()));
    int mi=-1;
    int mj=-1;
    double mlen=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(i==j) {
                continue;
            }
            double len=sqrt(pow(pts_src[i].x-pts_src[j].x,2)+pow(pts_src[i].y-pts_src[j].y,2));
            if(len>mlen) {
                mlen=len;
                mi=i;
                mj=j;
            }
        }
    }
    Point2f cent;
    cent.x=(pts_src[mi].x+pts_src[mj].x)/2;
    cent.y=(pts_src[mi].y+pts_src[mj].y)/2;
    std:: vector<Point2f> pts_dst;
    Point2f p1,p2,p3;
    pts_dst.resize(4);
    if(sqrt(pow(pts_src[mi].x-cent.x,2)+pow(pts_src[mi].y-cent.y,2))>sqrt(pow(cent.x-pts_src[mj].x,2)+pow(cent.y-pts_src[mj].y,2))) {
        pts_dst[mi]=pts_src[mi];
        p1.x=2*cent.x-pts_src[mi].x;
        p1.y=2*cent.y-pts_src[mi].y;
        pts_dst[mj]=p1;
        p2.x=pts_src[mj].x;
        p2.y=pts_src[mi].y;
        p3.x=pts_src[mi].x;
        p3.y=pts_src[mj].y;
    }
    else
    {
        pts_dst[mj]=pts_src[mj];
        p1.x=2*cent.x-pts_src[mj].x;
        p1.y=2*cent.y-pts_src[mj].y;
        pts_dst[mi]=p1;
        p2.x=pts_src[mj].x;
        p2.y=pts_src[mi].y;
        p3.x=pts_src[mi].x;
        p3.y=pts_src[mj].y;
    }
    for(int i=0;i<4;i++) {
        if(i==mi || i==mj) {
            continue;
        }
        if(sqrt(pow(pts_src[i].x-p2.x,2)+pow(pts_src[i].y-p2.y,2))<sqrt(pow(p3.x-pts_src[i].x,2)+pow(p3.y-pts_src[i].y,2)))  {
            pts_dst[i]=p2;
            pts_dst[6-i-mi-mj]=p3;
        }
        else {
            pts_dst[i]=p3;
            pts_dst[6-i-mi-mj]=p2;
        }
    }
    Mat h = findHomography(pts_src, pts_dst);
    Mat im_out;
    warpPerspective(im_src, im_out, h, im_src.size());
    ui->opencv_view->showImage(im_out);
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
}

void SelectCamera::FrameMoving()
{
    QVector<QPoint> points;
    points.push_back(QPoint(ui->frame_point_1->pos().x()+5,ui->frame_point_1->pos().y()+5));
    points.push_back(QPoint(ui->frame_point_2->pos().x()+5,ui->frame_point_2->pos().y()+5));
    points.push_back(QPoint(ui->frame_point_3->pos().x()+5,ui->frame_point_3->pos().y()+5));
    points.push_back(QPoint(ui->frame_point_4->pos().x()+5,ui->frame_point_4->pos().y()+5));
    emit RepaintLines(points);
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



































