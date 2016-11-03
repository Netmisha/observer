<<<<<<< HEAD
#ifndef VIDEOTAG_H
#define VIDEOTAG_H
#include "opencv2/opencv.hpp"
#include <QLabel>
#include <QWidget>
namespace Ui {
class VideoTag;
}

class VideoTag : public QWidget
{
    Q_OBJECT

public:
    explicit VideoTag(QWidget *parent = 0);
    ~VideoTag();

private slots:
    void on_Start_clicked();

    void on_Stop_clicked();

    void on_Pause_clicked();

private:
    volatile bool start=false;
    void ThreadStream();
    Ui::VideoTag *ui;
    volatile bool stream = false;
};

#endif // VIDEOTAG_H
=======
#ifndef VIDEOTAG_H
#define VIDEOTAG_H
#include "opencv2/opencv.hpp"
#include <QLabel>
#include <QWidget>
namespace Ui {
class VideoTag;
}

class VideoTag : public QWidget
{
    Q_OBJECT

public:
    explicit VideoTag(QWidget *parent = 0);
    ~VideoTag();

private slots:
    void on_Start_clicked();

    void on_Stop_clicked();

    void on_Pause_clicked();

private:
    volatile bool start=false;
    void ThreadStream();
    Ui::VideoTag *ui;
    volatile bool stream = false;
};

#endif // VIDEOTAG_H
>>>>>>> 18246caf5fdf0f3c5649c39f195306479651e665
