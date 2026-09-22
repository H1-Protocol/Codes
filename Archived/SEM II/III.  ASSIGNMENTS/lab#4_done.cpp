#include<iostream>
using namespace std;
struct student{
    string firstname;
    string lastname;
    int rollno;
    char gender;
    int marks[3];
    int total;
    float average;

    string getfirstname(){
        return firstname;
    }

    string getlastname(){
        return lastname;
    }

    int getrollno(){
        return rollno;
    }

    char getgender(){
        return gender;
    }

    void createstudentinfo(){
        cout << "enter first name: " << endl;
        cin >> firstname;
        cout << "enter last name: " << endl;
        cin >> lastname;
        cout << "enter roll no: " << endl;
        cin >> rollno;
        cout << "enter gender: " << endl;
        cin >> gender;
        cout << "enter marks: " << endl;
        for(int i=0;i<3;i++){
            cin >> marks[i];
        }
    }
    void displaystudentinfo(){
        cout << "firstname: " << firstname << endl;
        cout << "lastname: " << lastname << endl;
        cout << "rollno: " << rollno << endl;
        cout << "gender: " << gender << endl;
        cout << "marks: ";
        for(int i=0;i<3;i++){
            cout << marks[i] << endl;
        }
    }
    void calculatetotal(){
        total = 0;
        for(int i=0;i<3;i++){
            total += marks[i];
        }
    }
    void calculateaverage(){
        average = total / 3.0;
    }
    void displaytotal(){
        cout << "total marks are: " << total << endl;
        cout << "average marks are: " << average << endl;
        if(average >= 50){
            cout << "status: pass" << endl;
        }
        else{
            cout << "status: fail" << endl;
        }
    }
};
int main(){
    int n;
    cout << "enter number of students: " << endl;
    cin >> n;
    student s[n];
    for(int i=0;i<n;i++){
        cout << "enter details for student " << i+1 << endl;
        s[i].createstudentinfo();
        s[i].calculatetotal();
        s[i].calculateaverage();
    }
    cout << "----- STUDENT DETAILS -----" << endl;
    for(int i=0;i<n;i++){
        cout << " Student: " << i+1 << endl;
        s[i].displaystudentinfo();
        s[i].displaytotal();
    }
}

