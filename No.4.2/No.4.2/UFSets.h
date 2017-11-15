#ifndef UFSETS_H
#define UFSETS_H

#define MAXSIZE 10

class UFSets
{
private:
	int *parent;
	int size;
public:
	UFSets(int sz = MAXSIZE);
	void Union(int Root1, int Root2);
	int Find(int x);
	~UFSets();
};

#endif