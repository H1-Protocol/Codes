#include "stdio.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

int main() 
{    

    int *iPtr, iVal=10;
    iPtr  = &iVal;
    printf("\nAddress is in C    %p", iPtr);
    cout<<endl<<"Address is  in C++ "<<iPtr; 
    cout<<endl<<"Value is "<<*iPtr; 
    cout<<endl<<"----------------------"; 

    float fVal = 0.0;
    float *fPtr = &fVal;
    cout<<endl<<"Address is "<<fPtr; 
    cout<<endl<<"Value is "<<*fPtr; 
    cout<<endl<<"----------------------"; 

    char cVal = 'C';
    char *cPtr = &cVal;
    cout << endl << "Address is " << static_cast<void*>(cPtr); // cast the pointer to void* for correct address printing 
    cout << endl << "Value is " << *cPtr; // print the actual value of cVal
    cout << endl << "----------------------";
    
    //iPtr = 0;           //Allowed
    //iPtr = NULL;        //Allowed
    return 0;
}

// cout << char* will not print the address as treats char* as a C-style string,
//  will print the characters at that address until it finds a null terminator

// To force cout to print the address use cout << static_cast<void*>(p);

// Both static_cast<void*>(cPtr) and (void*)cPtr work, but static_cast is often 
// preferred in C++ is due to type safety and modern C++ best practices.

// static_cast<void*> is used to convert char* to void* so that cout prints the memory address instead of 
// treating the pointer as a C-string. like const char *name = "Ali";*/
