#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

void write_analysis(
    std::ostream& out, 
    const std::string& name, 
    double analysis(const std::vector<Student_info>&), 
    const std::vector<Student_info>& did, 
    const std::vector<Student_info>& didnt);

double optimistic_median_analysis(const std::vector<Student_info>& students);
double optimistic_median(const Student_info& s);
double average_analysis(const std::vector<Student_info>& students);
double median_analysis(const std::vector<Student_info>& students);
bool did_all_hw(const Student_info& s);
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif