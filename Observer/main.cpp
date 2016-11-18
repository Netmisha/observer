#include "mainwindow.h"
#include "selectcamera.h"
#include "settingswindow.h"
#include <QApplication>
#include <videotag.h>
#include <iostream>
#include "settingsfile.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/
    SelectCamera s;
    s.show();
    return a.exec();
}
