//
// Created by Даниил Шумский on 9.05.23.
//

#ifndef LW6_T3_MYHASHTABLE_H
#define LW6_T3_MYHASHTABLE_H

#include "HashTable.h"

class MyHashTable : public HashTable<unsigned int> {
public:
    explicit MyHashTable(HashTable<unsigned int>::size_t size) :
            HashTable<unsigned int>(size) {}

    void eraseEven() {
        for (int i = 0; i < size; i += 2)
            table[i].clear();
    }
};

#endif //LW6_T3_MYHASHTABLE_H
