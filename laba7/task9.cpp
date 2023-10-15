#include <iostream>
#include "include/inputChecker.h"

void build(int *&b) {
    int rules[5] = {30, 16, 8, 4, 2}, ptr = 1;
    for (int i = 0; i < 32; i++) {
        int c = 1, count = 0;
        for (int j = 0; j < 5; j++) {
            count += bool(i & c);
            c <<= 1;
        }
        for (int j = 0; j < rules[count]; j++) {
            b[ptr++] = i;
        }
    }
}

int main() {
    int *b = new int[241], c, podozr = 0, a[5] = {1, 2, 3, 4, 5};
    build(b);

    int k = (int)inputLLCompare(1, 240, "Введите номер отравленной бочки: "); // -- O(n) --

    std::cout << "---Прошло 24 часа--- \n Умерли: \n";
    c = 1;
    for (int i = 0; i < 5; i++) {
        if (bool(b[k] & c)) {
            std::cout << "Раб номер " << a[i] << '\n';
            a[i] = 0;
            podozr |= c;
        }
        c <<= 1;
    }

    for (int i = 0; i < 5; i++) {
        if (a[i]) {
            int j = i;
            while (a[j] == 0 && j < 4) {
                j++;
            }
            std::swap(a[i], a[j]);
        }
    }

    int first = 0;
    std::cout << "Под подозрением бочки под номерами: \n";
    for (int i = 1; i < 241; i++) {
        if (b[i] == podozr) {
            std::cout << i << " ";
            if (!first)
                first = i;
        }
    }

    std::cout << "\n\n---Прошло 48 часов--- \n Умерли: \n";

    c = 1;
    podozr = 0;
    for (int i = 0; i < 5; i++) {
        if (bool((k - first) & c)) {
            std::cout << "Раб номер " << i + 1 << '\n';
            podozr |= c;
        }
        c <<= 1;
    }

    std::cout << "\nФу, бочка номер " << podozr + first << ". Я бы на твоем месте испарился.";


    return 0;
}
