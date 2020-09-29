#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // this is the for
        // it uses the more reciteful app ri ovj e lk fof th erlk vwlk
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    cout << "Enter the size of the array :\n";
    int size;
    int arr[size];

    cout << "\nEnter the array Elements :\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    insertionSort(arr, size - 1);

    cout << "\nthe array after sorting is :\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}