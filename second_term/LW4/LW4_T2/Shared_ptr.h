#ifndef UNTITLED1_SHARED_PTR_H
#define UNTITLED1_SHARED_PTR_H

#include <ios>

template<typename T>
class Shared_ptr {
    T *m_ptr;
    int *m_owner_count;

public:

    explicit operator bool() const {
        return m_ptr != nullptr;
    }

    explicit Shared_ptr(T *ptr = nullptr)
            : m_ptr(ptr), m_owner_count(new int(1)) {
    }

    ~Shared_ptr() {
        (*m_owner_count)--;
        if (!*m_owner_count)
            delete m_ptr;
    }

    Shared_ptr(Shared_ptr &&x)
    noexcept: m_ptr(x.m_ptr), m_owner_count(x.m_owner_count) {
        x.m_owner_count = 1;
        x.m_ptr = nullptr;
    }

    Shared_ptr(const Shared_ptr &x) {
        m_ptr = x.m_ptr;
        m_owner_count = x.m_owner_count;
        (*m_owner_count)++;
    }

    Shared_ptr &operator=(const Shared_ptr &x) {
        if (&x == this)
            return *this;

        this->~Shared_ptr();
        m_ptr = x.m_ptr;
        m_owner_count = x.m_owner_count;
        (*m_owner_count)++;
        return *this;
    }

    Shared_ptr &operator=(Shared_ptr &&x) noexcept {
        if (&x == this)
            return *this;
        this->~Shared_ptr();

        m_ptr = x.m_ptr;
        m_owner_count = x.m_owner_count;
        x.m_owner_count = 1;
        x.m_ptr = nullptr;
        return *this;
    }

    size_t use_count() {
        return *m_owner_count;
    }

    T &operator*() const { return *m_ptr; }

    T *operator->() const { return m_ptr; }

    [[nodiscard]] bool isNull() const { return m_ptr == nullptr; }
};

template<class T, class... Args>
std::enable_if_t<!std::is_array<T>::value, Shared_ptr<T>>
make_shared(Args&&... args)
{
    return Shared_ptr<T>(new T(std::forward<Args>(args)...));
}

template<class T>
requires std::is_unbounded_array_v<T>
Shared_ptr<T> make_shared(std::size_t n) {
    return Shared_ptr<T>(new std::remove_extent_t<T>[n]);
}


template<typename T>
class Shared_ptr<T[]> {
    T *m_ptr;
    int *m_owner_count;

public:

    explicit operator bool() const {
        return m_ptr != nullptr;
    }

    explicit Shared_ptr(T *ptr = nullptr)
            : m_ptr(ptr), m_owner_count(new int(1)) {
    }

    ~Shared_ptr() {
        (*m_owner_count)--;
        if (!*m_owner_count)
            delete[] m_ptr;
    }

    Shared_ptr(Shared_ptr &&x)
    noexcept: m_ptr(x.m_ptr), m_owner_count(x.m_owner_count) {
        x.m_owner_count = 1;
        x.m_ptr = nullptr;
    }

    Shared_ptr(const Shared_ptr &x) {
        m_ptr = x.m_ptr;
        m_owner_count = x.m_owner_count;
        (*m_owner_count)++;
    }

    Shared_ptr &operator=(const Shared_ptr &x) {
        if (&x == this)
            return *this;

        this->~Shared_ptr();
        m_ptr = x.m_ptr;
        m_owner_count = x.m_owner_count;
        (*m_owner_count)++;
        return *this;
    }

    Shared_ptr &operator=(Shared_ptr &&x) noexcept {
        if (&x == this)
            return *this;
        this->~Shared_ptr();

        m_ptr = x.m_ptr;
        m_owner_count = x.m_owner_count;
        x.m_owner_count = 1;
        x.m_ptr = nullptr;
        return *this;
    }

    size_t use_count() {
        return *m_owner_count;
    }

    T &operator*() const { return *m_ptr; }

    T *operator->() const { return m_ptr; }

    [[nodiscard]] bool isNull() const { return m_ptr == nullptr; }

    T &operator[](size_t index) const { return m_ptr[index]; }
};

#endif //UNTITLED1_SHARED_PTR_H
