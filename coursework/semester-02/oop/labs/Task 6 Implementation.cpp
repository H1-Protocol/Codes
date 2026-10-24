#include <iostream>
#include <string>
using namespace std;

/* ---------------------------------------------------------------- */
// --------------------- Class: ElectricityBill -------------------
/* ---------------------------------------------------------------- */
class ElectricityBill {
    private:
        int customerId;
        string customerName;
        int unitsConsumed;

        // Private Helper Function Prototypes
        int validateUnits(int units);
        int calculateRate();
        float calculateTotal();
        float calculateSurcharge();
        float calculateFinalBill();
        string calculateStatus();

    public:
        // Constructor
        ElectricityBill();

        // Setter Function Prototypes
        void setCustomerId(int id);
        void setCustomerName(string name);
        void setUnits(int units);
        void setCustomer(int id, string name, int units);

        // Getter Function Prototypes
        int getCustomerId();
        string getCustomerName();
        int getUnits();
        float getTotal();
        float getSurcharge();
        float getFinalBill();
        string getStatus();

        // User Input Function Prototype
        void takeData();

        // Display Function Prototype
        void displayInfo();
};

/* ---------------------------------------------------------------- */
// ------------------------ Main Function --------------------------
/* ---------------------------------------------------------------- */
int main() {
    ElectricityBill c1;
    c1.takeData();
    c1.displayInfo();
    return 0;
}

/* ---------------------------------------------------------------- */
// ---------------- Private Function Definitions -------------------
/* ---------------------------------------------------------------- */

int ElectricityBill::validateUnits(int units) {
    if (units >= 0) {
        return units;
    } else {
        return 0;
    }
}

int ElectricityBill::calculateRate() {
    if (unitsConsumed < 100) {
        return 50;
    } else {
        return 80;
    }
}

float ElectricityBill::calculateTotal() {
    return unitsConsumed * calculateRate();
}

float ElectricityBill::calculateSurcharge() {
    if (calculateTotal() > 2000) {
        return calculateTotal() * 0.05;
    } else {
        return 0;
    }
}

float ElectricityBill::calculateFinalBill() {
    return calculateTotal() + calculateSurcharge();
}

string ElectricityBill::calculateStatus() {
    if (calculateFinalBill() >= 3000) {
        return "High Consumption";
    } else {
        return "Normal Consumption";
    }
}

/* ---------------------------------------------------------------- */
// ---------------- Public Function Definitions --------------------
/* ---------------------------------------------------------------- */

ElectricityBill::ElectricityBill() {
    customerId = 0;
    customerName = "Not Entered";
    unitsConsumed = 0;
}

void ElectricityBill::setCustomerId(int id) {
    customerId = id;
}

void ElectricityBill::setCustomerName(string name) {
    customerName = name;
}

void ElectricityBill::setUnits(int units) {
    unitsConsumed = validateUnits(units);
}

void ElectricityBill::setCustomer(int id, string name, int units) {
    customerId = id;
    customerName = name;
    setUnits(units);
}

int ElectricityBill::getCustomerId() {
    return customerId;
}

string ElectricityBill::getCustomerName() {
    return customerName;
}

int ElectricityBill::getUnits() {
    return unitsConsumed;
}

float ElectricityBill::getTotal() {
    return calculateTotal();
}

float ElectricityBill::getSurcharge() {
    return calculateSurcharge();
}

float ElectricityBill::getFinalBill() {
    return calculateFinalBill();
}

string ElectricityBill::getStatus() {
    return calculateStatus();
}

void ElectricityBill::takeData() {
    int id, units;
    string name;

    cout << "Enter Customer ID: ";
    cin >> id;

    cout << "Enter Customer Name: ";
    cin >> name;

    cout << "Enter Units Consumed: ";
    cin >> units;

    setCustomer(id, name, units);
}

void ElectricityBill::displayInfo() {
    cout << "========================================" << endl;
    cout << "Customer ID        : " << getCustomerId() << endl;
    cout << "Customer Name      : " << getCustomerName() << endl;
    cout << "Units Consumed     : " << getUnits() << endl;
    cout << "----------------------------------------" << endl;
    cout << "Total Bill         : " << getTotal() << endl;
    cout << "Surcharge          : " << getSurcharge() << endl;
    cout << "Final Bill Amount  : " << getFinalBill() << endl;
    cout << "Bill Status        : " << getStatus() << endl;
    cout << "========================================" << endl;
}

