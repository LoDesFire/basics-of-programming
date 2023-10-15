#include <iostream>
int main()
{
    int n, m, a[1400][1400];
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
            if (i != 0) {
                if (a[i - 1][j] > a[i][j]) a[i][j] = a[i - 1][j];
            }
            if (j != 0) {
                if (a[i][j - 1] > a[i][j]) a[i][j] = a[i][j - 1];
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << '\n';
    }
    return 0;

}