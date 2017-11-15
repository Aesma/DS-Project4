#ifndef GRAPHMTX_H
#define GRAPHMTX_H

#pragma execution_character_set("utf-8")

#define DefaultVertices 30

#include "MinSpanTree.h"

#include <QtGui>
#include <cstdio>
#include <QMessageBox>

template <class T,class E>
struct GraphNode
{
	int head;
	int tail;
	E cost;
	GraphNode(GraphNode &n)
	{
		head = n.head;
		tail = n.tail;
		cost = n.cost;
	}
	GraphNode():tail(-1), head(-1), cost(0){};
};

template <class T,class E>
class Graphmtx
{
public:
	Graphmtx(int sz = DefaultVertices);
	Graphmtx(Graphmtx<T, E>&G);
	T getValue(int i){ return i >= 0 && i <= numVertices ? VerticesList[i] : NULL; };
	E getWeight(int v1, int v2){ return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0; };
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	int getVertexPos(T vertex);	
	int NumberOfVertices(){ return numVertices; };
	int NumberOfEdges(){ return numEdges; };
	bool insertVertex(const T& vertex);
	bool insertEdge(int v1, int v2, E cost);
	bool removeVertex(int v);
	bool removeEdge(int v1, int v2);
	void Kruskal(MinSpanTree<T, E>&MST);
	GraphNode<T,E> getEdge(int i);
	~Graphmtx();
private:
	T *VerticesList;
	E **Edge;
	int maxVertices;
	int numEdges;
	int numVertices;
	int maxWeight;
	int count;
	GraphNode<T, E> graphNode[9];
};

template <class T,class E>
Graphmtx<T, E>::Graphmtx(int sz)
{
	maxVertices = sz;
	maxWeight = -1;
	numVertices = 0;
	numEdges = 0;
	count = 0;
	int i, j;
	VerticesList = new T[maxVertices];
	Edge = new E*[maxVertices];
	for (int i = 0; i < maxVertices;i++)
	{
		Edge[i] = new E[maxVertices];
	}
	for (int i = 0; i < maxVertices; i++)
	for (int j = 0; j < maxVertices; j++)
	{
		Edge[i][j] = (i == j) ? 0 : maxWeight;
	}
}

template <class T,class E>
Graphmtx<T, E>::Graphmtx(Graphmtx<T, E>&G)
{
	for (int i = 0; i < 9; i++)
		graphNode[i] = G.graphNode[i];
	maxVertices = G.maxVertices;
	numEdges = G.numEdges;
	numVertices = G.numVertices;
	maxWeight = G.maxWeight;
	count = G.count;
	VerticesList = new T[maxVertices];
	Edge = new E*[maxVertices];
	for (int i = 0; i < maxVertices; i++)
	{
		Edge[i] = new E[maxVertices];
	}
	for (int i = 0; i < maxVertices; i++)
		VerticesList[i] = G.VerticesList[i];
	for (int i = 0; i < maxVertices; i++)
	for (int j = 0; j < maxVertices; j++)
	{
		Edge[i][j] = G.Edge[i][j];
	}
}

template <class T,class E>
GraphNode<T,E> Graphmtx<T, E>::getEdge(int i)
{
	return graphNode[i];
}

template <class T,class E>
int Graphmtx<T, E>::getFirstNeighbor(int v)
{
	if (v != -1){
		for (int col = 0; col < numVertices;col++)
		if (Edge[v][col]>0)
			return col;
	}	QMessageBox::information(NULL, "FAIL",
		"未能找到该顶点的邻接顶点.");
	return -1;
}

template <class T,class E>
int Graphmtx<T, E>::getNextNeighbor(int v, int w)
{
	if (v != -1 && w != -1){
		for (int col = w + 1; col < numVertices;col++)
		if (Edge[v][col]>0)
			return col;
	}
	QMessageBox::information(NULL, "FAIL",
		"未能找到该顶点的邻接顶点的下一邻接顶点.");
	return -1;
}

template <class T,class E>
bool Graphmtx<T, E>::insertVertex(const T& vertex)
{
	if (numVertices == maxVertices)
		return false;
	VerticesList[numVertices++] = vertex;
	return true;
}

template <class T,class E>
bool Graphmtx<T, E>::removeVertex(int v)
{
	if (v < 0 || v >= numVertices)
		return false;
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];
	for (int i = 0; i < numVertices;i++)
	if (Edge[i][v]>0)
		numEdges--;
	for (int i = 0; i < numVertices; i++)
		Edge[i][v] = Edge[i][numVertices - 1];
	numVertices--;
	for (int i = 0; j < numVertices; j++)
		Edge[v][j] = Edge[numVertices][j];
	return true;
}

template <class T,class E>
bool Graphmtx<T, E>::insertEdge(int v1, int v2, E cost)
{
	if (v1>-1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2] == maxWeight){
		Edge[v1][v2] = Edge[v2][v1] = cost;
		graphNode[count].cost = cost;
		graphNode[count].head = v1;
		graphNode[count++].tail = v2;
		numEdges++;
		return true;
	}
	else
		return false;
}

template <class T,class E>
bool Graphmtx<T, E>::removeEdge(int v1, int v2)
{
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2] == maxWeight&&Edge[v1][v2]>0){
		Edge[v1][v2] = Edge[v2][1] = maxWeight;
		numEdges--;
		return true;
	}
	else
		return false;
}

template <class T,class E>
int Graphmtx<T, E>::getVertexPos(T vertex)
{
	for (int i = 0; i < numVertices;i++)
	if (VerticesList[i] = Vertex)
		return i;
	QMessageBox::information(NULL, "FAIL",
		"未能找到该顶点.");
	return -1;
}

template<class T,class E>
void Graphmtx<T, E>::Kruskal(MinSpanTree<T, E>&MST)
{
	MSTEdgeNode<T, E>ed;
	int u, v, count;
	int n = NumberOfVertices();
	int m = NumberOfEdges();
	MinHeap<MSTEdgeNode<T, E>>H(m);
	UFSets F(n);
	for (u = 0; u < n; u++)
	for (v = u + 1; v < n; v++)
	{
		if (getWeight(u, v) != maxValue){
			ed.tail = u;
			ed.head = v;
			ed.key = getWeight(u, v);
			H.Insert(ed);
		}
	}
	count = 1;
	while (count < n)
	{
		H.RemoveMin(ed);
		u = F.Find(ed.tail);
		v = F.Find(ed.head);
		if (u != v){
			F.Union(u, v);
			MST.Insert(ed);
			count++;
		}
	}
}

template <class T,class E>
Graphmtx<T, E>::~Graphmtx()
{
	delete[]VerticesList;
	for (int i = 0; i < maxVertices; i++)
		delete[]Edge[i];
	delete[]Edge;
}

#endif