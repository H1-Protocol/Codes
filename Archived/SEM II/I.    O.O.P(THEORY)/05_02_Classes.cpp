#include<iostream>
using namespace std;

// Using Class like C/C++ structure
class Rectangle
{
    int length; 
    int width;

public:
    void setLength(int len){
        if(len > 0)
            length = len;
        else{
            length = 0;
            cout<<"Length must be positive"<<endl;    
        }
    }  
    int getLength(){
        return length;
    }

};


int main(){
    Rectangle rec1;
    rec1.setLength(10);
    cout<<"\nArea = "<<2*rec1.getLength(); 

}