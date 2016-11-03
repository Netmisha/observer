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
        ui->opencv_view->showImage(frame);
    }
}
void SelectCamera::on_previewButton_clicked()
{
    run=true;
    std::thread thr(&SelectCamera::ShowImg, this);
    thr.detach();
}

void SelectCamera::on_nextButton_clicked()
{
    run=false;
}
