#include "Task3.h"

void Task3::task1() {
	double S, p, n;
	std::cin >> S >> p >> n;
	while (r_calc(p) == 0)
	{
		std::cout << "provide other p";
		std::cin >> p;
	}
	double r = r_calc(p);
	if (n > 0)
	{
		std::cout << "m = " << S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
	}
	else
	{
		std::cout << "There is an error\n";
	}
}
void Task3::task2(double m, double n, double S) {
	//29982
	//10
	//2000000
	long double p, m_var;
	m_var = 0;
	p = 1000;
	long double diff = abs(m - m_var);
	double endValue = 1000000;
	double startValue = 0;
	double middle = 0;

	while ((diff > 0.000000001))
	{
		p = (startValue + endValue) / 2;
		m_var = S * r_calc(p) * pow(1 + r_calc(p), n) / (12 * (pow(1 + r_calc(p), n) - 1));
		if (m_var > m)
		{
			endValue = p - 1;
			/*p = startValue + (endValue - startValue)/2;
			endValue = p;*/
		}
		else
		{
			startValue = p + 1;
			/*p = p + (endValue - startValue)/2;
			startValue = p;*/
		}
		diff = abs(m_var - m);
	}
	std::cout << std::fixed << std::setprecision(7) << p << "\n";
}
void Task3::task3(std::string path) {
	setlocale(LC_ALL, "Ru");
	char el;
	std::ifstream fin(path);
	if (!fin)
	{
		std::cout << "you entered wrong file name or file doesn't exists";
	}
	while (fin.get(el))
	{
		std::cout << el;
	}
	fin.close();
}

void Task3::task4(std::string path) {
	setlocale(LC_ALL, "Ru");
	char el;
	std::string read;
	std::ifstream fin(path);
	if (!fin)
	{
		std::cout << "you entered wrong file name or file doesn't exists";
	}
	while (fin.get(el))
	{
		if (std::isdigit(el))
		{
			read += el;
		}
		else
		{
			if (read != "")
			{
				std::cout << read << " ";
				read = "";
			}
			if (el == '\n')
			{
				std::cout << el;
			}

		}
	}
	if (read != "")
	{
		std::cout << read << " ";
	}
	std::cout << "\n";
	fin.close();
}



void Task3::task5(std::string& str30, int left, int right) {
	int i = left, j = right;
	int mid = str30[(left + right) / 2];

	while (i <= j) {
		while (str30[i] < mid)
			i++;
		while (str30[j] > mid)
			j--;
		if (i <= j) {
			std::swap(str30[i], str30[j]);
			i++; j--;
		}
	};

	if (left < j)
		task5(str30, left, j);
	if (i < right)
		task5(str30, i, right);
}

double Task3::r_calc(double p) {
	return p / 100;
}