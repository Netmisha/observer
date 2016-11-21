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
    QByteArrayData data[24];
    char stringdata0[312];
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
QT_MOC_LITERAL(6, 50, 20), // "SendToSettingsWindow"
QT_MOC_LITERAL(7, 71, 13), // "SettingsFile*"
QT_MOC_LITERAL(8, 85, 3), // "obj"
QT_MOC_LITERAL(9, 89, 23), // "SendSettingSelectCamera"
QT_MOC_LITERAL(10, 113, 16), // "on_Start_clicked"
QT_MOC_LITERAL(11, 130, 17), // "on_AddTag_clicked"
QT_MOC_LITERAL(12, 148, 14), // "on_dbl_clicked"
QT_MOC_LITERAL(13, 163, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(14, 180, 4), // "item"
QT_MOC_LITERAL(15, 185, 15), // "showContextMenu"
QT_MOC_LITERAL(16, 201, 11), // "itemClicked"
QT_MOC_LITERAL(17, 213, 15), // "on_Back_clicked"
QT_MOC_LITERAL(18, 229, 15), // "on_Next_clicked"
QT_MOC_LITERAL(19, 245, 12), // "ReceiveImage"
QT_MOC_LITERAL(20, 258, 3), // "Mat"
QT_MOC_LITERAL(21, 262, 6), // "imgsrc"
QT_MOC_LITERAL(22, 269, 23), // "ReceiveFromSelectCamera"
QT_MOC_LITERAL(23, 293, 18) // "ReceiveFromSetting"

    },
    "VideoTag\0SendID\0\0id\0OpenSettings\0"
    "OpenSelectCamera\0SendToSettingsWindow\0"
    "SettingsFile*\0obj\0SendSettingSelectCamera\0"
    "on_Start_clicked\0on_AddTag_clicked\0"
    "on_dbl_clicked\0QListWidgetItem*\0item\0"
    "showContextMenu\0itemClicked\0on_Back_clicked\0"
    "on_Next_clicked\0ReceiveImage\0Mat\0"
    "imgsrc\0ReceiveFromSelectCamera\0"
    "ReceiveFromSetting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoTag[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    0,   92,    2, 0x06 /* Public */,
       5,    0,   93,    2, 0x06 /* Public */,
       6,    1,   94,    2, 0x06 /* Public */,
       9,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  100,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    1,  102,    2, 0x08 /* Private */,
      15,    1,  105,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,
      18,    0,  110,    2, 0x08 /* Private */,
      19,    1,  111,    2, 0x08 /* Private */,
      22,    1,  114,    2, 0x08 /* Private */,
      23,    1,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

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
        case 3: _t->SendToSettingsWindow((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        case 4: _t->SendSettingSelectCamera((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        case 5: _t->on_Start_clicked(); break;
        case 6: _t->on_AddTag_clicked(); break;
        case 7: _t->on_dbl_clicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 9: _t->itemClicked(); break;
        case 10: _t->on_Back_clicked(); break;
        case 11: _t->on_Next_clicked(); break;
        case 12: _t->ReceiveImage((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 13: _t->ReceiveFromSelectCamera((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        case 14: _t->ReceiveFromSetting((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
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
        {
            typedef void (VideoTag::*_t)(SettingsFile * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoTag::SendToSettingsWindow)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (VideoTag::*_t)(SettingsFile * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoTag::SendSettingSelectCamera)) {
                *result = 4;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
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

// SIGNAL 3
void VideoTag::SendToSettingsWindow(SettingsFile * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void VideoTag::SendSettingSelectCamera(SettingsFile * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
