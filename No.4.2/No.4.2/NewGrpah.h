#ifndef NEWGRAPH_H
#define NEWGRAPH_H

#include <QMainWindow>
#include <QtGui>

#include "ui_newgraph.h"
#include "Graphmtx.h"

class NewMainWindow :public QMainWindow, public Ui::newGraph
{
public:
	NewMainWindow();
	void setGraph(MinSpanTree<int,int>t);
	~NewMainWindow();
private:
	void paintEvent(QPaintEvent *event);
private:
	MinSpanTree<int, int>tree;
};


#endif