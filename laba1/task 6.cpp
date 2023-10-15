#include <iostream>
#include <cmath>

int main()
{
    int opt = 0;
    do {
        std::cout << "Choose option: ";
        std::cin >> opt;
        long double A, B, C, D, x, b, K, p, n, z, y, m, h, d, k;
        switch (opt) {
            case 1:
                std::cout << "D: ";
                std::cin >> D;
                std::cout << "x: ";
                std::cin >> x;
                if (D * D * D + (A + D - b) != 0 && x + D != 0) {
                    b = x + D;
                    A = D * x / b;
                    std::cout << "Option 1: " << (A * A + b * cos(x)) / (D * D * D + (A + D - b)) << '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
            case 2:
                std::cout << "D: ";
                std::cin >> D;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "p: ";
                std::cin >> p;
                std::cout << "K: ";
                std::cin >> K;
                std::cout << "C: ";
                std::cin >> C;

                if (2 * A * B != 0) {
                    A = x + sin(p);
                    B = exp(K);
                    std::cout << "Option 2: " << (1 + K * K / (2 * A * B) - B + D * C) << '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
            case 3:
                std::cout << "D: ";
                std::cin >> D;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "p: ";
                std::cin >> p;
                std::cout << "K: ";
                std::cin >> K;
                std::cout << "n: ";
                std::cin >> n;
                if (K * D != 0) {
                    B = cos(x);
                    C = p - n;
                    std::cout << "Option 3: " << (B * B / (K * D) + B * C * C * C) << '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
            case 4:
                std::cout << "D: ";
                std::cin >> D;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "z: ";
                std::cin >> z;
                std::cout << "K: ";
                std::cin >> K;
                std::cout << "y: ";
                std::cin >> y;
                std::cout << "C: ";
                std::cin >> C;
                if (K - C * D != 0 && z >= 0) {
                    A = x - y;
                    B = sqrt(z);
                    std::cout << "Option 4: " << cos(x) + A * A / (K - C * D) - B << '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
            case 5:
                std::cout << "n: ";
                std::cin >> n;
                std::cout << "m: ";
                std::cin >> m;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "K: ";
                std::cin >> K;
                if (A != 0 && cos(x) != .0) {
                    A = fabs(n + m);
                    D = tan(x);
                    std::cout << "Option 5: " << 1.29 + K/A + D * D<< '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
            case 6:
                std::cout << "C: ";
                std::cin >> C;
                std::cout << "y: ";
                std::cin >> y;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "K: ";
                std::cin >> K;
                if (C != 0 && K != 0){
                    A = x + y;
                    D = fabs(C - A);
                    std::cout << "Option 6: " << (10.1 + A / C + D / (K * K))<< '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
            case 7:
                std::cout << "p: ";
                std::cin >> p;
                std::cout << "h: ";
                std::cin >> h;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "K: ";
                std::cin >> K;
                std::cout << "C: ";
                std::cin >> C;
                std::cout << "D: ";
                std::cin >> D;
                if (K * C * D != 0 && h > 0) {
                    A = x - p;
                    B = log(h);
                    std::cout << "Option 7: " << 0.78 * B + A * A * A / (K * C * D) << '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
            case 8:
                std::cout << "d: ";
                std::cin >> d;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "K: ";
                std::cin >> K;
                std::cout << "C: ";
                std::cin >> C;
                if (x > 0 && K != 0) {
                    A = log10(x);
                    B = x + exp(d);
                    std::cout << "Option 8: " << (A + B) - C * C / K<< '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
            case 9:
                std::cout << "z: ";
                std::cin >> z;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "p: ";
                std::cin >> p;
                std::cout << "C: ";
                std::cin >> C;
                std::cout << "K: ";
                std::cin >> K;
                std::cout << "D: ";
                std::cin >> D;
                if (C * D != 0) {
                    A = sin(x) - z;
                    B = fabs(p - x);
                    std::cout << "Option 9: " << (A + B) * (A + B) - K /(C * D)<< '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
            case 10:
                std::cout << "k: ";
                std::cin >> k;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "z: ";
                std::cin >> z;
                std::cout << "C: ";
                std::cin >> C;
                std::cout << "D: ";
                std::cin >> D;
                if (x > 0 && z >= 0 && log(x) - k != 0) {
                    A = log(x) - k;
                    B = sqrt(z);
                    std::cout << "Option 10: " << D * D + C * C / (0.75 * A) + B << '\n';
                }
                else std::cout << "ERROR" << '\n';
                break;
        }
    } while (opt);
    return 0;
}