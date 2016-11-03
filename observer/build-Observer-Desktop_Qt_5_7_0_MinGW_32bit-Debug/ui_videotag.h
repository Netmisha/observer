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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "cqtopencvviewergl.h"

QT_BEGIN_NAMESPACE

class Ui_VideoTag
{
public:
    QComboBox *Tags;
    QPushButton *Start;
    QPushButton *Stop;
    CQtOpenCVViewerGl *MainV;
    QPushButton *AddTag;
    QPushButton *DeleteTag;
    QPushButton *RenameTag;
    QPushButton *Pause;

    void setupUi(QWidget *VideoTag)
    {
        if (VideoTag->objectName().isEmpty())
            VideoTag->setObjectName(QStringLiteral("VideoTag"));
        VideoTag->resize(400, 300);
        Tags = new QComboBox(VideoTag);
        Tags->setObjectName(QStringLiteral("Tags"));
        Tags->setGeometry(QRect(280, 30, 111, 22));
        Start = new QPushButton(VideoTag);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(10, 170, 80, 21));
        Stop = new QPushButton(VideoTag);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(200, 170, 80, 21));
        MainV = new CQtOpenCVViewerGl(VideoTag);
        MainV->setObjectName(QStringLiteral("MainV"));
        MainV->setEnabled(true);
        MainV->setGeometry(QRect(10, 30, 271, 141));
        MainV->setAutoFillBackground(false);
        AddTag = new QPushButton(VideoTag);
        AddTag->setObjectName(QStringLiteral("AddTag"));
        AddTag->setGeometry(QRect(10, 200, 80, 21));
        DeleteTag = new QPushButton(VideoTag);
        DeleteTag->setObjectName(QStringLiteral("DeleteTag"));
        DeleteTag->setGeometry(QRect(100, 200, 80, 21));
        RenameTag = new QPushButton(VideoTag);
        RenameTag->setObjectName(QStringLiteral("RenameTag"));
        RenameTag->setGeometry(QRect(200, 200, 81, 21));
        Pause = new QPushButton(VideoTag);
        Pause->setObjectName(QStringLiteral("Pause"));
        Pause->setGeometry(QRect(100, 170, 80, 21));

        retranslateUi(VideoTag);

        QMetaObject::connectSlotsByName(VideoTag);
    } // setupUi

    void retranslateUi(QWidget *VideoTag)
    {
        VideoTag->setWindowTitle(QApplication::translate("VideoTag", "Form", 0));
        Start->setText(QApplication::translate("VideoTag", "Start|Continue", 0));
        Stop->setText(QApplication::translate("VideoTag", "Stop", 0));
        AddTag->setText(QApplication::translate("VideoTag", "Add Tag", 0));
        DeleteTag->setText(QApplication::translate("VideoTag", "Delete Tag", 0));
        RenameTag->setText(QApplication::translate("VideoTag", "Rename Tag", 0));
        Pause->setText(QApplication::translate("VideoTag", "Pause", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoTag: public Ui_VideoTag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOTAG_H
