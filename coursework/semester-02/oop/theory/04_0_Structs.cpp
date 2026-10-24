#include<iostream>
using namespace std;

struct Student{
    int regNo;
    string name;
};

int main()
{
    Student std1;
    std1.regNo = 100;
    std1.name = "Ali";
    cout<<endl<<"RegNo. :"<<std1.regNo;
    cout<<endl<<"Name: "<<std1.name;
}  
