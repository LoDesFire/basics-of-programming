#ifndef LW5_T2_ITERATOR_H
#define LW5_T2_ITERATOR_H

#include "deque.h"

template<typename T>
class Iterator {
    size_t index;
    typename Deque<T>::size_t* chunk;
    Deque<T> *deque;
public:
    Iterator(Deque<T> *ptr, typename Deque<T>::size_t* , typename Deque<T>::size_t);
    Iterator<T> operator++();
    Iterator<T> operator--();
    Iterator<T> operator+=(size_t);
    Iterator<T> operator-=(size_t);
    Iterator<T> operator[](size_t);
    bool operator!=(Iterator<T>);
    bool operator==(Iterator<T>);
    T& operator*();
};


template <typename T>
bool Iterator<T>::operator!=(Iterator<T> value2) {
    return !operator==(value2);
}

template <typename T>
bool Iterator<T>::operator==(Iterator<T> value2) {
    return this->chunk == value2.chunk && this->index == value2.index;
}


template <typename T>
Iterator<T>::Iterator(Deque<T> *ptr, typename Deque<T>::size_t*  _chunk, typename Deque<T>::size_t ind) {
    deque = ptr;
    chunk = _chunk;
    index = ind;
}

template <typename T>
Iterator<T> Iterator<T>::operator[](size_t ind) {
    if (ind > deque->CHUNK_SIZE - index - 1) {
        ind -= deque->CHUNK_SIZE - index - 1;
        *chunk += 1;
        *chunk += ind / deque->CHUNK_SIZE;
        index = ind - (ind / deque->CHUNK_SIZE) * deque->CHUNK_SIZE - 1;
    }
    else {
        index += ind;
    }
}

template <typename T>
Iterator<T> Iterator<T>::operator+=(size_t value) {
    if (value > deque->CHUNK_SIZE - index - 1) {
        value -= deque->CHUNK_SIZE - index - 1;
        *chunk += 1;
        *chunk += value / deque->CHUNK_SIZE;
        index = value - (value / deque->CHUNK_SIZE) * deque->CHUNK_SIZE - 1;
    }
    else {
        index += value;
    }
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator-=(size_t value) {
    if (value > index) {
        value -= index;
        (*chunk)--;
        (*chunk) -= value / deque->CHUNK_SIZE;
        index = value - (value / deque->CHUNK_SIZE) * deque->CHUNK_SIZE;
    }
    else {
        index -= value;
    }
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--() {
    if (index == 0) {
        if (*chunk == 0)
            throw std::length_error("");
        chunk = deque->chunksArray[*chunk - 1].chunkNumber;
        index = deque->CHUNK_SIZE;
    }
    index--;

    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++() {
    index++;
    if (index >= deque->CHUNK_SIZE) {
        chunk = (deque->chunksArray[*chunk + 1].chunkNumber);
        index = 0;
    }
    return *this;
}

template <typename T>
T& Iterator<T>::operator*() {
    return deque->chunksArray[*chunk].chunk[index];
}




#endif //LW5_T2_ITERATOR_H
