#include "Task2.h"

void Task2::task1(double R, double r, double l) {
    if (R <= 0 || r <= 0 || l <= 0)
    {
        std::cout << "Some variable is zero or below\n";
        return;
    }
    else {
        if (l * l - pow(R - r, 2) < 0)
        {
            std::cout << "Vaariables are wrong\n";
            return;
        }
        else {
            double h = sqrt(l * l - pow(R - r, 2));
            if (pow(l, 2) != (pow(h, 2) + pow((R - r), 2)))
            {
                std::cout << "There is some problems with numbers. (R-r)^2 + h^2 somehow doesn't equals l^2";
                return;
            }
            std::cout << "V = " << ((1.0 / 3.0) * M_PI * h * (pow(R, 2) + R * r + pow(r, 2))) << "\n";
            std::cout << "S = " << M_PI * (pow(R, 2) + (R + r) * l + pow(r, 2)) << "\n";
        }
    }
}
void Task2::task2(double x, double a) {
    if (fabs(x) < 1 && x != 0)
    {
        std::cout << a * (log(fabs(x))) << "\n";
    }
    else if (fabs(x) >= 1)
    {
        double perm = a - pow(x, 2);
        if (perm >= 0)
        {
            std::cout << sqrt(perm) << "\n";
        }
        else
        {
            std::cout << "There is some problems\n";
        }
    }
    else {
        std::cout << "There is some problems\n";
    }
}
void Task2::task3(double b, double x, double y) {
    if (b - x >= 0 && b - y > 0)
    {
        std::cout << log(b - y) * sqrt(b - x) << "\n";
    }
    else
    {
        std::cout << "There is some problems\n";
    }
}
void Task2::task4() {
    int i = rand() % 10 - 10;
    int until = 11;
    if (i <= 0)
    {
        i = 1;
    }
    else
    {
        until = i + 10;
    }
    for (; i <= until; i++)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void Task2::task5() {
    for (double x = -4; x < 4; x += 0.5)
    {
        if (x == 1)
        {
            std::cout << "Impossible to calc\n";
            ;
        }
        else
        {
            std::cout << funcForTask5(x) << "\n";
        }

    }
}

double Task2::funcForTask5(double x) {
    return (pow(x, 2) - 2 * x + 2) / (x - 1);
}