#pragma once
#include <iostream>
#include "IntQueue.h"

class FileReader
{
private:
	const char * fileName;
public:
	FileReader(const char *);
	~FileReader(void);
	
	void ReadQueue(IntQueue*);
	void SaveQueue(IntQueue*);
};
