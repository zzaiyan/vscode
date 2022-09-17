#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n <= 2) {
      cout << "1\n";
      continue;
    }
    if (n & 1) {
      cout << 7;
      n -= 3;
    }
    n /= 2;
    for (int i = 0; i < n; i++)
      cout << 1;
    cout << "\n";
  }

  return 0;
}
