/***************************************************************************
 *   Copyright (C) 2008 by Doğan Gölcük                                    *
 *   dogangolcuk@gmail.com                                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef CDLGNMEAGPS_H
#define CDLGNMEAGPS_H
#include "ui_IDlgNmeaGps.h"
#include <QSettings>

class CDlgNmeaGps:public QWidget, public Ui::IDlgNmeaGps {
    Q_OBJECT
public:


    ~CDlgNmeaGps() {

    }
    CDlgNmeaGps() 
{

        setupUi(this);
// 	ayarlariHatirla(ports);
        connect(PbKaydet,SIGNAL(clicked()),this,SLOT(Kaydet()));
    }

public:
        QSettings ayarlar;
public slots:
    void Kaydet() {
 
                ayarlar.setValue("DataBits",CbDataBits->currentIndex());
		ayarlar.setValue("Parity",CbParity->currentIndex());
		ayarlar.setValue("FlowControl",CbFlowControl->currentIndex());
		ayarlar.setValue("StopBits",CbStopBits->currentIndex());
                ayarlar.setValue("BaudRate",CbBaudRate->currentIndex());
// 		ayarlar.setValue("Com",ComDial->value());
		ayarlar.setValue("CCom",CbPorts->currentIndex());
                emit ayarlarDegisti(getAyarlar());

    }

void ayarlariHatirla(QStringList ports)
{
	  CbPorts->addItems(ports);
          QList<int> index = getAyarlar();
          CbDataBits->setCurrentIndex(index[0]);
	  CbParity->setCurrentIndex(index[1]);
	  CbFlowControl->setCurrentIndex(index[2]);
          CbStopBits->setCurrentIndex(index[3]);
          CbBaudRate->setCurrentIndex(index[4]);
	  CbPorts->setCurrentIndex(index[5]);	
//           ComDial->setValue(index[5]);
}
QList<int> getAyarlar()
{

QList<int> index;
index.append(ayarlar.value("DataBits").toInt());
index.append(ayarlar.value("Parity").toInt());
index.append(ayarlar.value("FlowControl").toInt());
index.append(ayarlar.value("StopBits").toInt());
index.append(ayarlar.value("BaudRate").toInt());
// index.append(ayarlar.value("Com").toInt());
index.append(ayarlar.value("CCom").toInt());
return index;
}
signals:
void ayarlarDegisti(QList<int>);

};
#endif