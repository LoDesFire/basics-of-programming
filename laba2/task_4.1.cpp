#include <iostream>

int main() {
    long double x, y;
    bool c;
    std::cin >> x >> y;
    c = x < y;
    std::cout << (c ? y : x);
    return 0;
}
