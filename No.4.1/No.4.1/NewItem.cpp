#include "NewItem.h"

NewItem::NewItem()
{

}

void NewItem::setNodeTable(Vertex<char, int>node)
{
	NodeTable = node;
}

QRectF NewItem::boundingRect()const
{
	int i = 0;
	Edge<char, int>*edge = NodeTable.adj;
	while (edge != NULL)
	{
		i++;
		edge = edge->link;
	}


	return QRectF(0, 0, 60 + (50 + 60)*i, 30);
}

void NewItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *poption, QWidget *widget)
{
	painter->setRenderHint(QPainter::Antialiasing);//¿¹¾â³Ý

	painter->setPen(Qt::black);
	painter->drawRect(0, 0, 30, 30);
	painter->drawRect(30, 0, 30, 30);
	painter->drawText(QPoint(10, 20), QString(NodeTable.data));
	painter->translate(QPoint(45, 15));
	if (NodeTable.adj != NULL)
		painter->drawLine(0, 0, 65, 0);
	else
		painter->drawText(-5, 5, "¡Ä");

	QPainterPath path;
	int i = 0;
	Edge<char, int>*edge = NodeTable.adj;
	while (edge != NULL)
	{
		path.moveTo(55, -5);
		path.lineTo(65, 0);
		path.lineTo(55, 5);
		painter->drawPath(path);
		painter->translate(QPoint(65, -15));
		painter->drawRect(0, 0, 30, 30);
		painter->drawRect(30, 0, 30, 30);
		painter->drawText(10, 20, QString::number(edge->dest));
		painter->translate(QPoint(45, 15));
		edge = edge->link;
		if (edge == NULL)
			painter->drawText(-5, 5, "¡Ä");
		else
			painter->drawLine(0, 0, 65, 0);
	}
}

NewItem::~NewItem()
{

}
