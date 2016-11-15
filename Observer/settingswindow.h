#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

namespace Ui {
class SettingsWindow;
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

private:
    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
