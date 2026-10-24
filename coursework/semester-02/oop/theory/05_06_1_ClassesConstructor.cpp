#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length; 
        int width;
    public:
        Rectangle(){
            length = 15;
            width = 10;
        }
       
        int getLength(){
            return length;
        }
       
        int getWidth(){
            return width;
        }

        int getArea(){
            return length * width;
        }

};


int main(){
    cout<<"\n\n";
    Rectangle rec1;
    cout<<"\nLength = "<<rec1.getLength(); 
    cout<<"\nWidth = "<<rec1.getWidth(); 
    cout<<"\nArea = "<<rec1.getArea(); 
}