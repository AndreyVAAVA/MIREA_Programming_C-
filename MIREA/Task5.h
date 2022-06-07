#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <algorithm>

#pragma once
class Task5
{
public:
	void task1(long a, long b, bool is1Method);
	void task2(long until);
	void fileProcessingTask19(std::string path);
	void fileProcessingTask32(std::string pathReadFile, std::string pathWriteFile);
	void seriesTask16(double e);
	void seriesTask47();
	void fileTask5(std::string path, long a, long b);
private:
	void findBiggest(long** matrix, long a, long b);
};

