#include <iostream>
#include <string>

int main()
{
    std::string s;
    int a[10]{}, ans1 = 0, ind;
    std::cin >> s >> ind;
    char c = s[ind - 1];
    for (int i = 0; i < s.length(); i++) {
        a[s[i] - '0']++;
        if (a[s[i] - '0'] == 1) ans1++;
    }
    std::cout << ans1 << '\n';
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == c) std::cout << s.length() - 1 - i << " ";
    }
    return 0;

}