/****************************************************************************
** Meta object code from reading C++ file 'videotag.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Observer/videotag.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videotag.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoTag_t {
    QByteArrayData data[18];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoTag_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoTag_t qt_meta_stringdata_VideoTag = {
    {
QT_MOC_LITERAL(0, 0, 8), // "VideoTag"
QT_MOC_LITERAL(1, 9, 6), // "SendID"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 2), // "id"
QT_MOC_LITERAL(4, 20, 12), // "OpenSettings"
QT_MOC_LITERAL(5, 33, 16), // "OpenSelectCamera"
QT_MOC_LITERAL(6, 50, 16), // "on_Start_clicked"
QT_MOC_LITERAL(7, 67, 17), // "on_AddTag_clicked"
QT_MOC_LITERAL(8, 85, 14), // "on_dbl_clicked"
QT_MOC_LITERAL(9, 100, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 117, 4), // "item"
QT_MOC_LITERAL(11, 122, 15), // "showContextMenu"
QT_MOC_LITERAL(12, 138, 11), // "itemClicked"
QT_MOC_LITERAL(13, 150, 15), // "on_Back_clicked"
QT_MOC_LITERAL(14, 166, 15), // "on_Next_clicked"
QT_MOC_LITERAL(15, 182, 12), // "ReceiveImage"
QT_MOC_LITERAL(16, 195, 3), // "Mat"
QT_MOC_LITERAL(17, 199, 6) // "imgsrc"

    },
    "VideoTag\0SendID\0\0id\0OpenSettings\0"
    "OpenSelectCamera\0on_Start_clicked\0"
    "on_AddTag_clicked\0on_dbl_clicked\0"
    "QListWidgetItem*\0item\0showContextMenu\0"
    "itemClicked\0on_Back_clicked\0on_Next_clicked\0"
    "ReceiveImage\0Mat\0imgsrc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoTag[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
      11,    1,   79,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,
      14,    0,   84,    2, 0x08 /* Private */,
      15,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void VideoTag::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoTag *_t = static_cast<VideoTag *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->OpenSettings(); break;
        case 2: _t->OpenSelectCamera(); break;
        case 3: _t->on_Start_clicked(); break;
        case 4: _t->on_AddTag_clicked(); break;
        case 5: _t->on_dbl_clicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->itemClicked(); break;
        case 8: _t->on_Back_clicked(); break;
        case 9: _t->on_Next_clicked(); break;
        case 10: _t->ReceiveImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoTag::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoTag::SendID)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (VideoTag::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoTag::OpenSettings)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (VideoTag::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoTag::OpenSelectCamera)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject VideoTag::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VideoTag.data,
      qt_meta_data_VideoTag,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoTag::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoTag::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoTag.stringdata0))
        return static_cast<void*>(const_cast< VideoTag*>(this));
    return QWidget::qt_metacast(_clname);
}

int VideoTag::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void VideoTag::SendID(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoTag::OpenSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void VideoTag::OpenSelectCamera()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
