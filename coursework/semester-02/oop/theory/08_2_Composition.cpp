#include <iostream>
using namespace std;
#define size 10

class Element {
    public:
    int value;
    Element(int value) {
        this->value = value;
        cout << "Element constructed!: " <<value<< endl; 
    }    
};

class Collection 
{
    public:
    Element el1, el2;
    Collection(int v1, int v2):  el2(v2), el1(v1) { 
        cout<<"Collection constructed!" << endl; 
    }
};

int main(void) 
{
    Collection coll(50, 70);
    cout<<"Size of Collection: "<<sizeof(coll)<<endl;
    cout<<coll.el1.value<<endl;
    cout<<coll.el2.value;
    return 0;
}