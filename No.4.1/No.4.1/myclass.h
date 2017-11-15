#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QtGui>

#include "ui_myclass.h"
#include "GraphLink.h"
#include "showGraph.h"

class MyClass : public QWidget,public Ui::MyClassClass
{
	Q_OBJECT
public:
	MyClass(QWidget *parent = 0);
	~MyClass();
private:
	void dealControl();
private slots:
	void dealEdit(const QString &text);//一开始写的时候把信号弄错了 然后又不想改函数··所以这个参数没啥用··
	void insertVertex();
	void insertEdge();
	void showSurface();
	void DFS();
	void BFS();
private:
	Graphlink<char, int> graph;
	showGraph showView;
};

#endif // MYCLASS_H
