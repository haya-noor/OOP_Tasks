#include <iostream>
using namespace std;

class small_set
{
    int size;
    bool arr[32];

public:
    small_set()
    {
        size = 32;
        for (int i = 0; i < size; i++)
        {
            arr[i] = false;
        }

    }

    void set_item(int element)
    {
        int set;
        if (element >= 0 && element < size)
        {
            arr[element] = true;
            cout<<"Enter elemet that you want to set with: ";
            cin>>set;
            cout<<"Element "<<element<<" is set with element "<< set <<endl;
        }
    }
    void clear_item(int clear)
    {
        if (clear >= 0 && clear < size)
        {
            arr[clear] = false;
        }
    }
    int test(int num)
    {
        if (num >= 0 && num < size)
        {
            return arr[num];
        }
        return false;
    }
};

int main()
{
    small_set s1;
    int choice;
    int element;

    while (choice != -1)
    {
        cout << "Enter one of the following:"<<endl;
        cout << " 1. Set element\n";
        cout << " 2. Clear element\n";
        cout << " 3. Test element\n";
        cout << "-1. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to set: ";
            cin >> element;
            s1.set_item(element);
            break;

        case 2:
            cout << "Enter element to clear: ";
            cin >> element;
            s1.clear_item(element);
            break;
        case 3:
            cout << "Enter element to test whether it's already in the set or not: ";
            cin >> element;
            if(s1.test(element))
                cout<<"Yes, "<<element<<" is present in the set\n";
            else
                cout<<"No, "<<element<<" is not present in the set\n";
            break;
        case -1:
            break;
        }
    }
    return 0;
}
