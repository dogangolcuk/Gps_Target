/********************************************************************************
** Form generated from reading UI file 'IGpsViewWidget.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IGPSVIEWWIDGET_H
#define UI_IGPSVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IGpsViewWidget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout1;
    QLabel *label;
    QLineEdit *LeEnlem;
    QLabel *label_2;
    QLineEdit *LeBoylam;
    QLabel *label_3;
    QLCDNumber *LcdHiz;
    QComboBox *CbHizBirimi;
    QLabel *label_4;
    QLCDNumber *LcdRota;
    QLabel *label_5;
    QLineEdit *LeZaman;
    QLabel *label_14;
    QDateEdit *DeGpsTarih;

    void setupUi(QWidget *IGpsViewWidget)
    {
        if (IGpsViewWidget->objectName().isEmpty())
            IGpsViewWidget->setObjectName(QString::fromUtf8("IGpsViewWidget"));
        IGpsViewWidget->resize(225, 398);
        gridLayout = new QGridLayout(IGpsViewWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_4 = new QGroupBox(IGpsViewWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout1 = new QGridLayout(groupBox_4);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout1->addWidget(label, 0, 0, 1, 1);

        LeEnlem = new QLineEdit(groupBox_4);
        LeEnlem->setObjectName(QString::fromUtf8("LeEnlem"));

        gridLayout1->addWidget(LeEnlem, 0, 1, 1, 2);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout1->addWidget(label_2, 1, 0, 1, 1);

        LeBoylam = new QLineEdit(groupBox_4);
        LeBoylam->setObjectName(QString::fromUtf8("LeBoylam"));

        gridLayout1->addWidget(LeBoylam, 1, 1, 1, 2);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout1->addWidget(label_3, 2, 0, 1, 1);

        LcdHiz = new QLCDNumber(groupBox_4);
        LcdHiz->setObjectName(QString::fromUtf8("LcdHiz"));
        LcdHiz->setFrameShape(QFrame::NoFrame);
        LcdHiz->setSegmentStyle(QLCDNumber::Flat);

        gridLayout1->addWidget(LcdHiz, 2, 1, 1, 1);

        CbHizBirimi = new QComboBox(groupBox_4);
        CbHizBirimi->setObjectName(QString::fromUtf8("CbHizBirimi"));
        QFont font;
        font.setPointSize(9);
        CbHizBirimi->setFont(font);
        CbHizBirimi->setInsertPolicy(QComboBox::NoInsert);
        CbHizBirimi->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        CbHizBirimi->setFrame(true);

        gridLayout1->addWidget(CbHizBirimi, 2, 2, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout1->addWidget(label_4, 3, 0, 1, 1);

        LcdRota = new QLCDNumber(groupBox_4);
        LcdRota->setObjectName(QString::fromUtf8("LcdRota"));
        LcdRota->setMaximumSize(QSize(16777215, 23));
        LcdRota->setLayoutDirection(Qt::LeftToRight);
        LcdRota->setFrameShape(QFrame::NoFrame);
        LcdRota->setFrameShadow(QFrame::Raised);
        LcdRota->setSmallDecimalPoint(false);
        LcdRota->setMode(QLCDNumber::Dec);
        LcdRota->setSegmentStyle(QLCDNumber::Flat);
        LcdRota->setProperty("value", QVariant(0));

        gridLayout1->addWidget(LcdRota, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout1->addWidget(label_5, 4, 0, 1, 1);

        LeZaman = new QLineEdit(groupBox_4);
        LeZaman->setObjectName(QString::fromUtf8("LeZaman"));

        gridLayout1->addWidget(LeZaman, 4, 1, 1, 2);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout1->addWidget(label_14, 5, 0, 1, 1);

        DeGpsTarih = new QDateEdit(groupBox_4);
        DeGpsTarih->setObjectName(QString::fromUtf8("DeGpsTarih"));

        gridLayout1->addWidget(DeGpsTarih, 5, 1, 1, 2);


        gridLayout->addWidget(groupBox_4, 0, 0, 1, 1);


        retranslateUi(IGpsViewWidget);

        QMetaObject::connectSlotsByName(IGpsViewWidget);
    } // setupUi

    void retranslateUi(QWidget *IGpsViewWidget)
    {
        IGpsViewWidget->setWindowTitle(QApplication::translate("IGpsViewWidget", "Gps", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        label->setText(QApplication::translate("IGpsViewWidget", "Enlem :", 0, QApplication::UnicodeUTF8));
        LeEnlem->setInputMask(QApplication::translate("IGpsViewWidget", "A99 99.999; ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("IGpsViewWidget", "Boylam:", 0, QApplication::UnicodeUTF8));
        LeBoylam->setInputMask(QApplication::translate("IGpsViewWidget", "A999 99.999; ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("IGpsViewWidget", "H\304\261z:", 0, QApplication::UnicodeUTF8));
        CbHizBirimi->clear();
        CbHizBirimi->insertItems(0, QStringList()
         << QApplication::translate("IGpsViewWidget", "KTS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IGpsViewWidget", "M/SN", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("IGpsViewWidget", "Rota :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("IGpsViewWidget", "Saat :", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        LeZaman->setToolTip(QApplication::translate("IGpsViewWidget", "Buraya simule yazarsan\304\261z gemi bilgilerini elle girebilirsiniz.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("IGpsViewWidget", "Tarih :", 0, QApplication::UnicodeUTF8));
        DeGpsTarih->setDisplayFormat(QApplication::translate("IGpsViewWidget", "dd.MM.yy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IGpsViewWidget: public Ui_IGpsViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IGPSVIEWWIDGET_H
