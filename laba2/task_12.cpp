#include <iostream>
int main() {
    long double a, b, c, x, y;
    bool flag = false;
    std::cin >> a >> b >> c >> x >> y;
    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) {
        std::cout << "Incorrect input";
        return 0;
    }
    if (a > b) {
        if (x - a >= 0 && y - b >= 0) flag = true;
    }
    else
        if (x - b >= 0 && y - a >= 0) flag = true;

    if (a > c) {
        if (x - a >= 0 && y - c >= 0) flag = true;
    }
    else
        if (x - c >= 0 && y - a >= 0) flag = true;

    if (b > c) {
        if (x - b >= 0 && y - c >= 0) flag = true;
    }
    else
        if (x - c >= 0 && y - b >= 0) flag = true;
    std::cout << (flag ? "YES" : "NO");
    return 0;
}