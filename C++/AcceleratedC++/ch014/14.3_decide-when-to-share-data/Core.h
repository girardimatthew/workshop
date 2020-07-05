#include "grade.h"

template <class T>
class Ptr { 
public:
    // manage reference count aswell as pointer
    Ptr(): p(0), refptr(new std::size_t(1)) { }
    Ptr(T* t): p(t), refptr(new std::size_t(1)) { }
    Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr; }
    Ptr& operator=(const Ptr&);
    ~Ptr();

    operator bool() const { return p; }
    T& operator*() const { 
        if (p)
            return *p;
        throw std::runtime_error("unbound Ptr");
    }
    T* operator->() const {
        if (p)
            return p;
        throw std::runtime_error("unbound Ptr");
    }
    // copy the object conditionally when needed
    void make_unique() {
        if (*refptr != 1) {
            --*refptr;
            refptr = new size_t(1);
            p = p ? p->clone() : 0;
        }
    }
private:
    T* p;
    std::size_t* refptr;
};

template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs) {
    ++*rhs.refptr;
    // free the left-hande side, destroying pointers if appropriate
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
    // copy in values from the right-hand side
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template <class T>
Ptr<T>::~Ptr() {
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}




template <class T>
class Handle {
public:
    Handle(): p(0) { }
    Handle(const Handle& s): p(0) { if (s.p) p = s.p->clone(); }
    Handle& operator=(const Handle&);
    ~Handle() { delete p; }

    Handle(T* t): p(t) { }
    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
};

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs) {
    if (&rhs != this) {
        delete p;
        p = rhs.p ? rhs.p->clone() : 0;
    }
    return *this;
}

template <class T>
T& Handle<T>::operator*() const {
    if (p)
        return *p;
    throw std::runtime_error("unbound Handle");
}

template <class T>
T* Handle<T>::operator->() const { 
    if (p)
        return p;
    throw std::runtime_error("unbound Handle");
}






class Core {
    friend class Student_info;
    friend class Ptr<Core>;
public:
    // default constructor
    Core(): midterm(0), final(0) { }
    // build a Core from an istream
    Core(std::istream& is) { read(is); }
    virtual ~Core() { }

    std::string name() const;
    void rename(std::string new_name) { n = new_name; }
    
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    virtual void regrade(double d, double = 0) { final = d; }
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

bool compare_Core_Handles(const Handle<Core> hc1, const Handle<Core> hc2) {
    //return compare_grade(*hc1, *hc2);
    return compare(*hc1, *hc2);
}