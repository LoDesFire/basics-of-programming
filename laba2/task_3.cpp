#include <iostream>

int main() {
    long long x, y;
    long double a, b, c, k;
    std::cin >> x >> y >> a >> b >> c >> k;
    if (x > y) y = 0;
    else
        if (x == y) {
            x = 0;
            y = 0;
        }
        else x = 0;

    if (a >= b) {
        if (a >= c) {
            a -= k;
        }
        else c -= k;
    }
    else {
        if (b >= c) {
            b -= k;
        }
        else c -= k;
    }
    std::cout << x << " " << y << '\n';
    std::cout << a << " " << b << " " << c;
    return 0;
}