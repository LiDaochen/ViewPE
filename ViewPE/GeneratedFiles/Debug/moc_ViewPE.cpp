/****************************************************************************
** Meta object code from reading C++ file 'ViewPE.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ViewPE.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewPE.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewPE_t {
    QByteArrayData data[17];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewPE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewPE_t qt_meta_stringdata_ViewPE = {
    {
QT_MOC_LITERAL(0, 0, 6), // "ViewPE"
QT_MOC_LITERAL(1, 7, 11), // "actionAbout"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "actionQuit"
QT_MOC_LITERAL(4, 31, 14), // "actionOpenFile"
QT_MOC_LITERAL(5, 46, 13), // "actionToolBar"
QT_MOC_LITERAL(6, 60, 15), // "actionStatusBar"
QT_MOC_LITERAL(7, 76, 19), // "OnSystemtrayClicked"
QT_MOC_LITERAL(8, 96, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(9, 130, 6), // "reason"
QT_MOC_LITERAL(10, 137, 20), // "actionOpenSystemTray"
QT_MOC_LITERAL(11, 158, 15), // "actionDosHeader"
QT_MOC_LITERAL(12, 174, 16), // "actionFileHeader"
QT_MOC_LITERAL(13, 191, 20), // "actionOptionalHeader"
QT_MOC_LITERAL(14, 212, 19), // "actionDataDirectory"
QT_MOC_LITERAL(15, 232, 18), // "actionSectionTable"
QT_MOC_LITERAL(16, 251, 12) // "actionImport"

    },
    "ViewPE\0actionAbout\0\0actionQuit\0"
    "actionOpenFile\0actionToolBar\0"
    "actionStatusBar\0OnSystemtrayClicked\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0actionOpenSystemTray\0actionDosHeader\0"
    "actionFileHeader\0actionOptionalHeader\0"
    "actionDataDirectory\0actionSectionTable\0"
    "actionImport"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewPE[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    1,   84,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ViewPE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewPE *_t = static_cast<ViewPE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actionAbout(); break;
        case 1: _t->actionQuit(); break;
        case 2: _t->actionOpenFile(); break;
        case 3: _t->actionToolBar(); break;
        case 4: _t->actionStatusBar(); break;
        case 5: _t->OnSystemtrayClicked((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 6: _t->actionOpenSystemTray(); break;
        case 7: _t->actionDosHeader(); break;
        case 8: _t->actionFileHeader(); break;
        case 9: _t->actionOptionalHeader(); break;
        case 10: _t->actionDataDirectory(); break;
        case 11: _t->actionSectionTable(); break;
        case 12: _t->actionImport(); break;
        default: ;
        }
    }
}

const QMetaObject ViewPE::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ViewPE.data,
      qt_meta_data_ViewPE,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ViewPE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewPE::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ViewPE.stringdata0))
        return static_cast<void*>(const_cast< ViewPE*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ViewPE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
