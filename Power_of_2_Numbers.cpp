#include <iostream>
using namespace std;

#define power_of_2(num) ((num & (num - 1)) == 0 ? " Yes " : " No ");

int main()
{
    int num;
    char c;

    while (c != 'e')
    {
        cout << "Enter a number:";
        cin >> num;

        cout << "The result is:";
        cout << power_of_2(num);
        cout<<endl;
        cout << "Press e to exit or any other char to continue:";
        cin>>c;
        cout<<endl;
    }
}

//2nd method
#include<iostream>
using namespace std;

#define power_of_2(num)

int main()
{
	int num;
	cout << "Enter a number:";
	cin >> num;
	if ((num & (num - 1)) == 0)
		cout << "Yes, " << num << " is power of 2.\n";
	else
		cout << "No, " << num << " is not a power of 2\n";
	return 0;
}
