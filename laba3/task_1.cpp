#include <iostream>

int main() {
    long double N, ild;
    int i = 1;
    while (i < 31) {
        ild = i;
        N += (i % 2 ? ild * ild * (1 - ild) * (1 - ild) : ild * ild *  (1.0/2.0 - ild * ild) * (1.0/2.0 - ild * ild));
        i++;
    }
    std::cout << N;
    return 0;
}
