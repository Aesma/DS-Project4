#include "myclass.h"

MyClass::MyClass(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	connect(currentButton, SIGNAL(clicked()), this, SLOT(showOldGraph()));
	connect(doButton, SIGNAL(clicked()), this, SLOT(getNewGraph()));
	connect(newButton, SIGNAL(clicked()), this, SLOT(showNewGraph()));

	makeGraph();
	IsChange = false;
}

void MyClass::makeGraph()
{
	for (int i = 0; i < 7; i++)
		graph.insertVertex(i);
	graph.insertEdge(1, 0, 28);
	graph.insertEdge(2, 1, 16);
	graph.insertEdge(3, 2, 12);
	graph.insertEdge(4, 3, 22);
	graph.insertEdge(5, 0, 10);
	graph.insertEdge(5, 4, 25);
	graph.insertEdge(6, 1, 14);
	graph.insertEdge(6, 3, 18);
	graph.insertEdge(6, 4, 24);
}

void MyClass::showOldGraph()
{
	Old.setGraph(graph);

	Old.show();
}

void MyClass::getNewGraph()
{
	graph.Kruskal(newGraph);

	QMessageBox::information(this, tr("Success"),
		tr("处理完成."));
	IsChange = true;
}

void MyClass::showNewGraph()
{
	if (!IsChange){
		QMessageBox::warning(this, tr("Error"),
			tr("道路没有进行处理!"));
		return;
	}
	New.setGraph(newGraph);

	New.show();
}

MyClass::~MyClass()
{

}
