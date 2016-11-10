#include "selectcamera.h"
#include "ui_selectcamera.h"
#include <thread>


SelectCamera::SelectCamera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCamera)
{
    ui->setupUi(this);
    ui->remote_settingBox->setVisible(false);
<<<<<<< HEAD
=======
    connect(this, SIGNAL(RepaintLines(QVector<QPoint>&)), ui->select_area, SLOT(setLinePos(QVector<QPoint>&)));
    connect(ui->frame_point_1,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    connect(ui->frame_point_2,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    connect(ui->frame_point_3,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    connect(ui->frame_point_4,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    img_pos=QPoint(0,0);
    img_size=QSize(0,0);
    ShowDeviceList();
    InitializationFrame();
>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301
}

SelectCamera::~SelectCamera()
{
    run=false;
    delete ui;
}
<<<<<<< HEAD

=======
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
>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301
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
<<<<<<< HEAD
        Mat frame;
        cap >> frame;
        ui->opencv_view->showImage(frame);
    }

}
void SelectCamera::on_previewButton_clicked()
=======
        cap_ >> img_scr_;
        if(cuted_){
            img_scr_=ProcessingImage(img_scr_);
            addImage(img_scr_);
        }
        else {
            addImage(img_scr_);
        }
    }
    cap_.release();
}
void SelectCamera::addImage( Mat img_scr_)
{
    if(mtx_.try_lock()) {
        cvtColor(img_scr_,img_scr_,COLOR_BGR2RGB);
        image = QImage((const unsigned char*)(img_scr_.data),
                              img_scr_.cols, img_scr_.rows,
                              img_scr_.step, QImage::Format_RGB888);
        ResizeImage();
        ui->image_scene->setPixmap(QPixmap::fromImage(image));
        mtx_.unlock();
    }
}
void SelectCamera::ResizeImage()
{
    int width=ui->widget->width();
    int height=ui->widget->height();
    float kof=(float)image.width()/(float)width;
    if(kof==0) {
        return;
    }
    if(kof>(float)image.height()/(float)height) {
        kof=(float)image.height()/(float)height;
    }
    if(kof!=1 && kof!=0) {
        image=image.scaled(QSize(width, height),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
    img_size=image.size();
    img_pos.setX(floor((width - image.width()) / 2));
    img_pos.setY(-floor((height - image.height()) / 2));
}
void SelectCamera::paintEvent(QPaintEvent *) {
    FrameMoving();
}
void SelectCamera::resizeEvent(QResizeEvent *)
{
    if(img_size.width()==0) {
        ui->image_scene->setGeometry(QRect(QPoint(0,0), ui->widget->size()));
    }else {
        ui->image_scene->setGeometry(QRect(img_pos, img_size));
    }
    ResizeImage();
    ui->select_area->setGeometry(QRect(ui->image_scene->pos(), ui->image_scene->size()));
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
>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301
{
    run=true;
    std::thread thr(&SelectCamera::ShowImg, this);
    thr.detach();
}
<<<<<<< HEAD

void SelectCamera::on_nextButton_clicked()
{
    run=false;
=======
void SelectCamera::CalculateHomography()
{
    std::vector<Point2f> pts_src;
    std:: vector<Point2f> pts_dst;
    Point2f cent, cross;
    auto points=ui->select_area->getPoints();
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
    int left=0;
    int top=0;
    double kof_x=(double)(img_scr_.cols)/ui->select_area->width();
    double kof_y=(double)(img_scr_.rows)/ui->select_area->height();
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
    mtx_.lock();
    int w=ui->frame_point_1->size().width();
    int h=ui->frame_point_1->size().height();
    QVector<QPoint> points;
    points.push_back(QPoint(ui->frame_point_1->pos().x(),ui->frame_point_1->pos().y()));
    points.push_back(QPoint(ui->frame_point_2->pos().x()+w,ui->frame_point_2->pos().y()));
    points.push_back(QPoint(ui->frame_point_3->pos().x()+w,ui->frame_point_3->pos().y()+h));
    points.push_back(QPoint(ui->frame_point_4->pos().x(),ui->frame_point_4->pos().y()+h));
    emit RepaintLines(points);
    mtx_.unlock();
}
void SelectCamera::InitializationFrame()
{
    int w=ui->frame_point_1->size().width();
    int h=ui->frame_point_1->size().height();
    ui->frame_point_1->setGeometry(1,1,w,h);
    ui->frame_point_2->setGeometry(ui->select_area->width()-w-1,1,w,h);
    ui->frame_point_3->setGeometry(ui->select_area->width()-w-1,ui->select_area->height()-h-1,w,h);
    ui->frame_point_4->setGeometry(1,ui->select_area->height()-h-1,w,h);
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
>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301
}
