/****************************************************************************
** Meta object code from reading C++ file 'videotag.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../videotag.h"
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
    QByteArrayData data[11];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoTag_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoTag_t qt_meta_stringdata_VideoTag = {
    {
QT_MOC_LITERAL(0, 0, 8), // "VideoTag"
QT_MOC_LITERAL(1, 9, 16), // "on_Start_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "on_Stop_clicked"
QT_MOC_LITERAL(4, 43, 16), // "on_Pause_clicked"
QT_MOC_LITERAL(5, 60, 17), // "on_AddTag_clicked"
QT_MOC_LITERAL(6, 78, 14), // "on_dbl_clicked"
QT_MOC_LITERAL(7, 93, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 110, 4), // "item"
QT_MOC_LITERAL(9, 115, 15), // "showContextMenu"
QT_MOC_LITERAL(10, 131, 11) // "itemClicked"

    },
    "VideoTag\0on_Start_clicked\0\0on_Stop_clicked\0"
    "on_Pause_clicked\0on_AddTag_clicked\0"
    "on_dbl_clicked\0QListWidgetItem*\0item\0"
    "showContextMenu\0itemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoTag[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       9,    1,   56,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,

       0        // eod
};

void VideoTag::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoTag *_t = static_cast<VideoTag *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Start_clicked(); break;
        case 1: _t->on_Stop_clicked(); break;
        case 2: _t->on_Pause_clicked(); break;
        case 3: _t->on_AddTag_clicked(); break;
        case 4: _t->on_dbl_clicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: _t->itemClicked(); break;
        default: ;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
