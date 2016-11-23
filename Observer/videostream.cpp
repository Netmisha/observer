#include "videostream.h"

VideoStream::VideoStream():QObject(nullptr) {
    connect(&timer_, SIGNAL(timeout()), this, SLOT(OnTimer()));
}
VideoStream::VideoStream(QString &file_name):QObject(nullptr) {
    setFileName(file_name);
    connect(&timer_, SIGNAL(timeout()), this, SLOT(OnTimer()));
}
VideoStream::VideoStream(settings_file::SettingsFile &settings) {
    setSettings(settings);
    connect(&timer_, SIGNAL(timeout()), this, SLOT(OnTimer()));
}
VideoStream::~VideoStream() {
    StopStream();
}
void VideoStream::setCropPoint(QVector<QPoint> & points)
{
    settings_.setCropPoints(points);
    if(!points.isEmpty()) {
        CalculateHomography();
    }
}
void VideoStream::setCropPoint(QVector<QPoint> & points, QSize size) {
    double kof_x=(double)(img_size_.width())/size.width();
    double kof_y=(double)(img_size_.height())/size.height();
    for(auto & it:points) {
        it.setX(it.x()*kof_x);
        it.setY(it.y()*kof_y);
    }
    settings_.setCropPoints(points);
    if(!points.isEmpty()) {
        CalculateHomography();
    }
}
void VideoStream::getCropPoint(QVector<QPoint> & points, QSize & size) {
    double kof_x=(double)(img_size_.width())/size.width();
    double kof_y=(double)(img_size_.height())/size.height();
    points.clear();
    for(auto & it:settings_.getCropPoints()) {
        points.push_back(QPoint(it.x()/kof_x,it.y()/kof_y));
    }
}
settings_file::SettingsFile &VideoStream::getSettings() {
    return settings_;
}
void VideoStream::setFPS(int fps) {
    FPS_=fps;
}
void VideoStream::setFileName(QString &file_name) {
    file_name_=file_name;
    settings_.setFileName(file_name);
    settings_.ReadSettings();
}
void VideoStream::setSettings(settings_file::SettingsFile &settings) {
    settings_=settings;
}
void VideoStream::addNewCamera(QString &name, int id) {
    settings_.addNewCamera(name, id);
}
void VideoStream::addNewCamera(QString &name, QString &path) {
    settings_.addNewCamera(name, path);
}
void VideoStream::StartStream() {
    if(settings_.getCameraType()==settings_file::kLocalType) {
        cap_.open(settings_.getCameraId());
        if(!cap_.isOpened()) {
            return;
        }
    }
    else {
        cap_.open(settings_.getCameraPath().toStdString());
        if(!cap_.isOpened()) {
            return;
        }
    }
    cap_>>img_scr_;
    img_size_.setWidth(img_scr_.cols);
    img_size_.setHeight(img_scr_.rows);
    settings_.setCameraSize(img_size_);
    if(!settings_.getCropPoints().isEmpty()) {
        CalculateHomography();
    }
    timer_.start(FPS_);
}
Mat VideoStream::getImageCroppedCu(Mat img,QString tagName){
    if(settings_.getTagsList().isEmpty()){
        //qDebug()<<"Tag List is empty.EXIT.";
        return img;
    }
    int tagPos=-1;
    for(int i=0;i<settings_.getTagsList().size();i++){
        if(settings_.getTagsList().at(i).name_ == tagName){tagPos = i;}
    }
    if(tagPos == -1){return img;}
    cv::Rect ROI(settings_.getTagsList().at(tagPos).rect_.x(),settings_.getTagsList().at(tagPos).rect_.y(),settings_.getTagsList().at(tagPos).rect_.width(),settings_.getTagsList().at(tagPos).rect_.height());
    currentimg = img(ROI);
    if (PREV){Previmg = currentimg; PREV = false;}
    else{PREV = true;}
    return currentimg;
}
Mat VideoStream::getImageCroppedPr(Mat img){
    if(settings_.getTagsList().isEmpty()){
        //qDebug()<<"Tag List is empty.EXIT.";
        return img;
    }
    return Previmg;
}
void VideoStream::OnTimer(){
    cap_ >> img_scr_;
    //img_scr_ =  getImageCroppedCu(img_scr_,"TAG");
    if(settings_.getCropPoints().isEmpty()){
        emit SendImage(img_scr_);
    }
    else {
        emit SendImage(ProcessingImage(img_scr_));
    }
}
void VideoStream::StopStream() {
    timer_.stop();
    cap_.release();
}
void VideoStream::Clear()
{
    settings_=settings_file::SettingsFile();
}
Point2f VideoStream::CrossingLine(std::vector<Point2f> &pts_src) {
    Point2f cross;
    if(pts_src[0].x>=pts_src[1].x) {
        cross=pts_src[0];
        pts_src[0]=pts_src[1];
        pts_src[1]=cross;
    }
    if(pts_src[2].x>=pts_src[3].x) {
        cross=pts_src[2];
        pts_src[2]=pts_src[3];
        pts_src[3]=cross;
    }
    double k1=(pts_src[1].y-pts_src[0].y)/(pts_src[1].x-pts_src[0].x);
    double k2=(pts_src[3].y-pts_src[2].y)/(pts_src[3].x-pts_src[2].x);
    double b1=pts_src[0].y-k1*pts_src[0].x;
    double b2=pts_src[2].y-k2*pts_src[2].x;
    cross.x=(b2-b1)/(k1-k2);
    cross.y=b1+k1*cross.x;
    return cross;
}
Point2f VideoStream::GravityCenter(std::vector<Point2f> &pts_src) {
    std::vector<Point2f> centr(pts_src.size());
    Point2f cent;
    auto add_point=[](double x, double y){ Point2f res; res.x=x; res.y=y; return res;};
    auto dis=[](Point2f p1, Point2f p2){return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));};
    centr[2]=add_point((pts_src[0].x+pts_src[1].x)/2,(pts_src[0].y+pts_src[1].y)/2);
    centr[1]=add_point((pts_src[3].x+pts_src[1].x)/2,(pts_src[3].y+pts_src[1].y)/2);
    centr[0]=pts_src[0];
    centr[3]=pts_src[3];
    Point2f c1, c2;
    c1=CrossingLine(centr);
    centr[3]=add_point((pts_src[0].x+pts_src[1].x)/2,(pts_src[0].y+pts_src[1].y)/2);
    centr[1]=add_point((pts_src[2].x+pts_src[1].x)/2,(pts_src[2].y+pts_src[1].y)/2);
    centr[0]=pts_src[0];
    centr[2]=pts_src[2];
    c2=CrossingLine(centr);
    double p1=(dis(pts_src[0], pts_src[1])+dis(pts_src[3], pts_src[1])+dis(pts_src[0], pts_src[3]))/2;
    double s1=sqrt(p1*(p1-dis(pts_src[0], pts_src[1]))*(p1-dis(pts_src[3], pts_src[1]))*(p1-dis(pts_src[0], pts_src[3])));
    double p2=(dis(pts_src[0], pts_src[1])+dis(pts_src[2], pts_src[1])+dis(pts_src[0], pts_src[2]))/2;
    double s2=sqrt(p2*(p2-dis(pts_src[0], pts_src[1]))*(p2-dis(pts_src[3], pts_src[1]))*(p2-dis(pts_src[0], pts_src[3])));
    cent.x=(c1.x*s1+c2.x*s2)/(s1+s2);
    cent.y=(c1.y*s1+c2.y*s2)/(s1+s2);
    return cent;
}
void VideoStream::CalculateHomography() {
    std::vector<Point2f> pts_src;
    std:: vector<Point2f> pts_dst;
    Point2f cent, cross;
    auto points=settings_.getCropPoints();
    pts_src.push_back(Point2f(points[0].x(),points[0].y()));
    pts_src.push_back(Point2f(points[2].x(),points[2].y()));
    pts_src.push_back(Point2f(points[1].x(),points[1].y()));
    pts_src.push_back(Point2f(points[3].x(),points[3].y()));
    cross=CrossingLine(pts_src);
    auto dis=[](Point2f p1, Point2f p2){return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));};
    cent=GravityCenter(pts_src);
    pts_src.clear();
    pts_src.push_back(Point2f(points[0].x(),points[0].y()));
    pts_src.push_back(Point2f(points[1].x(),points[1].y()));
    pts_src.push_back(Point2f(points[2].x(),points[2].y()));
    pts_src.push_back(Point2f(points[3].x(),points[3].y()));
    double width=(dis(pts_src[0],pts_src[1])+dis(pts_src[2],pts_src[3]))/2+2*fabs(cross.x-cent.x);
    double height=(dis(pts_src[0],pts_src[3])+dis(pts_src[1],pts_src[2]))/2+2*fabs(cross.y-cent.y);
    pts_dst.push_back(Point2f(0,0));
    pts_dst.push_back(Point2f(width - 1, 0));
    pts_dst.push_back(Point2f(width - 1, height -1));
    pts_dst.push_back(Point2f(0, height - 1 ));
    img_out_size_=Size(width, height);
    homography_ = findHomography(pts_src, pts_dst);
}
Mat VideoStream::ProcessingImage(Mat img_src) {
    Mat img_out;
    warpPerspective(img_src, img_out, homography_, img_out_size_);
    return img_out;
}
