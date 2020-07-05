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

    static int default_constructor_calls;
    static int custom_constructor_calls;
    static int stream_constructor_calls;
    static int copy_constructor_calls;
    static int assignment_calls;
    static int destructor_calls;

public:
    Student_info();
    Student_info(
        const std::string&, 
        const int&,
        const int&,
        const int&,
        const bool&
    );
    Student_info(std::istream&);
    Student_info(const Student_info&);

    Student_info& operator=(const Student_info&);
    ~Student_info();

    std::string name() { return n; }
    std::istream& read(std::istream&);
    double grade() const;
    std::string pass_or_fail() const;
    std::string letter() const;

    static void reset_class_info();
    static std::ostream& print_class_info(std::ostream&);
};

bool compare(Student_info&, Student_info&);
