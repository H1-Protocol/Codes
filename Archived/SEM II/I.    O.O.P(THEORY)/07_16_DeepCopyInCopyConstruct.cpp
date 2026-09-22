#include <iostream>
using namespace std;

class MyClass {
public:
    int *ptr;

    MyClass() {
        ptr = new int;
        *ptr = 2000;
    }

    // Deep Copy Constructor
    MyClass(const MyClass &other) {
        ptr = new int;        // allocate new memory
        *ptr = *other.ptr;    // copy value
    }

    // Destructor
    ~MyClass() {
        delete ptr;
    }
};

int main() {

    MyClass obj1;
    cout << "---\n";
    cout << *obj1.ptr << endl;
    *obj1.ptr = 5;
    cout << *obj1.ptr << endl;

    // Deep copy
    cout << "--- Deep ---\n";
    MyClass obj2 = obj1;

    *obj2.ptr = 10;

    cout << *obj1.ptr << endl; // remains 5
    cout << *obj2.ptr << endl; // becomes 10
        
    return 0;
}