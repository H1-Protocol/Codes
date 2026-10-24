#include <iostream>
#include <ctime>
using namespace std;

int main(){
    cout << endl<< endl<< endl<< endl;

    srand(time(0));
    int Ran_num = rand() % 5 + 1;

 switch(Ran_num){

    case 1: cout << "Frei das milch mann mit hitler, und hirito\n";
    break;
    case 2: cout << "Du Kannen Pet Die Katze\n";
    break;
    case 3: cout << "Leibe\n";
    break;
    case 4: cout << "Sie Bist Einen Criminal, Herr...\n";
    break;
    case 5: cout << "You Will Be K*LLED!!\n   schelt pferd!! \n";

 }
   return 0;
}