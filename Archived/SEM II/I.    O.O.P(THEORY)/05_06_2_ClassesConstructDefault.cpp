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
       
        int getLenth(){
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
    Rectangle rec1;
    //Rectangle rec1(); // This does not work    
    cout<<"\nLength = "<<rec1.getLenth(); 
    cout<<"\nWidth = "<<rec1.getWidth(); 
    cout<<"\nArea = "<<rec1.getArea(); 
}