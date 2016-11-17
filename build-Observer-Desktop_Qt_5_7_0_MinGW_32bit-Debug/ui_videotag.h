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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoTag
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *MainVideo;
    QFrame *line;
    QLabel *TagVideo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Start;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddTag;
    QListWidget *TagList;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Back;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Next;

    void setupUi(QWidget *VideoTag)
    {
        if (VideoTag->objectName().isEmpty())
            VideoTag->setObjectName(QStringLiteral("VideoTag"));
        VideoTag->resize(619, 448);
        verticalLayout_2 = new QVBoxLayout(VideoTag);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        MainVideo = new QLabel(VideoTag);
        MainVideo->setObjectName(QStringLiteral("MainVideo"));

        horizontalLayout->addWidget(MainVideo);

        line = new QFrame(VideoTag);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        TagVideo = new QLabel(VideoTag);
        TagVideo->setObjectName(QStringLiteral("TagVideo"));

        horizontalLayout->addWidget(TagVideo);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Start = new QPushButton(VideoTag);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setFlat(false);

        horizontalLayout_2->addWidget(Start);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        AddTag = new QPushButton(VideoTag);
        AddTag->setObjectName(QStringLiteral("AddTag"));

        horizontalLayout_2->addWidget(AddTag);


        verticalLayout->addLayout(horizontalLayout_2);

        TagList = new QListWidget(VideoTag);
        TagList->setObjectName(QStringLiteral("TagList"));

        verticalLayout->addWidget(TagList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Back = new QPushButton(VideoTag);
        Back->setObjectName(QStringLiteral("Back"));

        horizontalLayout_3->addWidget(Back);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        Next = new QPushButton(VideoTag);
        Next->setObjectName(QStringLiteral("Next"));

        horizontalLayout_3->addWidget(Next);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(VideoTag);

        QMetaObject::connectSlotsByName(VideoTag);
    } // setupUi

    void retranslateUi(QWidget *VideoTag)
    {
        VideoTag->setWindowTitle(QApplication::translate("VideoTag", "Form", 0));
        MainVideo->setText(QString());
        TagVideo->setText(QString());
        Start->setText(QApplication::translate("VideoTag", "Start", 0));
        AddTag->setText(QApplication::translate("VideoTag", "Add Tag", 0));
        Back->setText(QApplication::translate("VideoTag", "Add Camera", 0));
        Next->setText(QApplication::translate("VideoTag", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoTag: public Ui_VideoTag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOTAG_H
