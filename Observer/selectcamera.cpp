#include "selectcamera.h"
#include "ui_selectcamera.h"

SelectCamera::SelectCamera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCamera)
{
    ui->setupUi(this);
    ui->remote_settingBox->setVisible(!ui->remote_settingBox->isVisible());
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
