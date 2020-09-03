#include <iostream>
#include <cstdlib>

using namespace std;

// Swapping two values.
void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}


// this is the main function of the quicksort algorithms
// rest is just the recursive function 
// with base case and recursive call
// Partitioning the array on the basis of values at high as pivot value.
int Partition(int a[], int low, int high)
{
  int pivot, index, i;
  index = low;
  pivot = high;

  // Getting index of the pivot.
  for (i = low; i < high; i++)
  {
    if (a[i] < a[pivot])
    {
      swap(&a[i], &a[index]);
      index++;
    }
  }
  // Swapping value at high and at the index obtained.
  swap(&a[pivot], &a[index]);

  return index;
}

// Random selection of pivot.
// we can skip this function and directely make pviot as the last element of the array 
int RandomPivotPartition(int a[], int low, int high)
{
  int pvt, n, temp;
  n = rand();
  // Randomizing the pivot value in the given subpart of array.
  pvt = low + n % (high - low + 1);

  // Swapping pivot value from high, so pivot value will be taken as a pivot while partitioning.
  swap(&a[high], &a[pvt]);

  return Partition(a, low, high);
}

int QuickSort(int a[], int low, int high)
{
  int pindex;
  if (low < high)
  {
    // Partitioning array using randomized pivot.
    pindex = RandomPivotPartition(a, low, high);
    // Recursively implementing QuickSort.
    QuickSort(a, low, pindex - 1);
    QuickSort(a, pindex + 1, high);
  }
  return 0;
}

int main()
{

  // #ifndef ONLINE_JUDGE
  // 	freopen("input.txt", "r", stdin);
  // 	freopen("output.txt", "w", stdout);
  // #endif
  int n, i;
  cout << "\nEnter the number of data elements to be sorted: ";
  cin >> n;

  int arr[n];
  for (i = 0; i < n; i++)
  {
    cout << "Enter element " << i + 1 << ": ";
    cin >> arr[i];
  }

  QuickSort(arr, 0, n - 1);

  // Printing the sorted data.
  cout << "\nSorted Data ";
  for (i = 0; i < n; i++)
    cout << "->" << arr[i];

  return 0;
}
