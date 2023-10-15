#include <iostream>
#include <cmath>

int main() {
    long long pw[11][10] = {0}, n;
    int rn;
    std::cin >> n;
    for (int i = 0; i <= 10; i++)
        for (int j = 1; j < 10; j++)
            pw[i][j] = pow(i, j);
    rn = 1;
    for (int i = 1; i < n; i++) {
        long long tmp1 = i, ans = 0;
        if (i >= pw[10][rn]) rn++;
        while (tmp1 != 0) {
            ans += pw[tmp1 % 10][rn];
            tmp1 /= 10;
        }
        if (ans == i) std::cout << ans << "\n";
    }
    return 0;
}