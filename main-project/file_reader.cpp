#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

void read(const char* file_name, GoodsSubscription* array[], int& size)
{
	std::ifstream file(file_name);
	if (file.is_open())
	{
		size = 0;
		char tmp_buffer[MAX_STRING_SIZE];
		while (!file.eof())
		{
			GoodsSubscription* item = new GoodsSubscription;
			file >> item->price.money;
			file >> item->quantity;
			file >> item->category.categoryofgoods;
			file.read(tmp_buffer, 1); 
			file.getline(item->naming.nameofgoods, MAX_STRING_SIZE);
			array[size++] = item;
		}
		file.close();
	}
	else
	{
		throw "  ";
	}
}
