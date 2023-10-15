#include <iostream>
#include <cmath>

long long g(long long n)
{
  long long k = (n + 1) / 2;
  if (n == 0) return 0;
  return k * k + g(n / 2);
}

int main() {
    int k;
    std::cin >> k;
    while (k) {
        long long n, sum = 0;
        std::cin >> n;
        std::cout << g(n) << "\n";
        k--;
    }
    return 0;
}