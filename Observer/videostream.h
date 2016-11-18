#ifndef VIDEOSTREAM_H
#define VIDEOSTREAM_H
#include <QWidget>
#include "opencv2/opencv.hpp"
#include <QTimer>
#include "settingsfile.h"

using namespace cv;
namespace video_settings {
}
class VideoStream : public QObject {
    Q_OBJECT
public:
    VideoStream();
    VideoStream(QString &);
    VideoStream(settings_file::SettingsFile &);
    virtual ~VideoStream();
    void setCropPoint(QVector<QPoint> &);
    void setCropPoint(QVector<QPoint> &, QSize);
    void getCropPoint(QVector<QPoint> & points, QSize & size);
    settings_file::SettingsFile &getSettings();
    void setFPS(int);
    void setFileName(QString &);
    void setSettings(settings_file::SettingsFile &);
    void addNewCamera(QString &, int);
    void addNewCamera(QString &, QString &);
    void StartStream();
    void StopStream();
private slots:
    void OnTimer();
signals:
    void SendImage(Mat);
private:
    void ReadImage();
    Point2f CrossingLine(std::vector<Point2f> &);
    Point2f GravityCenter(std::vector<Point2f> &);
    void CalculateHomography();
    Mat ProcessingImage(Mat);
    VideoCapture cap_;
    Mat homography_;
    Mat img_scr_;
    QSize img_size_;
    Size img_out_size_;
    QTimer timer_;
    QString file_name_;
    settings_file::SettingsFile settings_;
    int FPS_=40;
};

#endif // VIDEOSTREAM_H
