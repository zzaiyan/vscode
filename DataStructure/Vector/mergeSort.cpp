#include <bits/stdc++.h>
using namespace std;

using Rank = int;

int cnt;

template <typename T>
void merge(T* ele, int lo, int hi) {
  int mi = lo + hi >> 1;
  int k = 0, i = lo, j = mi;
  T* buf = new T[hi - lo];
  while (i < mi && j < hi) {
    if (ele[i] < ele[j])
      buf[k++] = ele[i++];
    else
      buf[k++] = ele[j++];
  }

  while (i < mi)
    buf[k++] = ele[i++];
  while (j < hi)
    buf[k++] = ele[j++];

  for (int i = lo; i < hi; i++)
    ele[i] = buf[i - lo];

  delete[] buf;
  return;
}

template <typename T>
void mergeSort(T* ele, int lo, int hi) {
  if (hi - lo < 2)
    return;
  int mi = lo + hi >> 1;
  mergeSort(ele, lo, mi);
  mergeSort(ele, mi, hi);
  merge(ele, lo, hi);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  auto array = new char[n];
  for (int i = 0; i < n; i++) {
    array[i] = rand() % 26 + 'a';
    // array[i] = i + 1;
    cout << array[i] << ' ';
  }
  cout << "\nover !\n";

  sort(array, array + n);

  for (int i = 0; i < n; i++)
    cout << array[i] << ' ';

  cout << '\n';

  mergeSort(array, 0, n);
  for (int i = 0; i < n; i++)
    cout << array[i] << ' ';

  cout << '\n';

  return 0;
}