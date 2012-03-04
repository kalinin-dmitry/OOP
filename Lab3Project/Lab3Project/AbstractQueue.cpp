#include "AbstractQueue.h"

AbstractQueue::AbstractQueue(void) : count_of_item(0)
{
}

AbstractQueue::~AbstractQueue(void)
{
}
unsigned int AbstractQueue::getSize() const { return count_of_item; } 

void AbstractQueue::remAll(void)
{
	while (count_of_item > 0)
		rem();
}