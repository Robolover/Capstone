/****************************************************************************
** Meta object code from reading C++ file 'rhythm_game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rhythm_game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rhythm_game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Rhythm_Game_t {
    QByteArrayData data[20];
    char stringdata[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rhythm_Game_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rhythm_Game_t qt_meta_stringdata_Rhythm_Game = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 13),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 11),
QT_MOC_LITERAL(4, 39, 11),
QT_MOC_LITERAL(5, 51, 11),
QT_MOC_LITERAL(6, 63, 9),
QT_MOC_LITERAL(7, 73, 17),
QT_MOC_LITERAL(8, 91, 19),
QT_MOC_LITERAL(9, 111, 10),
QT_MOC_LITERAL(10, 122, 9),
QT_MOC_LITERAL(11, 132, 6),
QT_MOC_LITERAL(12, 139, 14),
QT_MOC_LITERAL(13, 154, 13),
QT_MOC_LITERAL(14, 168, 15),
QT_MOC_LITERAL(15, 184, 5),
QT_MOC_LITERAL(16, 190, 3),
QT_MOC_LITERAL(17, 194, 3),
QT_MOC_LITERAL(18, 198, 4),
QT_MOC_LITERAL(19, 203, 11)
    },
    "Rhythm_Game\0update_camera\0\0click_event\0"
    "intro_video\0enter_stage\0exit_game\0"
    "change_next_stage\0change_before_stage\0"
    "play_video\0play_game\0result\0video_function\0"
    "play_function\0answer_function\0apple\0"
    "bus\0cat\0duck\0finish_game"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rhythm_Game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Rhythm_Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Rhythm_Game *_t = static_cast<Rhythm_Game *>(_o);
        switch (_id) {
        case 0: _t->update_camera(); break;
        case 1: _t->click_event(); break;
        case 2: _t->intro_video(); break;
        case 3: _t->enter_stage(); break;
        case 4: _t->exit_game(); break;
        case 5: _t->change_next_stage(); break;
        case 6: _t->change_before_stage(); break;
        case 7: _t->play_video(); break;
        case 8: _t->play_game(); break;
        case 9: _t->result(); break;
        case 10: _t->video_function(); break;
        case 11: _t->play_function(); break;
        case 12: _t->answer_function(); break;
        case 13: _t->apple(); break;
        case 14: _t->bus(); break;
        case 15: _t->cat(); break;
        case 16: _t->duck(); break;
        case 17: _t->finish_game(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Rhythm_Game::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Rhythm_Game.data,
      qt_meta_data_Rhythm_Game,  qt_static_metacall, 0, 0}
};


const QMetaObject *Rhythm_Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rhythm_Game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Rhythm_Game.stringdata))
        return static_cast<void*>(const_cast< Rhythm_Game*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Rhythm_Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
