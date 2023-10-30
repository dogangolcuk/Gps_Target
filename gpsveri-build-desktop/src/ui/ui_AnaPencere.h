/********************************************************************************
** Form generated from reading UI file 'AnaPencere.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANAPENCERE_H
#define UI_ANAPENCERE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnaPencere
{
public:
    QAction *actionSerialConfig;
    QAction *actionKay_t_Yolu;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QWidget *GpsYuva;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout1;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout2;
    QLabel *label_15;
    QLineEdit *LeHedefEnlem;
    QLabel *label_16;
    QLineEdit *LeHedefBoylam;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout3;
    QLabel *label_19;
    QComboBox *CbUzunlukBirimi;
    QLabel *label_20;
    QLineEdit *LeMesafe;
    QLineEdit *LeKerteriz;
    QWidget *tab_5;
    QGridLayout *gridLayout4;
    QLineEdit *LeDkSonra;
    QLabel *label_23;
    QPushButton *PbHesapla;
    QTextEdit *TeDr;
    QWidget *tab_4;
    QGridLayout *gridLayout5;
    QLabel *label_13;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout6;
    QCheckBox *ChbVeri;
    QTableView *tablo;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *AnaPencere)
    {
        if (AnaPencere->objectName().isEmpty())
            AnaPencere->setObjectName(QString::fromUtf8("AnaPencere"));
        AnaPencere->resize(590, 407);
        actionSerialConfig = new QAction(AnaPencere);
        actionSerialConfig->setObjectName(QString::fromUtf8("actionSerialConfig"));
        actionKay_t_Yolu = new QAction(AnaPencere);
        actionKay_t_Yolu->setObjectName(QString::fromUtf8("actionKay_t_Yolu"));
        centralwidget = new QWidget(AnaPencere);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        GpsYuva = new QWidget(splitter_2);
        GpsYuva->setObjectName(QString::fromUtf8("GpsYuva"));
        splitter_2->addWidget(GpsYuva);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout1 = new QGridLayout(tab_2);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout2 = new QGridLayout(groupBox_2);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout2->addWidget(label_15, 0, 0, 1, 1);

        LeHedefEnlem = new QLineEdit(groupBox_2);
        LeHedefEnlem->setObjectName(QString::fromUtf8("LeHedefEnlem"));

        gridLayout2->addWidget(LeHedefEnlem, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout2->addWidget(label_16, 1, 0, 1, 1);

        LeHedefBoylam = new QLineEdit(groupBox_2);
        LeHedefBoylam->setObjectName(QString::fromUtf8("LeHedefBoylam"));

        gridLayout2->addWidget(LeHedefBoylam, 1, 1, 1, 1);


        gridLayout1->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout3 = new QGridLayout(groupBox_3);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout3->addWidget(label_19, 0, 0, 1, 1);

        CbUzunlukBirimi = new QComboBox(groupBox_3);
        CbUzunlukBirimi->setObjectName(QString::fromUtf8("CbUzunlukBirimi"));

        gridLayout3->addWidget(CbUzunlukBirimi, 0, 2, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout3->addWidget(label_20, 1, 0, 1, 1);

        LeMesafe = new QLineEdit(groupBox_3);
        LeMesafe->setObjectName(QString::fromUtf8("LeMesafe"));

        gridLayout3->addWidget(LeMesafe, 0, 1, 1, 1);

        LeKerteriz = new QLineEdit(groupBox_3);
        LeKerteriz->setObjectName(QString::fromUtf8("LeKerteriz"));

        gridLayout3->addWidget(LeKerteriz, 1, 1, 1, 1);


        gridLayout1->addWidget(groupBox_3, 0, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout4 = new QGridLayout(tab_5);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        LeDkSonra = new QLineEdit(tab_5);
        LeDkSonra->setObjectName(QString::fromUtf8("LeDkSonra"));

        gridLayout4->addWidget(LeDkSonra, 0, 0, 1, 1);

        label_23 = new QLabel(tab_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout4->addWidget(label_23, 0, 1, 1, 1);

        PbHesapla = new QPushButton(tab_5);
        PbHesapla->setObjectName(QString::fromUtf8("PbHesapla"));

        gridLayout4->addWidget(PbHesapla, 0, 2, 1, 1);

        TeDr = new QTextEdit(tab_5);
        TeDr->setObjectName(QString::fromUtf8("TeDr"));

        gridLayout4->addWidget(TeDr, 1, 0, 1, 3);

        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout5 = new QGridLayout(tab_4);
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout5->addWidget(label_13, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        splitter->addWidget(tabWidget);
        groupBox_5 = new QGroupBox(splitter);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout6 = new QGridLayout(groupBox_5);
        gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
        ChbVeri = new QCheckBox(groupBox_5);
        ChbVeri->setObjectName(QString::fromUtf8("ChbVeri"));
        QFont font;
        font.setPointSize(7);
        ChbVeri->setFont(font);

        gridLayout6->addWidget(ChbVeri, 0, 0, 1, 1);

        tablo = new QTableView(groupBox_5);
        tablo->setObjectName(QString::fromUtf8("tablo"));

        gridLayout6->addWidget(tablo, 1, 0, 1, 1);

        splitter->addWidget(groupBox_5);
        splitter_2->addWidget(splitter);

        gridLayout->addWidget(splitter_2, 0, 0, 1, 1);

        AnaPencere->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AnaPencere);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 590, 29));
        AnaPencere->setMenuBar(menubar);
        statusbar = new QStatusBar(AnaPencere);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AnaPencere->setStatusBar(statusbar);
        toolBar = new QToolBar(AnaPencere);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        AnaPencere->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionSerialConfig);
        toolBar->addAction(actionKay_t_Yolu);

        retranslateUi(AnaPencere);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AnaPencere);
    } // setupUi

    void retranslateUi(QMainWindow *AnaPencere)
    {
        AnaPencere->setWindowTitle(QApplication::translate("AnaPencere", "KB 0.1", 0, QApplication::UnicodeUTF8));
        actionSerialConfig->setText(QApplication::translate("AnaPencere", "Gps Ayarlar\304\261", 0, QApplication::UnicodeUTF8));
        actionKay_t_Yolu->setText(QApplication::translate("AnaPencere", "Kay\304\261t Dosyas\304\261", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_15->setText(QApplication::translate("AnaPencere", "Hedef Enlem :", 0, QApplication::UnicodeUTF8));
        LeHedefEnlem->setInputMask(QApplication::translate("AnaPencere", "A99 99.999; ", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("AnaPencere", "Hedef Boylam :", 0, QApplication::UnicodeUTF8));
        LeHedefBoylam->setInputMask(QApplication::translate("AnaPencere", "A999 99.999; ", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        label_19->setText(QApplication::translate("AnaPencere", "Mesafe :", 0, QApplication::UnicodeUTF8));
        CbUzunlukBirimi->clear();
        CbUzunlukBirimi->insertItems(0, QStringList()
         << QApplication::translate("AnaPencere", "NM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AnaPencere", "KM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AnaPencere", "YD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AnaPencere", "MT", 0, QApplication::UnicodeUTF8)
        );
        label_20->setText(QApplication::translate("AnaPencere", "Kerteriz :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("AnaPencere", "Hedef ", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("AnaPencere", "Sn. Aral\304\261klarla", 0, QApplication::UnicodeUTF8));
        PbHesapla->setText(QApplication::translate("AnaPencere", "Hesapla", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        TeDr->setToolTip(QApplication::translate("AnaPencere", "Tekrar Hesaplamaya Bas\304\261ld\304\261\304\237\304\261nda T\303\274m Buradaki Veriler Silinir.Ctrl A ile hepsini se\303\247ip Ctrl C ile kopyalayabilirsiniz.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("AnaPencere", "DR Mevkii", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("AnaPencere", "\n"
"Do\304\237an G\303\266lc\303\274k\n"
""
"2008\n"
"KB 0.1", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("AnaPencere", "Hakk\304\261nda", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("AnaPencere", "Kay\304\261t Defteri", 0, QApplication::UnicodeUTF8));
        ChbVeri->setText(QApplication::translate("AnaPencere", "De\304\237erleri Kaydet", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("AnaPencere", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnaPencere: public Ui_AnaPencere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANAPENCERE_H
