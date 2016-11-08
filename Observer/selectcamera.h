#ifndef SELECTCAMERA_H
#define SELECTCAMERA_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"
#include <QLabel>
#include <mutex>
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
    void on_select_from_listButton_clicked();

    void on_remote_cameraButton_clicked();

    void on_nextButton_clicked();

<<<<<<< HEAD
    void on_list_of_cameras_comboBox_currentIndexChanged(int index);
    void FrameMoving ();
    void on_cutButton_clicked();

signals:
    void RepaintLines(QVector<QPoint> &);
private:
    Point2f CrossingLine(std::vector<Point2f> &);
    void paintEvent(QPaintEvent *);
    void InitializationFrame();
=======
private:
>>>>>>> 761f1f10c020c61af79c178058402399ee8e1e39
    void ShowImg ();
    Ui::SelectCamera *ui;
    volatile bool run=false;
<<<<<<< HEAD
    QPoint press_pos;
    QVector<QPainter *> lines;
    VideoCapture cap;
    Mat h ;
    bool cut_=false;
=======
    std::mutex mut;
>>>>>>> 761f1f10c020c61af79c178058402399ee8e1e39
};

#endif // SELECTCAMERA_H
