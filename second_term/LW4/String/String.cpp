#include <iostream>
#include "String_global.h"

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

template<typename T>
class Reverse_iterator {
    T* _obj;
public:
    explicit Reverse_iterator(T *obj);
    explicit Reverse_iterator(Iterator<T> iterator);
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


class STRING_EXPORT String {

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
    [[nodiscard]] String&& substr(size_t, size_t) const;
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
};

Unique_ptr make_unique(std::size_t n) {
    return Unique_ptr(new char[n]);
}


template <typename T>
Reverse_iterator<T>::Reverse_iterator(Iterator<T> iterator) {
    _obj = iterator.operator->() - 1;
}

template <typename T>
Reverse_iterator<T>::Reverse_iterator(T *obj) : _obj(obj) {}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator+(size_t n) {
    Reverse_iterator<T> tmp(_obj - n);
    return tmp;
}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator-(size_t n) {
    Reverse_iterator<T> tmp(_obj + n);
    return tmp;
}

template <typename T>
bool Reverse_iterator<T>::operator==(Reverse_iterator<T> val) {
    return (_obj == val._obj);
}

template <typename T>
bool Reverse_iterator<T>::operator!=(Reverse_iterator<T> val) {
    return (_obj != val._obj);
}

template <typename T>
T& Reverse_iterator<T>::operator*() {
    return *_obj;
}

template <typename T>
T* Reverse_iterator<T>::operator->() {
    return _obj;
}

template <typename T>
T& Reverse_iterator<T>::operator[](size_t n) {
    return *(_obj - n);
}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator++(int) {
    return Reverse_iterator(_obj--);
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator+=(size_t n) {
    _obj -= n;
    return *this;
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator-=(size_t n) {
    _obj += n;
    return *this;
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator++() {
    --_obj;
    return *this;
}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator--(int) {
    return Reverse_iterator(_obj++);
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator--() {
    ++_obj;
    return *this;
}

String&& String::substr(size_t beg, size_t end) const {
    auto *tmp = new String;
    tmp->assign(this->begin() + beg, this->begin() + end);
    return std::move(*tmp);
}

String &String::operator+=(String const &str) {
    return append(str);
}
String &String::operator+=(const char *c_str) {
    return append(c_str);
}

String& String::append(const char* c_str) {
    insert(this->end(), c_str);
    return *this;
}
String& String::append(String const &str) {
    insert(this->end(), str);
    return *this;
}

String& String::insert(size_t pos, const char* c_str) {
    String new_str(c_str);
    insert(begin() + pos, new_str);
    return *this;
}

String& String::insert(iterator pos, const char* c_str) {
    String new_str(c_str);
    insert(pos, new_str);
    return *this;
}

String& String::insert(size_t pos, String const &str) {
    insert(begin() + pos, str);
    return *this;
}

String& String::insert(iterator pos, String const &str) {
    size_t delta = pos.operator->() - &this[0];

    if (this->_size + str._size > _capacity)
        reserve((this->_size + str._size) * 2);
    pos = this->begin() + delta;
    auto j = this->end() + str._size - 1;
    for (auto i = this->end() - 1; i != pos - 1; i--, j--)
        *j = *i;
    j = pos;
    for (auto i = str.begin(); i != str.end(); i++, j++)
        *j = *i;

    _size += str._size;
    _data[_size] = '\0';
    return *this;
}

String::iterator String::erase(iterator pos) {
    erase(pos, pos + 1);
    return pos;
}

String::iterator String::erase(iterator beg, iterator end) {
    size_t delta = end.operator->() - beg.operator->();
    auto j = beg;
    for (auto i = end; i != this->end(); i++, j++)
        *j = *i;

    _size -= delta;
    _data[_size] = '\0';
    return beg;
}

String &String::erase(size_t index, size_t count) {
    if (index + count > _size)
        count = _size - index;
    auto start = this->begin() + index;

    erase(start, start + count);
    return *this;
}

void String::assign(reverse_iterator beg, reverse_iterator end) {
    size_t size = beg.operator->() - end.operator->();
    String copy_str;
    copy_str.reserve(size);
    for (auto i = beg; i != end; i++) {
        copy_str.push_back(*i);
    }

    this->swap(copy_str);
}

void String::assign(iterator beg, iterator end) {
    size_t size = end.operator->() - beg.operator->();
    String copy_str;
    copy_str.reserve(size);
    for (auto i = beg; i != end; i++) {
        copy_str.push_back(*i);
    }

    this->swap(copy_str);
}

void String::assign(size_t size, char c) {
    String new_str(size, c);
    this->swap(new_str);
}

void String::assign(const char* c_str) {
    String new_str(c_str);
    this->swap(new_str);
}

void String::push_back(char c) {
    _size++;
    if (_size - 1 == _capacity)
        reserve(_size * 2);

    _data[_size - 1] = c;
    _data[_size] = '\0';
}

void String::pop_back() {
    if (!_size)
        throw std::out_of_range("String::pop_back()");
    _size -= 1;
    _data[_size] = '\0';
}

String::operator const char*() {
    return _data.operator->();
}

String &String::operator=(String &&str) noexcept {
    if (_data.operator->() == str._data.operator->())
        return *this;

    this->_data = std::move(str._data);
    str._data = Unique_ptr();

    this->_size = str._size;
    this->_capacity = str._capacity;

    return *this;
}

String &String::operator=(String const &str) {
    if (_data.operator->() == str._data.operator->())
        return *this;

    String new_str = String(str);
    this->swap(new_str);

    return *this;
}

String &String::operator=(const char *c_str) {
    if (_data.operator->() == c_str)
        return *this;

    String new_str(c_str);
    this->swap(new_str);

    return *this;
}

String::String(const char *c_str)
        : String() {
    size_t size = 0;
    while (c_str[size++] != '\0');
    size--;

    reserve(size);

    for (size_t i = 0; i < size; i++) {
        _data[i] = c_str[i];
    }
    _size = size;
    _data[_size] = '\0';
}


String::~String() {
    _capacity = 0;
    _size = 0;
}

String::String()
        : _capacity(0), _size(0), _data(Unique_ptr()) {}

String::String(size_t size, char c) : String() {
    reserve(size);
    resize(size, c);
}

String::String(String &&str) noexcept {
    _data = std::move(str._data);
    str._data = Unique_ptr();
    _size = str._size;
    _capacity = str._capacity;
}

String::String(String const &str) {
    _data = ::make_unique(str._capacity);
    for (size_t i = 0; i <= str._size; i++)
        _data[i] = str[i];

    _capacity = str._capacity;
    _size = str._size;
}

void String::reserve(size_t new_cap) {
    if (new_cap <= _capacity)
        return;
    Unique_ptr new_data = make_unique(new_cap);
    for (size_t i = 0; i < _size; i++)
        new_data[i] = _data[i];
    _data.swap(new_data);
    _capacity = new_cap;
    _data[_size] = '\0';
}

void String::resize(size_t size, char c) {
    if (size > _capacity)
        reserve(size * 2);

    for (size_t i = _size; i < size; i++)
        _data[i] = c;
    _size = size;
    _data[_size] = '\0';
}

void String::clear() { resize(0); }

void String::swap(String &vect2) {
    std::swap(_data, vect2._data);
    std::swap(_size, vect2._size);
    std::swap(_capacity, vect2._capacity);
}

typename String::const_reverse_iterator String::crbegin() const {
    return const_reverse_iterator(rbegin().operator->());
}

typename String::const_reverse_iterator String::crend() const { return const_reverse_iterator(rend().operator->()); }

typename String::const_iterator String::cbegin() const { return const_iterator(begin().operator->()); }

typename String::const_iterator String::cend() const { return const_iterator(end().operator->()); }

typename String::reverse_iterator String::rbegin() const { return reverse_iterator(end()); }

typename String::reverse_iterator String::rend() const { return reverse_iterator(begin()); }

typename String::iterator String::begin() const { return iterator(_data.operator->()); }

typename String::iterator String::end() const { return iterator(_data.operator->() + _size); }

char &String::operator[](size_t pos) const { return _data[pos]; }

char &String::at(size_t pos) const {
    if (pos >= _size)
        throw std::out_of_range("String::at()");
    return _data[pos];
}

bool String::empty() const { return _size == 0; }

char &String::back() const { return _data[_size - 1]; }

char *String::data() const { return _data.operator->(); }

char &String::front() const { return _data[0]; }

size_t String::capacity() const { return _capacity; }

size_t String::size() const { return _size; }

size_t String::max_size() {
    size_t max_ram = 9223372036854775807;
    return max_ram / ((sizeof(char) + 1) / 2);
}










String& String::Strcpy(String& s1, const String& s2) {
    s1.assign(s2.data());
    return s1;
}

String& String::Strncpy(String& s1, String& s2, size_t n) {
    s1.assign(s2.begin(), s2.begin() + n);
    return s1;
}

String& String::Strcat(String& s1, String& s2) {
    s1.append(s2);
    return s1;
}

String& String::Strncat(String& s1, String& s2, size_t n) {
    s1.append(s2.substr(0, n));
    return s1;
}

int String::Strcmp(String& s1, String& s2) {
    for (size_t i = 0; i == 0 || (s1[i - 1] != '\0' && s2[i - 1] != '\0');  i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}

int String::Strncmp(String& s1, String& s2, size_t n) {
    for (size_t i = 0; i < n && (i == 0 || (s1[i - 1] != '\0' && s2[i - 1] != '\0')); i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}

String&& String::Strtok(String& s1, String& s2) {
    static Iterator<char> begIt = nullptr, endIt = nullptr;

    auto *returnVal = new String;
    bool character[256]{};
    for (auto i : s2)
        character[i] = true;

    if (s1.data()) {
        begIt = s1.begin();
        endIt = s1.end();
    }

    auto it = begIt;
    while (it != endIt && character[*it])
        it++;

    if (it == endIt) {
        returnVal->assign(begIt, endIt);
        return std::move(*returnVal);
    }

    auto tokenBegin = it;

    while (it != endIt && !character[*it])
        it++;

    if (it != endIt)
        *it++ = '\0';

    returnVal->assign(tokenBegin, it);
    begIt = it;
    return std::move(*returnVal);
}

int String::Memcmp(const void *s1, const void *s2, size_t n) {
    auto *a = reinterpret_cast<const unsigned char *>(s1);
    auto *b = reinterpret_cast<const unsigned char *>(s2);
    for (size_t i = 0; i < n; i++) {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}

void *String::Memcpy(void *s1, const void *s2, size_t n) {
    auto *b = reinterpret_cast<const unsigned char *>(s2);
    auto *c = reinterpret_cast<unsigned char *>(s1);
    for (auto i = 0; i < n; i++)
        c[i] = b[i];
    return s1;
}

void *String::Memmove(void *s1, const void *s2, size_t n) {
    unsigned char arr[n];
    auto *b = reinterpret_cast<const unsigned char *>(s2);
    auto *c = reinterpret_cast<unsigned char *>(s1);
    for (auto i = 0; i < n; i++)
        arr[i] = b[i];
    for (auto i = 0; i < n; i++)
        c[i] = arr[i];
    return s1;
}

void *String::Memset(void *s, int c, size_t n) {
    auto *b = reinterpret_cast<unsigned char *>(s);
    for (auto i = 0; i < n; i++)
        b[i] = static_cast<unsigned char>(c);
    return s;
}


String&& String::Strerror(int errnum) {
    auto *tmp = new String(std::strerror(errnum));
    return std::move(*tmp);
}

size_t String::Strlen(String& s) {
    return s.size();
}

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
