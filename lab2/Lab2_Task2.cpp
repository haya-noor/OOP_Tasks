#include <iostream>
using namespace std;
#define Twopower(n1, n2) ((n1) << (n2))
int main()
{
	int n1, n2;
	char c;

	do
	{
		cout << "Enter  first number:";
		cin >> n1;

		cout << "Enter 2nd number:";
		cin >> n2;

		int result;

		result = Twopower(n1, n2);

		cout << "The reuslt is: " << result<<endl;

		cout << "Enter any key to continye or e to exit: ";
		cin >> c;

	} while (c != 'e');

	return 0;
}
