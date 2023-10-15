#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double height;
    std::cin >> height;
    std::cout << std::setprecision(9) << sqrt(2.0 * height/9.8);
    return 0;
}