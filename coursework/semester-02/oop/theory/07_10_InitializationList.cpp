#include <iostream>
using namespace std;
#define size 10

class MyClass {
    public:
    // MyClass(int a, int b, int c) : x(a), y(b) {
    //     z = c;
    // }
    
    //Using same name for arguments as of class member variables
    MyClass(int x, int y, int z) : x(x), y(y) { // Compiler automatically distinguish b/w argument and memeber varaibale
        this->z = z;
    }

    int x;
    int y;
    int z;
};

int main(){
    MyClass obj(1,2,3); 
    cout<<"X="<<obj.x<<", Y="<<obj.y<<", Z="<<obj.z;
}