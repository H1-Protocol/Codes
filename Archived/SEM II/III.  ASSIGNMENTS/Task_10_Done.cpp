 #include <iostream>
 #include <fstream>
 using namespace std;

class Chaser{
    
public:
    string make;         //Make is used for cars
    string Model;
    string chasis;
    int cyl;
    int hp;
    double capacity;

void display(){
    cout << "\n\nMake   : " << make;
    cout << "\nModel  : " << Model;
    cout << "\nChasis : " << chasis;
    cout << "\nEngine : " << capacity <<" litre (1jz-gte)";
     cout << "\nHP     : " << hp <<"hp";

    cout << "\n\n                The " <<make<< " " << Model << " has an of " << capacity << "l Inline-"<<cyl<<" engine. Which produces " <<hp<<" horsepower on tune. Which is a lot, ";
cout << "\n                                   Extremely High Potential 'Fun' Car, and you MUST for Yearn it.\n\n";
    

}

    
};
// Chaser is not part of task

class vehicle {            //Base Class
    private: 
    int registrationNumber;
    string engineNumber;

    protected:
    int year;
    string make, model;         //Make is used for cars

    public:
    string companyName = "Indus Motors";

void setVehicleInfo(int regNum, string engNum){
    this->registrationNumber = regNum;
    this->engineNumber = engNum;
}    
void setBasicInfo(string mk, string mdl, int yr) {
    this->make = mk;
    this->model = mdl;
    this->year = yr;
}

void displayVehicleInfo(){
    cout << "\nMake                 : " << make;
    cout << "\nModel                : " << model;
    cout << "\nYear                 : " << year;
    cout << "\nRegistration Number  : " << registrationNumber;
    cout << "\nEngine Number        : " << engineNumber;
    cout << "\nSold by              : " << companyName << endl<< endl<< endl;
}

};


class car : public vehicle{

// string make = "Nissan";
// string model = "Skyline R34 GTR";
// int year = 1999;
public:
int numberOfDoors;// = 2;
string fuelType; //= "Kerosene";
string transmissionType; //= "Manual 7-Speed";

void displayCarInfo(){
    cout << "------------>>>Car Spec Sheet<<<-------------\n";
    cout << "\nMake   : " << make;
    cout << "\nModel  : " << model;
    cout << "\nYear   : " << year;
    cout << "\nDoors  : " << numberOfDoors; 
    cout << "\nFuel   : " << fuelType;
    cout << "\nTrans  : " << transmissionType <<endl<<endl;
}
};

class motorcycle : public vehicle{

public:
double engineCapacity;
string type;       //(Sport / Cruiser / Standard)
bool hasABS;

void displayMotorcycleInfo(){
    cout << "\n\n---------->>Motorcycle Spec Sheet<<----------\n";
    cout << "\nMake   : " << make;
    cout << "\nModel  : " << model;
    cout << "\nYear   : " << year;
    cout << "\nType   : " << type;
    cout << "\nEngine : " << engineCapacity << " litre";
    cout << "\nABS    : " << hasABS <<" (0 for No, 1 for Yes)" <<endl<<endl ;
}
};


int main(){

car r34;

//r34.make = "Nissan Skyline";
//r34.model = "R34 GTR";
r34.numberOfDoors = 2;
//r34.year = 1999;
r34.fuelType = "Petrol";
r34.transmissionType = "Manual 6-Speed";

r34.setVehicleInfo(3401999,"RB26DETT-034567");
r34.setBasicInfo("Nissan","Skyline R34 GTR",1999);
r34.displayCarInfo();
r34.displayVehicleInfo();



motorcycle r12;

//r12.make = "BMW";
//r12.model = "R75";
//r12.year = 1941;
r12. engineCapacity = 0.75;
r12.type = "Cruiser";
r12.hasABS = false;

r12.setVehicleInfo(4895428, "BMW-ENG-75");
r12.setBasicInfo("BMW","R75",1941);
r12.displayMotorcycleInfo();
r12.displayVehicleInfo();

//                     TASK_ENDED

cout << endl<< endl<< endl<< endl<< endl<< endl;
Chaser one;

one.make = "Toyota";
one.Model = "Mark II";
one.chasis = "JZX90";
one.cyl = 6;
one.hp = 396;
one.capacity = 2.5;
//one.display();


 return 0; 
}