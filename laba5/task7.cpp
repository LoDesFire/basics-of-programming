#include <iostream>

int main() {
    long long k, n, t_cin, l = 1;
    std::cin >> k >> n >> t_cin;
    while (n != 0 || k != 0 || t_cin != 0) {
        int t = 1;
        long long res = 1;
        for (int i = 0; i < t_cin; i++) {
            t *= 10;
        }
        k %= t;
        while (n) {
            if (n & 1) {
                res = (res * k) % t;
                n--;
            }
            else {
                k = (k * k) % t;
                n /= 2;
            }
        }
        std::cout << "\nCase #" << l << ": " << res;
        l++;
        std::cin >> k >> n >> t_cin;
    }
    return 0;
}