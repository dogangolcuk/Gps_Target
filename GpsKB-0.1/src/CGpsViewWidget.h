/***************************************************************************
 *   Copyright (C) 2008 by Doğan Gölcük                                    *
 *   dogangolcuk@gmail.com                                                   *
 *                                                                         *
 ***************************************************************************/
#include "ui_IGpsViewWidget.h"
#include "SerialWidget.h"
#include <QSettings>
#include <QTimer>

class CGpsViewWidget:public SerialWidget, public Ui::IGpsViewWidget {
    Q_OBJECT
public:


    ~CGpsViewWidget() {
    }
    CGpsViewWidget() 
{

        setupUi(this);
// 	ayarlariHatirla(ports);
// if(fake){
//     		timer = new QTimer();
//   		connect(timer, SIGNAL(timeout()), this, SLOT(fakeGPRMC()));
//   		timer->start(3000);
// }
//         connect(PbKaydet,SIGNAL(clicked()),this,SLOT(Kaydet()));
 
      connect( this, SIGNAL( recvGPRMC(QString) ), this, SLOT(	setGPRMC(QString) )); 
// connect( CbGpsOff, SIGNAL( clicked() ), this, SLOT(	setGPRMC(QString) ));    
}

public:
//         QSettings ayarlar;
public slots:
    void setGPRMC(QString data)
{
// Gelen Veri
//           saat      enlem      boylam     sürat rota tarih 
// $GPRMC,203618,A,3650.221,N,02823.653,E,000.0,135,260208,000,W*69

             QStringList list = data.split(",");
             if(list[0]=="$GPRMC"){

	
// 		disconnect(timer);
	     	GpsSaat=list[1].insert(2, QString(":"));
		     GpsSaat=GpsSaat.insert(5, QString(":"));
		     GpsSaat=GpsSaat.append(QString(" Z"));

		GemiEnlem=list[3].insert(2," ");
		GemiEnlemYon=list[4];
		GemiEnlem=GemiEnlemYon+GemiEnlem;

		GemiBoylam=list[5].insert(3," ");
		GemiBoylamYon=list[6];
		GemiBoylam=GemiBoylamYon+GemiBoylam;

		GemiSurat=list[7];
		GemiRota=list[8];
		GpsTarih=list[9];
             	LeZaman->setText(GpsSaat);
             	LeEnlem->setText(GemiEnlem);
// 	     	LeEnlemYon->setText(GemiEnlemYon);
             	LeBoylam->setText(GemiBoylam);
//              	LeBoylamYon->setText(GemiBoylamYon);
// 	     	LeHiz->setText(GemiSurat);
double gemiSurat;
if(CbHizBirimi->currentText()=="KTS")
   gemiSurat=GemiSurat.toDouble();
if(CbHizBirimi->currentText()=="M/SN")
   gemiSurat=GemiSurat.toDouble()*0.5144;
	     LcdHiz->display(gemiSurat);

// 	     LeRota->setText(GemiRota);
LcdRota->display(GemiRota.toDouble());
             DeGpsTarih->setDate(QDate::fromString(GpsTarih, "ddMMyy"));
	}
          else return;

}
void fakeGPRMC()
{
QString enlem;
QString enlemYon;
enlemYon=LeEnlem->text().left(1);
enlem=LeEnlem->text().remove(0,1);
enlem=enlem.remove(" ");
QString boylam;
QString boylamYon;
boylamYon=LeBoylam->text().left(1);
boylam=LeBoylam->text().remove(0,1);
boylam=boylam.remove(" ");

QString fakeGPRMCDATA;
fakeGPRMCDATA.append("$GPRMC,203618,A,");
fakeGPRMCDATA.append(enlem+","+enlemYon+",");
fakeGPRMCDATA.append(boylam+","+boylamYon+",");
// fakeGPRMCDATA.append(LeHiz->text()+",");
// fakeGPRMCDATA.append(LeRota->text()+",260208,000,W*69");
emit recvGPRMC(fakeGPRMCDATA);
}
QString getEnlem(){
return GemiEnlem; 
}
QString getBoylam(){
return GemiBoylam; 
}
QString getEnlemYon(){
return GemiEnlemYon; 
}
QString getBoylamYon(){
return GemiBoylamYon; 
}
QString getGemiRota(){
return GemiRota; 
}
QString getGemiSurat(){
return GemiSurat; 
}
QString getSaat(){
return GpsSaat; 
}
QString getTarih(){
return GpsTarih; 
}
signals:

private:
QString GemiEnlem;
QString GemiEnlemYon;
QString GemiBoylam; 
QString GemiBoylamYon;
QString GpsSaat;
QString GemiRota;
QString GemiSurat;
QString GpsTarih;
QTimer *timer;
// void ayarlarDegisti(QList<int>);

};
