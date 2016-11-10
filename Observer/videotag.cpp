#include "videotag.h"
#include "ui_videotag.h"

using namespace cv;
VideoTag::VideoTag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoTag)
{
       ui->setupUi(this);
       //ui->TagList->addItem("Test1");
       //ui->TagList->addItem("Test2");
       connect(ui->TagList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_dbl_clicked(QListWidgetItem*)));
       connect(ui->TagList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked()));
       connect(ui->TagList->itemDelegate(),&QAbstractItemDelegate::commitData,this,VideoTag::OnDataRename);
       ui->TagList->setContextMenuPolicy(Qt::CustomContextMenu);
       connect(ui->TagList,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(showContextMenu(const QPoint&)));
}

VideoTag::~VideoTag()
{
    delete ui;
}
void VideoTag::itemClicked(){

    //ui->TagList->currentRow();
    CropArea = TagContainer.at(ui->TagList->currentRow())->TagPosition;

}
void VideoTag::showContextMenu(const QPoint &pos){
    QPoint item = ui->TagList->mapToGlobal(pos);
    TagListItem = item;
    QMenu submenu;
    submenu.addAction("Delete");
    QAction* rightclick = submenu.exec(item);
    if(rightclick && rightclick->text().contains("Delete")){
        tag_delete(pos);
    }
}

void VideoTag::OnDataRename(QWidget *EditLine){
    QString str = reinterpret_cast<QLineEdit*>(EditLine)->text();
    //int nRow = ui->TagList->currentRow();
    if(str == temp){

        qDebug()<<"Text not change";
    }else{

    qDebug()<<"Text has ben changed";
    }

}
void VideoTag::tag_delete(const QPoint& pos){
 ui->TagList->takeItem(ui->TagList->indexAt(pos).row());

}

void VideoTag::on_dbl_clicked(QListWidgetItem* it){
it->setFlags(it->flags() | Qt::ItemIsEditable);
ui->TagList->editItem(it);
temp = it->text();

}

void VideoTag::on_Start_clicked()
{
   if(VideoTag::start==true){
        return;
    }
    VideoTag::start = true;
    stream=true;
    std::thread thr(&VideoTag::ThreadStream, this);
    thr.detach();
}
void VideoTag::on_AddTag_clicked()
{
    if(firstTag == false){
      VPos++;
      qDebug()<<"Second tag";
      NewTag = new TagClass;
      NewTag->TagPosition = CropArea;
      NewTag->tag_id = VPos;
      NewTag->tag_name = "Temp" + QString::number(NewTag->tag_id);
      TagContainer.push_back(NewTag);
      NewTag = nullptr;
      ui->TagList->addItem(TagContainer.at(VPos)->tag_name);
       //ui->TagList->count();
    }
    else{
    std::thread thr (&VideoTag::TagStreamThread, this);
    thr.detach();
    }
}
void VideoTag::TagStreamThread(){
    if(firstTag == true){

        VPos++;
        NewTag = new TagClass;
        NewTag->TagPosition = CropArea;
        NewTag->tag_id = VPos;  //
        NewTag->tag_name = "FirstTag";   // setName for the tag
        TagContainer.push_back(NewTag);
        NewTag = nullptr;
        ui->TagList->addItem(TagContainer.at(VPos)->tag_name);
        firstTag = false;
    }
 while(1){
    mutex.lock();
    shot_ = shot_.copy(CropArea);
    shot_ = shot_.scaled(ui->TagVideo->width(),ui->TagVideo->height(),Qt::KeepAspectRatio);
    ui->TagVideo->setPixmap(QPixmap::fromImage(shot_));
    mutex.unlock();
 }

}
void VideoTag::ThreadStream(){ // Stream to MainStreamWindow
    cap = 0;
    while(1)
    {
      mutex.lock();
      cap >> frame;
      cvtColor(frame,frame,COLOR_BGR2RGB);
      QImage qimgOriginal((uchar*)frame.data,frame.cols,frame.rows, frame.step,QImage::Format_RGB888);
      shot_ = qimgOriginal;
      shot_ = shot_.scaled(ui->TagVideo->width(),ui->TagVideo->height(),Qt::KeepAspectRatio);
      qimgOriginal =  qimgOriginal.scaled(ui->MainVideo->width(),ui->MainVideo->height(),Qt::KeepAspectRatio);
      ui->MainVideo->setPixmap(QPixmap::fromImage(qimgOriginal));
      mutex.unlock();
    }
}

void VideoTag::mousePressEvent(QMouseEvent *event){
 if(lock_rect == true){
     rubber->close();
 }
origin = ui->MainVideo->mapFromGlobal(this->mapToGlobal(event->pos()));
rubber = new QRubberBand(QRubberBand::Rectangle,ui->MainVideo);
rubber->setGeometry(QRect(origin,ui->MainVideo->mapFromGlobal(this->mapToGlobal(event->pos()))));//
rubber->show();

}
void VideoTag::mouseMoveEvent(QMouseEvent *event){
rubber->setGeometry(QRect(origin,ui->MainVideo->mapFromGlobal(this->mapToGlobal(event->pos()))));//
}

void VideoTag::mouseReleaseEvent(QMouseEvent *event){
lock_rect = true;
CropArea = QRect(origin,rubber->size());
qDebug()<<CropArea;

}
void VideoTag::on_Stop_clicked()
{



}

void VideoTag::on_Pause_clicked()
{

}

void VideoTag::paintEvent(QPaintEvent *event){
    QPainter p,p1;
    p.begin(this);
    p.setPen(Qt::PenStyle::DashLine);
    p.drawRect(ui->MainVideo->x()-2,ui->MainVideo->y()+3,ui->MainVideo->width()+3,ui->MainVideo->height()-8);
    p.end();


}


