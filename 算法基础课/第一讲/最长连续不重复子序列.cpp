#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
int n, arr[N], cnt[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  int res = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    cnt[arr[i]]++;
    while (cnt[arr[i]] > 1) {
      cnt[arr[j]]--;
      j++;
    }
    res = max(res, i - j + 1);
  }
  cout << res << "\n";

  return 0;
}