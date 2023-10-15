#include <cstdio>
#include <string>

int pa(int *&a, int low, int high, int *&b) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] >= pivot) {
            i++;
            std::swap(a[j], a[i]);
            std::swap(b[j], b[i]);
        }
    }
    std::swap(a[high], a[++i]);
    std::swap(b[high], b[i]);
    return i;
}

void sort(int *&a, int low, int high, int *&b) {
    if (low < high) {
        int pivot = pa(a, low, high, b);
        sort(a, low, pivot - 1, b);
        sort(a, pivot + 1, high, b);
    }
}

void makeTask2(int *a, int *ct) {
    char c;
    do {
        c = getchar();
        a[c]++;
    } while (c != '~');
    c = getchar();

    sort(a, 0, 512, ct);
    int i = 0;
    while (a[i] != 0) {
        if (ct[i] != ' ' && ct[i] != '~' && ct[i] != '\n') {
            printf("%c: %d\n", char(ct[i]), a[i]);
        }
        i++;
    }
}