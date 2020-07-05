#pragma once

#include "Core.h"
#include "Grad.h"

class Student_info {
public:
    Student_info(): cp(0) {
        std::cout << "\tStudent_info::Student_info()" << std::endl;
    }
    Student_info(std::istream& is): cp(0) {
        std::cout << "\tStudent_info::Student_info(istream&)" << std::endl;
        read(is);
    }
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info() {
        std::cout << "\tStudent_info::~Student_info()" << std::endl;
        delete cp;
    }

    // oprations
    std::istream& read(std::istream&);

    std::string name() const { 
        if (cp) return cp->name();
        else throw std::runtime_error("uninitialized Student");
    }

    double grade() const {
        if (cp) return cp->grade();
        else throw std::runtime_error("uninitialized Student");
    }

    static bool compare(const Student_info& s1,
                        const Student_info& s2) {
        return s1.name() < s2.name();
    }
private:
    Core* cp;
};

// Copy Constructor
Student_info::Student_info(const Student_info& s): cp(0) {
    if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s) {
    if (&s != this) { // guard against self-assignment
        delete cp;
        if (s.cp) 
            cp = s.cp->clone();
        else 
            cp = 0;
    }
    return *this;
}

std::istream& Student_info::read(std::istream& is) {
    std::cout << "\t -Student_info::read(istream&)" << std::endl;
    delete cp;          // delete previous object, if any

    char ch;
    is >> ch;           // get record type

    if (ch == 'U') {
        cp = new Core(is);
    } else {
        cp = new Grad(is);
    }

    return is;
}