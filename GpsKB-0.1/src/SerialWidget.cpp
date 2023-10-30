#include "SerialWidget.h"

#include <QTimer>
#include <QSettings>
#include <QDebug>
#include <QtCore>

#ifdef unix
#include <QDir>
#include <QDataStream>
#endif

#include "qextserialport.h"

/// Widget for QextSerialPort
/** Handles the setup and use of QextSerialPort.
 *  Should eventually be a QDesigner plugin.
 */
SerialWidget::SerialWidget()
{
	// Default port number for testing
	// set port_name first, then connect()
#ifdef WIN32
	port_base = "\\\\.\\com";
#endif
#ifdef unix
	port_base = "ttyS";
// 	port_base = "ttyS";
#endif
	port_name = "";

	qDebug("Seri Port Sinifi Uretiliyor");
	CommPort = new QextSerialPort();
//         CbDataBits->addItem("DATA_5",DATA_5);

	receiveTimer = new QTimer(this);
	connect(receiveTimer, SIGNAL(timeout()), SLOT(receiveMsg()));
	receiveTimer->stop();
}


/// Open serial port
/** When the widget is created, it makes a list of available ports that can be opened.  
 *  The port_num is the index in that list
 */
int SerialWidget::portOpen(QList<int> index)
{
	int port_num=index[5];
	qDebug("Seri Port Aciliyor");
	CommPort->close();
// 	CommPort = new QextSerialPort();
	CommPort->setPortName( ports.value(port_num) );
          CommPort->setConf(index);
//   	CommPort->setDataBits(DATA_8);
// CommPort->setDataBitsInt(2);
// CommPort->setParity(PAR_NONE);
//   	CommPort->setFlowControl(FLOW_HARDWARE);
//   	CommPort->setStopBits(STOP_1);
//  	CommPort->setBaudRate(BAUD4800);
	if ( CommPort->open() )

	{
// 		QString q = trUtf8("Açılan port : "+ports.value(port_num));
// 	        qDebug( q.toUtf8() );
// 		statusbar()->showMessage( trUtf8("Açılan port : "+ports.value(port_num)), 3000);
		qDebug("Port : " + ports.value(port_num).toAscii() );

		receiveTimer->start(2);
                emit newPortName( portName(port_num) );
		return(1);
	}
	else
	{
		receiveTimer->stop();
		qDebug("Port Acilmadi" + ports.value(port_num).toAscii() );
		return(-1);
	}
	return(0);
}


/// Send text to serial port
/** Uses the text found in the SendText pointer. 
 */
/*
void SerialWidget::sendText()
{
	transmitMsg( SendText->text() );
	if ( CR->isChecked() )
	{
		transmitMsg ("\n");
	}
	SendText->clear();
}
*/

/// Transmit text on serial port
/** Writes data to port. 
 */
/*
void SerialWidget::transmitMsg(QString text )
{
  int i = CommPort->writeData((text).toAscii(),
                       (text).length());
  //qDebug((text).toAscii());
  qDebug("trasmitted : %d", i);
}
*/

/// Receive text
/** This is trggered by a timer to buffer data.
 *  Emits signal recvText(QString).
 */
void SerialWidget::receiveMsg()
{
  int numBytes = CommPort->bytesAvailable();
  if(numBytes > 0) {
    if(numBytes > 80) numBytes = 80;
    char buff[80];

    int i = CommPort->readData(buff, numBytes);
    buff[numBytes] = '\0';
    QString msg = buff;
	emit recvText(msg);

  for (int i = 0; i < numBytes; ++i) {
          if (msg.at(i)=='\n'){
              gecici.append('\n');
              if(gecici.startsWith("$GPRMC")){
                 emit recvGPRMC(gecici);
              }
          gecici.clear();
          }else
          gecici.append(msg.at(i));
  }
     qDebug("Gelen Veri : %d", i);
}

//     qDebug("Numbytres : %d", numBytes);
  }
/// Number of available ports
/** tryAllComs() loads a list of possible ports, then tries to open them. This is how many could be opened.
 */
int SerialWidget::portCount()
{
	return ports.count();
}

/// Port named by port_num
/** Full filename used to open a port.  This returns name only, and does not change the opened port. 
 */
QString SerialWidget::portName(int port_num)
{
	return ports.value(port_num);
}


/// Find available ports
/** Under Windows, it tries to open COM1 to COM32, and lists ones that actually open.
 *  Under Unix, it tries to open all files matching "/dev/ttyS*", and lists ones that actually open.
 *  When done, it emits the signal newMaxCount(int);
 */
QStringList SerialWidget::tryAllComs()
{
	QFile file;
/*
#ifdef WIN32
// WIN32 code here

//QDir::setCurrent("c:\");

	// Fixed at 32 com ports for now
	for (int x = 1; x < 32; x++)
	{
		port_name = QString(port_base + "%1") .arg(x);
		file.close();
		file.setFileName(port_name);
		if ( file.open(QIODevice::ReadOnly) )
		{
			//emit recvText ( "Available Port : " + port_name.toAscii() + "\n");
			ports << port_name;

		}
		else
			file.unsetError();
	}

#endif
*/
// #ifdef unix
// UNIX code here

	//QDir::setCurrent("/home");

	// Search /dev for filemask
	QDir dir = QDir("/dev");
	QString filter = port_base + "*";
	dir.setNameFilters( QStringList(filter) );
	dir.setFilter( QDir::System | QDir::CaseSensitive );
	QStringList entries = dir.entryList();
	
	QString q = QString("Bulunan port sayısı: %1") .arg( entries.count() );
	qDebug( q.toAscii() );

	for( QStringList::ConstIterator entry=entries.begin(); entry!=entries.end(); ++entry )
	{
		port_name = *entry;
		file.close();
		file.setFileName("/dev/" + port_name);
		if ( file.open(QIODevice::ReadWrite) )
		{
			// Have to actually try writing something, or nothing, and expect no error
			QDataStream test(&file);
			if ( test.writeRawData("", 0) > -1)
			{
				ports << "/dev/" + port_name;
				qDebug( "Gorunen Port : " + ports.last().toAscii() );
			}
			else 
				file.unsetError();
		}
		else
			file.unsetError();
	}

// #endif
	file.close();
	
	emit newMaxCount( ports.count() );

	return ports;
}

