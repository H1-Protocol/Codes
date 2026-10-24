#include<iostream>
using namespace std;

/*
    Structs: Comparing Structs member by member
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

    // Structure Initialization
    Student s1 = {"Ali", "Khan", 'A', 85, 90, 3.8};
    Student s2 = {"Ali", "Khan", 'A', 85, 90, 3.8};

    /*
        IMPORTANT CONCEPT:

        We cannot compare entire structures like this:

            if(s1 == s2)   ? (Not allowed in basic struct usage)

        Instead, we compare ALL members individually
        and combine the conditions using logical AND (&&).
    */

    if( s1.firstName       == s2.firstName &&
        s1.lastName        == s2.lastName &&
        s1.courseGrade     == s2.courseGrade &&
        s1.testScore       == s2.testScore &&
        s1.programingScore == s2.programingScore &&
        s1.GPA             == s2.GPA )
    {
        cout << "Both students are completely equal." << endl;
    }
    else
    {
        cout << "Students are different." << endl;
    }

    /*
        Explanation:

        The logical AND (&&) operator ensures that:

        - Every member must be equal
        - If even one member is different,
          the entire condition becomes false.

        This is called full structure comparison
        using member-wise relational checking.
    */

    return 0;
}

