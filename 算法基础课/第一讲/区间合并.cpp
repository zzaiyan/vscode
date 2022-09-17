#include <bits/stdc++.h>
using namespace std;

// constexpr int N = 1e5 + 5;
using Area = pair<int, int>;
vector<Area> vec;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    vec.push_back({l, r});
  }

  sort(vec.begin(), vec.end());

  int cnt = 0, l = -2e9, r = -2e9;
  for (auto& now : vec)
    if (r < now.first) {
      if (l != -2e9)
        cnt++;
      l = now.first, r = now.second;
    } else {
      r = max(r, now.second);
    }

  if (l != -2e9)
    cnt++;

  cout << cnt << '\n';
  return 0;
}