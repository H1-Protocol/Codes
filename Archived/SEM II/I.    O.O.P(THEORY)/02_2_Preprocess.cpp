#include<iostream>
using namespace std;
#define Square(x) x*x // Defining Macro

int main() 
{
    float x; 
    cout<<"Enter value to find its square: ";
    cin>>x; // Input from user
    cout<<"Square = "<<Square(x)<<endl; 
    return 0;
}