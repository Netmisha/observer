/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *SettingButton;
    QListWidget *CameraList;
    QPushButton *SQ2;
    QPushButton *SQ3;
    QLabel *StreamArea;
    QPushButton *SQ;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(594, 493);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SettingButton = new QPushButton(centralWidget);
        SettingButton->setObjectName(QStringLiteral("SettingButton"));
        SettingButton->setGeometry(QRect(470, 420, 101, 21));
        sizePolicy.setHeightForWidth(SettingButton->sizePolicy().hasHeightForWidth());
        SettingButton->setSizePolicy(sizePolicy);
        CameraList = new QListWidget(centralWidget);
        CameraList->setObjectName(QStringLiteral("CameraList"));
        CameraList->setGeometry(QRect(10, 50, 171, 341));
        SQ2 = new QPushButton(centralWidget);
        SQ2->setObjectName(QStringLiteral("SQ2"));
        SQ2->setGeometry(QRect(340, 0, 61, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/CROSS/Square2.png"), QSize(), QIcon::Normal, QIcon::Off);
        SQ2->setIcon(icon);
        SQ2->setIconSize(QSize(61, 51));
        SQ3 = new QPushButton(centralWidget);
        SQ3->setObjectName(QStringLiteral("SQ3"));
        SQ3->setGeometry(QRect(490, 0, 61, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/CROSS/Square4.png"), QSize(), QIcon::Normal, QIcon::Off);
        SQ3->setIcon(icon1);
        SQ3->setIconSize(QSize(61, 51));
        SQ3->setFlat(false);
        StreamArea = new QLabel(centralWidget);
        StreamArea->setObjectName(QStringLiteral("StreamArea"));
        StreamArea->setGeometry(QRect(200, 70, 361, 321));
        SQ = new QPushButton(centralWidget);
        SQ->setObjectName(QStringLiteral("SQ"));
        SQ->setGeometry(QRect(181, 1, 61, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/CROSS/Square.png"), QSize(), QIcon::Normal, QIcon::Off);
        SQ->setIcon(icon2);
        SQ->setIconSize(QSize(61, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 594, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        SQ2->setDefault(false);
        SQ3->setDefault(false);
        SQ->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        SettingButton->setText(QApplication::translate("MainWindow", "Settings", 0));
        SQ2->setText(QString());
        SQ3->setText(QString());
        StreamArea->setText(QString());
        SQ->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
