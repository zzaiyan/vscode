#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 10;
int n, m, a[N], s[N];
vector<int> alls;

using op = pair<int, int>;
vector<op> add, query;

int find(int x) {
  int l = 0, r = alls.size() - 1;
  while (l < r) {
    int mid = l + r >> 1;
    if (alls[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  // 映射到正整数集
  return r + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, c;
    cin >> x >> c;
    // x处值加c
    add.push_back({x, c});

    alls.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    query.push_back({a, b});

    alls.push_back(a);
    alls.push_back(b);
  }
  // 排序and去重
  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());
  // 处理操作
  for (auto item : add) {
    int x = find(item.first);
    a[x] += item.second;
  }
  // 处理前置和
  for (int i = 1; i <= alls.size(); i++) {
    s[i] = s[i - 1] + a[i];
  }
  for (auto item : query) {
    int l = find(item.first), r = find(item.second);
    cout << s[r] - s[l - 1] << endl;
  }

  return 0;
}