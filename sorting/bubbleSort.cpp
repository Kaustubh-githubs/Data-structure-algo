//  bubble sort recursive apporach

#include <bits/stdc++.h>
using namespace std;

void swapElements(int *first, int *second)
{
  int temp;
  temp = *first;
  *first = *second;
  *second = temp;
}

void bubbleSort(vector<int> &v, int len)
{

  if (len == 1)
    return;

  for (int i = 0; i < len - 1; i++)
  {
    if (v[i] > v[i + 1])
      swapElements(&v[i], &v[i + 1]);
  }
  bubbleSort(v, len - 1);
}

void show(vector<int> vec, int len)
{
  cout << "\n";
  for (auto it = vec.begin(); it < vec.end(); it++)
  {
    cout << *it << " ";
  }
  cout << "\n";
}

int main()
{
  vector<int> v = {10, 20, 12, 2, 54, 34, 23, 13};
  int len = v.size();
  cout << "\nThe array befour sorting is :\n";
  show(v, len);

  bubbleSort(v, len);

  cout << "\nThe array after sorting is :\n";

  show(v, len);

  return 0;
}