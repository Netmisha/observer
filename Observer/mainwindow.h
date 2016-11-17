#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "videotag.h"
#include "selectcamera.h"
#include "settingswindow.h"
<<<<<<< HEAD
#include "opencv2/opencv.hpp"
#include  <opencv2/highgui/highgui.hpp>
#include <mutex>
#include <QMouseEvent>
=======

>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
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
<<<<<<< HEAD
=======
    void on_pushButton_clicked();
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
    void CloseSettings();
    void OpenTags();
    void CloseTags();
    void CloseSelectCamera();
    void OpenSelectCamera();
    void on_SQ2_clicked();
<<<<<<< HEAD
    void on_SQ_clicked();
    void on_SQ3_clicked();
    void on_SettingButton_clicked();
    void itemClicked(QListWidgetItem *item);
     void ReceiveImageM(Mat imgsrc);
signals:
    void CameraID(int id);
=======

    void on_SQ_clicked();

    void on_SQ3_clicked();

>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
private:
    typedef struct {int id; QString name;}cameras;
    void ShowListCamera();
    void GetQuantCamer();
    int QU;
    Ui::MainWindow *ui;
<<<<<<< HEAD
    void mousePressEvent(QMouseEvent *event);
    Mat frameM;
    void paintEvent(QPaintEvent *event);
    QFont setF;
    volatile int windows=1;
    QPainter P1,P2,P3,P4;
    QLabel *S2_0,*S2_1,*S4_0,*S4_1;
    QHBoxLayout *LABELS; QWidget *lay;
    QPainter p2;
    QVector <cameras*> C;
=======
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
    QPixmap *pixmapS;
    QPixmap *pixmapS2;
    QPixmap *pixmapS3;
    QIcon *ButtonIcon3;
    QIcon *ButtonIcon2;
    QIcon *ButtonIcon;
<<<<<<< HEAD
=======
    QLabel *SoloSteam;
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
    SelectCamera * select_camera_;
    SettingsWindow * settings_;
    VideoTag * video_tag_;
};

#endif // MAINWINDOW_H
