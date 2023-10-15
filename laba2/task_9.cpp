#include <iostream>
#include <cmath>

int main() {
    long double z, x, y, a, b, e = powl(2, 1.0/logl(2)), f;
    int n;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "z: ";
    std::cin >> z;
    if (z > 0)
        x = 1.0 / (z * z + 2.0 * z);
    else
        x = 1 - z * z * z;
    std::cout << "Select function number (1, 2, 3): ";
    std::cin >> n;
    switch(n)
    {
        case 1:
            f = 2 * x;
            break;
        case 2:
            f = x * x * x;
            break;
        case 3:
            f = x / 3.0;
            break;
    }
    if (fabsl(x) > 0 && logl(fabsl(x)) + f != 0) {
        y = (2.5 * a * powl(e, -3 * x) - 4 * b * x * x) / (logl(fabsl(x)) + f);
    }
    else {
        std::cout << "ERROR";
        return 0;
    }
    std::cout << "z " << (z < 0 ? "< 0, " : ">= 0, ") << "f(x) = " << (n == 1 ? "2x" : (n == 2 ? "x^3" : "x/3")) << "\n";
    std::cout << y;
    return 0;
}
