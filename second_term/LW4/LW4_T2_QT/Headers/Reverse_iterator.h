#pragma once
#include <cstddef>
#include <cstdint>
#include "Iterator.h"

template<typename T>
class Reverse_iterator {
    T* _obj;
public:
    explicit Reverse_iterator(T *obj);
    explicit Reverse_iterator(Iterator<T> iterator);
    Reverse_iterator<T> operator+(size_t n);
    Reverse_iterator<T> operator-(size_t n);
    bool operator==(Reverse_iterator<T> val);
    bool operator!=(Reverse_iterator<T> val);
    T& operator*();
    T* operator->();
    T& operator[](size_t n);
    Reverse_iterator<T> operator++(int);
    Reverse_iterator<T>& operator+=(size_t n);
    Reverse_iterator<T>& operator-=(size_t n);
    Reverse_iterator<T>& operator++();
    Reverse_iterator<T> operator--(int);
    Reverse_iterator<T>& operator--();
};