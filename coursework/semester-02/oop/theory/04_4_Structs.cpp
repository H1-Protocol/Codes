#include<iostream>
using namespace std;

struct Student{
    int regNo;
    string name;
};

int main()
{
    Student stds[3];
    //cout<<"Size of Student struct: "<<sizeof(Student)<<" bytes"<<endl;
    cout<<"Size of Student struct: "<<sizeof(stds[0])<<" bytes"<<endl;
    
    for(int i=0; i<3; i++)
    {
        cout<<"\nEnter Value for Registration: ";
        cin>>stds[i].regNo;
        cout<<"Enter Value for Name: ";
        cin>>stds[i].name;
    }

    cout<<"\nRecords: \n";    
    for(int i=0; i<3; i++)
    {
        cout<<"Reg No: "<< stds[i].regNo<<", ";
        cout<<"Name: "<<stds[i].name<<endl;
    }
}  
