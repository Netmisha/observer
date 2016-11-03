#-------------------------------------------------
#
# Project created by QtCreator 2016-11-03T11:46:08
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Observer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    selectcamera.cpp

HEADERS  += mainwindow.h \
    selectcamera.h

FORMS    += mainwindow.ui \
    selectcamera.ui

INCLUDEPATH += C:\\OpenCV\\opencv-mingw\\install\\include

LIBS += -LC:\\OpenCV\\opencv-mingw\\install\\x86\\mingw\\bin \
    libopencv_core2413d \
    libopencv_highgui2413d \
    libopencv_imgproc2413d \
    libopencv_features2d2413d \
    libopencv_calib3d2413d \

LIBS += -LC:\\OpenCV\\opencv-mingw\\install\\x86\\mingw\\lib \
    libopencv_core2413d \
    libopencv_highgui2413d \
    libopencv_imgproc2413d \
    libopencv_features2d2413d \
    libopencv_calib3d2413d \
