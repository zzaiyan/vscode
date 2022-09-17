#include <bits/stdc++.h>
using namespace std;
constexpr int n = 30;
int main() {
  srand(time(0));
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 100 + 1;
  //排序前输出
  for_each(arr, arr + n, [](int x) { cout << x << ' '; });
  putchar('\n');
  // lambda排序
  sort(arr, arr + n, [](int a, int b) { return a > b; });
  //排序后输出
  for_each(arr, arr + n, [](int x) { cout << x << ' '; });
  putchar('\n');

  return 0;
}