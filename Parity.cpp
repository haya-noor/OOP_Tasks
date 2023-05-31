
#include <iostream>
using namespace std;

class Parity
{
private:
	int size;
	int *parity;

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
		for (; i < size - 1; i++)
		{
			temp[i] = parity[i];
		}
		delete[] parity;
		temp[i] = num;
		parity = temp;
	}
	void print()
	{
		cout << "The elements are: \n";
		for (int i = 0; i < size; i++)
		{
			cout << parity[i] << " ";
		}
		cout << endl;
	}
	void Delete(int num)
	{
		size--;
		int *temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = parity[i];
		}
		delete[] parity;
		parity = temp;
	}
	int test()
	{
		if (size % 2 == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	~Parity() // destructor
	{
		delete[] parity;
	}
};

int main()
{
	Parity p;
	int choose;
	int num;
	cout << " Choose one of the following:\n";
	cout << " 1) Put\n 2) Print\n 3) Delete\n 4) Test\n 5) Exit\n";
	cin >> choose;
	while (choose != 5)
	{
		switch (choose)
		{
		case 1:
			cout << "Enter a number: ";
			cin >> num;
			p.put(num);
			break;
		case 2:
			p.print();
			break;
		case 3:
			cout << "Enter a number: ";
			cin>>num;
			p.Delete(num);
			break;
		case 4:
			cout << p.test() << endl;
		default:
			break;
		}
		cout << " Choose one of the following:\n";
		cout << " 1) Put\n 2) Print\n 3) Delete\n 4) Test\n 5) Exit\n";
		cin >> choose;
	}
	return 0;
}
