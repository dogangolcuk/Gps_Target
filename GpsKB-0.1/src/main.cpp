#include <QApplication>
#include "dialogimpl.h"

DialogImpl* anapencere;
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	anapencere = new DialogImpl;

	anapencere->show(); 
	return app.exec();
}

