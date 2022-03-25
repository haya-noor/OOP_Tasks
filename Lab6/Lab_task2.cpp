#include<iostream>
#include<string>
using namespace std;

class person
{
private:
	string comp, uni;    //compitation
public:
	person()
	{
		cout << "Enter competitation AND university name:";
		getline(cin, comp);

		cin.ignore();

		getline(cin, uni);
	}
	friend class coordinator;
};

class coordinator
{
private:
	person p1;
	person p2;
public:
	void get_length()
	{
		string l1 = p1.comp;
		string l2 = p2.comp;
		if (l1.length() >= l2.length())
		{
			cout << l1.length();
		}
		else if(l2.length() >= l1.length())
		{
			cout << l2.length();
		}
		else if (l2.length() == l1.length())
		{
			cout << l1.length();
		}
	}
	void displayResult()
	{
		if (p1.uni == p2.uni)
		{
			cout << "Message from coordinator that person1 and person2 are roomates and room number is ";
			get_length();
		}
		else
		{
			cout << "Person1 and person2 are not roomates.\n";
		}
	}
};
int main()
{
	coordinator c;
	c.displayResult();

	return 0;
}