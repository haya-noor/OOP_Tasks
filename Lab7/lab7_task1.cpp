
#include<iostream>
using namespace std;

class person
{
	string name;
	int id;
	static int count;
public:
	person()
	{
		name = " ";
		id = 0;
		count++;
	}
	friend ostream& operator<<(ostream& out, person& p)
	{
        out<<p.name<<" "<<p.id<<endl;
        return out;
	}
	friend istream& operator>>(istream& in, person& p)
	{
		cout << "Enter Name and ID:";
		in >> p.name >> p.id;
		return in;
	}
    static int counter()
    {
        return count;
    }
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
	friend ostream& operator<<(ostream& out, date& d)
	{
        out<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
        return out;
	}
	friend istream& operator>>(istream& in, date& d)
	{
		cout << "Enter joining date(yyyy mm dd):";
		in >> d.year >> d.month >> d.day;
		return in;
	}
	bool operator <(date& d)
	{
		if (this->year !=  d.year)
            return this->year < d.year;
        else if(this->month != d.month)
            return this->month < d.month;
		else
			return this->day < d.day;
	}
	friend class person;
};

int main()
{
	person p1, p2;
	date d1, d2;

    cout<<"\nEnter person No. 1 Data:  \n";
    cin>>p1>>d1;
    
    cout<<"\nEnter person NO. 2 Data: \n";
    cin>>p2>>d2;

    if(d1 < d2)
        cout<< p1 <<" is senior to "<< p2 <<" since "<< d1 <<" is earlier to "<< d2 << endl;
    else 
        cout<< p2 <<" is senior to "<< p1 <<" since "<< d2 <<" is earlier to "<< d1 << endl; 

    cout<<"Total persons: "<< person::counter <<endl;
    return 0;      
}
