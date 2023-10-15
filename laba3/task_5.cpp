//12 variant
#include <iostream>
#include <cmath>

long long fact(long long n)
{
    if (!n) return 1;
    return fact(n - 1) * n;
}

int main() {
    int i, n;
    std::cout << "Enter a precision(1 - 10): ";
    std::cin >> i;
    std::cout << "Enter the number of iterations: ";
    std::cin >> n;
    for (; n > 0; n--) {
        long double Y = 0, x;
        std::cout << "Enter argument: ";
        std::cin >> x;
        for (int pr = i; pr > 0; pr--)
            Y += powl(-1.0, pr) * powl(2.0 * x, 2.0 * pr) / (long double)fact(2 * pr);
        std::cout << "Y(x) = " << Y << "; S(x) = " << 2.0 * (powl(cos(x), 2) - 1) << '\n';
    }
    return 0;
}
