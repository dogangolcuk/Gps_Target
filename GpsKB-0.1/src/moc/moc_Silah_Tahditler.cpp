/****************************************************************************
** Meta object code from reading C++ file 'Silah_Tahditler.h'
**
** Created: Sun May 4 20:10:30 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Silah_Tahditler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Silah_Tahditler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_SilahTahditler[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      43,   15,   35,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SilahTahditler[] = {
    "SilahTahditler\0\0tahditleriGoster()\0"
    "QString\0pruva()\0"
};

const QMetaObject SilahTahditler::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SilahTahditler,
      qt_meta_data_SilahTahditler, 0 }
};

const QMetaObject *SilahTahditler::metaObject() const
{
    return &staticMetaObject;
}

void *SilahTahditler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SilahTahditler))
	return static_cast<void*>(const_cast< SilahTahditler*>(this));
    if (!strcmp(_clname, "Ui::Pencere_Tahditler"))
	return static_cast< Ui::Pencere_Tahditler*>(const_cast< SilahTahditler*>(this));
    return QWidget::qt_metacast(_clname);
}

int SilahTahditler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: tahditleriGoster(); break;
        case 1: { QString _r = pruva();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        }
        _id -= 2;
    }
    return _id;
}
