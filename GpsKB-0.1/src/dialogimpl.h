#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include "ui_AnaPencere.h"
#include <QSettings>
#include <math.h>
#include "mercatorsailing.h"
#include "harita.h"
#include "CGpsViewWidget.h"
#include "CDlgNmeaGps.h"
#include <QGraphicsView>
#include <QImage>
#include <QPixmap>
#include <QDataWidgetMapper>
#include <QtSql>
#include <QFileDialog>
#include <QMessageBox>
#include <QHeaderView>
#include <QProgressDialog>
#include <QSettings>
// #include <QLineF>

//



class DialogImpl : public QMainWindow, public Ui::AnaPencere
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	CGpsViewWidget* gpsview;
	CDlgNmeaGps* DlgGps;
	mercatorsailing msail;
// 	QGraphicsView *view;
//         QGraphicsScene *scene;
//         QImage mercharita;
// 	QPixmap res;

	QSqlQueryModel *model;
	QItemSelectionModel *selectionModel ;
        QDataWidgetMapper *mapper ;
QSqlDatabase  db;
QSettings setting;
// QSqlDatabase db;

private:
// QString GemiEnlem;
// QString GemiEnlemYon;
// QString GemiBoylam; 
// QString GemiBoylamYon;
// QString GpsSaat;
// QString GemiRota;
// QString GemiSurat;
// QString GpsTarih;

QString hedefEnlem;
QString hedefEnlemYon;
QString hedefBoylam;
QString hedefBoylamYon;

QString hedefeKerteriz;
QString hedefeMesafe;

QString arsivYolu;

public slots:
void hesapla();
void DrHesapla();
void getKayitYolu();


signals:



private slots:
};
#endif




