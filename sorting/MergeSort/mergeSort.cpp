
//  Merge sort implementation
//  it is a recursive algorithms
//following the paradime of Divide and concure
// kaustubh Shrivastava

#include <iostream>
using namespace std;

// this is the main function
void merge(int arr[], int left, int mid, int right)
{

  // first of all we all we have three pointers..
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // now we first going to create two different array
  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // now we are going to merge back into the original array
  // befour that resetting the index back
  i = 0;
  j = 0;
  k = left;
  // here we are going to the doubling merging technique

  while (i < n1 && k < n2)
  {
    if (L[i] < R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // here we are copying the remaining elements to the final array
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergesort(int arr[], int start, int end)
{
  // the base case is when there is only one element to sort or merge..
  if (start >= end)
    return;

  // calculating the middle element
  int middle = start + (end - start) / 2;

  // this is the recursive call
  // 1. start -> mid  2. mid+1 -> end recursively
  mergesort(arr, start, middle);
  mergesort(arr, middle + 1, end);

  // third step is to merge the two array (that is sorted)
  merge(arr, start, middle, end);
}

// this is the main function of the programre
int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int size;
  cin >> size;
  int arr[size];

  for (int i = 0; i < size; i++)
    cin >> arr[i];

  cout << "The array befour sorting is :\n";
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";

  mergesort(arr, 0, size - 1);

  cout << "\nthe array after sorting is :\n";
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";

  return 0;
}