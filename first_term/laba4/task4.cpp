#include <iostream>

using namespace std;

#define INF 2e9

int main() {
    int k, g, ans = 0;
    int a[1001][1001],
    key[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    std::cin >> k >> g;

    for (int i = 0; i < k + 2; i++) {
        for (int j = 0; j < g + 2; j++) {
            if (i < k + 1 && i > 0 && j < g + 1 && j > 0)
                std::cin >> a[i][j];
            else
                a[i][j] = INF;
        }
    }
    for (int i = 1; i < k + 1; i++) {
        for (int j = 1; j < g + 1; j++) {
            int mn = a[i][j];
            bool isStrong = true;
            for (int k = 0; k < 8; k++) {
                if (a[i + key[k][0]][j + key[k][1]] <= mn) isStrong = false;
            }
            if (isStrong)
                ans++;
        }
    }
    std::cout << ans;
    return 0;
}