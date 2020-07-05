// This following example program demonstrates the use of exceptions:

#include <string>      // for string
#include <stdexcept>   // for exception, runtime_error, out_of_range
#include <iostream>    // for cout


int main ()
{
    // First we'll incite and catch an exception from the C++ Standard
    // library class std::string by attempting to replace a substring
    // starting at a position beyond the end of the string object.
    try {
        std::string ().replace (100, 1, 1, 'c');
    }
    catch (std::out_of_range &e) {

        // Print out the exception string, which in this implementation
        // includes the location and the name of the function that threw
        // the exception along with the reason for the exception.
        std::cout << "Caught an out_of_range exception: "
                  << e.what () << '\n';
    }
    catch (std::exception &e) {

        std::cout << "Caught an exception of an unexpected type: "
                  << e.what () << '\n';
    }
    catch (...) {
        std::cout << "Caught an unknown exception\n";
    }
    
    // Throw another exception.
    try {
        throw std::runtime_error ("a runtime error");
    }
    catch (std::runtime_error &e) {
        std::cout << "Caught a runtime_error exception: "
                  << e.what () << '\n';
    }
    catch (std::exception &e) {
        std::cout << "Caught an exception of an unexpected type: "
                  << e.what () << '\n';
    } 
    catch (...) {
        std::cout << "Caught an unknown exception\n";
    }
   
    return 0;
}