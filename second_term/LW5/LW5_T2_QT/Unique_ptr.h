#ifndef UNTITLED1_UNIQUE_PTR_H
#define UNTITLED1_UNIQUE_PTR_H

#include <iostream>

template<typename T>
class Unique_ptr {
    T *m_ptr;

public:

    void swap(Unique_ptr &new_ptr) {
        std::swap(new_ptr.m_ptr, m_ptr);
    }

    explicit operator bool() const {
        return m_ptr != nullptr;
    }

    explicit Unique_ptr(T *ptr = nullptr)
            : m_ptr(ptr) {
    }

    ~Unique_ptr() {
        delete m_ptr;
    }

    Unique_ptr(Unique_ptr &&x)
    noexcept: m_ptr(x.m_ptr) {
        x.m_ptr = nullptr;
    }

    Unique_ptr(const Unique_ptr &x) = delete;

    Unique_ptr &operator=(Unique_ptr &a) = delete;

    Unique_ptr &operator=(Unique_ptr &&x) noexcept {
        if (&x == this)
            return *this;
        delete m_ptr;

        m_ptr = x.m_ptr;
        x.m_ptr = nullptr;
        return *this;
    }

    T &operator*() const { return *m_ptr; }

    T *operator->() const { return m_ptr; }

    [[nodiscard]] bool isNull() const { return m_ptr == nullptr; }
};

template<class T, class... Args>
std::enable_if_t<!std::is_array<T>::value, Unique_ptr<T>>
make_unique(Args &&... args) {
    return Unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<class T>
requires std::is_unbounded_array_v<T>
Unique_ptr<T> make_unique(std::size_t n) {
    return Unique_ptr<T>(new std::remove_extent_t<T>[n]);
}


template<typename T>
class Unique_ptr<T[]> {
    T *m_ptr;

public:

    explicit operator bool() const {
        return m_ptr != nullptr;
    }

    explicit Unique_ptr(T *ptr = nullptr)
            : m_ptr(ptr) {
    }

    ~Unique_ptr() {
        delete[] m_ptr;
    }

    Unique_ptr(Unique_ptr &&x)
    noexcept: m_ptr(x.m_ptr) {
        x.m_ptr = nullptr;
    }

    Unique_ptr(const Unique_ptr &x) = delete;

    Unique_ptr &operator=(Unique_ptr &a) = delete;

    Unique_ptr &operator=(Unique_ptr &&x) noexcept {
        if (&x == this)
            return *this;
        delete m_ptr;

        m_ptr = x.m_ptr;
        x.m_ptr = nullptr;
        return *this;
    }

    T &operator*() const { return *m_ptr; }

    T *operator->() const { return m_ptr; }

    [[nodiscard]] bool isNull() const { return m_ptr == nullptr; }

    T &operator[](size_t index) const { return m_ptr[index]; }
};


#endif //UNTITLED1_UNIQUE_PTR_H
