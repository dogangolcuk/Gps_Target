/****************************************************************************
** Meta object code from reading C++ file 'SerialWidget.h'
**
** Created: Sun Mar 6 23:17:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GpsKB-0.1/src/SerialWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SerialWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x05,
      42,   37,   13,   13, 0x05,
      67,   63,   13,   13, 0x05,
      84,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     107,   13,  103,   13, 0x0a,
     128,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SerialWidget[] = {
    "SerialWidget\0\0text\0recvText(QString)\0"
    "name\0newPortName(QString)\0max\0"
    "newMaxCount(int)\0recvGPRMC(QString)\0"
    "int\0portOpen(QList<int>)\0receiveMsg()\0"
};

const QMetaObject SerialWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SerialWidget,
      qt_meta_data_SerialWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SerialWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SerialWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SerialWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialWidget))
        return static_cast<void*>(const_cast< SerialWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SerialWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: recvText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: newPortName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: newMaxCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: recvGPRMC((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { int _r = portOpen((*reinterpret_cast< QList<int>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: receiveMsg(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SerialWidget::recvText(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialWidget::newPortName(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialWidget::newMaxCount(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialWidget::recvGPRMC(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
