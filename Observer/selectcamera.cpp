#include "selectcamera.h"
#include "ui_selectcamera.h"
#include <QMessageBox>
SelectCamera::SelectCamera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCamera) {
    ui->setupUi(this);
    ui->remote_settingBox->setVisible(false);
    timer_show_=new QTimer();
    timer_send_=new QTimer();
    connect(timer_show_, SIGNAL(timeout()), this, SLOT(on_timer_show()));
    connect(timer_send_, SIGNAL(timeout()), this, SLOT(on_timer_send()));
    connect(this, SIGNAL(RepaintLines(QVector<QPoint>&)), ui->select_area, SLOT(setLinePos(QVector<QPoint>&)));
    connect(this, SIGNAL(SizeChange(QResizeEvent*)), this, SLOT(resizeEvent(QResizeEvent*)));
    connect(ui->frame_point_1,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    connect(ui->frame_point_2,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    connect(ui->frame_point_3,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    connect(ui->frame_point_4,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    img_pos_=QPoint(0,0);
    img_size_=QSize(0,0);
    ShowDeviceList();
    InitializationFrame();
    ui->image_scene->setVisible(run_);
    ui->widget->resize(width()-2,height()-ui->verticalLayout_4->geometry().height()-ui->horizontalLayout->geometry().height()-ui->statusbar->height()-195);
}
SelectCamera::~SelectCamera() {
    run_=false;
    delete ui;
}
Mat SelectCamera::ProcessingImage(Mat img_src) {
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
void SelectCamera::on_select_from_listButton_clicked() {
    if(!ui->select_cameraBox->isVisible()) {
        ui->select_cameraBox->setVisible(!ui->select_cameraBox->isVisible());
        ui->remote_settingBox->setVisible(!ui->remote_settingBox->isVisible());
        ui->list_of_cameras_comboBox->setCurrentIndex(literals::kDefaultIndex);
        cap_.release();
        run_=false;
    }
}
void SelectCamera::on_remote_cameraButton_clicked() {
    if(!ui->remote_settingBox->isVisible()) {
        ui->list_of_cameras_comboBox->setCurrentIndex(literals::kDefaultIndex);
        ui->select_cameraBox->setVisible(!ui->select_cameraBox->isVisible());
        ui->remote_settingBox->setVisible(!ui->remote_settingBox->isVisible());
        ui->camera_ipEdit->clear();
        ui->camera_portEdit->clear();
        ui->camera_passwordEdit->clear();
        run_=false;
    }
}
void SelectCamera::ShowImg () {

    cap_ >> img_scr_;
    if(cuted_){
        img_scr_=ProcessingImage(img_scr_);
        addImage(img_scr_);
        if(!resized_ || img_size_!=ui->image_scene->size()) {
            emit SizeChange(nullptr);
            resized_=!resized_;
        }
    }
    else {
        addImage(img_scr_);
        if(!resized_ || img_size_!=ui->image_scene->size()) {
            emit SizeChange(nullptr);
            resized_=!resized_;
        }
    }
}
void SelectCamera::addImage( Mat img_scr_) {
    if(mtx_.try_lock()) {
        cvtColor(img_scr_,img_scr_,COLOR_BGR2RGB);
        image_ = QImage((const unsigned char*)(img_scr_.data),
                              img_scr_.cols, img_scr_.rows,
                              img_scr_.step, QImage::Format_RGB888);
        ResizeImage();
        ui->image_scene->setPixmap(QPixmap::fromImage(image_));
        mtx_.unlock();
    }
}

void SelectCamera::on_timer_send() {
    cap_ >> img_scr_;
    if(cuted_){
        emit SendImage(ProcessingImage(img_scr_));
    }
    else {
        emit SendImage(img_scr_);
    }
}

void SelectCamera::send_stop() {
    timer_send_->stop();
    cap_.release();
}
void SelectCamera::on_timer_show() {
    ShowImg();
}
void SelectCamera::ResizeImage() {
    int width=ui->widget->width();
    int height=ui->widget->height();
    float kof=(float)image_.width()/(float)width;
    if(kof==0) {
        return;
    }
    if(kof>(float)image_.height()/(float)height) {
        kof=(float)image_.height()/(float)height;
    }
    if(kof!=1 && kof!=0) {
        image_=image_.scaled(QSize(width, height),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
    img_size_=image_.size();
    img_pos_.setX(floor((width - image_.width()) / 2));
    img_pos_.setY(-floor((height - image_.height()) / 2));
}
void SelectCamera::paintEvent(QPaintEvent *) {
    FrameMoving();
}

void SelectCamera::getImage(int id)
{
    cap_.open(id);
    if(!cap_.isOpened())
        return;
    timer_send_->start(literals::kDefaultFPS);
}
void SelectCamera::resizeEvent(QResizeEvent *) {
    ResizeImage();
    if(img_size_.width()==0) {
        ui->image_scene->setGeometry(QRect(QPoint(0,0), ui->widget->size()));
    }else {
        ui->image_scene->setGeometry(QRect(img_pos_, img_size_));
    }
    ui->select_area->setGeometry(QRect(ui->image_scene->pos(), ui->image_scene->size()));
    InitializationFrame();
}

void SelectCamera::showWindow(int id)
{
    if(id>=0) {
        ui->list_of_cameras_comboBox->setCurrentIndex(id);
        timer_show_->start(literals::kDefaultFPS);
        run_=true;
    }
    this->show();
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
Point2f SelectCamera::GravityCenter(std::vector<Point2f> &pts_src) {
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
void SelectCamera::CalculateHomography() {
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
void SelectCamera::on_nextButton_clicked() {
<<<<<<< HEAD
<<<<<<< HEAD
    //ui->list_of_cameras_comboBox->setCurrentIndex(-1); // this line makes TagWindow crash
=======
    ui->list_of_cameras_comboBox->setCurrentIndex(-1);
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
=======
    //ui->list_of_cameras_comboBox->setCurrentIndex(-1); // this line makes TagWindow crash
>>>>>>> master
    emit OpenTagsWindow();
}
void SelectCamera::on_list_of_cameras_comboBox_currentIndexChanged(int index) {
    run_=false;
    timer_show_->stop();
    cap_.release();
    ui->image_scene->setVisible(run_);
    if(index!=-1) {
        run_=true;
        resized_=!run_;
        ui->image_scene->setVisible(run_);
        cap_.open(ui->list_of_cameras_comboBox->currentIndex());
        if(!cap_.isOpened())
            return;
        ShowImg();
        timer_show_->start(literals::kDefaultFPS);
    }
}
void SelectCamera::FrameMoving() {
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
void SelectCamera::InitializationFrame() {
    int w=ui->frame_point_1->size().width();
    int h=ui->frame_point_1->size().height();
    ui->frame_point_1->setGeometry(1,1,w,h);
    ui->frame_point_2->setGeometry(ui->select_area->width()-w-1,1,w,h);
    ui->frame_point_3->setGeometry(ui->select_area->width()-w-1,ui->select_area->height()-h-1,w,h);
    ui->frame_point_4->setGeometry(1,ui->select_area->height()-h-1,w,h);
}
void SelectCamera::on_cutButton_clicked() {
    if(img_scr_.empty()) {
        return;
    }
    CalculateHomography();
    cuted_=true;
    resized_=!cuted_;
<<<<<<< HEAD
<<<<<<< HEAD
    // emit that img is cutted
=======
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
=======
    // emit that img is cutted
>>>>>>> master
}
void SelectCamera::on_originalButton_clicked() {
    cuted_=false;
    resized_=false;
    img_pos_=QPoint(0,0);
    img_size_=QSize(0,0);
}
void SelectCamera::on_camera_connectButton_clicked() {
    InitializationFrame();
    run_=false;
    timer_show_->stop();
    cap_.release();
    ui->image_scene->setVisible(run_);
        run_=true;
        resized_=!run_;
        ui->image_scene->setVisible(run_);
        cap_.open(0);
        if(!cap_.isOpened())
            return;
        ShowImg();
        timer_show_->start(literals::kDefaultFPS);
}

void SelectCamera::closeEvent(QCloseEvent *) {
    ui->list_of_cameras_comboBox->setCurrentIndex(-1);
    emit OpenTagsWindow();
}
