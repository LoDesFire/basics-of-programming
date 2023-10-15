#include <iostream>
#include <string>
#include "include/inputChecker.h"

int main() {
    int base = (int)inputLLCompare(2, 36, "Введите основание системы счисления (от 2 до 36): ") /* -- O(n) -- */, length;
    bool isNeg1 = false, isNeg2 = false;
    std::string s1, s2, baseS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::cout << "Введите 1-e число\n";
    bool inpCheck = false;
    while (!inpCheck) { // -- O(1/0) --
        inpCheck = true;
        std::getline(std::cin, s1);
        for (int i = 0; i < s1.length(); i++) { // -- O(n) --
            if (s1[i] > 'a' - 1 && s1[i] < 'z' + 1) s1[i] -= 32;
            if (base < 11 && (s1[i] > base + '0' - 1 || s1[i] < '0'))
                inpCheck = false;
            if (base > 10 && (s1[i] > base + '0' - 1 && s1[i] < 'A' || s1[i] < '0' || s1[i] > base - 11 + 'A')){
                inpCheck = false;
            }
            if (i == 0 && (s1[i] == '-' || s1[i] == '+')) {
                if (s1[i] == '-') {
                    isNeg1 = true;
                }
                s1.erase(0, 1);
                inpCheck = true;
            }

        }
        if (!inpCheck)
            std::cout << "---НЕВЕРНЫЙ ВВОД---\nВведите число по основанию " << base << " ещё раз.\n";
    }
    length = (int)s1.length();

    std::string c;
    std::cout << "Введите знак выражения.\n";
    do {
        std::getline(std::cin, c);
        if (c != "-" && c != "+")
            std::cout << "---НЕВЕРНЫЙ ВВОД---\nВведите знак выражения ещё раз.\n";
    } while (c != "-" && c != "+"); // -- O(1/0) --


    std::cout << "Введите 2-e число\n";
    inpCheck = false;
    while (!inpCheck) { // -- O(1/0) --
        inpCheck = true;
        std::getline(std::cin, s2);
        for (int i = 0; i < s2.length(); i++) { // -- O(n) --
            if (s2[i] > 'a' - 1 && s2[i] < 'z' + 1) s2[i] -= 32;
            if (base < 11 && (s2[i] > base + '0' - 1 || s2[i] < '0'))
                inpCheck = false;
            if (base > 10 && (s2[i] > base + '0' - 1 && s2[i] < 'A' || s2[i] < '0' || s2[i] > base - 11 + 'A')){
                inpCheck = false;
            }
            if (i == 0 && (s2[i] == '-' || s2[i] == '+')) {
                if (s2[i] == '-') {
                    isNeg2 = true;
                }
                s2.erase(0, 1);
                inpCheck = true;
            }
        }
        if (!inpCheck)
            std::cout << "---НЕВЕРНЫЙ ВВОД---\nВведите число по основанию " << base << " ещё раз.\n";
    }
    if (length < s2.length())
        length = (int)s2.length();
    length++;

    while (s1.length() != length) // -- O(n) --
        s1.insert(0, "0");
    while (s2.length() != length) // -- O(n) --
        s2.insert(0, "0");

    int *a = new int[length], *b = new int[length];

    for (int i = length - 1; i >= 0; i--) { // -- O(n) --
        a[i] = (int)baseS.find(s1[i]);
        b[i] = (int)baseS.find(s2[i]);
    }

    if (isNeg1) {
        for (int i = 0; i < length; i++) // -- O(n) --
            a[i] = base - a[i] - 1;
        a[length - 1] += 1;
        for (int i = length - 1; i >= 0; i--) { // -- O(n) --
            if (a[i] > base - 1)
                if (i) a[i-1] += a[i] / base;
            a[i] %= base;
        }
    }

    if (isNeg2) {
        for (int i = 0; i < length; i++) // -- O(n) --
            b[i] = base - b[i] - 1;
        b[length - 1] += 1;
        for (int i = length - 1; i >= 0; i--) { // -- O(n) --
            if (b[i] > base - 1)
                if (i) b[i-1] += b[i] / base;
            b[i] %= base;
        }
    }

    if (c == "-") {
        for (int i = 0; i < length; i++) // -- O(n) --
            b[i] = base - b[i] - 1;
        b[length - 1] += 1;
        for (int i = length - 1; i >= 0; i--) { // -- O(n) --
            if (b[i] > base - 1)
                if (i) b[i-1] += b[i] / base;
            b[i] %= base;
        }
    }

    for (int i = length - 1; i >= 0; i--) { // -- O(n) --
        a[i] += b[i];
        if (a[i] > base - 1)
            if (i) b[i - 1] += a[i] / base;
        a[i] %= base;
    }

    bool res = false;
    if (!(base & 1)) {
        if (a[0] > base / 2 - 1) {
            for (int i = 0; i < length; i++) // -- O(n) --
                a[i] = base - a[i] - 1;
            a[length - 1] += 1;
            for (int i = length - 1; i >= 0; i--) { // -- O(n) --
                if (a[i] > base - 1)
                    if (i) a[i-1] += a[i] / base;
                a[i] %= base;
            }
            res = true;
        }
    }
    else {
        bool isNeeded = true;
        for (int i = 0; i < length; i++) {
            if ((a[i] < (base - 1) / 2 && i != length - 1 ) || (i == length - 1 && a[i] <= (base - 1) / 2))
                isNeeded = false;
        }
        if (isNeeded) {
            for (int i = 0; i < length; i++) // -- O(n) --
                a[i] = base - a[i] - 1;
            a[length - 1] += 1;
            for (int i = length - 1; i >= 0; i--) { // -- O(n) --
                if (a[i] > base - 1)
                    if (i) a[i-1] += a[i] / base;
                a[i] %= base;
            }
            res = true;
        }
    }

    std::cout << "Результат: " << (res ? "-" : "");
    bool isZero = true;
    for (int i = 0; i < length; i++) { // -- O(n) --
        if (baseS[a[i]] != '0') isZero = false;
        if (!isZero || (baseS[a[i]] == '0' && i == length - 1)) std::cout << baseS[a[i]];
    }
    std::cout << '\n';

    return 0;
}
