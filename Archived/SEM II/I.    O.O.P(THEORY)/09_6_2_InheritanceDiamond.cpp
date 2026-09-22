#include <iostream>
using namespace std;

class A
{
public:
    int age, regNo;
    float cgpa;
};
class B :  virtual public A   
{};
class C : virtual public A
{};
class D : public B, public C
{};

int main()
{
    D d;
    cout<<sizeof(d);
    
    // Without virtual inheritance:
    // "age", "regNo", and "cgpa" counts twice,
    // causing data duplication and increasing the size.

    // With virtual inheritance:
    // Only one copy of A's members ("age", "regNo", "cgpa") is 
    // present. However, two pointers (vptrs), each of 4 bytes on
    // 32-bit systems are added managing virtual base classes internally.

    return 0;
}