#include <iostream>
using namespace std;
#define size 10

class Element {
    public:
    int value;
    Element() {
        value = 0;
        cout << "Element constructed!: " <<value<< endl; 
    }    
};

class Collection 
{
    public:
    Element el1, el2;
    Collection() { 
        cout<<"Collection constructed!" << endl; 
    }
};

int main(void) 
{
    Collection coll;
    cout<<"Size of Collection: "<<sizeof(coll)<<endl;
    cout<<coll.el1.value<<endl;
    cout<<coll.el2.value;
    
    
    cout<<endl<<endl<<endl;          //My Work fur Self-Testing

Element elr;
    cout << elr.value;

    return 0;
}