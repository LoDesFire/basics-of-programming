#include <iostream>
#include <cmath>

int main() {
    long double R, P, Q;
    std::cout << "Sphere radius: ";
    std::cin >> R;
    std::cout << "Edge: ";
    std::cin >> P;
    std::cout << "Angle(radian): ";
    std::cin >> Q;
    if (P * sinl(Q) / 2.0 >= R)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
