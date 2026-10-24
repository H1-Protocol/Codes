#include<iostream>
#include<string>
using namespace std;

/*
	-> This is the Lab Code for the Topic of:
		1). Function Prototypes
		2). "this" Pointer
		3). Constant Function (const)

*/

class Student{
	private:
		int rollNo;
		string name;
	public:
		// Constructor
		Student(int rollNo = 0, string name = "No Name Entered");
		
		// Setters
		void setInfo(int rollNo, string name);
		
		// Getters
		int getRollNo() const;
		string getName() const;
		
		// Other Functions
		void display() const;
		
		// Destructor
		~Student();	
		
};

int main(){
	
	Student s1(101,"Kaisar Khan");
	Student s2(102, "Mansoor Khan");
	
	s1.display();
	s2.display();
	
	
	
	return 0;
}

	Student::Student(int rollNo, string name){
			this->rollNo = rollNo;
			this->name = name;
		}
		
	Student::~Student(){
			// Any code for destructor goes here...
		}
		
void Student::setInfo(int rollNo, string name){
			this->rollNo = rollNo;
			this->name  = name;
		}
		
int Student::getRollNo() const{
			return this->rollNo;
		}
		
string Student::getName() const{
			return this->name;
		}
		
void Student::display() const{
			cout << "\n-----------------------------"<<endl;
			cout << "Student Rollno: " << this->getRollNo() <<endl;
			cout << "Student Name  : " << this->getName()<<endl;
			cout << "-----------------------------"<<endl;
			
		}
