#include <iostream>
#include "include/inputChecker.h"

bool signOfDivision(long long k, long long a) {
    if (k < 0) k = ~k + 1;
    long long c = (a + 1) >> 1;
    while(k > a) // -- O(log n) --
        k = (k >> 1) + (k & 1 ? c : 0);
    return (k == a);
}

int main() {
    long long k = inputLLCompare(LLONG_MIN, LLONG_MAX, "Введите число, для проверки делимости на 7, 79 и 107: "); // -- O(n) --
    std::cout << "Divides by 7 - " << (signOfDivision(k, 7) /* -- O(log n) -- */ ? "true" : "false") << '\n';
    std::cout << "Divides by 79 - " << (signOfDivision(k, 79) /* -- O(log n) -- */ ? "true" : "false") << '\n';
    std::cout << "Divides by 107 - " << (signOfDivision(k, 107) /* -- O(log n) -- */ ? "true" : "false") << '\n';
    return 0;
}
