#include <iostream>
using namespace std;
#define size 10

class Element {
    const int x = 10; // (default member initializer)
    
    int val;
    int &ref = val; // You can skip = value here and do it in the initlization list

    public:

    /*  About Constructor Initialization List: 
        If the constructor provides an initializer x(v), it overrides the default = 10.
        Thus, x is initialized directly with v, and the = 10 is ignored.

        A reference must be initialized at the moment it is created
        The initializer list is the only place where member variables are created/initialized
    */
    
    Element(int v1, int &v2): x(v1), ref(v2) {   
        cout << "Element constructed!: " <<this->x<< ", "<<this->ref<<endl;
        cout<<"Address of ref: "<<&ref<<endl;
        cout<<"Address of v2: "<<&v2<<endl; 
    }        
};

int main(void) 
{
    int a = 50, b = 1000;
    cout<<"Address of b in main: "<<&b<<endl;
    Element e(a, b);
    
    return 0;
}    


/*
Sequence when an object is created
    1. Memory is allocated for object
    2. Initialization list initializes the members
    3. Constructor body executes
*/

/*
We use initialization list
1. More efficient (no extra assignment)
2. Required for const variables
3. Required for reference members
4. Required for objects of other classes
*/
