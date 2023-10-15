#include <iostream>
#include <cmath>

int main() {
    long double x, h = M_PI/40.0;
    for (int i = 0; i <= 20; i++) {
        x = (long double)i * h;
        std::cout << sin(x) - cos(x) << "\n";
    }
    return 0;
}
