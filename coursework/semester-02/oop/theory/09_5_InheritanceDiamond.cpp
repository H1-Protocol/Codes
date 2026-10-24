#include <iostream>
using namespace std;
// Declaring Virtual Function   =>  virtual void draw();
// Declaring Virtual Destructor =>  virtual ~MyClass();
// Declaring Virtual Base Class =>  class Derived1 : virtual public Base;

class A
{
public:
    A(){
        cout<<"*** Constructor of A is called ***"<<endl;
    }
};

class B : virtual public A  // remove virtual to see changes
//class B : public A        // removed virtual
{
public:
    B(){
        cout<<"Constructor of B is called"<<endl;
    }
};

class C : virtual public A  //remove virtual to see changes
//class C : public A        //removed virtual
{
public:
    C(){
        cout<<"Constructor of C is called"<<endl;
    }
};

class D : public B, public C
{
public:
    D(){
        cout<<"Constructor of D is called"<<endl;
    }};

int main()
{
    D d;
    return 0;
}
