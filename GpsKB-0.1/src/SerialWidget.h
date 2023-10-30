#ifndef SERIALWIDGET_H
#define SERIALWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QDial>
#include <QStatusBar>
#include <QComboBox>
#include "qextserialport.h"

// class QextSerialPort;
class QextSerialPort;

class SerialWidget : public QWidget 
{
	Q_OBJECT

public:
	SerialWidget();

	// Run when class is created
	// Run more often to update list
	// Only shows ports that can actually open
	QStringList tryAllComs();
	

	int portCount();
	QString portName(int port_num);

	/// List of available ports
	/** Set by tryAllComs(). 
	 */
	QStringList ports;
	
	QextSerialPort *CommPort;
// 	QLineEdit* SendText;
//         QLineEdit* LeSeciliPort;
// 	QDial* Selector;
// 	QRadioButton* CR;
//         QStatusBar* statusbar;
//         QComboBox* CbDataBits;
        QString gecici;
// QList<int> index;
// 	QList<DataBitsType> databits;
private:
	QTimer *receiveTimer;
	
	/// String to use with an int to make port_name
	/** Set when widget is created, platform dependant.
	*/
	QString port_base;

	/// Name of port opened
	/** Set from port list when opened
	*/
	QString port_name;
	
signals:
	/// Sent when text received.
	/** A timer triggers a function to watch for data, this is trggered when some data shows up.
	 */
	void recvText(QString text);
	
	/// Sent when a port has been opened
	/** Connect this to setText(QString) type of slot. 
	 */
	void newPortName(QString name);

	/// Sent when the port list has been updated
	/** Connect this to setIntValue(int) type of slot.
	*/
	void newMaxCount(int max);

	/*
	GPS den gelen $GPRMC bilgilerini liste olarak yollar.
	*/
	
	void recvGPRMC(QString);

public slots:
	int portOpen(QList<int>);
//         void setDial(int num);
// 	void sendText();
// 	void setPort(int num);
//         void configurePort(int num);

private slots:
	void receiveMsg();
// 	void transmitMsg(QString text);
// 	void receiveRMC();
};
#endif
