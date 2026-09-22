#include<iostream>
using namespace std;
#define PI 3.14       // Define constant Value (A macro constant, replaces PI with 3.14)
#define Square(x) x*x // Defining Macro (A macro function, performs calculation using x)

int main() 
{
    cout<<"PI Value = "<<PI<<endl;
    cout<<"Square = "<<Square(5.5)<<endl;   // The preprocessor doesn’t perform any evaluation. 
                                            // Only performs text substitution. After preprocessing, 
                                            // the expression Square(5) becomes 5*5 not 25.       
    return 0;
}

// The preprocessor is a program that runs before the compiler
// The preprocessor performs substitution. 

// It processes the source code before compilation 
// 1. Replacing directives like #include (including files), #define (for macros), 
// 2. Conditional directives (like #ifdef) with the appropriate code, 
//    modifying the source code before passing to the compiler.


// There is a potential problem in the macro expands. 
// Without parentheses around x, can cause unintended results like
/*
#define Square(x) x*x
Square(2 + 3) will become 2 + 3 * 2 + 3 => 2 + 6 + 3 = 11  

use like below 
#define Square(x) ((x) * (x))
Square(2 + 3) will become ((2+3) * (2+3)) => (5 * 5) = 25
*/
