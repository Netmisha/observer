/****************************************************************************
** Meta object code from reading C++ file 'settingswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Observer/settingswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SettingsWindow_t {
    QByteArrayData data[20];
    char stringdata0[438];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsWindow_t qt_meta_stringdata_SettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SettingsWindow"
QT_MOC_LITERAL(1, 15, 14), // "OpenMainWindow"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "SettingsFile*"
QT_MOC_LITERAL(4, 45, 14), // "OpenTagsWindow"
QT_MOC_LITERAL(5, 60, 10), // "ShowWindow"
QT_MOC_LITERAL(6, 71, 27), // "on_open_tags_window_clicked"
QT_MOC_LITERAL(7, 99, 10), // "closeEvent"
QT_MOC_LITERAL(8, 110, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 123, 25), // "on_close_settings_clicked"
QT_MOC_LITERAL(10, 149, 28), // "on_open_dialogButton_clicked"
QT_MOC_LITERAL(11, 178, 35), // "on_setting_fileEdit_editingFi..."
QT_MOC_LITERAL(12, 214, 26), // "on_save_fileButton_clicked"
QT_MOC_LITERAL(13, 241, 26), // "on_save_timeButton_clicked"
QT_MOC_LITERAL(14, 268, 27), // "on_both_radioButton_clicked"
QT_MOC_LITERAL(15, 296, 32), // "on_on_change_radioButton_clicked"
QT_MOC_LITERAL(16, 329, 28), // "on_timer_radioButton_clicked"
QT_MOC_LITERAL(17, 358, 30), // "on_tags_listWidget_itemChanged"
QT_MOC_LITERAL(18, 389, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(19, 406, 31) // "on_setting_textEdit_textChanged"

    },
    "SettingsWindow\0OpenMainWindow\0\0"
    "SettingsFile*\0OpenTagsWindow\0ShowWindow\0"
    "on_open_tags_window_clicked\0closeEvent\0"
    "QCloseEvent*\0on_close_settings_clicked\0"
    "on_open_dialogButton_clicked\0"
    "on_setting_fileEdit_editingFinished\0"
    "on_save_fileButton_clicked\0"
    "on_save_timeButton_clicked\0"
    "on_both_radioButton_clicked\0"
    "on_on_change_radioButton_clicked\0"
    "on_timer_radioButton_clicked\0"
    "on_tags_listWidget_itemChanged\0"
    "QListWidgetItem*\0on_setting_textEdit_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   95,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    1,   99,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    1,  110,    2, 0x08 /* Private */,
      19,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void,

       0        // eod
};

void SettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingsWindow *_t = static_cast<SettingsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OpenMainWindow((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        case 1: _t->OpenTagsWindow((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        case 2: _t->ShowWindow((*reinterpret_cast< SettingsFile*(*)>(_a[1]))); break;
        case 3: _t->on_open_tags_window_clicked(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 5: _t->on_close_settings_clicked(); break;
        case 6: _t->on_open_dialogButton_clicked(); break;
        case 7: _t->on_setting_fileEdit_editingFinished(); break;
        case 8: _t->on_save_fileButton_clicked(); break;
        case 9: _t->on_save_timeButton_clicked(); break;
        case 10: _t->on_both_radioButton_clicked(); break;
        case 11: _t->on_on_change_radioButton_clicked(); break;
        case 12: _t->on_timer_radioButton_clicked(); break;
        case 13: _t->on_tags_listWidget_itemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->on_setting_textEdit_textChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SettingsWindow::*_t)(SettingsFile * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingsWindow::OpenMainWindow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SettingsWindow::*_t)(SettingsFile * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingsWindow::OpenTagsWindow)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SettingsWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SettingsWindow.data,
      qt_meta_data_SettingsWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWindow.stringdata0))
        return static_cast<void*>(const_cast< SettingsWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void SettingsWindow::OpenMainWindow(SettingsFile * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SettingsWindow::OpenTagsWindow(SettingsFile * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
