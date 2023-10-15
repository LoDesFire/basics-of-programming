#include <iostream>
#include "MyHashTable.h"

int main() {
    MyHashTable hs(1000);
    for (int i = 0; i < 100; i++)
        hs.insertValue(arc4random() % 2000);
    hs.print();

    hs.eraseEven();
    hs.print();
    return 0;
}
