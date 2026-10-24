#include <iostream>
#include <ctime>

using namespace std;

int main(){
int num, guess;

srand(time(0));


while(guess!=1,2,3,4,5){


num = rand() % 5 + 1;
cout << endl<< endl << "========Guess Anything Between========"<<endl<<"    ===========1 and 5===========" << endl<< endl;
cin >> guess;

if(guess == num){cout << endl << endl << endl;
cout << "You an SmartAss Now";}
else {cout << endl << endl << endl;
cout << "You DUI DumbFuck, Do It AGAIN!!!";}

cout << endl << endl << endl;
}
    return 0;
}