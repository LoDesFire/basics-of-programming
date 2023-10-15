//
// Created by Даниил Шумский on 8.05.23.
//

#include "hash_table.h"

HashTable::HashTable(int Size) :
        size(Size)
{
    table = new int[size]{};
    isUsed = new bool[size]{};
}

[[nodiscard]] int HashTable::hash(int key) const
{
    return key % size;
}

void HashTable::insertValue(int value, int i) {
    int key = hash(value + i);
    if (!isUsed[key] || table[key] == value) {
        isUsed[key] = true;
        table[key] = value;
        return;
    }

    insertValue(value, i + 1);
}

bool HashTable::findValue(int value, int i) {
    int key = hash(value + i);
    if (!isUsed[key])
        return false;

    if (table[key] == value)
        return true;

    return findValue(value, i + 1);
}

void HashTable::print() {
    for (int i = 0; i < size; i++) {
        if (isUsed[i]) {
            QString response = QString::number(i);
            response += ": ";
            response += QString::number(table[i]);
            qDebug() << response;
        }
    }
}

int HashTable::operator[](int index) {
    return table[index];
}
