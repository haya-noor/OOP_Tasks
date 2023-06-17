#include<iostream>
using namespace std;

struct DOB
{
    int day;
    string month;
    int year;
};
struct user
{
    string name, city;
    int age;
    struct DOB d;
};

int main()
{
    int size = 3;
    user arr[3];

    for(int i = 0; i<3; i++)
    {
        cout<<"Enter the record of "<<i + 1 <<" user\n";
        cout<<"Enter name: ";
        cin>>arr[i].name;
        cout<<"Enter city: ";
        cin>>arr[i].city;
        cout<<"Enter age:";
        cin>>arr[i].age;

        cout<<"Enter date of birth of "<<i+1<<" user\n";
        cout<<"Enter day:";
        cin>>arr[i].d.day;
        cout<<"Enter month: ";
        cin>>arr[i].d.month;
        cout<<"Enter year: ";
        cin>>arr[i].d.year;
    }

    cout<<"Enter date of birth to check if it's someone's birthday\n";
    DOB d1;
    cout<<"Enter day: ";
    cin>>d1.day;
    cout<<"Enter month:";
    cin>>d1.month;
    cout<<"Enter year:";
    cin>>d1.year;

    for(int j = 0; j< size; j++)
    {
        if(d1.day == arr[j].d.day && d1.month == arr[j].d.month && d1.year == arr[j].d.year)
        {
            cout<<"It's "<<arr[j].name<<"'s birthday. Happy birthday " <<arr[j].name<<endl;
        }
        else
        {
            cout<<"It's nobody's birthday\n";
        }
    }
    return 0;
}





//Birthday wisher with Exception handling
#include<iostream>
#include <algorithm> // For transform
#include <cstring>   // For strcmp
using namespace std;

struct DOB {
    int day;
    string month;
    int year;
};

struct User {
    string name, city;
    int age;
    DOB d;
};

//Checks if the day entered by the user is valid or not
bool isvalid_day(int day, string& month, int year) {
    if (month == "February") {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return day >= 1 && day <= 29;
        }
        else {
            return day >= 1 && day <= 28;
        }
    }
    else if (month == "April" || month == "June" || month == "September" || month == "November") {
        return day >= 1 && day <= 30;
    }
    else {
        return day >= 1 && day <= 31;
    }
}

//checks if the month entered by the user is valid or not
bool isvalid_month(string& month) {
    string validMonths[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    // Convert the input month to lowercase
    string lowercaseMonth = month;
    transform(lowercaseMonth.begin(), lowercaseMonth.end(), lowercaseMonth.begin(), ::tolower);

    // Check if the lowercase month matches any valid month names or abbreviations
    for (string& validMonth : validMonths) {
        string lowercaseValidMonth = validMonth;
        transform(lowercaseValidMonth.begin(), lowercaseValidMonth.end(), lowercaseValidMonth.begin(), ::tolower);

        if (lowercaseValidMonth == lowercaseMonth || validMonth.size() >= month.size() && strncmp(validMonth.c_str(), month.c_str(), month.size()) == 0)
            return true;
    }
    return false;
}

//checks if the year entered by the user is valid or not
bool isvalid_year(int year) {
    return year >= 1900 && year <= 2023;
}

int main() {
    int size;
    cout << "Enter the number of users: ";
    cin >> size;

    User* arr = new User[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter the record of User " << i + 1 << "\n";
        cout << "Enter name: ";
        cin >> arr[i].name;
        cout << "Enter city: ";
        cin >> arr[i].city;
        cout << "Enter age: ";
        cin >> arr[i].age;

        if (arr[i].age < 0) {
            cerr << "Age cannot be negative\n";
            exit(1);
        }

        cout << "Enter date of birth of User " << i + 1 << "\n";
        cout << "Enter day: ";
        cin >> arr[i].d.day;
        cout << "Enter month: ";
        cin >> arr[i].d.month;

        if (!isvalid_month(arr[i].d.month)) {
            cerr << "Invalid month\n";
            exit(1);
        }

        cout << "Enter year: ";
        cin >> arr[i].d.year;

        if (!isvalid_day(arr[i].d.day, arr[i].d.month, arr[i].d.year)) {
        cerr << "Please provide correct day for the given month and year\n";
        exit(1);
        }

        if (!isvalid_year(arr[i].d.year)) {
            cerr << "Please provide correct year\n";
            exit(1);
        }
    }

    cout << "Enter the date of birth to check if it's someone's birthday\n";
    DOB d1;
    cout << "Enter day: ";
    cin >> d1.day;
    cout << "Enter month: ";
    cin >> d1.month;

    if (!isvalid_month(d1.month)) {
        cerr << "Invalid month\n";
        exit(1);
    }

    cout << "Enter year: ";
    cin >> d1.year;

    if (!isvalid_day(d1.day, d1.month, d1.year)) {
        cerr << "Please provide correct day for the given month and year\n";
        exit(1);
    }

    if (!isvalid_year(d1.year)) {
        cerr << "Please provide correct year\n";
        exit(1);
    }

    bool foundBirthday = false;

    for (int j = 0; j < size; j++) {
        if (d1.day == arr[j].d.day && d1.month == arr[j].d.month && d1.year == arr[j].d.year) {
            cout << "It's " << arr[j].name << "'s birthday. Happy birthday " << arr[j].name << endl;
            foundBirthday = true;
        }
    }

    if (!foundBirthday) {
        cout << "It's nobody's birthday\n";
    }

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}



