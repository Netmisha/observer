/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Observer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[29];
    char stringdata0[369];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "CameraID"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 2), // "id"
QT_MOC_LITERAL(4, 24, 11), // "CameraID2_1"
QT_MOC_LITERAL(5, 36, 11), // "CameraID3_2"
QT_MOC_LITERAL(6, 48, 11), // "CameraID3_3"
QT_MOC_LITERAL(7, 60, 12), // "OpenSCWindow"
QT_MOC_LITERAL(8, 73, 15), // "PassSettingFile"
QT_MOC_LITERAL(9, 89, 13), // "SettingsFile*"
QT_MOC_LITERAL(10, 103, 3), // "obj"
QT_MOC_LITERAL(11, 107, 18), // "PassOnSelectCamera"
QT_MOC_LITERAL(12, 126, 14), // "on_SQ2_clicked"
QT_MOC_LITERAL(13, 141, 13), // "on_SQ_clicked"
QT_MOC_LITERAL(14, 155, 14), // "on_SQ3_clicked"
QT_MOC_LITERAL(15, 170, 24), // "on_SettingButton_clicked"
QT_MOC_LITERAL(16, 195, 11), // "itemClicked"
QT_MOC_LITERAL(17, 207, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(18, 224, 4), // "item"
QT_MOC_LITERAL(19, 229, 13), // "ReceiveImageM"
QT_MOC_LITERAL(20, 243, 3), // "Mat"
QT_MOC_LITERAL(21, 247, 6), // "imgsrc"
QT_MOC_LITERAL(22, 254, 9), // "Stream2nd"
QT_MOC_LITERAL(23, 264, 15), // "showContextMenu"
QT_MOC_LITERAL(24, 280, 3), // "pos"
QT_MOC_LITERAL(25, 284, 29), // "on_SelectCameraButton_clicked"
QT_MOC_LITERAL(26, 314, 22), // "ReceiveSettingFromSetW"
QT_MOC_LITERAL(27, 337, 17), // "CloseSelectCamera"
QT_MOC_LITERAL(28, 355, 13) // "ReceiveFromSC"

    },
    "MainWindow\0CameraID\0\0id\0CameraID2_1\0"
    "CameraID3_2\0CameraID3_3\0OpenSCWindow\0"
    "PassSettingFile\0SettingsFile*\0obj\0"
    "PassOnSelectCamera\0on_SQ2_clicked\0"
    "on_SQ_clicked\0on_SQ3_clicked\0"
    "on_SettingButton_clicked\0itemClicked\0"
    "QListWidgetItem*\0item\0ReceiveImageM\0"
    "Mat\0imgsrc\0Stream2nd\0showContextMenu\0"
    "pos\0on_SelectCameraButton_clicked\0"
    "ReceiveSettingFromSetW\0CloseSelectCamera\0"
    "ReceiveFromSC"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    1,  112,    2, 0x06 /* Public */,
       5,    1,  115,    2, 0x06 /* Public */,
       6,    1,  118,    2, 0x06 /* Public */,
       7,    0,  121,    2, 0x06 /* Public */,
       8,    1,  122,    2, 0x06 /* Public */,
      11,    0,  125,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  126,    2, 0x08 /* Private */,
      13,    0,  127,    2, 0x08 /* Private */,
      14,    0,  128,    2, 0x08 /* Private */,
      15,    0,  129,    2, 0x08 /* Private */,
      16,    1,  130,    2, 0x08 /* Private */,
      19,    1,  133,    2, 0x08 /* Private */,
      22,    1,  136,    2, 0x08 /* Private */,
      23,    1,  139,    2, 0x08 /* Private */,
      25,    0,  142,    2, 0x08 /* Private */,
      26,    1,  143,    2, 0x08 /* Private */,
      27,    0,  146,    2, 0x08 /* Private */,
      28,    1,  147,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::QPoint,   24,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CameraID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->CameraID2_1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->CameraID3_2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->CameraID3_3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->OpenSCWindow(); break;
        case 5: _t->PassSettingFile((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        case 6: _t->PassOnSelectCamera(); break;
        case 7: _t->on_SQ2_clicked(); break;
        case 8: _t->on_SQ_clicked(); break;
        case 9: _t->on_SQ3_clicked(); break;
        case 10: _t->on_SettingButton_clicked(); break;
        case 11: _t->itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->ReceiveImageM((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 13: _t->Stream2nd((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 14: _t->showContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 15: _t->on_SelectCameraButton_clicked(); break;
        case 16: _t->ReceiveSettingFromSetW((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        case 17: _t->CloseSelectCamera(); break;
        case 18: _t->ReceiveFromSC((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::CameraID)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::CameraID2_1)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::CameraID3_2)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::CameraID3_3)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::OpenSCWindow)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(SettingsFile * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::PassSettingFile)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::PassOnSelectCamera)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::CameraID(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::CameraID2_1(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::CameraID3_2(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::CameraID3_3(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::OpenSCWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::PassSettingFile(SettingsFile * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::PassOnSelectCamera()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
