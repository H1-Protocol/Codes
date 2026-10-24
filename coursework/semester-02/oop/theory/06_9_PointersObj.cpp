#include "stdio.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

class Student{

    public:
    int value;
    Student(){
        cout<<"\n Constructor Called";
        value = 100;
    }

    ~Student(){
        cout<<"\n Destructor Called";
    }

    void method(){
        cout<<"\n Print inside  Method";
    }
};

int main() 
{
    Student *s = new Student;
    //s->method();
    (*s).method();
    cout<<endl<<"\n Before Value: "<<s->value;
    delete s;  // delete is a C++ keyword, frees the memory and also call the destructor of a class 
    //free(s); // free() is a C library method, also used in C++, frees the memory and does not call the destructor of a class
    cout<<endl<<"\n After Value: "<<s->value;
    return 0;
}
