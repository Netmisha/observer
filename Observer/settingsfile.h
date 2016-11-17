#ifndef SETTINGSFILE_H
#define SETTINGSFILE_H

#include <QString>
#include <QVector>
#include <QPoint>
#include <QSize>
#include <QFile>
#include <QRect>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
namespace settings_file {
const QString kTagCamera="camera";
const QString kTagName="name";
const QString kTagPath="path";
const QString kTagCrop="crop";
const QString kTagPoints="points";
const QString kTagPoint="point";
const QString kTagX="x";
const QString kTagY="y";
const QString kTagSize="size";
const QString kTagWidth="width";
const QString kTagHeigth="height";
const QString kTagTags="tags";
const QString kTagTag="tag";
const QString kTagRect="rect";
const QString kTagSettings="settings";
const QString kTagEvents="events";
const QString kTagTimer="timer";
const QString kAttrType="type";
const QString kLocalType="local";
const QString kRemoteType="remote";
struct TagInfo{
    QString name_;
    QRect rect_;
    TagInfo(){}
    TagInfo(QString name, QRect rect):name_(name),rect_(rect){}
};
class SettingsFile
{
public:
    SettingsFile();
    SettingsFile(QString );
    QString &getFileName();
    QString &getCameraName();
    QString &getCameraType();
    QString &getCameraPath();
    int getCameraId();
    QVector<QPoint> &getCropPoints();
    QSize &getCameraSize();
    QVector<TagInfo> &getTagsList();
    QVector<QString> &getMonitoringTags();
    double &getTimer();
    void setFileName(QString &);
    void setCameraName(QString &);
    void setCameraType(QString &);
    void setCameraPath(QString &);
    void setCameraId(int);
    void setCropPoints(QVector<QPoint> &);
    void setCameraSize(QSize &);
    void setTagsList(QVector<TagInfo> &);
    void setMonitoringTags(QVector<QString>);
    void setTimer(double);
    void SaveSettings();
    void ReadSettings();
private:
    void ParseSettingsFile(QFile &);
    void GenerateSettingsFile(QFile &);
    QString file_name_;
    QString settings_;
    QString camera_name_;
    QString camera_type_;
    QString camera_path_;
    int camera_id_;
    QVector<QPoint> crop_points_;
    QSize camera_size_;
    QVector<TagInfo> tags_list_;
    QVector<QString> monitoring_tags_;
    double timer_;
};
}
#endif // SETTINGSFILE_H
