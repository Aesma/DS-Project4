#include "OldGraph.h"

OldMainWindow::OldMainWindow()
{
	setupUi(this);
}

void OldMainWindow::setGraph(Graphmtx<int, int>g)
{
	graph = g;
}

void OldMainWindow::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.translate(100, 50);
	painter.setPen(Qt::black);
	painter.setBrush(Qt::green);
	for (int i = 0; i < 9; i++)
	{
		GraphNode<int, int>node = graph.getEdge(i);
		int hw = 100 * (node.head % 3);
		if (node.head / 3 % 2 == 1){
			hw += 50;
		}
		int hh = 100 * (node.head / 3);
		if (node.head % 3 % 2 == 1){
			hh += 50;
		}
		int tw = 100 * (node.tail % 3);
		if (node.tail / 3 % 2 == 1){
			tw += 50;
		}
		int th = 100 * (node.tail / 3);
		if (node.tail % 3 % 2 == 1){
			th += 50;
		}
		painter.drawLine(hw + 20, hh + 20, tw + 20, th + 20);
		painter.drawEllipse(hw, hh, 40, 40);
		painter.drawEllipse(tw, th, 40, 40);
		painter.drawText(hw + 15, hh + 25, QString(char(node.head + 65)));
		painter.drawText(tw + 15, th + 25, QString(char(node.tail + 65)));
		painter.drawText((hw + tw) / 2 + 10, (hh + th) / 2 + 10, QString::number(node.cost));
	}
}

OldMainWindow::~OldMainWindow()
{

}