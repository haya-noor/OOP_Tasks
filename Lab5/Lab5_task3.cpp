#include<iostream>
#include<string>
using namespace std;

class stringType
{
private:
	string first;
	string second;
public:
	//Default constructor
	stringType()
	{
		first = " ";
		second = " ";
	}
	//Parametarized constructor
	stringType(int str1 , int str2)
	{
		first = str1;
		second = str2;
	}
	//Destructor
	~stringType()
	{}
	void setValues(string str1, string str2)
	{
		cout << "\nEnter first string:";
		getline(cin, str1);
		cout << endl;
		cin.ignore();
		cout << "Enter second string:";
		getline(cin, str2);
	}
	void printValues()
	{
		for (int i = 0; first[i] && second[i] != '\0'; i++)
		{
			cout << "String 1: " << first << endl;
			cout << "String 2: " << second << endl;
		}
	}
	int maxLength()
	{
		int maxlen = 0;
		for (int i = 0; first[i] || second[i] != '\0'; i++)
		{
			maxlen += i;
		}
		return maxlen;
	}
	int compare(string str1, string str2)
	{
		int length = maxLength();
		for (int i = 0; i < length; i++)
		{
			if (str1[i] == str2[i])
			{
				cout << "Equal strings.\n";
				return 0;
			}
			else if (str1[i] > str2[i])
			{
				cout << "String 1 is greater than string 2.\n";
				return 1;
			}
			else
			{
				cout << "string 2 is greater than string 1";
				return -1;
			}
		}
	}
	void copy(string str1, string str2)
	{                       
		int i = 0;                               //str1 = source    str2 = destination
		while(str1[i] != '\0')
		{
			str1 = str2;
			i++;
		}
		cout << str1;
	}
	string concatenate(string str1, string str2)
	{
		string str3;
		str3 = str1 + str2;
		return str3;
	}
	int searchword(string word)
	{
		for (int i = 0; first[i] || second[i] != '\0'; i++)
		{
			if (word[i] == first[i])
			{
				return word[i];
			}
			if (word[i] == second[i])
			{
				return word[i];
			}
		}

	}
	int searchChar(char ch)
	{
		cout << "Enter the character you want to find in the given two strings:";
		cin >> ch;
		for (int i = 0; first[i] || second[i] != '\0'; i++)
		{
			if (ch == first[i])
			{
				cout << ch << endl;
				return ch;
			}
			if (ch == second[i])
			{
				cout << ch << endl;
				return ch;
			}
			else
				cout << "Word's not found.\n";
			return 0;
		}
		
	}
};
int main()
{
	stringType st;
	int choice;
	string str1, str2, word;
	char ch;
	while (true)
	{
		cout << "1)Set Values\n2)Print Values\n3)Max Length\n4)Compare\n5)Concatenate\n6)Copy\n7)Searc hWord\n8)Search Char\n9)Exit\n";
		cout << "Enter your choice:";
		cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cout << "Setvalues:\n";
				st.setValues(str1, str2);
				cout << endl;
				break;
			}
			case 2:
			{
				cout << "PrintValues\n";
				st.printValues();
				cout << endl;
				break;
			}
			case 3:
			{
				cout << "Maxlength:\n";
				st.maxLength();
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "Compare:\n";
				st.compare(str1, str2);
				cout << endl;
				break;
			}
			case 5:
			{
				cout << "Concatenate";
				st.concatenate(str1, str2);
				cout << endl;
				break;
			}
			case 6:
			{
				cout << "Copy:\n";
				st.copy(str1, str1);
				cout << endl;
				break;
			}
			case 7:
			{
				cout << "SearchWord:\n";
				st.searchword(word);
				cout << endl;
				break;
			}
			case 8:
			{
				cout << "Searchchar:\n";
				cout << "Enter character:";
				cin >> ch;
				st.searchChar(ch);
				cout << endl;
				break;
			}
			case 9:
				return 0;
				break;
		    }
	}
}