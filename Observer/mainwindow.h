#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "videotag.h"
#include "selectcamera.h"
#include "settingswindow.h"
#include "opencv2/opencv.hpp"
#include  <opencv2/highgui/highgui.hpp>
#include <mutex>
#include <QMouseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void CloseSettings();
    void OpenTags();
    void CloseTags();
    void CloseSelectCamera();
    void OpenSelectCamera();
    void on_SQ2_clicked();
    void on_SQ_clicked();
    void on_SQ3_clicked();
    void on_SettingButton_clicked();
    void itemClicked(QListWidgetItem *item);

     void ReceiveImageM(Mat imgsrc); // streams video to main LABEL
     void Stream2nd(Mat imgsrc);  // stream video to second label screen
    //void Stream3rd(Mat img);
   // void Stream4th(Mat img);
 void showContextMenu(QPoint pos);
signals:
    void CameraID(int id);
    void CameraID2_1(int id);
    void CameraID3_2(int id);
    void CameraID3_3(int id);
private:

    typedef struct {int id; QString name;}cameras;
    void ShowListCamera();
    void GetQuantCamer();
    int QU;
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent *event);
    Mat frameM; Mat SecondFrame; Mat FourthFrame; Mat ThirdFrame;
    void paintEvent(QPaintEvent *event);
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
};

#endif // MAINWINDOW_H
