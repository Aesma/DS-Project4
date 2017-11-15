#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QDialog>
#include <QtGui>
#include "ui_myclass.h"
#include "Graphmtx.h"
#include "NewGrpah.h"
#include "OldGraph.h"

class MyClass : public QDialog,public Ui::MyClassClass
{
	Q_OBJECT
public:
	MyClass(QWidget *parent = 0);
	~MyClass();
private:
	void makeGraph();
private slots:
	void showOldGraph();
	void getNewGraph();
	void showNewGraph();
private:
	Graphmtx<int, int>graph;
	MinSpanTree<int, int>newGraph;
	NewMainWindow New;
	OldMainWindow Old;
	bool IsChange;
};

#endif // MYCLASS_H
