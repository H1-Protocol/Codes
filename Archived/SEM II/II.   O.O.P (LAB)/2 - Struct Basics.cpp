#include<iostream>
using namespace std;

/*
	-	Structs: A collection of a fixed number of components in which the components are accessed by name.
	-	The components may be of same or different data types.
	-	Structures are also known as Records
	-	The dot (.) member access operator is used to access a struct member.

*/

// Structure Definition = Structure Name and block of data types in it.
struct Student{
	string firstName;
	string lastName;
	char courseGrade;
	int testScore;
	int programingScore;
	double GPA;
};

int main(){
	
	// Variale Declaration:
		int a;
		int x, y, z;
	
	// Variable Initialization:
		int k = 10;
	
	// Struture Declaration:
		Student s1;
		Student s2, s3, s4;
		
	// Structure (aggregate) Initialization:
		Student s5 = {"Ali", "Khan", 'A', 85, 90, 3.8};
	
	// Strucutre (Member by Member) Initialization:
		Student s6;
		s6.firstName = "Kamran";
		s6.lastName = "Khan";
		s6.courseGrade = 'B';
		s6.testScore = 90;
		s6.programingScore = 88;
		s6.GPA = 3.2;

	
	return 0;
}
