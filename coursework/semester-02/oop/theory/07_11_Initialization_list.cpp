#include <iostream>
using namespace std;
#define size 10

// Understand Initialization List 
// Memory for the object is allocated before the constructor runs.

class Element {
    public:
    int v1, v2;
    // No confusion between class data member and local parameter i.e. data_member(local_parameter)
    Element(int v1, int v2): v2(v2), v1(v1) {
            cout << "Element constructed!: " <<v1<< " " << v2<< endl; 
    }    
};

int main(void) 
{
    Element e(50, 70);
    cout<<e.v1<<endl;
    cout<<e.v2<<endl;
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
