class Grad: public Core { 
public:
    // both constructors implicitly use Core::Core() to initialize the base part
    Grad(): thesis(0) {
        std::cerr << "\t>Grad::Grad()" << std::endl;
    }
    Grad(std::istream& is) { 
        std::cerr << "\t>Grad::Grad(istream&)" << std::endl;
        read(is); 
    }
    ~Grad() {
        std::cerr << "\t>Grad::~Grad()" << std::endl;
    }
    
    // virtual by inheritance
    std::istream& read(std::istream&);
    double grade() const;
protected:
    Grad* clone() const { 
        std::cerr << "\t  Grad::clone()" << std::endl;
        return new Grad(*this); 
    }
private:
    double thesis;
};

std::istream& Grad::read(std::istream& in) {
    std::cout << "\t  Grad::read(istream&)" << std::endl;
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