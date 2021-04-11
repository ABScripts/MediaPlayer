/****************************************************************************
** Meta object code from reading C++ file 'mediaplayer_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "include/controllers/mediaplayer_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplayer_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MediaPlayerController_t {
    QByteArrayData data[20];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaPlayerController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaPlayerController_t qt_meta_stringdata_MediaPlayerController = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MediaPlayerController"
QT_MOC_LITERAL(1, 22, 6), // "paused"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "playing"
QT_MOC_LITERAL(4, 38, 7), // "stopped"
QT_MOC_LITERAL(5, 46, 10), // "repeatMode"
QT_MOC_LITERAL(6, 57, 12), // "sequenceMode"
QT_MOC_LITERAL(7, 70, 11), // "shuffleMode"
QT_MOC_LITERAL(8, 82, 19), // "shuffleModeDisabled"
QT_MOC_LITERAL(9, 102, 15), // "durationChanged"
QT_MOC_LITERAL(10, 118, 15), // "positionChanged"
QT_MOC_LITERAL(11, 134, 16), // "getNextMediaFile"
QT_MOC_LITERAL(12, 151, 20), // "getPreviousMediaFile"
QT_MOC_LITERAL(13, 172, 10), // "setNewSong"
QT_MOC_LITERAL(14, 183, 12), // "changeStatus"
QT_MOC_LITERAL(15, 196, 6), // "status"
QT_MOC_LITERAL(16, 203, 16), // "changePlayerMode"
QT_MOC_LITERAL(17, 220, 4), // "mode"
QT_MOC_LITERAL(18, 225, 4), // "seek"
QT_MOC_LITERAL(19, 230, 8) // "position"

    },
    "MediaPlayerController\0paused\0\0playing\0"
    "stopped\0repeatMode\0sequenceMode\0"
    "shuffleMode\0shuffleModeDisabled\0"
    "durationChanged\0positionChanged\0"
    "getNextMediaFile\0getPreviousMediaFile\0"
    "setNewSong\0changeStatus\0status\0"
    "changePlayerMode\0mode\0seek\0position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaPlayerController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,
       8,    0,   95,    2, 0x06 /* Public */,
       9,    0,   96,    2, 0x06 /* Public */,
      10,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    1,  101,    2, 0x0a /* Public */,
      16,    1,  104,    2, 0x0a /* Public */,
      18,    1,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Double,   19,

       0        // eod
};

void MediaPlayerController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MediaPlayerController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paused(); break;
        case 1: _t->playing(); break;
        case 2: _t->stopped(); break;
        case 3: _t->repeatMode(); break;
        case 4: _t->sequenceMode(); break;
        case 5: _t->shuffleMode(); break;
        case 6: _t->shuffleModeDisabled(); break;
        case 7: _t->durationChanged(); break;
        case 8: _t->positionChanged(); break;
        case 9: _t->getNextMediaFile(); break;
        case 10: _t->getPreviousMediaFile(); break;
        case 11: _t->setNewSong(); break;
        case 12: _t->changeStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->changePlayerMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->seek((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MediaPlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayerController::paused)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MediaPlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayerController::playing)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MediaPlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayerController::stopped)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MediaPlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayerController::repeatMode)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MediaPlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayerController::sequenceMode)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MediaPlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayerController::shuffleMode)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MediaPlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayerController::shuffleModeDisabled)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MediaPlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayerController::durationChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MediaPlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayerController::positionChanged)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MediaPlayerController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MediaPlayerController.data,
    qt_meta_data_MediaPlayerController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MediaPlayerController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayerController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MediaPlayerController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaPlayerController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void MediaPlayerController::paused()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MediaPlayerController::playing()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MediaPlayerController::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MediaPlayerController::repeatMode()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MediaPlayerController::sequenceMode()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MediaPlayerController::shuffleMode()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MediaPlayerController::shuffleModeDisabled()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MediaPlayerController::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MediaPlayerController::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
