#include <iostream>
#include <iomanip>

int main()
{
    long long a, b;
    std::cin >> a >> b;
    if (a == 0 || b == 0) {
        if (a == 0 && b == 0) std::cout << "ERROR";
        else std::cout << "YES";
        return 0;
    }
    if (!(a % b)) {
        std::cout << "YES";
        return 0;
    }
    if (!(b % a)) {
        std::cout << "YES";
        return 0;
    }
    std::cout << "NO";
    return 0;
}