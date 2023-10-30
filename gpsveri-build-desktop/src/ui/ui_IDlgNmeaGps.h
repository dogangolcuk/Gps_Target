/********************************************************************************
** Form generated from reading UI file 'IDlgNmeaGps.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDLGNMEAGPS_H
#define UI_IDLGNMEAGPS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IDlgNmeaGps
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout1;
    QLabel *label_11;
    QComboBox *CbPorts;
    QLabel *label_6;
    QComboBox *CbDataBits;
    QLabel *label_10;
    QComboBox *CbBaudRate;
    QFrame *frame_2;
    QGridLayout *gridLayout2;
    QLabel *label_7;
    QComboBox *CbParity;
    QLabel *label_8;
    QComboBox *CbFlowControl;
    QLabel *label_9;
    QComboBox *CbStopBits;
    QPushButton *PbKaydet;
    QTextEdit *TeRecieveData;

    void setupUi(QWidget *IDlgNmeaGps)
    {
        if (IDlgNmeaGps->objectName().isEmpty())
            IDlgNmeaGps->setObjectName(QString::fromUtf8("IDlgNmeaGps"));
        IDlgNmeaGps->resize(573, 420);
        gridLayout = new QGridLayout(IDlgNmeaGps);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(IDlgNmeaGps);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout1 = new QGridLayout(frame);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout1->addWidget(label_11, 0, 0, 1, 1);

        CbPorts = new QComboBox(frame);
        CbPorts->setObjectName(QString::fromUtf8("CbPorts"));

        gridLayout1->addWidget(CbPorts, 1, 0, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout1->addWidget(label_6, 2, 0, 1, 1);

        CbDataBits = new QComboBox(frame);
        CbDataBits->setObjectName(QString::fromUtf8("CbDataBits"));

        gridLayout1->addWidget(CbDataBits, 3, 0, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout1->addWidget(label_10, 4, 0, 1, 1);

        CbBaudRate = new QComboBox(frame);
        CbBaudRate->setObjectName(QString::fromUtf8("CbBaudRate"));

        gridLayout1->addWidget(CbBaudRate, 5, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(IDlgNmeaGps);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout2 = new QGridLayout(frame_2);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout2->addWidget(label_7, 0, 0, 1, 1);

        CbParity = new QComboBox(frame_2);
        CbParity->setObjectName(QString::fromUtf8("CbParity"));

        gridLayout2->addWidget(CbParity, 1, 0, 1, 2);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout2->addWidget(label_8, 2, 0, 1, 2);

        CbFlowControl = new QComboBox(frame_2);
        CbFlowControl->setObjectName(QString::fromUtf8("CbFlowControl"));

        gridLayout2->addWidget(CbFlowControl, 3, 0, 1, 2);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout2->addWidget(label_9, 4, 0, 1, 1);

        CbStopBits = new QComboBox(frame_2);
        CbStopBits->setObjectName(QString::fromUtf8("CbStopBits"));

        gridLayout2->addWidget(CbStopBits, 5, 0, 1, 2);


        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        PbKaydet = new QPushButton(IDlgNmeaGps);
        PbKaydet->setObjectName(QString::fromUtf8("PbKaydet"));

        gridLayout->addWidget(PbKaydet, 1, 0, 1, 2);

        TeRecieveData = new QTextEdit(IDlgNmeaGps);
        TeRecieveData->setObjectName(QString::fromUtf8("TeRecieveData"));

        gridLayout->addWidget(TeRecieveData, 2, 0, 1, 2);


        retranslateUi(IDlgNmeaGps);

        QMetaObject::connectSlotsByName(IDlgNmeaGps);
    } // setupUi

    void retranslateUi(QWidget *IDlgNmeaGps)
    {
        IDlgNmeaGps->setWindowTitle(QApplication::translate("IDlgNmeaGps", "Gps Ayarlar\304\261", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("IDlgNmeaGps", "Port :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("IDlgNmeaGps", "DataBits :", 0, QApplication::UnicodeUTF8));
        CbDataBits->clear();
        CbDataBits->insertItems(0, QStringList()
         << QApplication::translate("IDlgNmeaGps", "DATA_5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "DATA_6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "DATA_7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "DATA_8", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("IDlgNmeaGps", "BaudRate :", 0, QApplication::UnicodeUTF8));
        CbBaudRate->clear();
        CbBaudRate->insertItems(0, QStringList()
         << QApplication::translate("IDlgNmeaGps", "BAUD50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD75", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD134", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD150", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD300", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD1800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD14400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD56000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD76800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD128000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "BAUD256000", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("IDlgNmeaGps", "Parity :", 0, QApplication::UnicodeUTF8));
        CbParity->clear();
        CbParity->insertItems(0, QStringList()
         << QApplication::translate("IDlgNmeaGps", "PAR_NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "PAR_ODD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "PAR_EVEN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "PAR_MARK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "PAR_SPACE", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("IDlgNmeaGps", "FlowControl :", 0, QApplication::UnicodeUTF8));
        CbFlowControl->clear();
        CbFlowControl->insertItems(0, QStringList()
         << QApplication::translate("IDlgNmeaGps", "FLOW_OFF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "FLOW_HARDWARE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "FLOW_XONXOFF", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("IDlgNmeaGps", "StopBits :", 0, QApplication::UnicodeUTF8));
        CbStopBits->clear();
        CbStopBits->insertItems(0, QStringList()
         << QApplication::translate("IDlgNmeaGps", "STOP_1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "STOP_1_5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IDlgNmeaGps", "STOP_2", 0, QApplication::UnicodeUTF8)
        );
        PbKaydet->setText(QApplication::translate("IDlgNmeaGps", "Ayarlar\304\261 Kaydet", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IDlgNmeaGps: public Ui_IDlgNmeaGps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDLGNMEAGPS_H
