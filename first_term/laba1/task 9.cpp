#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    a = a ^ b;
    std::cout << "step 1: " << a << " " << b << '\n';
    b = b ^ a;
    std::cout << "step 2: " << a << " " << b << '\n';
    a = a ^ b;
    std::cout << "result: " << a << " " << b << '\n';
    return 0;
}