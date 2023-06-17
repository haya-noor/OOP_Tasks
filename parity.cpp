
#include<iostream>
using namespace std;

class Parity
{
	private:
	int size;
	int* parity;

	public:
	Parity()
	{
		size = 0;
		parity = new int[size];
		*parity = 0;
	}
    
	void put(int num)
	{
		size++;
		int *temp = new int[size];
		int i = 0;
		for(; i<size-1; i++)
		{
			temp[i] = parity[i];
		}
		delete[] parity;
		temp[i] = num;
		parity = temp;
	}
	void print()
	{
		for(int i = 0; i<size; i++)
		{
			cout<<parity[i]<<" ";
		}
	}
	void deletenum(int num)
	{
		size--;
		int *temp = new int[size];
		for(int i = 0; i<size; i++)
		{
			temp[i] = parity[i];
		}
		delete[] parity;
		parity = temp;
	}
	void test(int num)
	{
		if(num % 2 == 0)
		{
			cout<<"Even";
		}
		else
		{
			cout<<"Odd";
		}
		cout<<endl;
	}
};
 
int main()
{
	Parity p;
	int choice, num;
	cout << "1)Input a number.\n2)Print the number.\n3)Delete the number.\n4)Test for even and odd.\n5)Exit\n";
	while (choice != 5)
	{
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Input a number:";
			cin >> num;
			p.put(num);
			cout << endl;
			break;
		case 2:
			p.print();
			cout << endl;
			break;
		case 3:
			cout<<"Enter num: ";
			cin>>num;
			p.deletenum(num);
			break;
		case 4:
			p.test(num);
			break;
		case 5:
			break;
		}
	}
}
