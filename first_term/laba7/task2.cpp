#include <iostream>
#include "include/inputChecker.h"

int *binToLL(long long x, int *res) {
    std::string s;
    bool isNegative = false;
    if (x < 0) {
        isNegative = true;
    }
    while (x) { // -- O(log n) --
        s += char('0' + (isNegative ? -(x % 2) : (x % 2)));
        x /= 2;
    }
    while (s.length() != 64) s += '0'; // -- O(log n) --

    std::reverse(s.begin(), s.end());

    for (int i = 0; i < 64; i++) {
        res[i] = int(isNegative == !(s[i] - '0'));
    }
    if (isNegative) res[63] += 1;
    return res;
}

int main() {
    long long x = inputLLCompare(LLONG_MIN + 1, LLONG_MAX, "Введите первое целое число в пределах ±2^63 ∓ 1: "), // -- O(n) --
    y = inputLLCompare(LLONG_MIN + 1, LLONG_MAX, "Введите второе целое число в пределах ±2^63 ∓ 1: "); // -- O(n) --
    int *s1 = new int[64], *s2 = new int[64];
    binToLL(x, s1); // -- O(log n) --
    binToLL(y, s2); // -- O(log n) --

    for (int i = 63; i >= 0; i--) {
        s1[i] += s2[i];
        if (i) s1[i - 1] += s1[i] / 2;
        s1[i] %= 2;
    }

    for (int i = 0; i < 64; i++) {
        std::cout << s1[i];
        if (!((i + 1) & 3)) std::cout << ' ';
    }
    std::cout << '\n';
    bool isNegative = false;
    if (s1[0] == 1) {
        isNegative = true;
        for (int i = 0; i < 64; i++) {
            s1[i] = !s1[i];
        }
        s1[63] += 1;
        for (int i = 63; i >= 0; i--) {
            if (i) s1[i - 1] += s1[i] / 2;
            s1[i] %= 2;
        }
    }
    long long ans = 0, pow = 1;
    for (int i = 63; i >= 0; i--) {
        if (s1[i]) ans += pow;
        pow <<= 1;
    }
    std::cout << (isNegative ? -ans : ans);
    return 0;
}
