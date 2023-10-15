#include <iostream>

int main() {
    long long n, sum;
    std::cin >> n;
    sum = ((2 + n - (n % 2)) * ((n - (n % 2) - 2)/2 + 1))/2;
    std::cout << sum;
    return 0;
}
