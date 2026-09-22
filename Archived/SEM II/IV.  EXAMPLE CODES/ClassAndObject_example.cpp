 #include <iostream>
 #include <fstream>
 using namespace std;

class Car{
    
public:
    string make;
    string Model;
    int hp;
    double capacity;

void display(){
    cout << "\nMake   : " << make;
    cout << "\nModel  : " << Model;
    cout << "\nHP     : " << hp <<"hp";
    cout << "\nEngine : " << capacity <<"l (1jz-gte)";

}
void carfunctions(){
    cout << endl << "\nThe 1995 " << make << " " << Model << " with " << hp << " horsepower and an engine capacity of " << capacity << "l."
    << " Is an Extremely High Potential 'Fun' Car, you MUST for Yearn it.";
}
    
};
int main(){

Car one;

one.make = "Toyota";
one.Model = "Mark II(JZX90)";
one.hp = 396;
one.capacity = 2.5;


one.display();
one.carfunctions();

 return 0; 
}