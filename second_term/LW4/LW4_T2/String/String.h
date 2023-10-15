#ifndef LW4_T2_STRING_H
#define LW4_T2_STRING_H

#include <cstddef>
#include <cstdint>
#include "../Iterators/Iterator.h"
#include "../Unique_ptr/Unique_ptr.h"
#include "../Iterators/Reverse_iterator.h"

class String {

    Unique_ptr _data;
    size_t _size, _capacity{};

public:
    using iterator = Iterator<char>;
    using reverse_iterator = Reverse_iterator<char>;
    using const_iterator = Iterator<const char>;
    using const_reverse_iterator = Reverse_iterator<const char>;

    String();
    String(size_t, char);
    String(String &&) noexcept;
    String(String const &);
    /* implicit */ String(const char *);
    String &operator=(const char *);
    String &operator=(String const &);
    String &operator=(String &&) noexcept;
    String &operator+=(String const &);
    String &operator+=(const char*);
//    String &&operator+(String const &);
//    String &&operator+(const char*);
    operator const char*();
    //String& operator=(std::initializer_list<char>);


    ~String();
    [[nodiscard]] iterator begin() const;
    [[nodiscard]] iterator end() const;
    [[nodiscard]] reverse_iterator rbegin() const;
    [[nodiscard]] reverse_iterator rend() const;
    [[nodiscard]] const_iterator cbegin() const;
    [[nodiscard]] const_iterator cend() const;
    [[nodiscard]] const_reverse_iterator crbegin() const;
    [[nodiscard]] const_reverse_iterator crend() const;
    [[nodiscard]] char &at(size_t) const;
    [[nodiscard]] char &back() const;
    [[nodiscard]] size_t capacity() const;
    [[nodiscard]] size_t size() const;
    [[nodiscard]] char *data() const;
    [[nodiscard]] char &front() const;
    [[nodiscard]] bool empty() const;
    static size_t max_size();
    char &operator[](size_t) const;

    void pop_back();
    void push_back(char);
    [[nodiscard]] String&& substr(size_t a, size_t b) const;
    void reserve(size_t);
    void resize(size_t, char = '\0');
    void assign(iterator, iterator);
    void assign(reverse_iterator, reverse_iterator);
    void assign(size_t, char);
    void assign(const char*);
    void clear();
    void swap(String &);

    iterator erase(iterator, iterator);
    iterator erase(iterator);
    String &erase(size_t, size_t);
    String& insert(iterator, String const &);
    String& insert(size_t, String const &);
    String& insert(size_t, const char*);
    String& insert(iterator, const char*);
    String& append(const char*);
    String& append(String const &);



    static String& Strcpy(String& s1, const String& s2);

    static String& Strncpy(String& s1, String& s2, size_t n);

    static String& Strcat(String& s1, String& s2);

    static String& Strncat(String& s1, String& s2, size_t n);

    static int Strcmp(String& s1, String& s2);

    static int Strncmp(String& s1, String& s2, size_t n);

    static String&& Strtok(String& s1, String& s2);

    static int Memcmp(const void *s1, const void *s2, size_t n);

    static void *Memcpy(void *s1, const void *s2, size_t n);

    static void *Memmove(void *s1, const void *s2, size_t n);

    static void *Memset(void *s, int c, size_t n);

    static String&& Strerror(int errnum);

    static size_t Strlen(String& s);

    //iterator insert(iterator, std::initializer_list<char>);
};

//String &&String::operator+(String const &str) {
//    String new_str(*this);
//    new_str += str;
//    return (String &&) new_str;
//}
//
//String &&String::operator+(const char* c_str) {
//    String new_str(*this);
//    new_str += c_str;
//    return (String &&) new_str;
//}

#endif //LW4_T2_STRING_H
