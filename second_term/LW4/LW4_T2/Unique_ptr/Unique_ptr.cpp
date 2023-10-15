#include "Unique_ptr.h"

void Unique_ptr::swap(Unique_ptr &new_ptr) {
    std::swap(new_ptr.m_ptr, m_ptr);
}

Unique_ptr::operator bool() const {
    return m_ptr != nullptr;
}

Unique_ptr::Unique_ptr(char *ptr)
        : m_ptr(ptr) {
}

Unique_ptr::~Unique_ptr() {
    delete[] m_ptr;
}

Unique_ptr::Unique_ptr(Unique_ptr &&x)
noexcept: m_ptr(x.m_ptr) {
    x.m_ptr = nullptr;
}

Unique_ptr &Unique_ptr::operator=(Unique_ptr &&x) noexcept {
    if (&x == this)
        return *this;
    delete m_ptr;

    m_ptr = x.m_ptr;
    x.m_ptr = nullptr;
    return *this;
}

char &Unique_ptr::operator*() const { return *m_ptr; }

char *Unique_ptr::operator->() const { return m_ptr; }

[[nodiscard]] bool Unique_ptr::isNull() const { return m_ptr == nullptr; }

char &Unique_ptr::operator[](std::size_t index) const { return m_ptr[index]; }

Unique_ptr make_unique(std::size_t n) {
    return Unique_ptr(new char[n]);
}