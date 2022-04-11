#include<iostream>
using namespace std;

class person
{
	string name1;
	string name2;
	int regNo1;
	int regNo2;
	static int count;
public:
	person()
	{
		name1 = name2 = " ";
		regNo1 = regNo2 = 0;
		count++;
	}
	friend ostream& operator<(ostream& out, person p)
	{
	}
	friend istream& operator>(istream& in, person p)
	{
		cout << "Person No. 1:\n";
		cout << "Enter Name and ID:";
		in >> p.name1 >> p.regNo1;
		cout << endl;
		cout << "Person No. 2:\n";
		cout << "Enter Name and ID:";
		in >> p.name2 >> p.regNo2;
	}
	friend class date;
};
int person::count = 0;

class date
{
	int day, month, year;
public:
	person p;
	date()
	{
		day = month = year = 0;
	}
	~date(){}
	//positive values******
	void positive()
	{
		if (day < 0 && day > 30 || month < 1 && month >12)
		{
			cout << "Please enter positive and within limit values.\n";
		}
	}
	//**********
	friend ostream& operator<<(ostream& out, date& d)
	{
	}
	friend istream& operator>(istream& in, date& d)
	{

		cout << "Enter joining date(yy/mm/dd):";
		in >> d.year >> d.month >> d.day;
	}
	bool operator <(date& d)
	{
		if (this->year < d.year)
		{
			cout << d.p.name1 << " is junior to " << d.p.name2 << " because " << this->year << "-" << this->month << "-" << this->day << " is earlier than";
			cout << d.year << "-" << d.month << d.day << endl;
		}
		else
		{
			cout << d.p.name1 << " is senior to " << d.p.name2 << " because " << this->year << "-" << this->month << "-" << this->day << " is earlier than";
			cout << d.year << "-" << d.month << d.day << endl;
		}
	}
	friend class person;
};

int main()
{
	int year, month, day;
	//string p1;
	date d1(int year, int month, int day);

	date d2(int year, int month, int day);

	person p1;
}