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
    SelectCamera select_camera;
    select_camera.show();
    /*VideoTag V;
    V.show();*/
=======
    //SelectCamera select_camera;
   // select_camera.show();
    VideoTag V;
    V.show();
>>>>>>> 308241a7847dfd01a02293d314c8ac01f84adcd7
    return a.exec();
}
