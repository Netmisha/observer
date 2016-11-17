#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
<<<<<<< HEAD

namespace Ui {
class SettingsWindow;
}
=======
#include "settingsfile.h"

class XMLHighlighter;
namespace Ui {
class SettingsWindow;
}
namespace settings_ui {
const int kMessageTimeout=3000;
}
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84

class SettingsWindow : public QMainWindow
{
    Q_OBJECT
<<<<<<< HEAD

=======
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
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
<<<<<<< HEAD
<<<<<<< HEAD
    void on_open_dialogButton_clicked();

private:
    Ui::SettingsWindow *ui;
=======

=======
>>>>>>> master
    void on_open_dialogButton_clicked();

    void on_setting_fileEdit_editingFinished();

    void on_save_fileButton_clicked();

private:
    void ClearAll();
    void Initialize();
    Ui::SettingsWindow *ui;
    settings_file::SettingsFile s;
>>>>>>> 6d8eb3eafc2e8426feb8594babd77383d6c11e84
};

#endif // SETTINGSWINDOW_H
