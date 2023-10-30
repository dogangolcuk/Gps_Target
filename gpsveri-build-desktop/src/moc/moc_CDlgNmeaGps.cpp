/****************************************************************************
** Meta object code from reading C++ file 'CDlgNmeaGps.h'
**
** Created: Sun Mar 6 23:18:02 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GpsKB-0.1/src/CDlgNmeaGps.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CDlgNmeaGps.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDlgNmeaGps[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   12,   12,   12, 0x0a,
      55,   49,   12,   12, 0x0a,
      95,   12,   84,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDlgNmeaGps[] = {
    "CDlgNmeaGps\0\0ayarlarDegisti(QList<int>)\0"
    "Kaydet()\0ports\0ayarlariHatirla(QStringList)\0"
    "QList<int>\0getAyarlar()\0"
};

const QMetaObject CDlgNmeaGps::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CDlgNmeaGps,
      qt_meta_data_CDlgNmeaGps, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDlgNmeaGps::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDlgNmeaGps::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDlgNmeaGps::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDlgNmeaGps))
        return static_cast<void*>(const_cast< CDlgNmeaGps*>(this));
    if (!strcmp(_clname, "Ui::IDlgNmeaGps"))
        return static_cast< Ui::IDlgNmeaGps*>(const_cast< CDlgNmeaGps*>(this));
    return QWidget::qt_metacast(_clname);
}

int CDlgNmeaGps::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ayarlarDegisti((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 1: Kaydet(); break;
        case 2: ayarlariHatirla((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: { QList<int> _r = getAyarlar();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CDlgNmeaGps::ayarlarDegisti(QList<int> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
