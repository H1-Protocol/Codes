#include<iostream>
using namespace std;

/*
    Structs and Functions:

    - Structures allow us to group related data together.
    - Functions can take structures as arguments or return structures.
    - Passing a struct to a function can be done:
        1. By value (makes a copy of the struct)
        2. By reference (avoids copy, changes original)
    - Functions allow modular code and reuse of logic.
*/

// Structure Definition
struct Student{
    string firstName;
    string lastName;
    int testScore;
    int programmingScore;
    double GPA;
};

// Function to calculate GPA of a student (pass by reference)
void calculateGPA(Student &s){
    // Simple average of testScore and programmingScore scaled to 4.0
    s.GPA = (s.testScore + s.programmingScore) / 2.0 / 25.0;
}

// Function to display student details (pass by value)
void displayStudent(Student s){
    cout << "Name: " << s.firstName << " " << s.lastName << endl;
    cout << "Test Score: " << s.testScore << endl;
    cout << "Programming Score: " << s.programmingScore << endl;
    cout << "GPA: " << s.GPA << endl;
}

int main(){

    // Structure Initialization
    Student s1;

    // Input student details
    cout << "Enter first name: ";
    cin >> s1.firstName;

    cout << "Enter last name: ";
    cin >> s1.lastName;

    cout << "Enter Test Score: ";
    cin >> s1.testScore;

    cout << "Enter Programming Score: ";
    cin >> s1.programmingScore;

    // Calculate GPA using function
    calculateGPA(s1);

    // Display student details using function
    cout << "\nStudent Details:" << endl;
    displayStudent(s1);

    /*
        Key Points:

        1. Structures can be passed to functions either by value or by reference.
        2. Pass by value: Function gets a copy of the struct, original remains unchanged.
        3. Pass by reference: Function works on original struct, changes persist.
        4. Functions improve modularity and readability.
        5. Always use the dot (.) operator inside functions to access members.
    */

    return 0;
}

