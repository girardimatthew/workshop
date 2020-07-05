// using sizeof() funciton
#include <iostream>

using namespace std;

int main() {
	cout << "Size of bool : " << sizeof(bool) << endl;
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
    int scores[10];
    cout << "Size of 10 elements array : " << sizeof(scores) << endl;
    return 0;
}

// char					1byte			-128 to 127 or 0 to 255
// unsigned char		1byte			0 to 255
// signed char			1byte			-128 to 127
// int					4bytes			-2147483648 to 2147483647
// unsigned int			4bytes			0 to 4294967295
// signed int			4bytes			-2147483648 to 2147483647
// short int			2bytes			-32768 to 32767
// unsigned short int	2bytes			0 to 65,535
// signed short int		2bytes			-32768 to 32767
// long int				4bytes			-2,147,483,648 to 2,147,483,647
// signed long int		4bytes			-2,147,483,648 to 2,147,483,647
// unsigned long int	4bytes			0 to 4,294,967,295
// float				4bytes			+/- 3.4e +/- 38 (~7 digits)
// double				8bytes			+/- 1.7e +/- 308 (~15 digits)
// long double			8bytes			+/- 1.7e +/- 308 (~15 digits)
// wchar_t				2 or 4 bytes	1 wide character