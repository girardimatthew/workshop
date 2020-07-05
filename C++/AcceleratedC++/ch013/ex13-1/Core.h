#include "grade.h"

class Core {
    friend class Student_info;
public:
    // default constructor
    Core(): midterm(0), final(0) {
        std::cerr << "\t>Core::Core()" << std::endl;
    }
    // build a Core from an istream
    Core(std::istream& is) { 
        std::cerr << "\t>Core::Core(istream&)" << std::endl;
        read(is);
    }
    virtual ~Core() {
        std::cerr << "\t>Core::~Core()" << std::endl;
    }

    std::string name() const;
    
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
protected:
    virtual Core* clone() const { 
        std::cerr << "\t  Core::clone()" << std::endl;
        return new Core(*this); 
    }
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
    std::cout << "\t    Core::read_common(istream&) ";
    in >> n >> midterm >> final;
    std::cout << n << ", " << midterm << ", " << final << endl;
    return in;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
    std::cout << "\t    Core::read_hw(istream&, vector& hw)" << std::endl;
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
    std::cout << "\t  Core::read(istream&)" << std::endl;
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