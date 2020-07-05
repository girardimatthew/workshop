#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::istream;

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
istream& read(istream& is, vector<Student_info>& v);
istream& read(istream& is, list<Student_info>& l);
istream& read(std::istream&, Student_info&);
istream& read_hw(istream&, vector<double>&);
#endif
