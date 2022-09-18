#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int d = y - x, v = b + a;
    if (d % v == 0)
      cout << d / v << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}