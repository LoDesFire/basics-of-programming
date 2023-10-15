#include <iostream>
#include <cmath>

int main() {
    long double a, b, c;
    int N;
    std::cin >> a >> b >> c >> N;
    switch(N)
    {
        case 2:
            std::cout << b * c - a * a;
            break;
        case 3:
            std::cout << a - b * c;
            break;
        case 7:
            std::cout << powl(a, 7) + c;
            break;
        case 56:
            std::cout << b * c;
            break;
        default:
            std::cout << pow(a + b, 3);
            break;
    }
    return 0;
}
