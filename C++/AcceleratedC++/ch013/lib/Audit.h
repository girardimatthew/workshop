class Audit: public Core { 
public:
    // both constructors implicitly use Core::Core() to initialize the base part
    Audit() { }
    Audit(std::istream& is) { read(is); }
    
    // virtual by inheritance
    std::istream& read(std::istream& in);
    double grade() const { return 0.0; }
    std::string grade_letter() const { return "A"; }
    bool valid() const { return true; }
    bool fulfill_requirements() const { return true; }
protected:
    Audit* clone() const { return new Audit(*this); }
private:  
};

std::istream& Audit::read(std::istream& in) {
    in >> n;
    return in;
}