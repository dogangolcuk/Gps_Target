/***************************************************************************
 *   Copyright (C) 2008 by Doğan Gölcük                                    *
 *   dogangolcuk@gmail.com                                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef HARITA_H
#define HARITA_H

#include <QGraphicsScene>
#include "mercatorsailing.h"
// #include "diagramitem.h"
// #include "diagramtextitem.h"

class QGraphicsSceneMouseEvent;
// class QMenu;
// class QPointF;
// class QGraphicsLineItem;
// class QFont;
 class QGraphicsTextItem;
// class QColor;

class Harita : public QGraphicsScene
{
    Q_OBJECT

public:
//     enum Mode { InsertItem, InsertLine, InsertText, MoveItem };

    Harita(QObject *parent = 0);
mercatorsailing msail;
double currentPosY;
double currentPosX;
//     QFont font() const
//         { return myFont; }
//     QColor textColor() const
//         { return myTextColor; }
//     QColor itemColor() const
//         { return myItemColor; }
//     QColor lineColor() const
//         { return myLineColor; }
//     void setLineColor(const QColor &color);
//     void setTextColor(const QColor &color);
//     void setItemColor(const QColor &color);
//     void setFont(const QFont &font);

public slots:
// QString Y2Enlem(double yimage);
// QString X2Boylam(double ximage);
//     void setMode(Mode mode);
//     void setItemType(DiagramItem::DiagramType type);
//     void editorLostFocus(DiagramTextItem *item);

signals:
void emlemHareket(double);
void boylamHareket(double);
//     void itemInserted(DiagramItem *item);
//      void textInserted(QGraphicsTextItem *item);
//     void itemSelected(QGraphicsItem *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
//     bool isItemChange(int type);

//     DiagramItem::DiagramType myItemType;
//     QMenu *myItemMenu;
//     Mode myMode;
//     bool leftButtonDown;
//     QPointF startPoint;
//     QGraphicsLineItem *line;
//     QFont myFont;
    QGraphicsTextItem *textItem;
//     QColor myTextColor;
//     QColor myItemColor;
//     QColor myLineColor;
};

#endif
