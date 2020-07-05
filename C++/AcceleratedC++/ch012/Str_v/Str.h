#pragma once

#include "../Vec/Vec.h"

class Str {  
    friend std::istream& operator>>(std::istream&, Str&);

public:
    typedef Vec<char>::size_type size_type;
    typedef Vec<char>::iterator iterator;
    typedef Vec<char>::const_iterator const_iterator;
    // default constructor; create an empty Str
    Str() { }
    // create a Str containing n copies of c
    Str(size_type n , char c): data(n, c) { }
    // create a Str from a null-terminated array of char
    // act as a user-defined conversion
    Str(const char* cp) { 
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }
    // create a Str from the range denoted by iterators b and e
    template <class In> Str(In b, In e): data(b, e) { }
    //
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
    //
    size_type size() const { return data.size(); }
    //
    Str& operator+=(const Str& s) {
        std::copy(
            s.data.begin(), 
            s.data.end(), 
            std::back_inserter(data)
        );
        return *this;
    }
    //
    template <class In>
    void insert(iterator p, In i, In j) {
        data.insert(p, i, j);
    }

    iterator begin() { return data.begin(); }
    const_iterator begin() const { return data.begin(); }
    iterator end() { return data.end(); }
    const_iterator end() const { return data.end(); }

    //
    operator bool() const { return size() > 0; }
    
    //
    //const char* c_str() const { return data; }
    //const char* data() const { return data.begin(); }

private:
    Vec<char> data;
};

std::ostream& operator<<(std::ostream&, const Str&);
std::ostream& operator<<(std::ostream& os, const Str& s) {
    for (Str::size_type i = 0; i != s.size(); ++i) {
        os << s[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, Str& s) {
    // obliterate existing value(s)
    s.data.clear();
    // read and discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ;       // nothig to do, except testing the condition
    // if still something to read, do so until next whitespace character
    if (is) {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));
        // if we read whitespace, then put it back on the stream
        if (is)
            is.unget();
    }
    return is;
}

Str operator+(const Str&, const Str&);
Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

Str operator+(const Str&, const char*);
Str operator+(const Str& s, const char* t) {
    Str r = s;
    r += Str(t, t + strlen(t));
    return r;
}

Str operator+(const char*, const Str&);
Str operator+(const char* s, const Str& t) {
    Str r(s, s + strlen(s));
    r += t;
    return r;
}

inline bool operator==(const Str& lhs, const Str& rhs) {
    return strcmp(lhs.begin(), rhs.begin()) == 0;
}