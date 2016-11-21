#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Mat src = imread("threshold.png", IMREAD_GRAYSCALE);
    Mat dst;
    return a.exec();
}
