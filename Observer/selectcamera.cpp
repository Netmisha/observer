#include "selectcamera.h"
#include "ui_selectcamera.h"
#include <QImage>
#include <QGraphicsPixmapItem>

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
    run_=false;
    Sleep(1000);
    delete ui;
}

Mat SelectCamera::ProcessingImage(Mat img_src)
{
    Mat img_out;
    warpPerspective(img_src, img_out, homography_, img_out_size_);
    return img_out;
}
void SelectCamera::ShowDeviceList() {
    int device_count=0;
    while (device_count<100) {
        cap_.open(device_count);
        if(!cap_.isOpened())
            break;
        cap_.release();
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
        cap_.release();
        run_=false;
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
        run_=false;
    }
}
void SelectCamera::ShowImg () {
    cap_.open(ui->list_of_cameras_comboBox->currentIndex());
    if(!cap_.isOpened())
        return;
    while(run_)
    {
        cap_ >> img_scr_;
        if(cuted_){
            ui->opencv_view->showImage(ProcessingImage(img_scr_));
        }
        ui->opencv_view->showImage(img_scr_);
    }
    cap_.release();
}
void SelectCamera::paintEvent(QPaintEvent *) {
    FrameMoving();
}

void SelectCamera::resizeEvent(QResizeEvent *)
{
    InitializationFrame();
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
}

Point2f SelectCamera::GravityCenter(std::vector<Point2f> &pts_src)
{
    std::vector<Point2f> centr(pts_src.size());
    Point2f cent;
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
    return cent;
}

void SelectCamera::CalculateHomography()
{
    std::vector<Point2f> pts_src;
    std:: vector<Point2f> pts_dst;
    Point2f cent, cross;
    auto points=ui->frame->getPoints();
    pts_src.push_back(Point2f(points[0].x(),points[0].y()));
    pts_src.push_back(Point2f(points[2].x(),points[2].y()));
    pts_src.push_back(Point2f(points[1].x(),points[1].y()));
    pts_src.push_back(Point2f(points[3].x(),points[3].y()));
    cross=CrossingLine(pts_src);
    auto dis=[](Point2f p1, Point2f p2){return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));};
    cent=GravityCenter(pts_src);
    pts_src.clear();
    pts_src.push_back(Point2f(points[0].x(),points[0].y()));
    pts_src.push_back(Point2f(points[1].x(),points[1].y()));
    pts_src.push_back(Point2f(points[2].x(),points[2].y()));
    pts_src.push_back(Point2f(points[3].x(),points[3].y()));
    double width=(dis(pts_src[0],pts_src[1])+dis(pts_src[2],pts_src[3]))/2+2*fabs(cross.x-cent.x);
    double height=(dis(pts_src[0],pts_src[3])+dis(pts_src[1],pts_src[2]))/2+2*fabs(cross.y-cent.y);
    int left=ui->opencv_view->getRenderPos().x();
    int top=ui->opencv_view->getRenderPos().y();
    double kof_x=(double)(img_scr_.cols)/ui->opencv_view->getRenderSize().width();
    double kof_y=(double)(img_scr_.rows)/ui->opencv_view->getRenderSize().height();
    pts_src.clear();
    pts_src.push_back(Point2f((points[0].x()-left)*kof_x,(points[0].y()-top)*kof_y));
    pts_src.push_back(Point2f((points[1].x()-left)*kof_x,(points[1].y()-top)*kof_y));
    pts_src.push_back(Point2f((points[2].x()-left)*kof_x,(points[2].y()-top)*kof_y));
    pts_src.push_back(Point2f((points[3].x()-left)*kof_x,(points[3].y()-top)*kof_y));
    pts_dst.push_back(Point2f(0,0));
    pts_dst.push_back(Point2f(width - 1, 0));
    pts_dst.push_back(Point2f(width - 1, height -1));
    pts_dst.push_back(Point2f(0, height - 1 ));
    homography_ = findHomography(pts_src, pts_dst);
    img_out_size_=Size(width, height);
}
void SelectCamera::on_nextButton_clicked()
{
    run_=false;
    this->close();
}
void SelectCamera::on_list_of_cameras_comboBox_currentIndexChanged(int index)
{
    run_=false;
    Sleep(500);
    if(index!=-1) {
        run_=true;
        std::thread thr(&SelectCamera::ShowImg, this);
        thr.detach();
    }
}
void SelectCamera::FrameMoving()
{
    int w=ui->frame_point_1->size().width();
    int h=ui->frame_point_1->size().height();
    QVector<QPoint> points;
    points.push_back(QPoint(ui->frame_point_1->pos().x(),ui->frame_point_1->pos().y()));
    points.push_back(QPoint(ui->frame_point_2->pos().x()+w,ui->frame_point_2->pos().y()));
    points.push_back(QPoint(ui->frame_point_3->pos().x()+w,ui->frame_point_3->pos().y()+h));
    points.push_back(QPoint(ui->frame_point_4->pos().x(),ui->frame_point_4->pos().y()+h));
    emit RepaintLines(points);
}

void SelectCamera::InitializationFrame()
{
    int w=ui->frame_point_1->size().width();
    int h=ui->frame_point_1->size().height();
    ui->frame_point_1->setGeometry(ui->opencv_view->getRenderPos().x(),ui->opencv_view->getRenderPos().y(),w,h);
    ui->frame_point_2->setGeometry(ui->opencv_view->getRenderPos().x()+ui->opencv_view->getRenderSize().width()-w,ui->opencv_view->getRenderPos().y(),w,h);
    ui->frame_point_3->setGeometry(ui->opencv_view->getRenderPos().x()+ui->opencv_view->getRenderSize().width()-w,ui->opencv_view->getRenderPos().y()+ui->opencv_view->getRenderSize().height()-h,w,h);
    ui->frame_point_4->setGeometry(ui->opencv_view->getRenderPos().x(),ui->opencv_view->getRenderPos().y()+ui->opencv_view->getRenderSize().height()-h,w,h);
}

void SelectCamera::on_cutButton_clicked()
{
    if(img_scr_.empty()) {
        return;
    }
    CalculateHomography();
    InitializationFrame();
    cuted_=true;
}

void SelectCamera::on_originalButton_clicked()
{
    InitializationFrame();
    cuted_=false;
}

void SelectCamera::on_camera_connectButton_clicked()
{
    InitializationFrame();
}
