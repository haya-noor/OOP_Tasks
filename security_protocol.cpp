#include<iostream>
#include<string>
using namespace std;

class entry
{
private:
	int id;

	string name;
	string rank;
	static int counter;

public:
	//Constructor
	entry()
	{
		id = 0;
		name = " ";
		rank = " ";
		counter++;
	}
	//Destructor
	~entry()
	{
	}
	//Officer information
	void officer_info()
	{
		cout << "Enter id:";
		cin >> id;
		cin.ignore();

		cout << "Enter name:";
		getline(cin, name);

		cout << "Enter rank:";
		getline(cin, rank);
	}

	//Check officer id whether its a palindrome or not
	void checkid()
	{
		int n, digit, reverse = 0;
		n = id;
		while (n != 0)
		{
			digit = n % 10;
			reverse = (reverse * 10)+ digit;
			n =  n/ 10;
		} 

		if (id == reverse)
		{
			//Palindrome
			cout << "The officer is not allowed to enter the restricted area.\n";
		}
		else
		{
			//Not a palindrome
			cout << "The officer is allowed to enter the restricted area.\n";
		}
	}
	//Get total number of officers
	static int get_count()
	{
		return counter;
	}

};
//initialization of the static variable
int entry::counter = 0;

int main()
{
	entry e;
	int choice;
	do
	{
		cout << "----Select----\n";
		cout << "1)Enter ID of the officer.\n2)Get total number of officer.\n3)Exit.\n";
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			e.officer_info();
			e.checkid();
			break;
		case 2:
			entry::get_count();
			break;
		case 3:
			break;
		}
	} while (choice != 3);
}
