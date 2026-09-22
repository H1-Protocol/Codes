#include <iostream>
using namespace std;

struct Student {
    string first_name;
    string last_name;
    int roll_num;
    char gender;
    int marks[3];
};

Student inputStudent();
void displayStudent(Student s);
int totalMarks(Student s);
float averageMarks(Student s);
void totalStudents(int n);

int main() {
    int n;
    cout << "Enter number of students: ";cin >> n;
Student students[n];

for(int i = 0; i < n; i++) {
    cout << "\nEnter details for student " << i + 1 << endl;
    students[i] = inputStudent();
    }

for(int i = 0; i < n; i++) {
    displayStudent(students[i]);
    }
    totalStudents(n);
    return 0;
}

Student inputStudent() {
    Student s;

    cout << "Enter First Name: ";cin >> s.first_name;
    cout << "\nEnter Last Name: ";cin >> s.last_name;
    cout << "\nEnter Roll Number: ";cin >> s.roll_num;
    cout << "\nEnter Gender (M/F): ";cin >> s.gender;

for(int i = 0; i < 3; i++) {
        cout << "Enter marks of subject " << i + 1 << ": ";cin >> s.marks[i];
    }
    return s;
}

int totalMarks(Student s) {
    int total = 0;
for(int i = 0; i < 3; i++) {
        total += s.marks[i];
    }
    return total;
}

float averageMarks(Student s) {
    return totalMarks(s) / 3.0;}

void displayStudent(Student s) {
    int total = totalMarks(s);
    float avg = averageMarks(s);

    cout << "\nName: " << s.first_name << " " << s.last_name;
    cout << "\nRoll#: " << s.roll_num;
    cout << "\nGender: " << s.gender;
    cout << "\nTotal Marks: " << total;
    cout << "\nAverage: " << avg;

    if(avg >= 50)
        cout << endl << "Status: Pass";
    else
        cout << endl << "Status: Fail" << endl;

    cout << "_________________________";
}

void totalStudents(int n) {
    cout << endl << "Total number of students: " << n << endl;
}

//ChatGPT was indeed used for partial guidance