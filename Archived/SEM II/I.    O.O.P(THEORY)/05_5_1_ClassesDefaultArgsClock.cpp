#include<iostream>
using namespace std;

class ClockType{
    int sec, min, hr;
    public:    
    //void setTime(int h, int m, int s){
    void setTime(const int& h, const int& m, const int& s){
        //h = 30; // error: assignment of read-only reference 'h'
        hr = h;
        min = m;
        sec = s;
    }   
    void print() const {
        //hr = 10; // error: assignment of member 'ClockType::hr' in read-only object
        cout<<hr<<":"<<min<<":"<<sec<<endl;
    }   
};

int main()
{
    ClockType clock1;
    clock1.setTime(7, 34, 18);
    clock1.print();
    return 0;
} 