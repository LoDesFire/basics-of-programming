#include <iostream>
#include <string>

int main ()
{
    std::string s;
    std::cin >> s;
    bool isEq = true, isPal = true;
    for(int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length() - 1 - i]) isPal = false;
        if (i > 1 && s[i - 1] != s[i]) isEq = false;
    }

    if (isEq) {
        std::cout << -1;
    }
    else {
        if (isPal) std::cout << s.length() - 1;
        else std::cout << s.length();
    }

    return 0;
}