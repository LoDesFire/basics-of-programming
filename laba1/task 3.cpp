#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    long double acc, vel, time;
    std::cin >> acc >> time >> vel;
    std:: cout << std::setprecision(20) << vel * time + (acc * time * time) / (2.0);
    return 0;
}