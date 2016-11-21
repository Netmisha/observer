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
    QByteArrayData data[22];
    char stringdata0[389];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectCamera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectCamera_t qt_meta_stringdata_SelectCamera = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SelectCamera"
QT_MOC_LITERAL(1, 13, 14), // "OpenTagsWindow"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "SettingsFile*"
QT_MOC_LITERAL(4, 43, 14), // "OpenMainWindow"
QT_MOC_LITERAL(5, 58, 12), // "RepaintLines"
QT_MOC_LITERAL(6, 71, 16), // "QVector<QPoint>&"
QT_MOC_LITERAL(7, 88, 10), // "showWindow"
QT_MOC_LITERAL(8, 99, 10), // "closeEvent"
QT_MOC_LITERAL(9, 110, 12), // "QCloseEvent*"
QT_MOC_LITERAL(10, 123, 33), // "on_select_from_listButton_cli..."
QT_MOC_LITERAL(11, 157, 30), // "on_remote_cameraButton_clicked"
QT_MOC_LITERAL(12, 188, 47), // "on_list_of_cameras_comboBox_c..."
QT_MOC_LITERAL(13, 236, 9), // "ShowImage"
QT_MOC_LITERAL(14, 246, 3), // "Mat"
QT_MOC_LITERAL(15, 250, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(16, 272, 25), // "on_originalButton_clicked"
QT_MOC_LITERAL(17, 298, 11), // "resizeEvent"
QT_MOC_LITERAL(18, 310, 13), // "QResizeEvent*"
QT_MOC_LITERAL(19, 324, 20), // "on_cutButton_clicked"
QT_MOC_LITERAL(20, 345, 11), // "FrameMoving"
QT_MOC_LITERAL(21, 357, 31) // "on_camera_connectButton_clicked"

    },
    "SelectCamera\0OpenTagsWindow\0\0SettingsFile*\0"
    "OpenMainWindow\0RepaintLines\0"
    "QVector<QPoint>&\0showWindow\0closeEvent\0"
    "QCloseEvent*\0on_select_from_listButton_clicked\0"
    "on_remote_cameraButton_clicked\0"
    "on_list_of_cameras_comboBox_currentIndexChanged\0"
    "ShowImage\0Mat\0on_nextButton_clicked\0"
    "on_originalButton_clicked\0resizeEvent\0"
    "QResizeEvent*\0on_cutButton_clicked\0"
    "FrameMoving\0on_camera_connectButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectCamera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    0,   97,    2, 0x06 /* Public */,
       5,    1,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  101,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    1,  105,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    1,  110,    2, 0x08 /* Private */,
      13,    1,  113,    2, 0x08 /* Private */,
      15,    0,  116,    2, 0x08 /* Private */,
      16,    0,  117,    2, 0x08 /* Private */,
      17,    1,  118,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    0,  122,    2, 0x08 /* Private */,
      21,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int, 0x80000000 | 3,    2,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SelectCamera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectCamera *_t = static_cast<SelectCamera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->OpenTagsWindow((*reinterpret_cast< SettingsFile*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->OpenMainWindow();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->RepaintLines((*reinterpret_cast< QVector<QPoint>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: _t->showWindow((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        case 4: _t->showWindow(); break;
        case 5: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 6: _t->on_select_from_listButton_clicked(); break;
        case 7: _t->on_remote_cameraButton_clicked(); break;
        case 8: _t->on_list_of_cameras_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->ShowImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 10: _t->on_nextButton_clicked(); break;
        case 11: _t->on_originalButton_clicked(); break;
        case 12: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 13: _t->on_cutButton_clicked(); break;
        case 14: _t->FrameMoving(); break;
        case 15: _t->on_camera_connectButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (SelectCamera::*_t)(SettingsFile * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectCamera::OpenTagsWindow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef int (SelectCamera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectCamera::OpenMainWindow)) {
                *result = 1;
                return;
            }
        }
        {
            typedef int (SelectCamera::*_t)(QVector<QPoint> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectCamera::RepaintLines)) {
                *result = 2;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
int SelectCamera::OpenTagsWindow(SettingsFile * _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int SelectCamera::OpenMainWindow()
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
int SelectCamera::RepaintLines(QVector<QPoint> & _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
