// Binary Search

// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int item)
{
  if (right >= left)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == item)
      return mid;

    if (arr[mid] > item)
      return binarySearch(arr, left, mid - 1, item);

    return binarySearch(arr, mid + 1, right, item);
  }

  return -1;
}

int main(void)
{

  cout << " Enter the size of the array :";
  int size;
  cin >> size;

  if (size < 1)
    return 0;

  cout << "Enter the array elements";
  int arr[size];

  for (auto i = 0; i < size; i++)
    cin >> arr[i];

  cout << "Enter the item to be searched for :";
  int item;
  cin >> item;

  int status = binarySearch(arr, 0, size - 1, item);

  (status == -1) ? cout << "Element not Found !!\n" : cout << "\nElement Found at position : " << status + 1 << "\n";
  return 0;
}