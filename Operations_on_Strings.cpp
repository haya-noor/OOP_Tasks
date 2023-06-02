#include <iostream>
#include <string>
using namespace std;

class stringType
{
private:
	string first;
	string second;

public:
	stringType()
	{
		first = "";
		second = "";
	}

	void setValues(string str1, string str2)
	{
		first = str1;
		second = str2;
	}

	void printValues()
	{
		cout << "String 1: " << first << endl;
		cout << "String 2: " << second << endl;
	}

	int maxLength()
	{
		int i = 0, j = 0;

		while (first[i] != '\0')
		{
			i++;
		}
		while (second[j] != '\0')
		{
			j++;
		}

		if (i > j)
		{
			cout << "String1 has the max length\n";
			return i;
		}
		else if (j > i)
		{
			cout << "String2 has the max length\n";
			return j;
		}
		else
		{
			cout << "Both strings have equal length\n";
			return i;
		}
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
				cout << "string 2 is greater than string 1    ";
				return -1;
			}
		}
	}
	void copy(string str1, string str2)
	{
		int i = 0;
		for (; str1[i] != '\0'; i++)
		{
			str2[i] = str1[i]; // copies string1 to string2
		}
		str2[i] = '\0'; //set a null-terminated character at the end of string
		cout << str2;
	}
	string concatenate(string str1, string str2)
	{
		string str3;
		str3 = str1 + str2;
		return str3;
	}

	int searchword(string word)
	{
		bool checkfirst = false;
		bool checksecond = false;
		int position = -1;

		for (int i = 0; first[i] != '\0'; i++)
		{
			if (word[0] == first[i])
			{
				checkfirst = true;
				position = i;

				// Check if the rest of the characters match
				for (int j = 1; word[j] != '\0'; j++)
				{
					if (word[j] != first[i + j])
					{
						checkfirst = false;
						break;
					}
				}

				if (checkfirst)
					return position;
			}
		}

		for (int i = 0; second[i] != '\0'; i++)
		{
			if (word[0] == second[i])
			{
				checksecond = true;
				position = i;

				for (int j = 1; word[j] != '\0'; j++)
				{
					if (word[j] != second[i + j])
					{
						checksecond = false;
						break;
					}
				}

				if (checksecond)
					return position;
			}
		}

		return -1; // Word not found
	}
	int searchChar(char ch)
	{
		bool checkfirst = false;
		bool checksecond = false;
		int position = -1;

		for(int i = 0; first[i] != '\0'; i++)
		{
			if(ch == first[i])
			{
				checkfirst = true;
				position = i;
			if(checkfirst)
				return position;
			}
		}
		for(int j = 0; second[j] != '\0'; j++)
		{
			if(ch == second[j])
			{
				checksecond = true;
				position = j;
			if(checkfirst)
				return position;
			}
		}
	}
};

#define menue                                                   \
	cout << "\nPlease Choose one of the following options: \n"; \
	cout << "\n1) setValues\n";                                 \
	cout << "2) printValues\n";                                 \
	cout << "3) maxLength\n";                                   \
	cout << "4) compare\n";                                     \
	cout << "5) concatenate\n";                                 \
	cout << "6) copy\n";                                        \
	cout << "7) searchWord\n";                                  \
	cout << "8) searchChar\n";                                  \
	cout << "9) Exit\n";

int main()
{
	stringType st;
	menue
	cout<< endl;
	int choice;
	string str1, str2, word;
	char ch;
	cout << "Enter your choice:";
	cin >> choice;
	while (choice != 9)
	{
		switch (choice)
		{
		case 1:
		{
			cout << "Enter first string: ";
			cin.ignore();
			getline(cin, str1);
			cout << "Enter second string: ";
			getline(cin, str2);

			st.setValues(str1, str2);
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
			int length = st.maxLength();
			cout << length;
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Compare:\n";
			cout << st.compare(str1, str2);
			cout << endl;
			break;
		}
		case 5:
		{
			cout << "Concatenate";
			string concatStr = st.concatenate(str1, str2);
			cout << concatStr;
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
			cout << "Enter word: ";
			cin >> word;
			int position = st.searchword(word);
			if (position != -1)
			{
				cout << "Word found at position: " << position << " either in the first string or the second string" << endl;
			}
			else
			{
				cout << "Couldn't find the specified word\n";
			}
			cout << endl;
			break;
		}
		case 8:
		{
			cout << "Searchchar:\n";
			cout << "Enter character:";
			cin >> ch;
			int positon =  st.searchChar(ch);
			if(positon != -1)
			{
				cout<<"Character found at positon: "<<positon<<" either in first or second string\n";
			}
			else 
				cout<<"Couldn't find the specified character\n";
			break;
		}
		case 9:
			return 0;
			break;
		}
		cout << endl;
		menue
		cout<< "Enter your choice:";
		cin >> choice;
	}
	return 0;
}
