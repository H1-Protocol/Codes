#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    int regNo;    // 4 bytes
    char* name;   // 4 bytes (on a 32-bit system)
};

int main() {
    Student std1; 

    // Allocate memory for name
    std1.name = new char[24];  
    strcpy(std1.name, "ABCDEF");  // Copying string correctly

    cout << "Size of std1: " << sizeof(std1) << endl;  // Output size of structure
    cout << "Name: " << std1.name << endl;  

    // Free dynamically allocated memory
    delete[] std1.name;

    return 0;
}
