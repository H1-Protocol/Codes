#include <iostream>
using namespace std;

class Circle {
	public:
	static const double PI;  // Declaration of constant static variable
	//static const int PI = 3;  // Definition and initialization Allowed (Integral type: int, char, bool)
	//static const double PI = 3.14159;  // Not allowed for non-integral types (double, float, string)
	static void showPI() {
        cout << "Value of PI: " << PI << endl;
    }
};
const double Circle::PI = 3.14159; // Allowed for all types

int main() {
    Circle::showPI();
    return 0;
}



/*
In pre-C++11, only static const integral types could be initialized inside the class.
Integral constant static members can be treated as compile-time constants.
Non-integral types (like double, float, string) were not considered compile-time constants, so they required a separate definition outside the class.

The reason was the integral types could be used in array sizes, template parameters and constant expressions
Example:
class A {
    static const int SIZE = 10;  // compile-time constant
};
int arr[A::SIZE];  // allowed

The compiler needs SIZE at compile time, and integral constants could provide that.
But double values were not allowed in such constant expressions in old C++ rules.
*/