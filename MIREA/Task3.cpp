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
	double m, p, n, S, m_perm;
	std::cin >> m >> n >> S;
	m_perm = 0;
	p = DBL_MAX/2;
	double diff = m - m_perm;
	double endValue = DBL_MAX;
	double startValue = 0;
	while (diff > 0.1)
	{
		m_perm = S * r_calc(p) * pow(1 + r_calc(p), n) / (12 * (pow(1 + r_calc(p), n) - 1));
		if (m_perm > m)
		{
			endValue = p;
			p = p - (p - startValue)/2;
		}
		else
		{
			startValue = p;
			p = p + (endValue - p)/2;
		}
		diff = abs(m_perm - m);
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

void Task3::task5() {
	std::string sorted;
	std::string String30;
	std::cin >> String30;
	char number_to_paste = 0;
	for (int i = 0; i < String30.length(); i++)
	{
		for (int j = 0; j < String30.length(); j++) {
			if (String30[i] > String30[j])
			{
				number_to_paste = String30[i];
				String30[i] = String30[j];
				String30[j] = number_to_paste;
				i = 0;
				break;
			}
		}
	}
	std::cout << String30;
}

double Task3::r_calc(double p) {
	return p / 100;
}
