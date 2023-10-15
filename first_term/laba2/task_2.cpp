#include <iostream>

int main() {
    long double x, y, z;
    bool flag = true;
    std::cin >> x >> y >> z;
    if (x + y <= z || x + z <= y || z + y <= x) flag = false;
    std::cout << (flag ? "YES" : "NO");
    return 0;
}
