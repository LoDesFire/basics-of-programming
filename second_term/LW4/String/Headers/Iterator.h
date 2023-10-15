#pragma once
#include <cstddef>
#include <cstdint>

template<typename T>
class Iterator {
    T* _obj;
public:
    Iterator(T *obj);
    T& operator*();
    bool operator==(Iterator<T> val);
    bool operator!=(Iterator<T> val);
    T* operator->();
    T& operator[](size_t n);
    Iterator<T> operator++(int);
    Iterator<T>& operator+=(size_t n);
    Iterator<T>& operator-=(size_t n);
    Iterator<T>& operator++();
    Iterator<T> operator--(int);
    Iterator<T> operator+(size_t n);
    Iterator<T> operator-(size_t n);
    Iterator<T>& operator--();
};