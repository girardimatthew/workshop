#pragma once

#include <iostream>
#include <string>

static const double minimum_score = 60.0;

class Student_info {
public:
    Student_info();
    Student_info(double, double, std::string);
    Student_info(std::istream&);

    std::string name() { return n; }
    std::istream& read(std::istream&);
    double grade() const;
    std::string pass_or_fail() const;

    operator double() const;

private:
    std::string n;
    double midterm, final, final_grade;
    bool pass;
};

bool compare(Student_info&, Student_info&);
