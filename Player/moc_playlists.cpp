/****************************************************************************
** Meta object code from reading C++ file 'playlists.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "include/models/playlists.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlists.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Playlists_t {
    QByteArrayData data[14];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Playlists_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Playlists_t qt_meta_stringdata_Playlists = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Playlists"
QT_MOC_LITERAL(1, 10, 27), // "currentSelectedIndexChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "nameAlreadyTaken"
QT_MOC_LITERAL(4, 56, 25), // "mediafileAddedSuccesfully"
QT_MOC_LITERAL(5, 82, 3), // "add"
QT_MOC_LITERAL(6, 86, 4), // "name"
QT_MOC_LITERAL(7, 91, 18), // "addMediaToPlaylist"
QT_MOC_LITERAL(8, 110, 14), // "mediafileIndex"
QT_MOC_LITERAL(9, 125, 12), // "playlistName"
QT_MOC_LITERAL(10, 138, 23), // "deleteMediaFromPLaylist"
QT_MOC_LITERAL(11, 162, 16), // "setPlaylistMedia"
QT_MOC_LITERAL(12, 179, 5), // "index"
QT_MOC_LITERAL(13, 185, 20) // "cirrentSelectedIndex"

    },
    "Playlists\0currentSelectedIndexChanged\0"
    "\0nameAlreadyTaken\0mediafileAddedSuccesfully\0"
    "add\0name\0addMediaToPlaylist\0mediafileIndex\0"
    "playlistName\0deleteMediaFromPLaylist\0"
    "setPlaylistMedia\0index\0cirrentSelectedIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Playlists[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   52,    2, 0x02 /* Public */,
       7,    2,   55,    2, 0x02 /* Public */,
      10,    1,   60,    2, 0x02 /* Public */,
      11,    1,   63,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   12,

 // properties: name, type, flags
      13, QMetaType::Int, 0x00495003,

 // properties: notify_signal_id
       0,

       0        // eod
};

void Playlists::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Playlists *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentSelectedIndexChanged(); break;
        case 1: _t->nameAlreadyTaken(); break;
        case 2: _t->mediafileAddedSuccesfully(); break;
        case 3: _t->add((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->addMediaToPlaylist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->deleteMediaFromPLaylist((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setPlaylistMedia((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Playlists::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Playlists::currentSelectedIndexChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Playlists::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Playlists::nameAlreadyTaken)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Playlists::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Playlists::mediafileAddedSuccesfully)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Playlists *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->m_CurrentSelectedIndex; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Playlists *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_CurrentSelectedIndex != *reinterpret_cast< int*>(_v)) {
                _t->m_CurrentSelectedIndex = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->currentSelectedIndexChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Playlists::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_Playlists.data,
    qt_meta_data_Playlists,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Playlists::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Playlists::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Playlists.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int Playlists::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Playlists::currentSelectedIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Playlists::nameAlreadyTaken()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Playlists::mediafileAddedSuccesfully()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
