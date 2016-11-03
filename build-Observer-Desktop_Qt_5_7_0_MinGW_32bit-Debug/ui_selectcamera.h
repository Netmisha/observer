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
#include <QtWidgets/QFrame>
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
    QFrame *videoFrame;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *previewButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nextButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SelectCamera)
    {
        if (SelectCamera->objectName().isEmpty())
            SelectCamera->setObjectName(QStringLiteral("SelectCamera"));
        SelectCamera->resize(800, 600);
        centralwidget = new QWidget(SelectCamera);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 50));
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
        select_cameraBox->setMinimumSize(QSize(0, 70));
        select_cameraBox->setMaximumSize(QSize(16777215, 70));
        verticalLayout_5 = new QVBoxLayout(select_cameraBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        list_of_cameras_comboBox = new QComboBox(select_cameraBox);
        list_of_cameras_comboBox->setObjectName(QStringLiteral("list_of_cameras_comboBox"));

        verticalLayout_5->addWidget(list_of_cameras_comboBox);


        verticalLayout_3->addWidget(select_cameraBox);

        remote_settingBox = new QGroupBox(centralwidget);
        remote_settingBox->setObjectName(QStringLiteral("remote_settingBox"));
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

        videoFrame = new QFrame(centralwidget);
        videoFrame->setObjectName(QStringLiteral("videoFrame"));
        videoFrame->setFrameShape(QFrame::Box);
        videoFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(videoFrame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        previewButton = new QPushButton(centralwidget);
        previewButton->setObjectName(QStringLiteral("previewButton"));

        horizontalLayout_3->addWidget(previewButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout_3->addWidget(nextButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(3, 5);

        verticalLayout_4->addLayout(verticalLayout_3);

        SelectCamera->setCentralWidget(centralwidget);
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
