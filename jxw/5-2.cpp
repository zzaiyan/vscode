#include <bits/stdc++.h>
using namespace std;
#define int long long

using Pos = pair<int, int>;
Pos getPos(int k, int n) {
  int i = 0, j, cnt = 0;
  for (i = 0; cnt += n - i; i++)
    if (cnt > k)
      break;
  j = n - (cnt - k);
  return {i, j};
}

Pos getPosQ(int k, int n) {}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n = 1e9, k;
  // cin >> k;
  k = n * (n + 1) / 2 - 1;
  auto p = getPos(k, n);
  cout << "i = " << p.first << "\tj = " << p.second << "\n";
  return 0;
}