#include "mainwindow.h"
#include "selectcamera.h"
#include <QApplication>
#include <videotag.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/
<<<<<<< HEAD
    //SelectCamera select_camera;
   // select_camera.show();
    VideoTag V;
    V.show();
=======
    SelectCamera select_camera;
    select_camera.show();
    /*VideoTag V;
    V.show();*/
>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
    return a.exec();
}
