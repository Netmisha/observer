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
    QByteArrayData data[18];
    char stringdata0[333];
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
QT_MOC_LITERAL(4, 44, 10), // "paintEvent"
QT_MOC_LITERAL(5, 55, 12), // "QPaintEvent*"
QT_MOC_LITERAL(6, 68, 11), // "resizeEvent"
QT_MOC_LITERAL(7, 80, 13), // "QResizeEvent*"
QT_MOC_LITERAL(8, 94, 8), // "addImage"
QT_MOC_LITERAL(9, 103, 3), // "Mat"
QT_MOC_LITERAL(10, 107, 33), // "on_select_from_listButton_cli..."
QT_MOC_LITERAL(11, 141, 30), // "on_remote_cameraButton_clicked"
QT_MOC_LITERAL(12, 172, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(13, 194, 47), // "on_list_of_cameras_comboBox_c..."
QT_MOC_LITERAL(14, 242, 11), // "FrameMoving"
QT_MOC_LITERAL(15, 254, 20), // "on_cutButton_clicked"
QT_MOC_LITERAL(16, 275, 25), // "on_originalButton_clicked"
QT_MOC_LITERAL(17, 301, 31) // "on_camera_connectButton_clicked"

    },
    "SelectCamera\0RepaintLines\0\0QVector<QPoint>&\0"
    "paintEvent\0QPaintEvent*\0resizeEvent\0"
    "QResizeEvent*\0addImage\0Mat\0"
    "on_select_from_listButton_clicked\0"
    "on_remote_cameraButton_clicked\0"
    "on_nextButton_clicked\0"
    "on_list_of_cameras_comboBox_currentIndexChanged\0"
    "FrameMoving\0on_cutButton_clicked\0"
    "on_originalButton_clicked\0"
    "on_camera_connectButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectCamera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   77,    2, 0x08 /* Private */,
       6,    1,   80,    2, 0x08 /* Private */,
       8,    1,   83,    2, 0x08 /* Private */,
      10,    0,   86,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    0,   88,    2, 0x08 /* Private */,
      13,    1,   89,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
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
        case 0: _t->RepaintLines((*reinterpret_cast< QVector<QPoint>(*)>(_a[1]))); break;
        case 1: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 2: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 3: _t->addImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 4: _t->on_select_from_listButton_clicked(); break;
        case 5: _t->on_remote_cameraButton_clicked(); break;
        case 6: _t->on_nextButton_clicked(); break;
        case 7: _t->on_list_of_cameras_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->FrameMoving(); break;
        case 9: _t->on_cutButton_clicked(); break;
        case 10: _t->on_originalButton_clicked(); break;
        case 11: _t->on_camera_connectButton_clicked(); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SelectCamera::RepaintLines(QVector<QPoint> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
