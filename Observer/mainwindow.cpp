#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings_=new SettingsWindow(parent);
    video_tag_=new VideoTag (parent);
    select_camera_=new SelectCamera(parent);
    connect(settings_, SIGNAL(OpenMainWindow()), this, SLOT(CloseSettings()));
    connect(settings_, SIGNAL(OpenTagsWindow()), this, SLOT(OpenTags()));
    connect(select_camera_, SIGNAL(OpenTagsWindow()), this, SLOT(CloseSelectCamera()));
    connect(video_tag_, SIGNAL(OpenSelectCamera()), this, SLOT(OpenSelectCamera()));
    connect(video_tag_, SIGNAL(OpenSettings()), this, SLOT(CloseTags()));
<<<<<<< HEAD
    QObject::connect(video_tag_,SIGNAL(SendID(int)),select_camera_,SLOT(getImage(int)));
    QObject::connect(select_camera_,SIGNAL(SendImage(Mat)),video_tag_,SLOT(ReceiveImage(Mat)));
    QObject::connect(this,SIGNAL(CameraID(int)),select_camera_,SLOT(getImage(int)));
    QObject::connect(select_camera_,SIGNAL(SendImage(Mat)),this,SLOT(ReceiveImageM(Mat)));
    GetQuantCamer();
    for (int i=0;i<C.size();i++){ ui->CameraList->addItem(C.at(i)->name);}
    connect(ui->CameraList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked(QListWidgetItem*)));

}
void MainWindow::mousePressEvent(QMouseEvent *event){


}
void MainWindow::ReceiveImageM(Mat imgsrc){
    frameM = imgsrc;
    QImage qimgOriginal((uchar*)frameM.data,frameM.cols,frameM.rows, frameM.step,QImage::Format_RGB888);
    qimgOriginal =  qimgOriginal.scaled(ui->StreamArea->width(),ui->StreamArea->height(),Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->StreamArea->setPixmap(QPixmap::fromImage(qimgOriginal));

}
void MainWindow::itemClicked(QListWidgetItem *item){
 emit CameraID(ui->CameraList->currentRow());
=======

    QObject::connect(video_tag_,SIGNAL(SendID(int)),select_camera_,SLOT(getImage(int)));
    QObject::connect(select_camera_,SIGNAL(SendImage(Mat)),video_tag_,SLOT(ReceiveImage(Mat)));

    pixmapS = new QPixmap("D:\\Projects\\Observer\\CROSS\\Square.png");
    ButtonIcon = new QIcon(*pixmapS);
    ui->SQ->setIcon(*ButtonIcon);
    ui->SQ->setIconSize(ui->SQ->size());

    pixmapS2 = new QPixmap("D:\\Projects\\Observer\\CROSS\\Square2.png");
    ButtonIcon2 = new QIcon(*pixmapS2);
    ui->SQ2->setIcon(*ButtonIcon2);
    ui->SQ2->setIconSize(ui->SQ2->size());

    pixmapS3 = new QPixmap("D:\\Projects\\Observer\\CROSS\\Square4.png");
    ButtonIcon3 = new QIcon(*pixmapS3);
    ui->SQ3->setIcon(*ButtonIcon3);
    ui->SQ3->setIconSize(ui->SQ3->size());
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
}

void MainWindow::GetQuantCamer(){
    VideoCapture V; int device_count=0;
    while (device_count<100) {
        cameras *T = new cameras;
        V.open(device_count);
        if(!V.isOpened()){T = nullptr; break;}
        V.release();
        T->id = device_count;
        T->name = "camera #" + QString::number(T->id);
        C.push_back(T);
        T = nullptr;
        device_count++;
    }
}
void MainWindow::ShowListCamera(){


}
void MainWindow::paintEvent(QPaintEvent *event){
if(windows == 1){
    P1.begin(this);
    P1.setPen(Qt::PenStyle::DashLine);
    P1.drawRect(ui->StreamArea->x(),ui->StreamArea->y(),ui->StreamArea->width(),ui->StreamArea->height());
    P1.end();
}
else if(windows == 2){
 P1.begin(this);
 P1.setPen(Qt::PenStyle::DashLine);
 P1.drawRect(ui->StreamArea->x(),ui->StreamArea->y()*2,ui->StreamArea->width()/2,ui->StreamArea->height()/2);
 P1.end();
/*QLabel *la = new QLabel(this);
QWidget *p = new QWidget;
la->setGeometry(ui->StreamArea->x(),ui->StreamArea->y()*2,ui->StreamArea->width()/2,ui->StreamArea->height()/2);
QHBoxLayout *w = new QHBoxLayout();
p->setLayout(w);
p->setGeometry(ui->StreamArea->geometry());
la->setText("fds");
w->addWidget(la);
setLayout(w);
P1.drawRect(la->geometry());
P1.end();

*/
 P2.begin(this);
 P2.setPen(Qt::PenStyle::DashLine);
 P2.drawRect(ui->StreamArea->x()*2,ui->StreamArea->y()*2,ui->StreamArea->width()/2,ui->StreamArea->height()/2);
 P2.end();

}
else if(windows == 4){
    P1.begin(this);
    P1.setPen(Qt::PenStyle::DashLine);
    P1.drawRect(ui->StreamArea->x(),ui->StreamArea->y(),ui->StreamArea->width()/2,ui->StreamArea->height()/2);
    P1.end();

    P2.begin(this);
    P2.setPen(Qt::PenStyle::DashLine);
    P2.drawRect(ui->StreamArea->x()*2,ui->StreamArea->y(),ui->StreamArea->width()/2,ui->StreamArea->height()/2);
    P2.end();

    P3.begin(this);
    P3.setPen(Qt::PenStyle::DashLine);
    P3.drawRect(ui->StreamArea->x(),ui->StreamArea->y()*3.5,ui->StreamArea->width()/2,ui->StreamArea->height()/2);
    P3.end();

    P4.begin(this);
    P4.setPen(Qt::PenStyle::DashLine);
    P4.drawRect(ui->StreamArea->x()*2,ui->StreamArea->y()*3.5,ui->StreamArea->width()/2,ui->StreamArea->height()/2);
    P4.end();

}

}
MainWindow::~MainWindow()
{
    delete ui;
    delete settings_;
    delete video_tag_;
    delete select_camera_;
}

<<<<<<< HEAD
void MainWindow::on_SettingButton_clicked()
=======
void MainWindow::on_pushButton_clicked()
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
{
    settings_->show();
    this->hide();
}

void MainWindow::CloseSettings()
{
    settings_->hide();
    this->show();
}

void MainWindow::OpenTags()
{
    settings_->hide();
    video_tag_->show();
}

void MainWindow::CloseTags()
{
    video_tag_->hide();
    settings_->show();
<<<<<<< HEAD
=======
}

void MainWindow::CloseSelectCamera()
{
    select_camera_->hide();
    video_tag_->show();
}

void MainWindow::OpenSelectCamera()
{
    video_tag_->hide();
    select_camera_->showWindow(0);
}


void MainWindow::on_SQ2_clicked()
{

}

void MainWindow::on_SQ_clicked()
{
SoloSteam = new QLabel;

}

void MainWindow::on_SQ3_clicked()
{

>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
}

void MainWindow::CloseSelectCamera()
{
    select_camera_->hide();
    video_tag_->show();
}

void MainWindow::OpenSelectCamera()
{
    video_tag_->hide();
    select_camera_->showWindow(0);
}


void MainWindow::on_SQ2_clicked()
{

windows =2;
this->update();

}

void MainWindow::on_SQ_clicked()
{
windows = 1;
this->update();

}

void MainWindow::on_SQ3_clicked()
{
windows = 4;
this->update();
}

