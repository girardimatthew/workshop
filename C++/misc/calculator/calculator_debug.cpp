// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 6.9
// Program structure
// *********************************************************************************

#include <iostream>
#include <vector>
#include "../std_lib_facilities_v2.h"

using namespace std;

const char print = ';';
const char quit  = 'x';
const string result = "= ";
const string prompt = "> ";

//------------------------------------------------------------------------------

class Token {
public:
	char kind;							// what kind of token
	double value;						// for numbers: a value
	Token(char ch)						// make a Token from a char
		:kind(ch), value(0) {}
	Token(char ch, double val) 			// make a Token from a char and a double
		:kind(ch), value(val) {}
};

//------------------------------------------------------------------------------

class Token_stream {
public:									// user interface
	Token_stream();						// make a Token_stream that reads from cin
	Token get();						// get a Token 
	void putback(Token t);				// put a Token back
private:								// implementation details
	bool full;							// is there a Token in the buffer?
	Token buffer;						// here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

Token_stream::Token_stream()			// Token_stream's constructor
	:full(false), buffer(0)				// no Token in buffer
{
}

//------------------------------------------------------------------------------

void Token_stream::putback(Token t) {
	if (full) error("putback() into a full buffer");	// test
	buffer = t;											// copy t to buffer
	full = true;										// buffer is now full
	cout << "\tputback called: " << t.kind << ", " << t.value << ", " << full << endl;
}

//------------------------------------------------------------------------------

Token Token_stream::get() {
	if (full) {			// do we already have a Token ready?
		// remove Token from buffer
		full = false;
		cout << "\tget() called, in test: " << buffer.kind << ", " << buffer.value << ", " << full << endl;
		return buffer;
	}

	char ch;
	cout << "\t01get() called - ch: " << ch << endl;
	cin >> ch;					// not that >> skips whitespace (space, newline, tab, etc.)
	cout << "\t02get() called - ch: " << ch << endl;

	double val;
	switch (ch) {
		case ';':				// for print
		case 'x':				// for quit
		case '(': case ')': case '+': case '-': case '*': case '/': case '%':
		case '{': case '}': case '!':
			return Token(ch);			// let each character represent itself
		case '.':
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9': {
			cin.putback(ch);			// put digit back into the input stream
			double val;
			cin >> val;					// read a floating-point number
			cout << "\tin case .-9 : " << val << endl;
			return Token('8',val);		// let '8' represent "a number"
		}
		default:
			error("Bad token");
	}
}

//------------------------------------------------------------------------------

Token_stream ts; 					// provides get() and putback()

//------------------------------------------------------------------------------

double expression(); 				// declaration so that primary() can call expression()

//------------------------------------------------------------------------------
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

double primary() {					// read and evaluate a Primary
	cout << "\t01primary called()" << endl;
	Token t = ts.get();
	double d;
	cout << "\t02primary called() t: " << t.kind << ", " << t.value << endl;
	switch (t.kind) { 			// handle '(' expression ')'
		case '(': {
			d=expression();
			t=ts.get();
			if (t.kind!=')') error("')' expected");
			break;
		}
		case '{': {
			d = expression();
			t = ts.get();
			if (t.kind!='}') error("'}' expected");
			break;
		}
		case '8': {				// we use '8' to represent a number
			d = t.value;
			break;		// return the number's value
		}
		default:
			error("primary expected");
	}

	t = ts.get();
	if (t.kind != '!') {
		ts.putback(t);
		return d;
	}

	return fact(d);
}

//------------------------------------------------------------------------------

double term() {
	cout << "\t01term() called" << endl;
	double left = primary();
	cout << "\t02in term() - left: " << left << endl;
	Token t = ts.get();			// get the next Token from the Token stream
	cout << "\t03in term() - t: " << t.kind << ", " << t.value << endl;
	while (true) {
		switch (t.kind) {
			case '*':
				left*=primary();
				t=ts.get();
				break;
			case '/': {
				double d = primary();
				if (d==0) error("divide by zero");
				left/=d;
				t=ts.get();
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
				ts.putback(t);		// put t back into the Token stream
				return left;
		}
	}
}

//------------------------------------------------------------------------------

double expression() {
	cout << "\t01expression() called" << endl;
	double left = term();			// read and evaluate a Term
	cout << "\t02in expression() - left: " << left << endl;
	Token t = ts.get();				// get the next Token from the Token stream
	while (true) {
		switch (t.kind) {
			case '+':
				left+=term();		// evaluate Term and add
				t=ts.get();
				break;
			case '-':
				left-=term();		// evaluate Term and substract
				t=ts.get();
				break;
			default:
				ts.putback(t);		// put t back into the token stream
				return left;		// finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

// expression evaluation loop
void calculate () {
    while (cin) {
        // cout << prompt;
        cout << "\t01in calculate.\n";
        Token t = ts.get();
        cout << "\t02in calculate(): " << t.kind << ", " << t.value << endl;
        while (t.kind == print) {
        	cout << "\t03in calculate(): " << t.kind << ", " << t.value << endl;
        	t = ts.get();
        	cout << "\t04in calculate(): " << t.kind << ", " << t.value << endl;
        }
        if (t.kind == quit) {
        	cout << "\t05in calculate(): " << t.kind << ", " << t.value << endl;
        	return;
        }
        ts.putback(t);
        cout << "\t06in calculate().\n";
        cout << result << expression() << endl;
    }
}

int main() {
    try {
        double val = 0;
        cout << "Welcome to our simple calculator.\n";
        cout << "Please enter expressions using floating-point numbers.\n";
        cout << "Valid operators: +, -, *, /, \%, !, (), {}.\n";
        cout << "Enter " << quit << " to quit; Enter " << print << " to print the result.\n";
        // while (cin) {
        //     Token t = ts.get();
        //     cout << "\t01in main: " << t.kind << ", " << t.value << endl; 
        //     if (t.kind == quit) 
        //         break;      // 'x' for quit
        //     if (t.kind == print)            // ';' for "print now"
        //         cout << result << val << '\n';
        //     else {
        //         ts.putback(t);
        //         cout << "\tin main putback called.\n";
        //     }
        //     cout << "\tin main expression called.\n";
        //     val = expression();
        //     cout << "\tin main val: " << val << endl;
        // }
        calculate();
        keep_window_open();
        return 0;
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