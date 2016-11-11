#include "videotag.h"
#include "ui_videotag.h"

using namespace cv;
VideoTag::VideoTag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoTag)
{
       ui->setupUi(this);
<<<<<<< HEAD
       this->setFixedSize(648,437);
       connect(ui->TagList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_dbl_clicked(QListWidgetItem*)));
       connect(ui->TagList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked()));
       connect(ui->TagList->itemDelegate(),&QAbstractItemDelegate::commitData,this,VideoTag::OnDataRename);
       ui->TagList->setContextMenuPolicy(Qt::CustomContextMenu);
       connect(ui->TagList,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(showContextMenu(const QPoint&)));
       ui->TagVideo->setText("Offline"); ui->TagVideo->setAlignment(Qt::AlignCenter); setF = ui->TagVideo->font();setF.setItalic(true);setF.setPointSize(10); ui->TagVideo->setFont(setF);
       ui->MainVideo->setText("Offline"); ui->MainVideo->setAlignment(Qt::AlignCenter); ui->MainVideo->setFont(setF);
=======
       ui->TagList->addItem("Test1");
       ui->TagList->addItem("Test2");
        connect(ui->TagList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_dbl_clicked(QListWidgetItem*)));
        connect(ui->TagList->itemDelegate(),&QAbstractItemDelegate::commitData,this,VideoTag::OnDataRename);
        ui->TagList->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(ui->TagList,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(showContextMenu(const QPoint&)));
>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
}

VideoTag::~VideoTag()
{
    delete ui;
}
<<<<<<< HEAD
void VideoTag::itemClicked(){
    CropArea = TagContainer.at(ui->TagList->currentRow())->TagPosition;
}
void VideoTag::showContextMenu(const QPoint &pos){
    QPoint item = ui->TagList->mapToGlobal(pos);
    TagListItem = item;
=======

void VideoTag::showContextMenu(const QPoint &pos){
    QPoint item = ui->TagList->mapToGlobal(pos);
>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
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
<<<<<<< HEAD
    if(str == temp){
    }else{
    TagContainer[ui->TagList->currentRow()]->tag_name = str;
    }

}
void VideoTag::tag_delete(const QPoint& pos){
int nRow = ui->TagList->indexAt(pos).row();
int QE = ui->TagList->count(); // starts from 1 not from 0
QE--;
for (int i=0;i<=QE;i++){
    qDebug()<<TagContainer.at(i)->tag_name;
}
for(int i=nRow;i<=QE;i++){
TagContainer.at(i)->tag_id--;
}
TagContainer.erase(TagContainer.begin()+nRow);
VPos--;
for (int i=0;i<QE;i++){
    qDebug()<<TagContainer.at(i)->tag_name<<" "<<TagContainer.at(i)->tag_id--;
}
=======
    qDebug()<<"changed";

}
void VideoTag::tag_delete(const QPoint& pos){
>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
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
<<<<<<< HEAD
void VideoTag::on_AddTag_clicked()
{
    if(firstTag == false){
      GetTagName = new QInputDialog;
      GetTagName->setOption(QInputDialog::NoButtons);
      while(1){
      ok = false;
      TagName = GetTagName->getText(NULL,"TagNameWindow","Set tag name:",QLineEdit::Normal,NULL,&ok);
      if ((TagName.isEmpty() || TagName.isNull()) && ok){
          QMessageBox::information(this,tr("Error"),tr("Set tag name"));
          TagName = TagName.null;
          continue;
      }
      else if(ok && (!TagName.isEmpty() || !TagName.isNull())){break;}
      return;
      }
      delete GetTagName;
      GetTagName = nullptr;
      VPos++;
      NewTag = new TagClass;
      NewTag->TagPosition = CropArea;
      NewTag->tag_id = VPos;
      NewTag->tag_name = TagName;
      TagContainer.push_back(NewTag);
      NewTag = nullptr;
      ui->TagList->addItem(TagContainer.at(VPos)->tag_name);
    }
    else if(firstTag == true){
        NewTag = new TagClass;
        GetTagName = new QInputDialog;
        GetTagName->setOption(QInputDialog::NoButtons);
        while(1){
        ok = false;
        TagName = GetTagName->getText(NULL,"TagNameWindow","Set tag name:",QLineEdit::Normal,NULL,&ok);
        if ((TagName.isEmpty() || TagName.isNull()) && ok){
            QMessageBox::information(this,tr("Error"),tr("Set tag name"));
            TagName = TagName.null;
            continue;
        }
        else if(ok && (!TagName.isEmpty() || !TagName.isNull())){break;}
        return;
        }
        delete GetTagName;
        GetTagName = nullptr;
        VPos++;
        NewTag->TagPosition = CropArea;
        NewTag->tag_id = VPos;  //
        NewTag->tag_name = TagName;   // setName for the tag
        TagContainer.push_back(NewTag);
        NewTag = nullptr;
        ui->TagList->addItem(TagContainer.at(VPos)->tag_name);
        firstTag = false;
        std::thread thr (&VideoTag::TagStreamThread, this);
        thr.detach();
    }

}
void VideoTag::TagStreamThread(){

 while(1){
    mutex.lock();
    shot_ = shot_.copy(CropArea);
    shot_ = shot_.scaled(ui->TagVideo->width(),ui->TagVideo->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
=======

void VideoTag::on_AddTag_clicked()
{
    std::thread thr (&VideoTag::TagStreamThread, this);
    thr.detach();
}
void VideoTag::TagStreamThread(){
 while(1){
    mutex.lock();
    shot_ = shot_.copy(CropArea);
    shot_ = shot_.scaled(ui->TagVideo->width(),ui->TagVideo->height(),Qt::KeepAspectRatio);
>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
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


<<<<<<< HEAD
=======

>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
}

void VideoTag::on_Pause_clicked()
{

}

void VideoTag::paintEvent(QPaintEvent *event){
    QPainter p,p1;
    p.begin(this);
    p.setPen(Qt::PenStyle::DashLine);
<<<<<<< HEAD
    p.drawRect(ui->MainVideo->x(),ui->MainVideo->y(),ui->MainVideo->width(),ui->MainVideo->height());
    p.end();
    p1.begin(this);
    p1.setPen(Qt::PenStyle::DashLine);
    p1.drawRect(ui->TagVideo->x(),ui->TagVideo->y(),ui->TagVideo->width(),ui->TagVideo->height());
    p1.end();
}
void VideoTag::on_Back_clicked()
{

}

void VideoTag::on_Next_clicked()
{

}
=======
    p.drawRect(ui->MainVideo->x()-2,ui->MainVideo->y()+3,ui->MainVideo->width()+3,ui->MainVideo->height()-8);
    p.end();


}


>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
