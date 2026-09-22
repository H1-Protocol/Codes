#include<iostream>
using namespace std;

/*
    Structs:
    - A struct is a collection of related variables grouped together.
    - The variables inside a struct are called members.
    - Members can be of same or different data types.
    - Structures are also known as records.
    - The dot (.) operator is used to access struct members.
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

    // Structure Initialization using aggregate initialization
    Student s1 = {"Ali", "Khan", 'A', 85, 90, 3.8};
    Student s2 = {"Ahmed", "Ali", 'B', 75, 80, 3.2};

    /*
        IMPORTANT CONCEPT:

        In C++, structures CANNOT be compared directly using
        relational operators like:

            s1 > s2
            s1 < s2
            s1 == s2

        This is because the compiler does not know how to compare
        two complete structures automatically (unless operator
        overloading is used in advanced OOP).

        Therefore, we compare individual members instead.
    */

    // Comparing Students based on GPA
    if(s1.GPA > s2.GPA)
    {
        cout << s1.firstName << " has higher GPA than "
             << s2.firstName << endl;
    }
    else if(s1.GPA < s2.GPA)
    {
        cout << s2.firstName << " has higher GPA than "
             << s1.firstName << endl;
    }
    else
    {
        cout << "Both students have equal GPA." << endl;
    }

    /*
        Here we used relational operators (>, <, ==)
        on individual structure members.

        For example:

            s1.GPA > s2.GPA
            s1.testScore == s2.testScore

        The comparison is done on specific data members,
        NOT on the entire structure at once.
    */

    // Example: Comparing test scores
    if(s1.testScore == s2.testScore)
    {
        cout << "Both students have equal test scores." << endl;
    }
    else
    {
        cout << "Test scores are different." << endl;
    }

    return 0;
}

