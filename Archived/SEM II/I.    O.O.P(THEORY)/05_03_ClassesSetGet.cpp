#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length; 
        int width;

    public:
        void setLength(int len){
            if(len >= 0)
                length = len;
            else
                cout<<"\nValue is not valid\n\n";
        }

        int getLenth(){
            return length;
        }

        void setWidth(int wid){
            width = wid;
        }

        int getWidth(){
            return width;
        }

        int getArea(){
            return length * width;
        }

        int getCircumference(){
            return 2 * (length + width);
        }

};


int main(){
    cout<<"\n\n";
    Rectangle rec1;
    rec1.setLength(10);
    rec1.setWidth(5);
    cout<<"\nLength = "<<rec1.getLenth(); 
    cout<<"\nWidth = "<<rec1.getWidth(); 
    cout<<"\nArea = "<<rec1.getArea(); 
    rec1.setLength(15);
    cout<<"\nArea = "<<rec1.getArea(); 
    cout<<"\nCircumference = "<<rec1.getCircumference(); 
}