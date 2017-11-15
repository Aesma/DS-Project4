#ifndef MINSPANTREE_H
#define MINSPANTREE_H

#include "minheap.h"
#include "UFSets.h"

const int maxValue = -1;

template <class T, class E>
struct MSTEdgeNode
{
	MSTEdgeNode(MSTEdgeNode<T, E>&n)
	{
		tail = n.tail;
		head = n.head;
		key = n.key;
	}
	int tail, head;
	E key;
	MSTEdgeNode() :tail(-1), head(-1), key(0){};
	bool operator <=(MSTEdgeNode<T, E>& R){ return key <= R.key; };
	bool operator >(MSTEdgeNode<T, E>& R){ return key > R.key; };
};

template <class T,class E>
class MinSpanTree
{
protected:
	MSTEdgeNode<T, E>*edgevalue;
	int maxSize, n;
public:
	MinSpanTree(int sz = DefaultSize - 1) :maxSize(sz), n(0)
	{
		edgevalue = new MSTEdgeNode<T, E>[sz];
	}
	MinSpanTree(MinSpanTree<T,E>&T);
	bool Insert(MSTEdgeNode<T, E>& item);
	int getNumOfTree(){ return n; };
	MSTEdgeNode<T, E>getMSTEdge(int i){ return edgevalue[i]; };
};

template<class T,class E>
bool MinSpanTree<T,E>::Insert(MSTEdgeNode<T, E>& item)
{
	if (n == maxSize)
		return false;
	edgevalue[n++] = item;

	return true;
}

template <class T,class E>
MinSpanTree<T, E>::MinSpanTree(MinSpanTree<T, E>&t)
{
	maxSize = t.maxSize;
	n = t.n;
	edgevalue = new MSTEdgeNode<T, E>[maxSize];
	for (int i = 0; i < maxSize; i++)
		edgevalue[i] = t.edgevalue[i];
}

#endif