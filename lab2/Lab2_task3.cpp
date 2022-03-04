#include<iostream>
#include<bitset>
using namespace std;
void decimal(int n1, int n2);
void binary(int n1, int n2);
void octal(int n1, int n2);
void hex(int n1, int n2);

int main()
{
	int base;
	int n1, n2;
	cout << "Enter base system (binary(2), octal(8), decimal(10):";
	cin >> base;

	cout << "Enter positive number 1:";
	cin >> n1;

	cout << "Enter positive number 2:";
	cin >> n2;

	//binary
	if (base == 2)
	{
		cout << "Sample output:\n";
		binary(n1, n2);
	}

	//octal 
	else if (base == 8)
	{
		cout << "Sample output:\n";
		octal(n1, n2);
	}

	//decimal
	else if (base == 10)
	{
		cout << "Sample output:\n";
		decimal(n1, n2);
	}
}

//for decimal 
void decimal(int n1, int n2)
{
	int sum = 0;

	sum = n1 + n2;

	cout << sum;
}

//for binary conversion
void binary(int n1, int n2)
{
	int sum[20],carry = 0, i = 0;                            
	while (n1 != 0 || n2 != 0)
	{
		int a = n1 % 10;   //   n1: first number
		int b = n2 % 10;    //   n2: second number
		sum[i++] = ((a + b + carry) % 2);
		carry = ((a + b + carry) / 2);
		n1 = n1 / 10;
		n2 = n2 / 10;
	}
	//for last carry
	if (carry != 0)
	{
		sum[i++] = carry;
	}
	i--;
	while (i >= 0)
	{
		cout << sum[i--];
	}
}

//for octal conversion 
void octal(int n1, int n2)
{
	int sum = 0, digit = 0, carry = 0, position = 1;
	
	while (n1 > 0 || n2 > 0 || carry) //Continue while loop until both numbers (n1, n2) and carry turns zero
	{
		int a = n1 % 10;
		int b = n2 % 10;
		digit = (a + b + carry);
		if (digit> 7)
		{
			carry = 1;
			digit %= 8;
		}
		else
		{
			carry = 0;
		}
		sum += digit * position;
		position *= 10;
		n1 = n1 / 10;
		n2 = n2 / 10;
	}
	cout << sum;
}