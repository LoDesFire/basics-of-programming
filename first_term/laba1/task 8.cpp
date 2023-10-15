#include <iostream>

int main()
{
    int h1, m1, h2, m2, h3, m3;
    std::cin >> h1 >> m1 >> h2 >> m2;
    m1 += h1 * 60;
    m2 += h2 * 60;
    if (m2 - m1 < 0) {
        m3 = (60 * 24 - m1) + m2;
        h3 = m3 / 60;
        m3 = m3 % 60;
    }
    else {
        h3 = (m2 - m1) / 60;
        m3 = (m2 - m1) % 60;
    }
    if (h3 <= 9) {
        std::cout << 0;
    }
    std::cout << h3 << ":";
    if (m3 <= 9) {
        std::cout << 0;
    }
    std::cout << m3 << "\n";
    return 0;
}