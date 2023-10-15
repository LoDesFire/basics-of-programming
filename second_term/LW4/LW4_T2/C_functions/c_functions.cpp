#include "c_functions.h"

String& Strcpy(String& s1, const String& s2) {
    s1.assign(s2.data());
    return s1;
}

String& Strncpy(String& s1, String& s2, size_t n) {
    s1.assign(s2.begin(), s2.begin() + n);
    return s1;
}

String& Strcat(String& s1, String& s2) {
    s1.append(s2);
    return s1;
}

String& Strncat(String& s1, String& s2, size_t n) {
    s1.append(s2.substr(0, n));
    return s1;
}

int Strcmp(String& s1, String& s2) {
    for (size_t i = 0; i == 0 || (s1[i - 1] != '\0' && s2[i - 1] != '\0');  i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}

int Strncmp(String& s1, String& s2, size_t n) {
    for (size_t i = 0; i < n && (i == 0 || (s1[i - 1] != '\0' && s2[i - 1] != '\0')); i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}

String&& Strtok(String& s1, String& s2) {
    static Iterator<char> begIt = nullptr, endIt = nullptr;

    auto *returnVal = new String;
    bool character[256]{};
    for (auto i : s2)
        character[i] = true;

    if (s1.data()) {
        begIt = s1.begin();
        endIt = s1.end();
    }

    auto it = begIt;
    while (it != endIt && character[*it])
        it++;

    if (it == endIt) {
        returnVal->assign(begIt, endIt);
        return std::move(*returnVal);
    }

    auto tokenBegin = it;

    while (it != endIt && !character[*it])
        it++;

    if (it != endIt)
        *it = '\0';

    returnVal->assign(tokenBegin, it);
    begIt = ++it;
    return std::move(*returnVal);
}

int Memcmp(const void *s1, const void *s2, size_t n) {
    auto *a = reinterpret_cast<const unsigned char *>(s1);
    auto *b = reinterpret_cast<const unsigned char *>(s2);
    for (size_t i = 0; i < n; i++) {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}

void *Memcpy(void *s1, const void *s2, size_t n) {
    auto *b = reinterpret_cast<const unsigned char *>(s2);
    auto *c = reinterpret_cast<unsigned char *>(s1);
    for (auto i = 0; i < n; i++)
        c[i] = b[i];
    return s1;
}

void *Memmove(void *s1, const void *s2, size_t n) {
    unsigned char arr[n];
    auto *b = reinterpret_cast<const unsigned char *>(s2);
    auto *c = reinterpret_cast<unsigned char *>(s1);
    for (auto i = 0; i < n; i++)
        arr[i] = b[i];
    for (auto i = 0; i < n; i++)
        c[i] = arr[i];
    return s1;
}

void *Memset(void *s, int c, size_t n) {
    auto *b = reinterpret_cast<unsigned char *>(s);
    for (auto i = 0; i < n; i++)
        b[i] = static_cast<unsigned char>(c);
    return s;
}


String&& Strerror(int errnum) {
    auto *tmp = new String(std::strerror(errnum));
    return std::move(*tmp);
}

size_t Strlen(String& s) {
    return s.size();
}