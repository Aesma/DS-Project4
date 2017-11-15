#include "stack.h"

Stack::Stack(int sz) :top(-1), maxSize(sz)
{
	elements = new int[maxSize];
	assert(elements != NULL);
}

void Stack::overflowProcess()
{
	int *newArray = new int[maxSize + stackIncreament];
	if (newArray == NULL){
		QMessageBox::warning(NULL, "Error",
			"ƒ⁄¥Ê∑÷≈‰ ß∞‹!");
		return;
	}
	for (int i = 0; i <= top; i++)
		newArray[i] = elements[i];
	maxSize = maxSize + stackIncreament;
	delete[]elements;
	elements = newArray;
}

void Stack::Push(const int &x)
{
	if (IsFull()){
		overflowProcess();
	}
	elements[++top] = x;
}

bool Stack::Pop(int &x)
{
	if (IsEmpty())
		return false;
	x = elements[top--];
	return true;
}

bool Stack::getTop(int &x)
{
	if (IsEmpty())
		return false;
	x = elements[top];
	return true;
}

Stack::~Stack()
{

}