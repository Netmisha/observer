#ifndef SELECTCAMERA_H
#define SELECTCAMERA_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"
<<<<<<< HEAD
#include <QLabel>
#include <mutex>
=======
#include <QWidget>
#include <QPainter>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>
#include <thread>
#include <mutex>

>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301
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

private slots:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void addImage(Mat);
    void on_select_from_listButton_clicked();

    void on_remote_cameraButton_clicked();

    void on_previewButton_clicked();

    void on_nextButton_clicked();

private:
<<<<<<< HEAD
    void ShowImg ();
    Ui::SelectCamera *ui;
    volatile bool run=false;
    std::mutex mut;
=======
    Point2f CrossingLine(std::vector<Point2f> &);
    Point2f GravityCenter(std::vector<Point2f> &);
    void CalculateHomography();
    void InitializationFrame();
    void ShowImg ();
    void ShowDeviceList();
    void ResizeImage();
    Ui::SelectCamera *ui;
    volatile bool run_=false;
    QPoint press_pos_;
    VideoCapture cap_;
    Mat homography_;
    bool cuted_=false;
    Size img_out_size_;
    Mat img_scr_;
    QSize img_size;
    QPoint img_pos;
    QImage image;
    std::mutex mtx_;
>>>>>>> e9c1bb0359ccd1f61c8f36615adef41abfe79301
};

#endif // SELECTCAMERA_H
