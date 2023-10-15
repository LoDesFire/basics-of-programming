#include <iostream>

int main() {
    long long n, sum = 0;
    std::cin >> n;
    for (int i = 2; i <= n; i += 2)
        sum += i;
    std::cout << sum;
    return 0;
}
