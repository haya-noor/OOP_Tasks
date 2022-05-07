#include<iostream>
#include<string>
using namespace std;

class vehicle
{
protected:
	int no_of_tires;
	int length;
	int no_of_seats;

public:
	vehicle(int t, int s, int l)
	{
		no_of_tires = t;
		length = l;
		no_of_seats = s;
	}

	~vehicle(){}

	void set_value(int t, int s, int l)
	{
		no_of_tires = t;
		no_of_seats = s;
		length = l;
	}

	virtual void get_value()
	{
		cout << "\nEnter num of tires:";
		cin >> no_of_tires;
		cout << "\nEnter length/size in feet:";
		cin >> length;
		cout << "\nEnter num of seats:";
		cin >> no_of_seats;
	}
	virtual void print() = 0;
};


class car :public vehicle
{
protected:
	string color;

public:
	car(int t, int s, int l, string c) :vehicle(t, s, l)
	{
		color = c;
	}

	~car(){}

	void set_value(int t, int s, int l, string c)
	{
		vehicle::set_value(t, s, l);
		color = c;
	}

	virtual void get_values()
	{
		vehicle::get_value();
		cout << "\nEnter color:";
		cin >> color;

	}
	virtual void print()
	{
		cout << "No of tires: " << no_of_tires << endl;
		cout << "No of seats: " << no_of_seats << endl;
		cout << "Length: " << length << endl;
		cout << "Color: " << color << endl;
	}
};

class vitz :public car
{
private:
	string model;
	int plate_num;

public:
	vitz(int t, int s, int l, string c, string m, int p) :car(t, s, l, c)
	{
		model = m;
		plate_num = p;
	}

	~vitz(){}

	void set_value(int t, int s, int l, string c, string m, int p)
	{
		car::set_value(t, s, l, c);
		model = "m";
		plate_num = p;
	}
	virtual void get_value()
	{
		car::get_value();
		cout << "Enter model of the car:";
		cin >> model;
		cout << "Enter number plate:";
		cin >> plate_num;
	}
	virtual void print()
	{
		car::print();
		cout << "Model num:" << model << endl;
		cout << "Plate num:" << plate_num << endl;
	}
};

int main()
{

	cout << "Enter all the values positive.\n";
	vehicle* ptr;
	vitz v(4, 2, 21, "grey", "cool", 221);
	ptr = &v;

	ptr->get_value();
	ptr->print();

	return 0;

}