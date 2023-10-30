/***************************************************************************
 *   Copyright (C) 2008 by Doğan Gölcük                                    *
 *   dogangolcuk@gmail.com                                                   *
 *                                                                         *
 ***************************************************************************/
#include "harita.h"
#include <QDebug>

/*

/// Customizing of code for Dialog.ui
Harita::Harita(QObject *parent)	
    : QGraphicsScene(parent)
{
// setupUi(this);

tex.setPlainText("DENEME");
QGraphicsLineItem li;
li.setLine(4,6,7,3);
//  scene.addText("Hello, world!");
 scene.addItem(&tex);
scene.addItem(&li);
 scene.setBackgroundBrush(Qt::blue);
// scene.
  view.setScene(&scene);
//   view.setViewport(harita);
  view.show();
    
//   QGridLayout *layout = new QGridLayout;
//         layout->addWidget(&view);
//        layout->addWidget(LeGemiEnlem);
//       fr->addWidget(&view);
//         fr->setLayout(layout);
//          this->setLayout(layout);
// QGraphicsView g=new QGraphicsView (harita);



	
// connect( CbGpsOnOff, SIGNAL( stateChanged ( int )   ), this, SLOT(setGPSState(int) ));
// connect( this, SIGNAL( connected ( )   ), this, SLOT(connectGPS() ));
// connect( this, SIGNAL( disconnected ( )   ), this, SLOT(disconnectGPS() ));
// connect(pushButton,SIGNAL( pressed ( )   ), this, SLOT(scen() ));
}
void Harita::scen()
{

}
 void Harita::mousePressEvent(QMouseEvent *mouseEvent)
 {
//            scene.addItem(&tex);
// addItem(textItem);
//             tex->setDefaultTextColor(myTextColor);
//             tex.setPos(mouseEvent->pos());
qDebug("X=%d",mouseEvent->x());
//             emit textInserted(textItem);
//     default:
//         ;
//     }
//     QGraphicsScene::mousePressEvent(mouseEvent);
//      if (QGraphicsItem *item =view.itemAt(event->scenePos())) {
//          qDebug() << "You clicked on item" << item;
//      } else {
//          qDebug() << "You didn't click on an item.";
//      }
 }
*/
#include <QtGui>

// #include "diagramscene.h"
// #include "arrow.h"

Harita::Harita( QObject *parent)
    : QGraphicsScene(parent)
{
connect( this, SIGNAL( emlemHareket ( double)   ), this, SLOT(Y2Enlem(double) ));
connect( this, SIGNAL( boylamHareket ( double)   ), this, SLOT(X2Boylam(double) ));
//     myItemMenu = itemMenu;
//     myMode = MoveItem;
//     myItemType = DiagramItem::Step;
//     line = 0;
//     textItem = 0;
//     myItemColor = Qt::white;
//     myTextColor = Qt::black;
//     myLineColor = Qt::black;

}
/*
QString Harita::Y2Enlem(double yimage)
{
// QStringList tmp=msail.RotaVeMesafe(initialEnlem,initialEnlemYon,initialBoylam,initialBoylamYon, hedefEnlem,hedefEnlemYon,hedefBoylam,hedefBoylamYon);
// QStringList tmp=msail.RotaVeMesafe("4040,000","N","02616,500","E", "4021,500","N","02616,500","E");

// QStringList tmp=msail.RotaVeMesafe("3839,000","N","02633,000","E", "3830,000","N","02633,000","E");

// double solUstEnlem=msail.dm2dd("4041,000","N");//90.0000
// double sagAltEnlem=msail.dm2dd("4021,000","N");//-90.0000

// double Y = msail.MeridyenParcasi(solUstEnlem);
// double A = msail.MeridyenParcasi(sagAltEnlem);

// double sign = 1.;
// if(solUstEnlem<=0.){
// 	Y = Y*sign;
// }
// if(sagAltEnlem <=0.){
// 	A = A*sign;
// qDebug("A degisen= %f",A);
// }
// double YGercekUzunluk= Y-A;
double YGercekUzunluk=tmp[1].toDouble();//NM olarak
double olcekY=YGercekUzunluk/2575.0;//yimage
double convfaktor=olcekY*currentPosY;
qDebug("EnlemConvFaktor= %f",YGercekUzunluk);
//  QStringList Dreb=msail.DrMevkii("3839,000","N","02633,000","W",180.,convfaktor);
 QString Enlem=msail.toDMS(Dreb.at(0).toDouble(),"NS");
 qDebug()<<"Mouse Enlemi = "<<Enlem;
return Enlem;

}

QString Harita::X2Boylam(double ximage)
{
// QStringList tmp=msail.RotaVeMesafe("4040,000","N","02616,000","E", "4040,000","N","02651,600","E");

// double solUstEnlem=msail.dm2dd("4041,000","N");//90.0000
// double sagAltEnlem=msail.dm2dd("4021,000","N");//-90.0000
//  double solUstBoylam=26.275;//derece olarak
//  double sagAltBoylam=26.86;
double solUstBoylam=msail.dm2dd("02633,000","E");//90.0000
double sagAltBoylam=msail.dm2dd("02651,300","E");
// double Y = msail.MeridyenParcasi(solUstEnlem);
// double A = msail.MeridyenParcasi(sagAltEnlem);

// double sign = 1.;
// if(solUstEnlem<=0.){
// 	Y = Y*sign;
// }
// if(sagAltEnlem <=0.){
// 	A = A*sign;
// qDebug("A degisen= %f",A);
// }
// double YGercekUzunluk= Y-A;
// double XGercekUzunluk=tmp[1].toDouble();//NM olarak
double XGercekUzunluk=(sagAltBoylam-solUstBoylam)*60.;
double olcekX=XGercekUzunluk/4185.0;//ximage35
double convfaktor=olcekX*currentPosX;
// qDebug("BoylamConvFaktor= %f",convfaktor);
//  QStringList Dreb=msail.BirSaatSonra("4040,000","N","02616,000","E",090.,convfaktor);
double yeniboylam=convfaktor/60.+solUstBoylam;
//  QString Boylam=msail.toDMS(Dreb.at(1).toDouble(),"EW");
// qDebug()<<"Mouse Boylami = "<<Boylam;
QString Boylam=msail.toDMS(yeniboylam,"EW");
// qDebug()<<"Mouse Boylami = "<<Boylam;
return Boylam;



}
*/
/*
void DiagramScene::setLineColor(const QColor &color)
{
    myLineColor = color;
    if (isItemChange(Arrow::Type)) {
        Arrow *item =
            qgraphicsitem_cast<Arrow *>(selectedItems().first());
        item->setColor(myLineColor);
        update();
    }
}

void DiagramScene::setTextColor(const QColor &color)
{
    myTextColor = color;
    if (isItemChange(DiagramTextItem::Type)) {
        DiagramTextItem *item =
            qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
        item->setDefaultTextColor(myTextColor);
    }
}

void DiagramScene::setItemColor(const QColor &color)
{
    myItemColor = color;
    if (isItemChange(DiagramItem::Type)) {
        DiagramItem *item =
            qgraphicsitem_cast<DiagramItem *>(selectedItems().first());
        item->setBrush(myItemColor);
    }
}

void DiagramScene::setFont(const QFont &font)
{
    myFont = font;

    if (isItemChange(DiagramTextItem::Type)) {
        QGraphicsTextItem *item =
            qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
        item->setFont(myFont);
    }
}

void DiagramScene::setMode(Mode mode)
{
    myMode = mode;
}

void DiagramScene::setItemType(DiagramItem::DiagramType type)
{
    myItemType = type;
}

void DiagramScene::editorLostFocus(DiagramTextItem *item)
{
    QTextCursor cursor = item->textCursor();
    cursor.clearSelection();
    item->setTextCursor(cursor);

    if (item->toPlainText().isEmpty()) {
        removeItem(item);
        item->deleteLater();
    }
}
*/
void Harita::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//  textItem = new QGraphicsTextItem(Y2Enlem(1.)+" "+X2Boylam(1.));
//             textItem->setFont(myFont);
//             textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
//             textItem->setZValue(1000.0);
//             connect(textItem, SIGNAL(lostFocus(DiagramTextItem *)),
//                     this, SLOT(editorLostFocus(DiagramTextItem *)));
//             connect(textItem, SIGNAL(selectedChange(QGraphicsItem *)),
//                     this, SIGNAL(itemSelected(QGraphicsItem *)));
            addItem(textItem);
//             textItem->setDefaultTextColor(myTextColor);
            textItem->setPos(mouseEvent->scenePos());
/*
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    DiagramItem *item;
    switch (myMode) {
        case InsertItem:
            item = new DiagramItem(myItemType, myItemMenu);
            item->setBrush(myItemColor);
            addItem(item);
            item->setPos(mouseEvent->scenePos());
            emit itemInserted(item);
            break;
        case InsertLine:
            line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                                        mouseEvent->scenePos()));
            line->setPen(QPen(myLineColor, 2));
            addItem(line);
            break;
        case InsertText:
            textItem = new DiagramTextItem();
            textItem->setFont(myFont);
            textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
            textItem->setZValue(1000.0);
            connect(textItem, SIGNAL(lostFocus(DiagramTextItem *)),
                    this, SLOT(editorLostFocus(DiagramTextItem *)));
            connect(textItem, SIGNAL(selectedChange(QGraphicsItem *)),
                    this, SIGNAL(itemSelected(QGraphicsItem *)));
            addItem(textItem);
            textItem->setDefaultTextColor(myTextColor);
            textItem->setPos(mouseEvent->scenePos());
            emit textInserted(textItem);
    default:
        ;
    }*/
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void Harita::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//   qDebug("x= %f",mouseEvent->scenePos().x());
  qDebug("x= %f,y= %f",mouseEvent->scenePos().x(),mouseEvent->scenePos().y());
currentPosY=mouseEvent->scenePos().y();
currentPosX=mouseEvent->scenePos().x();
emit emlemHareket(mouseEvent->scenePos().y());
emit boylamHareket(mouseEvent->scenePos().x());
/*
    if (myMode == InsertLine && line != 0) {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    } else if (myMode == MoveItem) {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
*/
  QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void Harita::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
/*
    if (line != 0 && myMode == InsertLine) {
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0 &&
            startItems.first()->type() == DiagramItem::Type &&
            endItems.first()->type() == DiagramItem::Type &&
            startItems.first() != endItems.first()) {
            DiagramItem *startItem =
                qgraphicsitem_cast<DiagramItem *>(startItems.first());
            DiagramItem *endItem =
                qgraphicsitem_cast<DiagramItem *>(endItems.first());
            Arrow *arrow = new Arrow(startItem, endItem);
            arrow->setColor(myLineColor);
            startItem->addArrow(arrow);
            endItem->addArrow(arrow);
            arrow->setZValue(-1000.0);
            addItem(arrow);
            arrow->updatePosition();
        }
    }
    line = 0;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
*/
}
/*
bool DiagramScene::isItemChange(int type)
{
    foreach (QGraphicsItem *item, selectedItems()) {
        if (item->type() == type)
            return true;
    }
    return false;
}

*/

