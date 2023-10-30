SOURCES += SerialWidget.cpp \
 dialogimpl.cpp \
 main.cpp \
 mercatorsailing.cpp \
 harita.cpp \
 posix_qextserialport.cpp \
 qextserialbase.cpp \
 qextserialport.cpp
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt
TARGET = ../bin/GpsKB

OBJECTS_DIR = obj

UI_DIR = ui

MOC_DIR = moc

HEADERS += SerialWidget.h \
dialogimpl.h \
 mercatorsailing.h \
 harita.h \
 CDlgNmeaGps.h \
 CGpsViewWidget.h \
 qextserialport.h \
 posix_qextserialport.h \
 qextserialbase.h
FORMS += AnaPencere.ui \
 IDlgNmeaGps.ui \
 IGpsViewWidget.ui
RESOURCES += images.qrc

QT += sql







