#include <iostream>
using namespace std;
#define size 10

int main() 
{    
    //int size = 10; //Also this
    int arr[size] = {}; // {}  for initilizing all with 0
    int *arrPtr = new int[size];

    cout<<endl;
    for(int i=0; i<size; i++)    
        cout<<arr[i]<<" ";

    for(int i=0; i<size; i++)    
        arrPtr[i] = i+1;

    cout<<endl;
    for(int i=0; i<size; i++)  {
        cout<<*(arrPtr + i)<<" ";
        //cout<<arrPtr[i]<<", ";
    }

    cout<<endl<<*arrPtr;

    cout<<endl<<"Before Deletion: "<<*arrPtr;
    delete[] arrPtr;
    cout<<endl<<"After Deletion: "<<*arrPtr;

    return 0;
}