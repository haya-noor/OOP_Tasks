#include<iostream>
using namespace std;

class BankAccount
{
protected:
	double balance;
	int AccNum;  //Account Number
public:

	BankAccount()
	{
		balance = 0.0;
		AccNum = 0;
	}
	~BankAccount(){}

	void setter()
	{
		balance = 100000;
	} 

	void getter()
	{
		cout << "\nEnter account number:";
		cin >> AccNum;
		cout << "Enter initial Balance:";
		cin >> balance;
	}

	void deposit_withdraw()
	{
		int option;
		double deposit, withdraw;

		cout << "Do you want to deposit or withdraw?\n 1) Deposit\n2) Withdraw\n";
		cin >> option;
		if (option == 1)
		{
			cout << "Enter amount to deposit:";
			cin >> deposit;

			balance += deposit;
			cout << "New balance is: " << balance << endl;
		}
		else if (option == 2)
		{
			cout << "How much do you want to withdraw?" << endl;
			cin >> withdraw;
			 
			if (balance < 1000)
			{
				cout << "You can't withdraw money because your balance is less than the minimum balance.\n";
			}
			else
			{
				balance -= withdraw;
				cout << "New balance is: " << balance << endl;
			}
		}
	}

	void print()
	{
		cout << "\nAccount Number: " << AccNum << endl;
		cout << "\nBalance: " << balance;
	}
};


class CheckingAccount :public BankAccount
{
protected:
	double interest;
	double service_charges;
	int mini_balance;  //minimum balance

public:

	CheckingAccount() :BankAccount()
	{
		interest = 0.0;
		service_charges = 0.0;
		mini_balance = 0;
	}

	~CheckingAccount(){}

	void setter()
	{
		BankAccount::setter();
		interest = 0.1 * balance;
		service_charges = 0.7 * balance;
		mini_balance = 1000;
	}

	void getter()
	{
		BankAccount::getter();
		BankAccount::deposit_withdraw();
		cout << "Balance after interest rate:";
		balance = balance * interest;
		cout << balance << endl;
	}

	int pays_serviceCharges()
	{
		if (balance < mini_balance)
		{
			cout << "Pay services charges." << endl;
			balance = balance - service_charges;
		}
		return balance;
	}

	void print()
	{
		BankAccount::print();
		cout << "\nCurrent balance: " << balance;
	}
};

class SavingAccount :public BankAccount, CheckingAccount
{
public:

	SavingAccount(){}

	~SavingAccount(){}

	void setter()
	{
		CheckingAccount::setter();
	}

	void getter()
	{
		CheckingAccount::getter();
		CheckingAccount::pays_serviceCharges();
	}

	void print()
	{
		CheckingAccount::print();
	}
};


int main()
{
	SavingAccount sa;
	sa.setter();
	sa.getter();
	sa.print();
}