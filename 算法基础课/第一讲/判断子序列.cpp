#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
int a[N], b[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] == b[j])
      i++;
    j++;
  }

  if (i < n)
    cout << "No\n";
  else
    cout << "Yes\n";

  return 0;
}