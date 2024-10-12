#include <iostream>
using namespace std;

template <typename T>

void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
             swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int choice;
    cout << "Enter the type of elements in the array:\n1. Integer\n2. Float \n";
    cin >> choice;

    if (choice == 1)
    {
        int arr[100];
        cout << "Enter the elements  \n";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "The unsorted array is: ";
        for (int i = 0; i < n; i++)
        {

            cout << arr[i] << " ";
        }
        cout << endl;

        bubbleSort(arr, n);

        cout << "The sorted array is: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else if (choice == 2)
    {
        float arr[100];
        cout << "Enter the elements  ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "The unsorted array is: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        bubbleSort(arr, n);

        cout << "The sorted array is: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        cout << "Invalid " << endl;
    }
    cout << endl;
    return 0;
}
