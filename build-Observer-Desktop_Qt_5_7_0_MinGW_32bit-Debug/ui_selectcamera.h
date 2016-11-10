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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <movableframe.h>
#include "myqframe.h"

QT_BEGIN_NAMESPACE

class Ui_SelectCamera
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *select_from_listButton;
    QRadioButton *remote_cameraButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *select_cameraBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *list_of_cameras_comboBox;
    QGroupBox *remote_settingBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *camera_ipEdit;
    QLineEdit *camera_portEdit;
    QLineEdit *camera_passwordEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *camera_connectButton;
    QWidget *widget;
    MyQFrame *select_area;
    MovableFrame *frame_point_1;
    MovableFrame *frame_point_4;
    MovableFrame *frame_point_2;
    MovableFrame *frame_point_3;
    QLabel *image_scene;
    QHBoxLayout *horizontalLayout;
    QPushButton *cutButton;
    QPushButton *originalButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nextButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SelectCamera)
    {
        if (SelectCamera->objectName().isEmpty())
            SelectCamera->setObjectName(QStringLiteral("SelectCamera"));
        SelectCamera->resize(1171, 606);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SelectCamera->sizePolicy().hasHeightForWidth());
        SelectCamera->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(SelectCamera);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(0, 70));
        groupBox->setMaximumSize(QSize(16777215, 70));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        select_from_listButton = new QRadioButton(groupBox);
        select_from_listButton->setObjectName(QStringLiteral("select_from_listButton"));
        select_from_listButton->setChecked(true);

        horizontalLayout_2->addWidget(select_from_listButton);

        remote_cameraButton = new QRadioButton(groupBox);
        remote_cameraButton->setObjectName(QStringLiteral("remote_cameraButton"));

        horizontalLayout_2->addWidget(remote_cameraButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(groupBox);

        select_cameraBox = new QGroupBox(centralwidget);
        select_cameraBox->setObjectName(QStringLiteral("select_cameraBox"));
        sizePolicy1.setHeightForWidth(select_cameraBox->sizePolicy().hasHeightForWidth());
        select_cameraBox->setSizePolicy(sizePolicy1);
        select_cameraBox->setMinimumSize(QSize(0, 70));
        select_cameraBox->setMaximumSize(QSize(16777215, 70));
        verticalLayout_2 = new QVBoxLayout(select_cameraBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        list_of_cameras_comboBox = new QComboBox(select_cameraBox);
        list_of_cameras_comboBox->setObjectName(QStringLiteral("list_of_cameras_comboBox"));
        list_of_cameras_comboBox->setMinimumSize(QSize(0, 25));

        verticalLayout_2->addWidget(list_of_cameras_comboBox);


        verticalLayout_4->addWidget(select_cameraBox);

        remote_settingBox = new QGroupBox(centralwidget);
        remote_settingBox->setObjectName(QStringLiteral("remote_settingBox"));
        sizePolicy1.setHeightForWidth(remote_settingBox->sizePolicy().hasHeightForWidth());
        remote_settingBox->setSizePolicy(sizePolicy1);
        remote_settingBox->setMinimumSize(QSize(0, 70));
        remote_settingBox->setMaximumSize(QSize(16777215, 70));
        verticalLayout_3 = new QVBoxLayout(remote_settingBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        camera_ipEdit = new QLineEdit(remote_settingBox);
        camera_ipEdit->setObjectName(QStringLiteral("camera_ipEdit"));
        camera_ipEdit->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(camera_ipEdit);

        camera_portEdit = new QLineEdit(remote_settingBox);
        camera_portEdit->setObjectName(QStringLiteral("camera_portEdit"));
        camera_portEdit->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(camera_portEdit);

        camera_passwordEdit = new QLineEdit(remote_settingBox);
        camera_passwordEdit->setObjectName(QStringLiteral("camera_passwordEdit"));
        camera_passwordEdit->setMinimumSize(QSize(0, 25));
        camera_passwordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(camera_passwordEdit);

        horizontalSpacer = new QSpacerItem(40, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        camera_connectButton = new QPushButton(remote_settingBox);
        camera_connectButton->setObjectName(QStringLiteral("camera_connectButton"));
        camera_connectButton->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(camera_connectButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(remote_settingBox);


        verticalLayout_5->addLayout(verticalLayout_4);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        select_area = new MyQFrame(widget);
        select_area->setObjectName(QStringLiteral("select_area"));
        select_area->setGeometry(QRect(20, 10, 500, 304));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(select_area->sizePolicy().hasHeightForWidth());
        select_area->setSizePolicy(sizePolicy3);
        select_area->setMinimumSize(QSize(0, 0));
        select_area->setFrameShape(QFrame::NoFrame);
        select_area->setFrameShadow(QFrame::Plain);
        select_area->setLineWidth(0);
        frame_point_1 = new MovableFrame(select_area);
        frame_point_1->setObjectName(QStringLiteral("frame_point_1"));
        frame_point_1->setGeometry(QRect(60, 30, 10, 10));
        sizePolicy.setHeightForWidth(frame_point_1->sizePolicy().hasHeightForWidth());
        frame_point_1->setSizePolicy(sizePolicy);
        frame_point_1->setCursor(QCursor(Qt::SizeFDiagCursor));
        frame_point_1->setFrameShape(QFrame::NoFrame);
        frame_point_1->setFrameShadow(QFrame::Raised);
        frame_point_1->setLineWidth(0);
        frame_point_4 = new MovableFrame(select_area);
        frame_point_4->setObjectName(QStringLiteral("frame_point_4"));
        frame_point_4->setGeometry(QRect(160, 30, 10, 10));
        sizePolicy.setHeightForWidth(frame_point_4->sizePolicy().hasHeightForWidth());
        frame_point_4->setSizePolicy(sizePolicy);
        frame_point_4->setCursor(QCursor(Qt::SizeBDiagCursor));
        frame_point_4->setFrameShape(QFrame::NoFrame);
        frame_point_4->setFrameShadow(QFrame::Raised);
        frame_point_4->setLineWidth(0);
        frame_point_2 = new MovableFrame(select_area);
        frame_point_2->setObjectName(QStringLiteral("frame_point_2"));
        frame_point_2->setGeometry(QRect(50, 120, 10, 10));
        sizePolicy.setHeightForWidth(frame_point_2->sizePolicy().hasHeightForWidth());
        frame_point_2->setSizePolicy(sizePolicy);
        frame_point_2->setCursor(QCursor(Qt::SizeBDiagCursor));
        frame_point_2->setFrameShape(QFrame::NoFrame);
        frame_point_2->setFrameShadow(QFrame::Raised);
        frame_point_2->setLineWidth(0);
        frame_point_3 = new MovableFrame(select_area);
        frame_point_3->setObjectName(QStringLiteral("frame_point_3"));
        frame_point_3->setGeometry(QRect(150, 120, 10, 10));
        sizePolicy.setHeightForWidth(frame_point_3->sizePolicy().hasHeightForWidth());
        frame_point_3->setSizePolicy(sizePolicy);
        frame_point_3->setCursor(QCursor(Qt::SizeFDiagCursor));
        frame_point_3->setFrameShape(QFrame::NoFrame);
        frame_point_3->setFrameShadow(QFrame::Raised);
        frame_point_3->setLineWidth(0);
        image_scene = new QLabel(widget);
        image_scene->setObjectName(QStringLiteral("image_scene"));
        image_scene->setGeometry(QRect(90, 280, 371, 81));
        image_scene->setFrameShape(QFrame::Box);
        image_scene->setLineWidth(1);
        image_scene->raise();
        select_area->raise();

        verticalLayout_5->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        cutButton = new QPushButton(centralwidget);
        cutButton->setObjectName(QStringLiteral("cutButton"));
        cutButton->setMinimumSize(QSize(0, 25));
        cutButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(cutButton);

        originalButton = new QPushButton(centralwidget);
        originalButton->setObjectName(QStringLiteral("originalButton"));
        sizePolicy.setHeightForWidth(originalButton->sizePolicy().hasHeightForWidth());
        originalButton->setSizePolicy(sizePolicy);
        originalButton->setMinimumSize(QSize(0, 25));
        originalButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(originalButton);

        horizontalSpacer_3 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setMinimumSize(QSize(0, 25));
        nextButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(nextButton);


        verticalLayout_5->addLayout(horizontalLayout);

        verticalLayout_5->setStretch(1, 5);

        verticalLayout_6->addLayout(verticalLayout_5);

        SelectCamera->setCentralWidget(centralwidget);
        select_area->raise();
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
        image_scene->setText(QString());
        cutButton->setText(QApplication::translate("SelectCamera", "Cut", 0));
        originalButton->setText(QApplication::translate("SelectCamera", "Original", 0));
        nextButton->setText(QApplication::translate("SelectCamera", "Next", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectCamera: public Ui_SelectCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCAMERA_H
