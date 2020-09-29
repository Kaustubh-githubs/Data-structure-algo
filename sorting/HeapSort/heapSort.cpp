/*
In this programe we are going to impliment the hipify algorithms
*/

// this is a three way process in
// step 1 put the elements in to from binary tree to-> heap

#include <iostream>
using namespace std;

// for swaping using pointers
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void heapify(int arr[], int n, int i)
{
  int largest = i;   // Initialize largest as root
  int l = 2 * i + 1; // left = 2*i + 1 this give left node of root
  int r = 2 * i + 2; // right = 2*i + 2 gives right node of the root

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest])
    largest = l;

  // If right child is larger than largest so far
  if (r < n && arr[r] > arr[largest])
    largest = r;

  // If largest is not root
  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // One by one extract an element from heap
  for (int i = n - 1; i > 0; i--)
  {
    // Move current root to end
    swap(&arr[0], &arr[i]);

    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << "\n";
}

// Driver program
int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cout << "*****HEAP SORT ALOGRITHMS*****\n\n";
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "The array Befour Sorting is :\n";
  printArray(arr, n);

  heapSort(arr, n);

  cout << "The array After Sorting is :\n";
  printArray(arr, n);
}