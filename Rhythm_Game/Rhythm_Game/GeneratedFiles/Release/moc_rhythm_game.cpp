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
    QByteArrayData data[11];
    char stringdata[135];
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
QT_MOC_LITERAL(3, 27, 12),
QT_MOC_LITERAL(4, 40, 11),
QT_MOC_LITERAL(5, 52, 11),
QT_MOC_LITERAL(6, 64, 17),
QT_MOC_LITERAL(7, 82, 19),
QT_MOC_LITERAL(8, 102, 11),
QT_MOC_LITERAL(9, 114, 9),
QT_MOC_LITERAL(10, 124, 10)
    },
    "Rhythm_Game\0update_camera\0\0start_button\0"
    "exit_button\0return_main\0change_next_stage\0"
    "change_before_stage\0chose_stage\0"
    "play_game\0next_stage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rhythm_Game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void Rhythm_Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Rhythm_Game *_t = static_cast<Rhythm_Game *>(_o);
        switch (_id) {
        case 0: _t->update_camera(); break;
        case 1: _t->start_button(); break;
        case 2: _t->exit_button(); break;
        case 3: _t->return_main(); break;
        case 4: _t->change_next_stage(); break;
        case 5: _t->change_before_stage(); break;
        case 6: _t->chose_stage(); break;
        case 7: _t->play_game(); break;
        case 8: _t->next_stage(); break;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
