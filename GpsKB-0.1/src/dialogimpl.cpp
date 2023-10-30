#include "dialogimpl.h"
#include <QDebug>
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{

        arsivYolu=setting.value("arsivYolu").toString();
if(!QFile::exists(arsivYolu))
getKayitYolu();

 	 db = QSqlDatabase::addDatabase("QSQLITE");
         db.setDatabaseName(arsivYolu);
 if(db.open())
         		 qDebug("Veritabani baglandi");

setupUi(this);

        model = new QSqlQueryModel;






	model->setQuery ( "SELECT id,saat, gemienlem,gemiboylam,gemirotasi,gemisurat,hedefenlem,hedefboylam,hedefkerterizi,hedefmesafesi,silahdrisa,silahirtifa,bhaadrisa FROM kb" );
	tablo->setModel( model );


        selectionModel = tablo->selectionModel();

	tablo->horizontalHeader()->setResizeMode ( QHeaderView::ResizeToContents );
	
model->setHeaderData ( 1, Qt::Horizontal, trUtf8 ( "Zaman" ) );
	model->setHeaderData ( 2, Qt::Horizontal, trUtf8 ( "Gemi Enlemı" ) );
	model->setHeaderData ( 3, Qt::Horizontal, trUtf8 ( "Gemi Boylamı" ) );
model->setHeaderData ( 4, Qt::Horizontal, trUtf8 ( "Gemi Rotası" ) );
model->setHeaderData ( 5, Qt::Horizontal, trUtf8 ( "Gemi Sürati KTS" ) );
model->setHeaderData ( 6, Qt::Horizontal, trUtf8 ( "Hedef Enlemi" ) );
model->setHeaderData ( 7, Qt::Horizontal, trUtf8 ( "Hedef Boylamı" ) );
model->setHeaderData ( 8, Qt::Horizontal, trUtf8 ( "Hedef Kerterizi" ) );
model->setHeaderData ( 9, Qt::Horizontal, trUtf8 ( "Hedef Mesafesi NM" ) );
model->setHeaderData ( 10, Qt::Horizontal, trUtf8 ( "Silah Drisa" ) );
model->setHeaderData ( 11, Qt::Horizontal, trUtf8 ( "Silah İrtifa" ) );
model->setHeaderData ( 12, Qt::Horizontal, trUtf8 ( "BHAa Drisa" ) );
	tablo->show();

gpsview = new CGpsViewWidget;
	QHBoxLayout *layout = new QHBoxLayout;
    	layout->addWidget(gpsview);
    	GpsYuva->setLayout(layout);

DlgGps = new CDlgNmeaGps;//seri port ayarları burda yapılsın.
DlgGps->ayarlariHatirla(gpsview->tryAllComs());//Daha önceki kaydettiğimiz ayarlar yerli yerinde olsun.	
gpsview->portOpen(DlgGps->getAyarlar());//Anapencere açıldığında seri porttan veri almaya başlasın.

connect( PbHesapla ,SIGNAL( pressed() ), this, SLOT( DrHesapla() ) );
connect( gpsview, SIGNAL( recvText(QString) ), DlgGps->TeRecieveData, SLOT(insertPlainText(QString) ), Qt::DirectConnection ); 
connect( actionSerialConfig, SIGNAL( activated() ), DlgGps, SLOT( show() ) );
connect( actionKay_t_Yolu, SIGNAL( activated() ), this, SLOT( getKayitYolu() ) );
//ayarlar değişince yeniden port aç.ayarlar liste halinde gelsin.
connect( DlgGps ,SIGNAL( ayarlarDegisti(QList<int>) ), gpsview, SLOT( portOpen(QList<int>) ) );
QTimer *timer = new QTimer();
connect(timer, SIGNAL(timeout()), this, SLOT(hesapla()));
timer->start(3000);
//  db= QSqlDatabase::addDatabase("QSQLITE");;
}
void DialogImpl::getKayitYolu()
{
 QSqlDatabase::removeDatabase("");
	QFileDialog dialog;
	dialog.setFileMode ( QFileDialog::DirectoryOnly );
	QString yol = dialog.getSaveFileName (
	                  this,
	                  QString::fromUtf8 ( "Kayıt Yapılacak Dosya Adı " ),
	                  "/home");
//              tmpop = new xmlop();
        QFile::copy( "/tmp/kbveriler" , yol);
//              delete tmpop;
	arsivYolu = yol;
 setting.setValue("arsivYolu",yol);
//  db 
// db = new QSqlDatabase;
db= QSqlDatabase::addDatabase("QSQLITE");
          db.setDatabaseName(arsivYolu);
          if(db.open())
          		 qDebug("Veritabani baglandi");


// 	label->setText ( arsivYolu );
// return yol;

}
/*
void DialogImpl::scen()
{

mercharita=  QImage(QDir::homePath() + "/2211yeni.jpg");
int yimage=mercharita.height();
int ximage=mercharita.width();
res = QPixmap::fromImage(mercharita);

scene = new Harita();
scene->setSceneRect(QRectF(0, 0, ximage, yimage));
scene->addPixmap(res);

    QHBoxLayout *layout = new QHBoxLayout;
//     layout->addWidget(fr);
    view = new QGraphicsView(scene);
//     view->scale(0.2,0.2);
    layout->addWidget(view);

//     QWidget *widget = new QWidget;
//     widget->setLayout(layout);
// widget->show();
    har->setLayout(layout);


}
*/
void DialogImpl::hesapla()
{

QString GemiEnlem;
QString GemiEnlemYon;
QString GemiBoylam;
QString GemiBoylamYon;
QString GemiSurat;
QString GemiRota;
QString GpsSaat;

		GemiEnlem=gpsview->getEnlem();
		GemiEnlemYon=gpsview->getEnlemYon();
		GemiBoylam=gpsview->getBoylam();
		GemiBoylamYon=gpsview->getBoylamYon();
                GemiSurat=gpsview->getGemiSurat();
	     	GemiRota=gpsview->getGemiRota();
		GpsSaat=gpsview->getSaat();



		hedefEnlem=LeHedefEnlem->text();//N43 34.875
// qDebug()<<GemiEnlem;
// hedefEnlemYon=LeHedefEnlemYon->text();
		hedefBoylam=LeHedefBoylam->text();
// hedefBoylamYon=LeHedefBoylamYon->text();

// msail.RotaVeMesafe("4137.050","N","02645.875","E", "4037.034","N","12944.367","W");

//Kerteriz ve Mesafe   
QStringList tmp=msail.RotaVeMesafe(GemiEnlem+" "+GemiBoylam,hedefEnlem+" "+hedefBoylam);

hedefeKerteriz=tmp[0];
hedefeMesafe=tmp[1];//NM olarak
double hedefMesafesi;
if(CbUzunlukBirimi->currentText()=="NM")
  hedefMesafesi=tmp[1].toDouble();
if(CbUzunlukBirimi->currentText()=="MT")
  hedefMesafesi=tmp[1].toDouble()*1852;
if(CbUzunlukBirimi->currentText()=="KM")
  hedefMesafesi=tmp[1].toDouble()*1.852;
if(CbUzunlukBirimi->currentText()=="YD")
  hedefMesafesi=tmp[1].toDouble()*2027;




LeKerteriz->setText(tmp[0]);
// LcdKerteriz->display(tmp[0]);
// qDebug()<<tmp[0];
// LcdMesafe->display(hedefMesafesi);
LeMesafe->setText(QString("%1").arg(hedefMesafesi));
// LeMesafeMetre->setText(QString("%1").arg(tmp[1].toDouble()*1852)+" Metre" );
// QStringList Dreb=msail.DrMevkii("4333.333","N","02300.228","E",90,2.666);
// float lon,lat;
// msail.GPS_Math_Str_To_Deg("N43 00.000 E02300.228", lon, lat, false);
// QString degstr=QString("%1").arg(lat);
// qDebug()<<degstr;
// qDebug()<<msail.toDMS(Dreb.at(1).toDouble(),"EW");

if(ChbVeri->isChecked()){
// db.transaction();
QSqlQuery insert;
insert.prepare ( "INSERT INTO kb (saat, gemienlem,gemiboylam,gemirotasi,gemisurat,hedefenlem,hedefboylam,hedefkerterizi,hedefmesafesi,silahdrisa,silahirtifa,bhaadrisa) "
		                 "VALUES (:1, :2, :3,:4,:5,:6,:7,:8,:9,:10,:11,:12)" );
		insert.bindValue ( ":1", GpsSaat );
		insert.bindValue ( ":2", GemiEnlem);
		insert.bindValue ( ":3", GemiBoylam);
insert.bindValue ( ":4", GemiRota );
insert.bindValue ( ":5", GemiSurat );
insert.bindValue ( ":6", hedefEnlem);
insert.bindValue ( ":7", hedefBoylam);
insert.bindValue ( ":8", hedefeKerteriz );
insert.bindValue ( ":9", hedefeMesafe );
insert.bindValue ( ":10", "" );
insert.bindValue ( ":11", "" );
insert.bindValue ( ":12", "" );
if ( insert.exec() ) {
model->setQuery ( "SELECT id,saat, gemienlem,gemiboylam,gemirotasi,gemisurat,hedefenlem,hedefboylam,hedefkerterizi,hedefmesafesi,silahdrisa,silahirtifa,bhaadrisa FROM kb ORDER BY id DESC" );
	model->query();
// db.commit();
//birşey yapmalı hey....
}
}
// insert.bindValue ( ":3", GemiBoylam+GemiBoylamYon );
// insert.bindValue ( ":3", GemiBoylam+GemiBoylamYon );
// insert.bindValue ( ":3", GemiBoylam+GemiBoylamYon );
// insert.bindValue ( ":3", GemiBoylam+GemiBoylamYon );
// insert.bindValue ( ":3", GemiBoylam+GemiBoylamYon );



}
void DialogImpl::DrHesapla()
{
QString GemiEnlem=gpsview->getEnlem();
// QString GemiEnlemYon=gpsview->getEnlemYon();
QString GemiBoylam=gpsview->getBoylam();
QString GemiSaat=gpsview->getSaat();
// QString GemiBoylamYon=gpsview->getBoylamYon();
// LwDr->clear();
TeDr->clear();
TeDr->append("KB Sürüm 0.1 "+GemiSaat);

double rota = gpsview->getGemiRota().toDouble();
double hiz= gpsview->getGemiSurat().toDouble();
double dksonra = LeDkSonra->text().toDouble()/3600.0;//mesela 30 saniye 0.0083 saat yapar
double gidilecekmesafe=hiz*dksonra;//dakikasonra=1 için 1 saat te alınacak mesafe .(hız kts olarak geldiğinden )
QStringList ilerlet;
// QStringList ilerletBoylam;
QString drEnlem;
QString drBoylam;
QString drEnlemYon;
QString drBoylamYon;
double zamanAralik;
zamanAralik=0.;
for(int i=0;i<30;i++)//
{
zamanAralik=zamanAralik+dksonra;
gidilecekmesafe=hiz*zamanAralik;

QStringList Dreb=msail.DrMevkii(GemiEnlem+" "+GemiBoylam,rota,gidilecekmesafe);
QString drMevki;

// drEnlem=msail.toDmsRakam;
// drEnlemYon=msail.toDmsYon;


// drBoylam=msail.toDmsRakam;
// drBoylamYon=msail.toDmsYon;
drMevki=msail.toDMS(Dreb.at(0).toDouble(),"NS")+" "+msail.toDMS(Dreb.at(1).toDouble(),"EW");


QStringList tmp=msail.RotaVeMesafe(drMevki, hedefEnlem+" "+hedefBoylam);

QString Kerteriz=tmp[0];
QString Mesafe=tmp[1];//NM olarak
double yarda=Mesafe.toDouble();
yarda=yarda*2027.;
Mesafe=QString("%1 Yarda").arg(yarda);
QString GMesafe=QString("%1 Nm").arg(gidilecekmesafe);

// ilerlet.append(drEnlem+drEnlemYon+" "+drBoylam+drBoylamYon+" Hedefe Kerterizi: "+Kerteriz+" Hedef Mesafesi : "+Mesafe+" Geminin Gidecegi mesafe: "+GMesafe);
TeDr->append(drMevki+" Hedef Kerterizi: "+Kerteriz+" Hedef Mesafesi : "+Mesafe+" Geminin Gidecegi mesafe: "+GMesafe);

}

}

