#pragma once

#include "Core.h"
#include "Grad.h"

class Student_info {
public:
    Student_info() { }
    Student_info(std::istream& is) { read(is); }
    // no copy, assign, or destructor: they're no longer needed

    // oprations
    std::istream& read(std::istream&);

    std::string name() const { 
        if (cp) return cp->name();
        else throw std::runtime_error("uninitialized Student");
    }
    void setName(std::string name) {
        if (cp)
            cp->setName(name);
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
    Ref_handle<Core> cp;
};

std::istream& Student_info::read(std::istream& is) {

    char ch;
    is >> ch;           // get record type

    // allocate new object of the appropriate type
    // use Handle<T>(T*) to build a Handle<Core> from the pointer to that object
    // call Handle<T>::operator= to assign the Handle<Core> to the left-hand side
    if (ch == 'U') {
        std::cout << "\t> new Core(is)" << std::endl;
        cp = new Core(is);
    } else {
        std::cout << "\t> new Grad(is)" << std::endl;
        cp = new Grad(is);
    }

    return is;
}