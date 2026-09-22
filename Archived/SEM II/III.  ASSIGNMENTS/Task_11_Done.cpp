 #include <iostream>
 #include <fstream>
 #include <string>
using namespace std;



class Person{

    protected:               
    string name ;
    int age ;       

    public:
void setPerson(string name, int age){
        this->name = name;
        this->age = age;
}

void displayPerson(){
    cout <<"The name is " << name << "Mr." << name << " and the age is " << age;
}};

class Student : public Person{
    protected:
    string studentID;
    string department;

    public:
void setStudent(string name, int age, string studentID , string department){
        setPerson(name, age);
        this->studentID = studentID;
        this->department = department;
    }
void displayStudent(){
    cout << "Name: " << name << "\nAge: " << age <<'\n';
    cout <<"Student ID: " << studentID << "\nDepartment: " << department << '\n';
}
};

class GraduateStudent : public Student{
    private:
    string researchTopic;
    float CGPA;

    public:
    void setGraduate(string name, int age, string studentID , string department,string researchTopic, float CGPA){
        setStudent( name,  age,  studentID ,  department);
        this->researchTopic = researchTopic;
        this->CGPA = CGPA;

    }
void displayGraduate(){
    //displayStudent();
    cout << "Name: " << name << "\nAge: " << age <<'\n';
    cout <<"Student ID: " << studentID << "\nDepartment: " << department << "\nResearch Topic: " << researchTopic << "\nCGPA: " << CGPA;
}

};







int main(){

    GraduateStudent grad2029;
    grad2029.setGraduate("Zakki Ahmed", 19, "253208974", "Software Engineering","2000-bit Architecture", 0.9);
    grad2029.displayGraduate();



 return 0; 
}