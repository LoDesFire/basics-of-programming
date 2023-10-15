#ifndef UNTITLED1_UNIQUE_PTR_H
#define UNTITLED1_UNIQUE_PTR_H

class Unique_ptr {
    char *m_ptr;

public:

    void swap(Unique_ptr &new_ptr);

    explicit operator bool() const;

    explicit Unique_ptr(char *ptr = nullptr);

    ~Unique_ptr();

    Unique_ptr(Unique_ptr &&) noexcept ;

    Unique_ptr(const Unique_ptr &x) = delete;

    Unique_ptr &operator=(Unique_ptr &a) = delete;

    Unique_ptr &operator=(Unique_ptr &&) noexcept ;

    char &operator*() const;

    char *operator->() const;

    [[nodiscard]] bool isNull() const;

    char &operator[](std::size_t index) const;
};

Unique_ptr make_unique(std::size_t n);



#endif //UNTITLED1_UNIQUE_PTR_H
