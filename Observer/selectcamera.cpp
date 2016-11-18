#include "selectcamera.h"
#include "ui_selectcamera.h"
#include <QMessageBox>
SelectCamera::SelectCamera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCamera) {
    ui->setupUi(this);
    Initialize();
}
SelectCamera::~SelectCamera() {
    delete ui;
    Refresh();
}
void SelectCamera::showWindow() {
    this->show();
}
void SelectCamera::showWindow(settings_file::SettingsFile &settings){
    InitializeFromFile(settings);
    this->show();
}
QVector<QString> &SelectCamera::getCameraList(){
    return camera_list_;
}
void SelectCamera::ShowDeviceList() {
    scan_camera_=true;
    int device_count=0;
    cv::VideoCapture cap_;
    while (device_count<100) {
        cap_.open(device_count);
        if(!cap_.isOpened())
            break;
        cap_.release();
        ui->list_of_cameras_comboBox->addItem(QString("Camera_%1").arg(++device_count));
        camera_list_.push_back(QString("Camera_%1").arg(device_count));
        ui->list_of_cameras_comboBox->setCurrentIndex(-1);
    }
    scan_camera_=false;
}
void SelectCamera::InitializeFromFile(settings_file::SettingsFile &settings) {
    video_stream_.setSettings(settings);
    video_stream_.StartStream();
}
void SelectCamera::InitializeFrames() {
    int w=ui->frame_point_1->size().width();
    int h=ui->frame_point_1->size().height();
    ui->frame_point_1->setGeometry(QRect(QPoint(0,0), ui->frame_point_1->size()));
    ui->frame_point_2->setGeometry(QRect(QPoint(ui->select_area->width()-w-1,0), ui->frame_point_2->size()));
    ui->frame_point_3->setGeometry(QRect(QPoint(ui->select_area->width()-w-1,ui->select_area->height()-h-1), ui->frame_point_3->size()));
    ui->frame_point_4->setGeometry(QRect(QPoint(0,ui->select_area->height()-h-1), ui->frame_point_4->size()));
    FrameMoving();
}
void SelectCamera::ResizeImage(QImage &image) {
    image=image.scaled(QSize(ui->widget->width(), ui->widget->height()),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    image_pos_=QPoint(((ui->widget->width()-image.width())/2),((ui->widget->height()-image.height())/16));
    image_size_=image.size();
    if(scan_camera_) {
        this->resizeEvent(nullptr);
        scan_camera_=false;
    }
}
void SelectCamera::Initialize() {
    on_select_from_listButton_clicked();
    ShowDeviceList();
    connect(&video_stream_, SIGNAL(SendImage(Mat)), this, SLOT(ShowImage(Mat)));
    connect(this, SIGNAL(RepaintLines(QVector<QPoint>&)), ui->select_area, SLOT(setLinePos(QVector<QPoint>&)));
    connect(ui->frame_point_1,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    connect(ui->frame_point_2,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    connect(ui->frame_point_3,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    connect(ui->frame_point_4,SIGNAL(FrameMoving()), this, SLOT(FrameMoving()));
    ui->widget->resize(width()-2,height()-ui->verticalLayout_4->geometry().height()-ui->horizontalLayout->geometry().height()-ui->statusbar->height()-195);
    InitializeFrames();
}
void SelectCamera::on_select_from_listButton_clicked() {
    ui->select_cameraBox->setVisible(true);
    ui->remote_settingBox->setVisible(false);
    Refresh();
}
void SelectCamera::on_remote_cameraButton_clicked() {
    ui->select_cameraBox->setVisible(false);
    ui->remote_settingBox->setVisible(true);
    Refresh();
}
void SelectCamera::on_list_of_cameras_comboBox_currentIndexChanged(int index) {
    if (index>=0 && !scan_camera_) {
        ui->image_scene->setVisible(true);
        ui->select_area->setVisible(true);
        scan_camera_=true;
        QString name(ui->list_of_cameras_comboBox->itemText(index));
        video_stream_.addNewCamera(name,index);
        video_stream_.StartStream();
    }
}
void SelectCamera::ShowImage(Mat img) {
    cvtColor(img,img,COLOR_BGR2RGB);
    QImage image((const unsigned char*)(img.data),
                          img.cols, img.rows,
                          img.step, QImage::Format_RGB888);
    ResizeImage(image);
    ui->image_scene->setPixmap(QPixmap::fromImage(image));
    ui->image_scene->update();
}
void SelectCamera::on_nextButton_clicked() {
    Refresh();
    emit OpenTagsWindow(video_stream_.getSettings());
}
void SelectCamera::on_originalButton_clicked() {
   QVector<QPoint> p(0);
   video_stream_.setCropPoint(p);
   scan_camera_=true;
}
void SelectCamera::resizeEvent(QResizeEvent *) {
    ui->image_scene->setGeometry(QRect(image_pos_, image_size_));
    ui->select_area->setGeometry(QRect(image_pos_, image_size_));
    InitializeFrames();
}
void SelectCamera::on_cutButton_clicked() {
    video_stream_.setCropPoint(ui->select_area->getPoints(), ui->image_scene->size());
    scan_camera_=true;
}
void SelectCamera::FrameMoving() {
    int w=ui->frame_point_1->size().width();
    int h=ui->frame_point_1->size().height();
    QVector<QPoint> points;
    points.push_back(QPoint(ui->frame_point_1->pos().x(),ui->frame_point_1->pos().y()));
    points.push_back(QPoint(ui->frame_point_2->pos().x()+w,ui->frame_point_2->pos().y()));
    points.push_back(QPoint(ui->frame_point_3->pos().x()+w,ui->frame_point_3->pos().y()+h));
    points.push_back(QPoint(ui->frame_point_4->pos().x(),ui->frame_point_4->pos().y()+h));
    emit RepaintLines(points);
}
void SelectCamera::Refresh() {
    video_stream_.StopStream();
    ui->list_of_cameras_comboBox->setCurrentIndex(-1);
    ui->image_scene->setVisible(false);
    ui->select_area->setVisible(false);
}
