#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
int n, m, p[N];

// 返回祖宗节点 + 路径压缩
int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

// 合并集合
void merge(int a, int b) {
  p[find(a)] = find(b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i <= n; i++)
    p[i] = i;

  char op;
  int a, b;
  while (m--) {
    cin >> op >> a >> b;
    if (op == 'Q') {
      if (find(a) == find(b))
        cout << "Yes\n";
      else
        cout << "No\n";
    } else if (op == 'M')
      merge(a, b);
  }

  return 0;
}