class Grad: public Core { 
public:
    // both constructors implicitly use Core::Core() to initialize the base part
    Grad(): thesis(0) { }
    Grad(std::istream& is) { read(is); }
    
    // virtual by inheritance
    std::istream& read(std::istream&);
    double grade() const;
    void regrade(double d, double t) { final = d; thesis = t; }
protected:
    Grad* clone() const { return new Grad(*this); }
private:
    double thesis;
};

std::istream& Grad::read(std::istream& in) {
    // std::cout << "Grad::read" << std::endl;
    //Core::read_common(in);
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}

double Grad::grade() const { 
    // scopre operator is essential here.
    return std::min(Core::grade(), thesis);
}