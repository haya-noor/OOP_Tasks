#include<iostream>
#include<string>
using namespace std;

class My_Father
{
protected:
	string name;
	string hair_color, eye_color;

public:
	My_Father(string n, string hc, string ec)
	{
		name = " ";
		hair_color = " ";
		eye_color = " ";
	}
	~My_Father(){}

	void setter(string n, string hc, string ec)
	{
		name = n;
		hair_color = hc;
		eye_color = ec;
	}

	void getter()
	{
		cout << "\nEnter name:";
		cin >> name;
		cout << "Enter hair color:";
		cin >> hair_color;
		cout << "Enter eye color:";
		cin >> eye_color;
	}

};

class My_Mother
{
protected:
	string name;
	string hair_color, eye_color;

public:
	My_Mother(string n, string hc, string ec)
	{
		name = n;
		hair_color = hc;
		eye_color = ec;
	}

	~My_Mother(){}

	void setter(string n, string hc, string ec)
	{
		name = n;
		hair_color = hc;
		eye_color = ec;
	}
	void getter()
	{
		cout << "\nEnter name:";
		cin >> name;
		cout << "Enter hair color:";
		cin >> hair_color;
		cout << "Enter eye color:";
		cin >> eye_color;
	}
};

class My_Self :public My_Father
{
protected:
	string education;
	int age;

public:
	My_Self(string n, string hc, string ec, string e, int a) :My_Father(n, hc, ec)
	{
		education = " ";
		age = 0;
	}

	~My_Self(){}

	void setter(string n, string hc, string ec, string e, int a)
	{
		My_Father::setter(n, hc, ec);
		education = e;
		age = a;
	}
	void getter()
	{
		My_Father::getter();
		cout << "Enter education:";
		cin >> education;
		cout << "Enter age:";
		cin >> age;
	}
};

class My_Sister :public My_Father, My_Mother
{
protected:
	string eduaction;
	int age;

public:
	My_Sister(string n, string hc, string ec, string e, int a) :My_Father(n, hc, ec), My_Mother(n, hc, ec)
	{
		eduaction = " ";
		age = 0;
	}

	~My_Sister(){}

	void settter(string n, string hc, string ec, string e, int a)
	{
		My_Mother::setter(n, hc, ec);
		eduaction = e;
		age = a;
	}
	void getter()
	{
		My_Mother::getter();
		cout << "Education:" << eduaction << endl;
		cout << "Age: " << age << endl;
	}
};

int main()
{

	cout << "Enter all the values positive.\n";
	My_Self s("Monica", "black", "black", "Phd", 35);
	s.getter();

	My_Sister sis("Rachel", "blond", "blue", "phd", 40);
	sis.getter();

}