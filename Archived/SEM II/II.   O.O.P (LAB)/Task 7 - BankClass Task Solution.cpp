#include<iostream>
#include<string>
using namespace std;

class BankAccount{

	private:
		// ---------------- STATE OF OBJECT (DATA MEMBERS) ----------------
		int accountNumber;
		string accountHolderName;
		string accountStatus;
		int balance;

		// Static variable to count how many accounts are created
		static int totalAccounts;


		// ---------------- PRIVATE HELPER FUNCTIONS ----------------
		// These are used internally inside the class

		bool validateAmount(int amount) const;   // checks if amount is positive
		bool validateWithdraw(int amount) const; // checks if withdrawal is possible
		void updateStatus();                     // updates account status


	public:

		// ---------------- CONSTRUCTORS ----------------
		BankAccount();
		BankAccount(int accNum, string name, int bal);


		// ---------------- MEMBER FUNCTIONS ----------------
		void setInitialDetails(int accNum, string name, int bal);

		void deposit(int amount);
		void withdraw(int amount);

		void displayAccountDetails() const;


		// ---------------- GETTER FUNCTIONS (CONST) ----------------
		int getAccountNumber() const;
		string getAccountHolderName() const;
		string getAccountStatus() const;
		int getBalance() const;


		// ---------------- STATIC FUNCTION ----------------
		static void showTotalAccounts();
};


// ---------------- STATIC VARIABLE INITIALIZATION ----------------
int BankAccount::totalAccounts = 0;



// ---------------- MAIN FUNCTION ----------------
int main(){

	BankAccount account1;

	account1.setInitialDetails(99848574,"Kaisar Khan",5000);

	account1.displayAccountDetails();

	account1.deposit(5000);
	account1.deposit(2000);

	account1.withdraw(1500);

	account1.deposit(1000);

	account1.displayAccountDetails();


	cout << endl;


	BankAccount account2(85757383,"Mahad",6000);

	account2.displayAccountDetails();


	cout << endl;

	BankAccount::showTotalAccounts();


	return 0;
}



// ---------------- DEFAULT CONSTRUCTOR ----------------
// Initializes object with default values

BankAccount::BankAccount(){

	this->accountNumber = 0;
	this->accountHolderName = "Not Set";
	this->accountStatus = "Normal";
	this->balance = 0;

	totalAccounts++;
}



// ---------------- PARAMETERIZED CONSTRUCTOR ----------------
// Used when user provides account details at object creation

BankAccount::BankAccount(int accNum, string name, int bal){

	this->accountNumber = accNum;
	this->accountHolderName = name;

	// Initial balance cannot be negative
	if(bal < 0)
		this->balance = 0;
	else
		this->balance = bal;

	updateStatus();

	totalAccounts++;
}



// ---------------- SET INITIAL DETAILS ----------------
// Used to assign account information

void BankAccount::setInitialDetails(int accNum, string name, int bal){

	this->accountNumber = accNum;
	this->accountHolderName = name;

	// Balance validation
	if(bal < 0)
		this->balance = 0;
	else
		this->balance = bal;

	updateStatus();
}



// ---------------- VALIDATE AMOUNT ----------------
// Negative deposits or withdrawals are not allowed

bool BankAccount::validateAmount(int amount) const{

	if(amount <= 0)
		return false;
	else
		return true;
}



// ---------------- VALIDATE WITHDRAW ----------------
// Withdrawal allowed only if balance is sufficient

bool BankAccount::validateWithdraw(int amount) const{

	if(amount <= this->balance)
		return true;
	else
		return false;
}



// ---------------- UPDATE ACCOUNT STATUS ----------------
// If balance < 1000 ? Low Balance
// If balance >= 1000 ? Normal

void BankAccount::updateStatus(){

	if(this->balance < 1000)
		this->accountStatus = "Low Balance";
	else
		this->accountStatus = "Normal";
}



// ---------------- DEPOSIT FUNCTION ----------------

void BankAccount::deposit(int amount){

	if(validateAmount(amount) == false){
		cout << "Invalid Deposit Amount." << endl;
		return;
	}

	this->balance = this->balance + amount;

	updateStatus();
}



// ---------------- WITHDRAW FUNCTION ----------------

void BankAccount::withdraw(int amount){

	if(validateAmount(amount) == false){
		cout << "Invalid Withdrawal Amount." << endl;
		return;
	}

	if(validateWithdraw(amount) == false){
		cout << "Withdrawal Failed. Insufficient Balance." << endl;
		return;
	}

	this->balance = this->balance - amount;

	updateStatus();
}



// ---------------- GETTER FUNCTIONS ----------------

int BankAccount::getAccountNumber() const{
	return this->accountNumber;
}

string BankAccount::getAccountHolderName() const{
	return this->accountHolderName;
}

string BankAccount::getAccountStatus() const{
	return this->accountStatus;
}

int BankAccount::getBalance() const{
	return this->balance;
}



// ---------------- DISPLAY ACCOUNT DETAILS ----------------

void BankAccount::displayAccountDetails() const{

	cout << "\n------------------ | Account Details | ------------------" << endl;

	cout << "Account Holder : " << getAccountHolderName() << endl;
	cout << "Account Number : " << getAccountNumber() << endl;
	cout << "Account Balance: " << getBalance() << endl;
	cout << "Account Status : " << getAccountStatus() << endl;

}



// ---------------- STATIC FUNCTION ----------------

void BankAccount::showTotalAccounts(){

	cout << "* Total Accounts: " << totalAccounts << endl;
}
