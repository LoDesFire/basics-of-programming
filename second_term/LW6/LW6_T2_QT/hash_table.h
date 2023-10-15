//
// Created by Даниил Шумский on 8.05.23.
//

#ifndef LW6_T2_HASH_TABLE_H
#define LW6_T2_HASH_TABLE_H

#include <QDebug>

class HashTable {
    int size;
    int *table;
    bool *isUsed;

public:
    explicit HashTable(int Size);
    [[nodiscard]] int hash(int key) const;
    void insertValue(int, int i = 0);
    bool findValue(int, int i = 0);
    void print();
    int operator[](int index);
};

#endif //LW6_T2_HASH_TABLE_H
