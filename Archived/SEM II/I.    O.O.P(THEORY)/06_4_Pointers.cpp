#include "stdio.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

int main() 
{    
    char c = 'g';
    char *cPtr;
    cPtr = &c;
    cout<<sizeof(c)<<endl;
    cout<<sizeof(cPtr)<<endl;
    cout<<*cPtr<<endl;
    
    return 0;
}
