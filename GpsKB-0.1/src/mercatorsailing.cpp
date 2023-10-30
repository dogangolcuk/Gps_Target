/***************************************************************************
 *   Copyright (C) 2008 by Doğan Gölcük                                    *
 *   dogangolcuk@gmail.com                                                   *
 *                                                                         *
 ***************************************************************************/
#include "mercatorsailing.h"

mercatorsailing::mercatorsailing()
{


}

double mercatorsailing::DegToRad(double derece)
{
 double conv_factor = (2.0 * pi)/360.0;
 double radyan= derece * conv_factor; 
 return radyan;
// qDebug("degtorad değeri %f",y);

}

double mercatorsailing::RadToDeg(double radyan)
{
 double conv_factor = 360/(2.0 * pi);
 double derece= radyan * conv_factor; 
 return derece;
// qDebug("degtorad değeri %f",y);

}

double mercatorsailing::MeridyenParcasi(double derece)
{
 //radyan olarak enlem
 double enlem = DegToRad(derece);
// float lat= derece;
 	// Set up "Constants" (as specified in Bowditch, page 552)
		// (a) Equatorial radius Y2Enlem(double yimage)of earth in minutes of arc of the equator
		double a = 21600/(2 * pi);
double a_rad_nm = a * pi / 180.0 / 1852;
		// (f) Earth's flattening
		double f = 1/298.257223563;
		// (e) Eccentricity of the Earth
		double e = sqrt((2 * f) - pow(f, 2));
qDebug("E = %f",e);

// Compute the result
// log(10)=2.30258509;
		// Compute first 4 terms of result
double M = (a * log(10) * log10((tan(DegToRad(45) + (enlem/2.0))))) -
			(a * (
				  ((pow(e,2)) * sin(enlem)) +
				  ((pow(e,4) / 3.0) * pow(sin(enlem), 3)) +
				  ((pow(e,6) / 5.0) * pow(sin(enlem), 5))
				 )
			);

/*
	float md, e2, e4, e6,v1,v2,v3,v4;

	e2 = e * e;
	e4 = e2 * e2;
	e6 = e4 * e2;
	v1 = M_PI/180.0 * (1.0 - e2 / 4.0 - 3.0 * e4 / 64.0 - 5.0 * e6 / 256.0);
	v2 = 3.0 /8.0 * (e2 - e4 / 4.0 + 15.0 * e6 / 128.0);
	v3 = 15.0 / 256.0 * (e4 + 3.0 * e6 / 4.0);
	v4 = a / 1852.0;
	md = v4 * (v1 * lat - v2 * sin(2.0 * lat) + v3 * sin(4.0 * lat));
// 	if(debug)
// 		printf("meridional factors A0 %g, A2 %g, A4 %g\n",
// 			v1 * v4, v2 * v4, v3 * v4);
// 	return(md);

return md;

*/
return M;
}

double mercatorsailing::dm2dd(QString lat_lon ,QString sign_in)//3234.420 , N
{
	double angle;
	if(sign_in=="N" || sign_in=="S") 
	{

		double derece = lat_lon.left(2).toDouble();	
        	double dakika= lat_lon.mid(2,6).toDouble();
//         	double saniye=lat_lon.right(3).toDouble();
// 		angle= derece + dakika/60.+saniye/3600.0;
		angle= derece + dakika/60.;
 		if (angle<0)
     			angle=-angle;

	}
	else if(sign_in=="E" || sign_in=="W")
	{
		double derece = lat_lon.left(3).toDouble();	
         	double dakika= lat_lon.mid(3,6).toDouble();
//          	double saniye=lat_lon.right(3).toDouble();
// 		angle= derece + dakika/60.+saniye/3600.0;//60*1000 saniyeyi(500) dk yapıp 60 ile çarp
		angle= derece + dakika/60.;
 		if (angle<0)
     		angle=-angle;
}

	int sign = 1;
	if (sign_in == "S" || sign_in == "W")
		sign = -1;
	 angle = angle * sign;
	return angle;
}

QStringList mercatorsailing::RotaVeMesafe(QString mevki1, QString mevki2)
{
float lat1,lat2,lon1,lon2,lon,lat;
 // Get angles 
//    lat1 = dm2dd(enlem1, yon1);
//    lat2 = dm2dd(hedefEnlem, yon3);
//    lon1 = dm2dd(boylam1, yon2);
//    lon2 = dm2dd(hedefBoylam, yon4);
//  GPS_Math_Str_To_Deg("N43 00.000 E023 00.228", lon, lat, false);
// qDebug()<<mevki1;
// qDebug()<<mevki2;
GPS_Math_Str_To_Deg(mevki1, lon1, lat1, false);
GPS_Math_Str_To_Deg(mevki2, lon2, lat2, false);
// qDebug()<<QString("Lat=%1").arg(lat);
// qDebug()<<QString("Lon=%1").arg(lon);
// QList<double> mr = distVincenty(lat1,lon1,lat2,lon2) ;
if(distVincenty(lat1,lon1,lat2,lon2)){}

double ker=RadToDeg(BearingTo);
//    if (dlat > 0)
//       course = course + 360;
    if (ker < 0)
       ker = ker + 360;

    if (ker >= 360)
       ker = ker - 360;

QString kerteriz=QString("%1").arg(ker);
QString mesafe=QString("%1").arg(DistTo/1852.);//mt to nm
QStringList tmp;
tmp.clear();
tmp.append(kerteriz);
tmp.append(mesafe);

// qDebug("Rota= %f  Mesafe = %f NM ", course,dist);
return tmp;

/*
double lat1,lat2,lon1,lon2,dlon,dist,course;  
 // Get angles 
   lat1 = dm2dd(enlem1, yon1);
   lat2 = dm2dd(hedefEnlem, yon3);
   lon1 = dm2dd(boylam1, yon2);
   lon2 = dm2dd(hedefBoylam, yon4);
// Y2Enlem(double yimage)
   dlon = lon2 - lon1;
   if (dlon > 180)
   	dlon = dlon - 360;
   if (dlon < -180)
   	dlon = dlon + 360;
   dlon = dlon * 60;

   // Reduce to parallel sailing if latitudes are the same
   if (lat2 == lat1)
      {
	dist = dlon*cos(DegToRad(lat1));
       if (dlon < 0) course = 270;
       if (dlon > 0) course = 90;
       if (dlon == 0) course = 0;
 if(dist<0)
    dist=-dist;
QString kerteriz=QString("%1").arg(course);
// kerteriz.arg();
QString mesafe=QString("%1").arg(dist);
QStringList tmp;
tmp.clear();
tmp.append(kerteriz);
tmp.append(mesafe);
qDebug("Rota= %f  Mesafe = %f NM ", course,dist);
//        form.course.value = course;
//        form.dist.value = dist;
//        sumdist = parseFloat(form.tdist.value);
//        if (isNaN(sumdist))
//            sumdist = 0;
//        sumdist = sumdist + dist;
//        form.tdist.value = sumdist;
       return tmp;
      }
double mp1,mp2,dmp,dlat;
  // Get Meridional Parts
   mp1 = MeridyenParcasi(lat1);
//      if (yon1 == "S") mp1 = -mp1;
   mp2 = MeridyenParcasi(lat2);
//     if (yon3 == "S") mp2 = -mp2;

   // Calculate course and distance
   dmp = mp2 - mp1;
   dlat = (lat2 - lat1) * 60;
   course = atan(dlon/dmp);
   dist = dlat/cos(course);
 if(dist<0)
    dist=-dist;
   course = RadToDeg(course);

   if (dlat > 0)
      course = course + 360;
   if (dlat < 0)
      course = course + 180;
   if (course >= 360)
      course = course - 360;

//    form.course.value = course;
//    form.dist.value = dist;
//    sumdist = parseFloat(form.tdist.value);
//    if (isNaN(sumdist))
//       sumdist = 0;
//    sumdist = sumdist + dist;
//    form.tdist.value = sumdist;
QString kerteriz=QString("%1").arg(course);
QString mesafe=QString("%1").arg(dist);
QStringList tmp;
tmp.clear();
tmp.append(kerteriz);
tmp.append(mesafe);

qDebug("Rota= %f  Mesafe = %f NM ", course,dist);
return tmp;
*/
}

QStringList mercatorsailing::DrMevkii(QString mevkii,double course,double distance )
{
float lon1,lat1;
// double lat1 = dm2dd(enlem1, yon1);
// double lon1 = dm2dd(boylam1, yon2);
GPS_Math_Str_To_Deg(mevkii, lon1, lat1, false);
// GPS_Math_Str_To_Deg(mevki2, lon2, lat2, false);

// QList<double> dest = destVincenty(lat1,lon1,course,distance) ;//distance in nm
if(destVincenty(lat1,lon1,course,distance)){}
// qDebug("Yeni Enlem %f",dest.at(0));
// qDebug("Yeni Boylam %f",dest.at(1));
// toDMS(dest.at(0),"NS")
// QString yenienlem=QString("%1").arg(dest.at(0));
// QString yeniBoylam=QString("%1").arg(dest.at(1));

QString yenienlem=QString("%1").arg(DrShipLat);
QString yeniBoylam=QString("%1").arg(DrShipLong);

QStringList tmp;
tmp.append(yenienlem);
tmp.append(yeniBoylam);
// qDebug()<< yenienlem << yeniBoylam;
// qDebug("%f",lon2);
return tmp;
}
/*
double R = 21600/(2 * pi);//nm
// double a_rad_nm = R * pi / 180.0 / 1852;
// qDebug("A rad nm= %f",a_rad_nm);
//  double R=3440.065; //nm 
// double R=6371; //km

   double d = distance/R;  // d = angular distance covered on earth's surface
   double lat1 = dm2dd(enlem1, yon1);
   double lon1 = dm2dd(boylam1, yon2);
   lat1=DegToRad(lat1);
   lon1=DegToRad(lon1);
//    double lat2 = dm2dd(hedefEnlem, yon3);
//   var lat1 = this.lat.toRad(), lon1 = this.lon.toRad();
   double brng = DegToRad(course);

  double lat2 = lat1 + d*cos(brng);
  double dPhi = log(tan(lat2/2+pi/4)/tan(lat1/2+pi/4));
  double q = (lat2-lat1)/dPhi;
  if (!isfinite(q)) q = cos(lat1);//isFinite  
double dLon = d*sin(brng)/q;
  // check for some daft bugger going past the pole

  if (fabs(lat2) > pi/2) lat2 = lat2>0 ? pi-lat2 : -pi-lat2;
double  lon2 ;

     lon2 = fmod(lon1+dLon+pi,2 * pi) - pi ;

//   lon2=lon1+dLon;
//    if (isnan(lat2) || isnan(lon2)) return ;
QString yenienlem=QString("%1").arg(RadToDeg(lat2));
QString yeniBoylam=QString("%1").arg(RadToDeg(lon2));
QStringList tmp;
tmp.append(yenienlem);
tmp.append(yeniBoylam);
qDebug()<< yenienlem << yeniBoylam;
qDebug("%f",lon2);
return tmp;
*/
// 		double a = 21600/(2 * pi);
/*
a=6378137.;
		double a_rad_nm = a * M_PI / 180.0 / 1852;
		// (f) Earth's flattening
		double f = 1/298.257223563;
		// (e) Eccentricity of the Earth
// 		double e = sqrt((2 * f) - pow(f, 2));
	 e = sqrt((2. * f) - f*f);
   		double lat1 = dm2dd(enlem1, yon1);
   		double lon1 = dm2dd(boylam1, yon2);
//     lat1=DegToRad(lat1);
//     lon1=DegToRad(lon1);
double lon2;
double lat2;

if(course == 0.0 || course == 180.0)
	{
	register int iteration;
	double m_from, m_guess, m_partial, lat;

	m_from = meridional_dist(lat1);
	m_guess = m_from + distance * Cos(course);
	lat = lat1 + (m_guess - m_from) / 60.0;
	for(iteration = 0; iteration < 10; iteration++)
	{
		m_partial = meridional_dist(lat);
		lat = lat + (m_guess - m_partial) / 60.0;
	}
	lat2 = lat;
}

		else if(course == 90.0 || course == 270.0)
		{
			partial = e * Sin(lat1);
			d_long = distance * sqrt(1 - partial * partial) /
				(a_rad_nm * Cos(lat1));
			lon2 += (course == 90.0)? d_long: -d_long;
// 			if(debug)
// 				printf("Same meridian\n");
		}

		else
		{
		register int iteration;
		double m_from, m_guess, m_partial, lat;

		m_from = meridional_dist(lat1);
		m_guess = m_from + distance * Cos(course);
		lat = lat1 + (m_guess - m_from) / 60.0;
		for(iteration = 0; iteration < 10; iteration++)
		{
		m_partial = meridional_dist(lat);
		lat = lat + (m_guess - m_partial) / 60.0;
		}
		lat2 = lat;
			delta_M = meridional_part(lat2) - meridional_part(lat1);
			d_long = fabs(delta_M * Tan(course));
			lon2 += (course < 180.0)? d_long: -d_long;
		}

		if(lon2 > 180.0)
			lon2 -= 360.0;
		else if(lon2 < -180.0)
			lon2 += 360.0;

// 		printf("New position             :- ");
// 		out_pos(to);

QString yenienlem=QString("%1").arg(RadToDeg(lat2));
QString yeniBoylam=QString("%1").arg(RadToDeg(lon2));
QStringList tmp;
tmp.append(yenienlem);
tmp.append(yeniBoylam);
qDebug()<< yenienlem << yeniBoylam;
qDebug("lon2 = %f",lon2);
return tmp;
*/
/*
double mercatorsailing::meridional_part(double lat)
// double lat;
{
// 		 a = 21600/(2 * pi);
a=6378137.;
                 a_rad_nm = a * M_PI / 180.0 / 1852;
		// (f) Earth's flattening
		 f = 1/298.257223563;
		// (e) Eccentricity of the Earth
// 		 e = sqrt((2 * f) - pow(f, 2));
	 e = sqrt((2. * f) - f*f);
	double mp, part;

	part = e * Sin(lat);
	mp = TODEG(log(Tan(45.0 + lat / 2.0))
	     - 0.5 * e * log((1 + part) / (1 - part)));
	return(mp);
}
*/
/*
double mercatorsailing::meridional_dist(double lat)
// double lat;
{
	double md, e2, e4, e6;
// 	 a = 21600/(2 * pi);
a=6378137.;
                 a_rad_nm = a * M_PI / 180.0 / 1852;
		// (f) Earth's flattening
		 f = 1/298.257223563;
		// (e) Eccentricity of the Earth
		 e = sqrt((2. * f) - f*f);
	e2 = e * e;
	e4 = e2 * e2;
	e6 = e4 * e2;
	v1 = pi/180.0 * (1.0 - e2 / 4.0 - 3.0 * e4 / 64.0 - 5.0 * e6 / 256.0);
	v2 = 3.0 /8.0 * (e2 - e4 / 4.0 + 15.0 * e6 / 128.0);
	v3 = 15.0 / 256.0 * (e4 + 3.0 * e6 / 4.0);
	v4 = a / 1852.0;
	md = v4 * (v1 * lat - v2 * Sin(2.0 * lat) + v3 * Sin(4.0 * lat));
// 	if(debug)
// 		printf("meridional factors A0 %g, A2 %g, A4 %g\n",
// 			v1 * v4, v2 * v4, v3 * v4);
// 	return(md);
	return(md);
}
*/
QString mercatorsailing::toDMS(double derece,QString yon) {  // convert numeric degrees to deg/min/sec
 if(yon=="NS"){
    if(derece<0) yon="S"; else yon="N";
  }
if(yon=="EW"){
   if(derece>0) yon="E"; 
   else  yon="W";
}
  double d = fabs(derece);  // (unsigned result ready for appending compass dir'n)
   d += 1/7200;  // add � second for rounding
  double deg = floor(d);
//   double min = floor((d-deg)*60);
  double min=(d-deg)*60;
//   double sec = floor((d-deg-min/60)*3600);
  // add leading zeros if required
  QString degstr,minstr,secstr;
degstr=QString("%1").arg(deg);
minstr=QString("%1").arg(min);
// secstr=QString("%1").arg(sec);
if(yon=="E" || yon=="W"){
  if (deg<100) degstr = "0" + degstr;
}
//   if (deg<100) degstr = "0" + degstr;
  if (deg<10) degstr = "0" + degstr;
   if (min<10) minstr = "0" + minstr;
//   if (sec<10) secstr = "0" + secstr;

//   return degstr + minstr + "," + secstr +yon;
// toDmsRakam=degstr + minstr;
// toDmsYon=yon;
return yon+degstr +" "+ minstr;
}
bool mercatorsailing:: distVincenty(double lat1,double lon1,double lat2,double lon2) 
{
// QList<double> dummy;
  double a = 6378137;
double b = 6356752.3142;
double  f = 1/298.257223563;  // WGS-84 ellipsiod
  double L = DegToRad(lon2-lon1);
  double U1 = atan((1-f) * tan(DegToRad(lat1)));
  double U2 = atan((1-f) * tan(DegToRad(lat2)));
  double sinU1 = sin(U1);
double cosU1 = cos(U1);
  double sinU2 =  sin(U2);
double cosU2 = cos(U2);
  
  double lambda = L;
double lambdaP = 2*M_PI;
  double iterLimit = 20;

double cosSqAlpha;
double sinSigma;
double cos2SigmaM;
double cosSigma;
double sigma;
double sinLambda;
double cosLambda;
  while (fabs(lambda-lambdaP) > 1e-12 && --iterLimit>0) {
     sinLambda = sin(lambda);
 cosLambda = cos(lambda);
     sinSigma = sqrt((cosU2*sinLambda) * (cosU2*sinLambda) + 
      (cosU1*sinU2-sinU1*cosU2*cosLambda) * (cosU1*sinU2-sinU1*cosU2*cosLambda));
    if (sinSigma==0) return false;  // co-incident points
     cosSigma = sinU1*sinU2 + cosU1*cosU2*cosLambda;
    sigma = atan2(sinSigma, cosSigma);
    double sinAlpha = cosU1 * cosU2 * sinLambda / sinSigma;
    cosSqAlpha = 1 - sinAlpha*sinAlpha;
    cos2SigmaM = cosSigma - 2*sinU1*sinU2/cosSqAlpha;
    if (isnan(cos2SigmaM)) cos2SigmaM = 0;  // equatorial line: cosSqAlpha=0 (§6)
    double C = f/16*cosSqAlpha*(4+f*(4-3*cosSqAlpha));
    lambdaP = lambda;
    lambda = L + (1-C) * f * sinAlpha *
      (sigma + C*sinSigma*(cos2SigmaM+C*cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)));
  }
  if (iterLimit==0) return false ; // formula failed to converge

  double uSq = cosSqAlpha * (a*a - b*b) / (b*b);
  double A = 1 + uSq/16384*(4096+uSq*(-768+uSq*(320-175*uSq)));
  double B = uSq/1024 * (256+uSq*(-128+uSq*(74-47*uSq)));
  double deltaSigma = B*sinSigma*(cos2SigmaM+B/4*(cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)-
    B/6*cos2SigmaM*(-3+4*sinSigma*sinSigma)*(-3+4*cos2SigmaM*cos2SigmaM)));
  double s = b*A*(sigma-deltaSigma);
  
  // initial & final bearings
  double fwdAz = atan2(cosU2*sinLambda, cosU1*sinU2-sinU1*cosU2*cosLambda);
  double revAz = atan2(cosU1*sinLambda, -sinU1*cosU2+cosU1*sinU2*cosLambda);
  
//   s = s.toFixed(3); // round to 1mm precision
DistTo=s;
BearingTo=fwdAz;
BearingFrom=revAz;
// QList<double> mr;
//   mr.append(s);
//   mr.append(fwdAz);
//   mr.append(revAz);
return true;
}

bool mercatorsailing::destVincenty(double lat1, double lon1, double brng, double dist) 
{

  double a = 6378137;
  double b = 6356752.3142;
  double f = 1/298.257223563;  // WGS-84 ellipsiod
  double s = dist*1852;//NM to mt
  double alpha1 = DegToRad(brng);
  double sinAlpha1 = sin(alpha1);
  double cosAlpha1 = cos(alpha1);
  
  double tanU1 = (1-f) * tan(DegToRad(lat1));
  double cosU1 = 1 / sqrt((1 + tanU1*tanU1));
  double sinU1 = tanU1*cosU1;
  double sigma1 = atan2(tanU1, cosAlpha1);
  double sinAlpha = cosU1 * sinAlpha1;
  double cosSqAlpha = 1 - sinAlpha*sinAlpha;
  double uSq = cosSqAlpha * (a*a - b*b) / (b*b);
  double A = 1 + uSq/16384*(4096+uSq*(-768+uSq*(320-175*uSq)));
  double B = uSq/1024 * (256+uSq*(-128+uSq*(74-47*uSq)));
  
  double sigma = s / (b*A);
  double sigmaP = 2*M_PI;
  double sinSigma;
  double cosSigma;
  double cos2SigmaM;
  while (fabs(sigma-sigmaP) > 1e-12) {
     cos2SigmaM = cos(2*sigma1 + sigma);
     sinSigma = sin(sigma);
     cosSigma = cos(sigma);
     double deltaSigma = B*sinSigma*(cos2SigmaM+B/4*(cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)-
     B/6*cos2SigmaM*(-3+4*sinSigma*sinSigma)*(-3+4*cos2SigmaM*cos2SigmaM)));
     sigmaP = sigma;
     sigma = s / (b*A) + deltaSigma;
  }

  double tmp = sinU1*sinSigma - cosU1*cosSigma*cosAlpha1;
  double lat2 = atan2(sinU1*cosSigma + cosU1*sinSigma*cosAlpha1, 
      (1-f)*sqrt(sinAlpha*sinAlpha + tmp*tmp));
  double lambda = atan2(sinSigma*sinAlpha1, cosU1*cosSigma - sinU1*sinSigma*cosAlpha1);
  double C = f/16*cosSqAlpha*(4+f*(4-3*cosSqAlpha));
  double L = lambda - (1-C) * f * sinAlpha *
      (sigma + C*sinSigma*(cos2SigmaM+C*cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)));

  double revAz = atan2(sinAlpha, -tmp);  // final bearing
// pos newpos;
// QList<double> pos;
// pos.append(RadToDeg(lat2));
DrShipLat=RadToDeg(lat2);
// pos.append(lon1+RadToDeg(L));
DrShipLong=lon1+RadToDeg(L);
// newpos.lon=RadToDeg(lon1+L);
//   return new LatLon(lat2.toDeg(), lon1+L.toDeg());
return true;
}
//Copyright (C) 1999 Alan Bleasby
void mercatorsailing::GPS_Math_Deg_To_DegMin(float v, qint32 *d, float *m)
{
    qint32 sign;

    if(v<(float)0.) {
        v *= (float)-1.;
        sign = 1;
    }
    else {
        sign = 0;
    }

    *d = (qint32)v;
    *m = (v-(float)*d) * (float)60.0;
    if(*m>(float)59.999) {
        ++*d;
        *m = (float)0.0;
    }

    if(sign) {
        *d = -*d;
    }

    return;
}


void mercatorsailing::GPS_Math_DegMin_To_Deg(const qint32 d, const float m, float& deg)
{

    deg = ((float)abs(d)) + m / (float)60.0;
    if(d<0) {
        deg = -deg;
    }

    return;
}


bool mercatorsailing::GPS_Math_Str_To_Deg(const QString& str, float& lon, float& lat, bool silent)
{
    QRegExp re("^\\s*([N|S]){1}\\W*([0-9]+)\\W*([0-9]+\\.[0-9]+)\\s+([E|W]){1}\\W*([0-9]+)\\W*([0-9]+\\.[0-9]+)\\s*$");
    if(!re.exactMatch(str)) {
//         if(!silent) QMessageBox::warning(0,QObject::tr("Error"),QObject::tr("Bad position format. Must be: [N|S] ddd mm.sss [W|E] ddd mm.sss"),QMessageBox::Ok,QMessageBox::NoButton);
        return false;
    }

    bool signLat    = re.cap(1) == "S";
    int degLat      = re.cap(2).toInt();
    float minLat   = re.cap(3).toDouble();

    GPS_Math_DegMin_To_Deg((signLat ? -degLat : degLat), minLat, lat);

    bool signLon    = re.cap(4) == "W";
    int degLon      = re.cap(5).toInt();
    float minLon   = re.cap(6).toDouble();

    GPS_Math_DegMin_To_Deg((signLon ? -degLon : degLon), minLon, lon);

    return true;
}