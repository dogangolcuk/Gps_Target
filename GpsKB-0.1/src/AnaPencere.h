/***************************************************************************
 *   Copyright (C) 2008 by Doğan Gölcük                                    *
 *   dogangolcuk@gmail.com                                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef ANAPENCERE_H
#define ANAPENCERE_H
#include "ui_AnaPencere.h"
class AnaPencere : public QMainWindow, public Ui::AnaPencere
{
Q_OBJECT
public:
	AnaPencere();

private:

public slots:
	void setDialMax(int max);
	
private slots:
};
#endif