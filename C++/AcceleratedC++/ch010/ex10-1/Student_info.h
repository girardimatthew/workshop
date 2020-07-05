#pragma once

#include <iostream>
#include <string>
#include <vector>

class Student_info {

private:
    std::string n;
    double midterm, final, final_grade;
    bool pass;
    std::string lgrade; // letter_grade

public:
    Student_info();
    Student_info(std::istream&);

    std::string name() { return n; }
    std::istream& read(std::istream&);
    double grade() const;
    std::string pass_or_fail() const;
    std::string letter() const;
};

bool compare(Student_info&, Student_info&);
