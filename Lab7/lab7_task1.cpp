#include<iostream>
using namespace std;

class person
{
	string name;
	int regNo;
	static int count;
public:
	person()
	{
		name = " ";
		regNo = 0;
		count++;
	}
	friend ostream& operator<(ostream& out, person p)
	{
	}
	friend istream& operator>(istream& in, person p)
	{
		cout << "Enter Name and ID:";
		in >> p.name >> p.regNo;
		return in;
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
	friend ostream& operator<<(ostream& out, date& d)
	{
	}
	friend istream& operator>(istream& in, date& d)
	{
		cout << "Enter joining date(yy/mm/dd):";
		in >> d.year >> d.month >> d.day;
		return in;
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
	person p1, p2;
	cin>>p1;
	cout<<p1;
	cin>>p2;
	cout<<p2;
}
