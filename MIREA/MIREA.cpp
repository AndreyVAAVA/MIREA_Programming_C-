// MIREA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

int main()
{
    Task2* obj1 = new Task2();
    Task3* obj2 = new Task3();
    Task4* obj3 = new Task4();
    //obj1->task5();
    //obj2->task3("task3.txt");
    obj3->task6();
    /*obj2->task4("task3.txt");
    obj2->task5();*/
    /*obj2->task4("task3.txt");*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file