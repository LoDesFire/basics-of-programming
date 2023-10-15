#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <algorithm>

template<typename T>
class Iterator {
    T* _obj;
public:
    explicit Iterator(T *obj);
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


template<typename T>
class Reverse_iterator {
    T* _obj;
public:
    explicit Reverse_iterator(T *obj);
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
class Vector {
    T *_arr;
    size_t _size, _capacity;


public:
    using iterator = Iterator<T>;
    using reverse_iterator = Reverse_iterator<T>;
    using const_iterator = Iterator<const T>;
    using const_reverse_iterator = Reverse_iterator<const T>;

    Vector();
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

    iterator begin() const;
    iterator end() const;
    reverse_iterator rbegin() const;
    reverse_iterator rend() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

    void pop_back();
    void push_back(T);
    void reserve(size_t);
    void resize(size_t, T element = T());
    void assign(Iterator<T>, Iterator<T>);
    void assign(Reverse_iterator<T>, Reverse_iterator<T>);
    void assign(size_t, T&&);
    void assign(size_t, T&);
    void clear();
    void swap(Vector<T>&);

    Iterator<T> erase(Iterator<T>, Iterator<T>);
    Iterator<T> erase(Iterator<T>);
    Iterator<T> insert(Iterator<T>, T& element);
    Iterator<T> insert(Iterator<T>, T&& element);
    Iterator<T> insert(Iterator<T>, std::initializer_list<T>);
    template <typename... Args>
    void emplace_back(Args&&...);
    template <typename... Args>
    void emplace(Iterator<T>, Args&&...);
};



//
//#endif //UNTITLED_MYVECTOR_H
//

