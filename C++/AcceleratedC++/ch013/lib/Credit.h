class Credit: public Core { 
public:
    // both constructors implicitly use Core::Core() to initialize the base part
    Credit() { }
    Credit(std::istream& is) { Core::read(is); }
    
    // virtual by inheritance
    double grade() const;
    std::string grade_letter() const;
    bool valid() const { return true; }
    bool fulfill_requirements() const {
        return midterm > 0.0 || final > 0.0;
    }
protected:
    Credit* clone() const { return new Credit(*this); }
private:
    std::string pass_or_fail() const;
};

double Credit::grade() const { 
    if (homework.empty()) {
        return ::grade(midterm, final);
    } else {
        return Core::grade();
    }
}

std::string Credit::pass_or_fail() const {
    bool pass = grade() >= 60.0;
    return pass ? "P" : "F";
}

std::string Credit::grade_letter() const {
    return pass_or_fail();
}