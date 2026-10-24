#include <iostream>
using namespace std;
#define size 10

class Element {
    int value;
    public:
    Element() {
        value = 0;
        cout << "Element constructed!" << endl; 
    }
    
    Element(int val) { 
        value = val; 
        cout << "Element(" << val << ") constructed!" << endl; 
    }

    Element(int val, int val2) { 
        value = val; 
        cout << "Element(" << val << ", " << val2 << ") constructed!" << endl; 
    }

    ~Element() { 
        cout << "Element(" << value << ") destructor called!" << endl; 
    }
    

    int Get(void) { 
        return value; 
    }
    void Put(int val) { 
        value = val; 
    }
};

class Collection 
{
    Element el1, el2;
    //Collection c; //Not Possible 
    //Collection* c;   // pointer allowed
    
    public:
    // if no default constructor exists for class "Element", then you will get error as below
    Collection() { // error: no matching function for call to 'Element::Element()'
        //Collection c; //Not Possible
        cout<<"Collection constructed!" << endl; 
    }

    Collection(int v1, int v2) : el1(v1), el2(v2) { 
        //Collection c; //Not Possible
        cout<<"Collection constructed!" << endl; 
    }

    Collection(int v11, int v12, int v21, int v22) : el1(v11,v12), el2(v21,v22) { 
        //Collection c; //Not Possible
        cout<<"Collection constructed!" << endl; 
    }
    

    ~Collection(){
        cout<<"Collection Destructor Called"<<endl;
    }

    int Get(int elno) { 
        return elno == 1 ? el1.Get() : el2.Get(); 
        //return elno == 1 ? el1.Get() : elno == 2 ? el2.Get() : 100; 
    }
    int Put(int elno, int val) { 
        if(elno == 1) el1.Put(val); else el2.Put(val); 
        //Collection c; //Possible Here
    }
};

int main(void) 
{
    Collection coll(1,2);
    cout<<"Element Value: "<<coll.Get(1)<<endl;
    cout<<"Element Value: "<<coll.Get(2)<<endl;
    cout<<"----------------"<<endl;

    Element e1; 
    cout<<"Element Value: "<<e1.Get()<<endl;
    cout<<"Size of Element: "<<sizeof(e1)<<endl;
    cout<<"Size of Collection: "<<sizeof(coll)<<endl;
    cout<<"----------------"<<endl;

    return 0;
}