#include<iostream>
using namespace std;

/*
    Arrays Inside a Struct:

    - A structure can contain arrays as its members.
    - This allows each structure variable to store multiple values
      for a single member.
    - Example use case: Store marks of a student in multiple subjects.
    - Access array elements using: structVariable.arrayName[index]
*/

// Structure Definition
struct Student{
    string firstName;
    string lastName;
    char courseGrade;
    int marks[3];      // Array to store marks in 3 subjects
    double GPA;
};

int main(){

    // Structure Initialization
    Student s1;

    cout << "Enter first name: ";
    cin >> s1.firstName;

    cout << "Enter last name: ";
    cin >> s1.lastName;

    // Input marks for all 3 subjects
    cout << "Enter marks for 3 subjects: ";
    for(int i = 0; i < 3; i++){
        cin >> s1.marks[i];
    }

    // Calculate GPA (simple average / 25 for example)
    int total = 0;
    for(int i = 0; i < 3; i++){
        total += s1.marks[i];
    }
    s1.GPA = total / 3.0 / 25.0;  // Example: scale to 4.0 GPA

    // Output student details
    cout << "\nStudent Data:" << endl;
    cout << "Name: " << s1.firstName << " " << s1.lastName << endl;
    cout << "Marks: ";
    for(int i = 0; i < 3; i++){
        cout << s1.marks[i] << " ";
    }
    cout << "\nGPA: " << s1.GPA << endl;

    /*
        Key Points:

        1. Arrays can be declared as members inside a struct.
        2. Access array elements using: structVariable.arrayName[index]
        3. Useful for storing multiple related values (like subject marks).
        4. Input/output of struct arrays must be done member-by-member.
        5. Aggregate input/output is NOT allowed for the array inside the struct either.
    */

    return 0;
}

