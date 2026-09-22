#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length; 
        int width;
    public:
    
        Rectangle(int length, int width){
            this->length = length;
            this->width = width;
        }

        Rectangle(int length){
            this->length = length;
            this->width = 1;
        }
        
        Rectangle(){
            this->length = 0;
            this->width = 0;
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
    Rectangle rec1; // This will not work, if missing default, 
                    // in presence of prametrized. Explict default is required.
    //Rectangle rec1(15);
    //Rectangle rec1(15, 10);
    cout<<"\nLength = "<<rec1.getLenth(); 
    cout<<"\nWidth = "<<rec1.getWidth(); 
    cout<<"\nArea = "<<rec1.getArea(); 
}