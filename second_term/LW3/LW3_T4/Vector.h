#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <algorithm>
#include "Iterator.h"
#include "Reverse_iterator.h"
#include <QDebug>

template <typename T>
class Vector {
    T *_arr;
    size_t _size, _capacity;

public:
    using iterator = Iterator<T>;
    using reverse_iterator = Reverse_iterator<T>;
    using const_iterator = Iterator<const T>;
    using const_reverse_iterator = Reverse_iterator<const T>;

    Vector();
    ~Vector();
    Vector(size_t, T element = T());
    Vector(std::initializer_list<T>);
    Vector(Vector<T> const &);
    T& at(size_t) const;
    T& back() const;
    [[nodiscard]] size_t capacity() const;
    [[nodiscard]] size_t size() const;
    T* data() const;
    T& front() const;
    [[nodiscard]] size_t max_size() const;
    [[nodiscard]] bool empty() const;
    T& operator[](size_t) const;
    void operator=(Vector<T> const &);

    iterator begin() const;
    iterator end() const;
    reverse_iterator rbegin() const;
    reverse_iterator rend() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

    void pop_back();
    void push_back(T&&);
    void push_back(T const&);
    void reserve(size_t);
    void resize(size_t, T element = T());
    void assign(Iterator<T>, Iterator<T>);
    void assign(Reverse_iterator<T>, Reverse_iterator<T>);
    void assign(size_t, T&&);
    void assign(size_t, T const&);
    void clear();
    void swap(Vector<T>&);

    Iterator<T> erase(Iterator<T>, Iterator<T>);
    Iterator<T> erase(Iterator<T>);
    Iterator<T> insert(Iterator<T>, T const& element);
    Iterator<T> insert(Iterator<T>, T&& element);
    Iterator<T> insert(Iterator<T>, std::initializer_list<T>);
    template <typename... Args>
    void emplace_back(Args&&...);
    template <typename... Args>
    void emplace(Iterator<T>, Args&&...);
};

template <typename T>
Vector<T>::~Vector() {

    for (int i = 0; i < _size; i++)
        (_arr + i)->~T();

    _capacity = 0;
    _size = 0;
    delete[] reinterpret_cast<int8_t*>(_arr);
    _arr = nullptr;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> l) :
    _size(l.size()),
    _capacity(l.size())
{
    _arr = reinterpret_cast<T*>(new int8_t[_size * sizeof(T)]);
    auto listIt = l.begin();
    for (size_t i = 0; i < _size; i++, listIt++) {
        T tmp = *listIt;
        new (_arr + i) T(std::move(tmp));
    }
}

template <typename T>
void Vector<T>::push_back(T const &newItem) {
    insert(this->end(), newItem);
}

template <typename T>
void Vector<T>::push_back(T&& newItem) {
    insert(this->end(), newItem);
}

template <typename T>
Iterator<T> Vector<T>::insert(Iterator<T> pos, std::initializer_list<T> list) {
    size_t ptr_num = pos.operator->() - begin().operator->();
    if (_size + list.size() >= _capacity) reserve(_size * 2 + list.size());

    T* ptr = &(*this)[ptr_num];

    for (auto i = end().operator->() + list.size() - 1; i > ptr + list.size() - 1; i--) {
        new (i) T(*(i - list.size()));
    }
    auto l = list.begin();
    for (auto i = ptr; i < ptr + list.size(); i++, l++) {
        new (i) T(*l);
    }
    _size += list.size();
    return pos;
}

template <typename T>
Iterator<T> Vector<T>::insert(Iterator<T> pos, T const& element) {
    return insert(pos, {element});
}

template <typename T>
Iterator<T> Vector<T>::insert(Iterator<T> pos, T&& element) {
    size_t ptr_num = pos.operator->() - begin().operator->();
    if (_size == _capacity) reserve(_size * 2 + 1);
    T* ptr = &(*this)[ptr_num];

    for (auto i = end().operator->(); i > ptr; i--) {
        new (i) T(*(i - 1));
    }

    new (ptr) T(std::move(element));
    _size++;
    return pos;
}

template <typename T>
void Vector<T>::assign(size_t newSize, T const& element) {
    clear();
    reserve(newSize);

    for (size_t i = 0; i != newSize; i++) {
        this->push_back(element);
    }
}

template <typename T>
void Vector<T>::assign(size_t newSize, T&& element) {
    clear();
    reserve(newSize);

    for (size_t i = 0; i != newSize; i++) {
        this->push_back(std::move(element));
    }
}

template <typename T>
void Vector<T>::resize(size_t newSize, T element) {
    reserve(newSize);
    for (size_t i = _size; i < newSize; i++) {
        new (_arr + i) T(element);
    }
    if (newSize < _size) {
        for (size_t i = newSize; i < _size; i++) {
            (_arr + i)->~T();
        }
    }
    _size = newSize;
}

template <typename T>
Vector<T>::Vector(size_t size, T element) :
        _size(size),
        _capacity(size)
{
    _arr = reinterpret_cast<T*>(new int8_t[size * sizeof(T)]);
    for (size_t i = 0; i < size; i++) {
        new (_arr + i) T(element);
    }
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace(Iterator<T> pos, Args&&... args) {
    T tmp(args...);
    insert(pos, std::move(tmp));
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace_back(Args&&... args) {
    emplace(this->end(), args...);
}

template <typename T>
Vector<T>::Vector(Vector<T> const &element) {
    _size = element._size;
    _capacity = element._capacity;
    _arr = reinterpret_cast<T*>(new int8_t[_size * sizeof(T)]);
    for (size_t i = 0; i < _size; i++) {
        new (_arr + i) T(element[i]);
    }
}

template <typename T>
void Vector<T>::operator=(Vector<T> const &element) {
    _size = element._size;
    _capacity = element._capacity;
    _arr = reinterpret_cast<T*>(new int8_t[_size * sizeof(T)]);
    for (size_t i = 0; i < _size; i++) {
        new (_arr + i) T(element[i]);
    }
}

template <typename T>
Iterator<T> Vector<T>::erase(Iterator<T> front, Iterator<T> back) {
    T *fr = front.operator->(), *bck = back.operator->();
    size_t diff = bck - fr;
    if (bck < fr) return front;
    for (auto i = fr; i < bck; i++)
        i->~T();
    _size -= diff;

    for (; fr < _arr + _size; fr++) {
        new (fr) T(std::move(*(fr + diff)));
    }
    return Iterator<T>(front);
}

template <typename T>
Iterator<T> Vector<T>::erase(Iterator<T> pos) {
    return erase(pos, ++pos);
}

template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const {
    return const_reverse_iterator(_arr + _size - 1);
}

template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const {
    return const_reverse_iterator(_arr - 1);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const {
    return const_iterator(_arr);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const {
    return const_iterator(_arr + _size);
}

template <typename T>
void Vector<T>::swap(Vector<T>& vect2) {
    std::swap(_arr, vect2._arr);
    std::swap(_size, vect2._size);
    std::swap(_capacity, vect2._capacity);
}

template <typename T>
void Vector<T>::clear() {
    resize(0);
}

template <typename T>
void Vector<T>::assign(Iterator<T> front, Iterator<T> back) {
    clear();
    size_t newSize = back.operator->() - front.operator->();
    if (newSize > _capacity) this->reserve(newSize);

    for (auto i = front; i != back; i++) {
        this->push_back(*i);
    }
}

template <typename T>
void Vector<T>::assign(Reverse_iterator<T> front, Reverse_iterator<T> back) {
    clear();
    size_t newSize = front.operator->() - back.operator->();
    if (newSize > _capacity) this->reserve(newSize);

    for (auto i = front; i != back; i++) {
        this->push_back(*i);
    }
}

template <typename T>
void Vector<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Vector::pop_back()");
    }
    (_arr + _size - 1)->~T();
    _size--;
}

template <typename T>
T& Vector<T>::operator[](size_t pos) const {
    return _arr[pos];
}

template <typename T>
void Vector<T>::reserve(size_t newCapacity) {
    if (newCapacity <= _capacity) return;

    T* newarr = reinterpret_cast<T*>(new int8_t[newCapacity * sizeof(T)]);

    for (size_t i = 0; i < _size; i++) {
        new (newarr + i) T(_arr[i]);
    }

    for (size_t i = 0; i < _size; i++) {
        (_arr + i)->~T();
    }

    delete[] reinterpret_cast<int8_t*>(_arr);
    _arr = newarr;
    _capacity = newCapacity;
}

template <typename T>
bool Vector<T>::empty() const {
    return _size == 0;
}

template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin() const {
    return reverse_iterator(_arr + _size - 1);
}

template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend() const {
    return reverse_iterator(_arr - 1);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() const {
    return iterator(_arr);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() const {
    return iterator(_arr + _size);
}

template <typename T>
Vector<T>::Vector() :
    _size(0),
    _capacity(0),
    _arr(nullptr)
{}



template <typename T>
T& Vector<T>::at(size_t pos) const
{
    if (pos >= _size)
    {
        throw  std::out_of_range("Vector::at()");
    }
    return _arr[pos];
}

template <typename T>
T& Vector<T>::back() const
{
    return _arr[_size - 1];
}

template <typename T>
size_t Vector<T>::capacity() const
{
    return _capacity;
}

template <typename T>
size_t Vector<T>::size() const
{
    return _size;
}

template <typename T>
T* Vector<T>::data() const
{
    return _arr;
}

template <typename T>
T& Vector<T>::front() const {
    return _arr[0];
}

template <typename T>
size_t Vector<T>::max_size() const {
    size_t max_ram = 9223372036854775807;
    if (sizeof(T) - 1 == 0)
        return max_ram / ((sizeof(T) + 1) / 2);
    return max_ram / (sizeof(T) / 2);
}


//
//#endif //UNTITLED_MYVECTOR_H
//

