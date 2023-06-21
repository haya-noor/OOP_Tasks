#include<iostream>
using namespace std;


class swappp
{
    int a,b;
    public:
    swappp()
    {
        a = 0;
        b = 0;
    }

    void setter()
    {
        cout<<"Enter value of a: ";
        cin>>a;
        cout<<"\nEnter value of b: ";
        cin>>b;
    }

    void swapppp()
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    void display()
    {
        cout<<"Before swapping\n";
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;

        swapppp();
        cout<<"After swapping\n";
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
    }
};

int main()
{
    swappp s;

    s.setter();
    s.display();
    return 0;
}
