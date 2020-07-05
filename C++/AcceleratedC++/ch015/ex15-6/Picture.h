#include <vector>
#include <string>
#include "Ptr.h"
#include "Vec.h"
#include "Str.h"

// Forward declaration
class Picture;

class Pic_base {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
    friend class String_Pic;
    friend class Picture;           // 15.2.7 Don't forget friends!

    // no public interface (except for the destructor)
    typedef Vec<Str>::size_type ht_sz;
    typedef Str::size_type wd_sz;

    // this class is an abstract base class
    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;
    virtual void reframe(char, char, char) = 0;
public:
    virtual ~Pic_base() { }
protected:
    static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
        while (beg != end) {
            os << " ";
            ++beg;
        }
    }
};

// ==================================================================================

class String_Pic: public Pic_base { 
    friend class Picture;
    Vec<Str> data;
    String_Pic(const Vec<Str>& v): data(v) { }

    ht_sz height() const { return data.size(); }
    wd_sz width() const;
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(char c, char tb, char s) { }
};

Pic_base::wd_sz String_Pic::width() const {
    Pic_base::wd_sz n = 0;
    for (Pic_base::ht_sz i = 0; i != data.size(); ++i) {
        n = std::max(n, data[i].size());
    }
    return n;
}

void String_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
    wd_sz start = 0;
    // write the row if we're still in range
    if (row < height()) {
        os << data[row];
        start = data[row].size();
    }
    // pad the output if necessary
    if (do_pad)
        pad(os, start, width());
}

// ==================================================================================

class Frame_Pic: public Pic_base {
    friend Picture frame(const Picture&, char, char, char);

    Ptr<Pic_base> p;
    char corner;
    char top_bottom;
    char side;
    Frame_Pic(const Ptr<Pic_base>& pic, char c, char tb, char s): 
        p(pic), corner(c), top_bottom(tb), side(s) { }

    wd_sz width() const { return p->width() + 4; }
    ht_sz height() const { return p->height() + 4; }
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(char c, char tb, char s);
};

void Frame_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
    if (row >= height()) {
        // out of range
        if (do_pad)
            pad(os, 0, width());
    } else {
        if (row == 0 || row == height() - 1) {
            // top or bottom row
            os << corner;
            os << Str(width() - 2, top_bottom);
            os << corner;
        } else if (row == 1 || row == height() - 2) {
            // second from top or bottom row
            os << side;
            pad(os, 1, width() - 1);
            os << side;
        } else {
            // interior row
            os << side << " ";
            p->display(os, row - 2, true);
            os << " " << side;
        }
    }
}

void Frame_Pic::reframe(char c, char tb, char s) {
    p->reframe(c, tb, s);
    
    corner = c;
    top_bottom = tb;
    side = s;
}

// ==================================================================================

class VCat_Pic: public Pic_base {
    friend Picture vcat(const Picture&, const Picture&);

    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t), bottom(b) { }

    wd_sz width() const { return std::max(top->width(), bottom->width()); }
    ht_sz height() const { return top->height() + bottom->height(); }
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(char c, char tb, char s);
};

void VCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
    wd_sz w = 0;
    if (row < top->height()) {
        // we are in the top subpicture
        top->display(os, row, do_pad);
        w = top->width();
    } else if (row < height()) {
        // we are in the bottom subpicture
        bottom->display(os, row - top->height(), do_pad);
        w = bottom->width();
    }
    if (do_pad)
        pad(os, w, width());
}

void VCat_Pic::reframe(char c, char tb, char s) {
    top->reframe(c, tb, s);
    bottom->reframe(c, tb, s);
}

// ==================================================================================

class HCat_Pic: public Pic_base {
    friend Picture hcat(const Picture&, const Picture&);
    Ptr<Pic_base> left, right;
    HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r): left(l), right(r) { }

    wd_sz width() const { return left->width() + right->width(); }
    ht_sz height() const { return std::max(left->height(), right->height()); }
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(char c, char tb, char s);
};

void HCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
    ht_sz left_row = row, right_row = row;

    if (left->height() > right->height()) {
        ht_sz v_pad = (left->height() - right->height()) / 2;
        right_row = (row < v_pad) ? right->height() : row - v_pad;
    } else {
        ht_sz v_pad = (right->height() - left->height()) / 2;
        left_row = (row < v_pad) ? left->height() : row - v_pad;
    }

    left->display(os, left_row, do_pad || right_row < right->height());
    right->display(os, right_row, do_pad);
}

void HCat_Pic::reframe(char c, char tb, char s) {
    left->reframe(c, tb, s);
    right->reframe(c, tb, s);
}

// ==================================================================================

class Picture { 
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend Picture frame(const Picture&, char, char, char);
    friend Picture hcat(const Picture&, const Picture&);
    friend Picture vcat(const Picture&, const Picture&);
public:
    Picture(const Vec<Str>& = Vec<Str>());
    void reframe(char c, char tb, char s) { p->reframe(c, tb, s); }
private:
    Picture(Pic_base* ptr): p(ptr) { }
    Ptr<Pic_base> p;
};

Picture::Picture(const Vec<Str>& v): p(new String_Pic(v)) { }

Picture frame(const Picture& pic, 
              char corner = '*', 
              char top_bottom = '-', 
              char side = '|') {
    return new Frame_Pic(pic.p, corner, top_bottom, side);
}

Picture hcat(const Picture& l, const Picture& r) {
    return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b) {
    return new VCat_Pic(t.p, b.p);
}

std::ostream& operator<<(std::ostream& os, const Picture& picture) {
    const Pic_base::ht_sz ht = picture.p->height();
    for (Pic_base::ht_sz i = 0; i != ht; ++i) {
        picture.p->display(os, i, false);
        os << std::endl;
    }
    return os;
}

// // Forward declaration
// class Picture;

// class Pic_base {
//     friend std::ostream& operator<<(std::ostream&, const Picture&);
//     friend class Frame_Pic;
//     friend class HCat_Pic;
//     friend class VCat_Pic;
//     friend class String_Pic;
//     friend class Picture;           // 15.2.7 Don't forget friends!

//     // no public interface (except for the destructor)
//     typedef std::vector<std::string>::size_type ht_sz;
//     typedef std::string::size_type wd_sz;

//     // this class is an abstract base class
//     virtual wd_sz width() const = 0;
//     virtual ht_sz height() const = 0;
//     virtual void display(std::ostream&, ht_sz, bool) const = 0;
//     virtual void reframe(char, char, char) = 0;
// public:
//     virtual ~Pic_base() { }
// protected:
//     static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
//         while (beg != end) {
//             os << " ";
//             ++beg;
//         }
//     }
// };

// // ==================================================================================

// class String_Pic: public Pic_base { 
//     friend class Picture;
//     std::vector<std::string> data;
//     String_Pic(const std::vector<std::string>& v): data(v) { }

//     ht_sz height() const { return data.size(); }
//     wd_sz width() const;
//     void display(std::ostream&, ht_sz, bool) const;
//     void reframe(char c, char tb, char s) { }
// };

// Pic_base::wd_sz String_Pic::width() const {
//     Pic_base::wd_sz n = 0;
//     for (Pic_base::ht_sz i = 0; i != data.size(); ++i) {
//         n = std::max(n, data[i].size());
//     }
//     return n;
// }

// void String_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
//     wd_sz start = 0;
//     // write the row if we're still in range
//     if (row < height()) {
//         os << data[row];
//         start = data[row].size();
//     }
//     // pad the output if necessary
//     if (do_pad)
//         pad(os, start, width());
// }

// // ==================================================================================

// class Frame_Pic: public Pic_base {
//     friend Picture frame(const Picture&, char, char, char);

//     Ptr<Pic_base> p;
//     char corner;
//     char top_bottom;
//     char side;
//     Frame_Pic(const Ptr<Pic_base>& pic, char c, char tb, char s): 
//         p(pic), corner(c), top_bottom(tb), side(s) { }

//     wd_sz width() const { return p->width() + 4; }
//     ht_sz height() const { return p->height() + 4; }
//     void display(std::ostream&, ht_sz, bool) const;
//     void reframe(char c, char tb, char s);
// };

// void Frame_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
//     if (row >= height()) {
//         // out of range
//         if (do_pad)
//             pad(os, 0, width());
//     } else {
//         if (row == 0 || row == height() - 1) {
//             // top or bottom row
//             os << corner;
//             os << std::string(width() - 2, top_bottom);
//             os << corner;
//         } else if (row == 1 || row == height() - 2) {
//             // second from top or bottom row
//             os << side;
//             pad(os, 1, width() - 1);
//             os << side;
//         } else {
//             // interior row
//             os << side << " ";
//             p->display(os, row - 2, true);
//             os << " " << side;
//         }
//     }
// }

// void Frame_Pic::reframe(char c, char tb, char s) {
//     p->reframe(c, tb, s);
    
//     corner = c;
//     top_bottom = tb;
//     side = s;
// }

// // ==================================================================================

// class VCat_Pic: public Pic_base {
//     friend Picture vcat(const Picture&, const Picture&);

//     Ptr<Pic_base> top, bottom;
//     VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t), bottom(b) { }

//     wd_sz width() const { return std::max(top->width(), bottom->width()); }
//     ht_sz height() const { return top->height() + bottom->height(); }
//     void display(std::ostream&, ht_sz, bool) const;
//     void reframe(char c, char tb, char s);
// };

// void VCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
//     wd_sz w = 0;
//     if (row < top->height()) {
//         // we are in the top subpicture
//         top->display(os, row, do_pad);
//         w = top->width();
//     } else if (row < height()) {
//         // we are in the bottom subpicture
//         bottom->display(os, row - top->height(), do_pad);
//         w = bottom->width();
//     }
//     if (do_pad)
//         pad(os, w, width());
// }

// void VCat_Pic::reframe(char c, char tb, char s) {
//     top->reframe(c, tb, s);
//     bottom->reframe(c, tb, s);
// }

// // ==================================================================================

// class HCat_Pic: public Pic_base {
//     friend Picture hcat(const Picture&, const Picture&);
//     Ptr<Pic_base> left, right;
//     HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r): left(l), right(r) { }

//     wd_sz width() const { return left->width() + right->width(); }
//     ht_sz height() const { return std::max(left->height(), right->height()); }
//     void display(std::ostream&, ht_sz, bool) const;
//     void reframe(char c, char tb, char s);
// };

// void HCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
//     ht_sz left_row = row, right_row = row;

//     if (left->height() > right->height()) {
//         ht_sz v_pad = (left->height() - right->height()) / 2;
//         right_row = (row < v_pad) ? right->height() : row - v_pad;
//     } else {
//         ht_sz v_pad = (right->height() - left->height()) / 2;
//         left_row = (row < v_pad) ? left->height() : row - v_pad;
//     }

//     left->display(os, left_row, do_pad || right_row < right->height());
//     right->display(os, right_row, do_pad);
// }

// void HCat_Pic::reframe(char c, char tb, char s) {
//     left->reframe(c, tb, s);
//     right->reframe(c, tb, s);
// }

// // ==================================================================================

// class Picture { 
//     friend std::ostream& operator<<(std::ostream&, const Picture&);
//     friend Picture frame(const Picture&, char, char, char);
//     friend Picture hcat(const Picture&, const Picture&);
//     friend Picture vcat(const Picture&, const Picture&);
// public:
//     Picture(const std::vector<std::string>& = std::vector<std::string>());
//     void reframe(char c, char tb, char s) { p->reframe(c, tb, s); }
// private:
//     Picture(Pic_base* ptr): p(ptr) { }
//     Ptr<Pic_base> p;
// };

// Picture::Picture(const std::vector<std::string>& v): p(new String_Pic(v)) { }

// Picture frame(const Picture& pic, 
//               char corner = '*', 
//               char top_bottom = '-', 
//               char side = '|') {
//     return new Frame_Pic(pic.p, corner, top_bottom, side);
// }

// Picture hcat(const Picture& l, const Picture& r) {
//     return new HCat_Pic(l.p, r.p);
// }

// Picture vcat(const Picture& t, const Picture& b) {
//     return new VCat_Pic(t.p, b.p);
// }

// std::ostream& operator<<(std::ostream& os, const Picture& picture) {
//     const Pic_base::ht_sz ht = picture.p->height();
//     for (Pic_base::ht_sz i = 0; i != ht; ++i) {
//         picture.p->display(os, i, false);
//         os << std::endl;
//     }
//     return os;
// }