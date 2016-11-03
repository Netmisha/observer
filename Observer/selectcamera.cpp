#include "selectcamera.h"
#include "ui_selectcamera.h"
#include "cqtopencvviewergl.h"

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
    /*VideoCapture cap(NULL); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return;

    namedWindow("Video",1);
    while(1)
    {
        Mat frame;
        cap >> frame;         // get a new frame from camera
        imshow("Video", frame);

        // Press 'c' to escape
        if(waitKey(30) == 'c') break;
    }*/
}
