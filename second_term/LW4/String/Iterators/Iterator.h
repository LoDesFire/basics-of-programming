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

template <typename T>
Iterator<T>::Iterator(T *obj) : _obj(obj) {}

template <typename T>
T& Iterator<T>::operator*() {
    return *_obj;
}

template <typename T>
bool Iterator<T>::operator==(Iterator<T> val) {
    return (_obj == val._obj);
}

template <typename T>
bool Iterator<T>::operator!=(Iterator<T> val) {
    return (_obj != val._obj);
}

template <typename T>
T* Iterator<T>::operator->() {
    return _obj;
}

template <typename T>
T& Iterator<T>::operator[](size_t n) {
    return _obj[n];
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
    return Iterator(_obj++);
}

template <typename T>
Iterator<T>& Iterator<T>::operator+=(size_t n) {
    _obj += n;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator-=(size_t n) {
    _obj -= n;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    ++_obj;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int) {
    return Iterator(_obj--);
}

template <typename T>
Iterator<T> Iterator<T>::operator+(size_t n) {
    Iterator<T> tmp(_obj + n);
    return tmp;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(size_t n) {
    Iterator<T> tmp(_obj - n);
    return tmp;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--() {
    --_obj;
    return *this;
}