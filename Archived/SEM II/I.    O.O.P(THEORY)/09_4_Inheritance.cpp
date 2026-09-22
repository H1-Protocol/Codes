#include<iostream>
using namespace std;

class A{
    int b;
    public:
    A(){b = 10;}
    void print(){
     cout<<"Class A: "<<b<<endl;
    }
};

class B: public A{
    int b;
    public:
    B(){b = 20;}
    void print(){
        cout<<"Class B: "<<b<<endl;
        A::print();
    }
};

int main(){
    B b;
    //b.b = 50;     //if b is public in class B then 
    //b.A::b = 30;  //if b is public in class A then
    b.print();
}
