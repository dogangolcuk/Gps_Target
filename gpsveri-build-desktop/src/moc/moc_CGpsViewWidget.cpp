/****************************************************************************
** Meta object code from reading C++ file 'CGpsViewWidget.h'
**
** Created: Sun Mar 6 23:18:04 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GpsKB-0.1/src/CGpsViewWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CGpsViewWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CGpsViewWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x0a,
      39,   15,   15,   15, 0x0a,
      59,   15,   51,   15, 0x0a,
      70,   15,   51,   15, 0x0a,
      82,   15,   51,   15, 0x0a,
      96,   15,   51,   15, 0x0a,
     111,   15,   51,   15, 0x0a,
     125,   15,   51,   15, 0x0a,
     140,   15,   51,   15, 0x0a,
     150,   15,   51,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CGpsViewWidget[] = {
    "CGpsViewWidget\0\0data\0setGPRMC(QString)\0"
    "fakeGPRMC()\0QString\0getEnlem()\0"
    "getBoylam()\0getEnlemYon()\0getBoylamYon()\0"
    "getGemiRota()\0getGemiSurat()\0getSaat()\0"
    "getTarih()\0"
};

const QMetaObject CGpsViewWidget::staticMetaObject = {
    { &SerialWidget::staticMetaObject, qt_meta_stringdata_CGpsViewWidget,
      qt_meta_data_CGpsViewWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CGpsViewWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CGpsViewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CGpsViewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CGpsViewWidget))
        return static_cast<void*>(const_cast< CGpsViewWidget*>(this));
    if (!strcmp(_clname, "Ui::IGpsViewWidget"))
        return static_cast< Ui::IGpsViewWidget*>(const_cast< CGpsViewWidget*>(this));
    return SerialWidget::qt_metacast(_clname);
}

int CGpsViewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SerialWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setGPRMC((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: fakeGPRMC(); break;
        case 2: { QString _r = getEnlem();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QString _r = getBoylam();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QString _r = getEnlemYon();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = getBoylamYon();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QString _r = getGemiRota();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { QString _r = getGemiSurat();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { QString _r = getSaat();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { QString _r = getTarih();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
