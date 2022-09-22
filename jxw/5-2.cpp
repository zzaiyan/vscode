#include <bits/stdc++.h>
using namespace std;
#define int long long

using Pos = pair<int, int>;
Pos getPos(int k, int n) {
  int i = n - 1 - (int)((sqrt(4 * n * (n + 1) - 8 * k - 7) - 1) / 2);
  int j = n + k - (2 * n - i) * (i + 1) / 2;
  return {i, j};
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n = 1e9, k;
  // cin >> k;
  k = n * (n + 1) / 2 - 1;
  cout << k << endl;
  auto q = getPos(k, n);
  cout << "i = " << q.first << "\tj = " << q.second << "\n";
  return 0;
}