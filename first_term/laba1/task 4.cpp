#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    long double b;
    std::cin >> b;
    std:: cout << std::setprecision(8) << b / (1.0l - 1.0l/1001.0l);
    return 0;
}