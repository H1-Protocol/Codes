#include <iostream>
#include <string>
using namespace std;

class Student {
	private:
    	int rollNo;
    	int score1, score2, score3;
    	string name;

	    // Private Helper Functions
	    int validateMarks(int marks){
			if (marks >= 0 && marks <=100){
				return marks;
			}else{
				return 0;
			}
		}
	
	    int calculateMarks() {
	        return score1 + score2 + score3;
	    }
	
	    int calculateAvg() {
	        return calculateMarks() / 3;
	    }
	
	    string calculateResult() {
	        if(calculateAvg() < 60){
					return "Fail.";
			}else{
					return "Pass.";
			}
	    }
	
	    float calculateGpa() {
	        int avg = calculateAvg();
	        float calculatedGpa = (avg / 100.0) * 4.0;
	        return calculatedGpa;
	    }

	public:
	    // Constructor
	    Student(){
			rollNo = 0;
			name = "Not Entered.";
			score1 = 0;
			score2 = 0;
			score3 = 0;
		}
		
		~Student(){
			// Destructor - Empty for now
		}
	
	    // Setter Functions
	    void setRollNo(int r) {
	        rollNo = r;
	    }
	
	    void setName(string n) {
	        name = n;
	    }
	
	    void setScore(int s1, int s2, int s3) {
	        score1 = validateMarks(s1);
	        score2 = validateMarks(s2);
	        score3 = validateMarks(s3);
	    }
	
	    void setStudent(int r, string n, int s1, int s2, int s3) {
	        rollNo = r;
	        name = n;
	        setScore(s1, s2, s3);
	        // gpa is no longer stored
	    }
	
	    // Getter Functions
	    int getRollNo() {
	        return rollNo;
	    }
	
	    string getName() {
	        return name;
	    }
	
	    float getGpa() {
	        return calculateGpa();  // dynamically calculate GPA
	    }
	
	    int getScore(int s) {
	        if (s == 1) return score1;
	        if (s == 2) return score2;
	        if (s == 3) return score3;
	        return 0;
	    }
	
	    int getObtainedMarks() {
	        return calculateMarks();
	    }
	
	    int getAvg() {
	        return calculateAvg();
	    }
	
	    string getResult() {
	        return calculateResult();
	    }
	
	    // User Input Function
	    void takeData() {
	        int r;
	        string n;
	        int s1, s2, s3;
	
	        cout << "Enter Roll no: ";
	        cin >> r;
	
	        cout << "Enter Name: ";
	        cin >> n;
	
	        cout << "Enter Subject1: ";
	        cin >> s1;
	
	        cout << "Enter Subject2: ";
	        cin >> s2;
	
	        cout << "Enter Subject3: ";
	        cin >> s3;
	
	        setStudent(r, n, s1, s2, s3);
	    }
	
	    // Display Function
	    void displayInfo() {
	        cout << "========================================" << endl;
	        cout << "Student Rollno : " << getRollNo() << endl;
	        cout << "Student Name   : " << getName() << endl;
	        cout << "Student GPA    : " << getGpa() << endl; // dynamically calculated
	        cout << "Subject1 Marks : " << getScore(1) << endl;
	        cout << "Subject2 Marks : " << getScore(2) << endl;
	        cout << "Subject3 Marks : " << getScore(3) << endl;
	        cout << "---------------------" << endl;
	        cout << "Total Marks    : " << getObtainedMarks() << endl;
	        cout << "Average Marks  : " << getAvg() << endl;
	        cout << "Exam Result    : " << getResult() << endl;
	        cout << "========================================" << endl;
	    }
};

int main() {
    Student s1;
    s1.takeData();
    s1.displayInfo();
    return 0;
}