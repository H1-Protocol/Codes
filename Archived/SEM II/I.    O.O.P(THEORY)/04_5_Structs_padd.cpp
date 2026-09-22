#include<iostream>
using namespace std;

// By Default, compilers add padding to struct 
// optimizing memory access and performance. 
struct Student
{
  char c1;  // Padding are added make the size multiple of the largest alignment (8 bytes for long long int).
  long long int a;  // 8 Bytes
  char c2; // Padding
};


int main()
{
  Student std;
  cout<<sizeof(Student)<<endl;
}  

// Padding ensures data members are aligned for efficient memory access. 
// While padding increases memory usage, it improves performance by 
// avoiding misaligned memory accesses.