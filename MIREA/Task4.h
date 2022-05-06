#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <map>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <cctype>
#include <string>

class Task4
{
public:
	void task1(std::string path);

	int task2(double x);

	void task3();

	void task4();

	void task5();
	
	void task6();

	long task7(int m, int b, int c, long i);

	void task8();

	void task9(std::string number, byte systemNumberWas, byte systemNumberWanted);
private:
	double circleArea(double R);
	double rectangleArea(double a, double b);
	double triangleArea(double a, double b, double c);
};

