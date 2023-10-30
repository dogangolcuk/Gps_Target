/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Sun Mar 2 13:42:28 2008
**      by: Qt User Interface Compiler version 4.3.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

class Ui_Dialog
{
public:
    QAction *actionQuit;
    QAction *actionView;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *ButtonTransmit;
    QRadioButton *ButtonCR;
    QLineEdit *SendText;
    QHBoxLayout *hboxLayout;
    QLabel *label_3;
    QLineEdit *ComName;
    QLCDNumber *ComNumber;
    QDial *ComDial;
    QSpacerItem *spacerItem;
    QLabel *label;
    QTextEdit *RecvText;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dialog)
    {
    if (Dialog->objectName().isEmpty())
        Dialog->setObjectName(QString::fromUtf8("Dialog"));
    Dialog->resize(591, 754);
    Dialog->setWindowIcon(QIcon(QString::fromUtf8(":/images/app.svg")));
    actionQuit = new QAction(Dialog);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionView = new QAction(Dialog);
    actionView->setObjectName(QString::fromUtf8("actionView"));
    centralwidget = new QWidget(Dialog);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
    centralwidget->setSizePolicy(sizePolicy);
    gridLayout = new QGridLayout(centralwidget);
#ifndef Q_OS_MAC
    gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout->setMargin(9);
#endif
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    gridLayout->addWidget(pushButton, 3, 2, 1, 1);

    ButtonTransmit = new QPushButton(centralwidget);
    ButtonTransmit->setObjectName(QString::fromUtf8("ButtonTransmit"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(ButtonTransmit->sizePolicy().hasHeightForWidth());
    ButtonTransmit->setSizePolicy(sizePolicy1);

    gridLayout->addWidget(ButtonTransmit, 2, 2, 1, 1);

    ButtonCR = new QRadioButton(centralwidget);
    ButtonCR->setObjectName(QString::fromUtf8("ButtonCR"));

    gridLayout->addWidget(ButtonCR, 2, 1, 1, 1);

    SendText = new QLineEdit(centralwidget);
    SendText->setObjectName(QString::fromUtf8("SendText"));

    gridLayout->addWidget(SendText, 2, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout->setSpacing(6);
#endif
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    hboxLayout->addWidget(label_3);

    ComName = new QLineEdit(centralwidget);
    ComName->setObjectName(QString::fromUtf8("ComName"));
    sizePolicy1.setHeightForWidth(ComName->sizePolicy().hasHeightForWidth());
    ComName->setSizePolicy(sizePolicy1);
    ComName->setAlignment(Qt::AlignRight);
    ComName->setReadOnly(true);

    hboxLayout->addWidget(ComName);

    ComNumber = new QLCDNumber(centralwidget);
    ComNumber->setObjectName(QString::fromUtf8("ComNumber"));
    sizePolicy1.setHeightForWidth(ComNumber->sizePolicy().hasHeightForWidth());
    ComNumber->setSizePolicy(sizePolicy1);
    ComNumber->setFrameShape(QFrame::NoFrame);
    ComNumber->setLineWidth(1);
    ComNumber->setNumDigits(2);
    ComNumber->setSegmentStyle(QLCDNumber::Flat);
    ComNumber->setProperty("value", QVariant(0));
    ComNumber->setProperty("intValue", QVariant(0));

    hboxLayout->addWidget(ComNumber);

    ComDial = new QDial(centralwidget);
    ComDial->setObjectName(QString::fromUtf8("ComDial"));
    ComDial->setMinimum(0);
    ComDial->setMaximum(16);
    ComDial->setSingleStep(1);
    ComDial->setPageStep(2);
    ComDial->setValue(0);
    ComDial->setSliderPosition(0);
    ComDial->setOrientation(Qt::Horizontal);
    ComDial->setInvertedAppearance(true);
    ComDial->setNotchTarget(2);
    ComDial->setNotchesVisible(true);

    hboxLayout->addWidget(ComDial);

    spacerItem = new QSpacerItem(311, 50, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);


    gridLayout->addLayout(hboxLayout, 0, 0, 1, 3);

    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 1, 0, 1, 2);

    RecvText = new QTextEdit(centralwidget);
    RecvText->setObjectName(QString::fromUtf8("RecvText"));
    RecvText->setUndoRedoEnabled(false);
    RecvText->setReadOnly(true);

    gridLayout->addWidget(RecvText, 4, 0, 1, 3);

    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 3, 0, 1, 2);

    Dialog->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Dialog);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 591, 19));
    menuSettings = new QMenu(menubar);
    menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    Dialog->setMenuBar(menubar);
    statusbar = new QStatusBar(Dialog);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    Dialog->setStatusBar(statusbar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuSettings->menuAction());
    menuSettings->addAction(actionView);
    menuFile->addSeparator();
    menuFile->addAction(actionQuit);

    retranslateUi(Dialog);
    QObject::connect(actionQuit, SIGNAL(activated()), Dialog, SLOT(close()));
    QObject::connect(ComDial, SIGNAL(valueChanged(int)), ComNumber, SLOT(display(int)));
    QObject::connect(SendText, SIGNAL(returnPressed()), ButtonTransmit, SLOT(click()));
    QObject::connect(pushButton, SIGNAL(clicked()), RecvText, SLOT(clear()));

    QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QMainWindow *Dialog)
    {
    Dialog->setWindowTitle(QApplication::translate("Dialog", "Serial Terminal", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("Dialog", "Quit", 0, QApplication::UnicodeUTF8));
    actionView->setText(QApplication::translate("Dialog", "View", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("Dialog", "Clear", 0, QApplication::UnicodeUTF8));
    ButtonTransmit->setText(QApplication::translate("Dialog", "Transmit", 0, QApplication::UnicodeUTF8));
    ButtonCR->setText(QApplication::translate("Dialog", "CR", 0, QApplication::UnicodeUTF8));
    SendText->setToolTip(QApplication::translate("Dialog", "Text to send", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("Dialog", "Com port", 0, QApplication::UnicodeUTF8));
    ComName->setToolTip(QApplication::translate("Dialog", "String for com port access, different on Windows and Unix", 0, QApplication::UnicodeUTF8));
    ComName->setText(QApplication::translate("Dialog", "COM", 0, QApplication::UnicodeUTF8));
    ComNumber->setToolTip(QApplication::translate("Dialog", "Com port number, appended to com port name", 0, QApplication::UnicodeUTF8));
    ComDial->setToolTip(QApplication::translate("Dialog", "Select com port number", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Dialog", "Send", 0, QApplication::UnicodeUTF8));
    RecvText->setToolTip(QApplication::translate("Dialog", "Received or Debug text", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Dialog", "Receive", 0, QApplication::UnicodeUTF8));
    menuSettings->setTitle(QApplication::translate("Dialog", "Settings", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("Dialog", "File", 0, QApplication::UnicodeUTF8));
    statusbar->setToolTip(QApplication::translate("Dialog", "Status Bar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

#endif // UI_DIALOG_H
