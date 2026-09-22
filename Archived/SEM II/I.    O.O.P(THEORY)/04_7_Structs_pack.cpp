#include<iostream>
using namespace std;
#pragma pack(1)/*As compilers add padding to struct optimizing memory access/ performance. 
                 however, working with binary data, network protocols, or file formats, 
                 exact memory layout is required. pack(1) forces byte-by-byte storage. 
                 Alignment must be a small power of two*/
struct Student
{
  char c1;
  long long int a;
  char c2;
};
#pragma pack() // Always reset packing with pack() after use.

int main()
{
  Student std;
  cout<<sizeof(std)<<endl;
}  

// Padding ensures data members are aligned for efficient memory access. 
// While padding increases memory usage, it improves performance by 
// avoiding misaligned memory accesses.