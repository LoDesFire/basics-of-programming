#include <iostream>
#include <cmath>

int main() {
    long double s, ans = 1;
    int n;
    std::cin >> n;
    s = 1.0 / (long double) n;
    for (int i = 0; i <= n; i++) {
        long double x = s * (long double) i;
        if (fabsl(sinhl(x) + acosl(x) - 1.5) < fabsl(sinhl(ans) + acosl(ans) - 1.5)) ans = x;
    }
    std::cout << ans;
    return 0;
}
