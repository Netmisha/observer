#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <settingsfile.h>
#include <QMainWindow>
#include "videotag.h"
#include "selectcamera.h"
#include "settingswindow.h"
#include "opencv2/opencv.hpp"
#include  <opencv2/highgui/highgui.hpp>
#include <mutex>
#include <QMouseEvent>
#include <videostream.h>
using namespace settings_file;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     SettingsFile *SettingsF;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SQ2_clicked();
    void on_SQ_clicked();
    void on_SQ3_clicked();
    void on_SettingButton_clicked();
    void itemClicked(QListWidgetItem *item);
    void ReceiveFromTags(SettingsFile *obj);
     void ReceiveImageM(Mat imgsrc); // streams video to main LABEL
     void Stream2nd(Mat imgsrc);  // stream video to second label screen
    //void Stream3rd(Mat img);
   // void Stream4th(Mat img);
 void showContextMenu(QPoint pos);
 void on_SelectCameraButton_clicked();
 void ReceiveSettingFromSetW(SettingsFile *obj);
 void CloseSelectCamera();
void ReceiveFromSC(SettingsFile *obj);
signals:
    void CameraID(int id);
    void CameraID2_1(int id);
    void CameraID3_2(int id);
    void CameraID3_3(int id);
    void OpenSCWindow();
    void PassSettingFile(SettingsFile *obj);
    void PassOnSelectCamera();

private:
    typedef struct {int id; QString name;}cameras;
    void ShowListCamera();
    void GetQuantCamer();
    int QU;
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent *event);
    Mat frameM; Mat SecondFrame; Mat FourthFrame; Mat ThirdFrame;
    QFont setF;
    volatile int windows=1;
    QPainter P1,P2,P3,P4;
    QLabel *S2_0,*S2_1,*S4_0,*S4_1;
    QHBoxLayout *LABELS; QWidget *lay;
    QPainter p2;
    QVector <cameras*> C;
    QPixmap *pixmapS;
    QPixmap *pixmapS2;
    QPixmap *pixmapS3;
    QIcon *ButtonIcon3;
    QIcon *ButtonIcon2;
    QIcon *ButtonIcon;
    SelectCamera * select_camera_;
    SettingsWindow * settings_;
    VideoTag * video_tag_;
    VideoStream StreamM;
    QVector <settings_file::SettingsFile*> Sett;
    bool rec = false;
};

#endif // MAINWINDOW_H
