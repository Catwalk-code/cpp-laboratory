#include "processing.h"

//  ,      
bool is_leap_year(int year)
{
	if (year % 400)
	{
		if (year % 100)
		{
			return !(year % 4);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

//      
//     1  12
//     ,   0
int days(int month, bool leap_year)
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 2:                                                   return leap_year ? 29 : 28;
	case 4: case 6: case 9: case 11:                          return 30;
	default: return 0;
	}
}

//    ,   1  1-  . .   
int days(date d)
{
	int result = 0;
	for (int year = 1; year < d.year; year++)
	{
		result += is_leap_year(year) ? 366 : 365;
	}
	bool leap_year = is_leap_year(d.year);
	for (int month = 1; month < d.month; month++)
	{
		result += days(month, leap_year);
	}
	result += d.day;
	return result;
}

//    ,    
int diff(date a, date b)
{
	int x = days(a);
	int y = days(b);
	return (x > y ? x - y : y - x) + 1;
}

int process(book_subscription* array[], int size)
{
	int max = diff(array[0]->start, array[0]->finish);
	for (int i = 1; i < size; i++)
	{
		int curr = diff(array[i]->start, array[i]->finish);
		if (curr > max)
		{
			max = curr;
		}
	}
	return max;
}
