/****************************************************************************
** Meta object code from reading C++ file 'map_graphics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dotandbox_1_1/map_graphics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map_graphics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_map_graphics_t {
    QByteArrayData data[9];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_map_graphics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_map_graphics_t qt_meta_stringdata_map_graphics = {
    {
QT_MOC_LITERAL(0, 0, 12), // "map_graphics"
QT_MOC_LITERAL(1, 13, 13), // "refresh_score"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "set_turn"
QT_MOC_LITERAL(4, 37, 15), // "mousePressEvent"
QT_MOC_LITERAL(5, 53, 12), // "QMouseEvent*"
QT_MOC_LITERAL(6, 66, 1), // "e"
QT_MOC_LITERAL(7, 68, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(8, 86, 5) // "event"

    },
    "map_graphics\0refresh_score\0\0set_turn\0"
    "mousePressEvent\0QMouseEvent*\0e\0"
    "mouseReleaseEvent\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_map_graphics[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       3,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    8,

       0        // eod
};

void map_graphics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        map_graphics *_t = static_cast<map_graphics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refresh_score((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: _t->set_turn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (map_graphics::*_t)(uint , uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&map_graphics::refresh_score)) {
                *result = 0;
            }
        }
        {
            typedef void (map_graphics::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&map_graphics::set_turn)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject map_graphics::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_map_graphics.data,
      qt_meta_data_map_graphics,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *map_graphics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *map_graphics::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_map_graphics.stringdata0))
        return static_cast<void*>(const_cast< map_graphics*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int map_graphics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void map_graphics::refresh_score(uint _t1, uint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void map_graphics::set_turn(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
