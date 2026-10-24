#include <iostream>
using namespace std;

/* Structure definition */
struct Student {
    string firstName;
    string lastName;
    int rollNo;
    char gender;
    int subject1;
    int subject2;
    int subject3;
};

/* Function prototypes */
Student createStudent();
void displayStudent(Student s);
int calculateTotalMarks(Student s);
float calculateAverage(Student s);
void totalStudents(int count);

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

     /*
       Beginner-Level Approach:
       Creating an array of structures using user input size.

       NOTE:
       Student students[n]; is called a Variable Length Array (VLA).
       It works in many compilers (like GCC), but it is NOT standard C++.

       Better (Standard C++) Approach:
       1) Using dynamic memory:
          Student* students = new Student[n];

       2) Using modern C++ (Recommended):
          #include <vector>
          vector<Student> students(n);

       For now, we are using this method because it is simple
       and easier to understand at beginner level.
    */
    
    Student students[n];   // Array of structures (Beginner-friendly version)

    /* Input student details */
    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter details for Student " << i + 1 << " ---\n";
        students[i] = createStudent();
    }

    /* Display student details */
    cout << "\n===== Student Records =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << " Information:\n";
        displayStudent(students[i]);
    }

    totalStudents(n);

    return 0;
}

/* Function to create a student */
Student createStudent() {
    Student s;

    cout << "First Name: ";
    cin >> s.firstName;

    cout << "Last Name: ";
    cin >> s.lastName;

    cout << "Roll No: ";
    cin >> s.rollNo;

    cout << "Gender (M/F): ";
    cin >> s.gender;

    cout << "Subject 1 Marks: ";
    cin >> s.subject1;

    cout << "Subject 2 Marks: ";
    cin >> s.subject2;

    cout << "Subject 3 Marks: ";
    cin >> s.subject3;

    return s;
}

/* Function to display student details */
void displayStudent(Student s) {
    cout << "Name        : " << s.firstName << " " << s.lastName << endl;
    cout << "Roll No     : " << s.rollNo << endl;
    cout << "Gender      : " << s.gender << endl;
    cout << "Marks       : "
         << s.subject1 << ", "
         << s.subject2 << ", "
         << s.subject3 << endl;

    cout << "Total Marks : " << calculateTotalMarks(s) << endl;

    // Improved version: calculate average only once
    float avg = calculateAverage(s);
    cout << "Average     : " << avg << endl;

    if (avg >= 50)
        cout << "Result      : Pass" << endl;
    else
        cout << "Result      : Fail" << endl;
}

/* Function to calculate total marks */
int calculateTotalMarks(Student s) {
    return s.subject1 + s.subject2 + s.subject3;
}

/* Function to calculate average marks */
float calculateAverage(Student s) {
    return calculateTotalMarks(s) / 3.0f;
}

/* Function to display total students */
void totalStudents(int count) {
    cout << "\nTotal number of students: " << count << endl;
}

