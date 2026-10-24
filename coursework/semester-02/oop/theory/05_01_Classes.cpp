#include<iostream>
using namespace std;
class Rectangle
{
    int length; 
    int width;
    int getArea();
};

int main(){
    Rectangle rec1;
    cout<<sizeof(rec1)<<endl;
}

// Padding in class ensures data members are aligned for efficient memory access. 