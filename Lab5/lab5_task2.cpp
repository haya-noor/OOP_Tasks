#include<iostream>
using namespace std;
class parity
{
public:
	int arrsize;
	int* arr;
	parity() //Constructor
	{
		 arrsize = 1;  //Already one element present in the array.
		 arr = new int[arrsize];
	}
	~parity()  //Destructor
	{}
	void put(int num)
	{
		cout << "Array element: " << endl;
		arr[0]=1;                   //first element in the array
		cout << arr[0] << endl;     
		cout << "Another element is added, so new array is : " << endl;
		++arrsize;
		int* temp = new int[arrsize];
		for (int i = 0; i < arrsize; i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		temp[arrsize - 1] = num;    //put num at the last index of the new arr, otherwise it would result garbage value.
		arr = temp;
	}
	void print()
	{
		for (int i = 0; i < arrsize; i++)
		{
			cout << arr[i]<<" ";
		}
		cout << endl;
	}
	void deletenum()
	{
		--arrsize;
		int* temp1 = new int[arrsize];
		for (int i = 0; i < arrsize ; i++)
		{
			temp1[i] = arr[i];
		}
		delete[]arr;
		arr = temp1;
	}
	int test(int num)
	{
		if (num % 2 == 0)
		{
			cout << "Entered number is even.\n";
			return 1;  //true
		}
		else
			cout << "Entered nuber is odd.\n";
			return 0;  //false
	}
};
int main()
{
	parity p;
	int choice, num;
	cout << "1)Input a number.\n2)Print the number.\n3)Delete the number.\n4)Test for even and odd.\n5)Exit\n";
	while (true)
	//do
	{
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Input a number:";
			cin >> num;
			p.put(num);
			p.print();
			cout << endl;
			break;
		case 2:
			p.print();
			cout << endl;
			break;
		case 3:
			
			p.deletenum();
			p.print();
			cout << endl;
			break;
		case 4:
			p.test(num);
			cout << endl;
			break;
		case 5:
			break;
		}
	}//while (choice == 5);
}