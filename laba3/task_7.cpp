#include <iostream>

#define M_E         2.71828182845904523536028747135266250
#define M_PI        3.14159265358979323846264338327950288
#define M_LN01      -2.3025850929940456840179914546843642

long long fact(long long n)
{
    if (!n) return 1;
    return fact(n - 1) * n;
}

long double fabsl(long double n)
{
    return (n < 0 ? -n : n);
}

long double floor(long double n)
{
    return (long double)((unsigned long long) n);
}

long double powl(long double n, int i) {
    long double res = 1;
    for (; i > 0; i--)
        res *= n;
    return res;
}

int main() {
    long double x;
    std::cout.precision(5);
    while (std::cin >> x) {
        long double sn = 0, cs = 0, ln = 0, ans = 404;

        if (x == 0.0) {
            std::cout << "ERROR";
            return 0;
        }

        long double g = x, xc = x;

        if (x > 0) {
            xc = floor(xc / (2.0L * M_PI) + 0.5);
            g -= xc * 2.0L * M_PI;
        }
        else {
            xc = floor(-xc / (2.0L * M_PI) + 0.5);
            g += xc * 2.0L * M_PI;
        }

        for (int i = 11; i >= 0; i--) {
            sn += powl(-1, i) * powl(g, 2 * i + 1) / (long double) fact(2 * i + 1);
            cs += powl(-1, i) * powl(g, 2 * i) / (long double) fact(2 * i);
        }

        int t = 0;
        long double l = fabsl(x);
        while (l < 1) {
            l *= 10.0;
            t++;
        }
        while (l > 10) {
            l /= 10.0;
            t--;
        }
        l = (l - 1) / (l + 1);
        for (int i = 40; i >= 0; i--)
            ln += 2.0 * powl(l, 2 * i + 1) / (long double) (2 * i + 1);
        ln += M_LN01 * (long double)t;


        if (sn < ans) ans = sn;
        if (cs < ans) ans = cs;
        if (ln < ans) ans = ln;

        std::cout << "Answer: " << ans << '\n';
        std::cout << "SIN: " << sn << "\n";
        std::cout << "COS: " <<cs << "\n";
        std::cout << "LN: " << ln << '\n';
    }
    return 0;
}