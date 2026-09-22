#include<iostream>
using namespace std;

/*
    Structs and Arrays:

    - A structure can be used to define a single complex variable
      (like Student) containing multiple members.
    - Often, we need to store multiple such structure variables.
    - For this, we use arrays of structures.

    Example:

        Student s[5];  // Array of 5 Student structures

    - Each element of the array is a structure variable.
    - Access members using BOTH the array index and dot (.) operator.

        Example:
            s[0].firstName = "Ali";
            s[1].GPA = 3.5;

    - Aggregate input/output is NOT allowed on the array either.
      We must use loops and member-wise input/output.
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

    // Array of 3 students
    Student students[3];

    // Input data for all students using a loop
    for(int i = 0; i < 3; i++){
        cout << "Enter details for Student " << i+1 << ":\n";

        cout << "First Name: ";
        cin >> students[i].firstName;

        cout << "Last Name: ";
        cin >> students[i].lastName;

        cout << "Course Grade: ";
        cin >> students[i].courseGrade;

        cout << "Test Score: ";
        cin >> students[i].testScore;

        cout << "Programming Score: ";
        cin >> students[i].programingScore;

        cout << "GPA: ";
        cin >> students[i].GPA;

        cout << endl;
    }

    // Output all student data using a loop
    cout << "\nAll Students Data:\n";
    for(int i = 0; i < 3; i++){
        cout << "Student " << i+1 << ": "
             << students[i].firstName << " "
             << students[i].lastName << ", Grade: "
             << students[i].courseGrade
             << ", Test Score: " << students[i].testScore
             << ", Programming Score: " << students[i].programingScore
             << ", GPA: " << students[i].GPA << endl;
    }

    /*
        Key Points:

        1. Array of structs is useful to store multiple records of same type.
        2. Access members using: arrayName[index].member
        3. Aggregate operations (cin >> array or cout << array) are NOT allowed.
        4. Loops are usually used for input/output of arrays of structures.
    */

    return 0;
}

