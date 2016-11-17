#ifndef SELECTCAMERA_H
#define SELECTCAMERA_H
#include <QMainWindow>
#include "opencv2/opencv.hpp"
<<<<<<< HEAD
=======
#include "opencv2/video.hpp"
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
#include <QWidget>
#include <QPainter>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>
#include <QTimer>
#include <mutex>
using namespace cv;
namespace Ui {
class SelectCamera;
}
namespace literals {
    const char kDefaultIndex=-1;
    const int kDefaultFPS=40;
}
class SelectCamera : public QMainWindow
{
    Q_OBJECT
public:
    explicit SelectCamera(QWidget *parent = 0);
    ~SelectCamera();
    Mat ProcessingImage(Mat);
    void showWindow(int id);
private slots:
    void paintEvent(QPaintEvent *);
    void getImage(int);
    void resizeEvent(QResizeEvent *);
    void addImage(Mat);
    void on_timer_show();
<<<<<<< HEAD
<<<<<<< HEAD
    void on_timer_send(); // emits the signal
=======
    void on_timer_send();
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
=======
    void on_timer_send(); // emits the signal
>>>>>>> master
    void send_stop();
    void on_select_from_listButton_clicked();
    void ResizeImage();
    void on_remote_cameraButton_clicked();
    void on_nextButton_clicked();
    void on_list_of_cameras_comboBox_currentIndexChanged(int);
    void FrameMoving ();
    void on_cutButton_clicked();
    void on_originalButton_clicked();
    void on_camera_connectButton_clicked();
    void closeEvent(QCloseEvent *);
signals:
    void RepaintLines(QVector<QPoint> &);
    void SizeChange(QResizeEvent *);
    void SendImage(Mat);
    void OpenTagsWindow();
private:
    Point2f CrossingLine(std::vector<Point2f> &);
    Point2f GravityCenter(std::vector<Point2f> &);
    void CalculateHomography();
    void InitializationFrame();
    void ShowImg ();
    void ShowDeviceList();
    Ui::SelectCamera *ui;
    VideoCapture cap_;
    Mat homography_;
    Mat img_scr_;
    QSize img_size_;
    Size img_out_size_;
    QPoint img_pos_;
    QImage image_;
    std::mutex mtx_;
    bool resized_=false;
    bool cuted_=false;
    bool run_=false;
    QTimer *timer_show_;
    QTimer *timer_send_;
};
#endif // SELECTCAMERA_H
