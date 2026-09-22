#include <iostream>
using namespace std;

int a = 6;

int add(int &a, int b=10){

    return a+b;
}

int main(){
    

cout << "No Operator : " << add(a) << endl;

cout << "Operator    : " << add(a, 97) << endl;
int a = 77;

cout << "New Operator    : " << add(a, 97) << endl;



return 0;
    }