#include<iostream>
using namespace std;

struct Student
{
  long long int a;  // Recommended in descending order of size
  char c2; 
  char c1;  // Padding of 6 bytes are added
};


int main()
{
  Student std;
  cout<<sizeof(std)<<endl;
}