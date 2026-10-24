#include<iostream>
using namespace std;

#define PI 3.14         // Define constant Value
const float PI2 = 3.14; // Define constant Value outside

int main() 
{
    const float PI2 = 3.14; // Define constant Value inside, as this PI2 is local variable
    //const float PI2 = 3.14; // Again defining constant inside is not allowed 
    //PI2 = 3.14; // Not allowed (You cannot change constant)
    
    #define PI 3.14 // Define constant Value inside
    #define PI 3.14 // Allowed to redefine it
    cout<<"PI Value = "<<PI<<endl;
    cout<<"PI2 Value = "<<PI2<<endl;
       
    return 0;
}