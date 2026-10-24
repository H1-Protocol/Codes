#include <iostream>
using namespace std;

/*
   Structure definition (C++ Style Structure)
   Data members + Member functions are defined together.
*/
struct Student {
    string firstName;
    string lastName;
    int rollNo;
    char gender;
    int subject1;
    int subject2;
    int subject3;

    /* Function to input student details */
    void createStudent() {
        cout << "First Name: ";
        cin >> firstName;

        cout << "Last Name: ";
        cin >> lastName;

        cout << "Roll No: ";
        cin >> rollNo;

        cout << "Gender (M/F): ";
        cin >> gender;

        cout << "Subject 1 Marks: ";
        cin >> subject1;

        cout << "Subject 2 Marks: ";
        cin >> subject2;

        cout << "Subject 3 Marks: ";
        cin >> subject3;
    }

    /* Function to calculate total marks */
    int calculateTotalMarks() {
        return subject1 + subject2 + subject3;
    }

    /* Function to calculate average marks */
    float calculateAverage() {
        return calculateTotalMarks() / 3.0f;
    }

    /* Function to display student details */
    void displayStudent() {
        cout << "Name        : " << firstName << " " << lastName << endl;
        cout << "Roll No     : " << rollNo << endl;
        cout << "Gender      : " << gender << endl;
        cout << "Marks       : "
             << subject1 << ", "
             << subject2 << ", "
             << subject3 << endl;

        cout << "Total Marks : " << calculateTotalMarks() << endl;

        // Improved version: calculate average only once
        float avg = calculateAverage();
        cout << "Average     : " << avg << endl;

        if (avg >= 50)
            cout << "Result      : Pass" << endl;
        else
            cout << "Result      : Fail" << endl;
    }
};

/* Function to display total number of students */
void totalStudents(int count);

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student students[n];   // Array of C++ style structures

    /* Input student details */
    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter details for Student " << i + 1 << " ---\n";
        students[i].createStudent();
    }

    /* Display student details */
    cout << "\n===== Student Records =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << " Information:\n";
        students[i].displayStudent();
    }

    totalStudents(n);

    return 0;
}

/* Function to display total students */
void totalStudents(int count) {
    cout << "\nTotal number of students: " << count << endl;
}

