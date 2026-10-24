#include <iostream>
using namespace std;
#define size 10

// Understand Initialization List Order and thus Dependency
class Element {
    public:
    int v1, v2;
    Element(int v1, int v2): v1(v1), v2(v2) {
    /*  v1 is initialized first and v2 second (because of declaration order).
        Both are initialized using the constructor parameters. */

    //Element(int v1, int v2): v2(v2), v1(v1) {   
    /*  Even though v2 appears first in the initializer list,
        members are still initialized in declaration order: v1 first, then v2. */

    //Element(int v1, int v2): v2(v1 + 1), v1(v1) {   
    /*  Valid: Both v1 and v2 members are initialized with constructor parameters */

    //Element(int v1, int v2): v1(v2 + 1), v2(v2) {
    /*  Valid: Both v1 and v2 members are initialized with constructor parameters */
        
    //Element(int v1, int v2): v2(this->v1 + 1), v1(v1) { //this->v1 means member v1 not constructor parameter v1.  
    /*  Valid: even though v2 appears first in the initializer list,
        initialization still happens as: member v1 initialized first with parameter v1,
        then member v2 initialized using the already initialized member v1. */

    //Element(int v1, int v2): v1(this->v2 + 1), v2(v2) { 
    /*  Problematic: v1 is initialized first, but it tries to use member v2,
        which has not been initialized yet. This results in garbage value. */
        cout << "Element constructed!: " <<this->v1<< " " << this->v2<< endl; 
    }        
};

int main(void) 
{
    Element e(50, 70);
    return 0;
}    