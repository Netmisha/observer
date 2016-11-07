/********************************************************************************
** Form generated from reading UI file 'selectcamera.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTCAMERA_H
#define UI_SELECTCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <movableframe.h>
#include <myframe.h>
#include "cqtopencvviewergl.h"

QT_BEGIN_NAMESPACE

class Ui_SelectCamera
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *select_from_listButton;
    QRadioButton *remote_cameraButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *select_cameraBox;
    QVBoxLayout *verticalLayout_5;
    QComboBox *list_of_cameras_comboBox;
    QGroupBox *remote_settingBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *camera_ipEdit;
    QLineEdit *camera_portEdit;
    QLineEdit *camera_passwordEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *camera_connectButton;
    CQtOpenCVViewerGl *opencv_view;
    QVBoxLayout *verticalLayout_6;
    myFrame *frame;
    MovableFrame *frame_point_4;
    MovableFrame *frame_point_2;
    MovableFrame *frame_point_3;
    MovableFrame *frame_point_1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *previewButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nextButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SelectCamera)
    {
        if (SelectCamera->objectName().isEmpty())
            SelectCamera->setObjectName(QStringLiteral("SelectCamera"));
        SelectCamera->resize(1060, 687);
        centralwidget = new QWidget(SelectCamera);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(16777215, 70));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        select_from_listButton = new QRadioButton(groupBox);
        select_from_listButton->setObjectName(QStringLiteral("select_from_listButton"));
        select_from_listButton->setChecked(true);

        horizontalLayout->addWidget(select_from_listButton);

        remote_cameraButton = new QRadioButton(groupBox);
        remote_cameraButton->setObjectName(QStringLiteral("remote_cameraButton"));

        horizontalLayout->addWidget(remote_cameraButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);

        select_cameraBox = new QGroupBox(centralwidget);
        select_cameraBox->setObjectName(QStringLiteral("select_cameraBox"));
        sizePolicy.setHeightForWidth(select_cameraBox->sizePolicy().hasHeightForWidth());
        select_cameraBox->setSizePolicy(sizePolicy);
        select_cameraBox->setMinimumSize(QSize(0, 58));
        select_cameraBox->setMaximumSize(QSize(16777215, 70));
        verticalLayout_5 = new QVBoxLayout(select_cameraBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        list_of_cameras_comboBox = new QComboBox(select_cameraBox);
        list_of_cameras_comboBox->setObjectName(QStringLiteral("list_of_cameras_comboBox"));

        verticalLayout_5->addWidget(list_of_cameras_comboBox);


        verticalLayout_3->addWidget(select_cameraBox);

        remote_settingBox = new QGroupBox(centralwidget);
        remote_settingBox->setObjectName(QStringLiteral("remote_settingBox"));
        sizePolicy.setHeightForWidth(remote_settingBox->sizePolicy().hasHeightForWidth());
        remote_settingBox->setSizePolicy(sizePolicy);
        remote_settingBox->setMaximumSize(QSize(16777215, 70));
        verticalLayout_2 = new QVBoxLayout(remote_settingBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        camera_ipEdit = new QLineEdit(remote_settingBox);
        camera_ipEdit->setObjectName(QStringLiteral("camera_ipEdit"));

        horizontalLayout_2->addWidget(camera_ipEdit);

        camera_portEdit = new QLineEdit(remote_settingBox);
        camera_portEdit->setObjectName(QStringLiteral("camera_portEdit"));

        horizontalLayout_2->addWidget(camera_portEdit);

        camera_passwordEdit = new QLineEdit(remote_settingBox);
        camera_passwordEdit->setObjectName(QStringLiteral("camera_passwordEdit"));
        camera_passwordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(camera_passwordEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        camera_connectButton = new QPushButton(remote_settingBox);
        camera_connectButton->setObjectName(QStringLiteral("camera_connectButton"));

        horizontalLayout_2->addWidget(camera_connectButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(remote_settingBox);

        opencv_view = new CQtOpenCVViewerGl(centralwidget);
        opencv_view->setObjectName(QStringLiteral("opencv_view"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(opencv_view->sizePolicy().hasHeightForWidth());
        opencv_view->setSizePolicy(sizePolicy1);
        opencv_view->setMinimumSize(QSize(780, 400));
        verticalLayout_6 = new QVBoxLayout(opencv_view);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        frame = new myFrame(opencv_view);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        frame_point_4 = new MovableFrame(frame);
        frame_point_4->setObjectName(QStringLiteral("frame_point_4"));
        frame_point_4->setGeometry(QRect(200, 230, 16, 16));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_point_4->sizePolicy().hasHeightForWidth());
        frame_point_4->setSizePolicy(sizePolicy2);
        frame_point_4->setStyleSheet(QStringLiteral("background-color:rgb(0, 0, 255);"));
        frame_point_4->setFrameShape(QFrame::Box);
        frame_point_4->setFrameShadow(QFrame::Plain);
        frame_point_2 = new MovableFrame(frame);
        frame_point_2->setObjectName(QStringLiteral("frame_point_2"));
        frame_point_2->setGeometry(QRect(370, 100, 16, 16));
        sizePolicy2.setHeightForWidth(frame_point_2->sizePolicy().hasHeightForWidth());
        frame_point_2->setSizePolicy(sizePolicy2);
        frame_point_2->setStyleSheet(QStringLiteral("background-color:rgb(0, 0, 255);"));
        frame_point_2->setFrameShape(QFrame::Box);
        frame_point_2->setFrameShadow(QFrame::Plain);
        frame_point_3 = new MovableFrame(frame);
        frame_point_3->setObjectName(QStringLiteral("frame_point_3"));
        frame_point_3->setGeometry(QRect(370, 240, 16, 16));
        sizePolicy2.setHeightForWidth(frame_point_3->sizePolicy().hasHeightForWidth());
        frame_point_3->setSizePolicy(sizePolicy2);
        frame_point_3->setStyleSheet(QStringLiteral("background-color:rgb(0, 0, 255);"));
        frame_point_3->setFrameShape(QFrame::Box);
        frame_point_3->setFrameShadow(QFrame::Plain);
        frame_point_1 = new MovableFrame(frame);
        frame_point_1->setObjectName(QStringLiteral("frame_point_1"));
        frame_point_1->setGeometry(QRect(200, 110, 16, 16));
        sizePolicy2.setHeightForWidth(frame_point_1->sizePolicy().hasHeightForWidth());
        frame_point_1->setSizePolicy(sizePolicy2);
        frame_point_1->setStyleSheet(QStringLiteral("background-color:rgb(0, 0, 255);"));
        frame_point_1->setFrameShape(QFrame::Box);
        frame_point_1->setFrameShadow(QFrame::Plain);

        verticalLayout_6->addWidget(frame);


        verticalLayout_3->addWidget(opencv_view);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        previewButton = new QPushButton(centralwidget);
        previewButton->setObjectName(QStringLiteral("previewButton"));
        previewButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(previewButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(nextButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        SelectCamera->setCentralWidget(centralwidget);
        frame->raise();
        statusbar = new QStatusBar(SelectCamera);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SelectCamera->setStatusBar(statusbar);

        retranslateUi(SelectCamera);

        QMetaObject::connectSlotsByName(SelectCamera);
    } // setupUi

    void retranslateUi(QMainWindow *SelectCamera)
    {
        SelectCamera->setWindowTitle(QApplication::translate("SelectCamera", "Add camera", 0));
        groupBox->setTitle(QApplication::translate("SelectCamera", "Add camera", 0));
        select_from_listButton->setText(QApplication::translate("SelectCamera", "Select camera from list", 0));
        remote_cameraButton->setText(QApplication::translate("SelectCamera", "Connects remote camera", 0));
        select_cameraBox->setTitle(QApplication::translate("SelectCamera", "Select camera", 0));
        remote_settingBox->setTitle(QApplication::translate("SelectCamera", "Remote settings", 0));
        camera_ipEdit->setPlaceholderText(QApplication::translate("SelectCamera", "IP", 0));
        camera_portEdit->setPlaceholderText(QApplication::translate("SelectCamera", "Port", 0));
        camera_passwordEdit->setPlaceholderText(QApplication::translate("SelectCamera", "Password", 0));
        camera_connectButton->setText(QApplication::translate("SelectCamera", "Connect", 0));
        previewButton->setText(QApplication::translate("SelectCamera", "Preview", 0));
        nextButton->setText(QApplication::translate("SelectCamera", "Next", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectCamera: public Ui_SelectCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCAMERA_H
