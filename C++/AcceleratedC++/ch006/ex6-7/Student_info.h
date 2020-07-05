#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

void write_analysis(
    std::ostream& out, 
    const std::string& name, 
    double analysis_function(const Student_info& s), 
    const std::vector<Student_info>& did, 
    const std::vector<Student_info>& didnt);

double perform_analysis(double analysis_function(const Student_info& s), 
                        const std::vector<Student_info>& students);
double optimistic_median(const Student_info& s);
bool did_all_hw(const Student_info& s);
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read(std::istream&, std::vector<Student_info>&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif