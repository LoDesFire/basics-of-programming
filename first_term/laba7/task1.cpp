#include <iostream>
#include "include/inputChecker.h"

int main() {
    std::string s;
    long long x = inputLLCompare(LLONG_MIN + 1, LLONG_MAX, "Введите целое число в пределах ±2^63 ∓ 1: "); // -- O(n) --
    bool isNegative = false;
    if (x < 0) {
        isNegative = true;
    }

    while (x) { // -- O(log n) --
        s += char('0' + (isNegative ? -(x % 2) : (x % 2)));
        x /= 2;
    }
    while (s.length() != 64) { // -- O(log n) --
        s += '0';
    }
    std::reverse(s.begin(), s.end());

    for (int i = 0; i < 64; i++) {
        std::cout << (isNegative != s[i] - '0');
        if (!((i + 1) & 3)) std::cout << ' ';
    }
    return 0;
}
