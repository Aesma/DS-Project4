#include "myclass.h"

MyClass::MyClass(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);

	dealControl();
}

void MyClass::dealControl()
{
	connect(vertexLine, SIGNAL(textChanged(const QString &)), this, SLOT(dealEdit(const QString &)));
	connect(ver2Line, SIGNAL(textChanged(const QString &)), this, SLOT(dealEdit(const QString &)));
	connect(ver3Line, SIGNAL(textChanged(const QString &)), this, SLOT(dealEdit(const QString &)));
	connect(begVerLine, SIGNAL(textChanged(const QString &)), this, SLOT(dealEdit(const QString &)));
	connect(vertexButton, SIGNAL(clicked()), this, SLOT(insertVertex()));
	connect(edgeButton, SIGNAL(clicked()), this, SLOT(insertEdge()));
	connect(showButton, SIGNAL(clicked()), this, SLOT(showSurface()));
	connect(dfsButton, SIGNAL(clicked()), this, SLOT(DFS()));
	connect(bfsButton, SIGNAL(clicked()), this, SLOT(BFS()));
}

void MyClass::dealEdit(const QString &text)
{
	if (vertexLine->text() != ""){
		QString str = vertexLine->text();
		str = str.left(1);
		vertexLine->setText(str);
	}
	if (ver2Line->text() != ""){
		QString str = ver2Line->text();
		str = str.left(1);
		ver2Line->setText(str);
	}
	if (ver3Line->text() != ""){
		QString str = ver3Line->text();
		str = str.left(1);
		ver3Line->setText(str);
	}
	if (begVerLine->text() != ""){
		QString str = begVerLine->text();
		str = str.left(1);
		begVerLine->setText(str);
	}
}

void MyClass::insertVertex()
{
	QString str = vertexLine->text();
	if (str == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("未输入结点."));
	}
	QByteArray byte = str.toLocal8Bit();
	char ch = byte[0];
	if (graph.insertVertex(ch)){
		QMessageBox::information(this, tr("Success"),
			tr("顶点插入成功."));
	}
	else{
		QMessageBox::warning(this, tr("Error"),
			tr("顶点插入失败!"));
	}
}

void MyClass::insertEdge()
{
	QString vStr1 = ver2Line->text();
	QString vStr2 = ver3Line->text();
	if (vStr1 == "" || vStr2 == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("顶点输入有错误!"));
		return;
	}
	QByteArray temp = vStr1.toLocal8Bit();
	int v1 = graph.getVertexPos(temp[0]);
	temp = vStr2.toLocal8Bit();
	int v2 = graph.getVertexPos(temp[0]);
	if (graph.insertEdge(v1, v2)){
		QMessageBox::information(this, tr("Success"),
			tr("边插入成功."));
	}
	else{
		QMessageBox::warning(this, tr("Error"),
			tr("边插入失败!"));
	}
}

void MyClass::showSurface()
{
	int v = graph.NumberOfVertices();
	int e = graph.NumberOfEdges();
	if (e > v*(v - 1) / 2 || v == 0){
		QMessageBox::warning(this, tr("Error"),
			tr("错误的图!"));
		return;
	}
	showView.setGraph(graph);

	showView.setWindowModality(Qt::ApplicationModal);
	showView.show();
}

void MyClass::DFS()
{
	QString str = begVerLine->text();
	QByteArray byte = str.toLocal8Bit();
	char ch = byte[0];
	QString order = graph.DFS(ch);

	searchLine->setText(order);
}

void MyClass::BFS()
{
	QString str = begVerLine->text();
	QByteArray byte = str.toLocal8Bit();
	char ch = byte[0];
	QString order = graph.BFS(ch);

	searchLine->setText(order);
}

MyClass::~MyClass()
{

}
