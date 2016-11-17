/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *setting_fileEdit;
    QToolButton *open_dialogButton;
    QTextEdit *setting_textEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *save_fileButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *both_radioButton;
    QRadioButton *on_change_radioButton;
    QRadioButton *timer_radioButton;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *time_spinBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *save_timeButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QListWidget *tags_listWidget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *open_tags_window;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *close_settings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(882, 565);
        SettingsWindow->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(8);
        SettingsWindow->setFont(font);
        centralwidget = new QWidget(SettingsWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, -1, -1, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_12 = new QVBoxLayout(groupBox_2);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        setting_fileEdit = new QLineEdit(groupBox_2);
        setting_fileEdit->setObjectName(QStringLiteral("setting_fileEdit"));
        setting_fileEdit->setMinimumSize(QSize(0, 25));
        setting_fileEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(setting_fileEdit);

        open_dialogButton = new QToolButton(groupBox_2);
        open_dialogButton->setObjectName(QStringLiteral("open_dialogButton"));
        open_dialogButton->setMinimumSize(QSize(0, 25));
        open_dialogButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(open_dialogButton);


        verticalLayout_11->addLayout(horizontalLayout_7);

        setting_textEdit = new QTextEdit(groupBox_2);
        setting_textEdit->setObjectName(QStringLiteral("setting_textEdit"));

        verticalLayout_11->addWidget(setting_textEdit);


        verticalLayout_12->addLayout(verticalLayout_11);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        save_fileButton = new QPushButton(groupBox_2);
        save_fileButton->setObjectName(QStringLiteral("save_fileButton"));
        save_fileButton->setMinimumSize(QSize(80, 25));
        save_fileButton->setMaximumSize(QSize(80, 25));

        horizontalLayout_5->addWidget(save_fileButton);


        verticalLayout_12->addLayout(horizontalLayout_5);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout_9 = new QVBoxLayout(groupBox);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMinimumSize(QSize(170, 0));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        both_radioButton = new QRadioButton(groupBox_3);
        both_radioButton->setObjectName(QStringLiteral("both_radioButton"));
        both_radioButton->setMinimumSize(QSize(0, 25));
        both_radioButton->setMaximumSize(QSize(16777215, 25));

        verticalLayout_5->addWidget(both_radioButton);

        on_change_radioButton = new QRadioButton(groupBox_3);
        on_change_radioButton->setObjectName(QStringLiteral("on_change_radioButton"));
        on_change_radioButton->setMinimumSize(QSize(0, 25));
        on_change_radioButton->setMaximumSize(QSize(16777215, 25));

        verticalLayout_5->addWidget(on_change_radioButton);

        timer_radioButton = new QRadioButton(groupBox_3);
        timer_radioButton->setObjectName(QStringLiteral("timer_radioButton"));
        timer_radioButton->setMinimumSize(QSize(0, 25));
        timer_radioButton->setMaximumSize(QSize(16777215, 25));

        verticalLayout_5->addWidget(timer_radioButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_8->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        sizePolicy1.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy1);
        groupBox_5->setMaximumSize(QSize(170, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        time_spinBox = new QDoubleSpinBox(groupBox_5);
        time_spinBox->setObjectName(QStringLiteral("time_spinBox"));
        time_spinBox->setMinimumSize(QSize(0, 25));
        time_spinBox->setMaximumSize(QSize(16777215, 25));
        time_spinBox->setFont(font);
        time_spinBox->setDecimals(3);
        time_spinBox->setMinimum(0.001);
        time_spinBox->setMaximum(100000);
        time_spinBox->setSingleStep(0.1);
        time_spinBox->setValue(1);

        horizontalLayout->addWidget(time_spinBox);

        label = new QLabel(groupBox_5);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 25));
        label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        save_timeButton = new QPushButton(groupBox_5);
        save_timeButton->setObjectName(QStringLiteral("save_timeButton"));
        save_timeButton->setMinimumSize(QSize(50, 25));
        save_timeButton->setMaximumSize(QSize(50, 25));

        horizontalLayout_3->addWidget(save_timeButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_8->addWidget(groupBox_5);


        horizontalLayout_4->addLayout(verticalLayout_8);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setMaximumSize(QSize(150, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tags_listWidget = new QListWidget(groupBox_4);
        tags_listWidget->setObjectName(QStringLiteral("tags_listWidget"));
        tags_listWidget->setFrameShape(QFrame::NoFrame);
        tags_listWidget->setLineWidth(0);
        tags_listWidget->setTabKeyNavigation(false);
        tags_listWidget->setProperty("showDropIndicator", QVariant(true));
        tags_listWidget->setDragEnabled(false);
        tags_listWidget->setDragDropOverwriteMode(false);
        tags_listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        tags_listWidget->setAlternatingRowColors(false);
        tags_listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tags_listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        tags_listWidget->setTextElideMode(Qt::ElideLeft);
        tags_listWidget->setFlow(QListView::TopToBottom);
        tags_listWidget->setResizeMode(QListView::Fixed);
        tags_listWidget->setLayoutMode(QListView::SinglePass);
        tags_listWidget->setViewMode(QListView::IconMode);
        tags_listWidget->setUniformItemSizes(false);
        tags_listWidget->setWordWrap(false);
        tags_listWidget->setSelectionRectVisible(true);

        verticalLayout->addWidget(tags_listWidget);


        horizontalLayout_4->addWidget(groupBox_4);


        verticalLayout_9->addLayout(horizontalLayout_4);


        horizontalLayout_2->addWidget(groupBox);

        horizontalLayout_2->setStretch(0, 6);

        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        open_tags_window = new QPushButton(centralwidget);
        open_tags_window->setObjectName(QStringLiteral("open_tags_window"));
        open_tags_window->setMinimumSize(QSize(80, 25));
        open_tags_window->setMaximumSize(QSize(80, 25));

        horizontalLayout_6->addWidget(open_tags_window);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        close_settings = new QPushButton(centralwidget);
        close_settings->setObjectName(QStringLiteral("close_settings"));
        close_settings->setMinimumSize(QSize(80, 25));
        close_settings->setMaximumSize(QSize(80, 25));

        horizontalLayout_6->addWidget(close_settings);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_7->addLayout(verticalLayout_4);

        SettingsWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SettingsWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SettingsWindow->setStatusBar(statusbar);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Settings", 0));
        groupBox_2->setTitle(QApplication::translate("SettingsWindow", "Setting file", 0));
        open_dialogButton->setText(QApplication::translate("SettingsWindow", "...", 0));
        save_fileButton->setText(QApplication::translate("SettingsWindow", "Save", 0));
        groupBox->setTitle(QApplication::translate("SettingsWindow", "Event settings", 0));
        groupBox_3->setTitle(QApplication::translate("SettingsWindow", "Event", 0));
        both_radioButton->setText(QApplication::translate("SettingsWindow", "Both", 0));
        on_change_radioButton->setText(QApplication::translate("SettingsWindow", "On change", 0));
        timer_radioButton->setText(QApplication::translate("SettingsWindow", "Timer", 0));
        groupBox_5->setTitle(QApplication::translate("SettingsWindow", "Timer properties", 0));
        label->setText(QApplication::translate("SettingsWindow", "second(s)", 0));
        save_timeButton->setText(QApplication::translate("SettingsWindow", "OK", 0));
        groupBox_4->setTitle(QApplication::translate("SettingsWindow", "Tags for monitoring", 0));
        open_tags_window->setText(QApplication::translate("SettingsWindow", "Tags", 0));
        close_settings->setText(QApplication::translate("SettingsWindow", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
