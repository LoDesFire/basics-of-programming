//
// Created by Даниил Шумский on 9.05.23.
//

#include "Stack.h"

template <typename T>
class HashTable {
public:
    using size_t = unsigned long long;

    explicit HashTable(size_t);
    void deleteValue(T);
    void insertValue(T);
    bool findValue(T);
    void print();

protected:
    size_t size;
    Stack<T> *table;
    size_t hash(size_t);
};

template <typename T>
typename HashTable<T>::size_t HashTable<T>::hash(typename HashTable<T>::size_t value) {
    return value % size;
}

template <typename T>
HashTable<T>::HashTable(typename HashTable<T>::size_t _size) :
    size(_size),
    table(new Stack<T>[size]())
{}

template <typename T>
bool HashTable<T>::findValue(T value) {
    size_t key = hash(value);
    auto curNode = table[key].topNode();
    while (curNode) {
        if (curNode->data == value)
            return true;
        curNode = curNode->next;
    }
    return false;
}

template <typename T>
void HashTable<T>::insertValue(T value) {
    size_t key = hash(value);

    if (!findValue(value))
        table[key].push(value);
}

template <typename T>
void HashTable<T>::print() {
    for (int i = 0; i < size; i++) {
        if (!table[i].isEmpty()) {
            auto curNode = table[i].topNode();
            while (curNode) {
                std::cout << curNode->data;
                curNode = curNode->next;
                if (curNode)
                    std::cout << " -> ";
            }
            std::cout << "\n";
        }
    }
}

template <typename T>
void HashTable<T>::deleteValue(T value) {
    if (!findValue(value))
        return;

    size_t key = hash(value);
    if (table[key].top() == value) {
        table[key].pop();
        return;
    }
    auto prevNode = table[key].topNode();
    auto curNode = prevNode->next;

    while (curNode) {
        if (curNode->data == value) {
            prevNode->next = curNode->next;
            curNode->next = nullptr;
            delete curNode;
            return;
        }

        prevNode = curNode;
        curNode = curNode->next;
    }
    throw std::exception();
}