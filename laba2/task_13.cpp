#include <iostream>
int main() {
    setlocale(LC_ALL, "Russian");
    long long k;
    std::cin >> k;
    if (k < 0) {
        k = -k;
        std::cout << "Мы нашли " << -k << " ";
    }
    else std::cout << "Мы нашли " << k << " ";
    k %= 100;
    if (k >= 11 && k <= 14) std::cout << "грибов в лесу";
    else {
        k %= 10;
        switch (k)
        {
            case 1:
                std::cout << "гриб в лесу";
                break;
            case 2:
            case 3:
            case 4:
                std::cout << "гриба в лесу";
                break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 0:
                std::cout << "грибов в лесу";
                break;
        }
    }
    return 0;
}