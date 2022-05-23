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
	delete [] numbersUntil;
	std::cout << "\n";
}

void Task5::fileProcessingTask19(std::string path)
{
	setlocale(LC_ALL, "Ru");
	std::map<char, long> amountOfChars;
	char el;
	std::ifstream fin(path);
	if (!fin)
	{
		std::cout << "you entered wrong file name or file doesn't exists";
	}
	while (fin.get(el))
	{
		amountOfChars[el] = amountOfChars.count(el) > 0 ? amountOfChars[el] + 1 : 1;

	}
	std::map<char, long>::iterator best = std::max_element(amountOfChars.begin(), amountOfChars.end(), [](const std::pair<char, long>& a, const std::pair<char, long>& b)->bool { return a.second < b.second; });
	for (int i = 0; i < amountOfChars.size(); i++)
	{
		if (amountOfChars.at(i) == best->first) std::cout << amountOfChars.at(i);
	}
	fin.close();
}

void Task5::fileProcessingTask32(std::string pathReadFile, std::string pathWriteFile)
{
	setlocale(LC_ALL, "Ru");
	char el;
	std::ifstream fin(pathReadFile);
	std::string result = "";
	if (!fin)
	{
		std::cout << "you entered wrong file name or file doesn't exists";
	}
	while (fin.get(el))
	{
		result += (el + 1);

	}
	fin.close();
	std::ofstream fout(pathWriteFile);
	fout << result;
	fout.close();
}

void Task5::seriesTask16(double e)
{
	long n = 1;
	double oneToThree = 0;
	double y = 0;
	while (oneToThree >= e)
	{
		oneToThree = 1 / pow(3, n);
		y += oneToThree*pow(cos(pow(3, n-1)), 3);
		n++;
	}
	std::cout << y << "\n";
}

void Task5::seriesTask47()
{
	long a, b, a0 = 0, b0 = 0;
	std::cout << "Enter amount of rows:\n";
	std::cin >> a;
	std::cout << "Enter amount of cols:\n";
	std::cin >> b;
	if (a != b)
	{
		std::cout << "Matrix isn't square";
	}
	else
	{
		long** matrix = new long*[a];
		for (long i = 0; i < b; i++)
			matrix[i] = new long[b];
		long value;
		for (long i = 0; i < a; i++)
		{
			for (long j = 0; j < b; j++)
			{
				printf("Enter value for row %d and column %d: ", i+1, j+1);
				std::cin >> value;
				matrix[i][j] = value;
			}
		}
		long diagonalSum = 0;
		for (long i = 0; i < a; i++)
		{
			for (long j = 0; j < b; j++)
			{
				if (i == j)
				{
					diagonalSum += matrix[i][j];
				}
			}
		}
		std::cout << diagonalSum << "\n";
	}
}

void Task5::fileTask5(std::string path)
{

}
