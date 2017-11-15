#ifndef STACK_H
#define STACK_H

#pragma execution_character_set("utf-8")

#define MAXSIZE 50
#define stackIncreament 20

#include <cassert>
#include <iostream>
#include <QMessageBox>

class Stack
{
public:
	Stack(int size = MAXSIZE);
	void Push(const int &x);
	bool Pop(int &x);
	bool getTop(int &x);
	bool IsEmpty()const{ return(top == -1) ? true : false; };
	bool IsFull()const{ return(top == maxSize - 1) ? true : false; };
	int getSize()const{ return top + 1; };
	void MakeEmpty(){ top = -1; };
	~Stack();
private:
	int *elements;
	int top;
	int maxSize;
private:
	void overflowProcess();
};

#endif