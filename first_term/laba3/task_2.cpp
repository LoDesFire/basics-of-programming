#include <iostream>
#include <cmath>

int main() {
    long double d = 0, e = 1e-3, nld, dn;
    int n = 1;
    do{
        nld = n;
        dn = powl(1.0/2.0, nld) + powl(1.0/3.0, nld);
        d += dn;
        n++;
    }while (dn >= e);
    std::cout << d;
    return 0;
}
