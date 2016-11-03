#ifndef CQTOPENCVVIEWERGL_H
#define CQTOPENCVVIEWERGL_H
#include "opencv2/opencv.hpp"
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>
using namespace cv;

class CQtOpenCVViewerGl : public QOpenGLWidget, protected QOpenGLFunctions_2_0
{
    Q_OBJECT
public:
    CQtOpenCVViewerGl(QWidget *);
signals:
   void imageSizeChanged( int outW, int outH ); /// Used to resize the image outside the widget
public slots:
   bool showImage( cv::Mat image ); /// Used to set the image to be viewed
protected:
   void initializeGL(); /// OpenGL initialization
   void paintGL(); /// OpenGL Rendering
   void resizeGL(int width, int height); /// Widget Resize Event

   void updateScene(); /// Forces a scene update
   void renderImage(); /// Render image on openGL frame
private:
    bool mSceneChanged; /// Indicates when OpenGL view is to be redrawn
    QImage mRenderQtImg; /// Qt image to be rendered
    cv::Mat mOrigImage; /// original OpenCV image to be shown

    QColor mBgColor; /// Background color

    int mOutH; /// Resized Image height
    int mOutW; /// Resized Image width
    float mImgratio; /// height/width ratio

    int mPosX; /// Top left X position to render image in the center of widget
    int mPosY; /// Top left Y position to render image in the center of widget

};

#endif // CQTOPENCVVIEWERGL_H
