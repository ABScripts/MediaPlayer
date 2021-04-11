/****************************************************************************
** Meta object code from reading C++ file 'mediaplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "include/models/mediaplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MediaPlayer_t {
    QByteArrayData data[9];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaPlayer_t qt_meta_stringdata_MediaPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MediaPlayer"
QT_MOC_LITERAL(1, 12, 15), // "durationChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "positionChanged"
QT_MOC_LITERAL(4, 45, 28), // "currentMediaFileTitleChanged"
QT_MOC_LITERAL(5, 74, 22), // "mediaStatusChangedSlot"
QT_MOC_LITERAL(6, 97, 21), // "currentMediaFileTitle"
QT_MOC_LITERAL(7, 119, 8), // "position"
QT_MOC_LITERAL(8, 128, 8) // "duration"

    },
    "MediaPlayer\0durationChanged\0\0"
    "positionChanged\0currentMediaFileTitleChanged\0"
    "mediaStatusChangedSlot\0currentMediaFileTitle\0"
    "position\0duration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       3,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00495003,
       7, QMetaType::QReal, 0x00495103,
       8, QMetaType::QReal, 0x00495001,

 // properties: notify_signal_id
       2,
       1,
       0,

       0        // eod
};

void MediaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MediaPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->durationChanged(); break;
        case 1: _t->positionChanged(); break;
        case 2: _t->currentMediaFileTitleChanged(); break;
        case 3: _t->mediaStatusChangedSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MediaPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayer::durationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MediaPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayer::positionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MediaPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayer::currentMediaFileTitleChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MediaPlayer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->m_CurrentMediaFileTitle; break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->getPosition(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->getDuration(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MediaPlayer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_CurrentMediaFileTitle != *reinterpret_cast< QString*>(_v)) {
                _t->m_CurrentMediaFileTitle = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->currentMediaFileTitleChanged();
            }
            break;
        case 1: _t->setPosition(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MediaPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MediaPlayer.data,
    qt_meta_data_MediaPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MediaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MediaPlayer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MediaPlayer::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MediaPlayer::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MediaPlayer::currentMediaFileTitleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
