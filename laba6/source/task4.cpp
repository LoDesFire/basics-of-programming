#include <iostream>
#include <string>

char hTL(char c) {
    return (c < 'Z' + 1 && c > 'A' - 1 ? (char)(c + 32) : c);
}

void makeTask4(std::string &s) {
    char prev = '\0';
    for (int i = 0; i < s.length(); i++) {
        bool isBig = false;
        char c = s[i];
        std::string res;
        if (c < 'Z' + 1 && c > 'A' - 1) {
            isBig = true;
            c += 32;
        }

        switch (c) {
            case 'c':
                    if (hTL(s[i + 1]) == 'i' || hTL(s[i + 1]) == 'e' || hTL(s[i + 1]) == 'y') {
                        res = (isBig ? 'S' : 's');
                    } else {
                        res =  (isBig ? 'K' : 'k');
                    }
                break;
            case 'q':
                    if (hTL(s[i+1]) == 'u') {
                        res = (isBig ? "Kv" : "kv");
                        ++i;
                    }
                    else {
                        res = (isBig ? 'K' : 'k');
                    }
                break;
            case 'x':
                    res = (isBig ? "Ks" : "ks");
                break;
            case 'w':
                    res = (isBig ? 'V' : 'v');
                break;
            case 'p':
                    if (hTL(s[i+1]) == 'h') {
                        res = (isBig ? 'F' : 'f');
                        ++i;
                    }
                    else {
                        res =  (isBig ? 'P' : 'p');
                    }
                break;
            case 'y':
                    if (s[i + 1] != '\0' && hTL(s[i + 1]) == 'o' && hTL(s[i + 2]) == 'u') {
                        i += 2;
                        res =  (isBig ? 'U' : 'u');
                    }
                    else {
                        res =  (isBig ? 'Y' : 'y');
                    }
                break;
            case 'o':
                if (hTL(s[i + 1]) == 'o') {
                    ++i;
                    res =  (isBig ? 'U' : 'u');
                }
                else {
                    res =  (isBig ? 'O' : 'o');
                }
                break;
            case 'e':
                    if (hTL(s[i + 1]) == 'e') {
                        ++i;
                        res =  (isBig ? 'I' : 'i');
                    }
                    else {
                        res =  (isBig ? 'E' : 'e');
                    }
                break;
            case 't':
                if (hTL(s[i+1]) == 'h') {
                    res =  (isBig ? "Z" : "z");
                    ++i;
                }
                else {
                    res = (isBig ? "T" : "t");
                }
                break;
            default:
                res = (isBig ? (char)(c - 32) : c);
                break;
        }
        if (prev != hTL(res[0])) {
            std::cout << res;
        }
        else {
            res.erase(0, 1);
            std::cout << res;
        }
        if (!res.empty()) {
            c = hTL(res[res.length() - 1]);
            if (c != 'a' && c != 'o' && c != 'i' && c != 'e' && c != 'u' && c != 'y' && c > 'a' - 1 && c < 'z' + 1)
                prev = c;
            else
                prev = '\0';
        }
    }
    std::cout << '\n';
}