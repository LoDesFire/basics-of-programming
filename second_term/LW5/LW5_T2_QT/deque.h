#ifndef LW5_T2_DEQUE_H
#define LW5_T2_DEQUE_H

#include "Shared_ptr.h"
#include "Iterator.h"


template<typename T>
class Iterator;

template<typename T>
class Deque {
    void resize_back();

    void resize_front();

    using size_t = unsigned long long;
    static const size_t CHUNK_SIZE = 5;
    struct _chunk {
        T chunk[CHUNK_SIZE];
        size_t *chunkNumber;
    };

    struct {
        size_t chunk, index;
    } beg, _end;

    size_t _sizeChunks, _size;
    Shared_ptr<_chunk[]> chunksArray;
public:
    Deque();

    void push_back(T);

    void print();

    void push_front(T);

    void pop_back();

    void pop_front();

    void clear();

    size_t size();

    bool empty();

    Iterator<T> begin();

    Iterator<T> end();

    friend class Iterator<T>;
};

template<typename T>
Deque<T>::Deque() :
        _sizeChunks(0),
        _size(0),
        chunksArray(make_shared<_chunk[]>(0)),
        beg{0, 0},
        _end{0, 0}
{}

template<typename T>
void Deque<T>::push_back(T element) {
    if (_sizeChunks == 0) {
        resize_back();
    }
    if (_end.index == CHUNK_SIZE) {
        resize_back();
        _end.chunk += 1;
        _end.index = 0;
    }

    chunksArray[_end.chunk].chunk[_end.index] = element;
    _end.index++;
    _size++;
}

template<typename T>
void Deque<T>::resize_back() {
    Shared_ptr<_chunk[]> _tmp = make_shared<_chunk[]>(_sizeChunks + 1);
    for (size_t i = 0; i < _sizeChunks; i++) {
        _tmp[i].chunkNumber = chunksArray[i].chunkNumber;
        *_tmp[i].chunkNumber = i;
        std::swap(_tmp[i], chunksArray[i]);
    }
    _sizeChunks++;
    _tmp[_sizeChunks - 1].chunkNumber = new size_t(_sizeChunks - 1);

    chunksArray = std::move(_tmp);
}

template<typename T>
void Deque<T>::resize_front() {
    Shared_ptr<_chunk[]> _tmp = make_shared<_chunk[]>(_sizeChunks + 1);
    _tmp[0].chunkNumber = new size_t(0);
    for (size_t i = 1; i < _sizeChunks + 1; i++) {
        _tmp[i].chunkNumber = chunksArray[i-1].chunkNumber;
        *_tmp[i].chunkNumber = i;
        std::swap(_tmp[i], chunksArray[i - 1]);
    }
    _sizeChunks++;
    beg.chunk++;
    _end.chunk++;

    chunksArray = std::move(_tmp);
}

template<typename T>
void Deque<T>::push_front(T element) {
    if (_sizeChunks == 0) {
        resize_back();
        beg.index = CHUNK_SIZE;
        _end.index = CHUNK_SIZE;
    }
    if (beg.index == 0) {
        resize_front();
        beg.chunk -= 1;
        beg.index = CHUNK_SIZE;
    }

    beg.index--;
    chunksArray[beg.chunk].chunk[beg.index] = element;
    _size++;

}

template<typename T>
void Deque<T>::pop_back() {
    if (_size == 0)
        throw std::out_of_range("pop_back in Deque");

    _end.index--;
//    chunksArray[_end.chunk].chunk[_end.index].~T();
//    chunksArray[_end.chunk].chunk[_end.index] = T();
    if (_end.index == 0) {
        _end.chunk--;
        _end.index = CHUNK_SIZE;
    }
    _size--;

    if (_size == 0)
        _end = beg;
}

template<typename T>
void Deque<T>::pop_front() {
    if (_size == 0)
        throw std::out_of_range("pop_back in Deque");

//    chunksArray[beg.chunk].chunk[beg.index].~T();
//    chunksArray[_end.chunk].chunk[_end.index] = T();
    beg.index++;
    if (beg.index == CHUNK_SIZE) {
        beg.chunk++;
        beg.index = 0;
    }
    _size--;

    if (_size == 0)
        _end = beg;
}

template<typename T>
void Deque<T>::clear() {
    _sizeChunks = 0;
    _size = 0;
    chunksArray = make_shared<_chunk[]>(0);
    beg = {0, 0};
    _end = {0, 0};
}

template<typename T>
typename Deque<T>::size_t Deque<T>::size() {
    return _size;
}

template<typename T>
bool Deque<T>::empty() {
    return _size == 0;
}

template<typename T>
void Deque<T>::print() {
    size_t chunk, tmp_index;
    tmp_index = beg.index;
    chunk = beg.chunk;

    while (tmp_index != _end.index || chunk != _end.chunk) {
        std::cout << chunksArray[chunk].chunk[tmp_index] << " ";
        tmp_index++;
        if (tmp_index == _end.index && chunk == _end.chunk)
            break;
        if (tmp_index == CHUNK_SIZE) {
            tmp_index = 0;
            chunk++;
        }
    }
}

template<typename T>
Iterator<T> Deque<T>::begin() {
    return Iterator<T>(this, chunksArray[beg.chunk].chunkNumber, beg.index);
}

template<typename T>
Iterator<T> Deque<T>::end() {
    return Iterator<T>(this, chunksArray[_end.chunk].chunkNumber, _end.index);
}

#endif
