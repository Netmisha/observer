#include "settingswindow.h"
#include "ui_settingswindow.h"

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
    emit OpenTagsWindow();
}

void SettingsWindow::closeEvent(QCloseEvent *)
{
    emit OpenMainWindow();
}

void SettingsWindow::on_close_settings_clicked()
{
    emit OpenMainWindow();
}

void SettingsWindow::on_open_dialogButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Select a file"), QDir::currentPath());
    QFile settings_file(file_name);
    settings_file.open(QIODevice::ReadOnly);
    if(!settings_file.isOpen()) {
        ui->statusbar->showMessage("File didn`t open!",settings_ui::kMessageTimeout);
        return ;
    }
    ui->setting_fileEdit->setText(file_name);
    //ui->setting_textEdit->setText(settings_file.readAll());
    ui->setting_textEdit->setPlainText(settings_file.readAll());
    settings_file.close();
    s.setFileName(file_name);
    s.ReadSettings();
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
    //ui->setting_textEdit->setText(settings_file.readAll());
    ui->setting_textEdit->setPlainText(settings_file.readAll());
    settings_file.close();
}

void SettingsWindow::ClearAll()
{
    ui->setting_fileEdit->clear();
    ui->setting_textEdit->clear();
}

void SettingsWindow::Initialize()
{
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
    s.SaveSettings();
}
