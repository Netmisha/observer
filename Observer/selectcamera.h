#ifndef SELECTCAMERA_H
#define SELECTCAMERA_H

#include <QMainWindow>

namespace Ui {
class SelectCamera;
}
namespace literals {
    const char kDefoultIndex=-1;
}
class SelectCamera : public QMainWindow
{
    Q_OBJECT

public:
    explicit SelectCamera(QWidget *parent = 0);
    ~SelectCamera();

private slots:
    void on_select_from_listButton_clicked();

    void on_remote_cameraButton_clicked();

    void on_previewButton_clicked();

private:
    Ui::SelectCamera *ui;
};

#endif // SELECTCAMERA_H
