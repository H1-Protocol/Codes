#include<iostream>
using namespace std;

class ClockType{
    int sec, min, hr;
    public:
    
    ClockType()
    {
        this->sec = 0;
        this->min = 0;
        this->hr = 0;
    }
    ClockType(int sec=0, int min=0, int hr=0)
    {
        this->sec = sec;
        this->min = min;
        this->hr = hr;
    }
    void print() const {
        cout<<hr<<":"<<min<<":"<<sec<<endl;
    }
};

int main()
{
    //ClockType clock1; //Line 1
    ClockType clock2(5); //Line 2
    ClockType clock3(12, 30); //Line 3
    ClockType clock4(7, 34, 18);
    clock2.print();
    return 0;
} 