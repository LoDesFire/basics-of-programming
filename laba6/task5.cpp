#include <iostream>
#include <string>

long long binpow(long long n, long long pow, long long m)
{
    long long res = 1;
    while (pow) {
        if (pow & 1) {
            res = (res * n) % m;
            pow--;
        }
        else {
            pow >>= 1;
            n = (n * n) % m;
        }
    }
    return res % m;
}

int main ()
{
    int t;
    std::cin >> t;
    while (t > 0) {
        long long L, m, freeSym, ans = 0;
        std::string s1, s2;
        std::cin >> L >> m >> s1 >> s2;
        freeSym = L - (long long)s1.length() - (long long)s2.length();
        if (freeSym >= 0) {
            ans = binpow(26, freeSym, m);
            if (s1 != s2) ans = (ans * 2) % m;
        }
        else {
            std::string s1_part, s2_part;

            if ((long long)s1.length() + freeSym >= 0 && (long long)s2.length() + freeSym >= 0) {
                s1_part = s1.substr(s1.length() + freeSym);
                s2_part = s2.substr(s2.length() + freeSym);
                if (s2.substr(0, -freeSym) == s1_part)
                    ans = 1;
                if (s1.substr(0, -freeSym) == s2_part )
                    ans = 1;
            }
        }

        std::cout << ans % m << "\n";
        t--;
    }
    return 0;
}