#include "mainwindow.h"
#include "selectcamera.h"
#include "settingswindow.h"
#include <QApplication>
#include <videotag.h>
#include <iostream>
<<<<<<< HEAD
=======
#include "settingsfile.h"
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
