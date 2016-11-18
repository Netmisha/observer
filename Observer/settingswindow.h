#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QListWidgetItem>
#include "settingsfile.h"

class XMLHighlighter;
namespace Ui {
class SettingsWindow;
}
namespace settings_ui {
const int kMessageTimeout=3000;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();
    void ShowWindow(settings_file::SettingsFile &);
signals:
    void OpenMainWindow();
    void OpenTagsWindow(settings_file::SettingsFile &);
private slots:
    void on_open_tags_window_clicked();
    void closeEvent(QCloseEvent *);
    void on_close_settings_clicked();
    void on_open_dialogButton_clicked();
    void on_setting_fileEdit_editingFinished();
    void on_save_fileButton_clicked();
    void on_save_timeButton_clicked();
    void on_both_radioButton_clicked();
    void on_on_change_radioButton_clicked();
    void on_timer_radioButton_clicked();
    void on_tags_listWidget_itemChanged(QListWidgetItem *);
    void on_setting_textEdit_textChanged();
private:
    void ClearAll();
    void Initialize(QString &);
    void ShowSettings();
    void SaveSettings();
    void WarningMessage();
    Ui::SettingsWindow *ui;
    settings_file::SettingsFile settings_file_;
};

#endif // SETTINGSWINDOW_H
