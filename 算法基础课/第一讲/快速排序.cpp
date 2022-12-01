#include <bits/stdc++.h>
using namespace std;

int arr[1000005];

template <class T> void quicksort(T *a, int l, int r) {
  if (l >= r)
    return;
  int x = a[l + r >> 1], i = l, j = r;
  do {
    while (a[i] < x)
      i++;
    while (a[j] > x)
      j--;
    if (i <= j)
      swap(a[i++], a[j--]);
  } while (i <= j);
  quicksort(a, l, j);
  quicksort(a, i, r);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", arr + i);
  quicksort(arr, 1, n);
  for (int i = 1; i <= n; i++) {
    if (i - 1)
      putchar(' ');
    printf("%d", arr[i]);
  }
  return 0;
}