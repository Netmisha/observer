#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QMessageBox>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_open_tags_window_clicked()
{
    //WarningMessage();

    emit OpenTagsWindow(settings_file_.getCameraName());
}

void SettingsWindow::ShowWindow(QString &file_name)
{
    this->show();
    settings_file_.setFileName(file_name);
    Initialize(file_name);
}

void SettingsWindow::closeEvent(QCloseEvent *)
{
    WarningMessage();
    emit OpenMainWindow();
}

void SettingsWindow::on_close_settings_clicked()
{
    WarningMessage();
    emit OpenMainWindow();
}

void SettingsWindow::on_open_dialogButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Select a file"), QDir::currentPath());
    Initialize(file_name);
}

void SettingsWindow::on_setting_fileEdit_editingFinished()
{
    QString file_name = ui->setting_fileEdit->text();
    QFile settings_file(file_name);
    settings_file.open(QIODevice::ReadOnly);
    if(!settings_file.isOpen()) {
        ui->statusbar->showMessage("File didn`t open!",settings_ui::kMessageTimeout);
        return ;
    }
    ui->setting_textEdit->setPlainText(settings_file.readAll());
    settings_file.close();
}

void SettingsWindow::ClearAll()
{
    ui->setting_fileEdit->clear();
    ui->setting_textEdit->clear();
}

void SettingsWindow::Initialize(QString &file_name)
{
    QFile settings_file(file_name);
    settings_file.open(QIODevice::ReadOnly);
    if(!settings_file.isOpen()) {
        ui->statusbar->showMessage("File didn`t open!",settings_ui::kMessageTimeout);
        return ;
    }
    ui->setting_fileEdit->setText(file_name);
    ui->setting_textEdit->setPlainText(settings_file.readAll());
    settings_file.close();
    settings_file_.setFileName(file_name);
    settings_file_.ReadSettings();
    if(settings_file_.getMonitoringType()==settings_file::kMonitoringBoth) {
        ui->both_radioButton->setChecked(true);
    }
    if(settings_file_.getMonitoringType()==settings_file::kMonitoringTags) {
        ui->on_change_radioButton->setChecked(true);
    }
    if(settings_file_.getMonitoringType()==settings_file::kMonitoringTimer) {
        ui->timer_radioButton->setChecked(true);
    }
    ShowSettings();
    ui->save_fileButton->setEnabled(false);
}

void SettingsWindow::ShowSettings()
{
    ui->time_spinBox->setValue(settings_file_.getTimer());
    while(ui->tags_listWidget->count()!=0) {
        ui->tags_listWidget->removeItemWidget(ui->tags_listWidget->item(0));
        ui->tags_listWidget->takeItem(0);
    }
    for(auto &it:settings_file_.getTagsList()) {
        QListWidgetItem* item = new QListWidgetItem(it.name_);
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item->setCheckState(Qt::Checked);
        if (!settings_file_.getMonitoringTags().contains(it.name_)) {
            item->setCheckState(Qt::Unchecked);
        }
        ui->tags_listWidget->addItem(item);
    }
}

void SettingsWindow::SaveSettings()
{
    settings_file_.SaveSettings();
    settings_file_.ReadSettings();
    QFile settings_file(settings_file_.getFileName());
    settings_file.open(QIODevice::ReadOnly);
    if(!settings_file.isOpen()) {
        ui->statusbar->showMessage("File didn`t open!",settings_ui::kMessageTimeout);
        return ;
    }
    ui->setting_textEdit->setPlainText(settings_file.readAll());
    settings_file.close();
    ShowSettings();
}

void SettingsWindow::WarningMessage()
{
    if(!ui->save_fileButton->isEnabled()) {
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning", "File is not saved. Would you like to save the file?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        on_save_fileButton_clicked();
    }
}

void SettingsWindow::on_save_fileButton_clicked()
{
    QString file_name = ui->setting_fileEdit->text();
    QFile settings_file(file_name);
    settings_file.open(QIODevice::WriteOnly);
    if(!settings_file.isOpen()) {
        ui->statusbar->showMessage("File didn`t open!",settings_ui::kMessageTimeout);
        return ;
    }
    settings_file.write(ui->setting_textEdit->toPlainText().toLatin1());
    settings_file_.setFileName(file_name);
    settings_file_.ReadSettings();
    ShowSettings();
    ui->save_fileButton->setEnabled(false);
}

void SettingsWindow::on_save_timeButton_clicked()
{
    settings_file_.setTimer(ui->time_spinBox->value());
    SaveSettings();
}

void SettingsWindow::on_both_radioButton_clicked()
{
    ui->time_spinBox->setEnabled(true);
    ui->tags_listWidget->setEnabled(true);
    settings_file_.setMonitoringType(settings_file::kMonitoringBoth);
    SaveSettings();
}

void SettingsWindow::on_on_change_radioButton_clicked()
{
    ui->time_spinBox->setEnabled(false);
    ui->tags_listWidget->setEnabled(true);
    settings_file_.setMonitoringType(settings_file::kMonitoringTags);
    ui->time_spinBox->setValue(0);
    settings_file_.setTimer(0);
    SaveSettings();
}

void SettingsWindow::on_timer_radioButton_clicked()
{
    ui->time_spinBox->setEnabled(true);
    ui->tags_listWidget->setEnabled(false);
    ui->time_spinBox->setValue(settings_file_.getTimer());
    settings_file_.setMonitoringType(settings_file::kMonitoringTimer);
    for(int i=0;i<ui->tags_listWidget->count(); i++) {
        ui->tags_listWidget->item(i)->setCheckState(Qt::Unchecked);
    }
    settings_file_.getMonitoringTags().clear();
    SaveSettings();
}
void SettingsWindow::on_tags_listWidget_itemChanged(QListWidgetItem *item)
{
    auto mon_tags=settings_file_.getMonitoringTags();
    mon_tags.removeAll(item->text());
    if(item->checkState()==Qt::Checked) {
        mon_tags.push_back(item->text());
    }
    settings_file_.setMonitoringTags(mon_tags);
    SaveSettings();
}

void SettingsWindow::on_setting_textEdit_textChanged()
{
    ui->save_fileButton->setEnabled(true);
}
