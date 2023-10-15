#include <iostream>

long double powl(long double n, long long i)
{
    long double res = 1;
    for (; i > 0; i--)
        res *= n;
    return res;
}

long double floorl(long double n)
{
    return (long double)((long long)n);
}

int main() {
    long double a0, an, d, N;
    long long n;
    std::cout << "Enter the FIRST element of sequence: ";
    std::cin >> a0;
    std::cout << "Enter the LAST element of sequence: ";
    std::cin >> an;
    std::cout << "Enter difference of sequence: ";
    std::cin >> d;
    N = ((an - a0 + d)/d);
    if (N - floorl(N) > 1e-3 || N <= 0.0 || d == 0) {
        std::cout << "ERROR";
        return 0;
    }
    n = (long long)N;
    std::cout << a0 * (powl(-2, n) - 1.0) / (-3) + d * (2.0/9.0 * (3.0 * powl(-2.0, n-1) * ((long double)n-1) + powl(-2.0, n-1) - 1));
    return 0;
}
