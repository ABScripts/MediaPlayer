/****************************************************************************
** Meta object code from reading C++ file 'mediaplayer_enums.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "include/mediaplayer_enums.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplayer_enums.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MediaPlayerEnums_t {
    QByteArrayData data[15];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaPlayerEnums_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaPlayerEnums_t qt_meta_stringdata_MediaPlayerEnums = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MediaPlayerEnums"
QT_MOC_LITERAL(1, 17, 12), // "PlayerStatus"
QT_MOC_LITERAL(2, 30, 4), // "None"
QT_MOC_LITERAL(3, 35, 10), // "SwitchPlay"
QT_MOC_LITERAL(4, 46, 7), // "Playing"
QT_MOC_LITERAL(5, 54, 6), // "Paused"
QT_MOC_LITERAL(6, 61, 7), // "Stopped"
QT_MOC_LITERAL(7, 69, 10), // "PlayerMode"
QT_MOC_LITERAL(8, 80, 10), // "SwitchMode"
QT_MOC_LITERAL(9, 91, 8), // "Sequence"
QT_MOC_LITERAL(10, 100, 6), // "Repeat"
QT_MOC_LITERAL(11, 107, 7), // "Shuffle"
QT_MOC_LITERAL(12, 115, 11), // "SectionTabs"
QT_MOC_LITERAL(13, 127, 7), // "Library"
QT_MOC_LITERAL(14, 135, 9) // "Playlists"

    },
    "MediaPlayerEnums\0PlayerStatus\0None\0"
    "SwitchPlay\0Playing\0Paused\0Stopped\0"
    "PlayerMode\0SwitchMode\0Sequence\0Repeat\0"
    "Shuffle\0SectionTabs\0Library\0Playlists"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaPlayerEnums[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       3,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    5,   29,
       7,    7, 0x0,    4,   39,
      12,   12, 0x0,    2,   47,

 // enum data: key, value
       2, uint(MediaPlayerEnums::None),
       3, uint(MediaPlayerEnums::SwitchPlay),
       4, uint(MediaPlayerEnums::Playing),
       5, uint(MediaPlayerEnums::Paused),
       6, uint(MediaPlayerEnums::Stopped),
       8, uint(MediaPlayerEnums::SwitchMode),
       9, uint(MediaPlayerEnums::Sequence),
      10, uint(MediaPlayerEnums::Repeat),
      11, uint(MediaPlayerEnums::Shuffle),
      13, uint(MediaPlayerEnums::Library),
      14, uint(MediaPlayerEnums::Playlists),

       0        // eod
};

void MediaPlayerEnums::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MediaPlayerEnums::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MediaPlayerEnums.data,
    qt_meta_data_MediaPlayerEnums,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MediaPlayerEnums::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayerEnums::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MediaPlayerEnums.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaPlayerEnums::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
