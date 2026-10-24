#include <iostream>
using namespace std;

class MyClass {
public:
    int *ptr;
    MyClass() {
        ptr = new int;
        *ptr = 2000;
    }
    ~MyClass() {
        delete ptr;
    }
};

int main() {

    MyClass obj1;
    cout<<"---\n";
    cout<<*obj1.ptr<<endl;
    *obj1.ptr = 5;
    cout<<*obj1.ptr<<endl;
    
    // Shallow copy
    cout<<"--- Shallow --- \n";
    MyClass obj2 = obj1;
    *obj2.ptr = 10;

    cout << *obj1.ptr << endl;
    cout << *obj2.ptr << endl;
        
    return 0;
}
