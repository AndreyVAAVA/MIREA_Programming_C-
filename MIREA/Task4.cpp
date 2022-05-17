#include "Task4.h"

void Task4::task1(std::string path)
{
	srand(time(0));
	std::ofstream fout(path);
	if (!fout)
	{
		std::cout << "you entered wrong file name or file doesn't exists";
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			fout << rand() % 1000 - 500;
			fout << " ";
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
		else
		{
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
	}

}

int Task4::task2(double x)
{
	return x > 0 ? 1 : x == 0 ? 0 : -1;
}

void Task4::task3()
{
	std::string namesArray[3] = { "triangle", "circle", "rectangle" };
	std::printf("You want %s, %s or %s area?\nEnter here figure name: ", namesArray[0].c_str(), namesArray[1].c_str(), namesArray[2].c_str());
	std::string figureName;
	std::cin >> figureName;
	std::transform(figureName.begin(), figureName.end(), figureName.begin(),
		[](unsigned char c) { return std::tolower(c); });
	if (figureName == namesArray[0])
	{
		std::cout << "Enter a, b, c: ";
		double a, b, c;
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
		if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a)
			std::cout << "Area = " << triangleArea(a, b, c) << "\n";
		else
			std::printf("%s does not exists\n", namesArray[0].c_str());
	}
	else if (figureName == namesArray[1])
	{
		std::cout << "Enter R: ";
		double R;
		std::cin >> R;
		if (R > 0)
			std::cout << "Area = " << circleArea(R) << "\n";
		else
			std::printf("%s does not exists\n", namesArray[1].c_str());
	}
	else if (figureName == namesArray[2])
	{
		std::cout << "Enter a, b: ";
		double a, b;
		std::cin >> a;
		std::cin >> b;
		if (a > 0 && b > 0)
			std::cout << "Area = " << rectangleArea(a, b) << "\n";
		else
			std::printf("%s does not exists\n", namesArray[2].c_str());
	}
	else
	{
		std::cout << "There is an error in name";
	}
}

void Task4::task4()
{
	bool isFilleedRed = true;
	//177, 219
	for (int j = 0; j < 6; j++)
	{
		std::cout << "*";
		for (int i = 0; i < 7; i++) std::cout << " *";
		for (int i = 0; i < 35; i++) std::cout << char(isFilleedRed ? 177 : 219);
		isFilleedRed = !isFilleedRed;
		std::cout << "\n";
	}
	for (int i = 0; i < 7; i++)
	{
		for (int i = 0; i < 36 + 7 * 2; i++) std::cout << char(isFilleedRed ? 177 : 219);
		isFilleedRed = !isFilleedRed;
		std::cout << "\n";
	}
	/*
		&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&################################################
		&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&################################################
		&& &&& &&& &&& &&& &&& &&& &&& &
		&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&################################################
		&& &&& &&& &&& &&& &&& &&& &&& &
		&& &&& &&& &&& &&& &&& &&& &&& &
		&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&################################################
		&& &&& &&& &&& &&& &&& &&& &&& &
		&& &&& &&& &&& &&& &&& &&& &&& &################################################
		&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&################################################

		################################################################################


		################################################################################

		################################################################################
	*/
}

void Task4::task5()
{
	//std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	float x;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 0, 85, NULL);
	LineTo(hDC, 200, 85);
	/*MoveToEx(hDC, 100, 0, NULL);
	LineTo(hDC, 100, 170);*/
	int scale = 10;
	for (x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - center
	{
		MoveToEx(hDC, scale * x + 100, -scale * sin(x) + 85, NULL);
		LineTo(hDC, scale * x + 100, -scale * sin(x) + 85);
	}
	// If first doesn't work, try this
	/*HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	int x = 0;
	for (float i = 0; i < 3.14 * 10; i += 0.05)
	{
		SetPixel(hdc, x, 50 + 25 * cos(i), RGB(255, 255, 255));
		x += 1;
	}

	ReleaseDC(hwnd, hdc);
	std::cin.ignore();*/
}

void Task4::task6()
{
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
			next_elem = roamNumbers.at(read[i + 1]);
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

long Task4::task7(int m, int b, int c, long i)
{
	long S = 0;
	for (int j = 0; j < i + 1; j++) S = (m * S + b) % c;
	return S;
}

void Task4::task8()
{
	int a[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
	float b[4][2] = { {1.20, 0.50}, {2.8, 0.4}, {5.0, 1.0}, {2.0, 1.5} };
	float money[3][4];
	float moneySum[3] = { 0, 0, 0 };
	float totalMoney = 0;
	float commisions[3][4];
	float commisionsSum[3] = { 0, 0, 0 };
	float totalComissions = 0;
	float diff[3][4];
	float diffSum[3] = { 0, 0, 0 };
	float totalDiff = 0;
	for (int i = 0; i < sizeof(a) / sizeof(*a); i++)
	{
		for (int j = 0; j < sizeof(a[i]) / sizeof(*a[i]); j++)
		{
			money[i][j] = a[i][j] * b[j][0];
			moneySum[i] += money[i][j];
			commisions[i][j] = a[i][j] * b[j][1];
			commisionsSum[i] += commisions[i][j];
			diff[i][j] = a[i][j] * (b[j][0] - b[j][1]);
			diffSum[i] += diff[i][j];
		}
		totalMoney += moneySum[i];
		totalComissions += commisionsSum[i];
		totalDiff += diffSum[i];
	}
	std::cout << "1.Money\n2.Comissions\n3.Difference\n";
	for (int i = 0; i < 3; i++)
	{
		printf("Seller %i m - %f c - %f d - %f\n", i + 1, moneySum[i], commisionsSum[i], diffSum[i]);
	}
	printf("Total money - %f, commissions - %f, difference - %f", totalMoney, totalComissions, totalDiff);

}

void Task4::task9(std::string number, byte systemNumberWas, byte systemNumberWanted)
{
	std::map<char, byte> stringNumbers;
	std::map<byte, char> numbersString;
	byte counter = 10;
	for (byte i = 65; i <= 90; i++)
	{
		stringNumbers[char(i)] = counter;
		numbersString[counter++] = char(i);
	}
	byte maxCharIndex = systemNumberWas;
	long newNumberIn10 = 0;
	int a = 0;
	if (systemNumberWas != 10) {
		for (int i = 0; i < number.length(); i++)
		{
			if (stringNumbers.count(number.at(i)) > 0) {
				newNumberIn10 += stringNumbers.at(number.at(i)) * pow(systemNumberWas, number.length() - (i + 1));
			}
			else
			{
				newNumberIn10 += (number.at(i) - '0') * pow(systemNumberWas, number.length() - (i + 1));
			}
		}
	}
	else
	{
		newNumberIn10 = std::stol(number);
	}

	number = std::to_string(newNumberIn10);

	std::cout << newNumberIn10 << "\n";
	std::string newNumberIn = "";
	int currNumber = 0;
	while (newNumberIn10 >= systemNumberWanted)
	{
		currNumber = newNumberIn10 % systemNumberWanted;
		newNumberIn10 /= systemNumberWanted;
		if (numbersString.count(currNumber) > 0) {
			newNumberIn += numbersString.at(currNumber);
		}
		else
		{
			newNumberIn += std::to_string(currNumber);
		}
	}
	newNumberIn += std::to_string(newNumberIn10);
	std::reverse(newNumberIn.begin(), newNumberIn.end());
	std::cout << newNumberIn;

}

double Task4::circleArea(double R)
{
	return R * R * M_PI;
}

double Task4::rectangleArea(double a, double b)
{
	return a * b;
}

double Task4::triangleArea(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
