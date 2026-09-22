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