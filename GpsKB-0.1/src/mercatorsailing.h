/***************************************************************************
 *   Copyright (C) 2008 by Doğan Gölcük                                    *
 *   dogangolcuk@gmail.com                                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef MERCATORSAILING_H
#define MERCATORSAILING_H
#include <math.h>
#include <QString>
#include <QStringList>
#include <QDebug>

#define pi 3.14159265359
/*
#define	TODEG(r) 	((r) * 57.2957795131)	
#define TORAD(d)	((d) / 57.2957795131)	

#define	Sin(x)		sin(TORAD(x))		
#define	Cos(x)		cos(TORAD(x))		
#define	Tan(x)		tan(TORAD(x))	
#define	Asin(x)		TODEG(asin(x))		
#define	Acos(x)		TODEG(acos(x))		
#define	Atan(x)		TODEG(atan(x))		
#define	Atan2(x1, x2)	TODEG(atan2(x1, x2))	

*//////////


class mercatorsailing
{
// Q_OBJECT
public:

	mercatorsailing();
	double DegToRad(double derece);
	double RadToDeg(double radyan);
        double MeridyenParcasi(double derece);
	double dm2dd(QString lat_lon ,QString sign_in);//3234.42 , N
	QStringList RotaVeMesafe(QString, QString );
	QStringList DrMevkii(QString , double rota,double surat );
	QString toDMS(double derece,QString yon);
// double meridional_dist(double lat);
// double meridional_part(double lat);
//derece olarak enlem , boylam, rota , nm olarak mesafe;
bool destVincenty(double lat1, double lon1, double brng, double dist) ;
bool distVincenty(double lat1,double lon1,double lat2,double lon2) ;

void GPS_Math_Deg_To_DegMin(float v, qint32 *d, float *m);
void GPS_Math_DegMin_To_Deg(const qint32 d, const float m, float& deg);

/// convert a string to a longitude / latitude pair
/**
    The string has to match the format [N|S] ddd mm.sss [W|E] ddd mm.sss

    On error and not silent a messagebox is raised.

    @param str input string
    @param lon reference to store the output longitude [�]
    @param lat reference to store the output latitude [�]

*/
bool GPS_Math_Str_To_Deg(const QString& str, float& lon, float& lat, bool silent = false);

/// convert a longitude / latitude pair to a human readable string
/**
    The output format will be [N|S] ddd mm.sss [W|E] ddd mm.sss

    @param lon the input longitude in [�]
    @param lon the input latitude in [�]
    @param str reference to string to store resulting output
*/
void GPS_Math_Deg_To_Str(const float& lon, const float& lat, QString& str);
double OwnShipLat;//Kendi gemimizin enlemi derece olarak
double OwnShipLong;//Kendi gemimizin boylamı derece olarak
double BearingTo;//gemiden hedefe kerteriz
double BearingFrom;//hedeften gemiye kerteriz
double DistTo;//hedefe olan uzaklık
double DrShipLat;//Gemi dr olarak ilerletildiğinde enlem
double DrShipLong;//Gemi dr olarak ilerletildiğinde enlem


QString toDmsRakam;
QString toDmsYon;
private:


// signals:

// private slots:
};
#endif




