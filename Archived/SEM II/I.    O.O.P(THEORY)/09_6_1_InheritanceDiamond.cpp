#include <iostream>
using namespace std;

class A
{
public:
    int a;
};

class B :  virtual public A 
//class B :  public A   // remove virtual to see compilation error 
{                       // error due to accessing variable "a"
public:                 // Without virtual, D end up with two copies of A.
    int b;
};

class C : virtual public A 
//class C : public A //remove virtual to see compilation error
{
public:
    int c;
};

class D : public B, public C
{
public:
    int d;
};

int main()
{
    D d;
    d.a = 1; //Ambiguity in accessing a, remove virtual to see this
    d.b = 2;
    d.c = 3;
    d.d = 4;
    cout<<"a="<<d.a<<", "; // error: request for member 'a' is ambiguous, remove virtual to see this 
    cout<<"b="<<d.b<<", c="<<d.c<<", d="<<d.d;
    return 0;
}

// Note:
// C3 linearization method is a well-defined algorithm for establishing a linear 
// order of classes in the inheritance hierarchy, C++ takes a different approach 
// based on its own set of rules and mechanisms defined by the Itanium C++ ABI.

// Monotonicity in the context of inheritance refers to the principle that, 
// as you move down the inheritance hierarchy, properties or behaviors should not 
// be removed or modified in a way that weakens the guarantees or functionality 
// provided by the base classes. 
// In other words, the derived classes should not violate or contradict the 
// expectations set by their base classes. 