/****************************************************************************
** Meta object code from reading C++ file 'AnaPencere.h'
**
** Created: Sun Mar 2 11:48:02 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AnaPencere.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnaPencere.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_AnaPencere[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AnaPencere[] = {
    "AnaPencere\0\0max\0setDialMax(int)\0"
};

const QMetaObject AnaPencere::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AnaPencere,
      qt_meta_data_AnaPencere, 0 }
};

const QMetaObject *AnaPencere::metaObject() const
{
    return &staticMetaObject;
}

void *AnaPencere::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnaPencere))
	return static_cast<void*>(const_cast< AnaPencere*>(this));
    if (!strcmp(_clname, "Ui::AnaPencere"))
	return static_cast< Ui::AnaPencere*>(const_cast< AnaPencere*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AnaPencere::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setDialMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}
