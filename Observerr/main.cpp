#include "mainwindow.h"
#include "selectcamera.h"
#include <QApplication>
#include <videotag.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/
    SelectCamera select_camera;
    select_camera.show();
    //VideoTag V;
    //V.show();
    return a.exec();
}
