#include <iostream>
#include <cmath>

int main() {
    int n, a[100]{}, b = 99;
    bool isZero;
    std::cin >> n;
    while (n) { // -- O(log n) --
        a[b--] = n % 3;
        n /= 3;
    }

    n = 1;
    while (n) { // -- O(n^2) --
        isZero = true;
        for (int i = b; i < 100; i++) { // -- O(n) --
            if (a[i]) isZero = false;
            if (!a[i] && !isZero) {
                a[i] = 3;
                a[i - 1] -= 1;
                if (!a[i - 1]) n++;
            }
        }
        n--;
    }

    isZero = true;
    for (int i = b; i < 100; i++) { // -- O(n) --
        if (a[i]) isZero = false;
        if (!isZero) std::cout << a[i];
    }
    return 0;
}
