/*
/ BANKING SYSTEM
/ 
/ A simple program that uses a class to hold user banking information and defines constructors, destructors, getters,
/ setters and more.
/ Author: Abhinav Rayamajhi
*/

#include <iostream>
#include <cmath>

using namespace std;

// Base class to hold the bank account details
class BankAccount
{

private: 
	// All the private variables that hold the user information
	string mUserName;
	int mAccountNumber;
	string mAccountType;
	int mPinNumber;
	double mAccountAmount;

public:
	// Default Constructor
	BankAccount()
		:mUserName ("Default"),	mAccountNumber (0), mAccountType ("Checking"), mPinNumber (0), mAccountAmount (0.0) {}

	// Constructor using member initialized lists
	BankAccount(string mUserName, int mAccountNumber, string mAccountType, int mPinNumber, double mAccountAmount)
		:mUserName(mUserName), mAccountType(mAccountType), mPinNumber(mPinNumber)
	{
		// Short hand if statement to make sure user does not input negative account numbers, abs function turns
		// negative account numbers to positive
		this->mAccountNumber = mAccountNumber < 0 ? abs(mAccountNumber) : mAccountNumber;

		// If statement to make sure user does not input negative amount, set it to 0 if user inputs negative
		this->mAccountAmount = mAccountAmount < 0 ? 0 : mAccountAmount;
	}

	// Destructor
	~BankAccount()
	{
		cout << "\n\n" << mUserName << "'s account has been deleted.";
	}

	// Getters
	string getName() 
	{ 
		return mUserName; 
	}

	int getAccountNumber() 
	{ 
		return mAccountNumber; 
	}

	string getAccountType() 
	{ 
		return mAccountType; 
	}

	int getPinNumber() 
	{ 
		return mPinNumber; 
	}

	double getAccountAmount() 
	{ 
		return mAccountAmount; 
	}

	// Setters
	void setName(string userName) 
	{ 
		mUserName = userName; 
	}

	void setAccountNumber(int accountNumber) 
	{
		// If statement to make sure user does not input negative account number
		mAccountNumber = accountNumber < 0 ? abs(accountNumber) : accountNumber; 
	}

	void setAccountType(string accountType)
	{
		mAccountType = accountType;
	}

	void setPinNumber(int pinNumber)
	{
		mPinNumber = pinNumber;
	}

	void setAccountAmount(double accountAmount)
	{
		// If statement to make sure user does not input negative account amount
		mAccountAmount = accountAmount < 0 ? 0 : accountAmount;
	}

	// Function to display all user information except pin number
	void viewAccountDetails()
	{
		cout << "\nUser Name: " << mUserName;
		cout << "\nAccount Number: " << mAccountNumber;
		cout << "\nAccount Type: " << mAccountType;
		cout << "\nAccount Amount: " << mAccountAmount << "\n";
	}

	// Function to check for low balance
	void checkForLowBalance()
	{
		// If balance is lower than 50 we output a warning message
		if (mAccountAmount < 50)
		{
			cout << "Hey your bank balance seems to have dropped below $50. You will incur additional fees for " <<
				"failure to maintain an account at or above $50.\nAdd additional balance today to prevent said fees.";
		}
	}
};

int main()
{
	cout << "SUPER BANKING SYSTEM\n";

	// Create a bank account for user 
	BankAccount user("Abhinav", 1, "Checking", 1000, 1000);

	// Print current balance
	user.viewAccountDetails();

	// Set account amount to negative
	user.setAccountAmount(-900);
	cout << "\nBalance was updated.";

	// Verify that 0 was saved for account amount instead of negative number
	cout << "\nCurrent balance: " << user.getAccountAmount() << "\n\n";

	// Print out the low balance warning now that our balance is 0 which is < 50
	user.checkForLowBalance();
}
