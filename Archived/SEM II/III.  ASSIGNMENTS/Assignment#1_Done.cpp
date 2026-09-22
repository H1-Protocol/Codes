#include <iostream>
#include <string>
using namespace std;

class Student {
	private:
    	int rollNo;
    	int score1, score2, score3;
    	string name;
		static string campus;

	    // Private Helper Functions
	    int validateMarks(int marks)const;
	    int calculateMarks() const;
	    int calculateAvg() const; 
	    string calculateResult() const;
	    float calculateGpa() const;
	public:

	    // Constructor
	    Student();
		~Student();

	    // Setter Functions
	    void setRollNo(int );
	    void setName(string );
	    void setScore(int , int , int );
	    void setStudent(int , string , int , int , int );

	    // Getter Functions
	    int getRollNo() const;
	    string getName() const;
	    float getGpa() const;
	    int getScore(int s) const;
	    int getObtainedMarks() const;
	    int getAvg() const;
	    string getResult() const;
		string getCampus() const;

	    // User Input Function
	    void takeData();
	
	    // Display Function
	    void displayInfo();
};

string Student::campus = "IMSciences";


int main() {
	//Stack
    Student s1;
    s1.setRollNo(43);
    s1.setName("Shah Fahad");
    s1.setScore(95, 96, 93);
    s1.displayInfo();

	//Heap
	Student* s2 = new Student();
	s2->setRollNo(34);
    s2->setName("Rehab Amin");
    s2->setScore(85, 98, 78);
	s2->displayInfo();
	
	//Stack Array
	Student sArray[5];

	for (int i = 0; i < 5; i++)
	{
		sArray[i].setName("Student_" + to_string(i));
		sArray[i].setRollNo(i+2);
		sArray[i].setScore(68 + i, 34 + i, 43 + i);
		sArray[i].displayInfo();
	}
	//Heap Array
	Student* dynamicSArray = new Student[10]; 
	for (int i = 0; i < 10; i++)
	{
		dynamicSArray[i].setRollNo(i+2);
		dynamicSArray[i].setName("Dynamic_" + to_string(i));
		dynamicSArray[i].setScore(48 + i, 12 + i, 56 + i);
		dynamicSArray[i].displayInfo();
	}

	delete s2;
	delete[] dynamicSArray;
	return 0;
}

//Functions
int Student::validateMarks(int marks) const{
	if (marks >= 0 && marks <=100){
		return marks;
	}else{
		return 0;
	}
}

int Student::calculateMarks() const 
{
	return score1 + score2 + score3;
}

int Student::calculateAvg() const
{
	return calculateMarks() / 3;
}

float Student::calculateGpa() const{
	int avg = calculateAvg();
	float calculatedGpa = (avg / 100.0) * 4.0;
	return calculatedGpa;
}

string Student::calculateResult() const{
	if(calculateAvg() < 60){
			return "Fail.";
	}else{
			return "Pass.";
	}
}

// Constructor
Student::Student()
{
	rollNo = 0;
	name = "Not Entered.";
	score1 = 0;
	score2 = 0;
	score3 = 0;
}

Student::~Student()
{
	// Destructor - Empty for now
}

// Setter Functions
void Student::setRollNo(int rollNo) 
{
	this->rollNo = rollNo;
}

void Student::setName(string name) 
{
	this->name = name;
}

void Student::setScore(int score1, int score2, int score3) 
{
	this->score1 = this->validateMarks(score1);
	this->score2 = this->validateMarks(score2);
	this->score3 = this->validateMarks(score3);
}

void Student::setStudent(int rollNo, string name, int score1, int score2, int score3) 
{
	this->rollNo = rollNo;
	this->name = name;
	this->setScore(score1, score2, score3);
	// gpa is no longer stored
}
// Getter Functions
int Student::getRollNo() const 
{
    return rollNo;
}

string Student::getName() const 
{
    return name;
}

float Student::getGpa() const 
{
    return calculateGpa();  // dynamically calculate GPA
}
	
int Student::getScore(int score) const
{
    if (score == 1) return score1;
    if (score == 2) return score2;
    if (score == 3) return score3;
    return 0;
}

int Student::getObtainedMarks() const 
{
    return calculateMarks();
}

int Student::getAvg() const
{
    return calculateAvg();
}
	
string Student::getResult() const
{
	return calculateResult();
}
string Student::getCampus() const
{
	return campus;
}
	
// User Input Function
void Student::takeData() 
{
    int rollNo;
    string name;
	int score1, score2, score3;

    cout << "Enter Roll no: ";
    cin >> rollNo;

	cout << "Enter Name: ";
	cin.ignore();
    getline(cin, name);

	cout << "Enter Subject1: ";
    cin >> score1;

    cout << "Enter Subject2: ";
    cin >> score2;
	
    cout << "Enter Subject3: ";
    cin >> score3;
	
	setStudent(rollNo, name, score1, score2, score3);
}
void Student::displayInfo() {
	cout << "========================================" << endl;
	cout << "Student Rollno : " << getRollNo() << endl;
	cout << "Student Name   : " << getName() << endl;
	cout << "Student GPA    : " << getGpa() << endl; // dynamically calculated
	cout << "Student Campus : " << getCampus() << endl; // dynamically calculated
	cout << "Subject1 Marks : " << getScore(1) << endl;
	cout << "Subject2 Marks : " << getScore(2) << endl;
	cout << "Subject3 Marks : " << getScore(3) << endl;
	cout << "---------------------" << endl;
	cout << "Total Marks    : " << getObtainedMarks() << endl;
	cout << "Average Marks  : " << getAvg() << endl;
	cout << "Exam Result    : " << getResult() << endl;
	cout << "========================================" << endl;
}