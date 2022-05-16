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

void Task5::task2(long until) {
	long* numbersUntil = new long[until];
	for (long i = 2; i < until; i++)
	{
		numbersUntil[i] = i;
	}
	bool isFirstIteration = true;
	for (long i = 2; i < until; i++)
	{
		if (numbersUntil[i] != 0)
		{
			for (long j = i; j < until; j += i)
			{
				if (!isFirstIteration)
				{
					numbersUntil[j] = 0;
				}
				else
				{
					isFirstIteration = false;
				}

			}
			isFirstIteration = true;
		}
	}
	for (long i = 2; i < until; i++)
	{
		if (numbersUntil[i] != 0) std::cout << numbersUntil[i] << " ";
	}
	std::cout << "\n";
}

void Task5::fileTask19()
{
}

void Task5::seriesTask16(double e)
{
}

void Task5::seriesTask47()
{
}
