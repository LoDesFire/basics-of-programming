#include <iostream>

int main() {
    long double x, y;
    std::cin >> x >> y;
    std::cout << (x < y ? y : x);

    return 0;
}
