#include <iostream>

int main()
{
    long double x, a, b, c;
    std::cin >> x;
    c = 23 * x * x;
    a = 3 * c + 8;
    b = x * (c + 32);
    std::cout << a + b << "\n" << a - b;
    return 0;
}