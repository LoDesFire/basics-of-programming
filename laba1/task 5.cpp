#include <iostream>
#include <iomanip>

int main()
{
    long double a1, a100, s;
    long long d;
    std::cin >> a1 >> a100;
    d = (a100 - a1) / (99.0l);
    std::cout << d << '\n';
    s = (2.0 * a1 + d * 69.0) * 70.0 / 2.0;
    std::cout << std::setprecision(10) << s;
    return 0;
}