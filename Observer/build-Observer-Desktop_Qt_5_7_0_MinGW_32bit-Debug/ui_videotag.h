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
#include <QtWidgets/QFrame>
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
    QListWidget *TagList;
    QPushButton *AddTag;
    QLabel *MainVideo;
    QLabel *TagVideo;
    QFrame *line;
    QPushButton *Back;
    QPushButton *Next;

    void setupUi(QWidget *VideoTag)
    {
        if (VideoTag->objectName().isEmpty())
            VideoTag->setObjectName(QStringLiteral("VideoTag"));
        VideoTag->resize(648, 437);
        Start = new QPushButton(VideoTag);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(30, 230, 221, 31));
        Start->setFlat(false);
        TagList = new QListWidget(VideoTag);
        TagList->setObjectName(QStringLiteral("TagList"));
        TagList->setGeometry(QRect(10, 280, 631, 111));
        AddTag = new QPushButton(VideoTag);
        AddTag->setObjectName(QStringLiteral("AddTag"));
        AddTag->setGeometry(QRect(400, 230, 221, 31));
        MainVideo = new QLabel(VideoTag);
        MainVideo->setObjectName(QStringLiteral("MainVideo"));
        MainVideo->setGeometry(QRect(20, 30, 241, 191));
        TagVideo = new QLabel(VideoTag);
        TagVideo->setObjectName(QStringLiteral("TagVideo"));
        TagVideo->setGeometry(QRect(390, 30, 241, 191));
        line = new QFrame(VideoTag);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(313, 20, 20, 221));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        Back = new QPushButton(VideoTag);
        Back->setObjectName(QStringLiteral("Back"));
        Back->setGeometry(QRect(10, 400, 71, 31));
        Next = new QPushButton(VideoTag);
        Next->setObjectName(QStringLiteral("Next"));
        Next->setGeometry(QRect(570, 400, 71, 31));
        TagList->raise();
        Start->raise();
        AddTag->raise();
        MainVideo->raise();
        TagVideo->raise();
        line->raise();
        Back->raise();
        Next->raise();

        retranslateUi(VideoTag);

        QMetaObject::connectSlotsByName(VideoTag);
    } // setupUi

    void retranslateUi(QWidget *VideoTag)
    {
        VideoTag->setWindowTitle(QApplication::translate("VideoTag", "Form", 0));
        Start->setText(QApplication::translate("VideoTag", "Start", 0));
        AddTag->setText(QApplication::translate("VideoTag", "Add Tag", 0));
        MainVideo->setText(QString());
        TagVideo->setText(QString());
        Back->setText(QApplication::translate("VideoTag", "Back", 0));
        Next->setText(QApplication::translate("VideoTag", "Next", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoTag: public Ui_VideoTag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOTAG_H
