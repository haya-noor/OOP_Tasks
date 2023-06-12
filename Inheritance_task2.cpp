#include <iostream>
#include <string>
using namespace std;

class MyFather
{
protected:
    string name;
    string eye_color;
    string hair_color;

public:
    MyFather(string n, string ec, string hc)
    {
        name = n;
        eye_color = ec;
        hair_color = hc;
    }

    string getName() const
    {
        return name;
    }

    string getEyeColor() const
    {
        return eye_color;
    }

    string getHairColor() const
    {
        return hair_color;
    }

    void setName()
    {
        cout << "Enter Father name: ";
        getline(cin, name);
    }

    void setEyeColor()
    {
        cout << "Enter Father eye color: ";
        getline(cin, eye_color);
    }

    void setHairColor()
    {
        cout << "Enter Father Hair color: ";
        getline(cin, hair_color);
    }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Eye Color: " << eye_color << endl;
        cout << "Hair Color: " << hair_color << endl;
    }
};

class MyMother
{
protected:
    string name;
    string eye_color;
    string hair_color;

public:
    MyMother(string n, string ec, string hc)
    {
        name = n;
        eye_color = ec;
        hair_color = hc;
    }

    string getName() const
    {
        return name;
    }

    string getEyeColor() const
    {
        return eye_color;
    }

    string getHairColor() const
    {
        return hair_color;
    }

    void setName()
    {
        cout << "Enter Mother name: ";
        getline(cin, name);
    }

    void setEyeColor()
    {
        cout << "Enter Mother eye color: ";
        getline(cin, eye_color);
    }

    void setHairColor()
    {
        cout << "Enter Mother Hair color: ";
        getline(cin, hair_color);
    }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Eye Color: " << eye_color << endl;
        cout << "Hair Color: " << hair_color << endl;
    }
};
class Myself : public MyFather
{
private:
    string education;
    int age;

public:
    Myself(string n, string ec, string hc, string e, int a)
        : MyFather(n, ec, hc)
    {
        education = e;
        age = a;
    }

    string getEducation() const
    {
        return education;
    }

    int getAge() const
    {
        return age;
    }

    void setName()
    {
        cout << "Enter your name: ";
        getline(cin, name);
    }

    void setEyeColor()
    {
        cout << "Enter your eye color: ";
        getline(cin, eye_color);
    }

    void setHairColor()
    {
        cout << "Enter your hair color: ";
        getline(cin, hair_color);
    }

    void setEducation()
    {
        cout << "Enter your education: ";
        getline(cin, education);
    }

    void setAge()
    {
        cout << "Enter your age: ";
        cin >> age;
        cin.ignore();
    }

    void print()
    {
        MyFather::print();
        cout << "Education: " << education << endl;
        cout << "Age: " << age << endl;
    }
};
class Mysister : public MyFather
{
private:
    string education;
    int age;

public:
    Mysister(string n, string ec, string hc, string e, int a)
        : MyFather(n, ec, hc)
    {
        education = e;
        age = a;
    }

    string getEducation() const
    {
        return education;
    }

    int getAge() const
    {
        return age;
    }

    void setName()
    {
        cout << "Enter your sister's name: ";
        getline(cin, name);
    }

    void setEyeColor()
    {
        cout << "Enter your sister's eye color: ";
        getline(cin, eye_color);
    }

    void setHairColor()
    {
        cout << "Enter your sister's hair color: ";
        getline(cin, hair_color);
    }

    void setSisterEducation() 
    {
        cout << "Enter your sister's education: ";
        getline(cin, education);
    }

    void setSisterAge() 
    {
        cout << "Enter sister's age: ";
        cin >> age;
        cin.ignore();
    }

    void print()
    {
        MyFather::print();
      //  MyMother::print();
        cout << "Education: " << education << endl;
        cout << "Age: " << age << endl;
    }
};

int main()
{
    // Default values
    MyFather father("Phil", "Black", "Black");
    MyMother mother("Claire", "Black", "Blonde");
    Myself myself("Luke", "Black", "Blonde", "High School", 18);
    Mysister sister("Haley", "Black", "Black", "BSc", 21);

    // Set values for father
    father.setName();
    father.setEyeColor();
    father.setHairColor();

    // Set values for mother
    mother.setName();
    mother.setEyeColor();
    mother.setHairColor();

    // Set values for myself
    myself.setName();
    myself.setEyeColor();
    myself.setHairColor();
    myself.setEducation();
    myself.setAge();

    // Set values for sister
    sister.setName();
    sister.setEyeColor();
    sister.setHairColor();
    sister.setSisterEducation();
    sister.setSisterAge();

    // Print the information
    cout << "\nFather Info:\n";
    father.print();

    cout << "\nMother Info:\n";
    mother.print();

    cout << "\nMy Info:\n";
    myself.print();

    cout << "\nSister Info:\n";
    sister.print();

    return 0;
}
