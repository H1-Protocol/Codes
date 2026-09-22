#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length; 
    public:
        void setLength(int length){
            //Rectangle::length = length; // Works, but use this for static variables
            this->length = length;
        }
        
        int getLength(){
            return length;
        }
};

int main(){
    Rectangle rec1;
    rec1.setLength(10);
    cout<<"\nLength = "<<rec1.getLength(); 
}