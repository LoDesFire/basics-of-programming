#include <iostream>
#include <cmath>

int main() {
    long long d, n;
    std::cin >> d;
    n = ceil(sqrt(d));
    if (d - (n * (n - 1) + 1) < 0) {
        std::cout << n + (d - (n * (n - 1) + 2)) << " " << n - 1;
    }
    else {
        std::cout << n - 1 << " " << n - (d - (n * (n - 1)));
    }
    return 0;
}