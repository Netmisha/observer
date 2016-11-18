#ifndef SELECTCAMERA_H
#define SELECTCAMERA_H
#include <QMainWindow>
#include <QPainter>
#include <mutex>
<<<<<<< HEAD
#include "settingsfile.h"
#include <settingsfile.h>
using namespace settings_file;

=======
#include "videostream.h"
>>>>>>> 137c4eb47e4b6bfda7b1177f445e5eb2dd59b4bf
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
    void showWindow(settings_file::SettingsFile &);
    void showWindow();
private slots:
<<<<<<< HEAD
    void ReceiveFromMainWindow(SettingsFile *obj);
    void ReceiveFromTags(SettingsFile *obj);
    void ReceiveSettingSW(SettingsFile *obj);
    void paintEvent(QPaintEvent *);
    void getImage(int);
    void resizeEvent(QResizeEvent *);
    void addImage(Mat);
    void on_timer_show();
    void on_timer_send(); // emits the signal
    void send_stop();
=======
>>>>>>> 137c4eb47e4b6bfda7b1177f445e5eb2dd59b4bf
    void on_select_from_listButton_clicked();
    void on_remote_cameraButton_clicked();
    void on_list_of_cameras_comboBox_currentIndexChanged(int);
    void ShowImage(Mat);
    void on_nextButton_clicked();
    void on_originalButton_clicked();
<<<<<<< HEAD
    void on_camera_connectButton_clicked();
    void closeEvent(QCloseEvent *);
    void on_MainWindow_clicked();
    void on_Settings_clicked();

signals:
    void RepaintLines(QVector<QPoint> &);
    void SizeChange(QResizeEvent *);
    void SendImage(Mat);
    void OpenTagsWindow();
    void PassToTagWindow(SettingsFile *obj);
    void PassToMain(SettingsFile *obj);
    void SendToSettings(SettingsFile *obj);
=======
    void resizeEvent(QResizeEvent *);
    void on_cutButton_clicked();
    void FrameMoving();
signals:
    OpenTagsWindow(settings_file::SettingsFile &);
    RepaintLines(QVector<QPoint> &);
>>>>>>> 137c4eb47e4b6bfda7b1177f445e5eb2dd59b4bf
private:
    void Refresh();
    void InitializeFromFile(settings_file::SettingsFile &);
    void InitializeFrames();
    void ResizeImage(QImage &);
    void Initialize();
    void ShowDeviceList();
    Ui::SelectCamera *ui;
<<<<<<< HEAD
    SettingsFile *SettingF;
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
    QString file_name_;
    settings_file::SettingsFile settings_;
=======
    VideoStream video_stream_;
>>>>>>> 137c4eb47e4b6bfda7b1177f445e5eb2dd59b4bf
    QVector<QString> camera_list_;
    QPoint image_pos_;
    QSize image_size_;
    bool scan_camera_;
};
#endif // SELECTCAMERA_H
