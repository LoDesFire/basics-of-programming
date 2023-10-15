#include <iostream>
#include <string>

int main()
{
    int n, m, a[500][500], b[500][500], c1[500][500]{};
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> b[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {

            for (int v = 0; v < m; v++) {
                c1[i][j] += a[i][v] * b[v][j];
            }

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << c1[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << (i == n - 1 ? "" : "\n");
    }
    return 0;
}