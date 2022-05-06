#include "Task5.h"

void Task5::task1(long a, long b, bool is1Method)
{
	if (is1Method)
	{
		while (a != b)
		{
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		std::cout << a;
	}
	else
	{
		while (a != 0 && b != 0)
		{
			if (a > b)
				a %= b;
			else
				b %= a;
		}
		std::cout << a + b;
	}
	
}
