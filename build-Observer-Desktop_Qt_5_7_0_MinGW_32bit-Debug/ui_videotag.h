/********************************************************************************
** Form generated from reading UI file 'videotag.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOTAG_H
#define UI_VIDEOTAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoTag
{
public:
    QPushButton *Start;
    QPushButton *Stop;
    QPushButton *Pause;
    QListWidget *TagList;
    QPushButton *AddTag;
    QLabel *MainVideo;
    QLabel *TagVideo;

    void setupUi(QWidget *VideoTag)
    {
        if (VideoTag->objectName().isEmpty())
            VideoTag->setObjectName(QStringLiteral("VideoTag"));
        VideoTag->resize(648, 388);
        Start = new QPushButton(VideoTag);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(10, 230, 71, 21));
        Stop = new QPushButton(VideoTag);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(190, 230, 71, 21));
        Pause = new QPushButton(VideoTag);
        Pause->setObjectName(QStringLiteral("Pause"));
        Pause->setGeometry(QRect(100, 230, 71, 21));
        TagList = new QListWidget(VideoTag);
        TagList->setObjectName(QStringLiteral("TagList"));
        TagList->setGeometry(QRect(10, 260, 631, 111));
        AddTag = new QPushButton(VideoTag);
        AddTag->setObjectName(QStringLiteral("AddTag"));
        AddTag->setGeometry(QRect(400, 230, 71, 21));
        MainVideo = new QLabel(VideoTag);
        MainVideo->setObjectName(QStringLiteral("MainVideo"));
        MainVideo->setGeometry(QRect(20, 30, 241, 191));
        TagVideo = new QLabel(VideoTag);
        TagVideo->setObjectName(QStringLiteral("TagVideo"));
        TagVideo->setGeometry(QRect(390, 30, 241, 191));
        TagList->raise();
        Start->raise();
        Stop->raise();
        Pause->raise();
        AddTag->raise();
        MainVideo->raise();
        TagVideo->raise();

        retranslateUi(VideoTag);

        QMetaObject::connectSlotsByName(VideoTag);
    } // setupUi

    void retranslateUi(QWidget *VideoTag)
    {
        VideoTag->setWindowTitle(QApplication::translate("VideoTag", "Form", 0));
        Start->setText(QApplication::translate("VideoTag", "Start|Cont.", 0));
        Stop->setText(QApplication::translate("VideoTag", "Stop", 0));
        Pause->setText(QApplication::translate("VideoTag", "Pause", 0));
        AddTag->setText(QApplication::translate("VideoTag", "Add Tag", 0));
        MainVideo->setText(QString());
        TagVideo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoTag: public Ui_VideoTag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOTAG_H
