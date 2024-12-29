#include "processing.h"
#include <string>
using namespace std;
double process(GoodsSubscription* array[], int size, string category)
{
	double sum = 0;
	for (int i = 0;i < size;i++) {
		if (array[i]->category.categoryofgoods == category) {
			sum += array[i]->price.money;
		}
	}
	return sum;
}
