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
	void dealEdit(const QString &text);//һ��ʼд��ʱ����ź�Ū���� Ȼ���ֲ���ĺ������������������ûɶ�á���
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
