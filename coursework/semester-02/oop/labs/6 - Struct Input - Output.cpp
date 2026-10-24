#include<iostream>
using namespace std;

/*
    Struct Input and Output:

    - In C++, we CANNOT perform aggregate input or output
      operations directly on a structure variable.

    - That means the following are NOT allowed:

            cin >> s1;      ?
            cout << s1;     ?

    - The compiler does not know how to read or display
      an entire structure automatically.

    - Therefore, we must perform input and output
      MEMBER-BY-MEMBER using the dot (.) operator.
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

    Student s1;

    /*
        ? INVALID (Aggregate Input Not Allowed)

        cin >> s1;

        The compiler does not know how to input
        all members of the structure at once.
    */

    // ? VALID: Member-by-member input

    cout << "Enter First Name: ";
    cin >> s1.firstName;

    cout << "Enter Last Name: ";
    cin >> s1.lastName;

    cout << "Enter Course Grade: ";
    cin >> s1.courseGrade;

    cout << "Enter Test Score: ";
    cin >> s1.testScore;

    cout << "Enter Programming Score: ";
    cin >> s1.programingScore;

    cout << "Enter GPA: ";
    cin >> s1.GPA;


    /*
        ? INVALID (Aggregate Output Not Allowed)

        cout << s1;

        The compiler does not know how to display
        the entire structure automatically.
    */

    // ? VALID: Member-by-member output

    cout << "\nStudent Data:" << endl;
    cout << "Name: " << s1.firstName << " " << s1.lastName << endl;
    cout << "Grade: " << s1.courseGrade << endl;
    cout << "Test Score: " << s1.testScore << endl;
    cout << "Programming Score: " << s1.programingScore << endl;
    cout << "GPA: " << s1.GPA << endl;

    /*
        IMPORTANT CONCLUSION:

        - Structures support aggregate initialization.
        - Structures support assignment.
        - Structures DO NOT support aggregate input/output.
        - We must use dot operator to access each member.
    */

    return 0;
}

