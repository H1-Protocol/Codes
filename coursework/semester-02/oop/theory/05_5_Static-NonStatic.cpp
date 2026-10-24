#include <iostream>
using namespace std;

class Circle
{
    int static count;
    int value;

public:
    static int methodStatic(){
        return count;       // Allowed
        //return value;     // Not Allowed
    }
    
    int methodNonStatic(){
        return count;       // Allowed 
        //return value;     // Allowed
    }
};
int Circle::count=0;

int main()
{
    return 0;
}