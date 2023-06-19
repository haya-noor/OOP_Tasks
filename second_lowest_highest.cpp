#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int lowest = INT_MAX;
    int secondLowest = INT_MAX;
    int highest = INT_MIN;
    int secondHighest = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < lowest)
        {
            secondLowest = lowest;
            lowest = arr[i];
        }
        else if (arr[i] < secondLowest && arr[i] != lowest)
        {
            secondLowest = arr[i];
        }

        if (arr[i] > highest)
        {
            secondHighest = highest;
            highest = arr[i];
        }
        else if (arr[i] > secondHighest && arr[i] != highest)
        {
            secondHighest = arr[i];
        }
    }

    cout << "Second Lowest Number: " << secondLowest << endl;
    cout << "Second Highest Number: " << secondHighest << endl;

    delete[] arr;

    return 0;
}

//Another Method
#include<iostream>
using namespace std;

void second_lowest_higest(int arr[], int size)
{
    int temp;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp; 
            }
        }
    }

    cout<<"Second lowest element: "<<arr[1]<<endl;
    cout<<"Second highest element: "<<arr[size-2]<<endl;
}

int main()
{
    int size;
    cout<<"Enter size of an array: ";
    cin>>size;

    int *arr = new int[size];

    cout<<"Enter elements of an array: ";
    for(int i = 0; i < size; i++)
    {
        cin>> arr[i];
    }

    cout<<"Array elements are: ";
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    second_lowest_higest(arr, size);
    return 0;
}
