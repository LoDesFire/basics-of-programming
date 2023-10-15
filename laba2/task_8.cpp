#include <iostream>
#include <cmath>

int main() {
    long double a, b, c, p, q, D, t1, t2, D1, Q, alpha, beta, x1, x2;
    int N;
    bool f2 = false;
    std::cout << "Choose option: ";
    std::cin >> N;
    switch(N) {
        case 1: {
            std::cout << "ax^4 + bx^2 + c = 0\n";
            std::cin >> a >> b >> c;
            D = b * b - 4.0 * a * c;

            if (D > 0 && a != 0) {
                t1 = (-b + sqrtl(D)) / (2.0 * a);
                t2 = (-b - sqrtl(D)) / (2.0 * a);
                if (t1 >= 0 || t2 >= 0) f2 = true;
                if (t1 > 0) std::cout << sqrtl(t1) << " " << -sqrtl(t1) << " ";
                if (t2 > 0) std::cout << sqrtl(t2) << " " << -sqrtl(t2) << " ";
                if (t1 == 0 || t2 == 0) std::cout << 0 << " ";
            }
            if (D == 0 || (a == 0 && b != 0)) {
                t1 = (a == 0 && D > 0) ? -c / b : (-b) / (2.0 * a);
                if (t1 >= 0) f2 = true;
                if (t1 > 0) std::cout << sqrtl(t1) << " " << -sqrtl(t1);
                if (t1 == 0) std::cout << 0;
            }
            if (a == 0 && b == 0 && c == 0) {
                std::cout << "Infinity of roots";
                f2 = true;
            }
            if (!f2)
                    std::cout << "There are no roots.";
        }
            break;
        case 2: {
            std::cout << "ax^4 + bx^3 + cx^2 + bx + a = 0\n";
            std::cin >> a >> b >> c;
            f2 = false;
            D = b * b - 4.0 * a * (c - 2.0 * a);
            if (D > 0 && a != 0) {
                t1 = (-b + sqrtl(D)) / (2.0 * a);
                t2 = (-b - sqrtl(D)) / (2.0 * a);
                D1 = t1 * t1 - 4.0;
                if (D1 > 0)
                    std::cout << (t1 + sqrtl(D1)) / 2.0 << " " << (t1 - sqrtl(D1)) / 2.0 << " ";
                if (D == 0)
                    std::cout << t1 / 2.0 << " ";
                if (D1 >= 0) f2 = true;

                D1 = t2 * t2 - 4.0;
                if (D1 > 0)
                    std::cout << (t2 + sqrtl(D1)) / 2.0 << " " << (t2 - sqrtl(D1)) / 2.0 << " ";
                if (D1 == 0)
                    std::cout << t2 / 2.0 << " ";
                if (D1 >= 0) f2 = true;
            } else if (D == 0 || (a == 0 && b != 0)) {
                t1 = (a == 0) ? -c / b : (-b) / (2.0 * a);
                D1 = t1 * t1 - 4.0;
                if (D1 > 0)
                    std::cout << (t1 + sqrtl(D1)) / 2.0 << " " << (t1 - sqrtl(D1)) / 2.0 << " ";
                if (D1 == 0)
                    std::cout << t1 / 2.0 << " ";
                if (D1 >= 0) f2 = true;
            }
            if (a == 0 && b == 0 && c == 0) {
                std::cout << "Infinity of roots";
                f2 = true;
            }
            else
                if (a == 0) {
                    std::cout << 0;
                    f2 = true;
                }
            if (!f2)
                std::cout << "There are no roots.";
        }
            break;
        case 3: {
            std::cout << "x^3 + px + q = 0\n";
            std::cin >> p >> q;

                Q = powl(p / 3.0, 3.0) + powl(q / 2.0, 2.0);
                if (Q >= 0 && (p != 0 || q != 0)) {
                    alpha = std::cbrtl(-q / 2.0 + sqrtl(Q));
                    beta = std::cbrtl(-q / 2.0 - sqrtl(Q));
                    if (Q > 0) std::cout << alpha + beta;
                    if (Q == 0) std::cout << alpha + beta << " " << -alpha;
                }
                else {
                    if (p == 0 && q == 0) {
                        std::cout << 0;
                    }
                    else
                        if (p < 0 && q == 0) {
                            std::cout << 0 << " " << sqrtl(-p) << " " << -sqrtl(-p);
                        }
                        else {
                            x1 = acos(-(q / 2) * powl(3 / -p, 1.5));
                            x2 = acos(-1);
                            std::cout << 2 * sqrtl(-p / 3) * cos(x1 / 3) << " ";
                            std::cout << 2 * sqrtl(-p / 3) * cos(x1 / 3 + 2 * x2 / 3) << " ";
                            std::cout << 2 * sqrtl(-p / 3) * cos(x1 / 3 - 2 * x2 / 3) << " ";
                        }
                }
        }
            break;
    }
    return 0;
}
