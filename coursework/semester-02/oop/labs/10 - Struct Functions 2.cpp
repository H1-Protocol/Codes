#include<iostream>
using namespace std;

/*
    Returning a Struct from a Function:

    - Functions can return structures in C++.
    - Returning a struct copies all members of the struct to the caller.
    - Useful for modular code where you want to create or calculate a struct
      inside a function and return it.
      
*/

// Structure Definition
struct Student{
    string firstName;
    string lastName;
    int testScore;
    int programmingScore;
    double GPA;
};

// Function to create a student record and return it
Student createStudent() {
    Student s;

    cout << "Enter first name: ";
    cin >> s.firstName;

    cout << "Enter last name: ";
    cin >> s.lastName;

    cout << "Enter Test Score: ";
    cin >> s.testScore;

    cout << "Enter Programming Score: ";
    cin >> s.programmingScore;

    // Calculate GPA (simple average scaled to 4.0)
    s.GPA = (s.testScore + s.programmingScore) / 2.0 / 25.0;

    return s;  // Return the complete struct
}

// Function to display a student
void displayStudent(Student s) {
    cout << "\nStudent Details:" << endl;
    cout << "Name: " << s.firstName << " " << s.lastName << endl;
    cout << "Test Score: " << s.testScore << endl;
    cout << "Programming Score: " << s.programmingScore << endl;
    cout << "GPA: " << s.GPA << endl;
}

int main() {
    // Call function to create a student and assign returned struct
    Student s1 = createStudent();

    // Display the returned student
    displayStudent(s1);

    /*
        Key Points:

        1. The function createStudent() returns a Student struct.
        2. The caller (main) receives a copy of the struct.
        3. Access members using dot (.) operator.
        4. Returning structs allows modular, reusable code.
        5. Be careful: returning very large structs by value may have performance cost.
           In such cases, returning by reference or pointer is better.
    */

    return 0;
}

