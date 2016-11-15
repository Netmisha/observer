#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "videotag.h"
#include "selectcamera.h"
#include "settingswindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void CloseSettings();
    void OpenTags();
    void CloseTags();
    void CloseSelectCamera();
    void OpenSelectCamera();
private:
    Ui::MainWindow *ui;
    SelectCamera * select_camera_;
    SettingsWindow * settings_;
    VideoTag * video_tag_;
};

#endif // MAINWINDOW_H
