#include "selectcamera.h"
#include "ui_selectcamera.h"
using namespace cv;
SelectCamera::SelectCamera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCamera)
{
    ui->setupUi(this);
    ui->remote_settingBox->setVisible(false);
}

SelectCamera::~SelectCamera()
{
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

void SelectCamera::on_previewButton_clicked()
{
    //CQtOpenCVViewerGl m=new CQtOpenCVViewerGl(ui->videoFrame);
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return;

    //namedWindow("Video",1);
    int i=1;
    while(i)
    {
        Mat frame;
        cap >> frame;
        imwrite("tem.jpg",frame);
        ui->label->setPixmap(QPixmap("tem.jpg"));
        ui->label->repaint();
    }
}
