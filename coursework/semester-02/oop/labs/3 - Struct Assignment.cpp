#include<iostream>
using namespace std;

/*
    Structs:
    - A struct is a collection of related variables grouped together.
    - The variables inside a struct are called members.
    - Members can be of same or different data types.
    - Structures are also known as records.
    - The dot (.) operator is used to access struct members.
*/

// Structure Definition
struct Student{
    string firstName;
    string lastName;
    char courseGrade;
    int testScore;
    int programingScore;
    double GPA;
};

int main(){

    // Structure Initialization using aggregate initialization
    Student s1 = {"Ali", "Khan", 'A', 85, 90, 3.8};

    // Structure Declaration
    Student s2;

    // Assigning s1 to s2 using assignment operator
    s2 = s1;

    /*
        This is valid in C++, and it performs member-wise copy automatically.

        That means the compiler internally does:

        s2.firstName = s1.firstName;
        s2.lastName = s1.lastName;
        s2.courseGrade = s1.courseGrade;
        s2.testScore = s1.testScore;
        s2.programingScore = s1.programingScore;
        s2.GPA = s1.GPA;

        All of this is done automatically by the compiler.
    */

    // Displaying values to verify copy
    cout << "Student 2 Data:" << endl;
    cout << "Name: " << s2.firstName << " " << s2.lastName << endl;
    cout << "Grade: " << s2.courseGrade << endl;
    cout << "Test Score: " << s2.testScore << endl;
    cout << "Programming Score: " << s2.programingScore << endl;
    cout << "GPA: " << s2.GPA << endl;

    return 0;
}

