#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  while (n--) {
    int ans = 0, q;
    cin >> q;
    while (q > 0) {
      ans += q & 1;
      // cout << "q=" << q << endl;
      q >>= 1;
    }
    cout << ans << " ";
  }
  cout << "\n";
  return 0;
}