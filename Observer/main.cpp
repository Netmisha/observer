#include "mainwindow.h"
#include "selectcamera.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    SelectCamera select_camera;
    select_camera.show();
    return a.exec();
}
