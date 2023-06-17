

#include <iostream>
#include <string>
using namespace std;

class Person
{
	string comp_uni;
	string comp;
	string uni;

public:
	Person()
	{
		cout << "Enter competition and University name: ";
		getline(cin, comp_uni);
		tokenize(comp_uni, comp, uni);
	}
	void tokenize(string comp_uni, string &comp, string &uni)
	{
		comp = "";
		uni = "";
		int i;
		for (i = 0; i < comp_uni.length(); i++)
		{
			if (comp_uni[i] != ' ')
				comp += comp_uni[i];
			else
				break;
		}
		for (i++; i < comp_uni.length(); i++)
		{
			uni += comp_uni[i];
		}
	}
	friend class Coordinator;
};

class Coordinator
{
	Person p1;
	Person p2;

public:
	void RoommateSelection()
	{
		int length1 = p1.comp.length();
		int length2 = p2.comp.length();
		if (p1.uni == p2.uni)
		{
			cout << "P1 and P2 are roommates, room number is " << (length1 > length2 ? length1 : length2);
		}
		else
		{
			cout << "P1 and P2 are not roommates." << endl;
		}
	}
};

int main()
{
	Coordinator c;
	c.RoommateSelection();
	return 0;
}
