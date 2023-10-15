#include <iostream>

int main() {
    long long n = 0, k = 0, a[513]{}, res = 1;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.length(); i++)
        res = (res * ++n) / ++a[s[i]];
    std::cout << res;
    return 0;
}