#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;

public:
    Rectangle()
    {                      // Remove this one, as it creates ambiguity, when calling default
        this->length = 10; // Try to create Rectangle rec1, then you will get error.
        this->width = 10;  // If you don't create default then it will not give error.
    }

    Rectangle(int length = 10, int width = 10)
    {
        this->length = length;
        this->width = width;
    }

    int getLenth()
    {
        return length;
    }

    int getWidth()
    {
        return width;
    }

    int getArea()
    {
        return length * width;
    }
};

int main()
{
    // Rectangle rec1; // Rectangle rec1() does not work, rec1() acts as function
    // Rectangle rec1(10);
    Rectangle rec1(10, 3);
    cout << "\nLength = " << rec1.getLenth();
    cout << "\nWidth = " << rec1.getWidth();
    cout << "\nArea = " << rec1.getArea();
}