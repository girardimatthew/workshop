#pragma once

#include <string>

class String_list {
private:
    std::string *list;
    std::string::size_type size;
    std::string::size_type max;

    void resize();
    
public:
    typedef std::string* iterator;
    String_list();
    ~String_list();

    void push_back(std::string);
    std::string* begin() { return list; }
    std::string* end() { return list + size; };

};