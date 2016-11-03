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

    void on_previewButton_clicked();

    void on_nextButton_clicked();

private:
    void ShowImg ();
    Ui::SelectCamera *ui;
    volatile bool run=false;
    std::mutex mut;
};

#endif // SELECTCAMERA_H
