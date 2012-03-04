#include "IntQueue.h"
#include <iostream>

IntQueue::IntQueue(void) : first(NULL), last(NULL), next(NULL), data(0)
{
}

IntQueue::IntQueue(const IntQueue& queue) //: first(queue.first), last(queue.last), 
{
	//std::cout << "copy" << std::endl;
	unsigned int size = queue.getSize();
	//std::cout << size << std::endl;
	IntQueue * currItem = queue.first;
	IntQueue * Item = new IntQueue;
	for (unsigned int i = 0; i < size; i++)
	{
		//(*this).push(currItem->data);

		Item->push(currItem->data);
		//std::cout << "test " << currItem->data << std::endl;
/*		IntQueue * item = new IntQueue;
		item->data = currItem->data;*/
		currItem = currItem->next;
		//item->next = currItem;
	}
	(*this) = (*Item);
	//std::cout << Item->getSize() << std::endl;
	//this->pop();
	//delete Item;
	//std::cout << this->getSize() << std::endl;
	//std::cout << Item->getSize() << std::endl;
	//first = last = next = NULL;
	//*this = queue;
}

IntQueue::~IntQueue(void)
{
	remAll();
}

void IntQueue::push(int data)
{
	IntQueue* item = new IntQueue;
	item->data = data;
	item->next = NULL;
	if(!first)
	{
		first = item;
		last = item;
	}
	else
	{
		last->next = item;
		last = item;
	}
	count_of_item++;
	return;
}

void IntQueue::pushGroup(int elem_cnt, ...)
{
	int* temp = &elem_cnt;
	for(; elem_cnt; elem_cnt--)
		push(*(++temp));
	return;
}

int IntQueue::pop()
{
	if (count_of_item > 0)
	{
		int data = first->data;
		rem();
		return data;
	}
	else
	{
		std::cout << "Error: (1) count_of_item <= 0" << std::endl;
		return 101;
	}
}

void IntQueue::rem()
{
	if (count_of_item > 0)
	{
		IntQueue* temp = first->next;
		delete first;
		if (!temp)
			first = last = NULL;
		else 
			first = temp;
		count_of_item--;
	} 
	else
	{
		std::cout << "Error: (2) count_of_item <= 0" << std::endl;
	}
	return;
}

/*void IntQueue::remAll()
{
	while (count_of_item > 0)
		rem();
	return;
}*/