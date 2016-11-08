#include "selectcamera.h"
#include "ui_selectcamera.h"
#include <thread>


SelectCamera::SelectCamera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCamera)
{
    ui->setupUi(this);
    ui->remote_settingBox->setVisible(false);
}

SelectCamera::~SelectCamera()
{
    run=false;
    delete ui;
}

void SelectCamera::on_select_from_listButton_clicked()
{
    ui->select_cameraBox->setVisible(!ui->select_cameraBox->isVisible());
    ui->remote_settingBox->setVisible(!ui->remote_settingBox->isVisible());
    ui->list_of_cameras_comboBox->setCurrentIndex(literals::kDefoultIndex);
}

void SelectCamera::on_remote_cameraButton_clicked()
{
    ui->select_cameraBox->setVisible(!ui->select_cameraBox->isVisible());
    ui->remote_settingBox->setVisible(!ui->remote_settingBox->isVisible());
    ui->camera_ipEdit->clear();
    ui->camera_portEdit->clear();
    ui->camera_passwordEdit->clear();
}
void SelectCamera::ShowImg () {
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return;
    while(run)
    {
        Mat frame;
        cap >> frame;
        if(cut_) {
            warpPerspective(frame, frame, h, frame.size());
        }
        ui->opencv_view->showImage(frame);
    }
<<<<<<< HEAD
    cap.release();
}
void SelectCamera::paintEvent(QPaintEvent *) {
    QVector<QPoint> points;
    points.push_back(QPoint(ui->frame_point_1->pos().x()+10,ui->frame_point_1->pos().y()+10));
    points.push_back(QPoint(ui->frame_point_2->pos().x(),ui->frame_point_2->pos().y()+10));
    points.push_back(QPoint(ui->frame_point_3->pos().x(),ui->frame_point_3->pos().y()));
    points.push_back(QPoint(ui->frame_point_4->pos().x()+10,ui->frame_point_4->pos().y()));
    emit RepaintLines(points);
}
Point2f SelectCamera::CrossingLine(std::vector<Point2f> &pts_src) {
    Point2f cross;
    if(pts_src[0].x>=pts_src[1].x) {
        cross=pts_src[0];
        pts_src[0]=pts_src[1];
        pts_src[1]=cross;
    }
    if(pts_src[2].x>=pts_src[3].x) {
        cross=pts_src[2];
        pts_src[2]=pts_src[3];
        pts_src[3]=cross;
    }
    double k1=(pts_src[1].y-pts_src[0].y)/(pts_src[1].x-pts_src[0].x);
    double k2=(pts_src[3].y-pts_src[2].y)/(pts_src[3].x-pts_src[2].x);
    double b1=pts_src[0].y-k1*pts_src[0].x;
    double b2=pts_src[2].y-k2*pts_src[2].x;
    cross.x=(b2-b1)/(k1-k2);
    cross.y=b1+k1*cross.x;
    return cross;
=======

}
void SelectCamera::on_previewButton_clicked()
{
    run=true;
    std::thread thr(&SelectCamera::ShowImg, this);
    thr.detach();
>>>>>>> 761f1f10c020c61af79c178058402399ee8e1e39
}

void SelectCamera::on_nextButton_clicked()
{
<<<<<<< HEAD
    Mat im_src=imread("1.jpg");
    std::vector<Point2f> pts_src;
    std::vector<Point2f> centr;
    std:: vector<Point2f> pts_dst;
    Point2f cent, cross;
    int index=-1;
    double max_dis=10000;
    pts_src.push_back(Point2f(ui->frame_point_1->pos().x()+ui->frame_point_4->size().width(), ui->frame_point_1->pos().y()+ui->frame_point_4->size().height()));
    pts_src.push_back(Point2f(ui->frame_point_3->pos().x(), ui->frame_point_3->pos().y()));
    pts_src.push_back(Point2f(ui->frame_point_2->pos().x(), ui->frame_point_2->pos().y()+ui->frame_point_4->size().height()));
    pts_src.push_back(Point2f(ui->frame_point_4->pos().x()+ui->frame_point_4->size().width(), ui->frame_point_4->pos().y()));
    pts_dst.resize(pts_src.size());
    centr.resize(4);
    cross=CrossingLine(pts_src);
    auto add_point=[](double x, double y){ Point2f res; res.x=x; res.y=y; return res;};
    auto dis=[](Point2f p1, Point2f p2){return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));};
    centr[2]=add_point((pts_src[0].x+pts_src[1].x)/2,(pts_src[0].y+pts_src[1].y)/2);
    centr[1]=add_point((pts_src[3].x+pts_src[1].x)/2,(pts_src[3].y+pts_src[1].y)/2);
    centr[0]=pts_src[0];
    centr[3]=pts_src[3];
    Point2f c1, c2;
    c1=CrossingLine(centr);
    centr[3]=add_point((pts_src[0].x+pts_src[1].x)/2,(pts_src[0].y+pts_src[1].y)/2);
    centr[1]=add_point((pts_src[2].x+pts_src[1].x)/2,(pts_src[2].y+pts_src[1].y)/2);
    centr[0]=pts_src[0];
    centr[2]=pts_src[2];
    c2=CrossingLine(centr);
    double p1=(dis(pts_src[0], pts_src[1])+dis(pts_src[3], pts_src[1])+dis(pts_src[0], pts_src[3]))/2;
    double s1=sqrt(p1*(p1-dis(pts_src[0], pts_src[1]))*(p1-dis(pts_src[3], pts_src[1]))*(p1-dis(pts_src[0], pts_src[3])));
    double p2=(dis(pts_src[0], pts_src[1])+dis(pts_src[2], pts_src[1])+dis(pts_src[0], pts_src[2]))/2;
    double s2=sqrt(p2*(p2-dis(pts_src[0], pts_src[1]))*(p2-dis(pts_src[3], pts_src[1]))*(p2-dis(pts_src[0], pts_src[3])));
    cent.x=(c1.x*s1+c2.x*s2)/(s1+s2);
    cent.y=(c1.y*s1+c2.y*s2)/(s1+s2);
    pts_src.clear();
    pts_src.push_back(Point2f(ui->frame_point_1->pos().x()+ui->frame_point_4->size().width(), ui->frame_point_1->pos().y()+ui->frame_point_4->size().height()));
    pts_src.push_back(Point2f(ui->frame_point_2->pos().x(), ui->frame_point_2->pos().y()+ui->frame_point_4->size().height()));
    pts_src.push_back(Point2f(ui->frame_point_3->pos().x(), ui->frame_point_3->pos().y()));
    pts_src.push_back(Point2f(ui->frame_point_4->pos().x()+ui->frame_point_4->size().width(), ui->frame_point_4->pos().y()));
    double width=(dis(pts_src[0],pts_src[1])+dis(pts_src[2],pts_src[3]))/2+2*fabs(cross.x-cent.x);
    double height=(dis(pts_src[0],pts_src[3])+dis(pts_src[1],pts_src[2]))/2+2*fabs(cross.y-cent.y);
    for(int i=0;i<4;i++) {
        if(max_dis>dis(pts_src[i],cross)) {
            max_dis=dis(pts_src[i],cross);
            index=i;
        }
    }
    switch (index) {
    case 0: {
        pts_dst[0]=pts_src[0];
        pts_dst[1]=add_point(pts_dst[0].x+width, pts_dst[0].y);
        pts_dst[2]=add_point(pts_dst[0].x+width, pts_dst[0].y+height);
        pts_dst[3]=add_point(pts_dst[0].x, pts_dst[0].y+height);
        break;
    }
    case 1: {
        pts_dst[1]=pts_src[1];
        pts_dst[0]=add_point(pts_dst[1].x-width, pts_dst[1].y);
        pts_dst[2]=add_point(pts_dst[1].x, pts_dst[1].y+height);
        pts_dst[3]=add_point(pts_dst[1].x-width, pts_dst[1].y+height);
        break;
    }
    case 2: {
        pts_dst[2]=pts_src[2];
        pts_dst[0]=add_point(pts_dst[2].x-width, pts_dst[2].y-height);
        pts_dst[1]=add_point(pts_dst[2].x, pts_dst[2].y-height);
        pts_dst[3]=add_point(pts_dst[2].x-width, pts_dst[2].y);
        break;
    }
    case 3: {
        pts_dst[3]=pts_src[3];
        pts_dst[0]=add_point(pts_dst[3].x, pts_dst[3].y-height);
        pts_dst[1]=add_point(pts_dst[3].x+width, pts_dst[3].y-height);
        pts_dst[2]=add_point(pts_dst[3].x-width, pts_dst[3].y);
        break;
    }
    default:
        break;
    }
    Mat h = findHomography(pts_src, pts_dst);
    Mat im_out;
    warpPerspective(im_src, im_out, h, im_src.size());
    ui->opencv_view->showImage(im_out);
    run=false;
}
void SelectCamera::on_list_of_cameras_comboBox_currentIndexChanged(int index)
{
=======
>>>>>>> 761f1f10c020c61af79c178058402399ee8e1e39
    run=false;
}
<<<<<<< HEAD

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

void SelectCamera::on_cutButton_clicked()
{
    Mat img=imread("1.jpg");
    ui->opencv_view->showImage(img);
}
=======
>>>>>>> 761f1f10c020c61af79c178058402399ee8e1e39
