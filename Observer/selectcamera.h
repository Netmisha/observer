#ifndef SELECTCAMERA_H
#define SELECTCAMERA_H
#include <QMainWindow>
#include <QPainter>
#include <mutex>
#include "videostream.h"
using namespace settings_file;
using namespace cv;
namespace Ui {
class SelectCamera;
}
class SelectCamera : public QMainWindow
{
    Q_OBJECT
public:
    explicit SelectCamera(QWidget *parent = 0);
    ~SelectCamera();
    QVector<QString> &getCameraList();
private slots:
    void showWindow(SettingsFile *);
    void showWindow();
    void closeEvent(QCloseEvent *);
    void on_select_from_listButton_clicked();
    void on_remote_cameraButton_clicked();
    void on_list_of_cameras_comboBox_currentIndexChanged(int);
    void ShowImage(Mat);
    void on_nextButton_clicked();
    void on_originalButton_clicked();
    void resizeEvent(QResizeEvent *);
    void on_cutButton_clicked();
    void FrameMoving();
    void on_camera_connectButton_clicked();    
signals:
    OpenTagsWindow(SettingsFile *);
    OpenMainWindow();
    RepaintLines(QVector<QPoint> &);
private:
    void Refresh();
    void InitializeFromFile(SettingsFile &);
    void InitializeFrames();
    void ResizeImage(QImage &);
    void Initialize();
    void ShowDeviceList();
    Ui::SelectCamera *ui;
    VideoStream video_stream_;
    QVector<QString> camera_list_;
    QPoint image_pos_;
    QSize image_size_;
    bool scan_camera_;
};
#endif // SELECTCAMERA_H
