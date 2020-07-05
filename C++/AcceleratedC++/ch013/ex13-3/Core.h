#include "grade.h"

class Core {
    friend class Student_info;
public:
    // default constructor
    Core(): midterm(0), final(0) { }
    // build a Core from an istream
    Core(std::istream& is) { read(is); }
    virtual ~Core() { }

    std::string name() const;
    
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    virtual bool valid() const { return !homework.empty(); }
protected:
    virtual Core* clone() const { return new Core(*this); }
    // accessible to derived classes
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
private:
    // accessible ONLY to Core
    std::string n;
};

string Core::name() const { return n; }

double Core::grade() const { 
    return ::grade(midterm, final, homework);
}

std::istream& Core::read_common(std::istream& in) {
    // read and store the student's name and exam grades
    in >> n >> midterm >> final;
    return in;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
    if (in) {
        // get rid of previous contents
        hw.clear();
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input
        // will work for the next student
        in.clear();
    }
    return in;
}

std::istream& Core::read(std::istream& in) { 
    // std::cout << "Core::read" << std::endl;
    read_common(in);
    read_hw(in, homework);
    return in;
}

bool compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}

bool compare_grade(const Core& c1, const Core& c2) {
    return c1.grade() < c2.grade();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2) {
    return compare(*cp1, *cp2);
}