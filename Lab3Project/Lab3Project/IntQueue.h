#pragma once
#include "abstractqueue.h"

class IntQueue :
	public AbstractQueue
{
private:
	int data;
	IntQueue* next;
	IntQueue* first;
	IntQueue* last;
	void rem(); 
public:
	IntQueue(void);
	IntQueue(const IntQueue&);
	~IntQueue(void);
	void push(int);	
	void pushGroup(const int, ...);	
	int pop();	
	//void remAll();	
};
