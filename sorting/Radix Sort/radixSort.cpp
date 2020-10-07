/*
    RADIX SORT ALGORITHM

The idea of Radix Sort is to do digit by digit sort starting from
 least significant digit to most significant digit.
 Radix sort uses counting sort as a subroutine to sort.

Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers
 complexity becomes O(nLogb(n))

STEPS :-
 Do following for each digit
  i where i varies from least significant digit to the most significant digit.
Sort input array using counting sort (or any stable sort)
 according to the i’th digit.

 for this we have to find the most largest number as it has the largest
digits as a whole
then starting from the
*/

#include <iostream>
#include <math.h>
using namespace std;

void countSort(int arr[], int exp, int size)
{
  // decleraing the ans array of same size as of original array
  int ans[size];

  // here range is only[0...9] so size is 10..
  // filling it up
  // filling 0 initially
  int frequency[10] = {0};

  // tereversing the original array and incrementing the value
  // of the matched digit in the frequency array
  for (int i = 0; i < size; i++)
  {
    frequency[arr[i] / exp % 10]++;
  }
  // calculating the prefix sum of the frequency array
  // for making it stable this now give us the position
  // where the last element goes up to which position
  for (int i = 1; i < 10; i++)
  {
    frequency[i] += frequency[i - 1];
  }
  // filling the ans array with sorted element by finding the
  // last position of  the element where it goes in the array

  // IMP :- here arr[i] / exp % 10 gives us the signifigent
  // digit in the number and this is showing the palce value for the
  // radix sort
  for (int i = size - 1; i >= 0; i--)
  {
    int pos = frequency[arr[i] / exp % 10] - 1;
    ans[pos] = arr[i];
    frequency[arr[i] / exp % 10]--;
  }

  // reassigning the original array
  for (int i = 0; i < size; i++)
    arr[i] = ans[i];
}

void radixSort(int arr[], int size)
{
  int max = arr[0];

  // here we are finding the maximum element in the array
  // for finding the iteration needed for radix sort to do

  for (int i = 0; i < size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }

  // at starting the we are starting at the once's place and move on

  // Do counting sort for every digit. Note that instead
  // of passing digit number, exp is passed. exp is 10^i
  // where i is current digit number
  int exp = 1;
  while (exp <= max)
  {
    countSort(arr, exp, size);
    exp = exp * 10;
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

  cout << "   *****RADIX SORT******\n";
  int n;
  cin >> n;
  int arr[n];
  // cout << "hello";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nThe array Befour Sorting is :\n";
  printArray(arr, n);

  radixSort(arr, n);

  cout << "\nThe array After Sorting is \nRelative order is maintained :\n";
  printArray(arr, n);

  return 0;
}