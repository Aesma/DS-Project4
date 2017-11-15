#include "showGraph.h"

showGraph::showGraph()
{
	setupUi(this);

	n = 0;
	scene = new QGraphicsScene(0, 0, width() - 20, height() - 20);
	view = new QGraphicsView;
	view->setScene(scene);
	setCentralWidget(view);

	connect(scene, SIGNAL(selectionChanged()), this, SLOT(generateScene()));
}

void showGraph::setGraph(Graphlink<char, int>&g)
{
	graph = g;

	clearOldGraph();
	emit scene->selectionChanged();
}

void showGraph::clearOldGraph()
{
	for (int i = 0; i < n; i++)
	{
		scene->removeItem(&item[i]);
	}
	
	//delete[]item;
}

void showGraph::generateScene()
{
	n = graph.NumberOfVertices();
	item = new NewItem[n];
	QGraphicsTextItem *textItem = new QGraphicsTextItem[n];
	for (int i = 0; i < n; i++)
	{
		item[i].setNodeTable(graph.getNode(i));
		item[i].setPos(QPoint(90, 20 + i * 30));
		textItem[i].setPlainText(QString::number(i));
		textItem[i].setPos(QPoint(70, 25 + i * 30));

		scene->addItem(&textItem[i]);
		scene->addItem(&item[i]);
	}
}

void showGraph::paintEvent(QPaintEvent *event)
{
	scene->setSceneRect(0, 0, width() - 20, height() - 20);
}

showGraph::~showGraph()
{

}