// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 06 Ex 03
// *********************************************************************************
// Add a factorial operator: use a suffix ! operator to represent "factorial".
// For example, the expresion 7! means 7*6*5*4*3*2*1. Make ! bind tighter 
// than * and /; that is, 7*8! means 7*(8!) rather than (7*8)!. 
// Begin by modifying the grammar to account for a higher-level operator. 
// To agree with the standard mathematical definition of factorial, let 0! evaluate to 1.
// *********************************************************************************

#include "../std_lib_facilities_v2.h"

const char print = ';';
const char quit  = 'x';
const string result = "= ";
const string prompt = "> ";

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t) {
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get() {
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        case ';':    // for "print"
        case 'x':    // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/': case '%': 
        case '{': case '}': case '!':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9': {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
        default:
            error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------
// factorial function
double fact(double n) {
    int f=1;
    int q = n;
    if ((double)q!=n) {
        error("factorial not defined for non-integers");
    }
    if (n<0) {
        error("factorial not defined for negative values");
    }
    else if (n==0) {
        return 1;
    }
    else {
        for (int i=1; i<=n; i++) {
            f=f*i;
        }
        return f;
    }
}

//------------------------------------------------------------------------------

// deal with numbers, parentheses and factorial
double primary()
{
    Token t = ts.get();
    double d = 0;
    switch (t.kind) {
        case '(': {   // handle '(' expression ')'
            d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            break;
        }
        case '{': {         // handle '{' expression '}'
            d = expression();
            t = ts.get();
            if (t.kind!='}') error("'}' expected");
            break;
        }
        case '8': {         // we use '8' to represent a number
            d = t.value;    // return the number's value
            break;
        }
        default:
            error("primary expected");
    }

    // check if we have the case Primary "!" (a factorial)
    t = ts.get();
    if (t.kind!='!') {      // not a factorial: put token back, return value from above
        ts.putback(t);
        return d;
    }

    return fact(d);         // a factorial; call factorial function

}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/': {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
            case '%': {
                double d = primary();
                int i1 = (int)left;
                if (i1 != left)
                    error("left-hand operand of \% is not an integer.");
                int i2 = (int)d;
                if (i2 != d)
                    error("right-hand operand of \% is not an integer.");
                if (i2 == 0)
                    error("\%: divide by zero.");
                left = i1 % i2;
                t = ts.get();
                break;
            }
            default: 
                ts.putback(t);     // put t back into the token stream
                return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression() {
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main() {
    try {
        double val = 0;
        cout << "Welcome to our simple calculator.\n";
        cout << "Please enter expressions using floating-point numbers.\n";
        cout << "Valid operators: +, -, *, /, \%, !, (), {}.\n";
        cout << "Enter " << quit << " to quit; Enter " << print << " to print the result.\n";
        while (cin) {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
                break;
            ts.putback(t);
            cout << result << expression() << endl;
        }
        keep_window_open();
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << '\n'; 
        keep_window_open("~1");
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n"; 
        keep_window_open("~2");
        return 2;
    }
}

//------------------------------------------------------------------------------