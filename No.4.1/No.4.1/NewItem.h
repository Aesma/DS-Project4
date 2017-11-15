#ifndef NEWITEM_H
#define NEWITEM_H

#include "GraphLink.h"

#include <QGraphicsItem>
#include <QtGui>

class NewItem:public QGraphicsItem
{
public:
	NewItem();
	void setNodeTable(Vertex<char, int>Node);
	~NewItem();
protected:
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *poption, QWidget *widget);
private:
	Vertex<char, int>NodeTable;
};

#endif 