#include "FileReader.h"
//#include <iostream>
#include <fstream>
//#include "IntQueue.h"

FileReader::FileReader(const char * inFileName) : fileName(inFileName)
{
}

FileReader::~FileReader(void)
{
}

void FileReader::ReadQueue(IntQueue* intQueueItem)
{
	std::ifstream input(fileName);
	if (input.fail()) 
	{
		std::cout << "Error: (3) File opening failed!" << std::endl;
		input.close();
		return;
	};
	
	int temp;
	
	while (!input.eof())
	{
		input >> temp;
		//std::cout << temp << std::endl;
		intQueueItem->push(temp);
	}
	/*
	file.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
	char * test = " ";
	file >> test;
	std::cout << test; */
	input.close();
	return;
}

void FileReader::SaveQueue(IntQueue* intQueueItem)
{
	std::ofstream output(fileName);
	if (output.fail())
	{
		std::cout << "Error: (4) Failed to save the file" << std::endl;
		output.close();
		return;
	};
	int temp;
	while (intQueueItem->getSize())
	{
		temp = intQueueItem->pop();
		//std::cout << temp << std::endl;
		output << temp; 
		if (intQueueItem->getSize())
		output << std::endl;
	}
	output.close();
	return;
}
