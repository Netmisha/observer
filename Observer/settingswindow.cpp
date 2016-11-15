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
    settings_file.open(QIODevice::ReadWrite);
    if(!settings_file.isOpen()) {
        return ;
    }
    ui->setting_textEdit->setText(settings_file.readAll());
}
