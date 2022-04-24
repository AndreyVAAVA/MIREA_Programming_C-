#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <map>

class Task4
{
public:
	void task1(std::string path) {
		srand(time(0));
		std::ofstream fout(path);
		if (!fout)
		{
			std::cout << "you entered wrong file name or file doesn't exists";
		}
		for (int i = 0; i < 10; i++)
		{
			fout << rand()%1000 -500;
			fout << " ";
			//srand(i);
		}
		fout.close();
		char el;
		std::string read;
		long sum = 0;
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
					sum += std::stoi(read);
					read = "";
					
				}
			}
		}
		std::cout << sum;
		fin.close();
	}

	int task2(double x) {
		if (x > 0)
		{
			return 1;
		}
		else if (x == 0) 
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	void task3() {
		//177, 219
	}

	void task6() {
		std::map <char, int> roamNumbers;
		roamNumbers['I'] = 1;
		roamNumbers['V'] = 5;
		roamNumbers['X'] = 10;
		roamNumbers['L'] = 50;
		roamNumbers['C'] = 100;
		roamNumbers['D'] = 500;
		roamNumbers['M'] = 1000;
		std::string read;
		std::cin >> read;
		int L_count = 0;
		int D_count = 0;
		long total = 0;
		bool lower = false;
		int current_elem = 0;
		int next_elem = 0;
		for (int i = 0; i < read.length(); i++)
		{
			int current_elem = roamNumbers.at(read[i]);
			if (i != read.length() - 1)
			{
				next_elem = roamNumbers.at(read[i+1]);
			}
			else
			{
				next_elem = 0;
			}
			if (current_elem == 50)
			{
				L_count++;
			}
			if (current_elem == 500)
			{
				D_count++;
			}
			if (D_count > 1 || L_count > 1)
			{
				std::cout << "There is an error with D or L";
			}
			else {
				if (roamNumbers.at(read[i]))
				{
					if (lower == true)
					{
						std::cout << "There is an error";
					}
					else {
						if (current_elem < next_elem && next_elem != 0)
						{
							total += (next_elem - current_elem);
							lower = true;
						}
						else
						{
							total += current_elem;
						}
					}
				}
			}
		}
		std::cout << total;
	}

	long task7(int m, int b, int c, long S, long i) {
		for (int j = 0; j < i+1; j++)
		{
			S = (m * S + b) % c;
;		}
		return S;
	}

	void task8() {

	}
};

