#pragma once

class AbstractQueue
{
protected:
	unsigned int count_of_item;
	virtual void rem() = 0;
public:
	AbstractQueue(void);
	virtual ~AbstractQueue(void);
	unsigned int getSize() const;	
	void remAll();// = 0;	
	//virtual void push() = 0;	
};
