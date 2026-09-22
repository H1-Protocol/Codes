#include<iostream>
using namespace std;

#define DEBUG
int main() 
{
    #ifdef DEBUG
        cout << "Debugging is enabled." << endl;
    #else
        cout << "Debugging is disabled." << endl;
    #endif
    return 0;
}

// 2. Conditional directives (like #ifdef) with the appropriate code, 
//    modifying the source code before passing to the compiler.

/*
if DEBUG is defined, the program will print "Debugging is enabled."
if DEBUG is not defined, it will print "Debugging is disabled."
In case debug is define, then the code between #ifdef DEBUG and #endif is included in the compilation.
like below
int main() 
{
    cout << "Debugging is enabled." << endl;
    return 0;
}
*/