/****************************************************************************
** Meta object code from reading C++ file 'veh.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../veh.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'veh.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSvehENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSvehENDCLASS = QtMocHelpers::stringData(
    "veh",
    "ConfV",
    "",
    "reinitV",
    "suppV",
    "modifV",
    "tabClick",
    "QModelIndex",
    "i",
    "filtrerV",
    "trierV",
    "rechV",
    "expoV"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSvehENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x0a,    1 /* Public */,
       3,    0,   69,    2, 0x0a,    2 /* Public */,
       4,    0,   70,    2, 0x0a,    3 /* Public */,
       5,    0,   71,    2, 0x0a,    4 /* Public */,
       6,    1,   72,    2, 0x0a,    5 /* Public */,
       9,    0,   75,    2, 0x0a,    7 /* Public */,
      10,    0,   76,    2, 0x0a,    8 /* Public */,
      11,    0,   77,    2, 0x0a,    9 /* Public */,
      12,    0,   78,    2, 0x0a,   10 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject veh::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSvehENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSvehENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSvehENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<veh, std::true_type>,
        // method 'ConfV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reinitV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'suppV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'modifV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tabClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'filtrerV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'trierV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rechV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'expoV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void veh::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<veh *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ConfV(); break;
        case 1: _t->reinitV(); break;
        case 2: _t->suppV(); break;
        case 3: _t->modifV(); break;
        case 4: _t->tabClick((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 5: _t->filtrerV(); break;
        case 6: _t->trierV(); break;
        case 7: _t->rechV(); break;
        case 8: _t->expoV(); break;
        default: ;
        }
    }
}

const QMetaObject *veh::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *veh::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSvehENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int veh::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
