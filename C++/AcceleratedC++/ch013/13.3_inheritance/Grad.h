class Grad: public Core { 
public:
    // both constructors implicitly use Core::Core() to initialize the base part
    Grad(): thesis(0) { }
    Grad(std::istream& is) { read(is); }
    
    // virtual by inheritance
    std::istream& read(std::istream&);
    double grade() const;
private:
    double thesis;
};

std::istream& Grad::read(std::istream& in) {
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