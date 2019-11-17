#include <string>
#include <iostream>
#include "Date.h"

void main()
{
	Date date1;
	Date date2(1, 2, 2030);
	std::cout << "Date1: " << date1 << std::endl;
	std::cout << "Date2: " << date2 << std::endl;
	if (date2 > date1)
	{
		std::cout << "Date2 is bigger" << std::endl;
	}
}