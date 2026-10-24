#include<iostream>
using namespace std;

struct Student{
    int regNo;
    string name;
};
//Student stds[3]; // Default Values as global
    
int main()
{
    Student stds[3] = {{1, "Alice"}, {2, "Bob"}, {3, "Mark"}};
    //Student stds[3]; // Garbage Values
    
    cout<<"Records: \n";    
    for(int i=0; i<3; i++)
    {
        cout<<"Reg No: "<< stds[i].regNo<<", ";
        cout<<"Name: "<<stds[i].name<<endl;
    }
}  
