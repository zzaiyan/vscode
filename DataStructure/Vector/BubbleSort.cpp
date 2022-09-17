#include <bits/stdc++.h>
using namespace std;

int swapCnt = 0;  // record swap() call times

template <typename T>
int bubble(T* ele, int lo, int hi) {
  int last = lo;
  while (++lo < hi)
    if (ele[lo - 1] > ele[lo]) {
      last = lo;
      swap(ele[lo - 1], ele[lo]);
      swapCnt++;
    }
  // return hi - 1;
  return last;
}

// if no change, last = low,
// then the loop will be broken.
template <typename T>
void bubbleSort(T* ele, int lo, int hi) {
  while (lo < (hi = bubble(ele, lo, hi)))
    ;
}

int main() {
  int n;
  cin >> n;

  auto array = new int[n];

  for (int i = 0; i < n; i++)
    cin >> array[i];

  bubbleSort(array, 0, n);  // sort interval = [0, n)

  for (int i = 0; i < n; i++)
    cout << array[i] << ' ';

  cout << '\n';
  // cout << "swap times: " << swapCnt << '\n';

  delete[] array;
  return 0;
}

int f(int n) {
  if (n <= 2)
    return 1;
  return f(n - 1) + f(n - 2);
}