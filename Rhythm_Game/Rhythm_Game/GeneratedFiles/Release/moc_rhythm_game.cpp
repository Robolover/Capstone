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
    QByteArrayData data[21];
    char stringdata[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rhythm_Game_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rhythm_Game_t qt_meta_stringdata_Rhythm_Game = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 11),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 13),
QT_MOC_LITERAL(4, 39, 15),
QT_MOC_LITERAL(5, 55, 11),
QT_MOC_LITERAL(6, 67, 11),
QT_MOC_LITERAL(7, 79, 9),
QT_MOC_LITERAL(8, 89, 17),
QT_MOC_LITERAL(9, 107, 19),
QT_MOC_LITERAL(10, 127, 10),
QT_MOC_LITERAL(11, 138, 9),
QT_MOC_LITERAL(12, 148, 6),
QT_MOC_LITERAL(13, 155, 14),
QT_MOC_LITERAL(14, 170, 13),
QT_MOC_LITERAL(15, 184, 15),
QT_MOC_LITERAL(16, 200, 5),
QT_MOC_LITERAL(17, 206, 3),
QT_MOC_LITERAL(18, 210, 3),
QT_MOC_LITERAL(19, 214, 4),
QT_MOC_LITERAL(20, 219, 11)
    },
    "Rhythm_Game\0click_event\0\0update_camera\0"
    "get_mouse_state\0intro_video\0enter_stage\0"
    "exit_game\0change_next_stage\0"
    "change_before_stage\0play_video\0play_game\0"
    "result\0video_function\0play_function\0"
    "answer_function\0apple\0bus\0cat\0duck\0"
    "finish_game"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rhythm_Game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    0,  121,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    0,  124,    2, 0x08 /* Private */,
      18,    0,  125,    2, 0x08 /* Private */,
      19,    0,  126,    2, 0x08 /* Private */,
      20,    0,  127,    2, 0x08 /* Private */,

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
    QMetaType::Void,

       0        // eod
};

void Rhythm_Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Rhythm_Game *_t = static_cast<Rhythm_Game *>(_o);
        switch (_id) {
        case 0: _t->click_event(); break;
        case 1: _t->update_camera(); break;
        case 2: _t->get_mouse_state(); break;
        case 3: _t->intro_video(); break;
        case 4: _t->enter_stage(); break;
        case 5: _t->exit_game(); break;
        case 6: _t->change_next_stage(); break;
        case 7: _t->change_before_stage(); break;
        case 8: _t->play_video(); break;
        case 9: _t->play_game(); break;
        case 10: _t->result(); break;
        case 11: _t->video_function(); break;
        case 12: _t->play_function(); break;
        case 13: _t->answer_function(); break;
        case 14: _t->apple(); break;
        case 15: _t->bus(); break;
        case 16: _t->cat(); break;
        case 17: _t->duck(); break;
        case 18: _t->finish_game(); break;
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
QT_END_MOC_NAMESPACE
