#include <iostream>
#include "AbstractQueue.h"
#include "IntQueue.h"
#include "FileReader.h"

int main()
{
	IntQueue q_item1;
	FileReader queue_file("C:\\data.txt");
	int item_count = 5;

	for (int i = 0; i < item_count; i++)
	{
	q_item1.push(i);
	std::cout <<  "q_item1 item: " << i << " " << "q_item1 size: " << q_item1.getSize() << std::endl; 
	}

	IntQueue q_item2 = q_item1;
	std::cout << "q_item2 size: " << q_item2.getSize() << std::endl; 
	
	queue_file.SaveQueue(&q_item1);
	std::cout << "q_item1 size: " << q_item1.getSize() << std::endl; 
	
	q_item2.remAll();

	queue_file.ReadQueue(&q_item2);

	std::cout << "q_item2 size: " << q_item2.getSize() << std::endl; 

	while (q_item2.getSize())
	{
	int i = q_item2.pop();
	std::cout << "q_item2 item: " << i << " " << "q_item2 size: " << q_item2.getSize() << std::endl;
	}
	/*
	i.push(123);
	i.push(1234);
	i.push(12345);
	i.push(123456);
	IntQueue ee = i;
	std::cout <<ee.getSize() << std::endl;		
	std::cout <<i.getSize() << std::endl;	
	ee.pop();
	std::cout <<ee.getSize() << std::endl;		
	std::cout <<i.getSize() << std::endl;
	std::cout << ee.pop()<< std::endl;
	std::cout << ee.pop()<< std::endl;
	ee.remAll();
	std::cout <<ee.getSize() << std::endl;		
	std::cout <<i.getSize() << std::endl;

	std::cout << i.pop()<< std::endl;
	std::cout << i.pop()<< std::endl;
	std::cout << i.pop()<< std::endl;
	std::cout << i.pop()<< std::endl;
	std::cout << i.pop()<< std::endl;
	std::cout << i.pop()<< std::endl;*/

	/*o.SaveQueue(&i);
	std::cout << i.getSize() << std::endl;
	
	o.ReadQueue(&i);
	std::cout << i.getSize() << std::endl;*/
	

	return 0;
}
