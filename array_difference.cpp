#include<iostream>
using namespace std;


void difference(int arr[], int size)
{
    int *diff = new int[size - 1];
    for(int i = 0; i < size - 1; i++)
    {
        diff[i] = arr[i + 1] - arr[i];
    }
    cout<<"Difference array: ";
    for(int i = 0; i < size - 1; i++)
    {
        cout<<diff[i]<<" ";
    }
}
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int *arr = new int[size];

    cout<<"Enter elements of array: ";
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    cout<<"Difference\n";
    difference(arr, size);

    return 0;
}
