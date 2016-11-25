#include "videotag.h"
#include "ui_videotag.h"

using namespace cv;
VideoTag::VideoTag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoTag)
{
    //emit SendId(int id) to send camera id
       ui->setupUi(this);
       connect(ui->TagList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_dbl_clicked(QListWidgetItem*)));
       connect(ui->TagList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked()));
       connect(ui->TagList->itemDelegate(),&QAbstractItemDelegate::commitData,this,VideoTag::OnDataRename);
       ui->TagList->setContextMenuPolicy(Qt::CustomContextMenu);
       connect(ui->TagList,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(showContextMenu(const QPoint&)));
       ui->TagVideo->setText("Offline"); ui->TagVideo->setAlignment(Qt::AlignCenter); setF = ui->TagVideo->font();setF.setItalic(true);setF.setPointSize(10); ui->TagVideo->setFont(setF);
       ui->MainVideo->setText("Offline"); ui->MainVideo->setAlignment(Qt::AlignCenter); ui->MainVideo->setFont(setF);
}

VideoTag::~VideoTag()
{
    delete ui;
}
void VideoTag::itemClicked(){
    ui->MainVideo->PaintRubber(ContainerT.at(ui->TagList->currentRow())->rect_,StreamM.getImageSize());
    CropArea=ui->MainVideo->getSelectedRect(StreamM.getImageSize());
}

void VideoTag::ReceiveFromSelectCamera(SettingsFile *obj){

    this->show();
    Tobj = obj;
    StreamM.setSettings(*Tobj);
    getTagsFromXML();
    //emit SendID(0);// Pass Camera ID. default is 0
    StreamM.StartStream();
    connect(&StreamM,SIGNAL(SendImage(Mat)),this,SLOT(ReceiveImage(Mat)));

}
bool VideoTag::getTagsFromXML(){

    /*for(auto &it:StreamM.getSettings().getTagsList()) {
        NewTagS=new settings_file::TagInfo();
        *NewTagS=it;
        ContainerT.push_back(NewTagS);
    }
    ui->MainVideo->Clear_Rubber();
    out = true;*/

    ui->MainVideo->Clear_Rubber();
    //if(out){return 0;}
    //else{
    if(Tobj->getTagsList().empty()){
        qDebug()<<"No tags in XML";
         return 1;
    }
    for (int i=0;i<Tobj->getTagsList().size();i++){
        qDebug()<<"Not empty";
        NewTagS = new TagInfo;
        *NewTagS = Tobj->getTagsList().at(i);
        ui->TagList->addItem(NewTagS->name_);
        ContainerT.push_back(NewTagS);
        NewTagS = nullptr;
        VPos++;
    }
    firstTag = false;
    //out = true;
    return 0;
    //}
}
void VideoTag::ReceiveFromSetting(SettingsFile *obj){
    this->show();
    Tobj = obj;
    StreamM.setSettings(*Tobj);
    getTagsFromXML();
    //emit SendID(0);// Pass Camera ID. default is 0
    StreamM.StartStream();

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
    }else{
    ContainerT[ui->TagList->currentRow()]->name_ = str;
    }
}
void VideoTag::tag_delete(const QPoint& pos){

if(ContainerT.empty()){
  QMessageBox::information(ui->TagList,tr("Empty"),tr("The list is empty. Nothing to delete"));
    return;
}
int nRow = ui->TagList->indexAt(pos).row();
int QE = ui->TagList->count(); // starts from 1 not from 0
QE--;
for (int i=0;i<=QE;i++){
    qDebug()<<ContainerT.at(i)->name_;
}

ContainerT.erase(ContainerT.begin()+nRow);
VPos--;
for (int i=0;i<QE;i++){
    qDebug()<<ContainerT.at(i)->name_;
}
 ui->TagList->takeItem(ui->TagList->indexAt(pos).row());
 if(ui->TagList->count() == 0){
     QRect nu(0,0,0,0);
     CropArea = nu;
 }
}

void VideoTag::on_dbl_clicked(QListWidgetItem* it){
it->setFlags(it->flags() | Qt::ItemIsEditable);
ui->TagList->editItem(it);
temp = it->text();
}

void VideoTag::on_AddTag_clicked()
{

    if(firstTag == false){
      GetTagName = new QInputDialog;
      GetTagName->setOption(QInputDialog::NoButtons);
      while(1){
      ok = false;
      TagName = GetTagName->getText(NULL,"TagNameWindow","Set tag name:",QLineEdit::Normal,NULL,&ok);
      if ((TagName.isEmpty()) && ok){
          QMessageBox::information(this,tr("Error"),tr("Set tag name"));
          TagName = TagName.null;
          continue;
      }
      else if(ok && (!TagName.isEmpty())){break;}
      return;
      }
      delete GetTagName;
      GetTagName = nullptr;
      VPos++;
      NewTagS = new TagInfo;
      CropArea=ui->MainVideo->getSelectedRect(StreamM.getImageSize());
      NewTagS->rect_ = CropArea;
      NewTagS->name_ = TagName;
      ContainerT.push_back(NewTagS);
      NewTagS = nullptr;
      ui->TagList->addItem(ContainerT.at(VPos)->name_);
    }
    else if(firstTag == true){

        NewTagS = new TagInfo;
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
        CropArea=ui->MainVideo->getSelectedRect(StreamM.getImageSize());
        NewTagS->rect_ = CropArea;
        NewTagS->name_ = TagName;
        ContainerT.push_back(NewTagS);
        NewTagS = nullptr;
        ui->TagList->addItem(ContainerT.at(VPos)->name_);
        firstTag = false;
    }
    ui->MainVideo->Clear_Rubber();
}
void VideoTag::closeEvent(QCloseEvent *){

 emit SendToMainFromTag(Tobj);
 this->hide();
}
void VideoTag::TagStreamThread(){

    mutex.lock();
    shot_ = shot_.copy(ui->MainVideo->getSelectedArea()); // <---- crops the area we need
    shot_ = shot_.scaled(ui->TagVideo->width(),ui->TagVideo->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->TagVideo->setPixmap(QPixmap::fromImage(shot_));
    mutex.unlock();
}

void VideoTag::ReceiveImage(Mat imgsrc){
    if (imgsrc.empty()){qDebug()<<"Nothing to display"; return;}
    if(!firstTag){TagStreamThread();}
    //cvtColor(imgsrc,imgsrc,COLOR_BGR2RGB);
    mutex.lock();
    frame = imgsrc;
    QImage qimgOriginal((uchar*)frame.data,frame.cols,frame.rows, frame.step,QImage::Format_RGB888);
    shot_ = qimgOriginal;
    shot_ = shot_.scaled(ui->frame_2->width(),ui->frame_2->height(), Qt::KeepAspectRatio, Qt::FastTransformation);
    qimgOriginal =  qimgOriginal.scaled(ui->frame->width(),ui->frame->height(),Qt::KeepAspectRatio, Qt::FastTransformation);
    int x=abs(ui->frame->width()-qimgOriginal.width())/2;
    int y=abs(ui->frame->height()-qimgOriginal.height())/2;
    ui->MainVideo->setGeometry(QRect(QPoint(x,y), qimgOriginal.size()));
    x=abs(ui->frame_2->width()-shot_.width())/2;
    y=abs(ui->frame_2->height()-shot_.height())/2;
    ui->TagVideo->setGeometry(QRect(QPoint(x,y), shot_.size()));
    ui->MainVideo->setPixmap(QPixmap::fromImage(qimgOriginal));
    mutex.unlock();
}

void VideoTag::mousePressEvent(QMouseEvent *event){

/* if(lock_rect == true){
     rubber->close();
 }
//origin = ui->MainVideo->mapFromGlobal(this->mapToGlobal(event->pos()));
origin = ui->MainVideo->mapFromGlobal(this->mapToParent(event->pos()));
qDebug()<<origin;
rubber = new QRubberBand(QRubberBand::Rectangle,ui->MainVideo); // passing parent for QRubberBand
rubber->setGeometry(QRect(origin,ui->MainVideo->mapToParent(this->mapFromParent(event->pos()))));
//rubber->setGeometry(QRect(origin,ui->MainVideo->mapFromGlobal(this->mapToGlobal(event->pos()))));//
qDebug()<<origin;
rubber->show();*/
}
void VideoTag::mouseMoveEvent(QMouseEvent *event){

    /*rubber->setGeometry(QRect(origin,QSize(ui->MainVideo->mapFromGlobal(this->mapToGlobal(event->pos())).x()-origin.x(),
                                           ui->MainVideo->mapFromGlobal(this->mapToGlobal(event->pos())).y()-origin.y())));
    qDebug()<<rubber->geometry();*/
}
void VideoTag::mouseReleaseEvent(QMouseEvent *){

/*lock_rect = true;
if(rubber->width() == 1 && rubber->height() == 1){
   QRect r(0,0,0,0);
    CropArea = r; // on mouse release tag window will show the whole videoStream
    return;
}

CropArea =QRect(origin,rubber->size()); //QRect(origin,rubber->size());
qDebug()<<CropArea;*/
}
void VideoTag::on_Back_clicked()
{
    this->hide();
    StreamM.StopStream();
    ui->MainVideo->clear();
    ui->TagVideo->clear();
    ui->TagVideo->setText("Offline"); ui->TagVideo->setAlignment(Qt::AlignCenter); setF = ui->TagVideo->font();setF.setItalic(true);setF.setPointSize(10); ui->TagVideo->setFont(setF);
    ui->MainVideo->setText("Offline"); ui->MainVideo->setAlignment(Qt::AlignCenter); ui->MainVideo->setFont(setF);
    Tobj->setTagsList(ContainerT); // set and pass setting to other window
    emit SendSettingSelectCamera(Tobj);
}

void VideoTag::on_Next_clicked()
{
    this->hide();
    StreamM.StopStream();
    Tobj->setTagsList(ContainerT);
    emit SendToSettingsWindow(Tobj);

}
