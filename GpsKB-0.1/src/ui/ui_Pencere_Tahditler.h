/********************************************************************************
** Form generated from reading ui file 'Pencere_Tahditler.ui'
**
** Created: Sun May 4 20:09:47 2008
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PENCERE_TAHDITLER_H
#define UI_PENCERE_TAHDITLER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QLCDNumber>
#include <QtGui/QListWidget>
#include <QtGui/QWidget>

class Ui_Pencere_Tahditler
{
public:
    QDial *dial;
    QLCDNumber *lcdNumber;
    QListWidget *listWidget;

    void setupUi(QWidget *Pencere_Tahditler)
    {
    if (Pencere_Tahditler->objectName().isEmpty())
        Pencere_Tahditler->setObjectName(QString::fromUtf8("Pencere_Tahditler"));
    Pencere_Tahditler->resize(579, 458);
    dial = new QDial(Pencere_Tahditler);
    dial->setObjectName(QString::fromUtf8("dial"));
    dial->setGeometry(QRect(9, 9, 161, 81));
    dial->setMaximum(360);
    dial->setWrapping(true);
    dial->setNotchTarget(2);
    dial->setNotchesVisible(true);
    lcdNumber = new QLCDNumber(Pencere_Tahditler);
    lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
    lcdNumber->setGeometry(QRect(370, 10, 191, 51));
    listWidget = new QListWidget(Pencere_Tahditler);
    listWidget->setObjectName(QString::fromUtf8("listWidget"));
    listWidget->setGeometry(QRect(310, 230, 256, 192));

    retranslateUi(Pencere_Tahditler);

    QMetaObject::connectSlotsByName(Pencere_Tahditler);
    } // setupUi

    void retranslateUi(QWidget *Pencere_Tahditler)
    {
    Pencere_Tahditler->setWindowTitle(QApplication::translate("Pencere_Tahditler", "Silah Tahditleri", 0, QApplication::UnicodeUTF8));
    listWidget->clear();

    QListWidgetItem *__item = new QListWidgetItem(listWidget);
    __item->setText(QApplication::translate("Pencere_Tahditler", "ggg", 0, QApplication::UnicodeUTF8));

    QListWidgetItem *__item1 = new QListWidgetItem(listWidget);
    __item1->setText(QApplication::translate("Pencere_Tahditler", "gg", 0, QApplication::UnicodeUTF8));
    __item1->setIcon(QIcon(QString::fromUtf8(":/images/rsc/agt_internet.png")));
    Q_UNUSED(Pencere_Tahditler);
    } // retranslateUi

};

namespace Ui {
    class Pencere_Tahditler: public Ui_Pencere_Tahditler {};
} // namespace Ui

#endif // UI_PENCERE_TAHDITLER_H
