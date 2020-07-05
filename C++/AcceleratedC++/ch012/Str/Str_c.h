#pragma once

#include <memory>
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_fill;

#include <stdexcept>
using std::out_of_range;

#include <cstring>
using std::strcmp;

class Str { 
    friend std::istream& operator>>(std::istream&, Str&);
    friend std::istream& getline(std::istream&, Str&);

public:
    typedef size_t size_type;
    typedef char* iterator;
    typedef const char* const_iterator;
    
    Str() { create(0, '\0'); }
    Str(size_type n , char c) { create(n, c); }
    Str(const Str& s) { create(s.begin(), s.end()); }
    Str(const char* cp) {  create(cp, cp + std::strlen(cp)); }
    template <class In> Str(In b, In e) { create(b, e); }

    Str& operator=(const Str&);

    ~Str() { uncreate(); }

    char& operator[](size_type i) { return chars[i]; }
    const char& operator[](size_type i) const { return chars[i]; }
    size_type size() const { return length - 1; }
    //
    iterator begin() { return chars; }
    const_iterator begin() const { return chars; }

    iterator end() { return chars + length - 1; }
    const_iterator end() const { return chars + length - 1; }

    Str& operator+=(const Str& s);
    Str& operator+=(const char* cp);

    const char* c_str() const { return chars; }
    const char* data() const { return chars; }
    size_type copy(iterator, size_type, size_type = 0) const;

    // Conversion operators - 12.6
    // ================
    // does not compile
    // use of overloaded operator '==' is ambiguous (with operand types 'Str' and 'const char [4]')
    // operator void*() const { return is_not_empty(); };
    operator bool() const { return size() > 0; }
    
    //
    Str substr(size_type, size_type) const;
    template <class In> void insert(iterator, In, In);

private:
    size_type length;
    iterator chars;
    
    allocator<char> alloc;

    void create(size_type, char);
    template<class In> void create(In, In);
    void uncreate();

    void append(const_iterator b, const_iterator e);
    void append(const char*, const size_type);
    void append(const char c);

    // void* is_not_empty() const {
    //     if (size() > 0)
    //         return chars;
    //     else
    //         return 0;
    // }
};

void Str::create(size_type n, char val) {
    length = n + 1;
    chars = alloc.allocate(length);
    uninitialized_fill(chars, chars + length - 1, val);
    alloc.construct(chars + length - 1, '\0');
}

template<class In>
void Str::create(In i, In j) {
    length = j - i + 1;
    chars = alloc.allocate(length);
    uninitialized_copy(i, j, chars);
    alloc.construct(chars + length - 1, '\0');
}

void Str::uncreate() {
    if (chars) {
        iterator it = chars + length;
        while (it != chars)
            alloc.destroy(--it);

        alloc.deallocate(chars, length);
    }
    chars = 0;
    length = 0;
}

Str& Str::operator=(const Str& rhs) {
    if (&rhs != this) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

Str& Str::operator+=(const Str& rhs) {
    append(rhs.begin(), rhs.end());
    return *this;
}

Str& Str::operator+=(const char* cp) {
    append(cp, strlen(cp));
    return *this;
}

void Str::append(const_iterator b, const_iterator e) {
    size_type new_length = length + (e - b);
    iterator new_chars = alloc.allocate(new_length);
    uninitialized_copy(chars, chars + length - 1, new_chars);
    uninitialized_copy(b, e, new_chars + length - 1);
    alloc.construct(new_chars + new_length - 1, '\0');

    uncreate();

    length = new_length;
    chars = new_chars;
}

void Str::append(const char* str, const size_type s) {
    size_type new_length = length + s;
    iterator new_chars = alloc.allocate(new_length);
    uninitialized_copy(chars, chars + length - 1, new_chars);
    uninitialized_copy(str, str + s, new_chars + length - 1);
    alloc.construct(new_chars + new_length - 1, '\0');

    uncreate();

    length = new_length;
    chars = new_chars;
}

void Str::append(const char c) {
    append(&c, 1);
}

// Ex 12-9: output operator
std::ostream& operator<<(std::ostream&, const Str&);
std::ostream& operator<<(std::ostream& os, const Str& s) {
    for (Str::size_type i = 0; i != s.size(); ++i) {
        os << s[i];
    }
    return os;
}

std::ostream_iterator<char>& operator <<(std::ostream_iterator<char>& osi, const Str& s) {
    copy(s.begin(), s.end(), osi);
    return osi;
}

// Input operator
std::istream& operator>>(std::istream& is, Str& s) {
    // obliterate existing value(s)
    s.uncreate();
    s.create(0, '\0');
    // read and discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ;       // nothig to do, except testing the condition
    // if still something to read, do so until next whitespace character
    if (is) {
        do s.append(c);
        while (is.get(c) && !isspace(c));
        // if we read whitespace, then put it back on the stream
        if (is)
            is.unget();
    }
    return is;
}

// Ex 12-8
std::istream& getline(std::istream& is, Str& s) {
    // obliterate existing value(s)
    s.uncreate();
    s.create(0, '\0');
    // read and discard leading whitespace
    char c;
    
    if (is) {
        while (is.get(c) && c != '\n')
            s.append(c);
    }
    return is;
}

// 
Str operator+(const Str&, const Str&);
Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

Str operator+(const char*, const Str&);
Str operator+(const char* s, const Str& t) {
    Str r(s, s + strlen(s));
    r += t;
    return r;
}

Str operator+(const Str&, const char*);
Str operator+(const Str& s, const char* t) {
    Str r = s;
    r += Str(t, t + strlen(t));
    return r;
}

Str::size_type Str::copy(iterator s, size_type len, size_type pos) const {
    if (pos > size()) throw out_of_range("pos > size()");
    size_type copy_length = std::min(len, size() - pos);
    std::copy(chars + pos, chars + pos + copy_length, s);
    return copy_length;
}

Str Str::substr(size_type i, size_type j) const {
    return Str(chars + i, chars + i + j);
}

template<class In>
void Str::insert(iterator p, In i, In j) {
    size_type new_length = length + (j - i);
    iterator new_chars = alloc.allocate(new_length);
    uninitialized_copy(chars, p, new_chars);
    uninitialized_copy(i, j, new_chars + (p - chars));
    uninitialized_copy(p, chars + length - 1, new_chars + (p - chars) + (j - i));
    alloc.construct(new_chars + new_length - 1, '\0');

    uncreate();
    
    length = new_length;
    chars = new_chars;
}

inline bool operator==(const Str& lhs, const Str& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

inline bool operator!=(const Str& lhs, const Str& rhs) {
  return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

inline bool operator<(const Str& lhs, const Str& rhs){
  return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

inline bool operator<=(const Str& lhs, const Str& rhs) {
  return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

inline bool operator>(const Str& lhs, const Str& rhs) {
  return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

inline bool operator>=(const Str& lhs, const Str& rhs) {
  return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}