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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete settings_;
    delete video_tag_;
    delete select_camera_;
}

void MainWindow::on_pushButton_clicked()
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

}
