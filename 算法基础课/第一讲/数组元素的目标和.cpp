#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
int a[N], b[N], n, m, x;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  int i = 0, j = m - 1;
  for (; i < n; i++) {
    while (j >= 0 && a[i] + b[j] > x)
      j--;
    if (a[i] + b[j] == x)
      break;
  }
  cout << i << ' ' << j << '\n';
  return 0;
}