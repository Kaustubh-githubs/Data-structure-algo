//  this is a programe implimenting the Linear search...

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> vec, int find)
{
}

void show(vector<int> vec)
{
  cout << "\n";
  for (auto it = vec.begin(); it <= vec.end(); it++)
    cout << *it << " ";
}

int main()
{
  vector<int> v;
  cout << "Enter the size of the array you are inserting :";
  int size;
  cin >> size;

  cout << "\nEnter an Unsorted array";

  for (int i = 0; i < size; i++)
  {
    int n;
    cin >> n;
    v.push_back(n);
  }

  show(v);
  cout << "\n Enter an item to be searched :";
  int find;
  cin >> find;

  linearSearch(v, find);

  return 0;
}