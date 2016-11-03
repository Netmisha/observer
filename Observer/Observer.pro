#-------------------------------------------------
#
# Project created by QtCreator 2016-11-03T11:46:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Observer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    select_camera.cpp \
    selectcamera.cpp

HEADERS  += mainwindow.h \
    select_camera.h \
    selectcamera.h

FORMS    += mainwindow.ui \
    select_camera.ui \
    selectcamera.ui

INCLUDEPATH += C:\\opencv-mingw\\install\\include

LIBS += -LC:\\opencv-mingw\\install\\x86\\mingw\\bin \
    libopencv_core2413d \
    libopencv_highgui2413d \
    libopencv_imgproc2413d \
    libopencv_features2d2413d \
    libopencv_calib3d2413d \

LIBS += -LC:\\opencv-mingw\\install\\x86\\mingw\\lib \
    libopencv_core2413d \
    libopencv_highgui2413d \
    libopencv_imgproc2413d \
    libopencv_features2d2413d \
    libopencv_calib3d2413d \
