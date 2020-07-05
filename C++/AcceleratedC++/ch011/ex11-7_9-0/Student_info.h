#pragma once

#include <iostream>
#include <string>
#include "Vec.h"

class Student_info {

private:
    std::string n;
    double midterm, final;
    Vec<double> homework;

public:
    Student_info();
    Student_info(std::istream&);

    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
    std::istream& read(std::istream&);
    double grade() const;
};

bool compare(const Student_info&, const Student_info&);