#include "settingsfile.h"
namespace settings_file {
SettingsFile::SettingsFile(){}

SettingsFile::SettingsFile(QString file_name):file_name_(file_name) {
    ReadSettings();
}
QString & SettingsFile::getFileName() {
    return file_name_;
}
QString & SettingsFile::getCameraName() {
    return camera_name_;
}
QString & SettingsFile::getCameraType() {
    return camera_type_;
}
QString & SettingsFile::getCameraPath() {
    return camera_path_;
}
int SettingsFile::getCameraId() {
    return camera_id_;
}
QVector<QPoint> & SettingsFile::getCropPoints() {
    return crop_points_;
}
QSize & SettingsFile::getCameraSize() {
    return camera_size_;
}
QVector<TagInfo> & SettingsFile::getTagsList() {
    return tags_list_;
}
QVector<QString> & SettingsFile::getMonitoringTags() {
    return monitoring_tags_;
}
QString &SettingsFile::getMonitoringType() {
    return monitoring_type_;
}
double & SettingsFile::getTimer() {
    return timer_;
}
void SettingsFile::setFileName(QString &file_name) {
    file_name_=file_name;
}
void SettingsFile::addNewCamera(QString &name, int id) {
    camera_name_=name;
    camera_id_=id;
    camera_type_=kLocalType;
}
void SettingsFile::addNewCamera(QString &name, QString &path) {
    camera_name_=name;
    camera_path_=path;
    camera_type_=kRemoteType;
}
void SettingsFile::setCameraName(QString &camera_name) {
    camera_name_=camera_name;
}
void SettingsFile::setCameraType(QString camera_type) {
    camera_type_=camera_type;
}
void SettingsFile::setCameraPath(QString &camera_path) {
    camera_path_=camera_path;
}
void SettingsFile::setCameraId(int camera_id) {
    camera_id_=camera_id;
}
void SettingsFile::setCropPoints(QVector<QPoint> &crop_points) {
    crop_points_.clear();
    crop_points_=crop_points;
}
void SettingsFile::setCameraSize(QSize &camera_size) {
    camera_size_=camera_size;
}
void SettingsFile::setTagsList(QVector<TagInfo> &tags_list) {
    tags_list_.clear();
    tags_list_=tags_list;
}
void SettingsFile::setMonitoringTags(QVector<QString>monitoring_tags) {
    monitoring_tags_.clear();
    monitoring_tags_=monitoring_tags;
}
void SettingsFile::setMonitoringType(QString type){
    monitoring_type_=type;
}
void SettingsFile::setTimer(double timer) {
    timer_=timer;
}
void SettingsFile::SaveSettings() {
    QFile file(file_name_);
    file.open(QIODevice::WriteOnly);
    GenerateSettingsFile(file);
}
void SettingsFile::ReadSettings() {
    tags_list_.clear();
    monitoring_tags_.clear();
    crop_points_.clear();
    QFile file(file_name_);
    file.open(QIODevice::ReadOnly);
    ParseSettingsFile(file);
}
void SettingsFile::GenerateSettingsFile(QFile &file) {
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement(kTagCamera);
    xmlWriter.writeTextElement(kTagName,camera_name_);
    xmlWriter.writeStartElement(kTagPath);
    xmlWriter.writeAttribute(kAttrType,camera_type_);
    if(camera_type_==kLocalType) {
        xmlWriter.writeCharacters(QString::number(camera_id_));
    }
    else {
        xmlWriter.writeCharacters(camera_path_);
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement(kTagCrop);
    xmlWriter.writeStartElement(kTagPoints);
    for(auto & it:crop_points_) {
        xmlWriter.writeStartElement(kTagPoint);
        xmlWriter.writeTextElement(kTagX,QString::number(it.x()));
        xmlWriter.writeTextElement(kTagY,QString::number(it.x()));
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement(kTagSize);
    xmlWriter.writeTextElement(kTagWidth,QString::number(camera_size_.width()));
    xmlWriter.writeTextElement(kTagHeigth,QString::number(camera_size_.height()));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement(kTagTags);
    for(auto & it:tags_list_) {
        xmlWriter.writeStartElement(kTagTag);
        xmlWriter.writeTextElement(kTagName,it.name_);
        xmlWriter.writeStartElement(kTagRect);
        xmlWriter.writeStartElement(kTagPoint);
        xmlWriter.writeTextElement(kTagX,QString::number(it.rect_.x()));
        xmlWriter.writeTextElement(kTagY,QString::number(it.rect_.x()));
        xmlWriter.writeEndElement();
        xmlWriter.writeStartElement(kTagSize);
        xmlWriter.writeTextElement(kTagWidth,QString::number(it.rect_.width()));
        xmlWriter.writeTextElement(kTagHeigth,QString::number(it.rect_.height()));
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement(kTagSettings);
    xmlWriter.writeAttribute(kAttrType,monitoring_type_);
    xmlWriter.writeStartElement(kTagEvents);
    for(auto & it:monitoring_tags_) {
        xmlWriter.writeTextElement(kTagName,it);
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeTextElement(kTagTimer,QString::number(timer_));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
}
void SettingsFile::ParseSettingsFile(QFile &file) {
    QXmlStreamReader Rxml;
    Rxml.setDevice(&file);
    Rxml.readNext();
    while(!Rxml.atEnd()) {
        if(Rxml.isStartElement())
        {
            if(Rxml.name() == kTagName)
            {
                camera_name_ = Rxml.readElementText();
            }
            if(Rxml.name() == kTagPath)
            {
                camera_type_ = Rxml.attributes().value(kAttrType).toString();
                if(camera_type_==kLocalType) {
                    camera_id_= Rxml.readElementText().toInt();
                }
                else {
                    camera_path_=Rxml.readElementText();
                }
            }
            if(Rxml.name() == kTagCrop)
            {
                Rxml.readNext();
                while (Rxml.name() != kTagSize) {
                    if(Rxml.name() == kTagPoint) {
                        while (Rxml.name() != kTagSize) {
                            int x,y;
                            if(Rxml.name() == kTagX) {
                                x=Rxml.readElementText().toInt();
                            }
                            if(Rxml.name() == kTagY) {
                                y=Rxml.readElementText().toInt();
                                crop_points_.push_back(QPoint(x,y));
                            }
                            Rxml.readNext();
                        }
                    }
                    else {
                        Rxml.readNext();
                    }
                }
                if(Rxml.name() == kTagSize) {
                    while (Rxml.name() != kTagTags) {
                        int w,h;
                        if(Rxml.name() == kTagWidth) {
                            w=Rxml.readElementText().toInt();
                        }
                        if(Rxml.name() == kTagHeigth) {
                            h=Rxml.readElementText().toInt();
                            camera_size_=QSize(w,h);
                        }
                        Rxml.readNext();
                    }
                }
            }
            if(Rxml.name() == kTagTags)
            {
                while (Rxml.name() != kTagSettings) {
                    if(Rxml.name() == kTagTag && Rxml.isStartElement()) {
                        while (Rxml.name() != kTagName) {
                            Rxml.readNext();
                        }
                        QString name=Rxml.readElementText();
                        while (Rxml.name() != kTagX) {
                            Rxml.readNext();
                        }
                        int x=Rxml.readElementText().toInt();
                        while (Rxml.name() != kTagY) {
                            Rxml.readNext();
                        }
                        int y=Rxml.readElementText().toInt();
                        while (Rxml.name() != kTagWidth) {
                            Rxml.readNext();
                        }
                        int w=Rxml.readElementText().toInt();
                        while (Rxml.name() != kTagHeigth) {
                            Rxml.readNext();
                        }
                        int h=Rxml.readElementText().toInt();
                        tags_list_.push_back(TagInfo(name, QRect(QPoint(x,y),QSize(w,h))));
                    }
                    else {
                        Rxml.readNext();
                    }
                }
            }
            if(Rxml.name() == kTagSettings)
            {
                monitoring_type_ = Rxml.attributes().value(kAttrType).toString();
                Rxml.readNext();
                while (Rxml.name() != kTagTimer) {
                    if(Rxml.name() == kTagName) {
                        monitoring_tags_.push_back(Rxml.readElementText());
                    }
                    Rxml.readNext();
                }
                if(Rxml.name() == kTagTimer) {
                    timer_=Rxml.readElementText().toDouble();
                }
            }
        }
        Rxml.readNext();
    }
}
}
