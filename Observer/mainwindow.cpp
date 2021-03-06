#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     settings_=new SettingsWindow(parent);
     video_tag_=new VideoTag (parent);
     SettingsF = new SettingsFile();
     select_camera_=new SelectCamera(parent);
     //QObject::connect(video_tag_,SIGNAL(SendID(int)),select_camera_,SLOT(getImage(int)));
     //QObject::connect(select_camera_,SIGNAL(SendImage(Mat)),video_tag_,SLOT(ReceiveImage(Mat)));
     //QObject::connect(this,SIGNAL(CameraID(int)),select_camera_,SLOT(getImage(int)));
     //QObject::connect(select_camera_,SIGNAL(SendImage(Mat)),this,SLOT(ReceiveImageM(Mat)));
     QObject::connect(ui->CameraList,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showContextMenu(QPoint)));
     //QObject::connect(select_camera_,SIGNAL(SendImage(Mat)),this,SLOT(Stream2nd(Mat)));
     //QObject::connect(this,SIGNAL(CameraID3_2(int)),select_camera_,SLOT(getImage(int)));
     //QObject::connect(select_camera_,SIGNAL(SendImage(Mat)),this,SLOT(Stream4th(Mat)));
     //QObject::connect(this,SIGNAL(CameraID3_3(int)),select_camera_,SLOT(getImage(int)));
     //QObject::connect(select_camera_,SIGNAL(SendImage(Mat)),this,SLOT(Stream3rd(Mat)));
     //GetQuantCamer();
     //for (int i=0;i<C.size();i++){ ui->CameraList->addItem(C.at(i)->name);}
     ui->Stream1->setVisible(false);
     ui->Stream2->setVisible(true); // main is Stream2
     ui->Stream3->setVisible(false);
     ui->Stream4->setVisible(false);
     connect(ui->CameraList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked(QListWidgetItem*)));
     ui->CameraList->setContextMenuPolicy(Qt::CustomContextMenu);
     QObject::connect(this,SIGNAL(PassSettingFile(SettingsFile*)),settings_,SLOT(ShowWindow(SettingsFile*)));
     QObject::connect(this,SIGNAL(PassOnSelectCamera()),select_camera_,SLOT(showWindow()));
     QObject::connect(settings_,SIGNAL(OpenMainWindow(SettingsFile*)),this,SLOT(ReceiveSettingFromSetW(SettingsFile*)));
     QObject::connect(select_camera_,SIGNAL(OpenMainWindow()),this,SLOT(CloseSelectCamera()));
     QObject::connect(select_camera_,SIGNAL(OpenTagsWindow(SettingsFile*)),video_tag_,SLOT(ReceiveFromSelectCamera(SettingsFile*)));
     QObject::connect(video_tag_,SIGNAL(SendSettingSelectCamera(SettingsFile*)),select_camera_,SLOT(showWindow(SettingsFile*)));
     QObject::connect(video_tag_,SIGNAL(SendToSettingsWindow(SettingsFile*)),settings_,SLOT(ShowWindow(SettingsFile*)));
     QObject::connect(settings_,SIGNAL(OpenTagsWindow(SettingsFile*)),video_tag_,SLOT(ReceiveFromSetting(SettingsFile*)));
     QObject::connect(video_tag_,SIGNAL(SendToMainFromTag(SettingsFile*)),this,SLOT(ReceiveFromTags(SettingsFile*)));
     connect(&StreamM, SIGNAL(OnSave(QString)), this, SLOT(OnSave(QString)));
}
void MainWindow::mousePressEvent(QMouseEvent *event){


}
void MainWindow::ReceiveFromTags(SettingsFile *obj){

    this->show();
    SettingsF = obj;
    StreamM.setSettings(*SettingsF);
    ui->CameraList->addItem(SettingsF->getCameraName());
}
void MainWindow::ReceiveSettingFromSetW(SettingsFile *obj){
    this->show();
    SettingsF = obj;
    StreamM.setSettings(*SettingsF);
    ui->CameraList->addItem(SettingsF->getCameraName());
}

void MainWindow::CloseSelectCamera()
{
    this->show();
}

void MainWindow::Stream2nd(Mat imgsrc){

    SecondFrame = imgsrc;
    QImage qimgOriginal((uchar*)SecondFrame.data,SecondFrame.cols,SecondFrame.rows, SecondFrame.step,QImage::Format_RGB888);
    qimgOriginal =  qimgOriginal.scaled(ui->Stream2->width(),ui->Stream2->height(),Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->Stream2->setPixmap(QPixmap::fromImage(qimgOriginal));
}
/*
void MainWindow::Stream4th(Mat imgsrc){
    ThirdFrame = imgsrc;
    QImage qimgOriginal((uchar*)ThirdFrame.data,ThirdFrame.cols,ThirdFrame.rows, ThirdFrame.step,QImage::Format_RGB555);
    qimgOriginal =  qimgOriginal.scaled(ui->Stream3_2->width(),ui->Stream3_2->height(),Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->Stream3_2->setPixmap(QPixmap::fromImage(qimgOriginal));
}
void MainWindow::Stream3rd(Mat imgsrc){
    FourthFrame = imgsrc;
    QImage qimgOriginal((uchar*)FourthFrame.data,FourthFrame.cols,FourthFrame.rows, FourthFrame.step,QImage::Format_RGB666);
    qimgOriginal =  qimgOriginal.scaled(ui->Stream3_1->width(),ui->Stream3_1->height(),Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->Stream3_1->setPixmap(QPixmap::fromImage(qimgOriginal));
} */
void MainWindow::showContextMenu(QPoint pos){
    QPoint item = ui->CameraList->mapToGlobal(pos);
    QMenu submenu;
    submenu.addAction("Add to 2nd subscreen");
    submenu.addAction("Add to 3rd subscreen");
    submenu.addAction("Add to 4th subscreen");
    QAction* rightclick = submenu.exec(item);
    if(rightclick && rightclick->text().contains("Add to 2nd subscreen")){
       qDebug()<<"Begin stream to second window";
       emit CameraID2_1(ui->CameraList->currentRow());
    }
    else if(rightclick && rightclick->text().contains("Add to 3rd subscreen")){
       emit CameraID3_2(ui->CameraList->currentRow());
    }
    else if(rightclick && rightclick->text().contains("Add to 4th subscreen")){
        emit CameraID3_3(ui->CameraList->currentRow());
    }
}

void MainWindow::ReceiveImageM(Mat imgsrc){
    cvtColor(imgsrc,imgsrc,COLOR_BGR2RGB);
    frameM = imgsrc;
    QImage qimgOriginal((uchar*)frameM.data,frameM.cols,frameM.rows, frameM.step,QImage::Format_RGB888);
    qimgOriginal =  qimgOriginal.scaled(ui->Stream2->width(),ui->Stream2->height(),Qt::IgnoreAspectRatio, Qt::FastTransformation);
    if(windows == 1){
    ui->Stream2->setPixmap(QPixmap::fromImage(qimgOriginal));
    }
    else if(windows == 2){
        ui->Stream1->setPixmap(QPixmap::fromImage(qimgOriginal));
        ui->Stream2->setPixmap(QPixmap::fromImage(qimgOriginal));
    }
    else if(windows == 4){
        ui->Stream1->setPixmap(QPixmap::fromImage(qimgOriginal));
        ui->Stream2->setPixmap(QPixmap::fromImage(qimgOriginal));
        ui->Stream3->setPixmap(QPixmap::fromImage(qimgOriginal));
        ui->Stream4->setPixmap(QPixmap::fromImage(qimgOriginal));
    }
}

void MainWindow::itemClicked(QListWidgetItem *item){
 //emit CameraID(ui->CameraList->currentRow());

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


MainWindow::~MainWindow()
{
    delete ui;
    delete settings_;
    delete video_tag_;
    delete select_camera_;
}

void MainWindow::on_SettingButton_clicked()
{
    emit PassSettingFile(SettingsF);
    this->hide();
}
void MainWindow::ReceiveFromSC(SettingsFile *obj){
    this->show();
    SettingsF = obj;
    StreamM.setSettings(*SettingsF);
}
void MainWindow::OnSave(QString msg)
{
    ui->logsBrowser->append(msg);
}
void MainWindow::on_SelectCameraButton_clicked()
{
    emit PassOnSelectCamera();
    this->hide();
}

void MainWindow::on_SQ2_clicked()
{
    ui->Stream1->setVisible(true);
    ui->Stream2->setVisible(true);
    ui->Stream3->setVisible(false);
    ui->Stream4->setVisible(false);
    windows =2;
}

void MainWindow::on_SQ_clicked()
{
    ui->Stream1->setVisible(false);
    ui->Stream2->setVisible(true); // main is Stream2
    ui->Stream3->setVisible(false);
    ui->Stream4->setVisible(false);
    windows = 1;
}

void MainWindow::on_SQ3_clicked()
{
    ui->Stream1->setVisible(true);
    ui->Stream2->setVisible(true);
    ui->Stream3->setVisible(true);
    ui->Stream4->setVisible(true);
windows = 4;
}

void MainWindow::on_CameraList_currentRowChanged(int currentRow)
{
    StreamM.StopStream();
    StreamM.setSettings(*SettingsF);
    StreamM.StartStream();
    StreamM.SetMonitoring(true);
    connect(&StreamM,SIGNAL(SendImage(Mat)),this,SLOT(ReceiveImageM(Mat)));
}
