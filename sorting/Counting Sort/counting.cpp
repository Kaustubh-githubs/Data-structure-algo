

/*
COUNTING SORT Breaffing 

It is a stable sorting(relative order should be same) algo (if we take out the prefix sum)
It uses extra space for enabling the sorting to work
It can be made stable or unstable
It is not the comparision based sorting algorthms
The main part is of cacluting the prefix sum of the frequency array
STEPS
S1 find the max & min from the array
S2 describe the range (max - min +1)
S3 fill the frequency array while treversing the array
S4 update the frequency array by adding the prefix sum
S5 create the ans array
S6 now treversing from the back in ans putting elements and decrement values in the frequency array


USES :-
when dataset is larger but not that much discret
where range of the numbers are bitween soe particular numbers

*/

#include <iostream>
#include <math.h>
// #include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int);

void countSort(int arr[], int min, int max, int size)
{
  // finding the range
  int range = max - min + 1;
  int frequency[range];

  // initilizing the frequency of elements 0 at starting
  for (int i = 0; i < range; i++)
    frequency[i] = 0;

  // filling the frequency array..
  for (int i = 0; i < size; i++)
  {
    int index = arr[i] - min;
    frequency[index]++;
  }

  // finding the prefix sum...
  for (int i = 1; i < range; i++)
  {
    frequency[i] = frequency[i] + frequency[i - 1];
  }

  // creating the answer array of size same a the original aray
  int ans[size];

  for (int i = size - 1; i >= 0; i--)
  {
    int val = arr[i];
    int pos = frequency[val - min];
    int idx = pos - 1;
    ans[idx] = val;
    frequency[val - min]--;
  }

  for (int i = 0; i < size; i++)
    arr[i] = ans[i];
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

  cout << "   *****COUNTING SORT******\n";
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nThe array Befour Sorting is :\n";
  printArray(arr, n);

  int mn = arr[0];
  int mx = arr[0];

  // finding the min and max from the array...
  for (int i = 0; i < n; i++)
  {
    mx = max(mx, arr[i]);
    mn = min(mn, arr[i]);
  }

  // calling the cout sort method...
  /*
	@param
	int arr[]
	int minimum
	int maximum
	int size of the array
	*/
  countSort(arr, mn, mx, n);

  cout << "\nThe array After Sorting is \nRelative order is maintained :\n";
  printArray(arr, n);
}
