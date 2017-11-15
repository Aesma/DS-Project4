#ifndef GRAPHLINK_H
#define GRAPHLINK_H

#pragma execution_character_set("utf-8")

#define DefaultVertices 30

#include "stack.h"
#include "SeqQueue.h"

#include <QtGui>
#include <cstdio>
#include <iostream>
#include <QMessageBox>

template <class T, class E>
struct Edge
{
	int dest;
	E cost;
	Edge<T, E> *link;
	Edge(){};
	Edge(int num, E weight) :dest(num), cost(weight), link(NULL){};
	bool operator !=(Edge<T, E>&R)const
	{
		return (dest != R.dest) ? true : false;
	}
};

template <class T,class E>
struct Vertex
{
	T data;
	Edge<T, E>*adj;
	Vertex(){};
	Vertex(Vertex& v)
	{
		data = v.data;
		adj = v.adj;
	}
};

template <class T,class E>
class Graphlink
{
public:
	Graphlink(int sz = DefaultVertices);
	T getValue(int i)
	{
		return (i >= 0 && i < numVertices) ? NodeTable[i].data : 0;
	}
	E getWeight(int v1, int v2);
	bool insertVertex(const T& vertex);
	bool removeVertex(int v);
	bool insertEdge(int v1, int v2/*, E cost*/);
	bool removeEdge(int v1, int v2);
	bool GraphEmpty()const
	{
		if (numEdges == 0)
			return true;
		return false;
	}
	bool GraphFull()const
	{
		if (numVertices == maxVertices || numEdges == maxVertices*(maxVertices - 1) / 2)
			return true;
		return false;
	}
	int NumberOfVertices(){ return numVertices; };
	int NumberOfEdges(){ return numEdges; };
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	int getVertexPos(const T vertex);
	Vertex<T, E>getNode(int v);
	QString BFS(T v);
	QString DFS(T v);
	~Graphlink();
private:
	Vertex<T, E>*NodeTable;
	int maxVertices;
	int numEdges;
	int numVertices;
};

template <class T,class E>
Graphlink<T, E>::Graphlink(int sz)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	NodeTable = new Vertex<T, E>[maxVertices];
	if (NodeTable == NULL){
		QMessageBox::warning(NULL, ("Error"),
			("¥¢¥Ê∑÷≈‰¥ÌŒÛ!"));
		exit(1);
	}
	for (int i = 0; i < maxVertices; i++)
		NodeTable[i].adj = NULL;
}

template <class T,class E>
Vertex<T, E> Graphlink<T, E>::getNode(int i)
{
	return NodeTable[i];
}

template <class T,class E>
int Graphlink<T,E>::getVertexPos(const T vertex)
{
	for (int i = 0; i < numVertices; i++)
	{
		if (NodeTable[i].data == vertex)
			return i;
	}
	return -1;
}

template <class T,class E>
int Graphlink<T, E>::getFirstNeighbor(int v)
{
	if (v != -1){
		Edge<T, E>*p = NodeTable[v].adj;
		if (p != NULL)
			return p->dest;
	}
	return -1;
}

template <class T,class E>
int Graphlink<T, E>::getNextNeighbor(int v, int w)
{
	if (v != -1){
		Edge<T, E>*p = NodeTable[v].adj;
		while (p != NULL&&p->dest != w)
			p = p->link;
		if (p != NULL&&p->link != NULL)
			return p->link->dest;
	}
	return -1;
}

template <class T,class E>
E Graphlink<T, E>::getWeight(int v1, int v2)
{
	if (v1 != -1 && v2 != -1){
		Edge<T, E>*p = NodeTable[v1].adj;
		while (p != NULL&&p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL)
			return p->cost;
	}
	return 0;
}


template <class T, class E>
bool Graphlink<T, E>::insertVertex(const T&vertex)
{
	if (numVertices == maxVertices)
		return false;
	NodeTable[numVertices].data = vertex;
	numVertices++;
	return true;
}

template <class T,class E>
bool Graphlink<T, E>::removeVertex(int v)
{
	if (numVertices == 1 || v < 0 || v >= numVertices)
		return false;
	Edge<T, E>*p, *s, *t;
	int i, k;
	while (NodeTable[v].adj != NULL)
	{
		p = NodeTable[v].adj;
		k = p->dest;
		s = NodeTable[k].adj;	
		t = NULL;
		while (s != NULL&&s->dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != NULL){
			NodeTable[k].adj = s->link;
		}
		else
			t->link = s->link;
		delete p;
		numEdges--;
	}
	numVertices--;
	NodeTable[v].data = NodeTable[numVertices].data;
	p = NodeTable[v].adj = NodeTable[numVertices].adj;
	while (p != NULL)
	{
		s = NodeTable[s->dest].adj;
		while (s != NULL)
		{
			if (s->dest == numVertices){
				s->dest = v;
				break;
			}
			else
				s = s->link;
		}
		return true;
	}
}

template <class T,class E>
bool Graphlink<T, E>::insertEdge(int v1, int v2/*, E weight*/)
{
	if (v1 >= 0 && v1 < numVertices&&v2 >= 0 && v2 < numVertices){
		Edge<T, E>*q, *p = NodeTable[v1].adj;
		while (p != NULL&&p->dest != v2)
			p = p->link;
		if (p != NULL)
			return false;
		p = new Edge<T, E>;
		q = new Edge<T, E>;
		p->dest = v2;
		//p->cost = weight;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q->dest = v1;
		//q->cost = weight;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
		return true;
	}
	return 0;
}

template <class T,class E>
bool Graphlink<T, E>::removeEdge(int v1, int v2)
{
	if (v1 != -1 && v2 != -1){
		Edge<T, E>*p = NodeTalbe[v1].adj, *q = NULL, *s = p;
		while (p != NULL&&p->dest != v2)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL){
			if (p == s)
				NodeTable[v1].adj = p->link;
			else
				q->link = p->link;
			delete p;
		}
		else{
			return false;
		}
		p = NodeTable[v2].adj;
		q = NULL;
		s = p;
		while (p->dest != v1)
		{
			q = p;
			p = p->link;
		}
		if (p == s)
			NodeTable[v2].adj = p->link;
		else
			q->link = p->link;
		delete p;
		return true;
	}
	return false;
}

template <class T,class E>
QString Graphlink<T, E>::DFS(T v)
{
	Stack stack;
	QString order;
	int loc;
	bool *visit = new bool[numVertices];
	for (int i = 0; i < numVertices; i++)
		visit[i] = false;
	loc = getVertexPos(v);
	order += getValue(loc);
	stack.Push(loc);
	visit[loc] = true;
	int w = loc;
	int w2 = getFirstNeighbor(w);
	while (!stack.IsEmpty())
	{
		while (w2 != -1)
		{
			if (!visit[w2]){
				visit[w2] = true;
				order += getValue(w2);
				stack.Push(w2);
				w = w2;
				w2 = getFirstNeighbor(w);
				continue;
			}
			w2 = getNextNeighbor(w, w2);
		}
		stack.Pop(w2);
		if (!stack.IsEmpty()){
			stack.Pop(w);
			stack.Push(w);
		}
	}
	delete[]visit;

	return order;
}

template <class T, class E>
QString Graphlink<T, E>::BFS(T v)
{
	QString order;
	int i, w, n = NumberOfVertices();
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false; 
	int loc = getVertexPos(v);
	order += getValue(loc);
	visited[loc] = true;
	SeqQueue<int>Q;
	Q.EnQueue(loc);
	while (!Q.IsEmpty())
	{
		Q.DeQueue(loc);
		w = getFirstNeighbor(loc);
		bool back = false;
		while (w != -1)
		{
			if (!visited[w]){
				if (w == getFirstNeighbor(loc)){
					order += "(";
					back = true;
				}
				order += getValue(w);
				visited[w] = true;
				Q.EnQueue(w);
			}
			w = getNextNeighbor(loc, w);
			if (w == -1 && back){
				order += ")";
				back = false;
			}
		}
	}
	delete[]visited;

	return order;
}

template <class T,class E>
Graphlink<T, E>::~Graphlink()
{
	for (int i = 0; i < numVertices; i++)
	{
		Edge<T, E>*p = NodeTable[i].adj;
		while (p != NULL)
		{
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;
}

#endif 