#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e3 + 5;
int n, m, q, s[N][N], d[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> q;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> s[i][j];
  //生成差分矩阵
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      d[i][j] = s[i][j] - s[i - 1][j] - s[i][j - 1] + s[i - 1][j - 1];
    }
  while (q--) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    d[x1][y1] += c, d[x2 + 1][y2 + 1] += c;
    d[x2 + 1][y1] -= c, d[x1][y2 + 1] -= c;
  }
  //计算差分矩阵前缀和
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
      cout << d[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}