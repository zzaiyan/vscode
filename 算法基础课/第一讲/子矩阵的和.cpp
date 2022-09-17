#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e3 + 5;
int grid[N][N], s[N][N], n, m, q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> grid[i][j];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i][j];
    }

  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
    cout << ans << "\n";
  }

  return 0;
}