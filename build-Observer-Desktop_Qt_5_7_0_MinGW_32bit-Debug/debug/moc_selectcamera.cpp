/****************************************************************************
** Meta object code from reading C++ file 'selectcamera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Observer/selectcamera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectcamera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SelectCamera_t {
    QByteArrayData data[28];
    char stringdata0[452];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectCamera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectCamera_t qt_meta_stringdata_SelectCamera = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SelectCamera"
QT_MOC_LITERAL(1, 13, 12), // "RepaintLines"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "QVector<QPoint>&"
QT_MOC_LITERAL(4, 44, 10), // "SizeChange"
QT_MOC_LITERAL(5, 55, 13), // "QResizeEvent*"
QT_MOC_LITERAL(6, 69, 9), // "SendImage"
QT_MOC_LITERAL(7, 79, 3), // "Mat"
QT_MOC_LITERAL(8, 83, 14), // "OpenTagsWindow"
QT_MOC_LITERAL(9, 98, 10), // "paintEvent"
QT_MOC_LITERAL(10, 109, 12), // "QPaintEvent*"
QT_MOC_LITERAL(11, 122, 8), // "getImage"
QT_MOC_LITERAL(12, 131, 11), // "resizeEvent"
QT_MOC_LITERAL(13, 143, 8), // "addImage"
QT_MOC_LITERAL(14, 152, 13), // "on_timer_show"
QT_MOC_LITERAL(15, 166, 13), // "on_timer_send"
QT_MOC_LITERAL(16, 180, 9), // "send_stop"
QT_MOC_LITERAL(17, 190, 33), // "on_select_from_listButton_cli..."
QT_MOC_LITERAL(18, 224, 11), // "ResizeImage"
QT_MOC_LITERAL(19, 236, 30), // "on_remote_cameraButton_clicked"
QT_MOC_LITERAL(20, 267, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(21, 289, 47), // "on_list_of_cameras_comboBox_c..."
QT_MOC_LITERAL(22, 337, 11), // "FrameMoving"
QT_MOC_LITERAL(23, 349, 20), // "on_cutButton_clicked"
QT_MOC_LITERAL(24, 370, 25), // "on_originalButton_clicked"
QT_MOC_LITERAL(25, 396, 31), // "on_camera_connectButton_clicked"
QT_MOC_LITERAL(26, 428, 10), // "closeEvent"
QT_MOC_LITERAL(27, 439, 12) // "QCloseEvent*"

    },
    "SelectCamera\0RepaintLines\0\0QVector<QPoint>&\0"
    "SizeChange\0QResizeEvent*\0SendImage\0"
    "Mat\0OpenTagsWindow\0paintEvent\0"
    "QPaintEvent*\0getImage\0resizeEvent\0"
    "addImage\0on_timer_show\0on_timer_send\0"
    "send_stop\0on_select_from_listButton_clicked\0"
    "ResizeImage\0on_remote_cameraButton_clicked\0"
    "on_nextButton_clicked\0"
    "on_list_of_cameras_comboBox_currentIndexChanged\0"
    "FrameMoving\0on_cutButton_clicked\0"
    "on_originalButton_clicked\0"
    "on_camera_connectButton_clicked\0"
    "closeEvent\0QCloseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectCamera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       4,    1,  122,    2, 0x06 /* Public */,
       6,    1,  125,    2, 0x06 /* Public */,
       8,    0,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  129,    2, 0x08 /* Private */,
      11,    1,  132,    2, 0x08 /* Private */,
      12,    1,  135,    2, 0x08 /* Private */,
      13,    1,  138,    2, 0x08 /* Private */,
      14,    0,  141,    2, 0x08 /* Private */,
      15,    0,  142,    2, 0x08 /* Private */,
      16,    0,  143,    2, 0x08 /* Private */,
      17,    0,  144,    2, 0x08 /* Private */,
      18,    0,  145,    2, 0x08 /* Private */,
      19,    0,  146,    2, 0x08 /* Private */,
      20,    0,  147,    2, 0x08 /* Private */,
      21,    1,  148,    2, 0x08 /* Private */,
      22,    0,  151,    2, 0x08 /* Private */,
      23,    0,  152,    2, 0x08 /* Private */,
      24,    0,  153,    2, 0x08 /* Private */,
      25,    0,  154,    2, 0x08 /* Private */,
      26,    1,  155,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,    2,

       0        // eod
};

void SelectCamera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectCamera *_t = static_cast<SelectCamera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RepaintLines((*reinterpret_cast< QVector<QPoint>(*)>(_a[1]))); break;
        case 1: _t->SizeChange((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 2: _t->SendImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 3: _t->OpenTagsWindow(); break;
        case 4: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 5: _t->getImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 7: _t->addImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 8: _t->on_timer_show(); break;
        case 9: _t->on_timer_send(); break;
        case 10: _t->send_stop(); break;
        case 11: _t->on_select_from_listButton_clicked(); break;
        case 12: _t->ResizeImage(); break;
        case 13: _t->on_remote_cameraButton_clicked(); break;
        case 14: _t->on_nextButton_clicked(); break;
        case 15: _t->on_list_of_cameras_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->FrameMoving(); break;
        case 17: _t->on_cutButton_clicked(); break;
        case 18: _t->on_originalButton_clicked(); break;
        case 19: _t->on_camera_connectButton_clicked(); break;
        case 20: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SelectCamera::*_t)(QVector<QPoint> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectCamera::RepaintLines)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SelectCamera::*_t)(QResizeEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectCamera::SizeChange)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SelectCamera::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectCamera::SendImage)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SelectCamera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectCamera::OpenTagsWindow)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject SelectCamera::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SelectCamera.data,
      qt_meta_data_SelectCamera,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SelectCamera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectCamera::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SelectCamera.stringdata0))
        return static_cast<void*>(const_cast< SelectCamera*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SelectCamera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void SelectCamera::RepaintLines(QVector<QPoint> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SelectCamera::SizeChange(QResizeEvent * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SelectCamera::SendImage(Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SelectCamera::OpenTagsWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
