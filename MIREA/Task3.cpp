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
void Task3::task2() {
	//29982
	//10
	//2000000
	double m, p, n, S, m_var;
	std::cin >> m >> n >> S;
	m_var = 0;
	p = DBL_MAX/2;
	double diff = abs(m - m_var);
	double endValue = DBL_MAX/2;
	double startValue = 0;
	double middle = 0;
	while (!(diff >= 0 && diff < 0.1))
	{
		m_var = S * r_calc(p) * pow(1 + r_calc(p), n) / (12 * (pow(1 + r_calc(p), n) - 1));
		p = startValue + (endValue - startValue)/2;
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
	std::cout << p << "\n";
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

std::string Task3::task5(std::string String30) {
	static int a = 0;
	a++;
	std::string pivotString;
	std::string sorted_less;
	std::string sorted_more;
	char number_to_paste = 0;
	char pivot = String30[0];
	for (int i = 0; i < String30.length(); i++)
	{
		if (String30[i] < pivot)
		{
			sorted_less += String30[i];
		}
		else if (String30[i] > pivot)
		{
			sorted_more = String30[i];
		}
		else
		{
			pivotString += String30[i];
		}
	}
	sorted_less = task5(sorted_less);
	sorted_more = task5(sorted_more);
	return sorted_less + pivotString + sorted_more;
}

double Task3::r_calc(double p) {
	return p / 100;
}
