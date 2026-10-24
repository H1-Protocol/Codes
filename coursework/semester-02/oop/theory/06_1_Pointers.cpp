#include "stdio.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

int main() 
{    
    // const int size = 10; 
    // If size is const, it can be used for array declaration in standard C++.

    int size = 10;
    cout<<"\nEnter Value: ";
    cin>>size;
    int arr[size];  // Some compilers (like GCC) allow Variable-Length Arrays (VLAs)
                    // This is a Variable-Length Array (VLA).
                    // VLAs are NOT part of the ISO C++ standard.
                    // Some compilers (like GCC and Clang) allow them as a compiler extension.
                    // Standard C++ requires the array size to be a compile-time constant.
                    // The portable alternative is dynamic allocation (new or vector).
                    // The array size must be a constant expression in C++.
    arr[0] = 10;
    cout<<"Value:  "<<arr[0]<<endl;
    cout<<"Size of Array: "<<sizeof(arr);
    
    return 0;
}
