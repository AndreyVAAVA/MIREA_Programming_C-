#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>

class Task3
{
private:
	double r_calc(double p);

public:
	void task1();
	void task2();
	void task3(std::string path);
	void task4(std::string path);
	std::string task5(std::string String30);

};

