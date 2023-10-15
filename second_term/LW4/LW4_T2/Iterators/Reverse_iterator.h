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

template <typename T>
Reverse_iterator<T>::Reverse_iterator(Iterator<T> iterator) {
    _obj = iterator.operator->() - 1;
}

template <typename T>
Reverse_iterator<T>::Reverse_iterator(T *obj) : _obj(obj) {}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator+(size_t n) {
    Reverse_iterator<T> tmp(_obj - n);
    return tmp;
}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator-(size_t n) {
    Reverse_iterator<T> tmp(_obj + n);
    return tmp;
}

template <typename T>
bool Reverse_iterator<T>::operator==(Reverse_iterator<T> val) {
    return (_obj == val._obj);
}

template <typename T>
bool Reverse_iterator<T>::operator!=(Reverse_iterator<T> val) {
    return (_obj != val._obj);
}

template <typename T>
T& Reverse_iterator<T>::operator*() {
    return *_obj;
}

template <typename T>
T* Reverse_iterator<T>::operator->() {
    return _obj;
}

template <typename T>
T& Reverse_iterator<T>::operator[](size_t n) {
    return *(_obj - n);
}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator++(int) {
    return Reverse_iterator(_obj--);
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator+=(size_t n) {
    _obj -= n;
    return *this;
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator-=(size_t n) {
    _obj += n;
    return *this;
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator++() {
    --_obj;
    return *this;
}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator--(int) {
    return Reverse_iterator(_obj++);
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator--() {
    ++_obj;
    return *this;
}