#ifndef SELECTCAMERA_H
#define SELECTCAMERA_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"
#include <QWidget>
#include <QPainter>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>
#include <thread>

using namespace cv;
namespace Ui {
class SelectCamera;
}
namespace literals {
    const char kDefoultIndex=-1;
}
class SelectCamera : public QMainWindow
{
    Q_OBJECT
public:
    explicit SelectCamera(QWidget *parent = 0);
    ~SelectCamera();
    Mat ProcessingImage(Mat);
private slots:
    void on_select_from_listButton_clicked();

    void on_remote_cameraButton_clicked();

    void on_nextButton_clicked();

    void on_list_of_cameras_comboBox_currentIndexChanged(int);

    void FrameMoving ();

    void on_cutButton_clicked();

    void on_originalButton_clicked();

    void on_camera_connectButton_clicked();

signals:
    void RepaintLines(QVector<QPoint> &);
private:
    Point2f CrossingLine(std::vector<Point2f> &);
    Point2f GravityCenter(std::vector<Point2f> &);
    void CalculateHomography();
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void InitializationFrame();
    void ShowImg ();
    void ShowDeviceList();
    Ui::SelectCamera *ui;
    volatile bool run_=false;
    QPoint press_pos_;
    VideoCapture cap_;
    Mat homography_;
    bool cuted_=false;
    Size img_out_size_;
    Mat img_scr_;
};

#endif // SELECTCAMERA_H
