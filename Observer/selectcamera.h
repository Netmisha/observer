#ifndef SELECTCAMERA_H
#define SELECTCAMERA_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"
#include <QRubberBand>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>
#include <QPainter>

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

    void on_list_of_cameras_comboBox_currentIndexChanged(int index);
signals:
    void RepaintLines(QVector<QPoint> &);
private:
    void paintEvent(QPaintEvent *);
    void InitializationFrame();
    void ShowImg ();
    void ShowDeviceList();
    Ui::SelectCamera *ui;
    volatile bool run=false;
    QPoint press_pos;
    QVector<QPainter *> lines;
};

#endif // SELECTCAMERA_H
