#pragma once

#include "Core.h"
#include "Grad.h"
#include "Credit.h"
#include "Audit.h"

class Student_info {
public:
    Student_info(): cp(0) { }
    Student_info(std::istream& is): cp(0) { read(is); }
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info() { delete cp; }

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

    std::string letter() const {
        if (cp) return cp->grade_letter();
        else throw std::runtime_error("uninitialized Student");
    }

    bool valid() const {
        if (cp) return cp->valid();
        else throw std::runtime_error("uninitialized Student");
    }

    bool fulfill_requirements() const {
        if (cp) return cp->fulfill_requirements();
        else throw std::runtime_error("uninitialized Student");
    }

    static bool compare(const Student_info& s1,
                        const Student_info& s2) {
        return s1.name() < s2.name();
    }

    static bool compare_grade(const Student_info& s1,
                              const Student_info& s2) {
        return s1.grade() > s2.grade();
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
    delete cp;          // delete previous object, if any

    char ch;
    is >> ch;           // get record type
    
    std:: cout << ch << std::endl;

    if (ch == 'U') { cp = new Core(is); }
    else if (ch == 'G') { cp = new Grad(is); }
    else if (ch == 'A') { cp = new Audit(is); }
    else { cp = new Credit(is); }

    // if (ch == 'U') { cp = new Core(is); }
    // else { cp = new Grad(is); }
    
    return is;
}