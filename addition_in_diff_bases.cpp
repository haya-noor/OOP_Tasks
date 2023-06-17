

#include <iostream>
#include<vector>
#include <bitset>
#include<iomanip>
#include<conio.h>
#include<string>
#include<math.h>
#include <map>
#include<algorithm>

using namespace std;
void decimal(int n1, int n2);
void binary(long n1, long n2);
void octal(int n1, int n2);
string hex(string n1, string n2);

int main()
{
	int base;
	char c;

	while (c != 'e')
	{
		cout << "Enter base system (binary(2), octal(8), decimal(10) or hex(16):";
		cin >> base;
		// binary
		if (base == 2)
		{
			long n1, n2;
			cout << "Enter a positive number1:";
			cin >> n1;
			cout << "Enter a positive number2:";
			cin >> n2;
			cout << "Sample output:\n";
			binary(n1, n2);
		}

		// octal
		else if (base == 8)
		{
			int n1, n2;
			cout << "Enter a positive number1:";
			cin >> n1;
			cout << "Enter a positive number2:";
			cin >> n2;
			cout << "Sample output:\n";
			octal(n1, n2);
		}

		// decimal
		else if (base == 10)
		{
			int n1,n2;
			cout << "Enter a positive number1:";
			cin >> n1;
			cout << "Enter a positive number2:";
			cin >> n2;
			cout << "Sample output:\n";
			decimal(n1, n2);
		}
		else if(base == 16)
		{
			string n1, n2;
			cout<<"Enter a positive number1: ";
			cin>>n1;
			//getline(cin, n1);
			//cin.ignore();
			cout<<"Enter a positive number2: ";
			//getline(cin, n2);
			//cin.ignore();
			cin>>n2;
			cout << "Sample output:\n";
			cout<<hex(n1, n2);
		}
		else
		{
			cout<<"Invalid option\n";
		}
		cout << "\nEnter any other key to continue or e to exit: ";
		cin >> c;
	}
	
	return 0;
}

// Addition of decimal numbers
void decimal(int n1, int n2)
{
	int sum = 0;

	sum = n1 + n2;

	cout << sum;
}

// Enter numbers n1 and n2 in binary and this function performs binary addition
void binary(long n1, long n2)
{
	int sum[20]; // array that stores the sum
	int c = 0;	 // c = carry
	int i = 0;

	while (n1 != 0 || n2 != 0)
	{
		sum[i++] = (int)((n1 % 10 + n2 % 10 + c) % 2);
		c = (int)((n1 % 10 + n2 % 10 + c) / 2);
		n1 = n1 / 10;
		n2 = n2 / 10;
	}
	if (c != 0) // if carry isn't zero
	{
		sum[i++] = c; // add that carry to the sum
	}
	--i;
	while (i >= 0)
	{
		cout << (sum[i--]);
	}
}

// for octal conversion
void octal(int n1, int n2)
{
	int sum = 0, digit = 0, carry = 0, digit_rank = 1;

	// Calculate the sum
	while (n1 > 0 || n2 > 0 || carry) // Continue while loop until both numbers (n1, n2) and carry turns zero
	{
		// Calculate the digit
		int a = n1 % 10;
		int b = n2 % 10;
		digit = (a + b + carry);

		// Determine if you should carry or not
		if (digit > 7)
		{
			carry = 1;
			digit %= 8;
		}
		else
		{
			carry = 0;
		}
		// Add the digit at the beggining of the sum
		sum += digit * digit_rank;
		digit_rank *= 10;

		// Get rid of the digits of a and b we used
		n1 = n1 / 10;
		n2 = n2 / 10;
	}
	cout << sum;
}

// for hex
map<char, int> hex_value_of_dec(void)
{
	map<char, int> m{{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};
	return m;
}
map<int, char> dec_value_of_hex(void)
{
	map<int, char> m{{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};
	return m;
}
string hex(string n1, string n2)
{
	map<char, int> m = hex_value_of_dec();
	map<int, char> k = dec_value_of_hex();

	if (n1.length() < n2.length())
		swap(n1, n2);

	int l1 = n1.length();
	int l2 = n2.length();

	string result = "";
	int carry = 0;
	int i, j;

	for (i = l1 - 1, j = l2 - 1; j >= 0; i--, j--)
	{
		int sum = m[n1[i]] + m[n2[j]] + carry;

		int add_to_result = k[sum % 16];
		result.push_back(add_to_result);

		carry = sum / 16;
	}

	while (i >= 0)
	{
		int sum = m[n1[i]] + carry;
		int add_to_result = k[sum % 16];
		result.push_back(add_to_result);

		carry = sum / 16;
		i--;
	}
	if (carry != 0)
	{
		result.push_back(k[carry]);
	}

	reverse(result.begin(), result.end());

	return result;
}
