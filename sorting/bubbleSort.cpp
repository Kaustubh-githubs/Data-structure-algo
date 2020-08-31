#include <bits/stdc++.h>
using namespace std;

// Input: Indices Range [l ... r)
// Invariant: A[l] <= key and A[r] > key
int GetRightPosition(int A[], int l, int r, int key)
{
  int m;

  while (r - l > 1)
  {
    m = l + (r - l) / 2;

    if (A[m] <= key)
      l = m;
    else
      r = m;
  }

  return l;
}

// Input: Indices Range (l ... r]
// Invariant: A[r] >= key and A[l] > key
int GetLeftPosition(int A[], int l, int r, int key)
{
  int m;

  while (r - l > 1)
  {
    m = l + (r - l) / 2;

    if (A[m] >= key)
      r = m;
    else
      l = m;
  }

  return r;
}

int CountOccurances(int A[], int size, int key)
{
  // Observe boundary conditions
  int left = GetLeftPosition(A, -1, size - 1, key);
  int right = GetRightPosition(A, 0, size, key);

  // What if the element doesn't exists in the array?
  // The checks helps to trace that element exists
  return (A[left] == key && key == A[right]) ? (right - left + 1) : 0;
}

int main()
{

  vector<vector<int>> v;

  return 0;
}