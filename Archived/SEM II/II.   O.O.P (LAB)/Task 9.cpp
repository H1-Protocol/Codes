#include<iostream>
using namespace std;

//-> Base Class
class Person{
	
	private:
		string CNIC;    // Private: Sensitive information, cannot be accessed directly outside this class
		float salary;   // Private: Sensitive information
	
	protected:
		string name;    // Protected: Accessible inside derived classes
		int age;        // Protected: Accessible inside derived classes
		string gender;  // Protected: Accessible inside derived classes
	
	public:
		string universityName;  // Public: Accessible from anywhere
		
		//-> Function to set private data
		void setPersonInfo(string CNIC, float salary){
			this->CNIC = CNIC;
			this->salary = salary;
		}
		
		//-> Function to display private data
		void displayPersonInfo(){
			cout<<"CNIC: "<<CNIC<<endl;
			cout<<"Salary: "<<salary<<endl;
		}
};


//-> Derived Class (Student)
class Student : public Person{
	
	public:
		int studentID;
		string program;
		int semester;
		
		void displayStudentInfo(){
			cout<<"Name: "<<name<<endl;        // Accessible (Protected)
			cout<<"Age: "<<age<<endl;          // Accessible (Protected)
			cout<<"Gender: "<<gender<<endl;    // Accessible (Protected)
			
			cout<<"Student ID: "<<studentID<<endl;
			cout<<"Program: "<<program<<endl;
			cout<<"Semester: "<<semester<<endl;
			
			cout<<"University: "<<universityName<<endl; // Public member
			
			// CNIC and Salary cannot be accessed directly here because they are private
		}
};


//-> Derived Class (Faculty)
class Faculty : public Person{
	
	public:
		int facultyID;
		string department;
		string designation;
		
		void displayFacultyInfo(){
			cout<<"Name: "<<name<<endl;        // Accessible (Protected)
			cout<<"Age: "<<age<<endl;          // Accessible (Protected)
			cout<<"Gender: "<<gender<<endl;    // Accessible (Protected)
			
			cout<<"Faculty ID: "<<facultyID<<endl;
			cout<<"Department: "<<department<<endl;
			cout<<"Designation: "<<designation<<endl;
			
			cout<<"University: "<<universityName<<endl;
			
			// Private members (CNIC, Salary) cannot be accessed directly here
		}
};


int main(){
	
	//-> Student Object
	Student s1;
	
	//-> Assigning public and derived class values
	s1.universityName = "ABC University";
	s1.studentID = 101;
	s1.program = "BS Artificial Intelligence";
	s1.semester = 3;
	
	//-> Setting private values through function
	s1.setPersonInfo("12345-1234567-1", 0);
	
	cout<<"------ Student Information ------"<<endl;
	s1.displayStudentInfo();
	cout<<endl;
	
	
	//-> Faculty Object
	Faculty f1;
	
	f1.universityName = "ABC University";
	f1.facultyID = 501;
	f1.department = "Computer Science";
	f1.designation = "Lecturer";
	
	f1.setPersonInfo("98765-7654321-9", 80000);
	
	cout<<"------ Faculty Information ------"<<endl;
	f1.displayFacultyInfo();
	cout<<endl;
	
	
	/* Student Notes
	
	Access Specifiers Overview
	
	---------------------------------------------------------
	Access Type | Inside Class | Derived Class | Outside Class
	---------------------------------------------------------
	Private     |     Yes      |      No       |      No
	Protected   |     Yes      |      Yes      |      No
	Public      |     Yes      |      Yes      |      Yes
	---------------------------------------------------------
	
	
	Effect of Public Inheritance
	
	-----------------------------------------------------------------
	Base Member | In Derived Class | Accessible via Object
	-----------------------------------------------------------------
	Private     | Inherited        | No
	Protected   | Protected        | No
	Public      | Public           | Yes
	-----------------------------------------------------------------
	
	*/
	
	return 0;
}
