#ifndef SHOWGRAPH_H
#define SHOWGRAPH_H

#include <QtWidgets/QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QtGui>

#include "NewItem.h"
#include "ui_GraphicsView.h"

class showGraph :public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
public:
	showGraph();
	void setGraph(Graphlink<char, int>&g);
	~showGraph();
private slots:
	void generateScene();
protected:
	void paintEvent(QPaintEvent *event);
	void clearOldGraph();
private:
	QGraphicsScene *scene;
	QGraphicsView *view;
	NewItem *item;
	Graphlink<char, int>graph; 
	int n;
};

#endif