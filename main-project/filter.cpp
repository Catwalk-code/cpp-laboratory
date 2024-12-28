#include "filter.h"
#include <cstring>
#include <iostream>

GoodsSubscription** filter(GoodsSubscription* array[], int size, bool (*check)(GoodsSubscription* element), int& result_size)
{
	GoodsSubscription** result = new GoodsSubscription * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_GoodsSubscription_by_promtovari(GoodsSubscription* element)
{
	return element->category.categoryofgoods == "Промтовары";
		
}

bool check_GoodsSubscription_by_price(GoodsSubscription* element)
{
	return element->price.money>100;
}

