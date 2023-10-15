#include <iostream>
#include <cmath>

long double mini(long double a, long double b)
{
    return (a < b ? a : b);
}

long double dist(long double x1, long double y1, long double x2, long double y2)
{
    return sqrtl(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    long double k, x, y, mn = -1;
    std::cout.precision(22);
    std::cin >> k >> x >> y;
    if (k < 0.0) {
        x = -x;
        y = -y;
        k = -k;
    }
    if (x < k && x > 0 || y < k && y > 0) {
        if (x < k && x > 0) {
            mn = mini(fabsl(k - y), fabsl(y));
        }
        if (y < k && y > 0) {
            mn = mn == -1 ? mini(fabsl(x), fabsl(k - x)) : mini(mini(fabsl(x), fabsl(k - x)), mn);
        }
    }
    else {
        mn = mini(dist(0, 0, x, y), dist(0, k, x, y));
        mn = mini(mini(dist(k, k, x, y), dist(k, 0, x, y)), mn);
    }
    std::cout << mn;
    return 0;
}