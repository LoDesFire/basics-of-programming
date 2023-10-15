#include <iostream>
#include <string>
#include <algorithm>

bool func(std::string &s2, std::string &s1, unsigned long long b, unsigned long long ns2) {
    while (ns2 < s2.length()) {

        if (b > 0 && s2[ns2] == s1[b - 1] && b < s1.length() - 1 && s2[ns2] == s1[b + 1]) {
            return bool(func(s2, s1, b - 1, ns2 + 1) + func(s2, s1, b + 1, ns2 + 1));
        }

        //std::cout << ns2 << " " << s2 << " b: " << b << '\n';

        if (b > 0 && s2[ns2] == s1[b - 1])
            b -= 1;
        else
            return false;

        ns2++;
    }
    return true;
}


int main ()
{
    int n;
    std::cin >> n;
    while (n) {
        std::string s1, s2, su;
        int ns2 = 0;
        std::cin >> s1 >> s2;
        if (s2.length() > 2) {
            ns2 = 2;
            int i = 2;
            while (s2[i - 2] != s2[i] && i < s2.length()) {
                ns2++;
                i++;
            }
            su = s2.substr(0, ns2);
        }
        else
            su = s2;

        bool ans = false;
        unsigned long long pos = 0, srch = s1.find(su, pos);

        while (srch != std::string::npos && pos < s1.length() && !ans) {
            if (func(s2, s1, srch + su.length() -1, su.length())) ans = true;

            pos = srch + su.length();
            if (pos < s1.length())
                srch = s1.find(su, pos);

        }

        std::reverse(su.begin(), su.end());
        pos = 0;
        srch = s1.find(su, pos);
        while (srch != std::string::npos && pos < s1.length() && !ans) {
            if (func(s2, s1, srch, su.length())) ans = true;

            pos = srch + su.length();
            if (pos >= 0)
                srch = s1.find(su, pos);

        }
        if (ans) std::cout << "YES\n";
        else std::cout << "NO\n";

        n--;
    }
    return 0;
}