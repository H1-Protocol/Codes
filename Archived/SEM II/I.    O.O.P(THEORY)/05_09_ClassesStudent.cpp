#include<iostream>
using namespace std;

class Student{    
    public:
        int rollNo;
        string name;
        
        Student(){
            rollNo = 100;
            name = "Not set";
        }

        Student(int rollNo, string name){
            this->rollNo = rollNo;
            this->name = name;
        }

        Student(int rollNo)
        {
            this->rollNo = rollNo;
        }

        Student(string name)
        {
            this->name = name;
            this->rollNo = 100;
        }
};

int main()
{
    //Student std1; 
    //Student std1(223); 
    //Student std1("Alice");
    Student std1(223, "Alice");
    cout<<"Name: "<<std1.name<<endl;
    cout<<"Roll No.: "<<std1.rollNo<<endl;
    return 0;
} 