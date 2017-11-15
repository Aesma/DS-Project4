#ifndef OLDGRAPH_H
#define OLDGRAPH_H

#include <QMainWindow>
#include <QtGui>

#include "Graphmtx.h"
#include "ui_oldgraph.h"

class OldMainWindow :public QMainWindow, public Ui::OldGraph
{
public:
	OldMainWindow();
	void setGraph(Graphmtx<int, int>g);
	~OldMainWindow();
private:
	void paintEvent(QPaintEvent *event);
private:
	Graphmtx<int, int>graph;
};

#endif