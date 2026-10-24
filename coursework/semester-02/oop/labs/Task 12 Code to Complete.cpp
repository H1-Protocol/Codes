#include<iostream>
#include<string>
using namespace std;

class Person{
	protected:
		string name;
		string gender;
	public:
		void setPersonInfo(string n, string g){
			name = n;
			gender = g;
		}
		
		void display(){
			cout << "Person Name  : " << name <<endl;
			cout << "Person Gender: " << gender <<endl;
		}
};

class Student:public Person{
	protected:
		int rollno;
		float gpa;
	public:
		void setStudentInfo(/*string n, string g,*/ int roll, float gp){
			/*name = n; gender = g;*/
			rollno = roll;
			gpa = gp;
		}
		
		void display(){
			cout << "Student Name     : " << name <<endl;
			cout << "Student Gender   : " << gender <<endl;
			cout << "Student Roll no  : " << rollno <<endl;
			cout << "Student GPA      : " << gpa <<endl;
		}
};

class GraduateStudent:public Student{
	
};

int main(){
	Person p1;
	p1.setPersonInfo("Kaisar", "Male");
	p1.display();
	
	cout<<"-------------------" <<endl;
	
	Student s1;
	s1.setStudentInfo("Kamal", "Male", 102, 3.2);
	s1.display();
	
	return 0;
}
