#pragma once

#include <iostream>
#include <string>
#include <vector>

class Student_info {

private:
    std::string n;
    double midterm, final, final_grade;
    std::vector<double> homework;

public:
    Student_info();
    Student_info(std::istream&);

    std::string name() { return n; }
    bool valid() const { return !homework.empty(); }
    std::istream& read(std::istream&);
    double grade() const;
};

bool compare(Student_info&, Student_info&);
