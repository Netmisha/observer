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
    connect(settings_, SIGNAL(OpenTagsWindow()), this, SLOT(OpenSelectCamera()));
    connect(select_camera_, SIGNAL(OpenTagsWindow()), this, SLOT(CloseSelectCamera()));
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

void MainWindow::CloseSelectCamera()
{
    select_camera_->hide();
    settings_->show();
}

void MainWindow::OpenSelectCamera()
{
    settings_->hide();
    select_camera_->showWindow(0);
}
