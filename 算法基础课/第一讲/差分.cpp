#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 5;
int s[N], d[N], n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    d[i] = s[i] - s[i - 1];
  }
  while (m--) {
    int l, r, c;
    cin >> l >> r >> c;
    d[l] += c, d[r + 1] -= c;
  }
  for (int i = 1; i <= n; i++) {
    d[i] += d[i - 1];
    cout << d[i] << " ";
  }
  return 0;
}