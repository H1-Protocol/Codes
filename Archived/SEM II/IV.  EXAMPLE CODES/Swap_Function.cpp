#include <iostream>
using namespace std;


void swap(int &a, int &b){

int temp;
temp=a;
a=b;
b=temp;
}

int main(){

int x=5, z=10;
cout<<x<<" "<<z<<endl;
swap(x,z);
cout<<x<<" "<<z;

return 0;
}

 