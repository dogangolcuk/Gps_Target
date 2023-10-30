/********************************************************************************
** Form generated from reading ui file 'mercator.ui'
**
** Created: Sun May 4 20:09:47 2008
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MERCATOR_H
#define UI_MERCATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

class Ui_harita
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *harita)
    {
    if (harita->objectName().isEmpty())
        harita->setObjectName(QString::fromUtf8("harita"));
    harita->resize(652, 376);
    pushButton = new QPushButton(harita);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(90, 60, 80, 27));

    retranslateUi(harita);

    QMetaObject::connectSlotsByName(harita);
    } // setupUi

    void retranslateUi(QWidget *harita)
    {
    harita->setWindowTitle(QApplication::translate("harita", "Form", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("harita", "PushButton", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(harita);
    } // retranslateUi

};

namespace Ui {
    class harita: public Ui_harita {};
} // namespace Ui

#endif // UI_MERCATOR_H
