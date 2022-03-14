#include<iostream>
using namespace std;

class Heater
{
private:
	int temperature;
public:
	Heater()
	{
		int t = 15;
		temperature = t;
		cout << "Temperature = " << t << endl;
	}
	~Heater()
	{
		cout << "I'm the destructor Hahaha.\n";
	}
	void warmer()
	{
		temperature += 5;
	}
	void cooler()
	{
		temperature -= 5;
	}
	void accessor()
	{
		cout << "Temperature = " << temperature << endl;
	}
};
int main()
{
	Heater h;
	int choice;
	cout << "1)Increase Temp\n2)Decrease Temp.\n";
	cout << "Enter your choice:";
	cin >> choice;
	switch (choice)
	{
	case 1:
		h.warmer();
		h.accessor();
		cout << endl;
		break;
	case 2:
		h.cooler();
		h.accessor();
		cout << endl;
		break;
	}
}