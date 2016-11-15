#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "xmlhighlighter.h"

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
signals:
    void OpenMainWindow();
    void OpenTagsWindow();
private slots:
    void on_open_tags_window_clicked();
    void closeEvent(QCloseEvent *);
    void on_close_settings_clicked();

    void on_open_dialogButton_clicked();

    void on_setting_fileEdit_editingFinished();

    void on_save_fileButton_clicked();

private:
    void ClearAll();
    void Initialize();
    Ui::SettingsWindow *ui;
    XMLHighlighter *xml_hl_;
};

#endif // SETTINGSWINDOW_H
