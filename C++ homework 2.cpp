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
	{
		mUserName = "Default";
		mAccountNumber = 0;
		mAccountType = "Checking";
		mPinNumber = 0;
		mAccountAmount = 0.0;
	}

	// Destructor
	~BankAccount()
	{
		cout << mUserName << "'s account has been deleted.";
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

	void setAccountNumber(double accountAmount)
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
		cout << "\nAccount Amount: " << mAccountAmount << "\n\n";
	}

	// Function to check for low balance
	void checkForLowBalance()
	{
		// If balance is lower than 50 we output a warning message
		if (mAccountAmount < 50)
		{
			cout << "Hey your bank balance seems to have dropped below $50. You will incur additional fees for " <<
				"failure to maintain an account at or above $50. Add additional balance today to prevent said fees.";
		}
	}

	// Function to verify pin number
	bool checkPin()
	{
		// Temporary variable to hold user input
		int tempPin;

		// Ask the user for pin number
		cout << "\nEnter the pin number for " << mUserName << ": ";
		cin >> tempPin;

		// If pin matches return true else return false
		if (tempPin == mPinNumber)
		{
			return true;
		}
		else
		{
			// If user inputs non integer characters, we have to clear the flag on cin and ignore those characters
			cin.clear();
			cin.ignore(1024, '\n');
			
			return false;
		}
	}

	// Function to deposit money

	// Function to withdraw money

	// Function to update balance in member initializer list
	int update()
	{
		// Temporary variable to store user input
		int tempBalance;

		// Ask user for balance
		cout << "\nEnter starting balance for account: ";
		cin >> tempBalance;

		// If user input balance is positive we return it
		if (tempBalance > 0)
		{
			return tempBalance;
		}
		// Else we return 0 as our starting balance
		else
		{
			// If user inputs non integer characters, we have to clear the flag on cin and ignore those characters
			cin.clear();
			cin.ignore(1024, '\n');

			return 0;
		}
	}

	// Constructor using member initialized lists
	BankAccount(string userName, int accountNumber, string accountType, int pinNumber)
		:mUserName(userName), mAccountType(accountType), mPinNumber(pinNumber), mAccountAmount(update())
	{
		// Short hand if statement to make sure user does not input negative account numbers, abs function turns
		// negative account numbers to positive
		mAccountNumber = accountNumber < 0 ? abs(accountNumber) : accountNumber;
	}

};

int main()
{
	cout << "SUPER BANKING SYSTEM\n";

	// Create a bank account for user and ask for starting balance
	BankAccount user("Abhinav", 1, "Checking", 1000);

	// Variable that stores user choice
	int userChoice;

	// Main program loop. Displays a menu with choices for user and calls the required functions based on choice
	do
	{
		cout << "\n1. View Account Details\n"
			<< "2. Deposit Money\n"
			<< "3. Withdraw Money\n"
			<< "4. Exit\n";
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			user.viewAccountDetails();
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			cout << "\nThank you for using this banking system. Goodbye!";
			break;

		default:
			cout << "\nInvalid option. Try again.\n";
			/*
			/ The following statements are required to clear the input stream if user inputs a non-integer. Otherwise
			/ characters will remain in stream and cause an infinite loop. Max number of characters ignored from the
			/ stream is set to 1024, which should be sufficient for most user inputs. 
			*/
			cin.clear();
			cin.ignore(1024, '\n');
			break;
		}
		cout << '\n';
	} while (userChoice != 4);
}
