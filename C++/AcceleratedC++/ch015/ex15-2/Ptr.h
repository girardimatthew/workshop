// Ptr class should be split into two
template <class T>
T* clone(const T* tp) { 
    return tp->clone();
}

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
            p = p ? clone(p) : 0;
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