#include<iostream>
#include<string>
using namespace std;

/* 
	The code demonstrates the implementation of the same Student class along
	with simple local variables created in the stack frame, as well as dynamically allocated variables
	in heap memory. These variables are accessed and displayed on the screen to show how they work.

	Similarly, objects of the Student class are created both locally in the stack frame and dynamically
	in the heap. The code also illustrates how to properly access and use these objects in each case.
	
*/


/*
============================================================
                CLASS DEFINITION
============================================================
*/

class Student{
	private:
		int rollNo;
		string name;

	public:

		// 1) Constructor (Runs automatically when object is created)
		Student(int rollNo = 0, string name = "No Name Entered");

		// 2) Destructor (Runs automatically when object is destroyed)
		~Student();

		// 3) Setter Function
		void setInfo(int rollNo, string name);

		// 4) Getter Functions (const ? cannot modify data members)
		int getRollNo() const;
		string getName() const;

		// 5) Display Function
		void display() const;
};



/*
============================================================
                        MAIN FUNCTION
============================================================
*/

int main(){

	cout << "\n========== SIMPLE VARIABLES ==========\n";

	// --------------------------------------------------------
	// 1) LOCAL VARIABLE (Stored in STACK)
	// --------------------------------------------------------
	int x = 5;   // Memory created inside main() stack frame

	cout << "Value of x (Stack Variable): " << x << endl;


	// --------------------------------------------------------
	// 2) POINTER TO STACK VARIABLE
	// --------------------------------------------------------
	int *p1 = &x;  // Pointer is in stack, stores address of x

	cout << "Value of x using pointer p1: " << *p1 << endl;


	// --------------------------------------------------------
	// 3) DYNAMIC VARIABLE (Stored in HEAP)
	// --------------------------------------------------------
	int *p2 = new int;   // Memory allocated in HEAP
	*p2 = 10;            // Assigning value using dereferencing

	cout << "Value of Heap Variable (*p2): " << *p2 << endl;



	cout << "\n========== STACK OBJECTS ==========\n";

	// --------------------------------------------------------
	// 4) OBJECTS CREATED IN STACK
	// --------------------------------------------------------

	Student s1;                 // Default Constructor called
	Student s2(101,"Khan");     // Parameterized Constructor called

	Student s3;                 // Default Constructor
	s3.setInfo(104, "Bashir");   // Setting values using setter

	// Accessing Stack Objects using DOT (.)
	s1.display();
	s2.display();
	s3.display();



	cout << "\n========== HEAP OBJECTS ==========\n";

	// --------------------------------------------------------
	// 5) OBJECT CREATED IN HEAP (Dynamic Object)
	// --------------------------------------------------------

	Student *ptrs1 = new Student;  // Object in HEAP, pointer in STACK

	Student *ptrs2 = new Student(109,"Tehseen Khan");

	// Accessing Heap Object using ARROW (->)
	ptrs1->setInfo(200,"Ali");
	ptrs1->display();

	ptrs2->display();



	// --------------------------------------------------------
	// 6) DEALLOCATING HEAP MEMORY
	// --------------------------------------------------------

	delete p2;      // Free heap memory of int
	delete ptrs1;   // Destructor called here
	delete ptrs2;   // Destructor called here

	cout << "\n========== PROGRAM END ==========\n";

	return 0;
}



/*
============================================================
            CLASS FUNCTION DEFINITIONS
============================================================
*/

// Constructor Definition
Student::Student(int rollNo, string name){
	this->rollNo = rollNo;
	this->name = name;

	cout << "Constructor Called for RollNo: " << this->rollNo << endl;
}


// Destructor Definition
Student::~Student(){
	cout << "Destructor Called for RollNo: " << this->rollNo << endl;
}


// Setter
void Student::setInfo(int rollNo, string name){
	this->rollNo = rollNo;
	this->name  = name;
}


// Getter
int Student::getRollNo() const{
	return this->rollNo;
}


// Getter
string Student::getName() const{
	return this->name;
}


// Display Function
void Student::display() const{
	cout << "\n-----------------------------"<<endl;
	cout << "Student RollNo: " << this->getRollNo() <<endl;
	cout << "Student Name  : " << this->getName()<<endl;
	cout << "-----------------------------"<<endl;
}
